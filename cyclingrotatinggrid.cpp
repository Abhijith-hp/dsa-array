class Solution {
public:
    vector<vector<int>> rotateGrid(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();

        int layers = min(m,n)/2;

        for(int layer=0;layer<layers;layer++){
            vector<int>nums;

            int top = layer;
            int bottom = m-layer-1;
            int left = layer;
            int right = n-layer-1;

            for(int j=left;j<=right;j++){
                nums.push_back(grid[top][j]);
            }

            for(int j=top+1;j<=bottom-1;j++){
                nums.push_back(grid[j][right]);
            }

            for(int i=right;i>=left;i--){
                nums.push_back(grid[bottom][i]);
            }

            for(int i=bottom-1;i>=top+1;i--){
                nums.push_back(grid[i][left]);
            }
            
            int len = nums.size();
            int normalized = k%len;
            rotate(begin(nums),begin(nums)+normalized,end(nums));
            int index = 0;

              for (int j = left; j <= right; j++) {
                grid[top][j] = nums[index++];
            }

            for (int i = top + 1; i <= bottom - 1; i++) {
                grid[i][right] = nums[index++];
            }

            for (int j = right; j >= left; j--) {
                grid[bottom][j] = nums[index++];
            }

            for (int i = bottom - 1; i >= top + 1; i--) {
                grid[i][left] = nums[index++];
            }


        }
    return grid;
    }
};