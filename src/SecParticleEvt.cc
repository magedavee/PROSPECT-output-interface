#include <vector>
#include <TFile.h>
#include <TTree.h>
#include <TClonesArray.h>
#include <iostream>
#include "SecParticleEvt.hh"

#include <Event.hh>
ClassImp(SecParticleEvt)
using namespace std;
SecParticleEvt::SecParticleEvt(char* fname)
{
	
//	gSystem->Load("libEventLib.so");
        
	//file=new TFile("myout.root");
	file=new TFile(fname);
	TTree * pg=GetTree();
	int j=0;
	int byte=0; 
	evtAddr=new SecondaryParticleEvent();
	pg->SetBranchAddress("SecParticle",& evtAddr);
	//do
	//{
		//SecondaryParticleEvent * i=new SecondaryParticleEvent();
		//pg->SetBranchAddress("SecParticle",& i);
		//byte=pg->GetEntry(j++);
		//if(byte!=0)
			//particleEvent->push_back(i);	
	//}while(byte);
//	numMax=j-2;
	num=0;
}

SecParticleEvt::~SecParticleEvt()
{
    delete this->evtAddr;
    file->Close();
    delete this->file;
    delete this->pg;
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
	return evtAddr;
}
SecondaryParticleEvent* SecParticleEvt::GetParticleEvent(int n)
{
	this->SetNum(n);
	return this->GetParticleEvent();
}
int SecParticleEvt::GetNum()
{
	return num;
}

int SecParticleEvt::GetNumMax()
{
	return pg->GetEntries();
}

void SecParticleEvt::SetNum(int n)
{
	if(n<=GetNumMax())
	{
		num=n;
		pg->GetEntry(n);
	}
	else
		cout<<n<<"  is greater than numMax= "<<GetNumMax()<<endl;
}
