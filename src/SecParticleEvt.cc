#include <iostream>
#include <string>
#include <vector>
#include <TFile.h>
#include <TTree.h>
#include <TClonesArray.h>
#include "SecParticleEvt.hh"

#include <Event.hh>
ClassImp(SecParticleEvt)
using namespace std;
SecParticleEvt::SecParticleEvt()
{
	
//	gSystem->Load("libEventLib.so");
        
	file=new TFile("myout.root");
	particleEvent=new vector<SecondaryParticleEvent*>();
	TTree * pg=GetTree();
	int j=0;
	int byte=0; 	
	do
	{
		SecondaryParticleEvent * i=new SecondaryParticleEvent();
		pg->SetBranchAddress("SecParticle",& i);
		byte=pg->GetEntry(j++);
		if(byte!=0)
			particleEvent->push_back(i);	
	}while(byte);
	cout<<particleEvent->size()<<endl;
	cout<<j<<endl;
	numMax=j-2;
	num=0;
}

SecParticleEvt::~SecParticleEvt()
{
}

TTree* SecParticleEvt::GetTree()
{
	TTree* pg;
	pg=(TTree*) file->Get("PG4");
	return pg;
}
TClonesArray* SecParticleEvt::GetParticles()
{
	return GetParticleEvent()->particles;
}

SecondaryParticleVertex* SecParticleEvt::GetVertex(int n)
{
	int nParticles=GetParticleEvent()->nParticlesDet+GetParticleEvent()->nParticlesGen+GetParticleEvent()->nParticlesGenInsideSepx;
	if(nParticles>n)
		return (SecondaryParticleVertex*)GetParticles()->At(n);
	else
	{	
		cout<<n<<" outbounds returing 0\n";
		return (SecondaryParticleVertex*)GetParticles()->At(0);
	}
		
}

SecondaryParticleEvent* SecParticleEvt::GetParticleEvent()
{
	return particleEvent->at(num);
}
int SecParticleEvt::GetNum()
{
	return num;
}

int SecParticleEvt::GetNumMax()
{
	return numMax;
}

void SecParticleEvt::SetNum(int n)
{
	if(n<numMax)
		num=n;
	else
		cout<<n<<"  is greater than numMax= "<<numMax<<endl;
}
