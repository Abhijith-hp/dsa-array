class Solution {
public:
    int helper(int i,int j,vector<vector<int>>& dungeon, vector<vector<int>>& dp){
        int m = dungeon.size();
        int n = dungeon[0].size();
     
        if(i >= m || j >= n) return INT_MAX;
        if(dp[i][j]!=-1) return dp[i][j];
        if(i==m-1 && j == n-1){
           if(dungeon[i][j]>0) return dp[i][j] = 1;
           else  return dp[i][j] = abs(dungeon[i][j]) +1;
        }
        int right = helper(i,j+1,dungeon,dp);
        int down = helper(i+1,j,dungeon,dp);
        int result = min(right,down) - dungeon[i][j];
        return dp[i][j] = (result <= 0) ? 1 : result;
    }
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int m = dungeon.size();
        int n = dungeon[0].size();
        vector<vector<int>> dp(m,vector<int>(n,-1));
        return helper(0,0,dungeon,dp);
      
    }
};