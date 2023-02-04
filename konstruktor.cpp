#include <iostream>
#include <string>
#include <sstream>
#include <vector>

typedef unsigned int uint;
const char maxSec = 60;
const char maxMin = 60;
const char maxHr = 24;

class Time
{
private:
    uint hour;
    uint minute;
    uint second;
public:
    Time(uint h = 0, uint m = 0, uint s = 0) :
        hour(h), minute(m), second(s) {} // проверка

    Time(std::string time = "00:00:00")//проверка
    {
        std::vector<uint> vec;
        std::istringstream iss(time);
        std::string str;
        int val;

        while (std::getline(iss, str, ':'))
        {
            std::stringstream ss;
            ss << str;
            ss >> val;
            vec.push_back(val);
        }
        hour = vec[0];
        minute = vec[1];
        second = vec[2];
    }

    void setHour(uint h) { hour = h; } // проверка
    void setMinute(uint m) { minute = m; } // проверка
    void setSecond(uint s) { second = s; } // проверка

    uint getHour()const { return hour; }
    uint getMinute()const { return minute; }
    uint getSecond()const { return second; }

    static Time secToTime(uint sec)
    {
        uint h = (uint)(sec / maxMin / maxHr);
        uint m = (uint)(sec / maxMin);
        uint s = sec - m * (maxMin);

        return Time(h, m, s);
    }

    static uint TimeToSec(Time& t)
    {
        return (t.getSecond() + t.getMinute() * maxMin + t.getHour() * maxHr * maxMin);
    }

    friend std::ostream& operator <<(std::ostream& out, Time& t);
    Time operator +(Time& t)// перегрузка операци 
    {
        uint h = hour - t.getHour() < 0 ? 0 : hour - t.getHour();
        uint m = minute - t.getMinute() < 0 ? 0 : minute - t.getMinute();
        uint s = second - t.getSecond() < 0 ? 0 : second - t.getSecond();
        return Time(h, m, s);
    }

    Time operator +(uint sec)// перегрузка операци
    {
        Time t(Time::secToTime(sec));
        return *this + t;
    }

    bool operator ==(Time& t)
    {
        return hour == t.getHour() && minute == t.getMinute() && second == t.getSecond();
    }

    bool operator !=(Time& t)
    {
        return hour != t.getHour() && minute != t.getMinute() && second != t.getSecond();
    }
};

int main()
{
    setlocale(LC_ALL,"ru"); 
    Time time(10, 15, 22);
    Time time1("11:16:23");
    Time time2(Time::secToTime(70));
    Time time3((time1 + time));
    Time time4((time + 120));

    std::cout << time3 << std::endl;
    std::cout << time4 << std::endl;


    system("PAUSE");
    return 0;
}

std::ostream& operator <<(std::ostream& out, Time& t)
{
    out << t.getHour() << ":" << t.getMinute() << ":" << t.getSecond();
    return out;
}