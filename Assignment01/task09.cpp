/*
9. Write a program that uses a two-dimensional array to store the highest and lowest tem-
peratures for each month of the year. The program should output the average high, average
low, and the highest and lowest temperatures for the year.
*/

# include<iostream>
# include<string>
using namespace std;

int indexLowTemp(float arr[]){
	int indexLow = 0;
	float lowestTemp = arr[0];

	for (int i=0; i<12; i++)
		if (arr[i] < lowestTemp)
			lowestTemp = arr[i], indexLow = i;

	return indexLow;
}

int indexHighTemp(float arr[]){
	int indexHigh = 0;
	float highestTemp = arr[0];

	for (int i=0; i<12; i++)
		if (arr[i] > highestTemp)
			highestTemp = arr[i], indexHigh = i;

	return indexHigh;
}

float averageLow(float arr[]){
	int count = 0;
	float average = 0;

	for (int i=0; i<12; i++)
		average += arr[i], ++count;

	return (average / count);
}

float averageHigh(float arr[]){
	int count = 0;
	float average = 0;

	for (int i=0; i<12; i++)
		average += arr[i], ++count ;

	return (average / count);
}

float getData(){
	float temp[12][2] =
		{{10.15, 22.5},
		 {18.6, 24.25},
		 {20.5, 30.45},
		 {23.2, 40.5},
		 {27.9, 42.2},
		 {32.3, 46.5},
		 {33.5, 48.1},
		 {30.6, 46.62},
		 {28.8, 41.7},
		 {23.7, 38.45},
		 {17.5, 33.75},
		 {12.4, 26.9}};

	float tempLow[12] = {0}, tempHigh[12] = {0};

	for (int i=0; i<12; i++)
		for (int j=0; j<2; j++)
			if (j == 0)
				tempLow[i] = temp[i][j];
			else
				tempHigh[i] = temp[i][j];

	cout << "Low Temp. Index : " << indexLowTemp(tempLow) << endl;
	cout << "High Temp. Index : " << indexHighTemp(tempHigh) << endl;
	cout << "Average Low Temp. : " << averageLow(tempLow) << endl;
	cout << "Average High Temp. : " << averageHigh(tempHigh) << endl;

	return 0;
}

int main(){
	cout << "2D array of highest and lowest temperatures for each month of the year" << endl;
	cout << "Test 1 : \n2D array : \n{{10.15, 22.5}\n{18.6, 24.25}\n{20.5, 30.45}\n{23.2, 40.5}\n{27.9, 42.2}\n{32.3, 46.5}\n{33.5, 48.1}\n{30.6, 46.62}\n{28.8, 41.7}\n{23.7, 38.45}\n{17.5, 33.75}\n{12.4, 26.9}} \nOutput : \n";
    getData();
}
