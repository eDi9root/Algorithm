class Solution {
public:
    double myPow(double x, int n) {
        double res=1.0;
        int y=abs(n);
        while(y>0){
            if(y%2!=0){
                res*=x;
            }
            x*=x;
            y=y/2;
            
        }
        if(n<0)return 1/res;

        return res;
    }
};