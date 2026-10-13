class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> mpp(26, 0);
        priority_queue<int> pq;
        int time = 0;

        for(int i = 0; i < tasks.size(); i++) mpp[tasks[i]-'A']++;
        for(int i = 0; i < 26; i++) if(mpp[i] > 0) pq.push(mpp[i]);

        while(!pq.empty()) {
            vector<int> taskQueue;

            for(int i = 0; i < n+1; i++) {
                if(!pq.empty()) {
                    int task = pq.top();
                    pq.pop();
                    task--;
                    taskQueue.push_back(task);
                } else break;
            }

            for(int &t : taskQueue) if(t > 0) pq.push(t);
            if(pq.empty()) time += taskQueue.size();
            else time += n+1;
        }

        return time;
    }
};