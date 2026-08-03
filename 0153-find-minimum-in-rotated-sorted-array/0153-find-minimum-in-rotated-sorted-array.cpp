class Solution {
public:
    int findMin(vector<int>& nums) {
        int low=0;
        int high=nums.size()-1;
     if(nums[0]<nums[high]){
        return nums[0];
     }   
     int small=nums[0];
     while(low<=high){
        int mid=low+((high-low)/2);
        if(nums[mid]>=small){
            low=mid+1;
        }
        else{
            small=nums[mid];
            high=mid;
        }
     }
     return small;
    }
};