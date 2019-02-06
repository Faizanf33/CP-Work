#include<string>
#include<sys/ioctl.h>
#include<unistd.h>
#include<iomanip>

using namespace std;
class Foodpanda{
  public:
    int datasize;
    string *hotel_name;
    string *hotel_contact;
    string *hotel_location;
    string *hotel_city;

    int detailsize;
    string **hotel_items;
    int **item_price;

    string **hotel_deals;
    int **deal_price;

    double amount_due;

    // prototypes used in Foodpanda app
    bool getdata();
    bool getdetail();
    string upper(string str);

    void welcome(winsize window);
    void displayboard(winsize window);

    void search(int window);
    int locate(string desired, int index[], string on);

    void display(int window, bool all);
    void displayinfo(int index, int window);

};
