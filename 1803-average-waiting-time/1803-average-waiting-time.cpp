#include<cmath>
class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        double waiting = 0;
        int currTime=0;
        for(int i=0;i<customers.size();i++){
            int start = customers[i][0];
            int time = customers[i][1];
            if(currTime<=start){
                currTime = start+time;
                waiting+=time;
            }
            else{
                int wait = (currTime + time - start) ;
                currTime = start + wait;
                waiting += wait;
            }
        }
        return waiting/customers.size();
    }

};