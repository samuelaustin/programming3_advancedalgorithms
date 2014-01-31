import sys
sys.path.append('./site-packages')
import networkx as nx
import numpy as np

G=nx.lollipop_graph(10,20)
for line in nx.generate_edgelist(G,data=False):
	print(line)

