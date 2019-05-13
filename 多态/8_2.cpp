#include<iostream>

using namespace std;

class Clock {
public:
    Clock(int huor = 0, int minute = 0, int second = 0);

    void showtime() const;

    Clock &operator++();

    Clock operator++(int);

private:
    int hour, minute, second;

};

Clock::Clock(int huor, int minute, int second) {
    if (0 <= hour && hour < 24 && 0 <= minute && minute < 60 && 0 <= second && second < 60) {
        this->hour = hour;
        this->minute = minute;
        this->second = second;


    } else
        cout << "Time error!" << endl;

}

void Clock::showtime() const {
    cout << hour << ":" << minute << ":"<<second << endl;

}

Clock & Clock::operator++() {//前置单目运算符
    second++;
    if (second > 60) {
        second -= 60;
        minute++;
        if (minute > 60) {
            minute -= 60;
            hour = (hour + 1) % 24;
        }
    }
    return * this;

}

Clock Clock::operator++(int) {
    Clock old = *this;
    ++(* this);
    return old;


}

int main(){
    Clock myclock(23,59,59);
    cout<<"First time out"<<endl;
    myclock.showtime();
    cout<<"Show myclock++";
    (myclock++).showtime();
    cout<<"show ++myclock";
    (++myclock).showtime();
    return 0;



}
