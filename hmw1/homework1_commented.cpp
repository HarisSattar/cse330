#include <iostream>

using namespace std;

float average(float d[], int n)		// returns the average of the array d, n is the number of values entered into the array
{
	if (n == 0)    					// special case if there is 0 input then the average is 0
		return 0;
		
	float sum = 0;
	for (int i = 0; i < n; i++) {	// goes through the array and adds all the values up
		sum += d[i];				// same as sum = sum + d[i]
	}
	return sum / n;					// returns the sum of the array divided by how many numbers are in the array
}

float variance(float d[], int n)	// returns the variance, which is the sum of the square of a set of values - the average of the values 
{									// diveded by the number of values - 1 (n-1). formula is in the book on page 21 problem 8
	
	if (n == 0)    					// again special case if there is 0 input then the variance doesnt exist
		return 0;
		
	float sum = 0;					// this will store the sum of the (values - average values)^2
	float avrg = average(d, n);		// this is the average of the array. uses the average function we wrote on top.
	
	for (int i = 0; i < n; i++) {	// goes through the array
		d[i] -= avrg;				// puts the value in the d array - the average of d array into the squared array
		d[i] *= d[i];				// squares the value that we put in the step before
		sum += d[i];				// adds the squared values up and stores it in sum
	}
	
	return sum / (n - 1);			// returns the variance (in the book the sum is the numerator of the formula and n-1 is the denominator)
}

int main()
{
	float value;					// stores what you will be typing into the terminal
	int numbers = 0;				// count how many numbers you inputed in the rerminal
	float d[100];					// array of 100 floats called d 
	
	for(int i = 0; i < 100 && cin >> value; i++) {			// loop through until it gets 100 hundred inputs or there is no more input left(Cntrl + D)
		d[i] = value;										// put the values you entered in to the array d
		numbers++;											// increase the number counter by 1
	}
	
	cout << "average = " << average(d, numbers) << endl;	// call to the average function
	cout << "variance = " << variance(d, numbers) << endl;	// call to the variance function
}

// to test the program for your input type: 1 2 3 4
// make sure your numbers are seperated by spaces.
// then press [enter]
// then press [Cntrl + d]
// your output should be : average = 2.5
//						   variance = 1.66667
