class Solution {
public:
    int solve(int ind,string &s,vector<vector<string>> &mp,vector<int> &dp){
        if(ind>=s.length())return 0;
        if(dp[ind]!=-1)return dp[ind];
        char ch = s[ind];
        int best=0;
        for(auto &str:mp[ch-'a']){
            int n=str.length();
            if(ind+n>s.length())continue;
            if(s.compare(ind,n,str)==0){
                best = max(best,solve(ind+n,s,mp,dp)+n);
            }
        }
        best = max(best,solve(ind+1,s,mp,dp));
        return dp[ind] = best;
    }
    int minExtraChar(string s, vector<string>& dictionary) {
        vector<vector<string>> strs(26);
        int n=s.length();
        vector<int> dp(n,-1);
        for(auto str : dictionary){
            strs[str[0]-'a'].push_back(str);
        }
        return n - solve(0,s,strs,dp);
    }
};