class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        string ans = "";
        int n = s.size();

        map<string, string> mp;
        for (auto &a: knowledge) {
            mp[a[0]] = a[1];
        }

        for (int i = 0; i < n; i++) {
            if (s[i] == '(') {
                string key = "";
                int j = i + 1;
                for (; j < n && s[j] != ')'; j++) {
                    key += s[j];
                }
                if (mp.find(key) != mp.end()) {
                    ans += mp[key];
                } else {
                    ans += "?";
                }
                i = j;
            } else {
                ans += s[i];
            }
        }
        return ans;
    }
};