class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int> store;
        int num, last;
        queue<int> q;

        for (int i = 1; i < 9; i++) q.push(i);

        while (!q.empty()) {
            num = q.front();
            q.pop();

            if(num > high) continue;
            if (low <= num && num <= high) store.push_back(num);

            last = num % 10;
            if (last < 9) {
                num = num * 10 + (last + 1);
                q.push(num);
            }
        }

        return store;
    }
};