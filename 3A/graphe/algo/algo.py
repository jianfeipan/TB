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
	def __DijkstraFromSource(graph, sourceNode):
		utils.Utils.isStr(sourceNode)
		utils.Utils.isDict(graph)
		if sourceNode not in graph:
			raise ValueError('the source node is not in the graph')

		D = {}	# dictionary of final distances
		P = {}	# dictionary of predecessors
		Q = priorityDictionary()	# estimated distances of non-final vertices
		Q[sourceNode] = 0
	
		for anode in Q:
			D[anode] = Q[anode]
			graph[sourceNode].routingPath[anode]=[]
		
			for neighbor in graph[anode].connections:
				sourceToNeighborLenght = D[anode] + graph[anode].connections[neighbor]
				if neighbor in D:
					if sourceToNeighborLenght < D[neighbor]:
						raise ValueError, "Dijkstra: found better path to already-final vertex"
				elif neighbor not in Q or sourceToNeighborLenght < Q[neighbor]:
					Q[neighbor] = sourceToNeighborLenght
					P[neighbor] = anode
			graph[sourceNode].routingPath[anode].append(Q[anode])	
			end = anode;
			while 1:
				graph[sourceNode].routingPath[anode].append(end)
				if end == sourceNode: break
				end = P[end]				
			graph[sourceNode].routingPath[anode].reverse()

	@staticmethod	
	def Dijkstra(graph):	
		for key in graph:
			Algo.__DijkstraFromSource(graph,key)

	@staticmethod
	def Floyd_Warshall(graph):
		utils.Utils.isDict(graph)

		dist = {}
		pred = {}
		for u in graph:
		    dist[u] = {}
		    pred[u] = {}
		    for v in graph:
		        dist[u][v] = 1000
		        pred[u][v] = -1
		    dist[u][u] = 0
		    for neighbor in graph[u].connections:
		        dist[u][neighbor] = graph[u].connections[neighbor]
		        pred[u][neighbor] = u
	 
		for t in graph:
		    for u in graph:
		        for v in graph:
		            newdist = dist[u][t] + dist[t][v]
		            if newdist < dist[u][v]:
		                dist[u][v] = newdist
		                pred[u][v] = pred[t][v]
		for s in graph:			
			for d in graph:
				graph[s].routingPath[d]=[]
				end = d;
				graph[s].routingPath[d].append(dist[s][d])
				while 1:
					graph[s].routingPath[d].append(end)
					if end == s: break
					end = pred[s][end]				
				graph[s].routingPath[d].reverse()
				
