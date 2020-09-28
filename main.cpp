#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <iterator>
#include <algorithm>
#include <cmath>
#include <map>
#include <set>



// add x
// del x
// qry x
// quit


int main() {
    std::string line;
    std::string command;
    std::multiset<int> bag;

    while (std::getline(std::cin, line)) {

        std::istringstream iss(line);
        for (std::string s; iss >> s;){
            if(s == "add" || s == "del" || s == "qry") {
                command = s;
            }
            else if(s == "quit") {
                return 0;
            }
            else {
                int n = std::stoi(s);
                if(command == "add") {
                    bag.insert(n);
                }
                else if(command == "del") {
                    bag.erase(std::remove(bag.begin(), bag.end(), n), bag.end());
                }
                else if(command == "qry") {
                    if (std::find(bag.begin(), bag.end(),n) != bag.end()) {
                        std::cout<<"T";
                    }
                    else {
                        std::cout<<"F";
                    }
                }
            }
        }
    }
}
