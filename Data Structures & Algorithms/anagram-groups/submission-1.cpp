//approch 2
/*
#include <unordered_map>
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<unordered_map,vector<string>> wordmap; //this is not possible
        for (string item:strs){
            unordered_map<char, int> temp;
            for (char c : item) {
                temp[c]++;
            }
            wordmap[temp].push_back(item);
        }
        vector<vector<string>> answer;
        for (const auto& [key, value] : wordmap) {
            //std::cout << key << ": " << value << "\n";
            answer.pushback(value);
        }
        return answer;
    }

};
*/
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;
//approch 2 fixed
/*
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> wordmap;

        for (const string& item : strs) {
            int count[26] = {0};
            for (char c : item) {
                count[c - 'a']++;
            }
            string key;
            for (int i = 0; i < 26; i++) {
                key += '#' + to_string(count[i]);
            }
            wordmap[key].push_back(item);
        }

        vector<vector<string>> answer;
        for (auto& [key, value] : wordmap) {
            answer.push_back(move(value));
        }
        return answer;
    }
};
*/
// approch 1 :

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> wordmap;
        string temp;
        for (const string& item : strs) {
            temp = item;
            sort(temp.begin(), temp.end());   
            wordmap[temp].push_back(item);
        }
        
        vector<vector<string>> answer;
        for (auto& [key, value] : wordmap) {
            answer.push_back(move(value));
        }
        return answer;
    }
};


// approch 1 : sort all and then add them to sublist , keep track using hash
// complexity : nlogn  
// approch 2 : character counting using hash and grouping based on that 
//complexity : n