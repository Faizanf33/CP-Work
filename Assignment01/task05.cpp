/*
5. Write a program that outputs inflation rates for two successive years and whether the inflation
is increasing or decreasing.
*/

# include<iostream>
# include<cstdlib>
using namespace std;


float calc_inflation(double price, double prev_price){
	return ((prev_price - price) / prev_price);
}

float user_input(){
	double curr_price, last_price, b_last_price;
	
	cout << "Enter current price of an item : ";
	cin >> curr_price;
	
	cout << "It's price one year ago : ";
	cin >> last_price;
	
	cout << "It's price two years ago : ";
	cin >> b_last_price;
	
	return ((calc_inflation(curr_price, last_price) + calc_inflation(last_price, b_last_price)) / 2);	

}

float output_rate(){
	return user_input() * 100;
	
}

int main(){
	cout << "Check inflation rates of an item for two successive years" << endl;
	long rate = output_rate();

	if (rate < 0)
		cout << "Rate increasing at : " << abs(rate) << "%" << endl;
		
	else
		cout << "Rate decreasing at : " << abs(rate) << "%" << endl;
}
