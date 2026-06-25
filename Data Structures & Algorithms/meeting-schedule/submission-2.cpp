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
        for(int i =0; i < intervals.size(); i++){
            int s1 = intervals[i].start;
            int e1 = intervals[i].end -1 ;

            for(int j = i+1; j < intervals.size();j++){
                int s2 = intervals[j].start;
                int e2 = intervals[j].end -1 ;

                if(e1 >= s2 && e2 >= s1){
                    ans = false;
                    break;
                }
            }
        }

        return ans;
    }
};
