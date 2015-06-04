# PROSPECT-output-interface

INSTALL
	You need to set $PG4_LIB_DIR which should point to libEventLib.so in PROSPECT-G4
	You need to change in the SecParticleEvt.hh and IoniEvt.hh </home/mage/PROSPECT/PROSPECT-G4/include/Output/Event.hh> to the 
	absolute path Event.hh
	You need to set $PG4_CODE which should point to directory of the root directory of PROSPECT-G4
	To install make a build directory dir-build
	cd dir-build
	cmake <path to >/PROSPECT-output-interface/.
	make
	
