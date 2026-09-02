class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        unordered_set<char> window;

        int left = 0;
        int maxLength = 0;

        for (int right = 0; right < s.length(); right++) {

            while (window.find(s[right]) != window.end()) {
                window.erase(s[left]);
                left++;
            }

            window.insert(s[right]);

            int currentLength = right - left + 1;

            maxLength = max(maxLength, currentLength);
        }

        return maxLength;
    }
};