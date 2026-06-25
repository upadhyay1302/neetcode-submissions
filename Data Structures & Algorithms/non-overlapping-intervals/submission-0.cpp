class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());

        int ans = 0;
        int prevEnd = intervals[0][1];

        for(int i =1; i < intervals.size(); i++){
            vector<int> curr= intervals[i];
            if(curr[0] >= prevEnd){
                prevEnd = curr[1];
            }
            else{
                ans++;
                prevEnd = min(prevEnd, curr[1]);
            }
        }
        return ans;
    }
};
