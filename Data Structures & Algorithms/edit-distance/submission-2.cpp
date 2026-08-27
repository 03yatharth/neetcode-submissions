class Solution {
public:
    vector<vector<int>> dp;
    int solve(int i,int j,string &word1, string &word2){
        int n=word1.length(),m=word2.length();
        if(j==m)return n-i;
        if(i==n)return m-j;
        if(dp[i][j]!=-1)return dp[i][j];
        int ans = 1e9;
        if(word1[i]==word2[j])
        ans = min(ans,solve(i+1,j+1,word1,word2));
        else{
            ans = min(ans,solve(i,j+1,word1,word2)+1);    //insert
            ans = min(ans,solve(i+1,j,word1,word2)+1);      //delete
            ans = min(ans,solve(i+1,j+1,word1,word2)+1);    //replace
        }
        return dp[i][j] = ans;
    }
    int minDistance(string word1, string word2) {
        int n=word1.length(),m=word2.length();
        dp.resize(n+1,vector<int>(m+1,0));
        dp.resize(n+1,vector<int>(m+1,0));
        for(int i=0;i<=n;i++){
            dp[i][m]=n-i;
        }
        for(int j=0;j<=m;j++){
            dp[n][j]=m-j;
        }
        for(int i=n-1;i>=0;i--){
            for(int j=m-1;j>=0;j--){
                int ans = 1e9;
                if(word1[i]==word2[j])
                ans = min(ans,dp[i+1][j+1]);
                else{
                    ans = min(ans,1+dp[i][j+1]);
                    ans = min(ans,1+dp[i+1][j]);
                    ans = min(ans,1+dp[i+1][j+1]);
                }
                dp[i][j] = ans;
            }
        }
        return dp[0][0];
    }
};