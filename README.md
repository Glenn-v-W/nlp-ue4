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

Watch this video for a quick summary of the plugin's features!

[INSERT VIDEO HERE]

## Troubleshooting

### command window pops up on first begin play

On first play, the plugin adds modules to the python virtual environment. This may take a few minutes depending on internet connectivity.

## [License](https://github.com/Glenn-v-W/nlp-ue4/blob/master/LICENSE)
NLP and Tensorflow Plugin - [MIT](https://opensource.org/licenses/MIT)

TensorFlow and TensorFlow Icon - [Apache 2.0](http://www.apache.org/licenses/LICENSE-2.0)
