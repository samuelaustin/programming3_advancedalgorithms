import sys
sys.path.append('./site-packages')
import networkx as nx
import numpy as np
import scipy as sp
import matplotlib.pyplot as plt
import utils
import re
import pylab as pl

import os
from subprocess import Popen, PIPE

def generate_data():
	apxg_vc		= range(0,10)
	apxi_vc		= range(0,10)
	apxir_vc	= range(0,10)
	apxr_vc		= range(0,10)
	apxr_vc_mean 	= range(0,10)
	apxr_vc_errorl 	= range(0,10)
	apxr_vc_errorh 	= range(0,10)
	ind = range(0,10)
	for i in range(0,10):
		G=nx.erdos_renyi_graph(200,0.01*(i+1))
		#G = nx.random_regular_graph((i+1)*5, 50)
		#G = nx.powerlaw_cluster_graph(50, i+2, 0.0)		
		temp_data = range(0,100)
		for j in range(0,100):
			process = Popen(["../build/programming3", utils.dmax(G),"r"], stdout=PIPE)	
			(output, err) = process.communicate()
			exit_code = process.wait()
			data = re.findall(r"[-+]?\d*\.\d+|\d+",output)	
			data = [float(s) for s in data]
			temp_data[j]=data[0]	
		#Random
		apxr_vc_mean[i]  	= np.mean(temp_data)
		apxr_vc_errorl[i] 	= np.min(temp_data)-np.mean(temp_data) 
		apxr_vc_errorh[i] 	= np.mean(temp_data)-np.max(temp_data)
		apxr_vc[i] 		= temp_data

		#Greedy		
		process = Popen(["../build/programming3", utils.dmax(G),"g"], stdout=PIPE)	
		(output, err) = process.communicate()
		exit_code = process.wait()
		apxg_vc[i] = int(output)

		#Greedy Improved
		process = Popen(["../build/programming3", utils.dmax(G),"i"], stdout=PIPE)	
		(output, err) = process.communicate()
		exit_code = process.wait()
		apxi_vc[i] = int(output)

		#Greedy Improved Reversed
		process = Popen(["../build/programming3", utils.dmax(G),"!"], stdout=PIPE)	
		(output, err) = process.communicate()
		exit_code = process.wait()
		apxir_vc[i] = int(output)

	#plt.errorbar(ind,apxr_vc_mean,[apxr_vc_errorl,apxr_vc_errorh],fmt='-bo')
	b1 = plt.plot(ind,apxr_vc_mean,'-kx',label='Random Heuristic')
	plt.boxplot(apxr_vc, sym='k+', positions=ind,notch=1)
	b3 = plt.plot(ind,apxg_vc,'-.ro',label='Greedy Heuristic')
	b4 = plt.plot(ind,apxi_vc,'-g^',label='Greedy Heuristic & Max Greedy Cover Pruning')
	b5 = plt.plot(ind,apxir_vc,'--bs',label='Greedy Heuristic & Min Greedy Cover Pruning')
	plt.ylabel('Size Vertex Cover')
	plt.xlabel('Graph Connectivity')
	plt.legend(loc='lower right')
	fig.savefig('generate_data.png', dpi=750)
	plt.show()
	#return (ind,apxr_vc_mean,[apxr_vc_errorl,apxr_vc_errorh],apxg_vc)

def averageNodeData():
	sizeOfCover = range(0,200)
	averageRemovedEdges = range(0,200)

	G = nx.erdos_renyi_graph(500,0.1)		
	temp_data = range(0,200)
	for j in range(0,200):
		process = Popen(["../build/programming3", utils.dmax(G),"r"], stdout=PIPE)	
		(output, err) = process.communicate()
		print(output)
		exit_code = process.wait()
		data = re.findall(r"[-+]?\d*\.\d+|\d+",output)	
		data = [float(s) for s in data]	
		print(data)
		sizeOfCover[j] = data[0]
		averageRemovedEdges[j] = data[1]
	plt.plot(averageRemovedEdges, sizeOfCover, 'ro')
	plt.ylabel('Size Vertex Cover')
	plt.xlabel('Average #Node Deletions')
	fig.savefig('average_node_deletions.png', dpi=750)
	plt.show()

def histogram():
	G=nx.erdos_renyi_graph(200,0.05)
	temp_data = range(0,1000)
	for j in range(0,1000):
			process = Popen(["../build/programming3", utils.dmax(G),"r"], stdout=PIPE)	
			(output, err) = process.communicate()
			exit_code = process.wait()
			data = re.findall(r"[-+]?\d*\.\d+|\d+",output)	
			data = [float(s) for s in data]
			temp_data[j]=data[0]
	(n,bins,patches)=pl.hist(temp_data,10,normed=1,histtype='bar',color='Burlywood',label='Histogram')
	y = plt.mlab.normpdf(bins,np.mean(temp_data),np.std(temp_data))
	pl.plot(bins,y,'k--',linewidth=1.5,label='Fitted Gaussian')
	plt.legend()
	plt.xlabel('Size Vertex Cover')
	plt.ylabel('Probability')
	fig.savefig('histogram.png', dpi=750)
	pl.show()
	
	
histogram();
generate_data()
averageNodeData()

#(ind,apxr_vc_mean,apxr_vc_error,apxg_vc) = generate_data()
#print(apxr_vc_error)
#plt.errorbar(ind,apxr_vc_mean,apxr_vc_error,fmt='-bo')
#plt.plot(ind,apxg_vc,'-ro')
#plt.show()

	
#(ind,data) = generate_data()
#print(data)
#print(ind)

#pl.figure(figsize=(10,6), dpi=80)
#pl.plot(ind, data, linewidth=1.0, linestyle='r--', marker='o')
#pl.savefig('plot.png', dpi=80)
#pl.show()
	
	
	
	
	
