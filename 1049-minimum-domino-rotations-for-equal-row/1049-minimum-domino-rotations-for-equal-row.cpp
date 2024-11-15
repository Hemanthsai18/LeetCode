class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        map<int, int> mp;
        for(int i=0;i<tops.size();i++){
            mp[tops[i]]++;
            mp[bottoms[i]]++;
        }
        vector<int> temp;
        for(int i=1;i<7;i++){
            if(mp[i]>=tops.size()){
                temp.push_back(i);
            }
        }


        if(temp.size()==0)
        return -1;
        int ans=INT_MAX;
        bool t = true;
        for(int j=0;j<temp.size();j++){
            int c = 0;
            for(int i=0;i<tops.size();i++){
                if(tops[i]!=temp[j]){
                    if(bottoms[i]!=temp[j]){
                        t = false;
                        break;
                    }
                    else c++;
                }
            }
            int d=0;
            for(int i=0;i<tops.size();i++){
                if(bottoms[i]!=temp[j]){
                    if(tops[i]!=temp[j]){
                        t = false;
                        break;
                    }
                    else d++;
                }
            }
            c = min(c,d);
            cout<<c;
            if(t)
            ans=min(ans,c);
            t=true;
        }
        return (ans==INT_MAX)?-1:(min((int)tops.size()-ans,ans));
    }
};