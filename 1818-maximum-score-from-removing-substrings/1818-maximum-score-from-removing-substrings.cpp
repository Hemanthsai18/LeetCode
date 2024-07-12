class Solution {
public:
    int maximumGain(string s, int x, int y) {
        string mainStr, nonStr;
        if(x>y){
            mainStr = "ab";
            nonStr = "ba";
        }
        else{
            mainStr = "ba";
            nonStr = "ab";
            int temp = x;
            x=y;
            y=temp;
        }
        int ans = 0;
        stack<char> st;
        for(int i=0;i<s.length();i++){

            if(s[i]=='a' or s[i] == 'b')
            st.push(s[i]);
            else{
                ans+=calc(st, x, mainStr, y, nonStr);
                st = stack<char>();
            }
        }
        if(!st.empty())
        ans+=calc(st, x, mainStr, y, nonStr);
        return ans;
    }

    int calc(stack<char> st, int x, string mainStr, int y, string nonStr){
        int ans = 0;
        stack<char> st2;
        while(!st.empty()){
            if(st2.empty()){
                
                st2.push(st.top());
                st.pop();
            }
            else{
                string tm = string(1, char(st.top())) + string(1, char(st2.top()));
                if(tm == mainStr){
                    ans+=x;
                    st.pop();
                    st2.pop();
                }
                else{
                    st2.push(st.top());
                    st.pop();
                }
            }
        }
        stack<char> st3;
        while(!st2.empty()){
            if(st3.empty()){
                st3.push(st2.top());
                st2.pop();
            }
            else{
                string tm = string(1, char(st2.top())) + string(1, char(st3.top()));
                if(tm == mainStr){
                    ans+=y;
                    st2.pop();
                    st3.pop();
                }
                else{
                    st3.push(st2.top());
                    st2.pop();
                }
            }
        }
        return ans;
    }

};