class Solution {
public:
    int findTheWinner(int n, int k) {
        queue<int> q;
        for(int i=0;i<n;i++){
            q.push(i+1);
        }
        while(1){
            if(q.size()==1)
            break;
            for(int i=0;i<k-1;i++){
                int t = q.front();
                q.pop();
                q.push(t);
            }
            q.pop();
            
        }
        return q.front();
    }
};