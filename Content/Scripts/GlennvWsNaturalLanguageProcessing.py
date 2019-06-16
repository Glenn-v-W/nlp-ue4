#converted for ue4 use from
#https://github.com/tensorflow/docs/blob/master/site/en/tutorials/_index.ipynb

from __future__ import print_function
from subprocess import call

def installPip(log=print):
    """
    Pip is the standard package manager for Python. Starting with Python 3.4
    it's included in the default installation, but older versions may need to
    download and install it. This code should pretty cleanly do just that.
    """
    log("Installing pip, the standard Python Package Manager, first")
    from os     import remove
    from urllib import urlretrieve
    urlretrieve("https://bootstrap.pypa.io/get-pip.py", "get-pip.py")
    call(["python", "get-pip.py"])

    # Clean up now...
    remove("get-pip.py")

def getPip(log=print):
    """
    Pip is the standard package manager for Python.
    This returns the path to the pip executable, installing it if necessary.
    """
    from os.path import isfile, join
    from sys     import prefix
    # Generate the path to where pip is or will be installed... this has been
    # tested and works on Windows, but will likely need tweaking for other OS's.
    # On OS X, I seem to have pip at /usr/local/bin/pip?
    pipPath = join(prefix, 'Scripts', 'pip.exe')

    # Check if pip is installed, and install it if it isn't.
    if not isfile(pipPath):
        installPip(log)
        if not isfile(pipPath):
            raise("Failed to find or install pip!")
    return pipPath

def installIfNeeded(moduleName, nameOnPip=None, notes="", log=print):
    """ Installs a Python library using pip, if it isn't already installed. """
    from pkgutil import iter_modules

    # Check if the module is installed
    if moduleName not in [tuple_[1] for tuple_ in iter_modules()]:
        log("Installing " + moduleName + notes + " Library for Python")
        call([getPip(log), "install", nameOnPip if nameOnPip else moduleName])


installIfNeeded("nltk")
installIfNeeded("gensim")
installIfNeeded("pandas")

from gensim.models import Word2Vec, KeyedVectors
#import pandas as pd
import nltk

import tensorflow as tf
import unreal_engine as ue
from TFPluginAPI import TFPluginAPI

#additional includes
from tensorflow.python.keras import backend as K	#to ensure things work well with multi-threading
from tensorflow import keras
import numpy as np   	#for reshaping input
import operator      	#used for getting max prediction from 1x10 output array
import random
import os

scripts_path = ue.get_content_dir() + "Scripts"
word2vec_dir = scripts_path + '/GoogleNews-vectors-negative300.bin'
word2vecmodel = KeyedVectors.load_word2vec_format(word2vec_dir, binary=True, limit=100000)




class KerasBackProp(TFPluginAPI):

	#keras stop callback
	class StopCallback(tf.keras.callbacks.Callback):
		def __init__(self, outer):
			self.outer = outer
			self.monitor = 'acc'
			self.value = 1
			self.verbose = 0
			
		def on_train_begin(self, logs={}):
			self.losses = []

		#def on_batch_end(self, batch, logs={}):
		def on_epoch_end(self, epoch, logs={}):
			if(self.outer.shouldStop):
				#notify on first call
				if not (self.model.stop_training):
					ue.log('Early stop called!')
				self.model.stop_training = True

			else:
				#json convertible types are float64 not float32
				logs['acc'] = np.float64(logs['acc'])
				accuracy = np.float64(logs['acc'])
				logs['loss'] = np.float64(logs['loss'])
				self.outer.callEvent("AccuracyUpdate", logs['acc'], True)
				self.outer.callEvent('TrainingUpdateEvent', logs, True)
					
			current = logs.get(self.monitor)
			if current is None:
				warnings.warn("Early stopping requires %s available!" % self.monitor, RuntimeWarning)

			if current >= self.value:
				if self.verbose > 0:
					print("Epoch %05d: early stopping THR" % epoch)
				self.model.stop_training = True

	#Called when TensorflowComponent sends Json input
	def onJsonInput(self, jsonInput):
		#build the result object
		result = {'word0':-1,}

		#If we try to predict before training is complete
		if not hasattr(self, 'model'):
			ue.log_warning("Warning! No 'model' found, prediction invalid. Did training complete?")
			return result

		#prepare the input
		
		#these are float values passed through the json from unreal to python
		actionindex = jsonInput['actionindex']
		word0 = jsonInput['word0']
		word1 = jsonInput['word1']
		word2 = jsonInput['word2']
		word3 = jsonInput['word3']
		word4 = jsonInput['word4']
		word5 = jsonInput['word5']
		word6 = jsonInput['word6']
		word7 = jsonInput['word7']
		word8 = jsonInput['word8']
		word9 = jsonInput['word9']
		inputarray = [word0,word1,word2,word3,word4,word5,word6,word7,word8,word9]
		ue.log(repr(inputarray))
		self.callEvent(str(repr(inputarray)), {}, True)
		inputarray_word2vec = np.zeros((1,10,300))
		
		ue.log("Print Word2Vec Input:")
		self.callEvent(str(repr(inputarray)), {}, True)
		
		for	index in range(10):
			try:
				inputarray_word2vec[0][index] = word2vecmodel[inputarray[index]]
				ue.log(repr(inputarray_word2vec[0][index]))
				ue.log("valid word")
			except:
				#inputarray_word2vec[0][index] = np.random.uniform(low=-1, high=1, size=300)
				ue.log("invalid word")
				#self.callEvent("word2vec failed, entered non-words", {}, True)
		index+=1
		
		inputarray_word2vec = np.asarray(inputarray_word2vec)
		
		ue.log("Print CNN Input:")
		ue.log(repr(inputarray_word2vec))
		
		#run the input through our network using stored model and graph
		with self.graph.as_default():
			ue.log("Start Predict")
			output = self.model.predict(inputarray_word2vec)
			ue.log(repr(output))
			self.callEvent("SetTempID", actionindex, True)
			self.callEvent("JsonOutput", output.tolist(), True)
			ue.log("Finished Predict")

	#Called when TensorflowComponent signals begin training (default: begin play)
	def onBeginTraining(self):
		ue.log("starting KerasBackProp training")
	
		#Load model from 		scripts_path + '/my_model.h5'
		try:
			ue.log("Try loading model")
			tf.keras.backend.clear_session()
			model = tf.keras.models.load_model(scripts_path + '/my_model.h5')
			model._make_predict_function()
			ue.log("Model loaded")
			model.summary()
			self.graph = tf.get_default_graph()
			self.model = model
		except:		
			ue.log("Loading model failed, training started instead")
			#reset the session each time we get training calls
			self.kerasCallback = self.StopCallback(self)
			K.clear_session()
		
			#Set Data Paths
			x_train_dir = scripts_path + '/TrainingDataSentences.csv'
			y_train_dir = scripts_path + '/TrainingDataIntents.csv'
			
			self.callEvent(repr(x_train_dir), {}, True)
			
			#load data
			x_train = np.genfromtxt(x_train_dir, delimiter=',',dtype='U')
			x_train_word2vec = []
			x_test_word2vec = []
			y_train = np.genfromtxt(y_train_dir, delimiter=',',dtype='U')
			y_train_modified = []
			y_test_modified = []

			trainingdatavariety = 1
			
			
			previoussize = 0
			for numtimesindex in range(trainingdatavariety):
				#For each sample sentence
				for index in range(len(x_train)):
					#Look for number of valid words in sample sentence
					numvalidwords = 0
					for smallindex in range(len(x_train[index])):
						try:
							word2vecmodel[x_train[index][smallindex]]
							numvalidwords+=1
						except:
							pass
					smallindex+=1
					ue.log(numvalidwords)
					#Make sentences with the valid words in all possible locations in the sentence
					for indexvalidwords in range(10-numvalidwords):
						emptyvec = np.zeros((10,300))
						x_train_word2vec.append(emptyvec)
						y_train_modified.append(y_train[index])
						
						wordindex = 0
						for smallindex in range(10):
							try:
								x_train_word2vec[len(x_train_word2vec)-1][wordindex+indexvalidwords] = word2vecmodel[x_train[index][smallindex]]
								wordindex+=1
							except:
								#x_train_word2vec[len(x_train_word2vec)-1][wordindex+indexvalidwords] = np.random.uniform(low=-1, high=1)#, size=300)
								pass
						smallindex+=1
						ue.log(y_train_modified[len(y_train_modified)-1])
						ue.log(y_train[index])
						ue.log(x_train_word2vec[len(x_train_word2vec)-1])
					indexvalidwords+=1
				index+=1
				previoussize = len(x_train_word2vec)
			numtimesindex+=1
			
			previoussize = 0
			for numtimesindex in range(1): #50
				#For each sample sentence
				for index in range(len(x_train)):
					#Look for number of valid words in sample sentence
					numvalidwords = 0
					for smallindex in range(len(x_train[index])):
						try:
							word2vecmodel[x_train[index][smallindex]]
							numvalidwords+=1
						except:
							pass
					smallindex+=1
					ue.log(numvalidwords)
					#Make sentences with the valid words in all possible locations in the sentence
					for indexvalidwords in range(1): #for indexvalidwords in range(10-numvalidwords):
						emptyvec = np.zeros((10,300))
						x_test_word2vec.append(emptyvec)
						y_test_modified.append(y_train[index])
						
						wordindex = 0
						for smallindex in range(10):
							try:
								x_test_word2vec[len(x_test_word2vec)-1][wordindex+indexvalidwords] = word2vecmodel[x_train[index][smallindex]]
								wordindex+=1
							except:
								#x_test_word2vec[len(x_test_word2vec)-1][wordindex+indexvalidwords] = np.random.uniform(low=-1, high=1, size=300)
								pass
						smallindex+=1
						ue.log(y_test_modified[len(y_test_modified)-1])
						ue.log(y_train[index])
						ue.log(x_test_word2vec[len(x_test_word2vec)-1])
					indexvalidwords+=1
				index+=1
				previoussize = len(x_test_word2vec)
			numtimesindex+=1
			
			x_train_word2vec = np.asarray(x_train_word2vec)
			x_test_word2vec = np.asarray(x_test_word2vec)
			y_train_modified = np.asarray(y_train_modified)
			y_test_modified = np.asarray(y_test_modified)
			ue.log(x_train_word2vec.shape)
			ue.log(y_train_modified.shape)
			ue.log(x_test_word2vec.shape)
			ue.log(y_test_modified.shape)
			
			'''
			with open(scripts_path + "/x_train_word2vec.txt", 'w') as outfile:
				outfile.write('# Array shape: {0}\n'.format(x_train_word2vec.shape))
				for data_slice in x_train_word2vec:
					np.savetxt(outfile, data_slice, fmt='%-7.2f')
					outfile.write('# New slice\n')

			with open(scripts_path + "/x_test_word2vec.txt", 'w') as outfile:
				outfile.write('# Array shape: {0}\n'.format(x_test_word2vec.shape))
				for data_slice in x_test_word2vec:
					np.savetxt(outfile, data_slice, fmt='%-7.2f')
					outfile.write('# New slice\n')
			
			with open(scripts_path + "/y_train_modified.txt", 'w') as outfile:
				outfile.write('# Array shape: {0}\n'.format(y_train_modified.shape))
				for data_slice in y_train_modified:
					np.savetxt(outfile, data_slice, fmt="%s")
					outfile.write('# New slice\n')
			
			with open(scripts_path + "/y_test_modified.txt", 'w') as outfile:
				outfile.write('# Array shape: {0}\n'.format(y_test_modified.shape))
				for data_slice in y_test_modified:
					np.savetxt(outfile, data_slice, fmt="%s")
					outfile.write('# New slice\n')
			'''	
			
			
			ue.log("Nr Intents:")
			nrIntents = y_train_modified[0].size
			ue.log(nrIntents)
			self.callEvent(repr(nrIntents), {}, True)
			
			sequence_length = 10
			vocabulary_size = 300
			embedding_dim = 256
			filter_sizes = [3,4,5]
			num_filters = 128
			drop = 0.25
			
			#define model
			inputs = tf.keras.layers.Input(shape=(sequence_length, vocabulary_size), dtype='float32')
			#flatten = tf.keras.layers.Flatten()(inputs)
			reshape = tf.keras.layers.Reshape((sequence_length,vocabulary_size,1))(inputs)

			conv_0 = tf.keras.layers.Conv2D(num_filters, kernel_size=(filter_sizes[0], embedding_dim), padding='valid', kernel_initializer='normal', activation='relu')(reshape)
			conv_1 = tf.keras.layers.Conv2D(num_filters, kernel_size=(filter_sizes[1], embedding_dim), padding='valid', kernel_initializer='normal', activation='relu')(reshape)
			conv_2 = tf.keras.layers.Conv2D(num_filters, kernel_size=(filter_sizes[2], embedding_dim), padding='valid', kernel_initializer='normal', activation='relu')(reshape)

			maxpool_0 = tf.keras.layers.MaxPool2D(pool_size=(sequence_length - filter_sizes[0] + 1, 1), strides=(1,1), padding='valid')(conv_0)
			maxpool_1 = tf.keras.layers.MaxPool2D(pool_size=(sequence_length - filter_sizes[1] + 1, 1), strides=(1,1), padding='valid')(conv_1)
			maxpool_2 = tf.keras.layers.MaxPool2D(pool_size=(sequence_length - filter_sizes[2] + 1, 1), strides=(1,1), padding='valid')(conv_2)

			concatenated_tensor = tf.keras.layers.Concatenate(axis=1)([maxpool_0, maxpool_1, maxpool_2])
			flatten = tf.keras.layers.Flatten()(concatenated_tensor)
			dropout = tf.keras.layers.Dropout(drop)(flatten)
			output = tf.keras.layers.Dense(units=nrIntents, activation='softmax')(dropout)

			model = tf.keras.Model(inputs=inputs, outputs=output)
			
			ue.log("Model made.")

			model.compile(	optimizer=tf.train.AdamOptimizer(0.0001),
							loss='binary_crossentropy',
							metrics=['accuracy'])
			
			ue.log("Model compiled.")
			
			ue.log(model.summary())

			model.fit(x_train_word2vec, y_train_modified, batch_size=128, epochs=1000, callbacks=[self.kerasCallback], validation_data = (x_test_word2vec, y_test_modified))
			
			ue.log("Testing Model.")
			
			result = model.evaluate(x_test_word2vec, y_test_modified, verbose=0)
			print("%s: %.2f%%" % (model.metrics_names[1], result[1]*100))

			ue.log("Model fit.")

			ue.log(repr(result))
			
			self.callEvent(repr(result), {}, True)
			#self.callEvent(repr(model.metrics_names), {}, True)
			
			#self.callEvent(repr(word2vecmodel['none']), {}, True)
			ue.log("Training complete.")
					
			#store our model and graph for prediction
			self.graph = tf.get_default_graph()
			self.model = model
			
			#Save Model to 		scripts_path + '/my_model.h5'
			model.save(scripts_path + '/my_model.h5')
			
			#fix lag
			tf.reset_default_graph()


#required function to get our api
def getApi():
	#return CLASSNAME.getInstance()
	return KerasBackProp.getInstance()
