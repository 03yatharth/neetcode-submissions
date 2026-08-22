class Solution {
public:
    vector<int> dp;
    int solve(int n){
        if(dp[n]!=-1)return dp[n];
        if(n==1)return dp[n] = 1;
        if(n==2)return dp[n] = 1;
        if(n==3)return dp[n] = 2;
        if(n==4)return dp[n] = 4;
        int maxi = 0;
        for(int i=1;i<n;i++){
            int left = solve(i);
            int right = solve(n-i);
            maxi = max(maxi,left*right);
            maxi = max(maxi,i*right);
            maxi = max(maxi,left*(n-i));
            maxi = max(maxi,i*(n-i));
        }
        return  dp[n] = maxi;
    }
    int integerBreak(int n) {
        dp.resize(n+1,-1);
        return solve(n);
    }
};