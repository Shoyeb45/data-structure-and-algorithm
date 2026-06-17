class Solution {
public:
    char processStr(string s, long long k) {
        long long final_length = 0;
        vector<long long> lengths(s.size(), 0);

        for (int i = 0; i < s.size(); i++) {
            char ch = s[i];
            if (ch == '*') {
                final_length = max(0LL, final_length - 1);
            } else if (ch == '#') {
                final_length *= 2;
            } else if (ch != '%') {
                final_length++;
            }
            lengths[i] = final_length;
        }
        if (k >= final_length) return '.';

        for (int i = s.size() - 1;; i--) {
            switch (s[i]) {
            case '*':
                break;
            case '#':
                if (k >= lengths[i] / 2)
                    k -= lengths[i] / 2;
                break;
            case '%':
                k = lengths[i] - 1 - k;
                break;
            default: // s[i] is a character
                if (lengths[i] == k + 1)
                    return s[i];
            }
        }
        return '.';
    }
};