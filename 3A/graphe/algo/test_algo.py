import os
import sys
path = os.path.abspath(os.path.join(os.path.dirname(__file__), '../node/'))
if not path in sys.path:
    sys.path.insert(1, path)
del path
import node
import dijkstraAlgo
import floyd_WarshallAlgo
import unittest

class TestAlgo(unittest.TestCase):	
	def setUp(self):
		self.dijkstra = dijkstraAlgo.DijkstraAlgo()
		self.floyd_Warshall = floyd_WarshallAlgo.Floyd_WarshallAlgo()
		self.graph= {}

		self.nodeS = node.Node();
		self.nodeS.connections = {'u':10.0, 'x':5.0};			

		self.nodeU = node.Node();
		self.nodeU.connections= {'v':1.0, 'x':2.0};

		self.nodeV = node.Node();
		self.nodeV.connections= {'y':4.0};

		self.nodeX = node.Node();
		self.nodeX.connections= {'u':3.0,'v':9.0,'y':2.0};

		self.nodeY = node.Node();
		self.nodeY.connections = {'s':7.0,'v':6.0};
		
		self.graph= {'s': self.nodeS,
						'u': self.nodeU,
						'v': self.nodeV,
						'x':self.nodeX,
						'y':self.nodeY}

   	def test_addConnection_raise_TypeError(self):
		with self.assertRaises(TypeError):
			self.dijkstra.findRoutingPath([])
		with self.assertRaises(TypeError):
			self.floyd_Warshall.findRoutingPath([])

	# Dijkstra : oriented graph
	def test_algo_Dijkstra_complets_the_routingPath_of_the_sourceNode(self):
		self.dijkstra.findRoutingPath(self.graph)
		print "######### Dijkstra #########"
		TestAlgo.printgraph(self.graph)	

	# Dijkstra : non oriented graph
	"""
	def test_algo_dijkstra_complets_the_routingPath_of_the_sourceNode2(self):
		self.graph= {}

		self.nodeA = node.Node();
		self.nodeA.connections = { 'b':1.0,'c':5.0, 'd':2.0};			

		self.nodeB = node.Node();
		self.nodeB.connections= {'a':1.0,'c':4.0, 'd':6.0};

		self.nodeC = node.Node();
		self.nodeC.connections= {'a':5.0, 'b':4.0, 'd':2.5};

		self.nodeD = node.Node();
		self.nodeD.connections= {'a':2.0, 'b':6.0,'c':2.5};
		
		self.graph= {'a': self.nodeA,
						'b': self.nodeB,
						'c': self.nodeC,
						'd':self.nodeD}
		self.dijkstra.findRoutingPath(self.graph)
		TestAlgo.printgraph(self.graph)
	"""

	# Floyd Warshall
	def test_algo_Floyd_Warshall_complets_the_routingPath_of_the_sourceNode(self):
		self.floyd_Warshall.findRoutingPath(self.graph)
		print "######### Floyd Warshall #########"
		TestAlgo.printgraph(self.graph)


	# Floyd Warshall
	"""
	def test_algo_Floyd_Warshall_complets_the_routingPath_of_the_sourceNode2(self):
		self.graph= {}

		self.nodeA = node.Node();
		self.nodeA.connections = { 'b':1.0,'c':5.0, 'd':2.0};			

		self.nodeB = node.Node();
		self.nodeB.connections= {'a':1.0,'c':4.0, 'd':6.0};

		self.nodeC = node.Node();
		self.nodeC.connections= {'a':5.0, 'b':4.0, 'd':2.5};

		self.nodeD = node.Node();
		self.nodeD.connections= {'a':2.0, 'b':6.0,'c':2.5};
		
		self.graph= {'a': self.nodeA,
						'b': self.nodeB,
						'c': self.nodeC,
						'd':self.nodeD}

		self.floyd_Warshall.findRoutingPath(self.graph)
		TestAlgo.printgraph(self.graph)		
	"""
	
	@staticmethod
	def printgraph(graph):
		for key in graph:
			print "from "+key + ":"
			for key2 in graph:
				print "       to {} ->{}  value: {}".format(key2,graph[key].routingPath[key2].path, graph[key].routingPath[key2].value)
		print "--------------------------------------------"

if __name__ == '__main__':
	unittest.main()
