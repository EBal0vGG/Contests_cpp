#include <iostream>
#include <cstdint>
#include <numeric>

class Fraction {
public:
    Fraction(int32_t numerator, int32_t denominator) {
        if (denominator == 0) {
            throw std::invalid_argument("Denominator cannot be zero.");
        }
        reduce(numerator, denominator);
    }

    Fraction(int32_t value) : numerator(value), denominator(1) {}

    Fraction() : numerator(1), denominator(1) {}

    Fraction operator+(const Fraction& other) const {
        int64_t num = static_cast<int64_t>(numerator) * other.denominator +
                      static_cast<int64_t>(other.numerator) * denominator;
        int64_t den = static_cast<int64_t>(denominator) * other.denominator;
        return Fraction(static_cast<int32_t>(num), static_cast<int32_t>(den));
    }

    Fraction operator-(const Fraction& other) const {
        int64_t num = static_cast<int64_t>(numerator) * other.denominator -
                      static_cast<int64_t>(other.numerator) * denominator;
        int64_t den = static_cast<int64_t>(denominator) * other.denominator;
        return Fraction(static_cast<int32_t>(num), static_cast<int32_t>(den));
    }

    Fraction operator*(const Fraction& other) const {
        int64_t num = static_cast<int64_t>(numerator) * other.numerator;
        int64_t den = static_cast<int64_t>(denominator) * other.denominator;
        return Fraction(static_cast<int32_t>(num), static_cast<int32_t>(den));
    }

    Fraction operator/(const Fraction& other) const {
        if (other.numerator == 0) {
            throw std::invalid_argument("Division by zero.");
        }
        int64_t num = static_cast<int64_t>(numerator) * other.denominator;
        int64_t den = static_cast<int64_t>(denominator) * other.numerator;
        return Fraction(static_cast<int32_t>(num), static_cast<int32_t>(den));
    }

    // Операторы присваивания
    Fraction& operator+=(const Fraction& other) {
        *this = *this + other;
        return *this;
    }

    Fraction& operator-=(const Fraction& other) {
        *this = *this - other;
        return *this;
    }

    Fraction& operator*=(const Fraction& other) {
        *this = *this * other;
        return *this;
    }

    Fraction& operator/=(const Fraction& other) {
        *this = *this / other;
        return *this;
    }

    bool operator<(const Fraction& other) const {
        return static_cast<int64_t>(numerator) * other.denominator <
               static_cast<int64_t>(other.numerator) * denominator;
    }

    bool operator<=(const Fraction& other) const {
        return static_cast<int64_t>(numerator) * other.denominator <=
               static_cast<int64_t>(other.numerator) * denominator;
    }

    bool operator>(const Fraction& other) const {
        return static_cast<int64_t>(numerator) * other.denominator >
               static_cast<int64_t>(other.numerator) * denominator;
    }

    bool operator>=(const Fraction& other) const {
        return static_cast<int64_t>(numerator) * other.denominator >=
               static_cast<int64_t>(other.numerator) * denominator;
    }

    bool operator==(const Fraction& other) const {
        return numerator == other.numerator && denominator == other.denominator;
    }

    bool operator!=(const Fraction& other) const {
        return !(*this == other);
    }

    friend std::ostream& operator<<(std::ostream& os, const Fraction& frac) {
        os << frac.numerator << "∕" << frac.denominator;
        return os;
    }

private:
    int32_t numerator;
    int32_t denominator;

    void reduce(int32_t num, int32_t den) {
        if (den < 0) {
            num = -num;
            den = -den;
        }
        int32_t gcd = std::gcd(num, den);
        numerator = num / gcd;
        denominator = den / gcd;
    }
};

int main() {
    Fraction frac1(3, -9);
    std::cout << frac1 << "\n"; // -1/3

    Fraction frac2(42, 2);
    std::cout << frac2 << "\n"; // 21/1

    Fraction frac3(-1, -2);
    std::cout << frac3 << "\n"; // 1/2

    Fraction frac4 = frac1 + frac2;
    std::cout << frac4 << "\n"; // 62/3

    Fraction frac5 = frac2 - frac3;
    std::cout << frac5 << "\n"; // 41/2

    Fraction frac6 = frac1 * frac3;
    std::cout << frac6 << "\n"; // -1/6

    Fraction frac7 = frac2 / frac3;
    std::cout << frac7 << "\n"; // 42/1

    return 0;
}