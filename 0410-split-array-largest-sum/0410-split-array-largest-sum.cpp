class Solution {
public:
    int splitArray(vector<int>& nums, int k) {
        int n=nums.size();
        int low=INT_MIN;
        int high=0;
        for(int i=0;i<n;i++){
            if(nums[i]>low) low=nums[i];
            high+=nums[i];
        }
        if(k==n) return low;
        while(low<=high){
            int mid=low+((high-low)/2);
            if(issafe(nums,k,mid,n)==true) high=mid-1;
            else low=mid+1; 
        }
        return low;
    }
    bool issafe(vector<int> &nums,int k,int mid,int n){
        int m=0;
        int s=1;
          for(int i=0;i<n;i++){
             if(m+nums[i]>mid){
                s++;
                m=nums[i];
                if(s>k) return false;
             }
             else m+=nums[i];
          }
              return true;
    }
};