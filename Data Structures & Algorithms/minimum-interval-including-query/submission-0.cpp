class Solution {
public:
    bool canFind(int curr, int start, int end){
        for(int i = start; i <= end; i++){
            if(curr == i) return true;
        }
        return false;
    }
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
        vector<int> ans;
        for(int i = 0; i < queries.size(); i++){
            int curr = queries[i];
            int size = INT_MAX;
            for(int j = 0; j < intervals.size(); j++){
                if (intervals[j][0] <= curr && curr <= intervals[j][1]){
                    size = min(size, intervals[j][1] - intervals[j][0] + 1);
                }
            }
            if(size != INT_MAX)
            ans.push_back(size);
            else ans.push_back(-1);
        }
        return ans;
    }
};
