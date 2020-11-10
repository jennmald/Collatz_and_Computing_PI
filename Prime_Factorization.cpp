// Jennefer Maldonado
// Date Due November 13 2020

#include <iostream>
#include <vector>
using namespace std;

// Question 1
// Function takes a number and determines if it is a prime
bool isprime(int n){
	// set to true by default
	bool result = true;
	// loop through starting at 2 and ending 
	// half way through the integer (sufficent)
	for (int i = 2; i<(n);i++){
		// check if there is no remainder
		if (n%i == 0){
			// if there's no remainder it can
			// be divided evenly into some other
			// integer therefore it is prime
			result = false;
			break; // no need to check longer
		}
	}
	return result;
}

// Tests the function that is implemented above
void test_isprime(){
	std::cout << "isprime(2) = "<< isprime(2) << '\n';
	std::cout << "isprime(10) = "<< isprime(10) << '\n';
	std::cout << "isprime(17) = "<< isprime(17) << '\n';
	std::cout << "isprime(4) = "<< isprime(4) << '\n';
	std::cout << "isprime(6) = "<< isprime(6) << '\n';
	// extra testing
	//std::cout << "isprime(3) = "<< isprime(3) << '\n';
	//std::cout << "isprime(5) = "<< isprime(5) << '\n';
	//std::cout << "isprime(21) = "<< isprime(21) << '\n';
	//std::cout << "isprime(97) = "<< isprime(97) << '\n';
	//std::cout << "isprime(66) = "<< isprime(66) << '\n';
	//std::cout << "isprime(73) = "<< isprime(73) << '\n';
}

// Question 2
// Function to find all the factors of  integer
std::vector<int>factorize( int n ){
	std::vector<int> answer;
	// loop through from 1 to n
	for(int j = 1; j<=n; j++){
		// check each number to see if it's a factor
		if(n%j == 0){
			// add to list if it is
			answer.push_back (j);
		}
	}
	return answer;
}

// Helper function to print vectors
void print_vector(std:: vector<int> v){
	// loop through starting at zero until length of vector
	for(int i = 0; i<v.size(); i++){
		std::cout << v[i] << ' ';
	}
	std::cout << '\n';
}


void test_factorize(){
	print_vector(factorize(2));
	print_vector(factorize(72));
	print_vector(factorize(196));
	print_vector(factorize(97));
}

// Question 3
// Function to find the prime factorization of a number
std::vector<int> prime_factorize( int n ){
	std:: vector<int> answer;
	std:: vector<int> factors = factorize(n);
	for(int i = 1; i<factors.size(); i++){
		int f = factors[i];
		if (isprime(f)){
			while(n%f==0){
				answer.push_back(f);
				n = n/f;
			}
		}
	}
	return answer;
}

void test_prime_factorize(){
	print_vector(prime_factorize(2));
	print_vector(prime_factorize(72));
	print_vector(prime_factorize(196));
}

//main method for testing
int main(){
	std::cout << "Testing Prime:\n";
	test_isprime();
	std::cout << "Testing Factorize:\n";
	test_factorize();
	std::cout << "Testing Prime Factorize:\n";
	test_prime_factorize();
}