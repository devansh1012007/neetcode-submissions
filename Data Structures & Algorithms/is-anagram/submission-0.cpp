#include <unordered_map>
#include <string>
using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) {
            return false;
        }
        unordered_map<char, int> smap;
        unordered_map<char, int> tmap;
        for (char c : s) {
            smap[c]++;
        }
        for (char c : t) {
            tmap[c]++;
        }
        return smap == tmap;
    }
};

// approch :
    /* 
    1. we read the string and save data in hash table and for contnet of both tables and we compare, compair ther lengths too
    complexity : n
    2. we ittrate through 1 string and remove elements for the other one as we ittrare, sort first (sort and compair)
    complexity : 
    */
