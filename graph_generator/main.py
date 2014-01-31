import sys
sys.path.append('./site-packages')
import networkx as nx
import numpy as np
import scipy as sp
import matplotlib.pyplot as plt
import utils

import os
from subprocess import Popen, PIPE

def generate_data():
	apxg_vc		= range(0,10)
	apxr_vc_mean 	= range(0,10)
	apxr_vc_errorl 	= range(0,10)
	apxr_vc_errorh 	= range(0,10)
	ind = range(0,10)
	for i in range(0,10):
		#G=nx.erdos_renyi_graph(50,0.01*i)
		#G = nx.random_regular_graph(i*5, 100)
		G = nx.powerlaw_cluster_graph(50, i+2, 0.0)		
		temp_data = range(0,200)
		for j in range(0,200):
			process = Popen(["../build/programming3", utils.dmax(G),"r"], stdout=PIPE)	
			(output, err) = process.communicate()
			exit_code = process.wait()
			temp_data[j]=int(output)
		apxr_vc_mean[i]  = np.mean(temp_data)
		apxr_vc_errorl[i] = np.min(temp_data)-np.mean(temp_data) 
		apxr_vc_errorh[i] = np.mean(temp_data)-np.max(temp_data)
		process = Popen(["../build/programming3", utils.dmax(G),"g"], stdout=PIPE)	
		(output, err) = process.communicate()
		exit_code = process.wait()
		apxg_vc[i] = int(output)
	return (ind,apxr_vc_mean,[apxr_vc_errorl,apxr_vc_errorh],apxg_vc)

(ind,apxr_vc_mean,apxr_vc_error,apxg_vc) = generate_data()
print(apxr_vc_error)
plt.errorbar(ind,apxr_vc_mean,apxr_vc_error,fmt='-bo')
plt.plot(ind,apxg_vc,'-ro')
plt.show()

	
#(ind,data) = generate_data()
#print(data)
#print(ind)

#pl.figure(figsize=(10,6), dpi=80)
#pl.plot(ind, data, linewidth=1.0, linestyle='r--', marker='o')
#pl.savefig('plot.png', dpi=80)
#pl.show()
	
	
	
	
	
