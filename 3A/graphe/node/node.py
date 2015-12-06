import os
import sys
path = os.path.abspath(os.path.join(os.path.dirname(__file__), '../utils/'))
if not path in sys.path:
    sys.path.insert(1, path)
del path

import utils
class Node:
	def __init__(self):
		self.connections = {}
		self.routingPath = {}

	def addConnection(self, destination, distance):
		utils.Utils.isStr(destination)
		utils.Utils.isFloat(distance)
		self.connections[destination] = distance

	def addPath(self, destination, path):
		utils.Utils.isStr(destination)
		utils.Utils.isList(path)
		self.routingPath[destination] = path
