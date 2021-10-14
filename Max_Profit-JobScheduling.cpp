/*
1)sorting jobs according to end time.
2)declare dp which stores {end time, total profit till that time}.
3)go through sorted jobs, find the best-fit end time(previous of upper bound of current starting time) from dp, and add current job profit to that one if it is greater than the maximum profit that has been present in dp, then add that calculated profit to the dp.
4)maximum profit has been stored at the end of dp, thus return (last element)->second.
*/

class Solution {
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
    int n=startTime.size();
	vector<vector<int>> jobs;
        for (int i = 0; i < n; ++i) {
            jobs.push_back({endTime[i], startTime[i], profit[i]});
        }
        sort(jobs.begin(), jobs.end()); // sort jobs according to end time
        map<int, int> dp = {{0, 0}}; 
        for (auto& job : jobs) {
            int cur = prev(dp.upper_bound(job[1]))->second + job[2]; 
            if (cur > dp.rbegin()->second)
                dp[job[0]] = cur;
        }
        return dp.rbegin()->second;
    }
};