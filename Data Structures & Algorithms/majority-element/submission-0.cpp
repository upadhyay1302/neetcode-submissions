class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int countNeeded = nums.size()/2;
        int currCount = 0;
        unordered_map<int, int> mp;
        for(int i = 0; i < nums.size(); i++){
            mp[nums[i]]++;
        }

        for(auto &[key, value]:mp){
            if(value > countNeeded) return key;
        }
        return -1;
    }
};