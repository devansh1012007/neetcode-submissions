// approch : 
/*
     1. : sort and then just run a check if adjecent are same ( nlogn + n )
     2. : make an hash map to keep track of the numbers, on the first repeat the loop ends (n+1)
*/
#include <iostream>
#include <unordered_map>
class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {       
     //approch 2:
     std::unordered_map<int, bool> hash;
     for (auto it = nums.begin(); it != nums.end(); ++it){
        if (hash.contains(*it)){
            return true;
        }
        else{
            hash.insert({*it, false});
        }
     }
     return false;
    }
};