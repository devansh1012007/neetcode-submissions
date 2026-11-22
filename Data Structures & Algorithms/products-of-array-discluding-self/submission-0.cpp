class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n, 1);

        for (int i = 1; i < n; i++) {
            res[i] = res[i - 1] * nums[i - 1];
        }
        int postfix = 1;
        for (int i = n - 1; i >= 0; i--) {
            res[i] *= postfix;
            postfix *= nums[i];
        }
        return res;
    }
};




/* 
we can use the divison method as it is super ez .we can use hash alongside to get faster results. 
=======================================================================================
for solve it in O(n) time without using the division operation -- we use recursion 
at each level v have 3 var :
- curr val for the ittrator via hashmap
- returns prod of all the value and the current val
- recieves the prod for all the elements after it 
=======================================================================================
I tried hash table but couldn't find answer in O(n)
=======================================================================================
# Best way based on solution:
we use prefix and postfix to calculate product of all the number before ittrator.
*/