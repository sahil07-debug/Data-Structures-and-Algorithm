class Solution {
public:
    int shipWithinDays(vector<int>& nums, int days) {
        int n=nums.size()-1;
        if(n==0) return nums[0];
        int low=0;
        int high=0;
        for(int i=0;i<=n;i++){
            high+=nums[i];
            if(nums[i]>=low) low=nums[i];
        }
        if(days==1)return high;
        int ans=high;
        while(low<=high){
            int mid=low+((high-low)/2);
            int d=1;
            int s=0;
            for(int i=0;i<=n;i++){
                s+=nums[i];
                if(s>mid){
                    d++;
                    s=nums[i];
                }
                if(d>days) break;
            }
            if(d<=days){
                ans=mid;
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return ans;
    }
};