/*
approch :
- use hashmap/hashsets with char for memory conservation as checkers for the row , col and sub-box, while you ittrate thorught the full map row by row.
- for conserving space use refrance instead of copying numbers for each hash map
- there will be multiple hash table at once. 
*/
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_set<char> rows[9];
        unordered_set<char> cols[9];
        unordered_set<char> boxes[9];

        for (int r = 0; r < 9; ++r) {
            for (int c = 0; c < 9; ++c) {
                char val = board[r][c];
                if (val == '.') {continue;}
                int boxIdx = (r / 3) * 3 + (c / 3); //smart
                // insert().second returns false if the element already exists
                if (!rows[r].insert(val).second ||!cols[c].insert(val).second ||
                    !boxes[boxIdx].insert(val).second) {return false;}
            }
        }
        return true;
    }
};
// Important : we can use 'bitmask' for a more memory optimized approch. IDK that so the following in AI code:

/*
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int rows[9] = {0}, cols[9] = {0}, boxes[9] = {0};

        for (int r = 0; r < 9; ++r) {
            for (int c = 0; c < 9; ++c) {
                if (board[r][c] == '.') continue;

                int bit = 1 << (board[r][c] - '1');
                int boxIdx = (r / 3) * 3 + (c / 3);

                if ((rows[r] & bit) || (cols[c] & bit) || (boxes[boxIdx] & bit)) {
                    return false;
                }

                rows[r] |= bit;
                cols[c] |= bit;
                boxes[boxIdx] |= bit;
            }
        }
        return true;
    }
};
*/