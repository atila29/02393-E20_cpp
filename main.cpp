#include <string>
#include <iostream>
#include <sstream>

long double fib(int n);

using namespace std;

int main(){

    string line;

    getline(cin, line);


    const char delim = ' ';


    string tmp;
    stringstream ss(line);


    while (getline(ss, tmp, delim)) {
        cout << fib(stoi(tmp)) << " ";

    }



    
    return 0;
}

long double fib(int n) {
    if (n <= 1)
        return 1;
    return fib(n-1) + fib(n-2);
}
