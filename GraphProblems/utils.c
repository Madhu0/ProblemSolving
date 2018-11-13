#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "../libutils.h"

typedef struct node {
  int vertex;
  struct node *next;
} Node;

typedef struct {
  int vertices;
  int edges;
  Node **edgeNodes;
} Graph;

Graph * initiateGraph(int vertices, int edges) {
  Graph *graph;
  graph = (Graph *)malloc(sizeof(Graph));
  graph->vertices = vertices;
  graph->edges = edges;
  graph->edgeNodes = (Node **)malloc(sizeof(Node *) * vertices);
  for(int i = 0; i < vertices; i++) {
    graph->edgeNodes[i] = NULL;
  }
  return graph;
}

Node* createNode(int val) {
  Node *node;
  node = (Node *)malloc(sizeof(Node));
  node->vertex = val;
  node->next = NULL;
  return node;
}

void addEdge(Graph *graph, int source, int dest) {
  if (graph->edgeNodes[source] == NULL) {
    graph->edgeNodes[source] = createNode(dest);
  } else {
    Node *temp;
    temp = graph->edgeNodes[source];
    while(temp->next != NULL) {
      temp = temp->next;
    }
    temp->next = createNode(dest);
  }
}

Graph* readALGraph(int vertices, int edges) {
  Graph *graph = initiateGraph(vertices, edges);
  int i;
  for(i = 0; i < edges; i++) {
    int v1, v2;
    scanf("%d%d", &v1, &v2);
    printf("Read %d %d\n", v1, v2);
    addEdge(graph, v1, v2);
  }
  return graph;
}

void printALGraph(Graph *graph) {
  int i;
  for(i = 0; i < graph->vertices; i++) {
    Node *temp;
    temp = graph->edgeNodes[i];
    printf("%d ::", i);
    while(temp != NULL) {
      printf(" -> %d", temp->vertex);
      temp = temp->next;
    }
    printf("\n");
  }
}

int ** readAMGraph(int noOfVertices, int noOfEdges) {
  int **graph;
  graph = (int **)malloc(sizeof(int *) * noOfVertices);
  for(int i = 0; i < noOfVertices; i++) {
    graph[i] = (int *)malloc(sizeof(int) * noOfVertices);
    memset(graph[i], 0, sizeof(int) * noOfVertices);
  }
  for(int i = 0; i < noOfEdges; i++) {
    int s, d;
    scanf("%d%d", &s, &d);
    graph[s][d] = 1;
  }
  return graph;
}

void printAMGraph(int **graph, int vertices) {
  int i, j;
  for(i = 0; i < vertices; i++) {
    printf("%d ::", i);
    for(j = 0; j < vertices; j++) {
      if (graph[i][j] == 1) {
        printf(" -> %d", j);
      }
    }
    printf("\n");
  }
}

void bfsALGraph(Graph *graph) {
  Queue *q = initQ();
  int visited[graph->vertices];
  memset(visited, 0, graph->vertices * sizeof(int));
  printf("--BFS--\n");
  int currentEle = 0;
  while(!isEmptyQ(q)) {
    Node *temp = graph->edgeNodes[currentEle];
    visited[currentEle] = 1;
    printf(" %d -> ", currentEle);
    // Process Vertex currentEle
    while(temp != NULL) {
      // printf("\nin enqueue \n");
      // Process Edge currentEle - temp->vertex
      enqueue(q, temp->vertex);
      temp = temp->next;
    }
    currentEle = dequeue(q);
    while(visited[currentEle] == 1 && !isEmptyQ(q)) {
      // printf("\n dequeued element %d %d\n", currentEle, visited[currentEle]);
      currentEle = dequeue(q);
    }
    // printf("\nNextElement %d\n", currentEle);
    // printQ(q);
  }
}

void dfsALGraph(Graph *graph, int start, int *visited) {
  visited[start] = 1;
  printf("%d ", start);
  // Process vertex start
  Node *temp = graph->edgeNodes[start];
  while(temp != NULL) {
    if (visited[temp->vertex] != 1) {
      // Process Edge start - temp->vertex
      dfsALGraph(graph, temp->vertex, visited);
    }
    temp = temp->next;
  }
}

void dfsInit(Graph *graph) {
  int visited[graph->vertices];
  memset(visited, 0, graph->vertices * sizeof(int));
  printf("--DFS--\n");
  dfsALGraph(graph, 0, visited);
  printf("\n");
}