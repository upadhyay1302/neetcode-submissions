class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, std::vector<int>, std::greater<int>> minHeap;

        for(int num : nums){
            minHeap.push(num);
            if(minHeap.size() > k){
                minHeap.pop();
            }
        }
        return minHeap.top();
    }
};
// sort the nums and then extract the kth largest would be direct index access
// [4,2,3,1] sort [4,3,2,1] k = 2 return arr[k - 1]; nlogn O(1)

// maxHeap and store all element of the nums into it, 

//minHeap of size 

