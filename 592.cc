#include <cassert>
#include <iostream>
#include <sstream>
#include <string>
using std::string;

struct Fraction {
    int numerator;
    int denominator;
};

std::ostream& operator<<(std::ostream& os, Fraction const& f)
{
    os << f.numerator << "/" << f.denominator;
    return os;
}

static int gcd(int a, int b)
{
    // Find Minimum of a and b
    int result = std::min(a, b);
    while (result > 0) {
        if (a % result == 0 && b % result == 0) {
            break;
        }
        result--;
    }

    // Return gcd of a and b
    return result;
}

enum class Operator { Plus, Minus };

Fraction apply_op(Fraction const& f1, Fraction const& f2, Operator const& op)
{
    Fraction result{};
    Fraction f1c{f1};
    Fraction f2c{f2};
    if (f1.denominator != f2.denominator) {
        f1c.numerator *= f2.denominator;
        f1c.denominator *= f2.denominator;
        f2c.numerator *= f1.denominator;
        f2c.denominator *= f1.denominator;
        assert(f1c.denominator == f2c.denominator);
    }
    switch (op) {
    case Operator::Plus:
        result.numerator = f1c.numerator + f2c.numerator;
        break;
    case Operator::Minus:
        result.numerator = f1c.numerator - f2c.numerator;
        break;
    }
    result.denominator = f1c.denominator;
    int factor{gcd(result.numerator, result.denominator)};
    if (factor != 0) {
        result.numerator /= factor;
        result.denominator /= factor;
    }
    if (result.numerator == 0) {
        result.denominator = 1;
    }
    if (result.denominator < 0) {
        result.numerator = -result.numerator;
        result.denominator = -result.denominator;
    }
    return result;
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
        Fraction result{};
        ss >> result.numerator;
        char slash{};
        ss >> slash;
        ss >> result.denominator;
        // std::cout << result << "\n";
        return result;
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
    // s.fractionAddition("-1/2+1/2");
    std::cout << s.fractionAddition("-1/4+1/2") << "\n";
    std::cout << s.fractionAddition("-1/2+1/2+1/3") << "\n";
    std::cout << s.fractionAddition("1/3-1/2") << "\n";
    std::cout << s.fractionAddition("5/3-1/3") << "\n";
}
