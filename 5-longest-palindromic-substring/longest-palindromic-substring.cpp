#include <string>
#include <algorithm>
#include <iostream>

class Solution {
private:
    // Helper function to expand around the given left and right indices
    // Returns the length of the palindrome
    int expandAroundCenter(const std::string& s, int left, int right) {
        while (left >= 0 && right < s.length() && s[left] == s[right]) {
            left--;
            right++;
        }
        // The length of the palindrome is (right - 1) - (left + 1) + 1
        return right - left - 1;
    }

public:
    std::string longestPalindrome(std::string s) {
        if (s.empty()) return "";
        
        int start = 0, maxLength = 0;
        
        for (int i = 0; i < s.length(); ++i) {
            // Case 1: Odd length palindromes (e.g., "aba", center is 'b')
            int len1 = expandAroundCenter(s, i, i);           
            int len2 = expandAroundCenter(s, i, i + 1);
            int len = std::max(len1, len2);
            if (len > maxLength) {
                maxLength = len;
                start = i - (len - 1) / 2;
            }
        }
        
        return s.substr(start, maxLength);
    }
};