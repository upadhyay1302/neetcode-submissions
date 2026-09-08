class Solution {
public:
    void reverse(vector<int>&nums, int start, int end){
        int i = start;
        int j = end;

        while(i < j){
            swap(nums[i], nums[j]);
            i++;
            j--;
        }
    }
    void rotate(vector<int>& nums, int k) {
        int start = 0;
        int end = nums.size()-1;

        k = k % nums.size();

        reverse(nums, start, end);
        reverse(nums, start, k - 1);
        reverse(nums, k, end);

    }
};