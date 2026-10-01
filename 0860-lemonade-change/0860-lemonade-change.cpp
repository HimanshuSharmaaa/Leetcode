class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        if(bills[0] != 5) return false;
        int five = 0, ten = 0, twenty = 0;

        for(int i = 0; i < bills.size(); i++) {
            if(bills[i] == 5) five++;
            else if(bills[i] == 10) {
                if(five == 0) return false;
                else {
                    five--;
                    ten++;
                }
            } else {
                if(ten > 0 && five > 0) {
                    twenty++;
                    ten--;
                    five--;
                } else if(five > 2) {
                    five -= 3;
                    twenty++;
                } else return false;
            }
        }

        return true;
    }
};