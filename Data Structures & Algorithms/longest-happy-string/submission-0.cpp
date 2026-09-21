class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        priority_queue<pair<int, char>> pq;

        if(a > 0) pq.push({a, 'a'});
        if(b > 0) pq.push({b, 'b'});
        if(c > 0) pq.push({c, 'c'});

        string res = "";
        while(!pq.empty()){
            int currCount = pq.top().first;
            int currChar = pq.top().second;
            pq.pop();
            
            if(res.length() >= 2 && res[res.length() - 1] == currChar && res[res.length() - 2] == currChar){
                if(pq.empty()) break;

                int nextCount = pq.top().first;
                int nextChar = pq.top().second;
                pq.pop();

                res += nextChar;

                nextCount--;

                if(nextCount > 0)
                pq.push({nextCount, nextChar});
                
            }
            else{
                res += currChar;
                currCount--;
            }
            if(currCount > 0)
            pq.push({currCount, currChar});
        }
        return res;

    }
};