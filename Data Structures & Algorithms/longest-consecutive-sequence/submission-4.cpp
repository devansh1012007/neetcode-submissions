#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.empty()) return 0;
        sort(nums.begin(), nums.end());

        int ans = 1;
        int length = 1;

        for (size_t i = 1; i < nums.size(); ++i) {
            if (nums[i] == nums[i - 1]) {
                continue; // skip duplicates
            } else if (nums[i] == nums[i - 1] + 1) {
                length++;
            } else {
                length = 1;
            }
            ans = max(ans, length);
        }
        return ans;
    }
};