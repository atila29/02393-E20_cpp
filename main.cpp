#include <iostream>
#include <cmath>


double pi(int n)
{
    double partial = 0;
    for (int i = 0; i < n; i++)
        partial += pow(-1,i)/(2.0 * i + 1);
    return 4 * partial;
}


int main() {

    int n;

    std::cin>>n;

    std::cout<<pi(n)<<std::endl;

    return 0;
}

