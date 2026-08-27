class Solution {
public:
    string frequencySort(string s) {
        int n=s.length();
        map<char,int>a;
        for(int i=0;i<n;i++){
            a[s[i]]++;
        }
        int j=0;
        while(j<n){
            int count=0;
            char b='\0';
            for (auto& pair : a) {
                if (pair.second > count) {
                    count = pair.second;
                    b = pair.first;
                }
            }
            if(count==0 || j==n) break;
            for(int i=0;i<count;i++){
                s[j]=b;
                j++;
            }
            a[b]=0;
        }
        return s;
    }
};