
class Solution {
public:
    vector<int> buildLPS(const vector<int>& pattern) {
        int m = pattern.size();
        vector<int> lps(m, 0);

        int len = 0;
        int i = 1;

        while (i < m) {
            if (pattern[i] == pattern[len]) {
                lps[i++] = ++len;
            } else {
                if (len != 0) {
                    len = lps[len - 1];
                } else {
                    lps[i++] = 0;
                }
            }
        }

        return lps;
    }

    bool isRotateAble(const vector<int>& subpart,
                      const vector<int>& check) {
        int n = subpart.size();
        if (n != (int)check.size()) return false;

        vector<int> lps = buildLPS(check);

        int i = 0, j = 0;

        while (i < 2 * n - 1) {
            int current = subpart[i % n];

            if (current == check[j]) {
                i++;
                j++;

                if (j == n) return true;
            } else if (j > 0) {
                j = lps[j - 1];
            } else {
                i++;
            }
        }

        return false;
    }

    int sortableIntegers(vector<int>& nums) {
        int n = nums.size(), sum = 0;

        vector<int> sorted = nums;
        sort(sorted.begin(), sorted.end());

        for (int k = 1; k <= n; k++) {
            if (n % k != 0) continue;

            bool isValidK = true;
            for (int start = 0; start < n; start += k) {
                vector<int> check(sorted.begin() + start,
                                  sorted.begin() + start + k);

                vector<int> subpart(nums.begin() + start,
                                    nums.begin() + start + k);

                if (!isRotateAble(subpart, check)) {
                    isValidK = false;
                    break;
                }
            }

            if (isValidK) sum += k;
        }

        return sum;
    }
};