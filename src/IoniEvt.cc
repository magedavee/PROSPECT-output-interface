#include <iostream>
#include <string>
#include <vector>
#include <TFile.h>
#include <TTree.h>
#include <TClonesArray.h>
#include "./IoniEvt.hh"
#include <Event.hh>
using namespace std;
IoniEvt::IoniEvt(char *fname)
{
	cout<<"ok\n";	
	file=new TFile(fname);
	ioniEvent=new vector<IoniClusterEvent*>();
	TTree * pg=GetTree();
	int j=0;
	int byte=0;
	do	
	{
		IoniClusterEvent * i=new IoniClusterEvent();
		pg->SetBranchAddress("ScIoni",& i);
		byte=pg->GetEntry(j++);
		if(byte!=0)
			ioniEvent->push_back(i);
	}while(byte);
	numMax=j-2;
	num=0;
	file->Close();
}

IoniEvt::~IoniEvt()
{
}

TTree* IoniEvt::GetTree()
{
	TTree* pg;
	pg=(TTree*) file->Get("PG4");
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
	return ioniEvent->at(num);
}

IoniClusterEvent* IoniEvt::GetIoniEvent(int n)
{
	SetEventNum(n);
	return ioniEvent->at(num);
}
int IoniEvt::GetNum()
{
	return num;
}

int IoniEvt::GetNumMax()
{
	return numMax;
}

void IoniEvt::SetEventNum(int n)
{
	if(n<=numMax)
		num=n;
	else
		cout<<n<<"  is greater than numMax= "<<numMax<<endl;
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
