class Solution {
public:
    string removeDuplicateLetters(string s) {
        map<char, int> freq;
        map<char, bool> inStack; 
        stack<char> st;

        for (char ch : s) {
            freq[ch]++;
        }

        for (char ch : s) {
            freq[ch]--;

            if (inStack[ch]) continue;

            while (!st.empty() && st.top() > ch && freq[st.top()] > 0) {
                inStack[st.top()] = false; 
                st.pop();
            }

            st.push(ch);
            inStack[ch] = true;
        }

        string ans = "";
        while (!st.empty()) {
            ans += st.top();
            st.pop();
        }
        reverse(ans.begin(), ans.end());

        return ans;
    }
};
