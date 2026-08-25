class Solution {
public:
    int getProf(int ind,bool buy,vector<int>& prices,vector<vector<int>> &dp){
        int n=prices.size();
        if(ind>=n)return 0;
        if(dp[ind][buy]!=-1)return dp[ind][buy];
        int best=0;
        if(buy){
            best = max(best,getProf(ind+1,false,prices,dp)-prices[ind]);
            best = max(best,getProf(ind+1,true,prices,dp));
        }
        else {
            best = max(best,getProf(ind+2,true,prices,dp)+prices[ind]);
            best = max(best,getProf(ind+1,false,prices,dp));
        }
        return dp[ind][buy] = best;
    }
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>> dp(n,vector<int>(2,-1));
        return getProf(0,true,prices,dp);
    }
};