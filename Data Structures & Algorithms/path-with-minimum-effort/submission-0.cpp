
class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {

        int totalRows = heights.size();
        int totalCols = heights[0].size();

        vector<vector<int>> distance(totalRows,
                            vector<int>(totalCols, INT_MAX));

        distance[0][0] = 0;

        priority_queue<pair<pair<int,int>,int>,
                       vector<pair<pair<int,int>,int>>,
                       greater<pair<pair<int,int>,int>>> pq;

        pq.push({{0,0}, 0});

        while(!pq.empty()){

            int sourceRow = pq.top().first.first;
            int sourceCol = pq.top().first.second;

            int diff = pq.top().second;

            pq.pop();

            if(diff > distance[sourceRow][sourceCol]) continue;

            if(sourceRow == totalRows - 1 &&
               sourceCol == totalCols - 1) {
                return diff;
            }

            for(int i = -1; i <= 1; i++){
                for(int j = -1; j <= 1; j++){

                    if(abs(i) != abs(j)){

                        int currRow = sourceRow + i;
                        int currCol = sourceCol + j;

                        if(currRow >= 0 && currRow < totalRows &&
                           currCol >= 0 && currCol < totalCols){

                            int newDiff = max(diff,
                                abs(heights[currRow][currCol] -
                                    heights[sourceRow][sourceCol]));

                            if(newDiff < distance[currRow][currCol]){

                                distance[currRow][currCol] = newDiff;

                                pq.push({{currRow, currCol}, newDiff});
                            }
                        }
                    }
                }
            }
        }

        return 0;
    }
};
