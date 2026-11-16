class Solution {
public:
    string digitSum(string s, int k) {
        string inte = "";

        while (s.size() > k) {
            inte = "";
            int val = 0;
            for (int i = 0; i < s.size(); i++) {
                if ((i + 1) % k == 0) {
                    val += (s[i] - '0');
                    inte += to_string(val);
                    val = 0;
                } else {
                    val += (s[i] - '0');
                }
            }

            if (s.size() % k != 0) {
                inte += to_string(val);

            }
            s = inte;
        }
        return s;
    }
};