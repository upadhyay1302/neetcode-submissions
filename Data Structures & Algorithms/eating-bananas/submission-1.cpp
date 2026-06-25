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
    int solveBS(vector<int>& nums, int h){
        int start = 1;
        int end =  *max_element(nums.begin(), nums.end());
        int ans = end;

        while(start <= end){
            int mid = start + (end - start)/2;
            int totalTime = 0;
            for(int i = 0; i < nums.size(); i++){
                int currAmount = nums[i];
                while(currAmount > 0){
                    currAmount = currAmount - mid;
                    totalTime = totalTime + 1;
                }
            }
            if(totalTime <= h){
                ans = mid;
                end = mid - 1;
            }
            else start = mid + 1;
        }
        return ans;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int currspeed = 1;
        // int ans = solve(piles,h, currspeed);
        int ans = solveBS(piles, h);
        return ans;
    }
};
