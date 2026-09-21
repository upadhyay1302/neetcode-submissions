class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        sort(nums.rbegin(), nums.rend());
        return nums[k - 1];
    }
};
// sort the nums and then extract the kth largest would be direct index access
// [4,2,3,1] sort [4,3,2,1] k = 2 return arr[k - 1];
