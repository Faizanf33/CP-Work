/*
Q2) Create a struct A having 4 data members keep their data types of your
choice and 2 member functions one for setting the values and other for
print the values, the print function i.e. Accessor should be constant.
Similarly, a struct B having the same four data members of the same type as
struct A and the same functions as struct A. Write a driver program that
swap the data between the object of struct A and the object of struct B.
*/

# include<iostream>
# include<fstream>
# include<string>
using namespace std;

struct A{
	int member1;
	long member2;
	float member3;
	double member4;

	void setValue(int v1, long v2, float v3, double v4){
		member1 = v1, member2 = v2, member3 = v3, member4 = v4;
		return;
	}
	int const Accessor1(){
		return member1;
	}
	long const Accessor2(){
		return member2;
	}
	float const Accessor3(){
		return member3;
	}
	double const Accessor4(){
		return member4;
	}
};

struct B{
	int member1;
	long member2;
	float member3;
	double member4;

	void setValue(int v1, long v2, float v3, double v4){
		member1 = v1, member2 = v2, member3 = v3, member4 = v4;
		return;
	}
	int const Accessor1(){
		return member1;
	}
	long const Accessor2(){
		return member2;
	}
	float const Accessor3(){
		return member3;
	}
	double const Accessor4(){
		return member4;
	}
};

void driver(A &objA, B &objB){
	A objTemp;
	// temp = A
	objTemp.setValue(objA.member1, objA.member2, objA.member3, objA.member4);
	// A = B
	objA.setValue(objB.member1, objB.member2, objB.member3, objB.member4);
	// B = temp
	objB.setValue(objTemp.member1, objTemp.member2, objTemp.member3, objTemp.member4);

	return;
}

int main(void){
	ifstream fin("data2.txt");
	if (fin){
		A objA;
		B objB;

		fin >> objA.member1 >> objA.member2 >> objA.member3 >> objA.member4;

		fin >> objB.member1 >> objB.member2 >> objB.member3 >> objB.member4;
		fin.close();

		cout << "Before swapping " << endl;
		//cout << objA.Accessor1() << endl;
		cout << objA.Accessor2() << endl;
		//cout << objA.Accessor3() << endl;
		//cout << objA.Accessor4() << endl;

		//cout << objB.Accessor1() << endl;
		cout << objB.Accessor2() << endl;
		//cout << objB.Accessor3() << endl;
		//cout << objB.Accessor4() << endl;

		driver(objA, objB);

		cout << "After swapping " << endl;
		//cout << objA.Accessor1() << endl;
		cout << objA.Accessor2() << endl;
		//cout << objA.Accessor3() << endl;
		//cout << objA.Accessor4() << endl;

		//cout << objB.Accessor1() << endl;
		cout << objB.Accessor2() << endl;
		//cout << objB.Accessor3() << endl;
		//cout << objB.Accessor4() << endl;
	}
	else
		cout << "File 'data2.txt' not found!" << endl;

	return 0;
}
