class Solution {
public:
    int solve(int l, int r, vector<int>&piles, vector<vector<int>>&DP){
        if(l > r) return 0;

        if(DP[l][r] != -1) return DP[l][r];

        bool even = (r-l)%2 == 0;
        int left = even? piles[l] : 0;
        int right = even? piles[r] : 0;
        DP[l][r] = max(solve(l + 1, r, piles, DP) + left, solve(l, r - 1, piles, DP) + right);
        return DP[l][r];
    }
    bool stoneGame(vector<int>& piles) {
        int total = 0;
        for(int pile : piles){
            total += pile;
        }
        vector<vector<int>>DP(piles.size(), vector<int>(piles.size(), -1));

        int aliceScore = solve(0, piles.size() - 1, piles, DP);
        if(aliceScore > total - aliceScore) return true;
        else return false;
    }

};

// even num of piles
// piles[i]

// if(i < j) return the result of the game compare AliceStone and BobStones -> Basecase
// int alicefirst = solve(i + 1, ) + piles[i];
// int alicelast = solve(i, j + 1) + piles[j];
// do we need a state to see whose turn it is - i think yes
