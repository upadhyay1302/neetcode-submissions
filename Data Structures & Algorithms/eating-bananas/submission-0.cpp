class Solution {
public:
    int solve(vector<int>& nums, int h, int currspeed){
        int totalTime = 0;
        for(int i = 0; i < nums.size(); i++){
            int currAmount = nums[i];

            while(currAmount > 0){
                currAmount = currAmount - currspeed;
                totalTime = totalTime + 1;
            }
        }

        cout << totalTime << "," << currspeed << endl;
        if(totalTime <= h) return currspeed;
        else{
            return solve(nums, h, currspeed + 1);
        }
        // return currspeed;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int currspeed = 1;
        int ans = solve(piles,h, currspeed);
        return ans;
    }
};
