class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int>n;
        int l=s.length();
        stack<char>st;
        int i=0;
        n.push(-1);
        int ans=0;
        while(i<l){
          if(s[i]=='('){
            st.push(s[i]);
            n.push(i);
          }else {
             if(!st.empty()){
                st.pop();
                n.pop();
                ans=max(ans,i-n.top());
             }else{
                n.push(i);
             }
          }
          i++;
        }
        return ans;
    }
};
