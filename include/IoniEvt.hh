/*
 * This is a helpper class to access ScIoni branch in the output tree easly
 *
 */
#ifndef PMTHIT_HH

#define PMTHIT_HH
#include <string>
#include <vector>
#include <TTree.h>
#include <TClonesArray.h>
#include </home/mage/PROSPECT/PROSPECT-G4-Sec/include/Output/Event.hh>
class IoniEvt
{
private:
	TFile *file;
	IoniClusterEvent * evtAddr;
	TTree * pg;
	int num;
	double time;
	//This takes each event in the ScIoni branch an puts them in a vector
public:
	//construtor
	IoniEvt(char * fname);
	~IoniEvt();
	// this is the lowest level of the structur. This gives you information on particular recoreded interaction
	IoniCluster* GetIoni(int n);
	// This will get a the event num IoniClusterEvent which is the top level stucture. 
	// Members that can be accesed are nIoniClust=the number of objects in  clusts, and clusts the structure contains all even information 
	IoniClusterEvent* GetIoniEvent();
	//this will allow you get any event and update num
	IoniClusterEvent* GetIoniEvent(int n);
	//returns the event tree for direct manipulation  
	TTree* GetTree();
	// This Array keeps all the interaction generated by a single event
	TClonesArray* GetClusts();
	//allows you the event you are looking at
	void SetEventNum(int);
	//tells you what even you are looking at
	int GetNum();
	//gets the max event
	int GetNumMax();
	//give length of time for this even.
	double GetTime();
	//gives you energy deposited for this even
	double GetEIoni();


};


#endif 
