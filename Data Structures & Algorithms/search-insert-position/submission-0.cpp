class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int start = 0;

        int end = nums.size() - 1;

        int ans = nums.size();

        while(start <= end){
            int mid = (start + end)/2;

            cout << start << " " << end << endl;
            cout << mid << endl;

            if(nums[mid] == target){
                return mid;
            }
            else if(nums[mid] < target){
                // ans = mid;
                start = mid + 1;
            }
            else{
                ans = mid;
                end = mid - 1;
            } 
        }

        return ans;
    }
};