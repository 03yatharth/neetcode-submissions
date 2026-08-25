class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<uint>> dp(n+1,vector<uint>(amount+1,0));
        sort(coins.begin(), coins.end());

        for(int i=0;i<=n;i++)dp[i][0]=1;
        for(int ind=n-1;ind>=0;ind--){
            for(int a=0;a<=amount;a++){
                if(a>=coins[ind]){
                    dp[ind][a] = dp[ind+1][a];
                    dp[ind][a] += dp[ind][a-coins[ind]];
                }
            }
        }
        return dp[0][amount];
    }
};