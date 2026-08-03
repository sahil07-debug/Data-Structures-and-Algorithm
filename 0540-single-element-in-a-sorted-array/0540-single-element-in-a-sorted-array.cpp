class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int low=0;
        int high=nums.size()-1;
        if(high==0) return nums[0];
        if(nums[low]!=nums[low+1]) return nums[low];
        if(nums[high]!=nums[high-1]) return nums[high];
        low=low+2;
        high=high-2;
        while(low<=high){
            int mid=low+((high-low)/2);
            if(nums[mid]!=nums[mid-1] && nums[mid]!=nums[mid+1]) return nums[mid];
            else if((mid%2==1 && nums[mid]==nums[mid-1]) || (mid%2==0 && nums[mid]==nums[mid+1])) low=mid+1;
            else if((mid%2==1 && nums[mid]==nums[mid+1]) || (mid%2==0 && nums[mid]==nums[mid-1])) high=mid-1;
        }
        return-1;

    }
};