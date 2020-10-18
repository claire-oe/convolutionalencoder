#include "programhistory.h"// allows access to "encoderprogram.h" content



programhistory::programhistory()
{
	//set all values back to zero
	registerstates.push_back(0);
	registerstates.push_back(0);
	registerstates.push_back(0);
}

//definition of methods decalared in header file
//stores the input
void programhistory::storeinput(int  input)
{
	inputs.push_back(input);
}
//stores the output and and current state values
void programhistory::storeoutputandstates(int A, int B, int C, int SR1, int SR2, int SR3)
{
	outputs.push_back(A);
	outputs.push_back(B);
	outputs.push_back(C);

	registerstates.push_back(SR1);
	registerstates.push_back(SR2);
	registerstates.push_back(SR3);
}

programhistory::~programhistory()
{
}
