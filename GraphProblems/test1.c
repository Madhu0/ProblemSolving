#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"utils.c"

#define COMPLIMENT(a) a == 1 ? 0 : 1

int processEdge(int src, int dest, int *color) {
  // printf("edges: %d %d %d %d\n", src, dest, color[src], color[dest]);
  if (color[src] == color[dest]) {
    return -1;
  }
  color[dest] = COMPLIMENT(color[src]);
  return 1;
}

int isBipartriteGraph(Graph *graph) {
  int color[graph->vertices];
  memset(color, -1, sizeof(int) * graph->vertices);
  int visited[graph->vertices];
  memset(visited, 0, sizeof(int) * graph->vertices);
  
  Queue *q;
  q = initQ();

  enqueue(q, 0);
  color[0] = 0;
  while(!isEmptyQ(q)) {
    // Process Vertex currEl
    int currEl = dequeue(q);
    visited[currEl] = 1;

    Node *temp = graph->edgeNodes[currEl];
    while(temp != NULL) {
      int currentVertex = temp->vertex;
      if (visited[currentVertex] != 1) {
        // Process Edge current - temp->vertex
        if (processEdge(currEl, currentVertex, color) == -1) {
          return -1;
        }
        enqueue(q, currentVertex);
      }
      temp = temp->next;
    }
  }
  return 1;
}

int main() {
  Graph *graph;
  int nodes, edges;
  scanf("%d%d", &nodes, &edges);
  printf("Read %d %d\n", nodes, edges);
  // printf("compl: 1 %d\n", COMPLIMENT(1));
  // printf("compl: 0 %d\n", COMPLIMENT(0));
  graph = readALGraph(nodes, edges);
  printALGraph(graph);
  // bfsALGraph(graph);

  // printf("BiPartrite Graph: %d\n", isBipartriteGraph(graph));
  
  dfsInit(graph);

  // int **amGraph;
  // amGraph = readAMGraph(nodes, edges);
  // printAMGraph(amGraph, nodes);

  return 0;
}