class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {

        vector<unordered_set<char>> rows(9);
        vector<unordered_set<char>> cols(9);
        vector<unordered_set<char>> boxes(9);

        for (int row = 0; row < 9; row++) {

            for (int col = 0; col < 9; col++) {

                char digit = board[row][col];

                if (digit == '.') {
                    continue;
                }

                int boxIndex = (row / 3) * 3 + (col / 3);

                if (rows[row].count(digit) ||
                    cols[col].count(digit) ||
                    boxes[boxIndex].count(digit)) {

                    return false;
                }

                rows[row].insert(digit);
                cols[col].insert(digit);
                boxes[boxIndex].insert(digit);
            }
        }

        return true;
    }
};