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
    std::string command;
    std::multiset<double> bag;

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
                double n = std::stod(s);
                if(command == "add") {
                    bag.insert(n);
                }
                else if(command == "del") {

                    auto itr = bag.find(n);
                    if(itr!=bag.end()){
                        bag.erase(itr);
                    }
                }
                else if(command == "qry") {

                    auto itr = bag.find(n);
                    if(itr!=bag.end()){
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
