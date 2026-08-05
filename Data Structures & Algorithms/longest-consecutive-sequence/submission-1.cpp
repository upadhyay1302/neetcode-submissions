class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int ans = 0;
        unordered_set<int> store(nums.begin(), nums.end());

        for(int i = 0; i < nums.size(); i++){
            int curr = nums[i];
            if(store.find(curr - 1) == store.end()){
                int length = 1;
                while(store.find(curr + length) != store.end()){
                    length++;
                }
                ans = max(ans, length);
            }
        }

        return ans;
    }
};
