class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& res) {
        unordered_map<int, unordered_set<int>> seat;
        int count = 0;

        for (auto &row: res) seat[row[0]].insert(row[1]);
        count += (n - seat.size()) * 2;

        for (auto& it : seat) {
            auto isAva = [&](int seatNo) {
                return it.second.find(seatNo) == it.second.end();
            };

            bool group1 = isAva(2) && isAva(3) && isAva(4) && isAva(5);
            bool group2 = isAva(4) && isAva(5) && isAva(6) && isAva(7);
            bool group3 = isAva(6) && isAva(7) && isAva(8) && isAva(9);

            if(group1 && group3) count += 2;
            else if(group1 || group2 || group3) count += 1;
        }

        return count;
    }
};