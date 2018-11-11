/* Question 2)
Create a class called time that has separate int member data for hours, minutes,
and seconds. One constructor should initialize this data to 0, and another
should initialize it to fixed values. Another member function should display it,
in 11:59:59 format. The final member function should add two objects of
type time passed as arguments. A main() program should create two initialized
time objects (should they be const?) and one that isn’t initialized.
Then it should add the two initialized values together,leaving the result in
the third time variable. Finally it should display the value of this third
variable. Make appropriate member functions const.
*/
# include<iostream>
using namespace std;

class Time{
    private:
        int hour;
        int minute;
        int second;

    public:
        Time(){
            hour = 0;
            minute = 0;
            second = 0;
        }

        Time(int h, int m, int s){
            second = s;
            minute = m;
            hour = h;
        }

        int getTime(char t) const{
            if (t == 'h')
                return hour;
            if (t == 'm')
                return minute;
            if (t == 's')
                return second;
        }

        void display(){
            if (hour < 10)
                cout << '0';

            cout << hour << ':';

            if (minute < 10)
                cout << '0';

            cout << minute << ':';

            if (second < 10)
                cout << '0';

            cout << second << endl;
        }

        void incSec(){
            second++;
            if (second > 59)
                second = 0, incMin();

            return;
        }

        void incMin(){
            minute++;
            if (minute > 59)
                minute = 0, incHour();

            return;
        }

        void incHour(){
            hour++;
            if (hour > 23)
                hour = 0;

            return;
        }

        void addTime(Time t1, Time t2){
            second = t1.getTime('s') + t2.getTime('s');
            if (second > 59){
                second = (second - 60);
                incMin();
                if (second > 59){
                    second = (second - 60);
                    incMin();
                }
            }
            minute += t1.getTime('m') + t2.getTime('m');
            if (minute > 59){
                minute = (minute - 60);
                incHour();
                if (minute > 59){
                    minute = (minute - 60);
                    incHour();
                }
            }
            hour += t1.getTime('h') + t2.getTime('h');
            if (hour > 23)
                hour = (hour - 24);
                if (hour > 23)
                    hour = (hour - 24);

            return;
        }
};

int main(void){
    Time t1(23, 59, 59);
    t1.display();

    Time t2(0,0,1);
    t2.display();

    Time t3;
    t3.addTime(t1, t2);
    t3.display();

    return 0;
}
