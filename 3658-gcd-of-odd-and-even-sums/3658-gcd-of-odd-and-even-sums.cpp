class Solution {
public:
    int calGCD(int a, int b){
        while(a != 0 && b != 0){
            if(a < b) b = b % a;
            else a = a % b;
        }
        return max(a,b);
    }

    int gcdOfOddEvenSums(int n) {
        int sumOdd = 0, sumEven = 0, odd = 1, even = 2;

        while(n > 0){
            sumOdd += odd;
            odd += 2;
            sumEven += even;
            even += 2;
            n--;
        }  
        
        return calGCD(sumOdd, sumEven);
    }
};