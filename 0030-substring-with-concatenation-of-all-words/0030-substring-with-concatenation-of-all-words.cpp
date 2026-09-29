class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {

        vector<int> result;

        int wordLength = words[0].length();
        int wordCount = words.size();

        unordered_map<string, int> required;

        for (string& word : words) {
            required[word]++;
        }

        for (int offset = 0; offset < wordLength; offset++) {

            int left = offset;
            int right = offset;
            int count = 0;

            unordered_map<string, int> window;

            while (right + wordLength <= s.length()) {

                string word = s.substr(right, wordLength);

                right += wordLength;

                if (required.find(word) == required.end()) {

                    window.clear();
                    count = 0;
                    left = right;

                    continue;
                }

                window[word]++;
                count++;

                while (window[word] > required[word]) {

                    string leftWord = s.substr(left, wordLength);

                    window[leftWord]--;
                    left += wordLength;
                    count--;
                }

                if (count == wordCount) {

                    result.push_back(left);

                    string leftWord = s.substr(left, wordLength);

                    window[leftWord]--;
                    left += wordLength;
                    count--;
                }
            }
        }

        return result;
    }
};