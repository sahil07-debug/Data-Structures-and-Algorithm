class Solution {
public:
    int minDays(vector<int>& nums, int m, int k) {
        int n=nums.size()-1;
        if(n+1<(long long) m*k) return -1;
        int low=INT_MAX;
        int high=INT_MIN;
        for (int i=0;i<=n; i++){
            if(nums[i]>high) high=nums[i];
            if(nums[i]<=low) low=nums[i];
        }
        if(n+1==(long long)m*k) return high;
        int days=high;
        while(low<=high){
            int f=0;
            int b=0;
            int mid=low+((high-low)/2);
            for(int i=0;i<=n;i++){
                if(nums[i]<=mid){
                    f++;
                    if(f==k){
                        b++;
                        f=0;
                    }
                }
                else f=0;
            }
            if(b>=m){
                    days=mid;
                    high=mid-1;
                }
                else low=mid+1;
               }
        return days;
    }
};