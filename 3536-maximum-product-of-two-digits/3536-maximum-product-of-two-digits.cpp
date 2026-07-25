class Solution {
public:
    int maxProduct(int n) {
        string str = to_string(n);
        sort(str.begin(), str.end());
        int maxProduct = 0, product;

        for(int i = 1; i < str.size(); i++){
            product = (str[i]-'0') * (str[i-1]-'0');
            maxProduct = max(maxProduct, product);
        }

        return maxProduct;
    }
};