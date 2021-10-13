#include "gmock/gmock.h"
#include "../src/Palindrome.cpp";

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}


class PalindromeCheckerSuite : public ::testing::Test {

public:
    void assertFoundPalindromes(const std::string &str, const std::vector<std::string> &expectedPalindromes) {
        EXPECT_THAT(Palindrome::findPalindromes(str),
                    testing::Eq(expectedPalindromes));
    }
};

TEST_F(PalindromeCheckerSuite, shouldNotFindPalindromesWhenNoPalindrom) {
    assertFoundPalindromes("", {});
    assertFoundPalindromes("a", {});
    assertFoundPalindromes("ab", {});
    assertFoundPalindromes("abca", {});
}

TEST_F(PalindromeCheckerSuite, shouldFindPalindromesWhenThereArePalindroms) {
    assertFoundPalindromes("aa", {"aa"});
    assertFoundPalindromes("bb", {"bb"});
    assertFoundPalindromes("aba", {"aba"});
    assertFoundPalindromes("le radar", {"radar"});
    assertFoundPalindromes("le radar au niveau du kayak", {"radar", "kayak"});
    assertFoundPalindromes("le radar de anna au niveau du kayak est assuré chez axa", {"radar", "anna", "kayak", "axa"});
    assertFoundPalindromes("Anna aime le kayak", {"Anna", "kayak"});
}

// "Anna fait du Kayak" => ["Anna", "Kayak"] std::vector<string>