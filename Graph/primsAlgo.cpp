#include<bits/stdc++.h>
using namespace std;

class Graph{
    int V;
    list<pair<int, int>> * l;
    bool isUndirec;

public:

    Graph(int V , bool isUndirec = true){
        this->V = V;
        l = new list<pair<int , int>> [V];
        this->isUndirec = isUndirec;
    }

    void addEdge(int u , int v , int wt){
        l[u].push_back({v,wt});
        if(isUndirec) l[v].push_back({u,wt});
    }

    //prims Algorithm

    void primsAlgo(int src){
    priority_queue<pair<int ,int> , vector<pair<int , int>> , greater<pair<int , int >>> pq; // min Heap
    vector<bool> mstSet(V , false);
    int ans  = 0;

    pq.push({0  , src});

    while(pq.size()>0){
        int u = pq.top().second;
        int kilo = pq.top().first;
        pq.pop();

        if(!mstSet[u]){
            mstSet[u] = true;
            ans+=kilo;
            list<pair<int,int>> neighbors = l[u];
            for(pair<int,int> n:neighbors){
                pq.push({n.second , n.first});
            }

        }
    }

    cout<<ans<<endl;

}

};







int main(){
   Graph graph(4);

   graph.addEdge(0,1,10);
   graph.addEdge(0,2,15);
   graph.addEdge(0,3,30);

   graph.addEdge(1,3,40);

   graph.addEdge(2,3,50);

    graph.primsAlgo(0);

    return 0;
}