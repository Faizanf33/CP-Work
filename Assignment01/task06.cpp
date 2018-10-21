/*
6. Write a C++ program that declares an array alpha of 50 components of type double. Initialize
the array so that the first 25 components are equal to the square of the index variable, and the
last 25 components are equal to three times the index variable. Output the array so that 10
elements per line are printed.
*/
# include<iostream>
using namespace std;

double pow(int x, int power){
	double result = 1;

	if (power == 0)
		return result;
	else
		for (int i=1; i<=power; i++)
			result *= x;
		
		return result;
}


int main(){
	cout << "Array 'alpha' of '50' components" << endl;
	double alpha[50];
	
	for (int i=0; i<50; i++){
		if (i<25)
			alpha[i] = pow(i, 2);
			
		else
			alpha[i] = pow(i, 3);
	}
	
	int j=1;
	for (int i=0; i<5; i++){
		
		for (j; (j%10 != 0); j++){
			cout << alpha[j-1]<< " ";	
		}
		cout << alpha[j-1] << endl;
		j++;
	}		
	return 0;
}
