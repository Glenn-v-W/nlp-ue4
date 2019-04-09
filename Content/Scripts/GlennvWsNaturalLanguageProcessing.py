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

		def on_batch_end(self, batch, logs={}):
			if(self.outer.shouldStop):
				#notify on first call
				if not (self.model.stop_training):
					ue.log('Early stop called!')
				self.model.stop_training = True

			else:
				if(batch % 5 == 0):
					#json convertible types are float64 not float32
					logs['acc'] = np.float64(logs['acc'])
					accuracy = np.float64(logs['acc'])
					logs['loss'] = np.float64(logs['loss'])
					self.outer.callEvent('TrainingUpdateEvent', logs, True)
					
		def on_epoch_end(self, epoch, logs={}):
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
		self.callEvent(str(repr(inputarray)), {}, True)
		inputarray_word2vec = np.array([word2vecmodel[inputarray]])
		
		self.callEvent(str(repr(inputarray_word2vec)), {}, True)
		#run the input through our network using stored model and graph
		with self.graph.as_default():
			output = self.model.predict(inputarray_word2vec)
			self.callEvent("JsonOutput", output.tolist(), True)

	#Called when TensorflowComponent signals begin training (default: begin play)
	def onBeginTraining(self):
		ue.log("starting KerasBackProp training")
		
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
		for index in range(len(x_train)):
			bigVector = word2vecmodel[x_train[index]]
			#self.callEvent(repr(bigVector), {}, True)
			x_train_word2vec.append(bigVector)
			index+=1
		x_train_word2vec = np.asarray(x_train_word2vec)
		#self.callEvent(repr(x_train_word2vec), {}, True)
		y_train = np.genfromtxt(y_train_dir, delimiter=',',dtype='U')
		nrIntents = y_train[0].size
		self.callEvent(repr(nrIntents), {}, True)

		#define model
		model = tf.keras.Sequential([
			tf.keras.layers.Flatten(),
			tf.keras.layers.Dense(310, activation='relu', use_bias=True, kernel_regularizer=tf.keras.regularizers.l2(0.001)),
			#tf.keras.layers.Dropout(0.2),
			tf.keras.layers.Dense(310, activation='relu', use_bias=True, kernel_regularizer=tf.keras.regularizers.l2(0.001)),
			#tf.keras.layers.Dropout(0.2),
			tf.keras.layers.Dense(nrIntents, activation='softmax')
		])
		
		model.compile(	optimizer=tf.train.AdamOptimizer(0.0001),
						loss='categorical_crossentropy',
						metrics=['accuracy'])
		
		model.fit(x_train_word2vec, y_train, batch_size=9999999, epochs=100000,
				  callbacks=[self.kerasCallback], validation_data=(x_train_word2vec, y_train))
		result = model.evaluate(x_train_word2vec, y_train)
		self.callEvent(repr(result), {}, True)
		self.callEvent(repr(model.metrics_names), {}, True)
		
		#self.callEvent(repr(word2vecmodel['none']), {}, True)
		ue.log("Training complete.")
        		
		#store our model and graph for prediction
		self.graph = tf.get_default_graph()
		self.model = model


#required function to get our api
def getApi():
	#return CLASSNAME.getInstance()
	return KerasBackProp.getInstance()
