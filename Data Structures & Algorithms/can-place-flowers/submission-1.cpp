class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        for(int i = 0; i < flowerbed.size(); i++){
            if(flowerbed[i] == 0){

                bool leftEmpty = false;
                bool rightEmpty = false;

                if(i == 0) leftEmpty = true;
                else if(flowerbed[i - 1] == 0) leftEmpty = true;

                if(i == flowerbed.size() - 1) rightEmpty =true;
                else if(flowerbed[i + 1] == 0) rightEmpty = true;

                if(rightEmpty && leftEmpty){
                    cout << i << endl;
                    flowerbed[i] = 1;
                    n--;
                }
            }
        }
        if(n <= 0) return true;
        else return false;
    }
};