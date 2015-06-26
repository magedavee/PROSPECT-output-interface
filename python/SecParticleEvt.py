import ROOT 
from ROOT import gROOT

class SecParticleEvt:
    def __init__(self,filename):
	 gROOT.ProcessLine(".L /home/mage/PROSPECT/PROSPECT-G4-build/lib/libEventLib.so")
	 gROOT.ProcessLine(".L /home/mage/Local/lib/libSecParticleEvt.so")
	 gROOT.ProcessLine(".L /home/mage/Local/include/SecParticleEvt.hh")
	 self.sp=ROOT.SecParticleEvt(filename)

###############sets the event number##########################
    def setEvtNum(self,num):
	self.sp.SetNum(num)

##Gets an event, return the current event if no num is given##
    def getEvt(self,num):
	if num is None:
	    return self.sp.GetParticleEvent()
	else:
	    return self.sp.GetParticleEvent(num)

################Gets a vertex in this event###################
    def getVertex(self,num):
	return self.sp.GetVertex(num)
