class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n=text1.length(),m=text2.length();
        vector<int> prev (m+1,0);

        for(int i=1;i<=n;i++){
            vector<int> cur = prev;
            for(int j=1;j<=m;j++){
                if(text1[i-1] == text2[j-1]){
                    cur[j] = 1 + prev[j-1];
                    continue ; 
                }
                int best = 0;
                best = max(best,prev[j]);
                best = max(best,cur[j-1]);
                cur[j] = best;
            }
            prev = cur;
        }
        return prev[m];
    }
};