class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        long long ans = 0;

        priority_queue<int> heap;

        for(int num : gifts){
            heap.push(num);
        }

        while(k != 0){
            int max = heap.top();
            heap.pop();
            heap.push(sqrt(max));
            k--;
        }

        while(!heap.empty()){
            ans = ans + heap.top();
            heap.pop();
        }
        return ans;
    }
};