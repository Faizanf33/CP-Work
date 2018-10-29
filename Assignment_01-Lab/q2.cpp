/*
Name: Faizan Ahmad
Creation Date: 28/10/2018
Problem Description: Calculate sum of the following serieses:

    sin x = x - x^3/3! + x^5/5! - x^7/7! + ...

    cos x = 1 - x^2/2! + x^4/4! - x^6/6! + ...
    
    tan x = x - x^3/3! + 2(x^5)/15! - 17(x^7)/315! + ...
*/

# include <iostream>
using namespace std;

int pow(int base, int exp);

float fact(int num);

int main(){
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
