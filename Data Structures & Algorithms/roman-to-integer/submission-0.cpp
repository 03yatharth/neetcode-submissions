class Solution {
public:
    int romanToInt(string s) {
        vector<int> mp(26,0);
        mp['I'-'A']=1;
        mp['V'-'A']=5;
        mp['X'-'A']=10;
        mp['L'-'A']=50;
        mp['C'-'A']=100;
        mp['D'-'A']=500;
        mp['M'-'A']=1000;
        
        int ans=0,n=s.length();
        for(int i=0;i<n;i++){
            int cur = mp[s[i]-'A'];
            if(i+1<n && cur < mp[s[i+1]-'A'])ans-=cur;
            else ans += cur;
        }
        return ans;
    }
};