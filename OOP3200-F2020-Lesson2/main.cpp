/** main.cpp
 *
 *	In this example program, did the following:
 *		- Examined a simple class with 'instance' data-members, a constructor, accessors, mutators.
 *
 *	@author		Andre Agrippa
 *	@studentID  100756090
*/


#include <iostream> 		// cin, cout
#include <iomanip>			// fixed, setprecision()
// #include <sstream> 			// stringstream
// #include <cmath>			// sqrt()
// #include <limits>			// INT_MAX, 
// #include <stdexcept>		// out_of_range
#include "MyConsoleInput.h" // ConsoleInput::ReadInteger()
#include "CartesianPoint.h"

using namespace std;

// main() function
int main()
{
	// Declarations
	// a point called 'origin', initialized to 0, 0
	CartesianPoint origin = CartesianPoint(10, 20);
	
	// a point called 'destination'
	CartesianPoint destination;

	int inputX; // temporary input variable for x
	int inputY; // temporary input variable for y
	
	// to store the distance between two points
	double distance;

	try
	{
		// Input

		// Prompt the user for the coordinates
		cout << "\nEnter coordinates of the destination point: " << endl;
		// prompt for, read, and store x coordinate:
		cout << "X: ";
		inputX = ConsoleInput::ReadInteger();
		destination.SetX(inputX);

		// prompt for, read, and store y coordinate:
		cout << "Y: ";
		inputY = ConsoleInput::ReadInteger();
		destination.SetY(inputY);


		// Processing
		// determine the distance between the two points
		//distance = origin.GetDistanceTo(destination);
		distance = origin - destination;
		cout << "Origin is equal to destination?:" << to_string(origin == destination) << endl;
		
		CartesianPoint newPoint = origin + destination;
		
		cout << "origin plus destination =" << newPoint << endl;

		// Output 
		// Show the points and the distance
		cout << fixed << setprecision(3); // formatting
		cout << "\nThe Distance between " << origin
			<< " and " << destination << " is "
			<< distance << ". " << endl;

		CartesianPoint anotherPoint;
		cout << "\nEnter another point:";
		
		cin >> anotherPoint;
		cout << "You entered:" << anotherPoint;
	}

	catch (exception& ex)
	{
		cerr << ex.what() << " Ending the program." << endl;
	}

	// done.
	cout << endl << endl;
	return 0;
} // end of main()
