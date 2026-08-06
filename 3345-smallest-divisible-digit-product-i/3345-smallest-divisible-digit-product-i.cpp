class Solution {
public:
    int digitProduct(int n) {
        int product = 1;
        
        while(n) {
            product *= n % 10;
            n /= 10;
        }

        return product;
    }

    int smallestNumber(int n, int t) {
        int smallest = INT_MAX;

        for(int i = n; i < 101; i++) {
            if(digitProduct(i) % t == 0) {
                smallest = i;
                break;
            }
        }

        return smallest;
    }
};