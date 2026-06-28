class Solution {
public:
    bool check(vector<int>& num) {
        if(num.size()<=100 && num.size()>=1){
            int n=num.size()-1;
            int smallest=num[0];
            int index=0;
            for(int i=1;i<=n;i++){
                if(num[i]<smallest){
                    smallest=num[i];
                    index=i;
                }
                if (num[i]==smallest && i==n && num[0]==smallest){
                    int j=n;
                    while(num[j]==smallest && j>0){
                        j--;
                    } 
                    index=j;
                }
            }
            int large;
            for(int i=0;i<=n-1;i++){
                index++;
                if (index>n){
                    index=0;
                }
               large=num[index];
               if(large<smallest){
                return false;
               }
               smallest=large;
            }
            return true;
        }
        else{
            return false;
        }
    }
};