import sys
sys.path.append('./site-packages')
import networkx as nx
import numpy as np
import utils
from subprocess import call


G = nx.lollipop_graph(10,20)
calout = call(["../build/programming3", utils.dmax(G)])
print(calout)
