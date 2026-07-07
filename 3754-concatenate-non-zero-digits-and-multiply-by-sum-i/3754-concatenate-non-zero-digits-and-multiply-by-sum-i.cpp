class Solution {
public:
    long long sumAndMultiply(int n) {
        if (n == 0) return 0;
        long long sum = 0;
        string no = "";

        while (n) {
            if (n % 10 != 0) {
                no = char((n%10) + '0') + no;
                sum += n % 10;
            }
            n = n / 10;
        }

        return sum * stoll(no);
    }
};