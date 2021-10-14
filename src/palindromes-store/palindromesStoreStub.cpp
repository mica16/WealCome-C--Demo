//
// Created by WealCome on 14/10/2021.
//

#include <iostream>
#include <vector>
#include "palindromesStore.h"
#include "palindromesStoreStub.h"

PalindromesStoreStub::~PalindromesStoreStub() {
}

void PalindromesStoreStub::store(std::vector<std::string> &palindromes) {
    storedPalindromes = palindromes;
}

