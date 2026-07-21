class KthLargest {
public:
    priority_queue<int, vector<int>, greater<int>> pq;
    int remove;
    KthLargest(int k, vector<int>& nums) {
        for(int i = 0; i < nums.size(); i++){
            pq.push(nums[i]);
            if(pq.size() > k){
                pq.pop();
            }
        }
        remove = k;
    }
    
    int add(int val) {
        pq.push(val);
        if(pq.size() > remove){
            pq.pop();
        }
        return pq.top();
    }
};
