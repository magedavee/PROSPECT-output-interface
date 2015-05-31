#include <iostream>
#include <string>
#include <vector>
#include <TFile.h>
#include <TTree.h>
#include <TClonesArray.h>
#include "PrimEvt.hh"

#include <Event.hh>
using namespace std;
PrimEvt::PrimEvt()
{
	
//	gSystem->Load("libEventLib.so");
        
	file=new TFile("myout.root");
	particleEvent=new vector<ParticleEvent*>();
	TTree * pg=GetTree();
	int j=0;
	int byte=0; 	
	do
	{
		ParticleEvent * i=new ParticleEvent();
		pg->SetBranchAddress("Prim",& i);
		pg->GetEntry(j++);
		if(byte!=0)
			particleEvent->push_back(i);	
	}while(byte);
	cout<<j<<endl;
	numMax=j-2;
	num=0;
}

PrimEvt::~PrimEvt()
{
}

TTree* PrimEvt::GetTree()
{
	TTree* pg;
	pg=(TTree*) file->Get("PG4");
	return pg;
}
TClonesArray* PrimEvt::GetParticles()
{
	return GetParticleEvent()->particles;
}

ParticleVertex* PrimEvt::GetVertex(int n)
{
	if(GetParticleEvent()->nParticles>n)
		return (ParticleVertex*)GetParticles()->At(n);
	else
	{	
		cout<<n<<" outbounds returing 0\n";
		return (ParticleVertex*)GetParticles()->At(0);
	}
		
}

ParticleEvent* PrimEvt::GetParticleEvent()
{
	return particleEvent->at(num);
}
int PrimEvt::GetNum()
{
	return num;
}

int PrimEvt::GetNumMax()
{
	return numMax;
}

void PrimEvt::SetNum(int n)
{
	if(n<numMax)
		num=n;
	else
		cout<<n<<"  is greater than numMax= "<<numMax<<endl;
}
