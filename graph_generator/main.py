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
	xaxis = range(0,10)
	ind = range(0,10)
	for i in range(0,10):
		print(str(i+1)+" ")
		#G=nx.erdos_renyi_graph(200,0.01*(i+1))
		#xaxis[i] = 0.01*(i+1)
		G = nx.random_regular_graph((i+1)*10, 101)
		xaxis[i] = (i+1)*10
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

	plt.errorbar(ind,apxr_vc_mean,[apxr_vc_errorl,apxr_vc_errorh],fmt='-bo')
	plt.ylabel('Size Vertex Cover')
	plt.xlabel('% Graph Connectivity')
	#Random and Greedy
	b1 = plt.plot(xaxis,apxr_vc_mean,'-kx',label='Random Heuristic')
	plt.boxplot(apxr_vc, sym='k+', positions=xaxis,notch=1)
	b3 = plt.plot(xaxis,apxg_vc,'-.ro',label='Greedy Heuristic')
	plt.legend(loc='lower right')
	plt.savefig('RandomGreedy.png', dpi=100)
	#With pruning
	b4 = plt.plot(xaxis,apxi_vc,'-g^',label='Greedy Heuristic & Min Greedy Cover Pruning')
	b5 = plt.plot(xaxis,apxir_vc,'--bs',label='Greedy Heuristic & Max Greedy Cover Pruning')
	plt.legend(loc='lower right')
	plt.savefig('Pruning.png', dpi=100)
	#plt.show()
	#return (ind,apxr_vc_mean,[apxr_vc_errorl,apxr_vc_errorh],apxg_vc)

def averageNodeData():
	sizeOfCover = range(0,200)
	averageRemovedEdges = range(0,200)

	G = nx.erdos_renyi_graph(100,0.05)		
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
	plt.xlabel('Average #Edge Deletions per Iteration')
	plt.savefig('average_node_deletions.png', dpi=100)
	#plt.show()

def histogram():
	
	for i in range(1,10):
		G=nx.erdos_renyi_graph(100,0.01*i)
		temp_data = range(0,500)
		for j in range(0,500):
				process = Popen(["../build/programming3", utils.dmax(G),"r"], stdout=PIPE)	
				(output, err) = process.communicate()
				exit_code = process.wait()
				data = re.findall(r"[-+]?\d*\.\d+|\d+",output)	
				data = [float(s) for s in data]
				temp_data[j]=data[0]
		plt.clf()
		pl.clf()		
		(n,bins,patches)=pl.hist(temp_data,5,normed=1,histtype='bar',color='Burlywood',label='Histogram '+str(0.2*i))
		y = plt.mlab.normpdf(bins,np.mean(temp_data),np.std(temp_data))
		pl.plot(bins,y,'k--',linewidth=1.5,label='Fitted Gaussian')
		plt.legend()
		plt.xlabel('Size Vertex Cover')
		plt.ylabel('Probability')
		plt.savefig('histogram' + str(0.2*i) + '.png', dpi=100)
		#pl.show()

def benchmarks():
	
	apxg_vc		= range(0,5)
	apxi_vc		= range(0,5)
	apxir_vc	= range(0,5)
	apxr_vc		= range(0,5)
	apxr_vc_mean 	= range(0,5)
	apxr_vc_errorl 	= range(0,5)
	apxr_vc_errorh 	= range(0,5)
	xaxis 		= range(0,5)
	ind 		= range(0,5)
	mincover	= [420,420,420,420,420]

	filename = "frb30-15-"
	for i in range(0,5):
		graph = "../files/" + filename + "/" + filename + str(i+1) + ".mis"
		xaxis[i] = i
		temp_data = range(0,50)
		print(i)
		for j in range(0,50):
			print(j)
			process = Popen(["../build/programming3", graph,"rf"], stdout=PIPE)	
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
		print("trace1")	
		process = Popen(["../build/programming3", graph,"gf"], stdout=PIPE)	
		(output, err) = process.communicate()
		exit_code = process.wait()
		apxg_vc[i] = int(output)
		
		#Greedy Improved
		print("trace2")		
		process = Popen(["../build/programming3", graph,"if"], stdout=PIPE)	
		(output, err) = process.communicate()
		exit_code = process.wait()
		apxi_vc[i] = int(output)

		#Greedy Improved Reversed
		print("trace3	")
		process = Popen(["../build/programming3", graph,"!f"], stdout=PIPE)	
		(output, err) = process.communicate()
		exit_code = process.wait()
		apxir_vc[i] = int(output)

	b0 = plt.plot(xaxis,mincover,'-r',label='optimum', linewidth=3.0)	
	plt.errorbar(ind,apxr_vc_mean,[apxr_vc_errorl,apxr_vc_errorh],fmt='-bo')
	plt.ylabel('Size Vertex Cover')
	plt.xlabel('Benchmark')
	plt.ylim = [400,450]
	#Random and Greedy
	b1 = plt.plot(xaxis,apxr_vc_mean,'-kx',label='Random Heuristic')
	plt.boxplot(apxr_vc, sym='k+', positions=xaxis,notch=1)
	b3 = plt.plot(xaxis,apxg_vc,'-.ro',label='Greedy Heuristic')
	#plt.legend(loc='lower right')
	plt.savefig('BenchRandomGreedy.png', dpi=100)
	#With pruning
	b4 = plt.plot(xaxis,apxi_vc,'-g^',label='Greedy Heuristic & Min Greedy Cover Pruning')
	b5 = plt.plot(xaxis,apxir_vc,'--bs',label='Greedy Heuristic & Max Greedy Cover Pruning')
	#plt.legend(loc='lower right')
	plt.savefig('BenchPruning.png', dpi=100)
	#plt.show()


#benchmarks()	
#histogram();
generate_data()
#averageNodeData()

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
	
	
	
	
	
