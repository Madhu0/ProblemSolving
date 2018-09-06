#include <stdio.h>
#include <stdlib.h>
#include "graphUtils.h"

int main() {
    struct Graph *graph;
    graph = scanGraph();
    printGraph(graph);
    return 0;
}