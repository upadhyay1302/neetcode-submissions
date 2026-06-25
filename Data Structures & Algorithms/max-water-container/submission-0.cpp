class Solution {
public:
    int maxArea(vector<int>& heights) {
        int start = 0;
        int end = heights.size()-1;
        int maxArea = 0;
        while(start < end){
            int currArea = (end - start) * min(heights[start], heights[end]);
            maxArea = max(currArea, maxArea);
            if(heights[start] < heights[end]) start++;
            else end--;
        }
        return maxArea;
    }
};
