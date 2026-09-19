class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        vector<int> ans;
        vector<pair<int, int>> temp;
        for(int num : arr){
            int diff = abs(num - x);
            temp.push_back({diff, num});
        }

        sort(temp.begin(), temp.end());

        for(int i = 0; i < k; i++){
            ans.push_back(temp[i].second);
        }

        sort(ans.begin(), ans.end());
        return ans;
    }
};


// arr , k, x
// k closest integers to x in the arry 
// results vec sorted in ascending order
// iterate through the arr and then for each element i will do abs(arr[i]-x) and then i store this in a different array and sort that and then return the first k elements from the array
