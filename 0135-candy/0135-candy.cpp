class Solution {
public:
    int candy(vector<int>& r) {
        if(r.size() == 1) return 1;

        int allocated = 1, total = 0, n = r.size();
        vector<int> left;
        left.push_back(1);

        for(int i = 1; i < n; i++) {
            if(r[i-1] >= r[i]) allocated = 1;
            else allocated++;

            left.push_back(allocated);
        }

        allocated = 1;
        for(int i = n-2; i >= 0; i--) {
            if(r[i] <= r[i+1]) allocated = 1;
            else allocated++;

            total += max(left[i], allocated);
        }

        return total + left[n-1];
    }
};