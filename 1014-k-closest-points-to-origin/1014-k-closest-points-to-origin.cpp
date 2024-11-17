class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<double, pair<int,int>>, vector<pair<double, pair<int,int>>>, greater<pair<double, pair<int,int>>>> pq;
        vector<vector<int>> ans;
        for(auto it: points)
        {
            int u = it[0], v = it[1];
            double dist = sqrt(pow(u, 2) + pow(v, 2));
            pq.push({dist, {u,v}});
        }

        while(!pq.empty() && k > 0)
        {
            int u = pq.top().second.first;
            int v = pq.top().second.second;
            pq.pop();
            k--;
            ans.push_back({u,v});
        }
        return ans;
    }
};