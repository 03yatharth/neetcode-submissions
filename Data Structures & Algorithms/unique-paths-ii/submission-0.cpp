class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n=obstacleGrid.size(),m=obstacleGrid[0].size();
        vector<vector<long long>> dp(n,vector<long long> (m,0));
        for(int i=0;i<n;i++){
            if(obstacleGrid[i][0]==1)break;
            dp[i][0]=1;
        }
        for(int i=0;i<m;i++){
            if(obstacleGrid[0][i]==1)break;
            dp[0][i]=1;
        }

        for(int i=1;i<n;i++){
            for(int j=1;j<m;j++){
                int top=0,left=0;
                if(obstacleGrid[i][j]==1)continue;
                if(i-1>=0)top=dp[i-1][j];
                if(j-1>=0)left=dp[i][j-1];
                dp[i][j] = top + left;
            }
        }
        return dp[n-1][m-1];
    }
};