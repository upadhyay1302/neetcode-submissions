class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        
        int n = gas.size();

        int totalGas = accumulate(begin(gas), end(gas), 0);
        int totalCost = accumulate(begin(cost), end(cost), 0);

        if(totalCost > totalGas) return -1;

        int total = 0;
        int res_index = 0;

        for(int i = 0; i < gas.size(); i++){
            total += gas[i] - cost[i];
            if(total < 0){
                total = 0;
                res_index = i + 1;
            }
        }
        return res_index;

    }
};
