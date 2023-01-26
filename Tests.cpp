//
// Created by shatar on 03.12.22.
//

#include "CYK.cpp"

#include "gtest/gtest.h"

TEST(first_test, ABC) {
    std::unordered_set<char> N({'A', 'B', 'C', 'S'});
    std::unordered_set<char> Sigma({'a', 'b', 'c'});
    std::unordered_multimap<char, std::string> P;
    P.insert({'B', "BC"});
    P.insert({'S', "AB"});
    P.insert({'A', "a"});
    P.insert({'B', "b"});
    P.insert({'C', "c"});
    char S = 'S';
    Grammar gram(N, Sigma, P, S);

    std::string first_correct_word = "abc";
    EXPECT_TRUE(CYK(gram, first_correct_word));
    std::string second_correct_word = "ab";
    EXPECT_TRUE(CYK(gram, second_correct_word));
    std::string incorrect_word = "ac";
    EXPECT_FALSE(CYK(gram, incorrect_word));
}

TEST(second_test, epsilon) {
    std::unordered_set<char> N({'S'});
    std::unordered_set<char> Sigma({'a'});
    std::unordered_multimap<char, std::string> P;
    P.insert({'S', ""});
    char S = 'S';
    Grammar gram(N, Sigma, P, S);

    std::string empty_word = "";
    EXPECT_TRUE(CYK(gram, empty_word));
    std::string not_empty_word = "aaaaa";
    EXPECT_FALSE(CYK(gram, not_empty_word));
}
