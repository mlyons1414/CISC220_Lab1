/*
 * test.cpp
 * Matthew Lyons & Hayden Troy
 *
 * 8/30/18
 */

//
#include <iostream>
using namespace std;

//FUNCTION DECALRATIONS
void stars();
bool isPrime(int Num);
void sum();
int sumTerms(int start, int sum);
int multTable(int n);
int multTables(int n);
int Collatz();
bool isLeapYear(int yearToCheck);
void printLeapYears(int startingYear);
int xStars (int n);
void CollatzV2();
bool isPrimeRecursive(int Num, int testdivisor);
int multTableRecursive(int n, int tablevalue);

int main() {
	//PROBLEM 1
	cout << "Hello World" << endl;

	//PROBLEM 2
	stars(); //calls the function stars

	//PROBLEM 3
	if (isPrime(1))
		cout << "True" << endl; //expected
	else
		cout << "False" << endl;
	if (isPrime(3))
		cout << "True" << endl; //expected
	else
		cout << "False" << endl;
	if (isPrime(20))
		cout << "True" << endl;
	else
		cout << "False" << endl; //expected
	stars();

	//PROBLEM 4
	sum();
	stars();

	//PROBLEM 5
	cout << sumTerms(0, 100000) << endl; //448 expected
	stars();

	//PROBLEM 6
	multTable(12); //multiplication table function
	stars();

	//PROBLEM 7
	multTables(12);
	stars();

	//PROBLEM 8
	cout << Collatz() << endl; //Collatz input
	stars();

	//PROBLEM 9
	printLeapYears(2017); //prints leap years
	stars();

	//PROBLEM 10

	//PROBLEM 11
	CollatzV2();
	stars();

	//PROBLEM 12
	cout << isPrimeRecursive(15, 2) << endl;

	//PROBLEM 13
	multTableRecursive(12, 1);

	return 0;
}

/* A line of stars */
void stars() {
	cout << "*******************" << endl;
}

/* Takes in a number and returns a boolean
 * for whether the number is prime or not
 */
bool isPrime(int Num) {
	if (Num == 1)
	{
		return true;
	}
	int i = 2;
	while (Num > i) {
		if (Num % i == 0) {
			return false;
		}
		i++;
	}
	return true;
}

/* Takes in two numbers and calculates
 * the sum between the two numbers
 */
void sum() {
	int sum = 0, i;
	for (i=1; i <= 300; i++){
		sum += i;

		if (i % 20 == 0){
			cout << sum << endl;
		}
	}
}

/* Takes in two numbers and calculates
 * how many steps it takes to reach the second number
 */
int sumTerms(int start, int sum) {
	int x = 1;
	int y = 0;
	while (start < sum + 1) {
		start = start + x;
		x++;
		y++;
	}
	return y;
}

/* Takes in a number and returns the mult table
 * of the number
 */
int multTable(int n) {
    for (int i = 1; i <= 12; ++i) {
        cout << n << " * " << i << " = " << n * i << endl;
    }
    return 0;
}

/* Takes in a number and returns every mult table
 * of the number
 */
int multTables(int n) {
	for (int n = 12; n > 0; --n) {
		multTable(n);
		cout << "\n";
	}
    return 0;
}

/* Takes in a user inputed natural number and
 * returns the number of steps to get the Collatz Conjuncture
 */
int Collatz() {
	int i = 0;
	int n;
	cout << "Please enter a natural number: " << endl;
	cin >> n;
	while (n > 1) {
		if (n % 2) {
			n = n / 2;
		}
		else {
			n = n * 3 + 1;
		}
		i++;
	}
	return i;
}

/* Takes in a year and returns a boolean
 * for whether or not the year is a leap year or not
 */
bool isLeapYear(int yearToCheck) {
	if (yearToCheck % 400 == 0) {
		return true;
	} else if (yearToCheck % 100 == 0) {
		return false;
	} else if (yearToCheck % 4 == 0) {
		return true;
	} else {
		return false;
	}
}

/* Calculates all the leap years for the next 400 years
 * and prints them
 */
void printLeapYears(int startingYear) {
	int yearToCheck = startingYear;
	for (int i = 0; i < 400; i++) {
		yearToCheck++;

		if (isLeapYear(yearToCheck)) {
			cout << " " << yearToCheck << endl;
		}
	}
}

/* Takes in a number and outputs an 'X' in stars
 * with the number inputed
 */
int xStars (int n) {
	if (n % 2 == 0) {
		n = n + 1;
	}
	for (int i = 1; i < 2*n; i++) { //rows
		for (int j = 1; j < 2*n; j++) { //columns
			if (i == j){
				cout << "*";
			 	 }
			else if (i + j == 2*n){
				if(i == 1){
					cout <<"*"<< endl;
				}
				else{
					cout << "*";
				}
			}
			else if(j == 2 * n - 1){
				cout << " " << endl;
			}
			else {
				cout << " ";
			}
		}
		if (i == 2*n - 1){
			cout << "" << endl;
		}
	}
	return 0;
}

/* Collatz now with two inputs
 *
 */
void CollatzV2() {
	int n;
	int m;
	cout << "Please enter two natural numbers, the first being smaller than the second: " << endl;
	cin >> n;
	cin >> m;
	for (int n; n < m; n++) {
	while (n > 1) {
		if (n % 2) {
			n = n / 2;
		}
		else {
			n = n * 3 + 1;
		}
	}
	if (n == 1) {
	cout << "Collatz Conjecture is still working." << endl;
	}
	}
}

/* isPrime now with recursion
 *
 */
bool isPrimeRecursive(int Num, int testdivisor) {
    if (Num == 1) {
        return true;
    }
    else if (Num % testdivisor == 0 ) {
        return false;
    }
    else if (testdivisor==Num) {
        return true;
    }
    else {
        return isPrimeRecursive(Num,testdivisor + 1);
    }
}

/*multTable now with recursion
 *
 */
int multTableRecursive(int n, int tablevalue) {
	if (tablevalue == 12) {
    	 cout << n << " * " << tablevalue << " = " << n*tablevalue << endl;
    }
    else {
        cout << n << " * " << tablevalue << " = " << n*tablevalue << endl;
        multTableRecursive(n, tablevalue + 1);
    }
	return 0;
}

