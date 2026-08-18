class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int ans = INT_MIN;
        int pre = 1;
        int suff = 1;
        for(int i = 0; i < nums.size(); i++){

            if(suff == 0) suff = 1;
            if(pre == 0) pre = 1;

            pre = pre * nums[i];
            suff = suff * nums[nums.size() - i - 1];

            ans = max(ans, max(pre, suff));
        }
        return ans;
    }
};
