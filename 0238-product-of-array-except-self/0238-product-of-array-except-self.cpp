class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> front(nums.size());
        front[0] = nums[0];
        vector<int> back(nums.size());
        back[nums.size()-1] = nums[nums.size()-1];
        for(int i=1;i<nums.size();i++){
            front[i] = front[i-1] * nums[i];
        }
        for(int i=nums.size()-2;i>=0;i--){
            back[i] = back[i+1] * nums[i];
        }
        vector<int> ans(nums.size());
        ans[0] = back[1];
        ans[nums.size()-1] = front[nums.size()-2];
        for(int i=1;i<nums.size()-1;i++){
            ans[i] = front[i-1] * back[i+1];
        }
        return ans;
    }
};