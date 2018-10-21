/*
8. Write a program that prompts the user to input a string and outputs the string in uppercase
letters.
*/

# include<iostream>
# include<fstream>
# include<string>
using namespace std;

string upperCase(char arr[], int size){
	string upperStr;
	
	for (int i=0; i<size; i++)
		if (arr[i] >= char(97) && arr[i] <= char(122))
			upperStr += char(arr[i] - 32);
			
		else
			upperStr += arr[i];
	
	return upperStr;
}

int main(){
	cout << "Output string in uppercase" << endl;
	string str;

	cout << "Enter a string : ";
	getline(cin, str);	
	
	int size = str.length();
	char *alpha = new char[size];
			
	for (int i=0; i < size; i++)
		alpha[i] = str[i];
		
	
	cout << "Output : " <<upperCase(alpha, size) << endl;	
	return 0;
}
