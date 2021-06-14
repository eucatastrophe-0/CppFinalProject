/*
Sam Schock
Exam 2 Part B: Recursion
Due 5/13/21
*/

#include <iostream>

using namespace std;

unsigned long long int factorial(int n);
unsigned long long int combination(int n, int r);
unsigned long long int permutation(int n, int r);

int main()
{
	int input, n, r;
	
	cout << "===== Recursive Function Demonstrator =====" << endl;

	do
	{
		cout << "\nSelect function:\n[0]Exit\n[1]Factorial\n[2]Combination\n[3]Permutation\n" << endl;
		cin >> input;

		switch (input) {
		case 0:
			break;
		case 1:
			cout << "Enter integer: " << endl;
			cin >> n;
			cout << "\n" << n << "! = " << factorial(n) << endl;
			break;
		case 2:
			cout << "C(n,r)\nEnter integer for n: ";
			cin >> n;
			cout << "Enter integer for r: ";
			cin >> r;

			cout << "\nC(" << n << "," << r << ") = " << combination(n, r) << endl;
			break;
		case 3:
			cout << "P(n,r)\nEnter integer for n: ";
			cin >> n;
			cout << "Enter integer for r: ";
			cin >> r;

			cout << "\nP(" << n << "," << r << ") = " << permutation(n, r) << endl;
			break;
		}
	} while (input != 0);
	
	return 0;
}

unsigned long long int factorial(int n)
{
	if (n > 0)
	{
		return (n * factorial(n - 1));
	}
	else
	{
		return 1;
	}
}

unsigned long long int combination(int n, int r)
{
	return (
		factorial(n) / (factorial(r) * factorial(n - r))
		);
}

unsigned long long int permutation(int n, int r)
{
	return (
		factorial(n) / factorial(n - r)
		);
}