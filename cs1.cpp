/*
    Time Complexity: O( N * log(N) )
    Space Complexity: O( N )

    where 'N' is the number of cities.

    hard
*/


// DSU


int find_par(int v, vector<int>& parent)
{
    if (v == parent[v])
        return v;
    return parent[v] = find_par(parent[v], parent);
}


void union_sets(int a, int b, vector<int>& parent, vector<int>& _rank, int& cnt_good, int& cnt_bad)
{
    a = find_par(a, parent);
    b = find_par(b, parent);

    
    if (a != b)
    {
        if (_rank[a] < _rank[b])
            swap(a, b);


        
        if (_rank[a] > 1)
        {
            if (_rank[a] % 2)
                cnt_bad--;
            else
                cnt_good--;
        }
       
        if (_rank[b] > 1)
        {
            if (_rank[b] % 2)
                cnt_bad--;
            else
                cnt_good--;
        }

        parent[b] = a;
        _rank[a] += _rank[b];

        
        if (_rank[a] > 1)
        {
            if (_rank[a] % 2)
                cnt_bad++;
            else
                cnt_good++;
        }
    }
}


vector<int> goodBad(int& n, vector<vector<int>>& edge)
{


    vector<int> parent(n + 1), _rank(n + 1);
    int cost = 0;

    
    vector<int> ans;


    
    for (int i = 1; i < n + 1; i++)
    {

        parent[i] = i;
        _rank[i] = 1;
    }


    int cnt_good = 0, cnt_bad = 0;

    for (int i = 0; i < n - 1; i++)
    {


        
        union_sets(edge[i][0], edge[i][1], parent, _rank, cnt_good, cnt_bad);

        ans.push_back(abs(cnt_good - cnt_bad));
    }

    return ans;
}