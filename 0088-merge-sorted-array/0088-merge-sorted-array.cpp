class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        if(n==0) return;
        int j=0;
        int k=0;
        vector<int> ans;
        while(j<m && k<n){
          if(nums1[j]<=nums2[k]){
            ans.push_back(nums1[j]);
            j++;
          }
          else{
            ans.push_back(nums2[k]);
            k++;
          }
        }
        if(k<n){
            for(int i=k;i<n;i++){
                ans.push_back(nums2[i]);
            }
        }
         if(j<m){
            for(int i=j;i<m;i++){
                ans.push_back(nums1[i]);
            }
        }
        for(int i=0;i<m+n;i++){
            nums1[i]=ans[i];
        }
    }
};