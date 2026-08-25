class Solution {
public:
    vector<vector<int>> dp;
    int tar = -1,off;
    int solve(int ind,vector<int>& nums,int sum){
        int n=nums.size();
        if(ind==n){
            if(sum==tar)return 1;
            return 0;
        }
        if(dp[ind][sum+off]!=-1)return dp[ind][sum+off];
        int ans = 0;
        ans += solve(ind+1,nums,sum+nums[ind]);
        ans += solve(ind+1,nums,sum-nums[ind]);
        return dp[ind][sum+off] = ans;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum=0;
        for(auto &i:nums)sum+=abs(i);
        dp.resize(nums.size(),vector<int>(2*sum+1,-1));
        tar = target;
        off = sum;
        return solve(0,nums,0);
    }
};