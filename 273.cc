#include <iostream>
#include <sstream>
#include <string>

using std::string;

class Solution
{
public:
    string number_mod_10_to_word(int num)
    {
        switch (num) {
        case 0:
            return "";
        case 1:
            return "One";
        case 2:
            return "Two";
        case 3:
            return "Three";
        case 4:
            return "Four";
        case 5:
            return "Five";
        case 6:
            return "Six";
        case 7:
            return "Seven";
        case 8:
            return "Eight";
        case 9:
            return "Nine";
        }
        std::cerr << "number for number_mod_10_to_word() was over 10\n";
        std::exit(1);
    }

    string number_mod_100_to_word(int num)
    {
        if (num < 10) {
            return number_mod_10_to_word(num);
        }
        switch (num) {
        case 10:
            return "Ten";
        case 11:
            return "Eleven";
        case 12:
            return "Twelve";
        case 13:
            return "Thirteen";
        case 18:
            return "Eighteen";
        }
        if (num > 13 && num < 20) {
            return number_mod_10_to_word(num - 10) + "teen";
        } else if (num >= 20 && num < 30) {
            return "Twenty " + number_mod_10_to_word(num % 10);
        } else if (num >= 30 && num < 40) {
            return "Thirty " + number_mod_10_to_word(num % 10);
        } else if (num >= 40 && num < 50) {
            return "Fourty " + number_mod_10_to_word(num % 10);
        } else if (num >= 50 && num < 60) {
            return "Fivety " + number_mod_10_to_word(num % 10);
        } else if (num >= 60 && num < 70) {
            return "Sixty " + number_mod_10_to_word(num % 10);
        } else if (num >= 70 && num < 80) {
            return "Seventy " + number_mod_10_to_word(num % 10);
        } else if (num >= 80 && num < 90) {
            return "Eighty " + number_mod_10_to_word(num % 10);
        } else if (num >= 90 && num < 100) {
            return "Ninety " + number_mod_10_to_word(num % 10);
        } else {
            std::cerr << "number for number_mod_100_to_word() was over 100\n";
            std::exit(1);
        }
    }

    string number_mod_1000_to_word(int num)
    {
        if (num < 100) {
            return number_mod_100_to_word(num);
        } else {
            return number_mod_10_to_word(num / 100) + " Hundred " +
                   number_mod_100_to_word(num % 100);
        }
        std::cerr << "number for number_mod_1000_to_word() was over 1000\n";
        std::exit(1);
    }

    string number_mod_1_000_000_to_word(int num)
    {
        if (num < 1000) {
            return number_mod_1000_to_word(num);
        } else {
            return number_mod_1000_to_word(num / 1000) + " Thousand " +
                   number_mod_1000_to_word(num % 1000);
        }
        std::cerr
            << "number for number_mod_1_000_000_to_word() was over 1000\n";
        std::exit(1);
    }

    string number_mod_1_000_000_000_to_word(int num)
    {
        if (num < 1'000'000) {
            return number_mod_1_000_000_to_word(num);
        } else {
            return number_mod_1000_to_word(num / 1'000'000) + " Million " +
                   number_mod_1_000_000_to_word(num % 1'000'000);
        }
        std::cerr
            << "number for number_mod_1_000_000_000_to_word() was over 1000\n";
        std::exit(1);
    }

    string number_mod_1_000_000_000_000_to_word(int num)
    {
        if (num < 1'000'000'000) {
            return number_mod_1_000_000_000_to_word(num);
        } else {
            return number_mod_1000_to_word(num / 1'000'000'000) + " Billion " +
                   number_mod_1_000_000_000_to_word(num % 1'000'000'000);
        }
        std::cerr
            << "number for number_mod_1_000_000_000_to_word() was over 1000\n";
        std::exit(1);
    }

    string space_corrector(string s)
    {
        std::stringstream ss{s};
        string result{};
        string word{};
        while (!ss.eof()) {
            ss >> word;
            result += word + " ";
            word.clear();
        }
        result.pop_back();
        return result;
    }

    string numberToWords(int num)
    {
        if (num == 0) {
            return "Zero";
        } else if (num < 2147483647) {
            return space_corrector(number_mod_1_000_000_000_000_to_word(num));
        }
        std::cerr << "Not implemented";
        std::exit(1);
    }
};

int main()
{
    Solution s;
    for (int i = 0; i < 10; i++) {
        int min = 0;
        int max = 1'000'000'000;
        int range = max - min + 1;
        int num = rand() % range + min;
        std::cout << num << ": " << s.numberToWords(num) << "\n";
    }
}
