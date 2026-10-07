class Solution {
public:
    int minGroups(vector<vector<int>>& in) {
        multiset<int> result;
        sort(in.begin(), in.end());
        result.insert(-1);

        for(int i = 0; i < in.size(); i++) {
            int found = -1;

            if(*result.begin() < in[i][0]) {
                result.erase(result.begin());
                result.insert(in[i][1]);
            } else result.insert(in[i][1]);
        }

        return result.size();
    }
};