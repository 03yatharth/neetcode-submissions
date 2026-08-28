class Solution {
public:
    vector<int> dp;
    int jump(vector<int>& nums) {
        int n=nums.size();
        dp.resize(n+1,0);
        for(int ind=n-2;ind>=0;ind--){
            int ans = 1e9;
            for(int i=1;i<=nums[ind];i++){
                int x = ind+i;
                int next=1e9;
                if(x<n)next = dp[x];
                ans = min(ans,next+1);
            }
            dp[ind] = ans;
        }
        return dp[0];
    }
};