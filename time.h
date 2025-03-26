#ifndef TIME_H
#define TIME_H

class Time{
private:
    int seconds;

public:
    Time(int sec = 0);
    void set(int sec);
    int get_seconds() const;
    Time operator+(const Time &rhs) const;
    Time operator-(const Time &rhs) const;
    Time operator*(int scalar) const;
    void print() const;
    friend std::ostream &operator<<(std::ostream &out, const Time &t);
    friend std::istream &operator>>(std::istream &in, Time &t);
    operator int() const;
};


#endif // TIME_H
