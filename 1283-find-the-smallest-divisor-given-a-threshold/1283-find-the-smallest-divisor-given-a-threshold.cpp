class Solution {
public:
    int smallestDivisor(vector<int>& nums, int k) {
        int n=nums.size()-1;
        int low=1;
        int high=INT_MIN;
        for(int i=0;i<=n;i++){
            if(high<nums[i]) high=nums[i];
        }
        if(n+1==k) return high;
        if(n==0) return (ceil((double)high / k));
        int ans=high;
        while(low<=high){
            int mid=low+((high-low)/2);
            long long sum=0;
            for(int i=0;i<=n;i++){
                sum += (nums[i] + mid - 1) / mid;
            }
            if(sum<=k){
                ans=min(mid,ans);
                high=mid-1;
            }
            else low=mid+1;

        }
        return ans;
    }
};