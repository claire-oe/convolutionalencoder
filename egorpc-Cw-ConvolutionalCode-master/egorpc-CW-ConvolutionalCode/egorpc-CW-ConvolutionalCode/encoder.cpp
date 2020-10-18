#include "encoder.h"// allows access to "encoder.h" content



encoder::encoder()
{

}

void encoder::encoderlogic(programhistory &history)// the function 
{
	for (int j = 0; j < history.inputs.size(); j++) {
		reg3 = reg2;
		reg2 = reg1;
		reg1 = history.inputs[j];

		//generator polynomials
		A = reg1;
		B = reg2 xor reg3;
		C = reg2;
		history.storeoutputandstates(A, B, C, reg1, reg2, reg3);
	}//end for
}

encoder::~encoder()
{
}
