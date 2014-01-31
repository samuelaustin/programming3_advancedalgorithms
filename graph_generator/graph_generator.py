import networkx as nx


# Choose random graph to generate
G = nx.lollipop_graph(10,20)

# Print graph to file
f = open("testGraph.dim", "w")
f.write("p edge " + str(G.number_of_nodes()) + " " + str(G.number_of_edges()))
f.write("\n")
for line in nx.generate_edgelist(G, data=False):
	print(line)
	f.write("e " + line + "\n")
