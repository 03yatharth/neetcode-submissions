class Solution {
public:
    bool checkValidString(string s) {
        int l=0,r=0;
        for(auto &i:s){
            if(i=='('){
                l++;
                r++;
            }
            else if(i==')'){
                l--;
                r--;
                if(r<0)return false;
            }
            else{
                l--;
                r++;
            }
            l=max(l,0);
        }
        if(r<0 || l!=0)return false;
        return true;
    }
};
