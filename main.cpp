#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <iterator>
#include <algorithm>
#include <cmath>
#include <map>
#include <set>

int main() {
    std::string line;
    std::map<std::string, std::multiset<int>> sets;

    std::getline(std::cin, line);

    std::string set_name;
    std::istringstream iss(line);
    for (std::string s; iss >> s;) {
        if(!set_name.empty()) {
            if ( sets.find(set_name) == sets.end() ) {
                // not found
                std::multiset<int> new_set;
                new_set.insert(stoi(s));
                sets[set_name] = new_set;
            } else {
                sets[set_name].insert(stoi(s));
            }
            set_name = "";
        }
        else {
            set_name = s;
        }
    }

    for (const auto& p : sets) {

        std::stringstream  s;
        copy(p.second.begin(),p.second.end(), std::ostream_iterator<int>(s," "));
        std::cout<<s.str();

    }
}
