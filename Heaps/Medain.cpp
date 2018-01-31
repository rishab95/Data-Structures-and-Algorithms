#include<bits/stdc++.h>
using namespace std;
priority_queue<int, vector<int>, greater <int> > min_hp;
priority_queue<int> max_hp;

void put(int val)
{
    if( max_hp.size() && val >= max_hp.top())
        min_hp.push(val);
    else
        max_hp.push(val);

    if(abs(max_hp.size() - min_hp.size()) > 1)
    {
        if(max_hp.size() > min_hp.size())
        {
            int var = max_hp.top();
            max_hp.pop();
            min_hp.push(var);
        }
        else
        {
            int var = min_hp.top();
            min_hp.pop();
            max_hp.push(var);
        }
    }
}

double get_median()
{
    int ans = min_hp.size() + max_hp.size();
    double val;
    if(ans % 2 == 1)
    {
        if(max_hp.size() > min_hp.size())
            val = max_hp.top();
        else
            val = min_hp.top();
    }
    else
    {
        val = 0;
        if(max_hp.empty() == false)
            val += max_hp.top();
        if(min_hp.empty() == false)
            val += min_hp.top();
        val/=2;
    }
    return val;
}

int main()
{
    int n, x;
    cin >> n;
    for(int i = 0; i<n; i++)
    {
        cin>>x;
        put(x);
        cout << get_median() << endl;
    }
}
