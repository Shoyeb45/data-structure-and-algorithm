class Solution {
public:
    int maxDepth(string s) {
        int n = s.size();

        stack<char> st;
        int ans = 0;
        int a = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == '(') {
                a++;
                st.push(s[i]);
            } else if (s[i] == ')' && !st.empty() && st.top() == '(') {
                a--;
                st.pop();
            }
            ans = max(ans, a);
        }
        return ans;
    }
};