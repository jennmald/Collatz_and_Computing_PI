// Jennefer Maldonado
// Date Due November 13 2020

#include <iostream>
#include <cmath>
using namespace std;

// helper method to compute f(x)
float f(float x){
	// computes f(x)
	float fx = sqrt(1.0 - (x*x));
	return fx;
}

// Trapezoidal Rule for the integral
// Not necessary but written for understanding
float integral(float a, float b, float N){
	// change in x 
	float delta = ((b-a)/N);
	float sum = 0.0;
	// x_k-1
	float prev = a;
	// x_k
	float next = a + delta;
	// compute the sum to approximate the integral
	for(int k = 0; k<=N; k++){
		float fs = f(prev) + f(next);
		sum = sum + ((fs/2)*delta);
		// update x_k-1 and x_k
		prev = next;
		next = a + (k*delta);
	}
	return sum;
}

// Function to estimate pi
// Uses helper method f
// Inputs: N = number of intervals
float compute_pi(float N){
	// change in x = b-a/N
	float delta = ((1)/N);
	// first element in the interval x_k-1
	float prev = 0;
	// next element in the interval x_k
	float next = delta;
	float pi = 0;
	// start the sum
	for(int k = 2; k<= N; k++){
		pi = pi +(f(prev)+f(next));
		// update x_k-1 and x_k
		prev = next;
		next = k*delta;
	}
	// multiply by 2 and deltax
	float c_pi = 2*delta*pi;
	// find the error
	float errors = M_PI - c_pi;
	std::cout << "The error is "<< errors << '\n';
	return c_pi;
}


//main method for testing
int main(){
	//std::cout << integral(0, 1 , 100000) << '\n';
	//std::cout << f(0.25) << '\n';
	std::cout << compute_pi(10000) << '\n';
	std::cout << compute_pi(100) << '\n';
	std::cout << compute_pi(1000) << '\n';
	std::cout << compute_pi(100000) << '\n';
}


// For the compiler optimization levels I tried three levels:
// -O1 
// -O2
// -O3
// From inspection I do not think each level made too 
// of a change when running the code. The function being 
// used is not too computationally expensive since it only
// has a single for loop containing addition and multipication.
// I believe that used on code dealing with matrices, or other
// large data set the compiler optimization levels would work
// better than I was able to tell for this program.