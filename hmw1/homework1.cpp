/*
 ^ Haris Sattar
 * CSE 330
 *
 */
#include <iostream>

using namespace std;

float average(float d[], int n)
{
	float sum = 0;

	if (n == 0)
		return 0;

	for (int i = 0; i < n; i++)
		sum += d[i];

	return sum / n;
}

float variance(float d[], int n)
{
	float avrg = average(d, n);
	float sum = 0;

	if (n == 0)
		return 0;


	for (int i = 0; i < n; i++) {
		d[i] -= avrg;
		d[i] *= d[i];
		sum += d[i];
	}

	return sum / (n - 1);
}

int main()
{
	float value;
	int numbers = 0;
	float d[100];

	for(int i = 0; i < 100 && cin >> value; i++, numbers++)
		d[i] = value;

	cout << "average = " << average(d, numbers) << endl;
	cout << "variance = " << variance(d, numbers) << endl;
}
