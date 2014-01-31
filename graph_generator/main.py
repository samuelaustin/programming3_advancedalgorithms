import sys
sys.path.append('./site-packages')
import networkx as nx
import numpy as np
#import pylab as pl
import matplotlib.pyplot as pl
import utils

import os
from subprocess import Popen, PIPE

def generate_data():
	approx_vertex_cover = np.zeros([1,11])
	ind = np.zeros([1,11])
	for i in range(0,10):
		G=nx.erdos_renyi_graph(100,0.01*i)
		process = Popen(["../build/programming3", utils.dmax(G)], stdout=PIPE)	
		(output, err) = process.communicate()
		exit_code = process.wait()
		data = [int(s) for s in output.split() if s.isdigit()]
		approx_vertex_cover[0,i]=data[0]
		ind[0,i]= i
		nx.draw(G)
		pl.savefig('g'+str(i)+'.png')
		pl.clf()
	return (ind,approx_vertex_cover)
	
(ind,data) = generate_data()
print(data)
print(ind)

#pl.figure(figsize=(10,6), dpi=80)
pl.plot(ind, data, linewidth=1.0, linestyle='r--', marker='o')
#pl.savefig('plot.png', dpi=80)
pl.show()
	
	
	
	
	
