class Solution {
public:
    int reverseDegree(string s) {
        int degree = 0;
        for (int i = 0; i < s.size(); i++) {
            char c = s[i];
            int x = ((c - 'z') * -1) + 1;
            degree += x * (i + 1);
        }
        
        return degree;
    }
};