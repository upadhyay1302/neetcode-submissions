class Solution {
public:

    void nextSmallerElement(vector<int> &heights, vector<int> &nextAns){
        stack <int> s;

        s.push(-1);
        int n = heights.size();
        for(int i = n-1; i >= 0; i--){
            int element = heights[i];
            while(s.top() != -1 && heights[s.top()] >= element){
                s.pop();
            }
            nextAns.push_back(s.top());
            s.push(i);
        }
    }

    void prevSmallerElement(vector<int> &heights, vector<int> &prevAns){
        stack <int> s;

        s.push(-1);
        int n = heights.size();
        for(int i = 0; i < n ; i++){
            int element = heights[i];
            while(s.top() != -1 && heights[s.top()] >= element){
                s.pop();
            }
            prevAns.push_back(s.top());
            s.push(i);
        }
    }


    int largestRectangleArea(vector<int>& heights) {
        vector<int> prevAns;
        vector<int> nextAns;

        nextSmallerElement(heights, nextAns);
        reverse(nextAns.begin(), nextAns.end());
        prevSmallerElement(heights, prevAns);

        for(int i = 0; i < heights.size(); i++){
            if(nextAns[i] == -1){
                nextAns[i]= nextAns.size();
            }
        }
        cout << endl;
        for(int i = 0; i < heights.size(); i++){
            cout << prevAns[i] << " ";
        }

        int maxArea = 0;

        for(int i = 0; i < heights.size(); i++){
            int widht = nextAns[i] - prevAns[i] - 1;
            int currArea = heights[i] * widht;
            maxArea = max(maxArea, currArea);
        }


        return maxArea;

    }
};