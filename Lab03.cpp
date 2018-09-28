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
	char max = str[0];
	for (int i=1; i<str.length(); i++)
		if (str[i] > max)
			max = str[i];
			
	return max;
}

void print(int a[], int size){
	for (int i=0; i<size; i++)
		cout << "Value " << i+1 << " is : " << a[i] << endl;
	
}

void reversePrint(int a[], int size){
	for (size; size>0; size--)
		cout << "Value " << size << " is : " << a[size-1] << endl;
	
}

void input(int a[], int size){
	for (int i=0; i<size; i++){
		cout << "Enter value " << i+1 << " : ";
		cin >> a[i];

	}				
	print(a, size);
	cout << endl;
	reversePrint(a, size);
}


int main(void){
//	cout << power(4, 1) << endl;
//	cout << Max("My name is Faizan Ahmad", "Hello World!", "What is your name?") << endl;
//	cout << Max("Hello", "Hell0", "Hell1") << endl;
//	range(0, 21);
//	cout << numlength(2345) << endl; 
//	cout << maxChar("Hamza");
//	cout << maxChar("Do i know you?");
	int arr[5];
	input(arr, 5);	

	return 0;
}
