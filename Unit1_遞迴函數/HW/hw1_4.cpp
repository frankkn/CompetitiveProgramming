#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

int main () {
    std::string s;
    while (std::cin >> s) {
        std::vector<std::string> permutations;
        std::sort(s.begin(), s.end());
        do { 
            permutations.push_back(s);
        } while (std::next_permutation(s.begin(), s.end()));
        std::cout << permutations.size();
        for (auto const& p : permutations) { std::cout << "\n" << p; }
    }
    return 0;
}