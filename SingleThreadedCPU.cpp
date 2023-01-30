#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        priority_queue<pair<int,int>,vector<pair<int,int>>, greater<>> heap;
        vector<array<int,3>> sortedTask;
        for(int i=0;i<tasks.size();i++)
        {
            sortedTask.push_back({tasks[i][0],tasks[i][1],i});vjf
        }
        
        sort(sortedTask.begin(),sortedTask.end());
        vector<int> sequence;
        long long currtime=0;
        int taskindex=0;
        while(taskindex<tasks.size()||!heap.empty())
        {
            if(heap.empty()&&currtime<sortedTask[taskindex][0])
            {
                currtime=sortedTask[taskindex][0];
            }
            while(currtime>=sortedTask[taskindex][0]&&taskindex<tasks.size())
            {
                heap.push({sortedTask[taskindex][1],sortedTask[taskindex][2]});
                taskindex++;
            }
            int t = heap.top().second;
            int tt = heap.top().first;
            heap.pop();
            sequence.push_back(t);
            currtime+=tt;

        }

        return sequence;
        
    }
};