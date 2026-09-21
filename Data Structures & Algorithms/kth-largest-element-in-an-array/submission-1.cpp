class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> maxHeap;

        for(int num : nums){
            maxHeap.push(num);
        }

        int element;
        for(int i = 0; i < k; i++){
             element = maxHeap.top();
            maxHeap.pop();
        }
        return element;
    }
};
// sort the nums and then extract the kth largest would be direct index access
// [4,2,3,1] sort [4,3,2,1] k = 2 return arr[k - 1]; nlogn O(1)

// maxHeap and store all element of the nums into it, 

