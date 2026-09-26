class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int finalLength = INT_MAX;

        for(int i = 0; i < nums.size(); i++){
            int currSum = 0;
            for(int j = i; j < nums.size(); j++){
                currSum += nums[j];
                if(currSum >= target){
                    finalLength = min(finalLength, j - i + 1);
                }
            }
        }
        if(finalLength == INT_MAX) return 0;
        return finalLength;
    }
};


/**
notes
nums , target

minimize the length and subaary sum >= target

target = 10, nums = [2,1,5,1,5,3]

// brute force - finding all subarrys using 2 for loops and then we calculate sum of each subaary and if sum>= target we find its length and then we try to miizize this length 
int finalLength = INT_MAX

finalLength = min(finalLength, length of the subaary j - i + 1)

**/