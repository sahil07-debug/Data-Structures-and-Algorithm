class Solution {
public:
    int findKthPositive(vector<int>& nums, int k) {
        int low=0;
        int high=nums.size()-1;
        if(high+1==nums[high]) return nums[high]+k;
        if(nums[0]>k) return k;
        while(low<=high){
           int mid=low+((high-low)/2);
           if(nums[mid]-mid-1<k){
            low=mid+1;
           }
           else high=mid-1;
        }
        return low+k;
    }
};