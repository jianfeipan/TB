import networkx as nx
import pylab as plt

# Sample graph
G = nx.Graph()
G.add_node(10)
G.add_edge(0, 1)
G.add_edge(1, 2)
G.add_edge(2, 3)
G.add_edge(1, 3)

labels = {(0, 1): 'foo', (2, 3): 'bar'}

pos = nx.spring_layout(G)

nx.draw(G, pos)
nx.draw_networkx_edge_labels(G, pos, edge_labels=labels, font_size=30)

plt.show()
