class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {

        int start = 0;
        int end = nums.size() - 1;
        vector<int> ans(nums.size(), 0);

        int curr = end;

        while(start <= end){
            if(abs(nums[start]) < abs(nums[end])){
                cout << nums[start] << " < " << nums[end] << endl;
                ans[curr] = nums[end] * nums[end];
                curr--;
                end--;
            }
            else{
                ans[curr] = nums[start] * nums[start];
                curr--;
                start++;
            }
        }
        return ans;

    }
};