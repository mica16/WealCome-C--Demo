//
// Created by WealCome on 14/10/2021.
//

#ifndef WEALCOME_C___DEMO_PALINDROMESSTORESTUB_H
#define WEALCOME_C___DEMO_PALINDROMESSTORESTUB_H

#include <vector>
#include "palindromesStore.h"

class PalindromesStoreStub : public PalindromesStore {
public:
    std::vector <std::string> storedPalindromes;
    void store(std::vector<std::string> &palindromes) override;
    ~PalindromesStoreStub() override;
};

#endif //WEALCOME_C___DEMO_PALINDROMESSTORESTUB_H