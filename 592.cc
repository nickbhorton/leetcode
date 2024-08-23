#include <cassert>
#include <iostream>
#include <sstream>
#include <string>
using std::string;

struct Fraction {
private:
    static int gcd(int a, int b)
    {
        int result = std::min(a, b);
        while (result > 0) {
            if (a % result == 0 && b % result == 0) {
                break;
            }
            result--;
        }
        return result;
    }

public:
    Fraction(int numerator, int denominator)
    {
        if (numerator != 0 && denominator < 0) {
            this->numerator = -numerator;
            this->denominator = -denominator;
        } else if (denominator == 0) {
            this->numerator = 0;
            this->denominator = 0;
            return;
        } else if (numerator == 0) {
            this->numerator = 0;
            this->denominator = 1;
            return;
        } else {
            this->numerator = numerator;
            this->denominator = denominator;
        }
        int factor{
            gcd(this->numerator < 0 ? -this->numerator : this->numerator,
                this->denominator)
        };
        if (factor > 0) {
            this->numerator /= factor;
            this->denominator /= factor;
        } else {
            std::cerr << "the gcd of " << this->numerator << " and "
                      << this->denominator << " was " << factor << "\n";
            std::exit(1);
        }
    }
    int numerator;
    int denominator;
};

std::ostream& operator<<(std::ostream& os, Fraction const& f)
{
    os << f.numerator << "/" << f.denominator;
    return os;
}

enum class Operator { Plus, Minus };

Fraction apply_op(Fraction const& f1, Fraction const& f2, Operator const& op)
{
    switch (op) {
    case Operator::Plus:
        return Fraction(
            f1.numerator * f2.denominator + f2.numerator * f1.denominator,
            f1.denominator * f2.denominator
        );
    case Operator::Minus:
        return Fraction(
            f1.numerator * f2.denominator - f2.numerator * f1.denominator,
            f1.denominator * f2.denominator
        );
    }
    return Fraction(0, 0);
}

Fraction operator+(Fraction const& f1, Fraction const& f2)
{
    return apply_op(f1, f2, Operator::Plus);
}

Fraction operator-(Fraction const& f1, Fraction const& f2)
{
    return apply_op(f1, f2, Operator::Minus);
}

class Solution
{
    Fraction parse_fraction(std::stringstream& ss)
    {
        int numerator{};
        ss >> numerator;
        char slash{};
        ss >> slash;
        int denominator{};
        ss >> denominator;
        return Fraction(numerator, denominator);
    }

    Operator parse_op(std::stringstream& ss)
    {
        char c{};
        ss >> c;
        switch (c) {
        case '+':
            return Operator::Plus;
        case '-':
            return Operator::Minus;
        }
        std::cerr << "could not parse operator\n";
        std::exit(1);
    }

public:
    string fractionAddition(string expression)
    {
        std::stringstream ss{expression};
        Fraction f1 = parse_fraction(ss);
        while (!ss.eof()) {
            Operator o = parse_op(ss);
            Fraction f2 = parse_fraction(ss);
            switch (o) {
            case Operator::Plus:
                f1 = f1 + f2;
                break;
            case Operator::Minus:
                f1 = f1 - f2;
                break;
            }
        }
        std::stringstream output{};
        output << f1;
        return output.str();
    }
};
int main()
{
    Solution s{};
    Fraction f1(1, 2);
    Fraction f2(-1, 2);
    Fraction f3(1, -2);
    Fraction f4(-1, -2);
    Fraction f5(2, 4);
    std::cout << f1 << "\n";
    std::cout << f2 << "\n";
    std::cout << f3 << "\n";
    std::cout << f4 << "\n";
    std::cout << f5 << "\n";
    std::cout << s.fractionAddition("-1/2+1/2") << "\n";
    std::cout << s.fractionAddition("-1/2+1/2+1/3") << "\n";
    std::cout << s.fractionAddition("1/3-1/2") << "\n";
    std::cout << s.fractionAddition("5/3-1/3") << "\n";
}
