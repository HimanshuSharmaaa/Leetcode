class Solution {
public:
    long long countCommas(long long n) {
        long long result = 0;

        if(n > 999) result += n - 1000 + 1;
        if(n > 999999) result += n - 1000000 + 1;
        if(n > 999999999) result += n - 1000000000 + 1;
        if(n > 999999999999) result += n - 1000000000000 + 1;
        if(n > 999999999999999) result += n - 1000000000000000 + 1;

        return result;
    }
};