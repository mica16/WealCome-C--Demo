//
// Created by WealCome on 14/10/2021.
//

#ifndef WEALCOME_C___DEMO_PALINDROMESSTORE_H
#define WEALCOME_C___DEMO_PALINDROMESSTORE_H

struct PalindromesStore {
    virtual ~PalindromesStore() = default;;
    virtual void store(std::vector<std::string> &palindromes) = 0;
};


#endif //WEALCOME_C___DEMO_PALINDROMESSTORE_H