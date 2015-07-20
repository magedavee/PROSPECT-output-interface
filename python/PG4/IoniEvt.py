import ROOT 
from ROOT import gROOT
import numpy as np
import matplotlib.pyplot as plt

class IoniEvt:
    def __init__(self,filename):
	self.sp=ROOT.IoniEvt(filename)
	self.vertex={"x":0,"y":0,"z":0,"px":0,"py":0,"pz":0,"vol":0,"E":0,"pid":0,"l":0,"t":0}

###############sets the event number###########################
    def setEvtNum(self,num):
	self.sp.SetEventNum(num)

##Gets an event, return the current event if no num is given###
    def getEvt(self,num=None):
	if num is None:
	    return self.sp.GetIoniEvent()
	else:
	    return self.sp.GetIoniEvent(num)

################Gets a vertex in this event####################
    def getVertex(self,num):
	vert= self.sp.GetIoni(num)
	self.vertex["x"]=vert.x[0]
	self.vertex["y"]=vert.x[1]
	self.vertex["z"]=vert.x[2]
	self.vertex["vol"]=vert.vol
	self.vertex["pid"]=vert.PID
	self.vertex["l"]=vert.l
	self.vertex["E"]=vert.E
	self.vertex["t"]=vert.t
	self.vertex["dt"]=vert.dt
	return self.vertex

##############Get the total numeber of Event####################
    def getTotEvt(self):
	return self.sp.GetNumMax()

##############Get the current Event number######################
    def getEvtNum(self):
	return self.sp.GetNum()

##############Get the current Event energy######################
    def getEvtEnergy(self):
	return self.sp.GetEIoni()
##############Get the number of detectec for current event######
    def getNumCluster(self):
	return self.sp.GetIoniEvent().nIoniClusts
    
#############Shows hist of the number of particles detected######
    def showClustersHis(self):
	total=self.getTotEvt()
	num=[]
	for i in xrange(0,total):
	    det=self.getEvt(i).nIoniClusts
	    num.append(det)
	plt.hist(num)
	plt.ylabel("frequency")
	plt.title("Number of Clusters")
	plt.show()

#############Shows hist of a vertext property for this event#####
    def plotEvtProp(self,name):
	total=self.getNumCluster()
	num=[]
	for i in xrange(0,total):
	    vert=self.getVertex(i)
	    num.append(vert[name])
	plt.hist(num)
	plt.ylabel("frequency")
	plt.title("Event "+str(self.getEvtNum())+" "+name)
	plt.show()
#############Shows hist of a vertext property for this event#####
    def plotTotProp(self,name):
	num=[]
	evt=self.getTotEvt()
	for j in xrange(0,evt):
	    self.setEvtNum(j)
	    total=self.getNumCluster()
	    for i in xrange(0,total):
		vert=self.getVertex(i)
		num.append(vert[name])
	plt.hist(num)
	plt.ylabel("frequency")
	plt.title("total "+name)
	plt.show()

#################################################################
