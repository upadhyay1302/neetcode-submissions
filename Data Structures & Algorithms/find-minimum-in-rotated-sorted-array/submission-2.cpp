class Solution {
public:
    int pivotIndex(vector<int>&nums){
        int start = 0;
        int end = nums.size() - 1;
        while(start <= end){
            if(nums[start] <= nums[end])return start;
            if(start == end) return start;

            int mid = start + (end - start)/2;

            if(mid + 1 <= end && nums[mid] > nums[mid + 1]){
                return mid + 1;
            }
            if(mid - 1 >= 0 && nums[mid - 1] > nums[mid] ){
                return mid;
            }

            if(nums[start] > nums[mid]){
                end = mid - 1;
            }
            else start = mid + 1;
        }
        return -1;
    }
    int findMin(vector<int> &nums) {
        int pivot = pivotIndex(nums);
        cout << pivot;
        return nums[pivot];
    }
};
