/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    bool canAttendMeetings(vector<Interval>& intervals) {
        bool ans = true;

        // e1 >= s2 && e2 >= s1
        sort(intervals.begin(), intervals.end(),
        [](const Interval& a, const Interval& b) {
            return a.start < b.start;
        });
        
        for(int i = 1; i < intervals.size(); i++){
            int s2 = intervals[i].start;
            int e1 = intervals[i-1].end - 1;

            if(e1 >= s2) ans = false;
        }

        return ans;
    }
};
