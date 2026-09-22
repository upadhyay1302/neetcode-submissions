class Solution {
public:
    bool checkValidString(string s) {
        int leftMin = 0;
        int leftMax = 0;
        for(char c : s){
            if(c == '('){
                leftMin++;
                leftMax++;
            }
            else if(c == ')'){
                leftMin--;
                leftMax--;
            }
            else{
                leftMin--;
                leftMax++;
            }

            if(leftMax < 0) return false;

            if(leftMin < 0) leftMin = 0;
        }
        if(leftMin == 0) return true;
        else return false;
    }
};

// leftMin= min number of unmatched ( after processing rhe characters of s so far
// leftMax = max number of unmatched ( after processing rhe characters of s so far
