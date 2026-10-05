class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int ans = 0;

        for(int i = 0; i < nums.size(); i++){
            int currSum = 0;
            for(int j = i; j < nums.size(); j++){
                currSum += nums[j];

                if(currSum % k == 0) ans++;
            }
        }

        return ans;
    }
};