class Solution {
public:
    vector<string> ans;
    void f(int up_ob, int ob_rem, int cb_rem, string &str) {
        if (ob_rem + cb_rem == 0) {
            ans.push_back(str);
            return;
        }

        if (ob_rem > 0) {
            str += "(";
            f(up_ob + 1, ob_rem - 1, cb_rem, str);
            str.pop_back();
        }
        if (up_ob > 0 && cb_rem > 0) {
            str += ")";
            f(up_ob - 1, ob_rem, cb_rem - 1, str);
            str.pop_back();
        }
    }

    vector<string> generateParenthesis(int n) {
        string inte = "";
        f(0, n, n, inte);
        return ans;
    }
};