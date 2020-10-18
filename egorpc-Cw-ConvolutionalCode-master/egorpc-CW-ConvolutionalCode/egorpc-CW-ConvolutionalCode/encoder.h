#pragma once
#include "programhistory.h"// allows access to "encoderprogram.h" content

using namespace std;

//encoder class definition
class encoder
{
public:
	encoder();
	~encoder();
	//declaration of the encoder method

	int reg1 = 0, reg2 = 0, reg3 = 0;//initialises all the shift registers
	int A, B, C;//initialises the outputs

    //funtion that calculates the output and the states 
	void encoderlogic(programhistory &history);

};

