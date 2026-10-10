class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        unordered_map<int,int> mpp;
        vector<int> result;

        for(int i = 0; i < nums.size(); i++) mpp[nums[i]]++;

        for(const auto&i : mpp) {
            pq.push({i.second, i.first});
            if(pq.size() > k) pq.pop();
        }

        while(!pq.empty()) {
            result.push_back(pq.top().second);
            pq.pop();
        }

        return result;
    }
};