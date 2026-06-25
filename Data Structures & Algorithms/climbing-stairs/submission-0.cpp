class Solution {
public:
    int solve(int n){
        if(n == 0) return 1;
        if(n < 0) return 0;

        int count = 0;
        for(int i = 1; i <= 2; i++){
            count = count + solve(n - i);
        }

        return count;


        

    }
    int climbStairs(int n) {
        return solve(n);
        
    }
};
