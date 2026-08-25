class Solution {
public:
    vector<vector<int>> dp;
    int solve(int ind,int amount, vector<int>& coins){
        if(amount==0)return 1;
        if(amount<0 || ind>=coins.size())return 0;
        if(dp[ind][amount]!=-1)return dp[ind][amount];
        int ans = 0;
        ans += solve(ind+1,amount,coins);
        ans += solve(ind,amount-coins[ind],coins);
        return dp[ind][amount] = ans;
    }
    int change(int amount, vector<int>& coins) {
        dp.resize(coins.size(),vector<int>(amount+1,-1));
        return solve(0,amount,coins);
    }
};