// Copyright 2020 Adam Tremblay

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include "ED.hpp"

ED::ED(std::string s1, std::string s2) {
    s1_ = s1;
    s2_ = s2;
    M_ = s1_.size() + 1;
    N_ = s2_.size() + 1;
    opt_ = std::vector<std::vector<int> > (M_, std::vector<int> (N_, 0));
}

int ED::penalty(char a, char b) {
    return a == b ? 0 : 1;
}

int ED::min(int a, int b, int c) {
    return std::min(a, std::min(b, c));
}

int ED::optDistance() {
    int sum = 0;

    // initialize last column
    for (int i = M_ - 1; i >= 0; --i) {
        opt_.at(i).at(N_ - 1) = sum;
        sum += 2;
    }
    sum = 0;

    // initialize bottom row
    for (int i = N_ - 1; i >= 0; --i) {
        opt_.at(M_ - 1).at(i) = sum;
        sum += 2;
    }

    // now calculate rest of matrix
    for (int m = M_ - 2; m >= 0; --m) {
        for (int n = N_ - 2; n >= 0; --n) {
            int f_bottom = opt_.at(m + 1).at(n) + 2;
            int f_right = opt_.at(m).at(n + 1) + 2;
            int mid = opt_.at(m + 1).at(n + 1) + penalty(s1_.at(m), s2_.at(n));
            opt_.at(m).at(n) = ED::min(f_bottom, f_right, mid);
        }
    }
    return opt_.at(0).at(0);
}

int main() {
    ED ed("KITTEN", "SITTING");
    std::cout << "ED = " << ed.optDistance() << std::endl;
    return 0;
}
