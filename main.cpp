
#include <vector>
#include <set>
#include "Graphviz.h"
const int INF = 1000000000;

vector<int> Dejkstra(int s, int n, vector<vector<pair<int, int> > >& w) {//g
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
    return d;
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
    int s = 0; //start point
    vector<vector<pair<int, int> > > w;

    //file reading
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

    //Outputting input vector
    cout << "Starting cout:\n";
    cout << "N is: " << n << endl;
    for (auto i: w) {
        for (auto j: i)
            cout << j.first<< " " << j.second << "  ";
        cout << "\n";
    }
    cout << "Ending cout\n\n";

    //Do graph
    Graphviz graph;
int count=0;
string str;
    for (auto i: w) {
        for (auto j: i)
            if(count < j.first)str += "\t" + to_string(count) + " -- " + to_string(j.first) + "[label=""" + to_string(j.second) + """]" + ";";
            if(count!= n -1)str +="\n";
            graph(str);
            str.clear();
            count ++;
    }

    //Outputing result
    vector<int> res(Dejkstra(s, n, w));
    for (auto i : res) cout << i << " ";
    cout << "\n";

}
