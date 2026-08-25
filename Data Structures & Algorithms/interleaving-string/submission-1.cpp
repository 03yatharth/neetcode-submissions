class Solution {
public:
    vector<vector<vector<int>>> dp;
    bool solve(int i,int j,int k,string &s1, string &s2, string &s3){
        int n1=s1.length(),n2=s2.length(),n3=s3.length();
        if(i==n1 && j==n2 && k==n3)return true;
        if(dp[i][j][k]!=-1)return dp[i][j][k];
        bool flag = false;
        if(i<n1 && k<n3 && s1[i]==s3[k])flag |= solve(i+1,j,k+1,s1,s2,s3);
        if(j<n2 && k<n3 && s2[j]==s3[k])flag |= solve(i,j+1,k+1,s1,s2,s3);
        return dp[i][j][k] = flag;
    }
    bool isInterleave(string s1, string s2, string s3) {
        int n1=s1.length(),n2=s2.length(),n3=s3.length();
        dp.resize(n1+1,vector<vector<int>> (n2+1,vector<int> (n3+1,-1)));
        return solve(0,0,0,s1,s2,s3);
    }
};