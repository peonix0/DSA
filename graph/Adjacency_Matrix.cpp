// Undirected graphs

#include<iostream>
#include "../queue/queue_using_simple_array.cpp"
using namespace std;

namespace Queue{
  #include "../queue/queue_using_simple_array.cpp"
}

struct Graph{
  int V;
  int E;
  int **adjMatrix;        // 2D array
};

class edge{
public:

  int Source;
  int Destination;

    edge(int S,int D)
   :Source(S), Destination(D){}

};

Graph *createGraph(int N_v){

  Graph *G = new(nothrow) Graph;
  if(!G){
    cout <<"~ Memory error ~\n";
    return NULL;
  }
  G->V = N_v;
  G->E = 0;
  G->adjMatrix = new int*[N_v];
  for(int i=0;i<N_v;i++){
    G->adjMatrix[i] = new int[N_v];
    for(int j=0;j<N_v;j++){
      G->adjMatrix[i][j] = 0;
    }

  }
  return G;
}

void DisplayGraph(Graph *G){
  int N_v = G->V;

  for(int i=0;i<N_v;i++){
    for(int j=0;j<N_v;j++){
      cout.width(3);
      cout << G->adjMatrix[i][j];
    }cout <<"\n";
  }
}

bool findEdge(Graph *G, edge E){
  int N_v  = G->V;
  if(E.Source >= N_v || E.Destination >= N_v){
    return false;
  }
  else if(G->adjMatrix[E.Source][E.Destination] == 1){
    return true;
  }
  return false;
}

void insertEdge(Graph *G, edge E){
  int N_v = G->V;
  if(E.Source >= N_v || E.Destination >= N_v){
    cout << "~ Source or Destination node are out of range ~\n";
    return;
  }
  if(findEdge(G,E)){
    cout << "~ Edge already there ~\n";
    return;
  }
  else{

    G->adjMatrix[E.Source][E.Destination] = 1;
    G->adjMatrix[E.Destination][E.Source] = 1;
    G->E +=1;
  }
}


void removeEdge(Graph *G, edge E){
  if(!findEdge(G,E)){
    cout << "~ Edge is not there ~\n";
    return;
  }
  else{

    G->adjMatrix[E.Source][E.Destination] = 0;
    G->adjMatrix[E.Destination][E.Source] = 0;
    G->E -=1;
    cout <<"~ Edge removed ~\n";
  }
}

void deleteGraph(Graph *G){
  if(G->adjMatrix){
    for(int i=0;i<G->V;i++){
      delete(G->adjMatrix[i]);
    }
    delete[] G->adjMatrix ;
  }
  delete G;
  cout <<"~ Graph deleted ~\n";
}

// Depth first search algorithm

void DFS(Graph *G, int Start, bool *Visited_node){
  int N_v = G->V;

  int position = Start;
  if(true){
    Visited_node[position] = true;
    for(int i=0;i<N_v; i++){
      if(G->adjMatrix[position][i]==1 && Visited_node[i]==0){
        cout << position <<" -> "<<i<<" ";
        Visited_node[i] = true;
        DFS(G,i,Visited_node);
      }
    }
  }
}

// Breadth first search Algorithm

void BFS(Graph *G, int start){
   Queue::queue *Active = Queue::create_queue(G->V);
   Queue::enqueue(Active, start);
   bool Visited_node[G->V] = {0};
   cout <<"BFS: ";
   while(!Queue::isEmpty(Active)){
     int position = Queue::dequeue(Active);
     Visited_node[position] = 1;
     for(int i=0;i<G->V;i++){
       if(G->adjMatrix[position][i]==1 && Visited_node[i]==0){
         cout <<position<<" -> "<<i<<" ";
         Queue::enqueue(Active, i);
         Visited_node[i] = 1;
       }
     }
   }
   cout <<"\n";
}



// //test
//
// int main(){
//   Graph *G = createGraph(5);
//
//   insertEdge(G,edge(0,1));
//   insertEdge(G,edge(1,2));
//   insertEdge(G,edge(0,2));
//   insertEdge(G,edge(1,3));
//   insertEdge(G,edge(1,4));
//   DisplayGraph(G);
//   cout <<"-------------\n";
//
//   removeEdge(G,edge(0,2));
//
//   DisplayGraph(G);
//   insertEdge(G,edge(0,2));
//
//   bool *Visited_node = new bool[G->V]();
//   DFS(G,0,Visited_node);
//   delete []Visited_node;
//   cout <<"\n";
//   BFS(G,0);
//   cout <<"\n";
//
//   deleteGraph(G);
// }
