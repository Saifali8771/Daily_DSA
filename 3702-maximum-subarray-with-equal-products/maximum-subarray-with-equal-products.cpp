hdsfsgfabfga7bfbgfuawh8y32uhbdjfs#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxLength(vector<int>& nums) {
        int n = nums.size();
        int maxLen = 1;
        long long totalLcm = 1;
        int maxVal = 0;
        for (int x : nums) {
            totalLcm = std::lcm(totalLcm, (long long)x);
            maxVal = max(maxVal, x);
        }
        long long maxPossibleProduct = totalLcm * maxVal;

        for (int i = 0; i < n; ++i) {
            long long currentProd = 1;
            long long currentGcd = 0;
            long long currentLcm = 1;

            for (int j = i; j < n; ++j) {
                if (currentProd > maxPossibleProduct / nums[j]) {
                    break;
                }
                currentProd *= nums[j];
                currentGcd = std::gcd(currentGcd, (long long)nums[j]);
                currentLcm = std::lcm(currentLcm, (long long)nums[j]);

                if (currentProd == currentLcm * currentGcd) {
                    maxLen = max(maxLen, j - i + 1);
                }
            }
        }
        return maxLen;
    }
};
