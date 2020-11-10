// Jennefer Maldonado
// Date Due November 13 2020

#include <iostream>
using namespace std;
// Function to iteratively compute the Collatz 
// sequence of a number
// recieves input n as a starting point
void collatz(int n){
	// print starting point 
	std::cout << n << ' ';
	// iterate until n is 1
	while(n != 1){
		// check if even
		if (n % 2 == 0){
			// divide by 2
			n = n/2; 
			// print sequence value
			std::cout << n << ' ';
		}
		else{ // otherwise
			n = (n*3)+1;
			// print sequence value
			std::cout << n << ' ';
		}
	}// next line
	std::cout << '\n';
}

//main method for testing
int main(){
	// read in command line integer
	int n;
	cin >> n;
	// print collatz sequence
	collatz(n);
}