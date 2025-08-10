class Solution {
public:
    int calculate(string s) {
        stack<int>st;
        int sign=1;
        int result=0;
        int no=0;
        for(int i=0;i<s.length();i++){
            if(isdigit(s[i])){
              no=(no*10)+(s[i]-'0');
            }else if(s[i]=='+'){
              result+=(sign*no);
              sign=1;
              no=0;
            }else if(s[i]=='-'){
              result+=(sign*no);
              sign=-1;
              no=0;
            }else if(s[i]=='('){
              st.push(result);
              st.push(sign);
              no=0;
              sign=1;
              result=0;
            }else if(s[i]==')'){
                result+=(sign*no);
                no=0;
              int ns = st.top();
              st.pop();
              int nr=(st.top());
              st.pop();
              result*=ns;
              result+=nr;
            }
        }
        result+=(no*sign);
        return result;
    }
};
