class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        // 1. sort the array and then compare consecutive elements;
        // [1,2,3,1] => [1,1,2,3] one for loop i - 0 to nums.length()-2; compare i and i + 1
        // nlogn + n = nlogn 

        // 2. unordered map andas we iterate throguh array we store -> O(n) O(n) 

        unordered_map <int, int> mp;

        for(int i = 0; i < nums.size(); i++){
            if(mp.find(nums[i]) != mp.end()){
                return true;
            }
            mp[nums[i]]++;
        }
        return false;

    }
};