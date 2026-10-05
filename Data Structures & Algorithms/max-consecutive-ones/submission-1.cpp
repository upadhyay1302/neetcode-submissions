class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int ans = 0;
        int count = 0;

        for(int num : nums){
            if(num == 0){
                ans = max(count, ans);
                count = 0;
            }
            else{
                count++;
            }
        }
        ans = max(ans, count);
        return ans;
    }
};