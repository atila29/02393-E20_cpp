#include <iostream>

int main() {

    int n;
    int sum = 0;

    std::cin>>n;

    for(int i = 0; i<=n; i += 2)
    {
        sum += i;
    }

    std::cout<<sum<<std::endl;

    return 0;
}