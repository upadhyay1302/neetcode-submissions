class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int>ans;
        sort(nums.begin(), nums.end());
        int start = 0;
        int end = nums.size()-1;

        while(start < end){
            cout << start << " "<<end << endl;
            if(nums[start]+nums[end] == target){
                ans.push_back(start);
                ans.push_back(end);
                break;
            }
            else if(nums[start] + nums[end] > target) end--;
            else start++;
        }
        return ans;
    }
};
