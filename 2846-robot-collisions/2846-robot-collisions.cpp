class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        
        vector<int> indices(positions.size());
        for (int i = 0; i < indices.size(); ++i) {
            indices[i] = i;
        }

        sort(indices.begin(), indices.end(), [&](int a, int b) {
            return positions[a] < positions[b];
        });

        vector<int> positions_sort(positions.size());
        vector<int> healths_sort(positions.size());
        vector<char> directions_sort(positions.size());

        for (int i = 0; i < indices.size(); ++i) {
            positions_sort[i] = positions[indices[i]];
            healths_sort[i] = healths[indices[i]];
            directions_sort[i] = directions[indices[i]];
        }

        for(int i=0;i<positions.size();i++){
            cout<<positions_sort[i]<<" "<<healths_sort[i]<<" "<<(char)directions_sort[i]<<endl;
        }

        stack<int> st;
        vector<int> ans;
        int pos, curr;
        for(int i=0;i<positions.size();i++){
            if(directions_sort[i] == 'R')
            st.push(i);
            else{
                while(!st.empty()){
                    pos = st.top();
                    st.pop();
                    if(healths_sort[pos]>healths_sort[i]){
                        st.push(pos);
                        healths_sort[pos]--;
                        healths_sort[i] = 0;
                        break;
                    }
                    else if(healths_sort[pos]<healths_sort[i]){
                        healths_sort[pos] = 0;
                        healths_sort[i]--;
                    }
                    else{
                        healths_sort[pos] = 0;
                        healths_sort[i] = 0;
                        break;
                    }
                }
            }
        }
        for (int i = 0; i < indices.size(); ++i) {
            healths[indices[i]] = healths_sort[i];
        }
        for(int i=0;i<healths.size();i++){
            if(healths[i]!=0)
            ans.push_back(healths[i]);
        }
        return ans;
    }
};