class Solution {
public:
    double myPow(double x, int n) {
        long long N=n;
        if(N<0){
            x = 1.0/x;
            N=-N;
        }
        if(N==0)return 1;
        if(N==1)return x;
        double half = myPow(x,N/2);
        if(N%2) return half*half*x;
        return half*half;
    }
};