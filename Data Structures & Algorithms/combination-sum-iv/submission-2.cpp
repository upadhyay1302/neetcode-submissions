class Solution {
public:
    int solve(vector<int>&nums, int target, vector<int>&DP){
        if(target == 0) return 1;
        if(DP[target] != -1) return DP[target];
        int ans = 0;
        for(int num : nums){
            if(target < num) break;
            ans += solve(nums, target - num, DP);
        }
        DP[target]= ans;
        return DP[target];
    }
    int combinationSum4(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        vector<int>DP(target + 1, -1);
        return solve(nums,target, DP);
    }
};