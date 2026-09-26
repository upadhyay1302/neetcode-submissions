class Solution {
public:
    int pivotIndex(vector<int>&nums){
        int start = 0;
        int end = nums.size() - 1;
        while(start <= end){
            if(start == end) return start;
            int mid = start + (end - start)/2;
            if(mid + 1 <= end && nums[mid] > nums[mid + 1]){
                return mid;
            }
            if(mid - 1 >= 0 && nums[mid] < nums[mid - 1]){
                return mid - 1;
            }
            if(nums[start] > nums[mid]){
                end = mid - 1;
            }
            else{
                start = mid + 1;
            }
        }
        return -1;
    }

    int binarySearch(int start, int end, vector<int>&arr, int target){
        cout << start << end << endl;
        while(start <= end){
            
            int mid = start + (end - start)/2;

            if(arr[mid] == target){
                return mid;
            }
            if(arr[mid] < target){
                start = mid + 1;
            }
            else end = mid - 1;
        }
        return -1;
    }

    int search(vector<int>& nums, int target) {
        int pivotindex = pivotIndex(nums);
        int ans = -1;
        if(target >= nums[0] && target <= nums[pivotindex]){
            cout << "Calling first binary search" << endl;
            ans = binarySearch(0, pivotindex, nums, target);

        }
        else{
            ans = binarySearch(pivotindex + 1, nums.size() - 1, nums, target);
            cout << ans;
        }
        return ans;
    }
};