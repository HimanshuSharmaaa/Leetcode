class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int> store, ans;

        for (int len = 2; len < 10; len++) {
            for (int start = 1; start <= 10 - len; start++) {
                int num = 0;
                for (int d = start; d < start + len; d++) {
                    num = num * 10 + d;
                }
                if (num >= low && num <= high) store.push_back(num);
            }
        }

        for (int i = 2; i < store.size(); i++) {
            if (i > high) break;
            if (low <= i && i <= high) ans.push_back(i);
        }

        return store;
    }
};