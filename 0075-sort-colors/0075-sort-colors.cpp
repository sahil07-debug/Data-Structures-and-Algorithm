class Solution {
public:
    void sortColors(vector<int>& nums) {
        int count=0;
        int n=nums.size();
        for(int i=0;i<2;i++){
             for(int j=0;j<n;j++){
                if(nums[j]==i){
                    swap(nums[count],nums[j]);
                    count++;
                }
             }
        }
    }
};