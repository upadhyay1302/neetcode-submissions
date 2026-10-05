class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        double totalTime = 0;

        double firstCustomerArrivalTime = customers[0][0];

        for(int i = 0; i < customers.size(); i++){
            int currArrival = customers[i][0];
            int timeToCook = customers[i][1];

            cout << firstCustomerArrivalTime << endl;

            if(firstCustomerArrivalTime <= currArrival){

                cout << firstCustomerArrivalTime << '<' << currArrival << endl;
                
                totalTime = totalTime + timeToCook;
                firstCustomerArrivalTime = currArrival + timeToCook;
            }

            else {
                firstCustomerArrivalTime = firstCustomerArrivalTime + timeToCook;
                totalTime = totalTime + firstCustomerArrivalTime - currArrival;
            }

        }
        return totalTime/customers.size();
    }
};


/**

customers=[[2,3],[6,3],[7,5],[11,3],[15,2],[18,1]]

firstCustomerArrivalTime = 9 + 5 = 14 + 3 = 17 + 2 = 19 + 1 = 20

totalTime = 3 + 3 + 7 + 6 + 4 + 2


**/