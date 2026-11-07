class Solution {
public:
    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
        priority_queue<
            pair<int,int>,
            vector<pair<int,int>>,
            greater<pair<int,int>>
        > pq;

        priority_queue<
            pair<long long, pair<int,int>>,
            vector<pair<long long, pair<int,int>>>,
            greater<pair<long long, pair<int,int>>>
        > occupied;

        vector<int> result;

        for(int i = 0; i < servers.size(); i++) {
            pq.push({servers[i], i});
        }

        long long currTime = 0;

        for(int i = 0; i < tasks.size(); i++) {

            // Time must never move backwards
            currTime = max(currTime, (long long)i);

            // Release all available servers
            while(!occupied.empty() &&
                  occupied.top().first <= currTime) {

                pq.push(occupied.top().second);
                occupied.pop();
            }

            // If all servers are busy, jump forward
            if(pq.empty()) {

                currTime = occupied.top().first;

                while(!occupied.empty() &&
                      occupied.top().first <= currTime) {

                    pq.push(occupied.top().second);
                    occupied.pop();
                }
            }

            // Assign the best available server
            auto server = pq.top();
            pq.pop();

            result.push_back(server.second);

            occupied.push({
                currTime + tasks[i],
                server
            });
        }

        return result;
    }
};