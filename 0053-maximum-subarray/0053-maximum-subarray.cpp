class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxi=INT_MIN;
        int n=nums.size();
        for(int i=0;i<n;i++){
            int sum =sum+nums[i];
            if(maxi<sum){
                maxi=sum;
            }
            if(sum<0){
                sum=0;
            }
        }
        if(maxi==0){
            maxi=INT_MIN;
            for(int i=0;i<n;i++){
                if(nums[i]>maxi){
                    maxi=nums[i];
                }
            }
        }
        return maxi;
    }
};