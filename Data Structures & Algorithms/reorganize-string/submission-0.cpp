class Solution {
public:
    string reorganizeString(string s) {
        unordered_map<char, int>mp;

        for(char ch : s){
            mp[ch]++;
        }

        priority_queue<pair<int, char>> pq;
        for(auto &p : mp){
            pq.push({p.second, p.first});
        }

        string res = "";

        while(!pq.empty()){
            int currCount = pq.top().first;
            char currCh = pq.top().second;
            pq.pop();

            if(res.length() > 0 && res.back() == currCh){
                if(pq.empty()) return "";
                int nextCount = pq.top().first;
                char nextCh = pq.top().second;
                pq.pop();

                res += nextCh;
                nextCount--;
                if(nextCount > 0){
                    pq.push({nextCount, nextCh});
                }
            }
            else{
                res += currCh;
                currCount--;
            }

            if(currCount > 0){
                    pq.push({currCount, currCh});
            }
        }
        return res;
    }
};