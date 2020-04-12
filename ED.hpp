// Copyright 2020 Adam Tremblay

#ifndef ED_HPP_
#define ED_HPP_

#include <algorithm>
#include <string>

class ED {
 public:
    // accepts the two strings to be compared
    ED(std::string s1, std::string s2);

    // destructor
    ~ED();

    // returns the penalty for aligning chars a and b (this will be a 0 or a 1)
    static int penalty(char a, char b);

    // returns the min of the three args
    static int min(int a, int b, int c);

    // populates the matrix based on having the two strings,
    // and returns the optimal distance (from the [0][0] cell
    // of the matrix when done).
    int optDistance();

    // traces the matrix and returns a string that can be
    // printed to display the actual alignment. In general,
    // this will be a multi-line string
    std::string alignment();

 private:
    std::string s1_;
    std::string s2_;
    int M_;
    int N_;
    int** opt_;
};

#endif  // ED_HPP_
