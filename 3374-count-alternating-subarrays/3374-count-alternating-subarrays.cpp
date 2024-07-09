class Solution {
public:
    long long countAlternatingSubarrays(vector<int>& nums) {
        long long ans = 0;
        long long start = 0;
        for(long long i=1;i<nums.size();i++){
            if(nums[i] != nums[i-1])
            continue;
            else{
                ans += calc(i-1-start);
                start = i;
            }
        }
        ans+=calc(nums.size()-1-start);
        return ans;
    }
    long long calc(long long n){
        n++;
        long long int sum = n*(n+1)/2;
        return sum;
    }
};