class Solution {
public:
    bool checkDivisibility(int n) {
        int c=n;
        int a=0;
        int b=1;
        while(n>0){
            a+=n%10;
            b*=n%10;
            n=n/10;
        }
        return (c%(a+b)==0);
    }
};