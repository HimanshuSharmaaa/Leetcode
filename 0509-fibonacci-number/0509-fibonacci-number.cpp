class Solution {
public:
    int cal(int n, int first, int second) {
        if (n == 0) return second;
        return cal(n - 1, second, first + second);
    }

    int fib(int n) {
        if (n == 0) return 0;
        if (n == 1) return 1;
        return cal(n - 1, 0, 1);
    }
};