class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        int activeOnes = count(begin(s), end(s), '1');
        int countZeros = 0, maxOnes = 0;
        vector<int> store;

        for(int i = 0; i < s.size(); i++){
            if(s[i] == '0') countZeros++;
            else {
                if(countZeros != 0) store.push_back(countZeros);
                countZeros = 0;
            }
        }

        if(countZeros != 0) store.push_back(countZeros);

        for(int i = 1; i < store.size(); i++){
            maxOnes = max(maxOnes, store[i-1]+store[i]);
        }

        return maxOnes+activeOnes;
    }
};