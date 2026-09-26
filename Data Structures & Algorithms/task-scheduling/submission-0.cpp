class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int>mp(26, 0);

        for(char ch : tasks){
            mp[ch - 'A']++;
        }

        int time = 0;

        priority_queue<int> maxHeap;

        for(int p: mp){
            if(p > 0)
            maxHeap.push(p);
        }

        while(!maxHeap.empty()){
            vector<int> temp;

            for(int i = 1; i <= n + 1; i++){
                if(!maxHeap.empty()){
                    int freq = maxHeap.top();
                    maxHeap.pop();
                    freq--;
                    temp.push_back(freq);
                }
            }

            for(int f : temp){
                if(f > 0){
                    maxHeap.push(f);
                }
            }

            if(maxHeap.empty()) time += temp.size();
            else time += n + 1;
        }

        return time;
    }
};
