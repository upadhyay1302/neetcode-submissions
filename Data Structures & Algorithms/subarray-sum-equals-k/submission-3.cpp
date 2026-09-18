class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> mp;

        int ans = 0;

        int sum = 0;
        int currSum = 0;
        mp[0] = 1;

        for(auto num : nums){
            currSum += num;
            int diff = currSum - k;
            ans += mp[diff];
            mp[currSum]++;
        }
        return ans;
    }
};