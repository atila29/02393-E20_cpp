#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <iterator>
#include <algorithm>
#include <cmath>
#include <map>


int main() {
    std::vector<std::vector<int>> numbers;
    std::string line;
    std::map<int, std::vector<int>> histogram;
    std::vector<int> result;
    int line_index = 1;

    int l;
    int n;
    std::cin>>l;
    std::cin>>n;

    while (std::getline(std::cin, line)) {

        std::istringstream iss(line);
        for (std::string s; iss >> s;){
            result.push_back(stoi(s));
            line_index++;
        }
        if(line_index > n)
            break;

    }

    auto m = std::max_element(result.begin() , result.end()).operator[](0);

    int k = ceil((double) m / (double) l);

    for (int i = 0; i <= m; i += k) {

        if(histogram.find(i) == histogram.end()) {
            histogram[i] = std::vector<int>();
        }
        for (std::vector<int>::const_iterator v = result.begin(); v != result.end(); ++v) {

            if( *v >= i && * v < i + k) {
                histogram.at(i).push_back(*v);
            }
        }
        std::cout << std::to_string(i) + ": " + std::to_string(histogram.at(i).size()) << std::endl;
    }
}
