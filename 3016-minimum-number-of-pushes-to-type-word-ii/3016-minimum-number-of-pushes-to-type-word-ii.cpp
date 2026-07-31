class Solution {
public:
    int minimumPushes(string word) {
        if(word.size() < 9) return word.size();
        vector<int> store(26, 0);
        int turn = 1, ans = 0;

        for(int i = 0; i < word.size(); i++) store[word[i]-'a']++;
        sort(store.begin(), store.end(), greater<>());

        for(int i = 0; i < 26; i++) {
            if(store[i] == 0) return ans;
            if( i > 0 && i % 8 == 0) turn++;
            ans += store[i] * turn;
        }

        return ans;
    }
};