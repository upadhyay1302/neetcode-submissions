class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int five = 0;
        int ten = 0;
        int twenty = 0;

        for(int i = 0; i < bills.size(); i++){
            int currBill = bills[i];

            if(currBill == 5) five++;
            else if(currBill == 10){
                if(five == 0){
                    return false;
                }
                five--;
                ten++;
            }
            else{//20;
                if(five >=3){
                    five = five - 3;
                }
                else if((ten >= 1 && five >= 1)){
                    ten--;
                    five--;
                }
                else return false;
                twenty++;
            }
        }
        return true;
        
    }
};