class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        int x=target[0],y=target[1],z=target[2];
        int a=0,b=0,c=0;
        for(auto &t:triplets){
            int i=t[0],j=t[1],k=t[2];
            if(i<=x && j<=y && k<=z){
                a=max(a,i);b=max(b,j);c=max(c,k);
            }
            if(a==x && b==y && c==z)return true;
        }
        return false;
    }
};