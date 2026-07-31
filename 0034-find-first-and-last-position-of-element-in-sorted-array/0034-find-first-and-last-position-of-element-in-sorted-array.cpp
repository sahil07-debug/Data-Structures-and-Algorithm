class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int>ans={-1,-1};
        if (nums.empty()) {
            return ans;
        }
        int min=0;
        int max=nums.size()-1;
        while(min<=max){
           int mid=min+((max-min)/2);
           if(nums[mid]==target){
            ans[0]=mid;
            max=mid-1;
           }
           else if(nums[mid]<target){
            min=mid+1;
           }
           else{
            max=mid-1;
           }
    }
    if(ans[0]==-1){
        return{-1,-1};
    }
     min=ans[0];
     max=nums.size()-1;
     while(min<=max){
           int mid=min+((max-min)/2);
           if(nums[mid]==target){
            ans[1]=mid;
            min=mid+1;
           }
           else if(nums[mid]<target){
            min=mid+1;
           }
           else{
            max=mid-1;
           }
    }
    return ans;
    }
};