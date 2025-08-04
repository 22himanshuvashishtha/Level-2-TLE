class Solution {
public:
    int minInsertions(string s) {
        int open=0;
        int ans=0;
        int i=0;
        while(i<s.length()){
            if(s[i]=='('){
                open++;
                i++;
            }else{
                if (i + 1 < s.length() && s[i + 1] == ')') {
                    if (open > 0) open--;
                    else ans++;  
                    i += 2;
                } else {
                   if (open > 0) {
                        open--;
                        ans++;  
                    } else {
                        ans += 2;  
                    }
                    i++;
                }
               
            }
        }
        ans += open * 2;
        return ans;
    }
};
