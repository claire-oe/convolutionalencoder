#pragma once
//using standard libraries
#include <iostream>//using std::cout; std::cin; std::endl;
#include <fstream>
#include <iomanip>
#include <string>//using C++ standard string class
#include <bitset>
#include <sstream>
#include "encoder.h"
#include "programhistory.h"

using namespace std;

//encoderprogram class definition
class encoderprogram
{
public:
	encoderprogram();
	~encoderprogram();
	//declaration of the encoderprogram method
	void enterinputtype();// declares function responsible for taking user input type and then collecting the input
	void encoderlogic();//declares a funtion to call the encoder logic function
	void displaytrellis();// declares function responsible for displaying the trellis diagram and maybe saving it as a textfile

	int Thetextfileinput;//creating an integer
	char inputtype, saveoption;//creating a ch
	string filename, textfileinput, inputsequence, trellisoutputstring;
	stringstream trellisoutput;// declares a stream class to operate on strings
	ofstream outputTextFile; // Creates an instance of ofstream 
	ifstream inputTextFile; // Creates an instance of ifstream 
	programhistory history;//includes the program history 
	encoder encoder1;//includes the encoder
};

