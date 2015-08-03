#include <iostream>
#include <string>
#include <vector>
#include <TFile.h>
#include <TTree.h>
#include <TClonesArray.h>
#include "./IoniEvt.hh"
#include </home/mage/PROSPECT/PROSPECT-G4-Sec/include/Output/Event.hh>
using namespace std;
IoniEvt::IoniEvt(char *fname)
{
	file=new TFile(fname);
	pg=GetTree();
	int j=0;
	int byte=0;
	evtAddr=new IoniClusterEvent();
	pg->SetBranchAddress("ScIoni",& evtAddr);


	//do	
	//{
		//IoniClusterEvent * i=new IoniClusterEvent();
		//pg->SetBranchAddress("ScIoni",& i);
		//byte=pg->GetEntry(j++);
		//if(byte!=0)
			//ioniEvent->push_back(i);
	//}while(byte);
	num=0;
}

IoniEvt::~IoniEvt()
{
    delete this->evtAddr;
    file->Close();
    delete this->file;
    delete this->pg;
}

TTree* IoniEvt::GetTree()
{
	return pg;
}
TClonesArray* IoniEvt::GetClusts()
{
	return GetIoniEvent()->clusts;
}

IoniCluster* IoniEvt::GetIoni(int n)
{
	if(GetIoniEvent()->nIoniClusts>n)
		return (IoniCluster*)GetClusts()->At(n);
	else
	{	
		cout<<n<<" outbounds returing 0\n";
		return (IoniCluster*)GetClusts()->At(0);
	}
		
}

IoniClusterEvent* IoniEvt::GetIoniEvent()
{
	return evtAddr;
}

IoniClusterEvent* IoniEvt::GetIoniEvent(int n)
{
	SetEventNum(n);
	return evtAddr;
}
int IoniEvt::GetNum()
{
	return num;
}

int IoniEvt::GetNumMax()
{
	return pg->GetEntries();
}

void IoniEvt::SetEventNum(int n)
{
	if(n<=GetNumMax())
	{
		num=n;
		pg->GetEntry(num);
	}
	else
		cout<<n<<"  is greater than numMax= "<<GetNumMax()<<endl;
}
double IoniEvt::GetTime()
{
	if(GetIoniEvent()->nIoniClusts>0)
	{
		double delta=GetIoni(0)->t-GetIoni(GetIoniEvent()->nIoniClusts-1)->t;
		return delta;
	}
	else
		return 0;
}
double IoniEvt::GetEIoni()
{
	return GetIoniEvent()->EIoni;
}
