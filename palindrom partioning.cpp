class Solution {
public:
    vector<vector<string>> ans;
    
    bool isPalindrome(const string& s, int l, int r) {
        while(l < r) {
            if(s[l++] != s[r--]) {
                return false;
            }
        }
        return true;
    }
    
    void backtrack(const string& s, int ind, vector<string>& temp) {
        int n = s.length();
        if(ind == n) {
            ans.push_back(temp);
            return;
        }
        
        for(int i = ind; i < n; i++) {
            if(isPalindrome(s, ind, i)) {
                temp.push_back(s.substr(ind, i - ind + 1));
                backtrack(s, i + 1, temp);
                temp.pop_back();
            }
        }
    }
    
    vector<vector<string>> partition(string s) {
        vector<string> temp;
        backtrack(s, 0, temp);
        return ans;
    }
};
