//
// Created by shatar on 03.12.22.
//

#include <iostream>
#include <vector>

#include "Grammar.h"

bool process_epsilon(Grammar& gram) {
    for (auto iter = gram.P.begin(); iter != gram.P.end(); ++iter) {
        if (iter->second == "") {
            return true;
        }
    }
    return false;
}

void initialize(std::unordered_map<char, std::vector<std::vector<bool>>>& dp,
                Grammar& gram, std::string& word) {
    size_t len = word.size();
    for (char non_terminal : gram.N) {
        dp[non_terminal] =
                std::vector<std::vector<bool>>(len, std::vector<bool>(len, false));
        for (size_t pos = 0; pos < len; ++pos) {
            for (auto iter = gram.P.begin(); iter != gram.P.end(); ++iter) {
                if ((iter -> first == non_terminal) &&
                    (iter -> second.size() == 1) &&
                    (iter -> second[0] == word[pos])) {
                    dp[non_terminal][pos][pos] = true;
                }
            }
        }
    }
}

void count_dp(std::unordered_map<char, std::vector<std::vector<bool>>>& dp,
              Grammar& gram, std::string& word) {
    size_t len = word.size();
    for (size_t substring_len = 1; substring_len < len; ++substring_len) {
        for (size_t start = 0; start < len - substring_len; ++start) {
            for (auto iter = gram.P.begin(); iter != gram.P.end(); ++iter) {
                if (iter->second.size() == 2) {
                    for (size_t mid_position = start;
                         mid_position < start + substring_len;
                         ++mid_position) {
                        if (dp[iter->second[0]][start][mid_position] &&
                            dp[iter->second[1]][mid_position + 1]
                            [start + substring_len]) {
                            dp[iter->first][start][start + substring_len] =
                                    true;
                        }
                    }
                }
            }
        }
    }
}

bool CYK(Grammar& gram, std::string& word) {
    if (word == "") {
        return process_epsilon(gram);
    }
    size_t len = word.size();
    std::unordered_map<char, std::vector<std::vector<bool>>> dp;
    initialize(dp, gram, word);
    count_dp(dp, gram, word);
    return dp[gram.S][0][len - 1];
}
