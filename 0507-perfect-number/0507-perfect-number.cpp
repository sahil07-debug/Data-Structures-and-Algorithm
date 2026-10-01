class Solution {
public:
    bool checkPerfectNumber(int num) {
        if (num==1)return false;
        int x=1;
        for(int i=2;i<=sqrt(num);i++){
            if(num%i==0){
                x+=i;
                if(i!=num/i) x+=num/i;
            }
        }
        return x==num;
    }
};