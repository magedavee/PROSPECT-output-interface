import ROOT 
from ROOT import gROOT
import numpy as np
import matplotlib.pyplot as plt

class SecParticleEvt:
    def __init__(self,filename):
	self.sp=ROOT.SecParticleEvt(filename)
	self.vertex={"x":0,"y":0,"z":0,"px":0,"py":0,"pz":0,"vol":0,"E":0,"pid":0}

###############sets the event number###########################
    def setEvtNum(self,num):
	self.sp.SetNum(num)

##Gets an event, return the current event if no num is given###
    def getEvt(self,num=None):
	if num is None:
	    return self.sp.GetParticleEvent()
	else:
	    return self.sp.GetParticleEvent(num)

################Gets a vertex in this event####################
    def getVertex(self,num):
	vert= self.sp.GetVertex(num)
	self.vertex["x"]=vert.x[0]
	self.vertex["y"]=vert.x[1]
	self.vertex["z"]=vert.x[2]
	self.vertex["px"]=vert.p[0]
	self.vertex["py"]=vert.p[1]
	self.vertex["pz"]=vert.p[2]
	self.vertex["vol"]=vert.vol
	self.vertex["pid"]=vert.PID
	return self.vertex

##############Get the total numeber of Event####################
    def getTotEvt(self):
	return self.sp.GetNumMax()

##############Get the current Event number######################
    def getEvtNum(self):
	return self.sp.GetNum()

##############Get the number of detectec for current event######
    def getNumParticle(self):
	return self.sp.GetParticleEvent().nParticlesDet
    
#############Shows hist of the number of particles detected######
    def showParticlesDetHis(self):
	total=self.getTotEvt()
	num=[]
	for i in xrange(0,total):
	    det=self.getEvt(i).nParticlesDet
	    num.append(det)
	plt.hist(num)
	plt.ylabel("frequency")
	plt.title("Number of Particles detected")
	plt.show()

#############Shows hist of a vertext property for this event#####
    def plotEvtProp(self,name):
	total=self.getNumParticle()
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
	    total=self.getNumParticle()
	    for i in xrange(0,total):
		vert=self.getVertex(i)
		num.append(vert[name])
	plt.hist(num)
	plt.ylabel("frequency")
	plt.title("total "+name)
	plt.show()

#################################################################
