/*
Name: Faizan Ahmad
Creation Date: 28/10/2018
Problem Description: 
    (1) a function named as thirdMin,
    (2) a function named as fifthMax
*/
# include <iostream>
using namespace std;

int thirdMin(int arr[], int size);

int fifthMax(int arr[], int size);

int main()
{
    int size = 10;
    int arr[size] = {1,2,3,4,5,6,7,8,9,10};
    cout << thirdMin(arr, size) << endl;
    cout << fifthMax(arr, size) << endl;
    return 0;
}

int thirdMin(int arr[], int size)
{
    int min = arr[0], count = size;
    
    for (int i = 0; i < size; i++)
        if (arr[i] > min && (size - count) < 2)
            min = arr[i], count--;

    return min;
}       

int fifthMax(int arr[], int size)
{
    int max = arr[0], count = 1;
    
    for (int i = 0; i < size; i++)
        if (arr[i] > max && count < 5)
            max = arr[i], count++;

    return max;
}
