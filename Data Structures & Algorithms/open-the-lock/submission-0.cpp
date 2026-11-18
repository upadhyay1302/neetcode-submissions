class Solution {
   public:
    vector<string> findNeighbours(string lock) {
        vector<string> res;

        for (int i = 0; i < 4; i++) {
            string next = lock;

            char currCh = lock[i];

            // Increment
            if (currCh == '9')
                next[i] = '0';
            else
                next[i] = currCh + 1;

            res.push_back(next);

            // Decrement
            next = lock;

            if (currCh == '0')
                next[i] = '9';
            else
                next[i] = currCh - 1;

            res.push_back(next);
        }

        return res;
    }
    int openLock(vector<string>& deadends, string target) {
        unordered_set<string> visited(deadends.begin(), deadends.end());

        string start = "0000";

        if (visited.find(start) != visited.end()) return -1;

        queue<pair<string, int>> q;
        q.push({start, 0});

        while (!q.empty()) {
            pair<string, int> p = q.front();
            q.pop();

            string lock = p.first;
            int turns = p.second;

            if (lock == target) return turns;

            for (auto& neighbhours : findNeighbours(lock)) {
                if (visited.find(neighbhours) == visited.end()) {
                    visited.insert(neighbhours);
                    q.push({neighbhours, turns + 1});
                }
            }
        }
        return -1;
    }
};

/**

5 5 5 5

**/