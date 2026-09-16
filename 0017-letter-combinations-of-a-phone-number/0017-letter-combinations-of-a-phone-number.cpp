class Solution {
public:
    vector<string> letterCombinations(string digits) {

        if (digits.empty()) {
            return {};
        }

        vector<string> mapping = {
            "", "", "abc", "def",
            "ghi", "jkl", "mno",
            "pqrs", "tuv", "wxyz"
        };

        vector<string> result;
        string current;

        function<void(int)> backtrack = [&](int index) {

            if (index == digits.length()) {
                result.push_back(current);
                return;
            }

            string letters = mapping[digits[index] - '0'];

            for (char letter : letters) {

                current.push_back(letter);

                backtrack(index + 1);

                current.pop_back();
            }
        };

        backtrack(0);

        return result;
    }
};