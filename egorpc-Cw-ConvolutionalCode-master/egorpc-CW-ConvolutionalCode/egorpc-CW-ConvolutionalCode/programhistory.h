#pragma once
#include<vector>//using C++ standard vector class

using namespace std;

class programhistory
{
public:
	programhistory();
	~programhistory();
   
	//declares methods for storage of all the inputs, outputs and register states
	void storeinput(int input);
	void storeoutputandstates(int A, int B, int C, int SR1, int SR2, int SR3);

	//vectors to store inputs, outputs and register states
	vector<int>inputs;
	vector<int>outputs;
	vector<int>registerstates;
};

