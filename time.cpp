#include <iostream>
#include "time.h"

Time::Time(int sec) : seconds(sec){};

void Time::set(int sec){
    seconds = sec;
}
int Time::get_seconds() const{
    return seconds;
}
Time Time::operator+(const Time &rhs) const{
    return Time(seconds + rhs.seconds);
}
Time Time::operator-(const Time &rhs) const{
    return Time(seconds - rhs.seconds);
}
Time Time::operator*(int scalar) const{
    return Time(seconds * scalar);
}
std::ostream &operator<<(std::ostream &out, const Time &t){
    int h = t.seconds / 3600;
    int m = (t.seconds % 3600) / 60;
    int s = t.seconds % 60;
    out << (h < 10 ? "0" : "") << h << "h:" << (m < 10 ? "0" : "") << m << "m:" << (s < 10 ? "0" : "") << s << "s";
    return out;
}
std::istream &operator>>(std::istream &in, Time &t){
    int h, m, s;
    char xd;
    in >> h >> xd >> m >> xd >> s;
    t.seconds = h*3600 + m*60 + s;
    return in;
}
Time::operator int() const{
    return seconds;
}

int main(){
    //checking using the exmaple use from lab 02
    Time t1(200);
    std::cout << t1 << std::endl; // displays 03m:20s
    Time t2;
    std::cin >> t2; // user enters 10h:12m:01s
    Time t3 = t2 - t1; // 10h:8m:41s
    std::cout << t3 << std::endl;
    int t3s = t3; // 36521
    std::cout << t3s << std::endl;
    return 0;
}
