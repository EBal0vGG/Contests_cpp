#include <iostream>
#include <string>
#include <chrono>

class TimerGuard {
public:
    TimerGuard(const std::string& mes, std::ostream& out) :
        mes_(mes),
        out_(out),
        time_1(std::chrono::high_resolution_clock::now())
    {}

    ~TimerGuard() {
        auto time_2 = std::chrono::high_resolution_clock::now();
        auto dur = std::chrono::duration_cast<std::chrono::milliseconds>(time_2 - time_1);
        out_ << mes_ << " " << dur.count() << std::endl;
    }

private:
    std::string mes_;
    std::ostream& out_;
    std::chrono::time_point<std::chrono::high_resolution_clock> time_1;
};

int main() {

    return 0;
}
