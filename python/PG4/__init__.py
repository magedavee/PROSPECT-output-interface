import ROOT
from ROOT import gROOT
from SecParticleEvt import SecParticleEvt
gROOT.ProcessLine(".L /home/mage/PROSPECT/PROSPECT-G4-build/lib/libEventLib.so")
gROOT.ProcessLine(".L /home/mage/Local/lib/libSecParticleEvt.so")
gROOT.ProcessLine(".L /home/mage/Local/include/SecParticleEvt.hh")
__all__=['SecParticleEvt']
