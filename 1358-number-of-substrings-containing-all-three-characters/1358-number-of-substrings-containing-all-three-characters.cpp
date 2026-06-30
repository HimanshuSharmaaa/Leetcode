class Solution {
public:
    int numberOfSubstrings(string s) {
        int i = 0, noOfSub = 0, a = -1, b = -1, c = -1;
        
        while(i < s.size()){
            if(s[i] == 'a') a = i;
            if(s[i] == 'b') b = i;
            if(s[i] == 'c') c = i;

            if(a != -1 && b != -1 && c != -1) {
                int mini = min(a, min(b,c));
                noOfSub += mini+1;
            }
            
            i++;
        }
        
        return noOfSub;
    }
};