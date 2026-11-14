class Solution {
public:

    // Encode: Convert vector of strings into one string
    string encode(vector<string>& strs) {

        string ans = "";

        for (string s : strs) {

            // Add length of string
            ans += to_string(s.size());

            // Add delimiter
            ans += '#';

            // Add actual string
            ans += s;
        }

        return ans;
    }

    // Decode: Restore original vector of strings
    vector<string> decode(string s) {

        vector<string> ans;

        int i = 0;

        while (i < s.size()) {

            // Step 1: Find delimiter '#'
            int j = i;

            while (s[j] != '#') {
                j++;
            }

            // Step 2: Extract string length
            int len = stoi(s.substr(i, j - i));

            // Step 3: Move to beginning of actual string
            i = j + 1;

            // Step 4: Extract exactly 'len' characters
            string word = s.substr(i, len);

            ans.push_back(word);

            // Step 5: Move to next encoded string
            i = i + len;
        }

        return ans;
    }
};