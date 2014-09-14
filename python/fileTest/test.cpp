#include <bits/stdc++.h>

using namespace std;

set<int> calU(map< int, set<int> > graph)
{
    set<int> ret;
    int attack = -1, endure = -1;
    bool isExist = false;
    for (map< int, set<int> >::iterator it = graph.begin();
            it != graph.end(); ++ it) {
        map<int, bool> isVisited;
        queue<int> que;
        attack = it->first;
        que.push(attack);
        isVisited[attack] = true;
        endure = -1;
        while (! que.empty()) {
            int cur = que.front();
            que.pop();
            set<int> &adj = graph[cur];
            for (set<int>::iterator it = adj.begin(); it != adj.end(); ++ it) {
                int next = *it;
                if (! isVisited[next]) {
                    isVisited[next] = true;
                    que.push(next);
                }
            }
            endure = cur;
        }
        if (graph[attack].find(endure) == graph[attack].end()) {
            isExist = true;
            break;
        }
    }
    if (! isExist) {
        return ret;
    }

    set<int> attackSet, attackOneSet;//攻的集和、一次被攻推到的集合
    set<int> endureSet, endureOneSet;//受的集合、一次被受推到的集合
    set<int> bothOneSet, unknownSet;//攻受都可以一次推到的集合、未确定的集合
    map<int, int> weight;

    for (map< int, set<int> >::iterator it = graph.begin();
            it != graph.end(); ++ it) {
        unknownSet.insert(it->first);
    }
    unknownSet.erase(attack);
    attackSet.insert(attack);
    for (set<int>::iterator it = graph[attack].begin();
            it != graph[attack].end(); ++ it) {
        unknownSet.erase(*it);
        attackOneSet.insert(*it);
        weight.insert(make_pair(*it, 1));
    }
    unknownSet.erase(endure);
    endureSet.insert(endure);
    for (set<int>::iterator it = graph[endure].begin();
            it != graph[endure].end(); ++ it) {
        if (attackOneSet.find(*it) != attackOneSet.end()) {
            attackOneSet.erase(*it);
            bothOneSet.insert(*it);
        }
        else {
            unknownSet.erase(*it);
            endureOneSet.insert(*it);
            weight.insert(make_pair(*it, 1));
        }
    }

    while (! attackOneSet.empty() || ! endureOneSet.empty()) {
        if (! attackOneSet.empty()) {
            int cur = *(attackOneSet.begin());
            int maxWeight = weight[cur];
            for (set<int>::iterator it = attackOneSet.begin();
                    it != attackOneSet.end(); ++ it) {
                if (weight[*it] > maxWeight) {
                    maxWeight = weight[*it];
                    cur = *it;
                }
            }

            attackOneSet.erase(cur);
            attackSet.insert(cur);
            set<int> &adj = graph[cur];
            for (set<int>::iterator it = adj.begin();
                    it != adj.end(); ++ it) {
                weight[*it] ++;
                if (unknownSet.find(*it) != unknownSet.end()) {
                    unknownSet.erase(*it);
                    attackOneSet.insert(*it);
                    weight.insert(make_pair(*it, 1));
                }
                else if (endureOneSet.find(*it) != endureOneSet.end()) {
                    endureOneSet.erase(*it);
                    bothOneSet.insert(*it);
                }
            }
        }
        if (! endureOneSet.empty()) {
            int cur = *(endureOneSet.begin());
            int maxWeight = weight[cur];
            for (set<int>::iterator it = endureOneSet.begin();
                    it != endureOneSet.end(); ++ it) {
                if (weight[*it] > maxWeight) {
                    maxWeight = weight[*it];
                    cur = *it;
                }
            }

            endureOneSet.erase(cur);
            endureSet.insert(cur);
            set<int> &adj = graph[cur];
            for (set<int>::iterator it = adj.begin();
                    it != adj.end(); ++ it) {
                weight[*it] ++;
                if (unknownSet.find(*it) != unknownSet.end()) {
                    unknownSet.erase(*it);
                    endureOneSet.insert(*it);
                }
                else if (attackOneSet.find(*it) != attackOneSet.end()) {
                    attackOneSet.erase(*it);
                    bothOneSet.insert(*it);
                }
            }
        }
    }

    for (map< int, set<int> >::iterator it = graph.begin();
            it != graph.end(); ++ it) {
        if (attackSet.find(it->first) == attackSet.end() &&
                endureSet.find(it->first) == endureSet.end()) {
            ret.insert(it->first);
        }
    }

    return ret;
}

int main()
{
    freopen("input.txt", "r", stdin);
    map< int, set<int> > graph;
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++ i) {
        graph[i] = set<int>();
    }
    int a, b;
    while (cin >> a >> b) {
        graph[a].insert(b);
        graph[b].insert(a);
    }
    set<int> ans = calU(graph);
    for (set<int>::iterator it = ans.begin();
            it != ans.end(); ++ it) {
        cout << *it << " ";
    }
    cout << endl;
    return 0;
}
