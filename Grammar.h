//
// Created by shatar on 03.12.22.
//

#ifndef CYK_GRAMMAR_H
#define CYK_GRAMMAR_H

#include <string>
#include <unordered_set>
#include <unordered_map>

struct Grammar {
    std::unordered_set<char> N;
    std::unordered_set<char> Sigma;
    std::unordered_multimap<char, std::string> P;
    char S;
    Grammar(std::unordered_set<char>& N,
            std::unordered_set<char>& Sigma,
            std::unordered_multimap<char, std::string>& P,
            char S): N(N), Sigma(Sigma), P(P), S(S) {}
};

#endif //CYK_GRAMMAR_H
