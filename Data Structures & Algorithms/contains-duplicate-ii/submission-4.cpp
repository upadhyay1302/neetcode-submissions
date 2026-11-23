class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {

        // if(k == 1)return false;

        if(nums.size() == 0 || nums.size() == 1) return false;
        int windowSize = k;

        // windowSize = min(windowSize, static_cast<int>(nums.size() - 1));
        
        unordered_map<int,int> mp;
        for(int i = 0; i <= windowSize; i++){
            if(mp.find(nums[i]) != mp.end()){
                return true;
            }
            mp[nums[i]]++;
        }

        for(int i = windowSize + 1; i < nums.size(); i++){

            int toAdd = nums[i];

            int toRemove = nums[i - k - 1];

            mp[toRemove]--;
            if(mp[toRemove] == 0) mp.erase(toRemove);
            if(mp.find(toAdd) != mp.end()){
                return true;
            }
            
            mp[toAdd]++;
        }
        return false;
    }
};