class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        string ans = "";
        int n = s.size();

        unordered_map<string, string> mp;
        for (auto &a: knowledge) {
            mp[a[0]] = a[1];
        }

        string key = "";

        for (int i = 0; i < n; i++) {
            if (s[i] == '(') {
                int j = i + 1;
                key.clear();

                for (; j < n && s[j] != ')'; j++) {
                    key += s[j];
                }
                
                ans += mp.find(key) == mp.end() ? "?" : mp[key];
                i = j;
            } else {
                ans += s[i];
            }
        }
        return ans;
    }
};