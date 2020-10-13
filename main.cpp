#include <iostream>
#include <string>
#include <regex>

using namespace std;


int gcd(int a, int b)
{
    if (a == 0)
        return b;
    return gcd(b % a, a);
}

class fraction {
private:
    int  numerator;
    int denominator;
public:
    // Class constructor
    fraction(int n, int d);
    // Methods to update the fraction
    void add(fraction f);
    void mult(fraction f);
    void div(fraction f);
    // Display method
    void display(void);

    void simplify();
};

fraction::fraction(int n, int d) {
    numerator = n;
    denominator = d;
}

void fraction::add(fraction f) {
    int d = gcd(denominator, f.denominator);
    d = (denominator * f.denominator) / d;

    int n = numerator * (d / denominator) + f.numerator * (d / f.denominator);

    numerator = n;
    denominator = d;
    simplify();
}

void fraction::mult(fraction f) {
    numerator = numerator * f.numerator;
    denominator = denominator * f.denominator;
    simplify();
}

void fraction::div(fraction f) {
    this->mult(fraction(f.denominator,f.numerator));
}

void fraction::display(void) {
    cout<<this->numerator<<" / "<<this->denominator<<endl;
}

void fraction::simplify()
{
    int common_factor = gcd(numerator, denominator);

    numerator = numerator / common_factor;
    denominator = denominator / common_factor;
}


int main() {
    string line;

    regex rgx(R"(^(\d+)\s\/\s(\d+)\s(div|[*+])\s(\d+)\s\/\s(\d+)$)");

    smatch matches;

    for (std::string line; std::getline(std::cin, line);) {
        if(regex_search(line, matches, rgx)) {

            fraction fr0 = fraction(stoi(matches[1].str()), stoi(matches[2].str()));
            fraction fr1 = fraction(stoi(matches[4].str()), stoi(matches[5].str()));

            if(matches[3].str() == "*") {
                fr0.mult(fr1);
            }
            else if(matches[3].str() == "+") {
                fr0.add(fr1);
            }
            else if(matches[3].str() == "div") {
                fr0.div(fr1);
            }

            fr0.display();

        }
    }

}
