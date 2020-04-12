// Copyright 2020 Adam Tremblay

#include <algorithm>
#include <string>
#include "ED.hpp"

ED::ED(std::string s1, std::string s2) {
    s1_ = s1;
    s2_ = s2;
    M_ = s1_.size() + 1;
    N_ = s2_.size() + 1;
    opt_ = new int*[M_];
    for (int i = 0; i < M_; ++i) {
        opt_[i] = new int[N_];
    }
}

ED::~ED() {
    delete [] opt_;
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
        opt_[i][N_ - 1] = sum;
        sum += 2;
    }
    sum = 0;

    // initialize bottom row
    for (int i = N_ - 1; i >= 0; --i) {
        opt_[M_ - 1][i] = sum;
        sum += 2;
    }

    // now calculate rest of matrix
    for (int m = M_ - 2; m >= 0; --m) {
        for (int n = N_ - 2; n >= 0; --n) {
            int f_bottom = opt_[m + 1][n] + 2;
            int f_right = opt_[m][n + 1] + 2;
            int mid = opt_[m + 1][n + 1] + penalty(s1_.at(m), s2_.at(n));
            opt_[m][n] = ED::min(f_bottom, f_right, mid);
        }
    }
    return opt_[0][0];
}

std::string ED::alignment() {
    int n = 0;
    int m = 0;
    std::string temp_str = "";

    // from opt_[0][0] to opt_[M_-1][N_-1]
    while (n != N_ - 1 || m != M_ - 1) {
        if (m != M_ - 1 && (opt_[m][n] == opt_[m + 1][n] + 2)) {
            temp_str.push_back(s1_.at(m));
            temp_str += " - 2\n";
            ++m;
        } else if (n != N_ - 1 && opt_[m][n] == (opt_[m][n + 1] + 2)) {
            temp_str += "- ";
            temp_str.push_back(s2_.at(n));
            temp_str += " 2\n";
            ++n;
        } else if (n != N_ - 1 && m != M_ - 1) {
            // char are different
            if (opt_[m][n] == opt_[m + 1][n + 1] + 1) {
                temp_str.push_back(s1_.at(m));
                temp_str += " ";
                temp_str.push_back(s2_.at(n));
                temp_str += " 1\n";
                ++n;
                ++m;
            } else if (opt_[m][n] == opt_[m + 1][n + 1]) {
                temp_str.push_back(s1_.at(m));
                temp_str += " ";
                temp_str.push_back(s2_.at(n));
                temp_str += " 0\n";
                ++n;
                ++m;
            }
        }
    }

    return temp_str;
}
