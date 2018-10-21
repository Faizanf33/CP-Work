/*
1. Write the definition of a function that takes as input three decimal numbers (e.g. a, b, c)
and returns the first number multiplied by the second number to the power of third number i.e.
returns (a*b)c.
*/

# include<iostream>
using namespace std;

double pow(float x, float power){
	double result = 1;

	if (power == 0){
		return 1;
	}
	else{
		for (int i=1; i<=power; i++){
			result *= x;
		}
		return result;
	}
}

double sqr2pow(float a, float b, float c){
	return pow((a * b), c);
}

int main(){
	cout << "Testing (a x b) ^ c" << endl;
	cout << "Test 1\na = 21, b = 6, c = 0\nOutput : "<< sqr2pow(21, 6, 0) << endl;
	cout << "Test 2\na = 2, b = 21, c = 3\nOutput : "<< sqr2pow(2, 21, 3) << endl;
	cout << "Test 3\na = 0, b = 0, c = 0\nOutput : "<< sqr2pow(0, 0, 0) << endl;		
}
