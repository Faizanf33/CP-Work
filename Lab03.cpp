# include<iostream>
# include<string>
using namespace std;

int power(int b, int e){
	int result = b;
	if (e == 0)
		return 1;
		
	for (int i=1; i<e; i++)
		result *= b;
		
	return result;
}

string Max(string s1, string s2, string s3){
	if (s1.length() > s2.length() && s1.length() > s3.length())
		return s1;
	
	else if (s2.length() > s1.length() && s2.length() > s3.length())
		return s2;
		
	else
		return s3;
}

void range(int start, int end){
	for (start; start<=end; start++)
		cout << start << endl;
}

int numlength(int x){
	int length = 1;
	while(x > 9)
		x = x / 10, length++;
	
	return length;
}

char maxChar(string str){
	int size = str.length();
	char max = str[0];
	for (int i=1; i<size; i++)
		if (str[i] > char(max))
			max = str[i];
			
	return max;
}

int main(void){
	cout << power(4, 1) << endl;
	cout << Max("My name is Faizan Ahmad", "Hello World!", "What is your name?") << endl;
	cout << Max("Hello", "Hell0", "Hell1") << endl;
//	range(0, 21);
	cout << numlength(2345) << endl; 
	cout << maxChar("Hamza");
	cout << maxChar("Do i know you?");
	return 0;
}
