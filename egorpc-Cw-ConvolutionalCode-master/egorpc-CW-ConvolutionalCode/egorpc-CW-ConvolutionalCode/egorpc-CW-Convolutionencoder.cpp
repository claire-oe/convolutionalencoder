#include <iostream>//using std::cout; std::cin; std::endl;
#include <string>//using C++ standard string class
#include "encoderprogram.h"//allow access to content of "encoderprogram.h"
#include "encoder.h" //allow access to content of "encoder.h"

using namespace std;

int main() {
	char rerun = 'Y';
	while (rerun == 'Y' || rerun == 'y') {// a loop to enable program rerun 

	cout << "This is a Convolutional encoder Program " << endl;
	cout << "Name: Claire Egorp, SID: 8149233" << endl;
	cout << "The generator polynomial will be :" << endl;
	cout << "Output A is G(100)" << endl;
	cout << "Output B is G(011)" << endl;
	cout << "Output C is G(010)" << endl;
	
		encoderprogram encoderprogram1;// create an encoderprogram object called encoderprogram1
		encoderprogram1.enterinputtype(); // excutes the "enterinputtype" method define in encoderprogram source file
		encoderprogram1.encoderlogic();  // excutes the "encoderlogic" method define in encoderprogram source file
		encoderprogram1.displaytrellis(); // excutes the "displaytrellis" method define in encoderprogram source file


		cout << endl;
		cout << "Please enter Y, If you would you like to rerun the program" << endl;
		cin >> rerun;
	}
	cout << "Thank you for using the convolutional encoder program." << endl;
	cout << "Goodbye!" << endl;

	return 0;// indicate successful termination
} // end main
