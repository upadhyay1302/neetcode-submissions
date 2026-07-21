class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq;
        for(int i = 0; i < stones.size(); i++){
            pq.push(stones[i]);
        }

        while(pq.size() > 1){
            int last = pq.top();
            pq.pop();
            int secondLast = pq.top();
            pq.pop();
            cout << last << " " << secondLast << endl;
            if(last > secondLast){
                pq.push(last - secondLast);
            }
        }
        if(pq.size() == 1) return pq.top();
        return 0;
        
    }
};
