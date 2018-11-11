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
