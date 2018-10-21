/*
2. Write a function that takes as a parameter an integer (as a long value) and prints the number
of odd, even, and zero digits in the long integer.
*/

# include<iostream>
using namespace std;

int checkDigit(long num){
	int odd = 0, even = 0, zero = 0, digit;

  	while (num > 0){
  		digit = num % 10;

		if (digit == 0){
 			zero += 1;
		}

  		else if (digit % 2 == 0){
  			even += 1;
		}

		else if (digit % 2 != 0){
			odd += 1;
		}

		num = num / 10;
    }
	cout << "odd digits : " << odd << "\neven digits : " << even << "\nzero digits : " << zero << endl;
	return 0;
}

int main(){
	cout << "Checking the number of odd, even, and zero digits in the long integer" << endl;
	cout << "Test 1\nnumber = 32290001\nOutput : \n";
	checkDigit(32290001);
	cout << "Test 2\nnumber = 90001\nOutput : \n";
	checkDigit(90001);
	cout << "Test 3\nnumber = 10101010\nOutput : \n";
	checkDigit(10101010);	
}
