import networkx as nx
def dmax(G):
	out = "p edge " + str(G.number_of_nodes()) + " " + str(G.number_of_edges()) + "\n"
	for line in nx.generate_edgelist(G, data=False):
		out += "e " + line + "\n"
	return out
