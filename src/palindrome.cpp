#include <string>
#include <vector>
#include "palindromes-store/palindromesStore.h"

class Palindrome {

public:
    std::vector<std::string> static findPalindromes(const std::string &str, PalindromesStore &palindromesStore) {
        std::vector<std::string> foundPalindromes = {};
        _findPalindromes(str, foundPalindromes);
        palindromesStore.store(foundPalindromes);
        return {foundPalindromes};
    }

private:
    void static _findPalindromes(const std::string &str, std::vector<std::string> &foundPalindromes) {
        auto str2 = str; 
        std::replace(str2.begin(), str2.end(), '\'', ' ');
        const auto spaceIndex = str2.find(' ');
        const auto currentWord = str2.substr(0, spaceIndex);
        if (isPalindrome(currentWord))
            foundPalindromes.push_back(currentWord);
        if (noNextWord(spaceIndex))
            return;
        checkNextWord(str2, foundPalindromes, spaceIndex);
    }

    static bool noNextWord(const unsigned long spaceIndex) { return spaceIndex == std::string::npos; }

    static void checkNextWord(const std::string &str, std::vector<std::string> &foundPalindromes, const unsigned long spaceIndex) {
        std::string nextWord = str.substr(spaceIndex + 1);
        _findPalindromes(nextWord, foundPalindromes);
    }

    bool static isPalindrome(const std::string &word) {
        if (word.length() < 2)
            return false;
        for (int i = 0; i < word.length() / 2; i++)
            if (tolower(word.at(i)) != word.at(word.length() - i - 1))
                return false;
        return true;
    }

};