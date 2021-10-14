//
// Created by WealCome on 13/10/2021.
//

#include <iostream>
#include "palindrome.cpp"

class HttpPalindromesStore : public PalindromesStore {
    void store(std::vector<std::string> &palindromes) override {
        for (const auto &palindrome: palindromes) {
            std::cout << palindrome << std::endl;
        }
    }
};

int main() {
    HttpPalindromesStore palindromesStore;
    Palindrome::findPalindromes("Le radar d'Anna a flashé le Kayak du bb", palindromesStore);
}
