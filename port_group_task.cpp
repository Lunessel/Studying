#include <iostream>
#include <bits/stdc++.h>
using namespace std;

#define DATA_SIZE 40
#define PORTS_COUNT 64
#define GROUP_COUNT 4094

void solve(void)
{
    vector<int> data = {2, 20, 6, 23, 2, 24, 5, 25, 6, 24, 3, 26, 5, 24, 8, 29, 1, 23, 4, 21, 6, 27, 7, 28, 9, 27, 4, 22, 1, 26, 1, 29, 7, 24, 6, 25, 9, 21, 8, 22};
    vector<int> ports, groups;
    int maxports, maxgroups, iports, igroups, tempports, tempgroups, answer;
    maxports = 1;
    maxgroups = 1;
    iports = 0;
    igroups = 0;
    tempports = 1;
    tempgroups = 1, answer = 0;

    while (true)
    {
        for (int i = 0; i < data.size(); i += 2)
        {
            ports.push_back(data[i]);
            groups.push_back(data[i + 1]);
        }
        sort(ports.begin(), ports.end()); // 12223
        sort(groups.begin(), groups.end());

        for (int i = 0; i < ports.size() - 1; i++)
        {
            if (ports[i] == ports[i + 1])
            {
                tempports++;
                if (maxports < tempports)
                {
                    maxports = tempports;
                    iports = i + 1;
                }
            }
            else
            {
                tempports = 1;
            }
        }
        /////////////////////////////////////////////////////////////
        for (int i = 0; i < ports.size() - 1; i++)
        {
            if (groups[i] == groups[i + 1])
            {
                tempgroups++;
                if (maxgroups < tempgroups)
                {
                    maxgroups = tempgroups;
                    igroups = i + 1;
                }
            }
            else
            {
                tempgroups = 1;
            }
        }
        if (maxports == maxgroups && maxports == 1)
        {
            break;
        }
        answer += 1;
        //Видаляємо повтори з ports i groups
        if (maxports >= maxgroups)
        {
            for (int i = 0; i < data.size();)
            {
                if (data[i] == ports[iports])
                {
                    data.erase(data.begin() + i, data.begin() + i + 2);
                }
                else
                {
                    i += 2;
                }
            }
            //ports.erase(ports.begin() + iports - maxports + 1, ports.begin() + iports + 1);
        }
        else
        {
            for (int i = 0; i < data.size();)
            {
                if (data[i + 1] == groups[igroups])
                {
                    data.erase(data.begin() + i, data.begin() + i + 2);
                }
                else
                {
                    i += 2;
                }
            }
            //groups.erase(groups.begin() + igroups - maxgroups + 1, groups.begin() + igroups + 1);
        }
        ports.clear();
        groups.clear();
        maxports = 1;
        maxgroups = 1;
        tempports = 1;
        tempgroups = 1;
        iports = 0;
        igroups = 0;
    }
    answer += data.size() / 2;
    cout << answer;
}

int main(void)
{
    solve();
}