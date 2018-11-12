/*
Q5) Write a program whose main function is merely a collection of variable
declarations and function calls. This program reads a text and outputs the
letters, together with their counts.
*/

# include<iostream>
# include<iomanip>
# include<fstream>
# include<string>
using namespace std;

struct Letter{
	int lower_count,
		upper_count;

	char upper,
		lower;
};

void printResult(fstream &fout, Letter letters[], int total_letters){
	// converting int value to double
	double total = total_letters, percent = 0;
	fout << fixed << setprecision(0);

	for (int i=0; i<26; i++){
		percent = (letters[i].lower_count / total) * 100;

		fout << letters[i].lower << " "<< letters[i].lower_count <<
		" " << percent << "%\n";

		percent = (letters[i].upper_count / total) * 100;
		fout << letters[i].upper << " "<< letters[i].upper_count <<
		" " << percent << "%\n";
	}
	fout.close();
	return;
}

int count(fstream &fin, Letter letters[]){
	int total_letters = 0;
	while (!fin.eof()){
		string word;
		fin >> word;
		for (int i=0; i<word.length(); i++){
			for (int j=0; j<26; j++){
				// for letters A-Z
				if (word[i] == letters[j].upper){
					letters[j].upper_count++;
					total_letters++;
					break;
				}
				// for letters a-z
				else if (word[i] == letters[j].lower){
					letters[j].lower_count++;
					total_letters++;
					break;
				}
				else
					continue;
			}
		}
	}
	fin.close();
	return total_letters;
}

bool openFile(fstream &fstr, string &file, string fileIs){
	cout << "Enter "<< fileIs << " file name : ";
	cin >> file;

	if (fileIs == "input")
		fstr.open(file.c_str());
	else
		fstr.open(file.c_str(), ios::app);

	if (fstr.is_open())
		return true;
	else
		return false;
}

void init(Letter letters[]){
	for (int i=0; i<26; i++){
		letters[i].upper = char(i + 65);
		letters[i].lower = char(i + 97);
		letters[i].upper_count = 0;
		letters[i].lower_count = 0;
	}
	return;
}

int main(void){
	fstream fin;
	string file;

	if (openFile(fin, file, "input")){
		Letter letters[26];
		// initializing letters array with all letters & and their count to zero
		init(letters);
		int total_letters = count(fin, letters);

		fstream fout;
		openFile(fout, file, "output");
		printResult(fout, letters, total_letters);
		cout << "Result saved to file : '" << file << "'" << endl;
	}
	else
		cout << "File '"<< file <<"'not found!" << endl;

	return 0;
}
