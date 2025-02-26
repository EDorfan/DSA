class Solution {
    public:
        void reverseString(vector<char>& s) {
            vector<char> tmp(s.size());
            for (int i = 0; i < s.size(); i++) {
                tmp[s.size()-i-1] = s[i];
            }
            s = tmp;
                        
        }
    };