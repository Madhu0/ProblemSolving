//
// Created by Madhu on 30/04/18.
//

#include <stdlib.h>
#include <stdio.h>

struct Edge {
    int source, dest, weight;
};

struct Graph{
    int V, E;
    struct Edge *edges;
};

/**
 * Creates a graph from given edges, assuming vertices are designated with digits starting from 1
 * @param edges Edges in format of 2D array { source, destination, weights }
 * @param numberOfVertices number of vertices in the graph
 * @param numberOfEdges Number of edges in the graph
 * @return Returns the pointer to newly created graph
 */
struct Graph * createGraph(int **edges, int numberOfVertices, int numberOfEdges) {
    struct Graph *graph;
    graph = (struct Graph *)malloc(sizeof(struct Graph));
    graph->V = numberOfVertices;
    graph->E = numberOfEdges;
    graph->edges = (struct Edge *)malloc(sizeof(struct Edge) * numberOfEdges);

    int i;
    for(i = 0; i < numberOfEdges; i++) {
        struct Edge edge;
        edge.source = edges[0][i];
        edge.dest = edges[1][i];
        edge.weight = edges[2][i];
        graph->edges[i] = edge;
    }

    return graph;
}

/**
 * Prints the given graph
 * @param graph Graph
 */
void  printGraph(struct Graph *graph) {
    for(int i = 0; i < graph->E; i++) {
        printf("Edge: %d - %d Weight %d\n", graph->edges[i].source, graph->edges[i].dest, graph->edges[i].weight);
    }
}

struct Graph * scanGraph() {
    int **edges, noOfEdges, i, noOfVertices;
    printf("Enter number of vertices and edges: ");
    edges = (int **)malloc(sizeof(int *) * 3);
    scanf("%d%d", &noOfVertices, &noOfEdges);
    for(i = 0; i < 3; i++) {
        edges[i] = (int *)malloc(sizeof(int) * noOfEdges);
    }
    for(i = 0; i < noOfEdges; i++) {
        scanf("%d%d%d", &edges[0][i], &edges[1][i], &edges[2][i]);
    }
    return createGraph(edges, noOfVertices, noOfEdges);
}