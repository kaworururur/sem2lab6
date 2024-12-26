#include <iostream>
#include <stdexcept>

class Time {
private:
    int hours;
    int minutes;
    int seconds;

public:
    class TimeOutOfRange : public std::out_of_range {
    public:
        TimeOutOfRange(const std::string& msg) : out_of_range(msg) {}
    };

    Time(int h, int m, int s) : hours(h), minutes(m), seconds(s) {
        if (hours < 0 || hours > 23 || minutes < 0 || minutes > 59 || seconds < 0 || seconds > 59) {
            throw TimeOutOfRange("Invalid time parameters");
        }
    }

    void printTime() {
        std::cout << hours << ":" << minutes << ":" << seconds << std::endl;
    }
};

int main() {
    try {
        Time t1(12, 30, 45);
        t1.printTime();

        Time t2(25, 80, 90); // Неправильные параметры времени
    }
    catch (const Time::TimeOutOfRange& e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    return 0;
}