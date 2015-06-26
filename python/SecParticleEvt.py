import ROOT 
from ROOT import gROOT
import numpy as np
import matplotlib.pyplot as plt

class SecParticleEvt:
    def __init__(self,filename):
	 gROOT.ProcessLine(".L /home/mage/PROSPECT/PROSPECT-G4-build/lib/libEventLib.so")
	 gROOT.ProcessLine(".L /home/mage/Local/lib/libSecParticleEvt.so")
	 gROOT.ProcessLine(".L /home/mage/Local/include/SecParticleEvt.hh")
	 self.sp=ROOT.SecParticleEvt(filename)

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
	return self.sp.GetVertex(num)

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



