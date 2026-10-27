class Solution {
public:
    vector<string> createGrid(int m, int n) {
        string stop = ".", hash = "#", first = "", rest = "";
        vector<string> result;

        for(int i = 0; i < n; i++) {
            first += stop;
            if(i != n-1) rest += hash;
            else rest += stop;
        }

        result.push_back(first);
        for(int i = 1; i < m; i++) result.push_back(rest);
        return result;
    }
};