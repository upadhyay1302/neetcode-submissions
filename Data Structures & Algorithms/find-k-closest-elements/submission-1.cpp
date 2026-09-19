class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        vector<int> ans;
        // vector<pair<int, int>> temp;
        priority_queue<pair<int, int>> heap;

        for(int num : arr){
            int diff = abs(num - x);
            heap.push({diff, num});
            if(heap.size() > k){
                heap.pop();
            }
        }

        // sort(temp.begin(), temp.end());

        for(int i = 0; i < k; i++){
            ans.push_back(heap.top().second);
            heap.pop();
        }

        sort(ans.begin(), ans.end());
        return ans;
    }
};


// arr , k, x
// k closest integers to x in the arry 
// results vec sorted in ascending order
// iterate through the arr and then for each element i will do abs(arr[i]-x) and then i store this in a different array and sort that and then return the first k elements from the array


// smallest 'k' differences just storing all the <differences,element> into a minHeap, and then we keeping doing minHeap.top() and minHeap.pop() -> O(nlogn) time

// maxHeap, and make sure that we only have k elements in it


