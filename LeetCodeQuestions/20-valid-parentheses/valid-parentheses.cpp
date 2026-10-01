class Solution {
public:
    bool isValid(string s) {
        stack<char> st;

        auto check_pair = [&](char ch, char o_br, char c_br) -> bool {
            return ch == c_br && st.top() == o_br;
        };

        for (char ch: s) {
            if (ch == '(' || ch == '[' || ch == '{') {
                st.push(ch);
            } else if (st.empty()) {
                return false;
            } else if (check_pair(ch, '(' , ')') || check_pair(ch, '[', ']') || check_pair(ch, '{', '}')) {
                st.pop();
            } else {
                return false;
            }
        }
        return st.empty();
    }
};