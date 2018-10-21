/*
Q4) A .txt file named “data.txt” has a data in rows and cols 4 rows and 4 cols. Read the data from the file and create a two dimensional array named ARR[4][4] for storing this data. For each task create separate function. After reading the data to the array perform the following tasks.
1. Swap the rows after asking the user and store the array again in the same file.
2. Reverse all the rows and swap row1 with row4 and row2 with row3.
3.Calculate (ARR[4][4]*ARR[4][4]) according to the rules of matrix multiplication in MATH bit wise multiplication will not be accepted ,create a txt file named “result.txt” and store result there.
*/
# include<iostream>
# include<fstream>
# include<string>
using namespace std;

void swapRow(int arr[][4], string file){
	int to, from, row;
	string str;	
	cout << "1. Enter the number of rows you want to swap : ";
	cin >> to >> str >> from;
	if (to <= 0 | to > 4 | from <= 0 | from > 4){
		cout << "Invalid row number!" << endl;
		return;
	}
	ofstream fout(file.c_str(), ios::app);
	fout << endl;
	for (int i=0; i<4; i++){
		if (i == (to-1)) row = (from-1);
		else if (i == (from-1)) row = (to-1);
		else row = i;
				
		for (int j=0; j<4; j++){
			fout << arr[row][j] << " ";
		}
		fout << endl;
	}
	fout.close();
	cout << "Row " << to << " and " << from << " are swapped and stored to file : '" << file << "'." << endl;
	return;
}

void swapMatrix(int arr[][4]){
	cout << "\n2. Reversing all the rows and swapping row1 with row4 and row2 with row3." << endl;
	
	for (int i=3; i>=0; i--){
		for (int j=3; j>=0; j--){
			cout << arr[i][j] << " ";
		}	
		cout << endl;
	}
	return;
}

void matrixMltp(int arr[][4]){
	string file = "result4.txt";
	ofstream fout(file.c_str());
	
	cout << "\n3. Calculating (ARR[4][4] x ARR[4][4]) ..." << endl;
	
	int sum;
	for (int row=0; row<4; row++){
		for (int col=0; col<4; col++){
			sum = 0;
			for (int curr_row=0; curr_row<4; curr_row++){
				sum += arr[row][curr_row] * arr[curr_row][col];
			}
			fout << sum << " ";
		}
		fout << endl;
	}
	cout << "Result stored to file : '" << file << "'." << endl;
	return;
}

int main(void){
	int ARR[4][4] = {0};
	string file = "data4.txt";
	
	ifstream fin(file.c_str());
	if (fin){
		for (int i=0; i<4; i++){
			for (int j=0; j<4; j++)
				fin >> ARR[i][j];
		}
		fin.close();
	}
	else{
		cout << "File :'" << file << "' not found!" <<endl;
		return 0;
	}
	swapRow(ARR, file);
	swapMatrix(ARR);
	matrixMltp(ARR);
	return 0;	
}

