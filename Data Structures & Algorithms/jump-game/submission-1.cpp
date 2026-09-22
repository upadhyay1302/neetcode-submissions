class Solution {
public:
    bool solve(vector<int>&nums, int i, vector<int>&DP){
        if(i == nums.size() -1 ) return true;

        if(nums[i] == 0) return false;

        if(DP[i] != -1) return DP[i];

        bool ans = false;
        for(int jump = 1; jump <= nums[i]; jump++){
            ans = ans || solve(nums, i + jump, DP) ;
        }
        DP[i] = ans;
        return DP[i];
    }
    bool canJump(vector<int>& nums) {
        vector<int>DP(nums.size(), -1);
        return solve(nums, 0, DP);
    }
};

// DP[i] = starting at index i can we reach till the end index using the elements in the nums starting at index i
// 3 states 
// -1 undecalared state default
// 0 false
// 1 true
