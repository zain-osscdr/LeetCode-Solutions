class Solution {
public:
    string longestPalindrome(string s) {

        int bestStart = 0;
        int bestLength = 1;

        auto expand = [&](int left, int right) {

            while (left >= 0 &&
                   right < s.length() &&
                   s[left] == s[right]) {

                int currentLength = right - left + 1;

                if (currentLength > bestLength) {
                    bestStart = left;
                    bestLength = currentLength;
                }

                left--;
                right++;
            }
        };

        for (int i = 0; i < s.length(); i++) {

            expand(i, i);

            expand(i, i + 1);
        }

        return s.substr(bestStart, bestLength);
    }
};