class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
         vector<vector<int>> ans;

        sort(intervals.begin(), intervals.end());

        ans.push_back(intervals[0]);

        for(int i = 1; i < intervals.size(); i++){
            vector<int>& prev = ans.back();
            vector<int>& curr = intervals[i];

            if(prev[1] >= curr[0]){
                prev[0] = min(prev[0], curr[0]);
                prev[1] = max(prev[1], curr[1]); 
            }
            else{
                ans.push_back(curr);
            }
        }
        return ans;
    }
};
