#include "gmock/gmock.h"
#include "../src/Palindrome.cpp"
#include "../src/palindromes-store/palindromesStoreStub.h"
using ::testing::Eq;

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

class PalindromeCheckerSuite : public ::testing::Test {

public:
    PalindromesStoreStub palindromesStoreStub;

    void assertFoundPalindromes(const std::string &str, const std::vector<std::string> &expectedPalindromes) {
        EXPECT_THAT(Palindrome::findPalindromes(str, palindromesStoreStub),
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
    assertFoundPalindromes("L'radar que j'aime", {"radar"});
}

TEST_F(PalindromeCheckerSuite, shouldSavePermanentlyAllFoundPalindromes) {
    Palindrome::findPalindromes("Anna aime le kayak", palindromesStoreStub);
    const std::vector<std::string> expectedStored = {"Anna", "kayak"};
    EXPECT_THAT(palindromesStoreStub.storedPalindromes, Eq(expectedStored));
}

// "Anna fait du Kayak" => ["Anna", "Kayak"] std::vector<string>