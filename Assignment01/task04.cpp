/*
4. Write a program that reads a string and outputs the number of times each lowercase vowel
appears in it. Your program must contain a function with one of its parameters as a string
variable, and return the number of times each lowercase vowel appears in it. Also write a
program to test your function.
*/

# include<iostream>
# include<string>
using namespace std;

int checkVowel(string line){
	int v_a = 0 ,v_e = 0 ,v_i = 0 ,v_o = 0 ,v_u = 0;
	int size = line.length();
		
	for (int i=0; i<size; i++){
		if (line[i] == 'a')
			v_a += 1;

		else if (line[i] == 'e')
			v_e += 1;

		else if (line[i] == 'i')
			v_i += 1;

		else if (line[i] == 'o')
			v_o += 1;

		else if (line[i] == 'u')
			v_u += 1;
		
	}
	cout << "a : "<< v_a << "\ne : "<< v_e << "\ni : "<< v_i << "\no : "<< v_o << "\nu : "<< v_u << endl;
	return 0;
}

int main(){
	cout << "Checking the number of times each lowercase vowel appears in a string" << endl;
	cout << "Test 1\nstring = 'Testing 1'\nOutput : \n";	
	checkVowel("Testing 1");	
	cout << "Test 2\nstring = 'CheCking voWels buT onLy LowEr Ones!'\nOutput : \n";	
	checkVowel("CheCking voWels buT onLy Upper Ones!");	
	cout << "Test 3\nstring = '#testing vowels @c++ 4u!'\nOutput : \n";	
	checkVowel("#testing vowels @c++ 4u!");	
		
}
