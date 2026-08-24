class Solution {
public:
    vector<vector<int>> dp;
    int ttl = 0;
    int solve(int ind,int cur,vector<int>& nums){
        int n = nums.size();
        int left = ttl - cur;
        if(dp[ind][cur]!=-1)return dp[ind][cur];
        if(ind==n)return abs(cur-left);
        int best = 1e9; 
        best = min(best,solve(ind+1,cur+nums[ind],nums));
        best = min(best,solve(ind+1,cur,nums));
        return dp[ind][cur] = best;
    }
    int lastStoneWeightII(vector<int>& stones) {
        int sum=0,n=stones.size();
        for(auto &i:stones)sum+=i;
        ttl = sum;
        dp.resize(n+1,vector<int>(ttl+1,-1));
        return solve(0,0,stones);
    }
};