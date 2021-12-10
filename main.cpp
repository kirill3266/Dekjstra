#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <string>
#include <utility>
using namespace std;

const int INF = 1000000000;

void Dejkstra(int s, int n, vector<vector<pair<int, int> > >& w) {//g
    vector<int> d (n, INF),  p (n); //d is best distance, p is point
    d[s] = 0; //d from start to start is zero
    set < pair<int,int> > q ; //queue
    q.emplace (make_pair (d[s], s)); //pair<distance,start>
    while (!q.empty()) {
        int v = q.begin()->second; //takes point
        q.erase (q.begin());//deletes queue

        for (size_t j=0; j<w[v].size(); ++j) { //vor every distance from point takes arguments
            int to = w[v][j].first,
                    len = w[v][j].second;
            if (d[v] + len < d[to]) { //compares distance to prev. point + len and best distance to point
                q.erase (make_pair (d[to], to));//if true, deletes pair
                d[to] = d[v] + len;
                p[to] = v;
                q.emplace (make_pair (d[to], to));
            }
        }
    }
    for (auto i : d) cout << i << " ";
    cout << "\n";
}

int main() {
    fstream File("../Input.txt");
    if (!File.is_open()) {
        cerr << "Uh oh, SomeText.txt could not be opened for writing!" << endl;
        exit(1);
    }

    int n; //for num of elems
    int tmp;
    bool b = true; //to assign n once
    int it = 0; //iterator for rows
    int i = 0; //iterator for it
    vector<vector<pair<int, int> > > w;

    while (!File.eof()) {

        vector<pair<int, int >> vec;
        if (b) {
            File >> n;
            b = false;
        } else {
            if (it >= n) break; //to prevent appending while eof
            do {
                File >> tmp;
             if(tmp!=0) vec.emplace_back(make_pair(i%n, tmp));
                i++;
                if (i % n == 0) it++;
            } while (i % n != 0);
            w.push_back(vec);
        }
    }

    cout << "Starting cout:\n";
    cout << "N is: " << n << endl;
    for (auto i: w) {
        for (auto j: i)
            cout << j.first<< " " << j.second << "  ";
        cout << "\n";
    }
    cout << "Ending cout\n";

    Dejkstra(0, n, w);
}
