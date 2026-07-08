class Solution {
public:
    static const int MOD = 1e9 + 7;

    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        int n = s.size();

        // Prefix sum of digits
        vector<int> prefSum(n + 1, 0);

        // Prefix count of non-zero digits
        vector<int> cntNZ(n + 1, 0);

        // Compressed non-zero digits
        string nz = "";

        for (int i = 0; i < n; i++) {
            prefSum[i + 1] = prefSum[i] + (s[i] - '0');
            cntNZ[i + 1] = cntNZ[i] + (s[i] != '0');

            if (s[i] != '0')
                nz += s[i];
        }

        int m = nz.size();

        // pow10[i] = 10^i % MOD
        vector<long long> pow10(m + 1, 1);
        for (int i = 1; i <= m; i++)
            pow10[i] = (pow10[i - 1] * 10) % MOD;

        // Prefix value of compressed string
        vector<long long> prefNum(m + 1, 0);
        for (int i = 0; i < m; i++) {
            prefNum[i + 1] = (prefNum[i] * 10 + (nz[i] - '0')) % MOD;
        }

        vector<int> ans;

        for (auto &q : queries) {
            int l = q[0];
            int r = q[1];

            // Sum of digits
            long long sum = prefSum[r + 1] - prefSum[l];

            // Indices in compressed string
            int L = cntNZ[l];
            int R = cntNZ[r + 1];

            // Number formed by non-zero digits in range
            long long num = 0;
            if (L != R) {
                num = (prefNum[R] -
                       (prefNum[L] * pow10[R - L]) % MOD +
                       MOD) % MOD;
            }

            ans.push_back((sum * num) % MOD);
        }

        return ans;
    }
};