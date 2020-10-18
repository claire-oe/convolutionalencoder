#include "encoderprogram.h"// allows access to "encoderprogram.h" content



encoderprogram::encoderprogram()
{
}

void encoderprogram::enterinputtype()//defining function responsible for taking user input type and then collecting the input
{
	cout << "Please choose between the following options:" << endl;
	cout << "Enter F or f to enter the input filename " << endl;
	cout << "Enter S or s to register the input sequence directly to the console" << endl;
	cin >> inputtype ;// the input choice of the user
	cout << "\n";

	if (inputtype == 'F' || inputtype == 'f') {// first input choice: enter the input filename 
		cout << "please enter the input textfile" << endl;
		cin>> filename;//input file name


		inputTextFile.open(filename);// open the file named
		if (inputTextFile.is_open()) {
			// get length of file
			inputTextFile.seekg(0, inputTextFile.end);
			int magnitude = inputTextFile.tellg();
			inputTextFile.seekg(0, inputTextFile.beg);
			if (magnitude == 0) // check if magnitude of the file is 0 the if it is a blank textfile
			{
				cout << "The file is empty, hence this program will terminate now." << endl;
				exit(EXIT_FAILURE);
			}//end if
			else {
				cout << "File read successfully" << endl;
			}//end else
			while (!inputTextFile.eof()) //while the program still runs
			{
				getline(inputTextFile, textfileinput, ';');
				if (textfileinput.length() == 0)
				{
					cout << endl;
					break;
				}//end if
				Thetextfileinput = stoi(textfileinput);
				if (Thetextfileinput != 0 && Thetextfileinput != 1) {
					cout << "Wrong format of input in the text file, hence this program will terminate now.";
					exit(EXIT_FAILURE);
				}//end if
				history.storeinput(Thetextfileinput);

			}//end while
		}

	}//end if
	inputTextFile.close();

	if (inputtype == 'S' || inputtype == 's') {

		cout << "Please enter input sequence" << endl;
		cin >> inputsequence;
		for (int i = 0; i < inputsequence.size(); i++)
		{
			int Theinputsequence = inputsequence[i] - 48;
			history.storeinput(Theinputsequence);
		}//end for

	}// end if
	 if (inputtype != 'F' && inputtype != 'f' && inputtype != 'S' && inputtype != 's') {// error check for user inputtype choice, result for choicing out of the given options
		cout << "Oops! you did not enter F or f or S or s" << endl;
		exit(EXIT_FAILURE);
	}//end if
 
}// end enterinputtype
     

void encoderprogram::encoderlogic()
{
	encoder1.encoderlogic(history);// defining funtion that calls the encoder logic from the class encoder
}

void encoderprogram::displaytrellis()
{

  trellisoutput << "Trellis diagram showing the state changes: " << endl;
  trellisoutput << "Input : n\\a,"; 
  for (int i = 0; i < history.inputs.size(); i++) {
	  trellisoutput << setw(4) << setfill(' ');///sets with of the output to 4
	  trellisoutput << history.inputs[i] << ",";
  }
  trellisoutput << endl << "Output: n\\a,";
  for (int i = 0; i < history.outputs.size(); i++) {
	  if (i % 3 == 0) trellisoutput << ", ";//groups the digits in sets of three's
	  trellisoutput << history.outputs[i];
  }
  trellisoutput << endl << "Current State:" << endl;
  for (int i = 0; i < 8; i++) {//assigns the maximum vaue of the decimal to 8
	  trellisoutput << bitset<3>(i) << "(" << i << ")" <<":";//converts the decimal vaue to 3 bit binary digits
	  for (int j = 0; j < history.registerstates.size(); j = j + 3)
	  {
		  int result = history.registerstates[j + 2] + history.registerstates[j + 1] * 2 + history.registerstates[j] * 4;// converts binary values to decimal value
		  if (result == i)// compares the result integers with the displayed current state
			  trellisoutput << " x :";
		  else trellisoutput << "   :";
	  }
	  trellisoutput << endl;
	 
  }
  trellisoutputstring = trellisoutput.str();//converts the stringstream to regular string
  cout << trellisoutputstring;// prints the output diagram
  cout << "Please enter Y or y, if would you like to save the output in a textfile" << endl;
  cin >> saveoption;
  cout << endl;
  if (saveoption == 'Y' || saveoption == 'y') {
	  trellisoutputstring = trellisoutput.str();
	  outputTextFile.open("trellis.txt");// opens text file
	  outputTextFile << trellisoutputstring;//pushes string into the textfile
	  outputTextFile.close();// closes textfile
	  cout << "Saved to file trellis.txt" << endl;
  }
  else
	  cout << "okay!";
  return;
}
encoderprogram::~encoderprogram()
{
}
