class Solution {
public:
    int solve(int i, int total, int target, int stoneSum, vector<int>& stones, vector<vector<int>>&DP){
        if(i == stones.size() || total >= target){
            return abs(total - (stoneSum - total));
        }

        if(DP[total][i] != -1) return DP[total][i];

        int include = solve(i + 1, total + stones[i], target, stoneSum, stones, DP);
        int exlcude = solve(i + 1, total, target, stoneSum, stones, DP);


        DP[total][i] = min(include, exlcude);
        return DP[total][i];
    }
    int lastStoneWeightII(vector<int>& stones) {
        int stoneSum = 0;
        for(int stone : stones){
            stoneSum += stone;
        }
        int target = (stoneSum + 1)/2;
        vector<vector<int>>DP(stoneSum + 1, vector<int>(stones.size() + 1, -1));
        return solve(0, 0, target, stoneSum, stones, DP);
    }
};

// if S1 and S2 are any two subsets
// S1 - S2 = ans
// S1 + S2 = S(total sum of array)
// so S1 = S - S2
// S - S2 - S2 = ans
// S -2S2 = ans
// ideally if S2 = S/2 then ans = 0, otherwise we want to go as close to S/2 as possible
// stones array
// target = S/2
// rerurn 2*total - stonesum