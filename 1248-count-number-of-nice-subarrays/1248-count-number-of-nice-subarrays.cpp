class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n=nums.size();
        int ans=0;
        if(k==0) return (n*(n+1))/2;
        if(k<=n){
            int i=0;
            int j=0;
            int count=0;
            while(j<n){        
            while(count<k && j<n){
                if(nums[j]%2==1)count++;
                j++;
            }
            if(count<k) return ans;
            int start=1;
            int end=1;
            while(j<n && nums[j]%2==0 ){
                end++;
                j++;
            }
            while(i<j && nums[i]%2==0){
                start++;
                i++;
            }
            ans+=start*end;
            i++;
            count--;
            }
        }
        return ans;
        
    }
};