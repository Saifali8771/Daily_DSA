#include <string>
#include <vector>

class Solution {
public:
    std::string getPermutation(int n, int k) {
        std::vector<int> fact(n, 1);
        for (int i = 1; i < n; ++i) {
            fact[i] = fact[i - 1] * i;
        }

        std::vector<int> numbers;
        for (int i = 1; i <= n; ++i) {
            numbers.push_back(i);
        }
        --k;

        std::string result = "";
        for (int i = n; i >= 1; --i) {
            int blockSize = fact[i - 1];
            int index = k / blockSize;
            
            result += std::to_string(numbers[index]);
            numbers.erase(numbers.begin() + index);

            k %= blockSize;
        }

        return result;
    }
};