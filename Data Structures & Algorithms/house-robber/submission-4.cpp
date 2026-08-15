class Solution {
public:
    int solve(vector<int>& nums){
        vector<int> DP(nums.size(), -1);
        DP[0] = nums[0];
        if(nums.size() > 1)DP[1] = max(nums[0], nums[1]);

        for(int i = 2; i < nums.size();i++){
            int include = nums[i] + DP[i - 2];
            int exclude = 0 + DP[i - 1];

            DP[i] = max(include, exclude);
        }
        return DP[nums.size() -1];
    }
    int rob(vector<int>& nums) {
        return solve(nums);
    }
};
