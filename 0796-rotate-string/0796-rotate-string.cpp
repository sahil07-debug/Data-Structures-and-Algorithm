class Solution {
public:
    bool rotateString(string s, string goal) {
        int n=s.length();
        if(n!=goal.length()) return false;
        string d=s+s;
        return d.find(goal)!=string::npos;
    }
};