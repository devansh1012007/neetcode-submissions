#include <unordered_map>
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
    std::unordered_map<int, int> maps;
    for (auto it = nums.begin(); it != nums.end(); ++it) {
        maps[*it]++;
    }
    std::vector<int> answer;
    std::vector<std::pair<int, int>> vec(maps.begin(), maps.end());
    std::sort(vec.begin(), vec.end(), [](const auto& a, const auto& b) {
        return a.second > b.second;
    });
    auto it = vec.begin();
    while (it != vec.end() && k >0) {
        answer.push_back(it->first);
        it++;
        k--;
    }
    return answer;
    }
};
/*
option 1 
make a hash map for keeping track of freq
## important point that i misses : they are asking top 2 most frequest not the frequency threshold   
time complexity : n

*/