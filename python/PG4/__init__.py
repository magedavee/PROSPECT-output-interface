import ROOT
from ROOT import gROOT
from SecParticleEvt import SecParticleEvt
from IoniEvt import IoniEvt
gROOT.ProcessLine(".L /home/mage/PROSPECT/PROSPECT-G4-build/lib/libEventLib.so")
gROOT.ProcessLine(".L /home/mage/Local/lib/libSecParticleEvt.so")
gROOT.ProcessLine(".L /home/mage/Local/lib/libIoniEvt.so")
gROOT.ProcessLine(".L /home/mage/Local/include/SecParticleEvt.hh")
gROOT.ProcessLine(".L /home/mage/Local/include/IoniEvt.hh")
__all__=['SecParticleEvt','IoniEvt']
