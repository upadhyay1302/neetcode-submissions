class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;

        for(int i = 0; i < n; i++){
            int cnt = 0;
            for(int j = i; j < n; j++){
                if(nums[j] == 0) break;
                cnt++;
            }
            ans = max(cnt, ans);
        }
        return ans;
    }
};