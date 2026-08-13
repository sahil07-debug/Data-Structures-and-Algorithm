class Solution {
public:
    bool lemonadeChange(vector<int>& nums) {
        int n=nums.size();
        int x=0;
        int y=0;
        for(int i=0;i<n;i++){
            if(nums[i]==5){
                x++;
            }
            else if(nums[i]==10){
                if(x>0){
                    x--;
                    y++;
                }
                else return false;
            }
            else{
                if(y>0&&x>0){
                    y--;
                    x--;
                }
                else if(x>2){
                    x-=3;
                }
                else return false;
            }
        }
        return true;
    }
};