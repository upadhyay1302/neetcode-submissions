class Solution {
public:
    void removeFromMaxHeap(priority_queue<int>& maxHeap, int elemToRemove){
        vector<int>temp;

        while(!maxHeap.empty()){
            int topElem = maxHeap.top();
            maxHeap.pop();

            if(topElem == elemToRemove){
                break;
            }
            else{
                temp.push_back(topElem);
            }
        }

        for(auto insertElem : temp){
            maxHeap.push(insertElem);
        }
    }
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        priority_queue<pair<int,int>> maxHeap;

        vector<int> ans;

        for(int i = 0; i < k; i++){
            maxHeap.push({nums[i],i});
        }

        ans.push_back(maxHeap.top().first);


        for(int i = k; i < nums.size(); i++) {

            maxHeap.push({nums[i], i});

            while(!maxHeap.empty() && maxHeap.top().second <= i - k) {
                maxHeap.pop();
            }

            ans.push_back(maxHeap.top().first);
        }



        return ans;
    }
};
