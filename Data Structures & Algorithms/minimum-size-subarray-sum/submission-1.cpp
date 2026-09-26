class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int finalLength = INT_MAX;

        int i = 0;
        int j = 0;
        int currSum = 0;
        while(j < nums.size()){
            currSum += nums[j];

            while(currSum >= target){
                finalLength = min(finalLength, j - i + 1);
                currSum = currSum - nums[i];
                i++;
            }
            j++;
        }
        if(finalLength == INT_MAX) return 0;
        return finalLength;
    }
};
/**
    1,5,1,5 target = 10
      i
          j
currSum = 11
finalLength = 3 - 0 + 1 = 4, 3 - 1 + 1 = 3


**/
/**
notes
nums , target

minimize the length and subaary sum >= target

target = 10, nums = [2,1,5,1,5,3]

// brute force - finding all subarrys using 2 for loops and then we calculate sum of each subaary and if sum>= target we find its length and then we try to miizize this length 
int finalLength = INT_MAX

finalLength = min(finalLength, length of the subaary j - i + 1)

O(n^2) cause of 2 for loops


// better 
// sliding window algo, but we dont know the sizd of the sliding window => dynamic sliding window



**/