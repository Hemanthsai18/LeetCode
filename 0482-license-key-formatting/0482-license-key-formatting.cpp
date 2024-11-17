class Solution {
public:
    string licenseKeyFormatting(string s, int k) {
        s.erase(std::remove(s.begin(), s.end(), '-'), s.end());
        string ans="";
        for(int i=s.length()-1;i>=0;){
            for(int j=0;j<k&&i>=0;j++){
                if(s[i]>='a' && s[i]<='z')
                s[i]-=32;
                ans += s[i];
                i--;
            }
            ans += "-";
        }
        if(ans.length()==0)
        return ans;
        reverse(ans.begin(), ans.end());
        return ans.substr(1, ans.length());
    }
};