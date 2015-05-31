#ifndef SEC_HH

#define SEC_HH
#include <string>
#include <vector>
#include <TTree.h>
#include <TClonesArray.h>
#include <TObject.h>
#include </home/mage/PROSPECT/PROSPECT-G4/include/Output/Event.hh>
class SecParticleEvt:public TObject
{
private:
	TFile *file;
	int num, numMax;
	std::vector<SecondaryParticleEvent*> *particleEvent;
public:
	SecParticleEvt();
	ClassDef(SecParticleEvt,1);
	~SecParticleEvt();
	SecondaryParticleVertex* GetVertex(int n);
	SecondaryParticleEvent* GetParticleEvent();
	TTree* GetTree();
	TClonesArray* GetParticles();
	void SetNum(int);
	int GetNum();
	int GetNumMax();


};


#endif 
