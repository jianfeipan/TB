import os
import sys
path = os.path.abspath(os.path.join(os.path.dirname(__file__), '../node/'))
if not path in sys.path:
    sys.path.insert(1, path)

path = os.path.abspath(os.path.join(os.path.dirname(__file__), '../utils/'))
if not path in sys.path:
    sys.path.insert(1, path)
del path
import node
import utils
from priodict import priorityDictionary

class Algo:
	@staticmethod
	def Dijkstra(graphe, sourceNode):
		utils.Utils.isStr(sourceNode)
		utils.Utils.isDict(graphe)
		if sourceNode not in graphe:
			raise ValueError('the source node is not in the graphe')

		D = {}	# dictionary of final distances
		P = {}	# dictionary of predecessors
		Q = priorityDictionary()	# estimated distances of non-final vertices
		Q[sourceNode] = 0
	
		for anode in Q:
			D[anode] = Q[anode]
			graphe[sourceNode].routingPath[anode]=[]
		
			for neighbor in graphe[anode].connections:
				sourceToNeighborLenght = D[anode] + graphe[anode].connections[neighbor]
				if neighbor in D:
					if sourceToNeighborLenght < D[neighbor]:
						raise ValueError, "Dijkstra: found better path to already-final vertex"
				elif neighbor not in Q or sourceToNeighborLenght < Q[neighbor]:
					Q[neighbor] = sourceToNeighborLenght
					P[neighbor] = anode
			graphe[sourceNode].routingPath[anode].append(Q[anode])	
			end = anode;
			while 1:
				graphe[sourceNode].routingPath[anode].append(end)
				if end == sourceNode: break
				end = P[end]				
			graphe[sourceNode].routingPath[anode].reverse()
			print graphe[sourceNode].routingPath[anode]

