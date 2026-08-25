class Solution {
public:
    vector<vector<int>> dp;
    int solve(int i,int j,int prev,vector<vector<bool>>& vis,vector<vector<int>>& mat){
        int n=mat.size(),m=mat[0].size();
        if(i<0 || i>=n || j<0 || j>=m)return 0;
        if(vis[i][j] || mat[i][j]<=prev)return 0;
        if(dp[i][j]!=-1)return dp[i][j];
        vis[i][j]=true;

        int dx[4] = {0,0,1,-1};
        int dy[4] = {1,-1,0,0};
        int best = 0;
        for(int k=0;k<4;k++){
            int x = dx[k]+i;
            int y = dy[k]+j;
            best = max(
                best,
                solve(x,y,mat[i][j],vis,mat)+1
            );
        }
        vis[i][j]=false;
        return dp[i][j] = best;
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int n=matrix.size(),m=matrix[0].size();
        dp.resize(n,vector<int> (m,-1));
        vector<vector<int>> temp;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                temp.push_back({matrix[i][j],i,j});
            }
        }
        int ans= 0;
        sort(temp.begin(),temp.end());
        for(auto i:temp){
            vector<vector<bool>> vis(n,vector<bool> (m,false));
            ans = max(
                ans,
                solve(i[1],i[2],-1,vis,matrix)
            );
        }
        return ans;
    }
};