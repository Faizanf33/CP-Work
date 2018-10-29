/*
Name: Faizan Ahmad
Creation Date: 28/10/2018
Problem Description: compute the value of exp x using the first N terms of the power series expansion.
*/

# include <iostream>
using namespace std;

int pow(int base, int exp);

float fact(int num);

double series(int x, int n);

int main(){
    cout << series(10, 10) << endl;
    return 0;
}

int pow(int base, int exp)
{
	if (exp == 0)
		return 1;

	int result = base;		
	for (int i=1; i<exp; i++)
		result *= base;
		
	return result;
}

float fact(int num)
{
    float result = num;
    
    if (num == 0)
        result = 1;
    
    else
        for (int i = (num-1); i > 0; i--)
            result *= i;
        
    return result;
}

double series(int x, int n)
{
    double exp = 0;
    for (int i = 0; i < n; i++)
        exp += (pow(x, i) / fact(i));
        
    return exp;
}
