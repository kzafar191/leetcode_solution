// Last updated: 5/6/2026, 5:10:26 pm
class Solution {
public:
	int maximalRectangle(vector<vector<char>>& matrix) {
		if(matrix.empty() || matrix[0].empty()) return 0;
		int rows = matrix.size(), cols = matrix[0].size();
		vector<int> height(cols, 0);
		int maxArea = 0;
		for(int r = 0; r < rows; ++r) {
			for(int c = 0; c < cols; ++c) {
				height[c] = (matrix[r][c] == '1') ? height[c] + 1 : 0;
			}
			maxArea = max(maxArea, largestRectangleArea(height));
		}
		return maxArea;
	}

private:
	int largestRectangleArea(vector<int>& heights) {
		stack<int> st;
        heights.push_back(0);
        int maxarea=0;
        for(int i=0;i<heights.size();++i){
            while(!st.empty()&& heights[st.top()]>heights[i]){
                int h=heights[st.top()];
                st.pop();
                int w = st.empty()?i:i-st.top()-1;
				maxarea = max(maxarea, h*w);
            }
            st.push(i);
        }
        heights.pop_back();
        return maxarea;
	}
};