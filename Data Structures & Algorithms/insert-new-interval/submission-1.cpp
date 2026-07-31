class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int i = 0;
        vector<vector<int>> ans;

        while(i < intervals.size() && newInterval[0] > intervals[i][1]){
            ans.push_back(intervals[i]);
            i++;
        }
        // newInterval[0] - s1
        // newInterval[1] - e1
        // intervals[i][0] - s2
        // intervals[i][1] - e2
        // e2 >= s1 && e1 >= s2
        // intervals[i][1] >= newInterval[0] && newInterval[1] >= intervals[i][0]
        while(i < intervals.size() && (intervals[i][1] >= newInterval[0] && newInterval[1] >= intervals[i][0])){
            newInterval[0] = min(newInterval[0],intervals[i][0] );
            newInterval[1] = max(newInterval[1],intervals[i][1] );
            i++;
        }

        ans.push_back(newInterval);

        while(i < intervals.size()){
            ans.push_back(intervals[i]);
            i++;
        }
        return ans;
    }
};
