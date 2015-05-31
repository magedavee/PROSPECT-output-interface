import ROOT
from ROOT import gROOT

def initROOT():
	print "Init ROOT"
	gROOT.ProcessLine(".L /home/mage/PROSPECT/PROSPECT-G4-build/lib/libEventLib.so")
	gROOT.ProcessLine(".L /home/mage/Evt-root/Evt-build/libSecParticleEvt.so")
