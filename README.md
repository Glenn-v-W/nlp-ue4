# nlp-ue4

Natural Language Processing Plugin for Unreal Engine 4 using Tensorflow

This plugin was built upon getnamo's tensorflow-ue4 plugin, which you can find here: https://github.com/getnamo/tensorflow-ue4.

This plugin allows you to extract entities and intents from sentences fully in Blueprints, without touching C++ or Python!

## Installation

1.  To use this NLP plugin, you must first follow the instructions for intalling [tensorflow-ue4](https://github.com/getnamo/tensorflow-ue4).
2.    Download and add [nlp-ue4 plugin](https://github.com/Glenn-v-W/nlp-ue4) to \Plugins
3.    Download and add [GoogleNews-vectors-negative300.bin (3.39 GB!)](https://drive.google.com/file/d/0B7XkCwpI5KDYNlNUTTlSS21pQmM/edit?usp=sharing) to \Content\Scripts

## Examples

You can find a bare-bones example project here:

https://github.com/Glenn-v-W/nlp-ue4-examples

For a more in-depth use of this plugin, you can find a text-based adventure game I've been working on here:

[SOON™]

## Feature Overview

This Plugin's workings were heavily inspired by [Microsoft LUIS](https://eu.luis.ai). Similarly to it, we work with entities and intents. The main difference between LUIS and this plugin is that this plugin works offline, without the need to pay for Microsoft Azure, but it is missing a number of features that Microsoft LUIS does have. Namely patterns, regexes, etc. In an ideal world these will be added later, but we'll see.

So, how to get started using this plugin.
There's two major parts for using this plugin, there's an in-engine part, and an out-of-engine part. Let's start to the latter.

### Entities

Make your way to \Content\Entities
In this folder, you can put as many entities as you wish. Each type of entity must be a .csv file, and the name of the file will be the type of the entity.

The .csv file must have the following structure:

[![colors.csv](https://puu.sh/DcFZK/06892ba83b.png)]

Field A1 must be empty or "---"

Field B1 must be "Entities"

Field A2 must contain either True or False. This determines whether the entity has an impact on the intent of a sentence, in other words, it determines if the entity is meaningful. Colors and many adjectives may be described as meaningless as far as the intent is concerned. True = meaningful, False = meaningless

Field B2, B3, B4 and onwards must be structured as seen in the image. Words that fall within the same entity/category but have a different meaning should be in different fields, while synonyms should be in the same field. (For example, Red and Ruby are in the same field, since as far as we're conserned here, they're synonyms, blue meanwhile is in a different field.)

Field A3, A4, A5 and onwards must have unique names, but the names are meaningless, I suggest using row-numbers for simplicity.


Additionally, the first word in B2 will be referred to as the "base" of that Entity.

### TrainingData and Intents

Make your way to \Content\Scripts

This folder must contain 3 .csv files for the plugin to function;

TrainingDataSentences.csv
TrainingDataIntents.csv
Intents.csv

The following screenshot has those files open in that order, from left to right, TrainingDataSentences, TrainingDataIntents and Intents

[![intents](https://puu.sh/DcG9Y/593462f598.png)]

So, what's going on here?
TrainingDataSentences.csv (left-hand file) includes the sentences our neural net will be training on for intent recognition.
Ideally, add as many sentences similar to what players may be saying in the game to this document, but be careful!

1. Change sentence to be lower case
2. Remove all punctuation marks (,.?!)
3. Remove all stop words:
{‘ourselves’, ‘hers’, ‘between’, ‘yourself’, ‘but’, ‘again’, ‘there’, ‘about’, ‘once’, ‘during’, ‘out’, ‘very’, ‘having’, ‘with’, ‘they’, ‘own’, ‘an’, ‘be’, ‘some’, ‘for’, ‘do’, ‘its’, ‘yours’, ‘such’, ‘into’, ‘of’, ‘most’, ‘itself’, ‘other’, ‘off’, ‘is’, ‘s’, ‘am’, ‘or’, ‘who’, ‘as’, ‘from’, ‘him’, ‘each’, ‘the’, ‘themselves’, ‘until’, ‘below’, ‘are’, ‘we’, ‘these’, ‘your’, ‘his’, ‘through’, ‘don’, ‘nor’, ‘me’, ‘were’, ‘her’, ‘more’, ‘himself’, ‘this’, ‘down’, ‘should’, ‘our’, ‘their’, ‘while’, ‘above’, ‘both’, ‘up’, ‘to’, ‘ours’, ‘had’, ‘she’, ‘all’, ‘no’, ‘when’, ‘at’, ‘any’, ‘before’, ‘them’, ‘same’, ‘and’, ‘been’, ‘have’, ‘in’, ‘will’, ‘on’, ‘does’, ‘yourselves’, ‘then’, ‘that’, ‘because’, ‘what’, ‘over’, ‘why’, ‘so’, ‘can’, ‘did’, ‘not’, ‘now’, ‘under’, ‘he’, ‘you’, ‘herself’, ‘has’, ‘just’, ‘where’, ‘too’, ‘only’, ‘myself’, ‘which’, ‘those’, ‘i’, ‘after’, ‘few’, ‘whom’, ‘t’, ‘being’, ‘if’, ‘theirs’, ‘my’, ‘against’, ‘a’, ‘by’, ‘doing’, ‘it’, ‘how’, ‘further’, ‘was’, ‘here’, ‘than’} 
4. Make sure you replace all words that belong to an Entity to the base of that entity (see Entities)
5. If a word belongs to an entity that was selected to be meaningless to the intent, remove it.

So, for example: 
  Imagine we have:
  an Entity of Objects with Base barrel that includes chest
  an Entity of Colors with base red that includes green, and is set to be meaningless
  an Intent of Equipables with base key (that includes key, obviously)
  
    Open the green chest using the green key
  
  would become
    
    open barrel using key

This sentence can then be added to our .csv file, where each word is a seperate field, and all the fields after the sentence is complete are filled with "none" until J. (max of 10 words)

Of course this sentence corresponds to an intent, we must select the corresponding intent of this sentence. We do this in TrainingDataIntents.csv, where we set the corresponding field to 1, and all incorrect fields to 0. These collumns correspond directly with the rows in Intents.csv, so for example, if Intents.csv has the followin fields; B2:GoTo, B3:GoThrough, B4:Use and B5:PickUp.
the first of those, GoTo, corresponds to the first collumn in TrainingDataIntents.csv, the second one, GoThrough, corresponds to the second collumn, and so on. 

Intents.csv has similar rules to Entities;

Field A1 must be empty or "---"

Field B1 must be "Intents" (!!!)

Field A3, A4, A5 and onwards must have unique names, but the names are meaningless, I suggest using row-numbers for simplicity.


That may sound like a lot, so you can also watch this video for a quick summary of the plugin's features!

[INSERT VIDEO HERE]

## Troubleshooting

### command window pops up on first begin play

On first play, the plugin adds modules to the python virtual environment. This may take a few minutes depending on internet connectivity. If the NaturalLanguageComponent does not complete training, wait for a few minutes before pressing play again.

## [License](https://github.com/Glenn-v-W/nlp-ue4/blob/master/LICENSE)
NLP and Tensorflow Plugin - [MIT](https://opensource.org/licenses/MIT)

TensorFlow and TensorFlow Icon - [Apache 2.0](http://www.apache.org/licenses/LICENSE-2.0)
