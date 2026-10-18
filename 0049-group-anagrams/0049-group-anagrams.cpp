
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> groups;

        for (const string& s : strs) {
            int freq[26] = {};

            for (char c : s) {
                freq[c - 'a']++;
            }

            string key;
            for (int count : freq) {
                key += to_string(count) + "#";
            }

            groups[key].push_back(s);
        }

        vector<vector<string>> result;

        for (auto& entry : groups) {
            result.push_back(entry.second);
        }

        return result;
    }
};
