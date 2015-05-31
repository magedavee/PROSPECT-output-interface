#ifndef PRIMCON_HH

#define PRIMCON_HH
#include <string>
#include <vector>
#include <TTree.h>
#include <TClonesArray.h>
#include <Event.hh>
class PrimEvt
{
private:
	TFile *file;
	int num, numMax;
	std::vector<ParticleEvent*> *particleEvent;
public:
	PrimEvt();
	~PrimEvt();
	ParticleVertex* GetVertex(int n);
	ParticleEvent* GetParticleEvent();
	TTree* GetTree();
	TClonesArray* GetParticles();
	void SetNum(int);
	int GetNum();
	int GetNumMax();


};


#endif 
