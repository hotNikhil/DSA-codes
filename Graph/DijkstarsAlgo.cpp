#include<bits/stdc++.h>
using namespace std;

class Edge{
    public:

    int v;
    int wt;

    Edge(int v , int wt){
        this->v = v;
        this->wt = wt;
    }

};


void dijkstras(vector<vector<Edge>> &graph , int src , int V){
        priority_queue<pair<int, int> , vector<pair<int , int>>, greater<pair<int , int>>> pq; // min heap 
        pq.push(make_pair(0,0));
        vector<int> dis(V , INT_MAX);
        dis[src] = 0;

        while(!pq.empty()){
            int u = pq.top().second;
            pq.pop();

            vector<Edge> edges = graph[u];
            for(Edge e : edges){
                if(dis[e.v] > dis[u] + e.wt){
                    dis[e.v] = dis[u] + e.wt;
                    pq.push({dis[e.v] , e.v});
                }
            }
        }

        for(int d: dis){
            cout<<d<<" ";
        }

        cout<<endl;
    }


int main(){
    int V = 6;
    vector<vector<Edge>> graph(V);

    graph[0].push_back(Edge(1,2));
    graph[0].push_back(Edge(2,4));

    graph[1].push_back(Edge(2,1));
    graph[1].push_back(Edge(3,7));

    graph[2].push_back(Edge(4,3));

    graph[3].push_back(Edge(5,1));

    graph[4].push_back(Edge(3,2));
    graph[4].push_back(Edge(5,5));

    dijkstras(graph, 0 , V);

    return 0;
}