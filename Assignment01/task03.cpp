/*
3. Write a program that prints the day number of the year, given the date in the form monthday-
year.
*/
# include<iostream>
# include<sstream>
using namespace std;

bool checkDay(int day, int month, bool leap=false){
	if ((month == 1, 3, 5, 7, 8, 10, 12) && day > 31)
		return false;

	else if ((month == 4, 6, 9, 11) && day > 30)
		return false;
	
	else if (leap == true && month == 2 && day > 29)
		return false;

	else if (leap == false && month == 2 && day > 28)
		return false;

	else
		return true;
}

bool checkMonth(int month){
	if (month > 0 && month <= 12)
		return true;
	else
		return false;
}

bool checkYear(int year, bool check_leap=false){
	if (check_leap == false)	
		if (year > 100 && year < 9999)
			return true;
		else
			return false;
	
	else if (check_leap == true)
		if ((year % 4 == 0) && (year % 100 != 0))
			return true;
		
		else if ((year % 100 == 0) && (year % 400 == 0))
			return true;

		else
			return false;
}

int calcDay(int day, int month, int year){
	bool is_leap = false;
	int day_num = 0;
	cout << "Validating date : " << month << "/" << day << "/"<< year << endl;

	if (checkYear(year) == true)
		if (checkYear(year, true) == true)
			is_leap = true;
		else
			is_leap = false;	
	
	if (is_leap == true)
		cout << year << " is a leap year!" << endl;

	if (is_leap == false)
		cout << year << " is not a leap year!" << endl;

	if (checkYear(year) == false){
		cout << "Invalid year : " << year << endl;
		return day_num;
	}

	else if (checkDay(day, month, is_leap) == false){
		cout << "Invalid day : " << day << endl;
		return day_num;
	}

	else if (checkMonth(month) == false){
		cout << "Invalid month : " << month << endl;
		return day_num;	
	}

	else
		if ((month == 2) && (is_leap == true))
			day_num += day;

		else if ((month == 2) && (is_leap == false))
			day_num += day;

		for (int i=1; i<=month; i++)
			//for Jan-Jul				
			if ((i == 2) && (is_leap == true) && (i != month))
				day_num += 29;
			else if ((i == 2) && (is_leap == false) && (i != month))
				day_num += 28;
			else if ((i < month) && (i%2 != 0) && (i < 8))
				day_num += 31;
			else if ((i < month) && (i%2 == 0) && (i < 8))
				day_num += 30;
			
			//for Aug-Dec
			else if ((i < month) && (i%2 == 0) && (i > 7))
				day_num += 31;
			else if ((i < month) && (i%2 != 0) && (i > 7))
				day_num += 30;
			//for Curr Month
			else if (i == month && i != 2)
				day_num += day;
			else
				continue;
		return day_num;

}

int dayNumber(string date){
	int size = date.length(), day = 0, month = 0, year = 0, char_count = 0;
	string temp;

	for(int i=0; i<size; i++)
		if (date[i] != '-')
			temp += date[i];
		
		else if(char_count == 0){
		    stringstream geek(temp);
			geek >> month, temp = "", char_count ++;
			}

		else if(char_count == 1){
		    stringstream geek(temp);   
			geek >> day, temp = "", char_count ++;
			}

    stringstream geek(temp);   
	geek >> year;
	
	return calcDay(day, month, year);
}

int main(){
	cout << "Check the day number of the year" << endl;
	string date;
	cout << "Enter date (MM-DD-YYYY): ";
	cin >> date;
	int day_number = dayNumber(date);
	if (day_number != 0)
		cout << "Day number : "<< day_number << endl;
}
