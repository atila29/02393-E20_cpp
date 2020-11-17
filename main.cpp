#include <string>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>

using namespace std;



vector<int> rec_reverse(vector<int> v);

int main(){

    string line;

    getline(cin, line);


    const char delim = ' ';

    vector<int> v;

    stringstream ss(line);

    string word;

    while(getline(ss, word, delim)){
        v.push_back(stoi(word));
    }
    vector<int> reversed = rec_reverse(v);

    for(auto i : reversed) {
        cout<< i << " ";
    }
}

vector<int> rec_reverse(vector<int> v) {

    if(v.size() <= 1)
        return v;


    vector<int> reversed;
    reversed.push_back(v.back());
    v.pop_back();

    vector<int> next_vector = rec_reverse(v);


    reversed.insert(reversed.end(), next_vector.begin(), next_vector.end());

    return reversed;

}

