class Solution {
public:
    int numDistinct(string s, string t) {
        int n=s.length(),m=t.length();
        vector<long long> cur(m+1,0);
        cur[m]=1;
        for(int i=n-1;i>=0;i--){
            for(int j=0;j<m;j++){
                if(s[i]==t[j])cur[j]+=cur[j+1];
                if(cur[j]>1e9)cur[j]=1e9;
            }
        }
        return cur[0];
    }
};