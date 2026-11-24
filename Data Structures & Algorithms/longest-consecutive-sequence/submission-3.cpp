#include <unordered_set>
using namespace std;
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> numbers(nums.begin(),nums.end());
        int ans =0;
        for (int items:numbers){
            if (numbers.find(items-1) == numbers.end()){
                int length = 1;
                while(numbers.find(items+length) != numbers.end()){
                    length++;
                }
                ans = max(ans,length);
            }
        }
        return ans;
    }
};