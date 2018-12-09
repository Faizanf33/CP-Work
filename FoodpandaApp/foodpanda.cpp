#include<iostream>
#include<fstream>
#include<sys/ioctl.h>
#include<unistd.h>
#include<string>
#include<iomanip>

using namespace std;

struct Foodpanda{
    int filesize;
    string *hotel_name;
    string *hotel_contact;
    string *hotel_location;
    string *hotel_city;

    // prototypes used in Foodpanda app
    bool getdata();
    string upper(string str);

    void welcome(winsize window);
    void displayboard(winsize window);
    void search(int window);
    int locate(string desired, int index[], string on);
    void display(int window, bool all);
    void displaydetail(int index, int window);
};

/////////////////// Start of Main ///////////////////////////
int main(){
  Foodpanda app;
  struct winsize window;

  app.getdata();

  cout << "\x1B[32m";   // change text color to green

  bool exit = false;
  while (not exit)
  {
    // display welcome window
    app.welcome(window);

    int input = cin.get();

    if (input == 27)
      exit = true;

    else if (input == 10)
      app.displayboard(window);

    else
      cout << '\a';
  }

  cout << "\x1B[0m";    // set default text color

  // clears the console
  system("clear");
  return 0;
}
/////////////////// End of Main ///////////////////////////

/* This method receives data from file
   and sets data to pointed array(s)
   note: file 'data.csv' is required */
bool Foodpanda :: getdata()
{
  string file = "data.csv", line;
  // initializing filesize
  filesize = 0;

  // open file and count number of lines
  ifstream fin(file.c_str());
  if (fin.is_open())
  {
    while(not fin.eof())
    {
      getline(fin, line);
      filesize++;   // this counts number of lines
    }
    // close the file
    fin.close();
  }

  else
  {
    cout << "File '" << file << "' not found!\n";
    return false;
  }

  /*
  Re-open the file to get data and
  create a dynamic array(s) with respect
  to name, contact, address, city.
  */
  fin.open(file.c_str());

  // dynamic memory allocation
  hotel_name = new string[filesize];
  hotel_contact = new string[filesize];
  hotel_location = new string[filesize];
  hotel_city = new string[filesize];

  for(int i = 0; i < filesize; i++)
  {
    getline(fin, hotel_name[i], ',');
    getline(fin, hotel_contact[i], ',');
    getline(fin, hotel_location[i], ',');
    getline(fin, hotel_city[i], '\n');
  }

  fin.close();
  return true;
}

// this method CAPITALIZES a given string
string Foodpanda :: upper(string str)
{
	string upperStr;

	for (int i = 0; i < str.length(); i++)
  {
    // if alphabet is lower case than convert to upper
    if (str[i] >= char(97) && str[i] <= char(122))
      upperStr += char(str[i] - 32);

    // else no change
    else
      upperStr += str[i];
  }

	return upperStr;
}

/* This method outputs welcome screen
   as designed in 'display.txt' file */
void Foodpanda :: welcome(winsize window)
{
  // checks the current console window size
  ioctl(STDOUT_FILENO, TIOCGWINSZ, &window);

  system("clear");
  string design;
  ifstream file("display.txt");

  while(not file.eof())
  {
    getline(file, design);
    cout << design << endl;
    window.ws_row--;
  }
  file.close();

  for (int col = 0; col < ((window.ws_row - 1) * window.ws_col); col++)
    cout << ' ';

  return;
}


void fillspace(int width)
{
  for (int i = 0; i < width; i++)
    cout << ' ';

  return;
}

void Foodpanda :: displayboard(winsize window)
{
  system("clear");
  ioctl(STDOUT_FILENO, TIOCGWINSZ, &window);
  fillspace((window.ws_col * 4) + window.ws_col / 6);

  cout << "[Find or see your nearest hotels/restaurants";
  cout << " address/contact]\n\n";
  fillspace(window.ws_col / 6);
  cout << "[1] Find local restaurants/hotels\n";
  fillspace(window.ws_col / 6);
  cout << "[2] Show famous hotels/restaurants\n";
  fillspace(window.ws_col / 6);
  cout << "[3] Show all available\n\n";
  fillspace(window.ws_col / 6);
  cout << "[Esc to exit]\n";
  fillspace(window.ws_col / 6);
  cout << "Enter choice[1 - 3]: ";
  int choice = cin.get();
  if (choice == 49)
    search(window.ws_col);

  else if (choice == 50)
    display(window.ws_col, false);

  else if (choice == 51)
    display(window.ws_col, true);

  cin.get();
  return;
}
void Foodpanda :: display(int window, bool all)
{
  system("clear");
  fillspace((window * 4) + window / 6);
  cout << "[:] Name(s) of hotels/restaurants\n\n";

  if (all)
  {
    fillspace(window / 12);
    for (int i = 0; i < filesize - 1; i++)
    {
      cout << '[' << i + 1 << ']' << ' ';
      cout << setw(20) << left << upper(hotel_name[i]);

      if ((i + 1) % 3 == 0 and i > 0)
      {
        cout << endl;
        fillspace(window / 12);
      }
    }
  }

  else if (not all)
  {
    fillspace(window / 6);
    for (int i = 0; i < 5; i++)
    {
      cout << '[' << i + 1 << ']' << ' ';
      cout << upper(hotel_name[i]) << endl;
      fillspace(window / 6);
    }
  }

  cout << endl;
  int index = -1;
  fillspace(window / 6);
  cout << "[:] For detail: ";
  cin >> index;

  fillspace(window / 6);

  if (all and index > 0 and index <= filesize)
    displaydetail(index - 1, window);

  else if (index > 0 and index <= 5)
    displaydetail(index - 1, window);

  else
    cout << "[Invalid entry!]" << endl;

  cin.get();
  return;
}


void Foodpanda :: search(int window)
{
  system("clear");
  fillspace((window * 4) + window / 6);

  cout << "[Go ahead and tell us what you know]\n\n";
  fillspace(window / 6);
  cout << "[1] Search by name\n";
  fillspace(window / 6);
  cout << "[2] Search by contact\n";
  fillspace(window / 6);
  cout << "[3] Search by location\n\n";
  fillspace(window / 6);
  cout << "[Esc to exit]\n";
  fillspace(window / 6);
  cout << "Enter choice[1 - 3]: ";
  string input;
  int index[filesize];// = {0};

  cin >> input;
  if (input == "1")
    fillspace(window / 6);
    cout << "Enter name: ";
    cin >> input;
    locate(input, index, "hotel_name");

  return;
}

int Foodpanda :: locate(string desired, int index[], string on)
{
  for (int i = 0; i < filesize; i++)
  {
    if (on == "hotel_name" and upper(hotel_name[i]).find(upper(desired)))
      cout << hotel_name[i] << endl;
  }

  cin.get();
  return *index;
}

void Foodpanda :: displaydetail(int index, int window)
{
  system("clear");
  fillspace((window * 4) + window / 6);

  cout << "[Detail Info]\n\n";
  fillspace(window / 6);
  cout << "Name    :   " << upper(hotel_name[index]) << endl;
  fillspace(window / 6);
  cout << "Contact :  " << upper(hotel_contact[index]) << endl;
  fillspace(window / 6);
  cout << "Address :  " << upper(hotel_location[index]) << endl;
  fillspace(window / 6);
  cout << "City    :   " << upper(hotel_city[index]) << endl;
  cout << endl;
  fillspace(window / 6);
  cout << "[Press any key to exit]" << endl;

  cin.get();
  return;
}
