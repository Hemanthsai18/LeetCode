class Solution {
public:
    string reverseParentheses(string s) {
        stack<int> st;
        string ans = "";
        for(int i=0;i<s.length();i++){
            if(s[i] == '('){
                st.push(i);
            }
            else if(s[i] == ')'){
                int k = st.top();
                st.pop();
                reverse(s.begin() + k, s.begin() + i);

                cout<<i<<" "<<k<<endl;
                
            }
        }
        for(int i=0;i<s.length();i++){
            if(s[i] != '(' && s[i] != ')'){
                ans.push_back(s[i]);
            }
        }
        return ans;
    }
};