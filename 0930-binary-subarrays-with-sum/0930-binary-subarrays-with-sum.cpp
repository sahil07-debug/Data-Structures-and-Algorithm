class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int n=nums.size();
        int ans=0;
        if(n<goal) return  ans;
        int i=0;
        int j=0;
        int count=0;
        if(goal==0){
            while(j<n){
                while(j<n && nums[j]==0){
                count++;
                j++;
                  }
                ans+=(count*(count+1)/2);
                i=j+1;
                j++;
                count=0;
            }
        }
        while(j<n){
            while(count<goal && j<n){
               if(nums[j]==1) count++;
                j++;
            }
            if(count<goal) return ans;
            int start=1;
            int end=1;
            while(j<n && nums[j]==0){
              end++;
              j++;
           }
            while(i<j && nums[i]==0){
                start++;
                i++;
            }
            ans+=start*end;
            count--;
            i++;
        }
        return ans;
    }
};