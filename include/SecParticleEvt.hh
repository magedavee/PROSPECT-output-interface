#ifndef SEC_HH

#define SEC_HH
#include <string>
#include <vector>
#include <TTree.h>
#include <TClonesArray.h>
#include <TObject.h>
#include </home/mage/PROSPECT/PROSPECT-G4-Sec/include/Output/Event.hh>
class SecParticleEvt:public TObject
{
private:
	TFile *file;
	int num, numMax;
	std::vector<SecondaryParticleEvent*> *particleEvent;
public:
	SecParticleEvt(char* fname);
	ClassDef(SecParticleEvt,1);
	~SecParticleEvt();
	//gives the information at vertex, this is lowest level of information
	SecondaryParticleVertex* GetVertex(int n);
	//Return the top level of the event, gives you information about number of vertexs
	SecondaryParticleEvent* GetParticleEvent();
	SecondaryParticleEvent* GetParticleEvent(int n);
	TTree* GetTree();
	//returns the iterator 
	TClonesArray* GetParticles();
	void SetNum(int);
	int GetNum();
	int GetNumMax();


};


#endif 
