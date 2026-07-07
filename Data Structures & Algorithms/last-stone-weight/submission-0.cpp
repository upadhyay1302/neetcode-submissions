class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        while(stones.size() > 1){
            sort(stones.begin(), stones.end());

            int last = stones[stones.size()-1];
            stones.erase(stones.begin() + (stones.size()-1));
            int secondLast = stones[stones.size()-1];
            stones.erase(stones.begin() + (stones.size()-1));

            if(last > secondLast){
                stones.push_back(last - secondLast);
            }
        }
        if(stones.size() == 1) return stones[0];
        return 0;
    }
};
