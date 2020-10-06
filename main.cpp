#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <iterator>
#include <algorithm>
#include <cmath>
#include <map>
#include <set>
#include <list>

using namespace std;

int main() {
    string line;
    map<string, list<int>> sets;

    getline(cin, line);

    string set_name;
    istringstream iss(line);
    for (string s; iss >> s;) {
        if(!set_name.empty()) {
            if ( sets.find(set_name) == sets.end() ) {
                // not found
                list<int> new_set;
                new_set.insert(new_set.end(),stoi(s));
                sets[set_name] = new_set;
            } else {
                sets[set_name].insert(sets[set_name].end(),stoi(s));
            }
            set_name = "";
        }
        else {
            set_name = s;
        }
    }



    bool test = true;

    int sum = 0;

    while(test) {
        int current = 1;
        for(auto it = sets.begin(); it != sets.end(); ++it) {

            if(!it->second.empty()) {
                int v = *it->second.begin();

                current *= v;

                it->second.erase(it->second.begin());
            }
            else {
                current = 0;
            }

        }
        sum  += current;
        current = 0;

        test = false;
        for(auto it = sets.begin(); it != sets.end(); ++it) {

            if(!it->second.empty()) {
                test = true;
            }

        }


    }

    cout<<sum;


}
