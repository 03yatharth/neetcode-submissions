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
        dp.resize(n,vector<int>(m,-1));
        return solve(0,0,word1,word2);
    }
};