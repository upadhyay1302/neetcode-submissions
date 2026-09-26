class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {

        if(hand.size() % groupSize != 0) return false;
        sort(hand.begin(), hand.end());

        unordered_map<int, int> mp;

        for(int n : hand){
            mp[n] ++;
        }

        int currSize = 0;

        for(int i = 0; i < hand.size(); i++){
            int currHand = hand[i];
            if(mp[currHand] > 0){
                for(int j = currHand; j < currHand + groupSize; j++){
                    if(mp[j] == 0) return false;
                    mp[j]--;
                }
            }
        }
        return true;
    }
};

/**

hand = [1,2,4,2,3,5,3,4], groupSize = 4

hand = [1,2,2,3,3,4,4,5]


**/