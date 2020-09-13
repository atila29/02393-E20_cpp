#include <iostream>
#include <cmath>
#include <string>


std::string PrimeFactors(int n)
{
    bool first = true;
    std::string result;

    while (n % 2 == 0)
    {
        result  += first? "2" : " * 2";
        n = n/2;
        first = false;
    }
    for (int i = 3; i <= sqrt(n); i = i+2)
    {
        while (n%i == 0)
        {

            result  += first? std::to_string(i)  : " * " + std::to_string(i);
            n = n / i;
            first = false;
        }
    }
    if (n > 2)
        result += first? std::to_string(n)  : " * " + std::to_string(n);
    return result;

}


int main() {

    int n;

    std::cin>>n;

    std::cout<<PrimeFactors(n)<<std::endl;

    return 0;
}

