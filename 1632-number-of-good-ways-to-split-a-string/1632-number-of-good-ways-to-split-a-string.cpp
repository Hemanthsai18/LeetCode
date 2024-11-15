class Solution {
public:
    int numSplits(string s) {
        set<char> left, right;
        int ans=0;
        vector<int> leftc(s.length());
        for(int i=0;i<s.length();i++){
            left.insert(s[i]);
            leftc[i] = left.size();
        }
        for(int i=s.length()-1;i>0;i--){
            right.insert(s[i]);
            cout<<right.size()<<" "<<leftc[i-1]<<" ";
            if(leftc[i-1] == right.size())
            ans++;
        }
        return ans;
    }
};