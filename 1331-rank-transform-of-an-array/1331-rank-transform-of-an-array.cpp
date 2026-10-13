class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        int rank = 1, prev, n = arr.size();
        
        if(n == 0) return {};
        priority_queue<int, vector<int>, greater<int>> pq;
        unordered_map<int,int> mpp;
        vector<int> result(arr.size(), 0);

        for(int i : arr) pq.push(i);
        prev = pq.top();

        while(!pq.empty()) {
            if(prev != pq.top()) rank++, prev = pq.top();
            mpp[pq.top()] = rank;
            pq.pop();
        }

        for(int i = 0; i < n; i++) result[i] = mpp[arr[i]];
        return result;
    }
};