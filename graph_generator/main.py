import sys
sys.path.append('./site-packages')
import networkx as nx
import numpy as np
import pylab as pl
import utils

import os
from subprocess import Popen, PIPE

def generate_data():
	approx_vertex_cover = np.zeros([1,10])
	for i in range(0,10):
		G=nx.erdos_renyi_graph(100,0.1*i)
		process = Popen(["../build/programming3", utils.dmax(G)], stdout=PIPE)	
		(output, err) = process.communicate()
		exit_code = process.wait()
		output
	plot()
