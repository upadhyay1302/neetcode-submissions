class Solution {
public:
    bool solve(vector<vector<int>>& matrix, int target){
        int rowCount = matrix.size();
        int colCount = matrix[0].size();
        int total = rowCount * colCount;
        int start = 0;
        int end = total - 1;
        while(start <= end){
            int mid = start + (end - start)/2;
        
            int rowIndex = mid/colCount;
            int colIndex = mid%colCount;

            cout << mid <<',' << matrix[rowIndex][colIndex] << endl;

            if(matrix[rowIndex][colIndex] == target){
                return true;
            }
            else if(matrix[rowIndex][colIndex] > target){
                end = mid - 1;
            }
            else start = mid + 1;
        }
        return false;
        
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
       bool ans = solve(matrix, target);
       return ans; 
    }
};
