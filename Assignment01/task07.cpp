/*
7. Write a C++ function, lastLargestIndex, that takes as parameters an int array and its size
and returns the index of the last occurrence of the largest element in the array.
*/
# include<iostream>
using namespace std;

int lastLargestIndex(int arr[], int size){
	int max = arr[0], index = 0;
	
	for (int i=1; i<size; i++){
		if (arr[i] >= max)
			max = arr[i], index = i;		
	}
			
	return index;	
}

int main(){
	cout << "Testing last largest index in an array" << endl;
	cout << "Test 1\narray = {21,10,99,83,14,56,31,22,123,434,5,65} \nOutput : ";
	int arr1[12] = {21,10,99,83,14,56,31,22,123,434,5,65};
	cout << lastLargestIndex(arr1, 12) << endl;

	cout << "Test 2\narray = {0,210,12123,21,645,254,1658,1354645,25458,12} \nOutput : ";
	int arr2[10] = {0,210,12123,21,645,254,1658,1354645,25458,12};
	cout << lastLargestIndex(arr2, 10) << endl;

	cout << "Test 3\narray = {-12,-12,-16,-16,-16,-16,-25,-25,-25,-25} \nOutput : ";
	int arr3[10] = {-12,-12,-16,-16,-16,-16,-25,-25,-25,-25};
	cout << lastLargestIndex(arr3, 10) << endl;
}
