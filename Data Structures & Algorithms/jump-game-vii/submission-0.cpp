class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        int n=s.length(),count=0;
        vector<bool> t(n,0); 
        t[0]=1;

        for(int i=0;i<n;i++){
            if(i-minJump>=0)count+=t[i-minJump];
            if(i-maxJump-1>=0)count-=t[i-maxJump-1];
            if(count>0 && s[i]=='0')t[i]=true;
        }
        return t[n-1];
    }
};