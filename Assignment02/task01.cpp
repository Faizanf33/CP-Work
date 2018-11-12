/*
Q1) (HugeInteger Struct) Create a struct HugeInteger that uses two 40-element
arrays to store integers. Provide member functions input, output, add and
subtract. For comparing HugeInteger objects, provide functions isEqualTo,
isNotEqualTo, isGreaterThan, isLessThan, isGreaterThanOrEqualTo and
isLessThanOrEqualTo—each of these is a “predicate” function that simply
returns true if the relationship holds between the two HugeIntegers and
returns false if the relationship does not hold. Also, provide a predicate
function isZero. If you feel ambitious, provide member functions multiply,
divide and modulus.
*/

# include<iostream>
# include<fstream>
# include<string>
using namespace std;

struct HugeInteger{
	string infile, outfile;
	int *array1;
	int *array2;
	int *outarray;
	int size;

	// constructor
	HugeInteger(int s){
		array1 = new int[s];
		array2 = new int[s];
		outarray = new int[s];
		size = s;
	}

	bool input(){
		ifstream fin(infile.c_str());
		if (fin){
			for(int i=0; i<size; i++){
				// insert values in array1
				fin >> array1[i];
			}
			for(int i=0; i<size; i++){
				// insert values in array2
				fin >> array2[i];
			}
			fin.close();
			return true;
		}
		else
			return false;
	}

	void output(){
		ofstream fout(outfile.c_str(), ios::app);
		for (int i=0; i<size; i++){
			fout << outarray[i] << " ";
		}
		fout << endl;
		fout.close();
		return;
	}

	void add(){
		for (int i=0; i<size; i++){
			outarray[i] = array1[i] + array2[i];
		}
		output();
		return;
	}

	void subtract(){
		for (int i=0; i<size; i++){
			outarray[i] = array1[i] - array2[i];
		}
		output();
		return;
	}

	void multiply(){
		for (int i=0; i<size; i++){
			outarray[i] = array1[i] * array2[i];
		}
		output();
		return;
	}

	void divide(){
		for (int i=0; i<size; i++){
			outarray[i] = array1[i] / array2[i];
		}
		output();
		return;
	}

	void modulus(){
		for (int i=0; i<size; i++){
			outarray[i] = array1[i] % array2[i];
		}
		output();
		return;
	}
};

bool isEqualTo(HugeInteger obj){
	for(int i=0; i<obj.size; i++)
		if (obj.array1[i] != obj.array2[i]){
			return false;
		}
	return true;
}

bool isNotEqualTo(HugeInteger obj){
	for(int i=0; i<obj.size; i++)
		if (obj.array1[i] == obj.array2[i]){
			return false;
		}
	return true;
}

bool isGreaterThan(HugeInteger obj){
	for(int i=0; i<obj.size; i++)
		if (obj.array1[i] <= obj.array2[i]){
			return false;
		}
	return true;
}

bool isLessThan(HugeInteger obj){
	for(int i=0; i<obj.size; i++)
		if (obj.array1[i] >= obj.array2[i]){
			return false;
		}
	return true;
}

bool isGreaterThanOrEqualTo(HugeInteger obj){
	for(int i=0; i<obj.size; i++)
		if (obj.array1[i] < obj.array2[i]){
			return false;
		}
	return true;
}

bool isLessThanOrEqualTo(HugeInteger obj){
	for(int i=0; i<obj.size; i++)
		if (obj.array1[i] > obj.array2[i]){
			return false;
		}
	return true;
}

bool isZero(HugeInteger obj){
	for(int i=0; i<obj.size; i++)
		if (obj.array1[i] != 0 || obj.array2[i] != 0){
			return false;
		}
	return true;
}

int main(void){
	int num = 40;
	HugeInteger obj(num);
	// input filename (required)
	obj.infile = "data1.txt";
	// output filename (required)
	obj.outfile = "result1.txt";
	if (obj.input()){
		obj.add();
		obj.subtract();
		obj.multiply();
		obj.divide();
		obj.modulus();
		if (isEqualTo(obj))
			cout << "Elements of Array 1 are equal to elements of Array 2" << endl;
		else if (isNotEqualTo(obj))
			cout << "Elements of Array 1 are not equal to elements of Array 2" << endl;
		else if (isGreaterThan(obj))
			cout << "Elements of Array 1 are greater than elements of Array 2" << endl;
		else if (isLessThan(obj))
			cout << "Elements of Array 1 are less than elements of Array 2" << endl;
		else if (isGreaterThanOrEqualTo(obj))
			cout << "Elements of Array 1 are greater than or equal to elements of Array 2" << endl;
		else if (isLessThanOrEqualTo(obj))
			cout << "Elements of Array 1 are less than or equal to elements of Array 2" << endl;
		else if (isZero(obj))
			cout << "Elements of Array 1 and Array 2 are zero" << endl;
		else
			cout << "No comparison between elements of Array 1 and Array 2" << endl;
	}
	else
		cout << "File '" << obj.infile << "' not found!" << endl;
	return 0;
}
