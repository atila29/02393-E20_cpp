#include <string>
#include <iostream>
#include <sstream>
#include <algorithm>

using namespace std;

long d(string u, string v);


long f(char e, char e1);

string replace(string s);

int main(){

    string line;

    getline(cin, line);


    const char delim = ' ';


    stringstream ss(line);

    string word1;
    getline(ss, word1, delim);


    string word2;
    getline(ss, word2, delim);

    cout << d(word1, word2);

    
    return 0;
}

long d(const string u, const string v) {

    if(u.length() == 0)
        return v.length();
    if(v.length() == 0)
        return u.length();


    long a = d(replace(u), v) + 1;
    long b = d(u, replace(v)) + 1;
    long c = d(replace(u), replace(v)) + f(u[0], v[0]);

    return min({a,b,c});
}

string replace(const string s) {
    string tmp = s;
    return tmp.replace(0,1,"");
}


long f(char e, char e1) {
    return e == e1 ? 0 : 1;
}

