class Solution {
public:
    int minEatingSpeed(vector<int>& nums, int h) {
        int low=1;
        int high=INT_MIN;
        int n=nums.size()-1;
        for(int i=0;i<=n;i++){
            if(nums[i]>high) high=nums[i];
        }
        if(h==n+1) return high;
        if(n==0) return (ceil((double)high / h));
        int k = high;
        while(low<=high){
            int mid=low+((high-low)/2);
            long long sum=0;
            for(int i=0;i<=n;i++){
               sum += (nums[i] + mid - 1) / mid;
            }
            if(sum<=h){
              high=mid-1;
              k=mid;
            }
            else low=mid+1;
        }
        return k;
    }
};