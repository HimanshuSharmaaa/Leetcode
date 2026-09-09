class Solution {
public:
    long long countCommas(long long n) {
        long long ans = 0, lower = 1000, upper, count, comma = 1;

        while(lower <= n) {
            upper = lower * 1000 - 1;
            if(upper > n) upper = n;
            
            ans += (upper - lower + 1) * comma;
            lower *= 1000;
            comma++;
        }

        return ans;
    }
};