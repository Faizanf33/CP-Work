# include<iostream>
# include<fstream>
# include<string>
using namespace std;

string upperCase(string line){
	string upperStr;
	int size = line.length();
	
	for (int i=0; i<size; i++)
		if (line[i] >= char(97) && line[i] <= char(122))
			upperStr += char(line[i] - 32);
			
		else
			upperStr += line[i];
	
	return upperStr;
}

int main(){	
	string line, filename;
	cout << "Enter filename : ";
	cin >> filename;
	ifstream fin((filename+".txt").c_str());
	
	filename = upperCase(filename)+"2.txt";

	ofstream fout(filename.c_str());

	if (fin.is_open())
		while(!fin.eof()){
			getline(fin, line);
			fout << upperCase(line) << endl;
		}
	else
		cout << "file not found!" << endl;
	
	fin.close(), fout.close();
		
	return 0;		
}
