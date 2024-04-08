#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100

// Node structure for the adjacency list
struct Node {
    int data;
    struct Node* next;
};

// Graph representation using an adjacency matrix
struct GraphMatrix {
    int vertices;
    int matrix[MAX_VERTICES][MAX_VERTICES];
};

// Graph representation using an adjacency list
struct GraphList {
    int vertices;
    struct Node* adjList[MAX_VERTICES];
};

// Initialize an adjacency matrix graph with all elements set to 0
void initGraphMatrix(struct GraphMatrix* graph, int vertices) {
    graph->vertices = vertices;
    for (int i = 0; i < vertices; ++i) {
        for (int j = 0; j < vertices; ++j) {
            graph->matrix[i][j] = 0;
        }
    }
}

// Add an edge to the adjacency matrix
void addEdgeMatrix(struct GraphMatrix* graph, int src, int dest) {
    if (src >= 0 && src < graph->vertices && dest >= 0 && dest < graph->vertices) {
        graph->matrix[src][dest] = 1;
        graph->matrix[dest][src] = 1;
    } else {
        printf("Invalid vertices.\n");
    }
}

// Display the adjacency matrix
void displayGraphMatrix(struct GraphMatrix* graph) {
    printf("Adjacency Matrix Representation:\n");
    for (int i = 0; i < graph->vertices; ++i) {
        for (int j = 0; j < graph->vertices; ++j) {
            printf("%d ", graph->matrix[i][j]);
        }
        printf("\n");
    }
}

// Initialize an adjacency list graph with all linked lists set to NULL
void initGraphList(struct GraphList* graph, int vertices) {
    graph->vertices = vertices;
    for (int i = 0; i < vertices; ++i) {
        graph->adjList[i] = NULL;
    }
}

// Add an edge to the adjacency list
void addEdgeList(struct GraphList* graph, int src, int dest) {
    if (src >= 0 && src < graph->vertices && dest >= 0 && dest < graph->vertices) {
        // Create a new node for the destination vertex and add it to the source vertex's list
        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = dest;
        newNode->next = graph->adjList[src];
        graph->adjList[src] = newNode;

        // Create a new node for the source vertex and add it to the destination vertex's list
        newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = src;
        newNode->next = graph->adjList[dest];
        graph->adjList[dest] = newNode;
    } else {
        printf("Invalid vertices.\n");
    }
}

// Display the adjacency list
void displayGraphList(struct GraphList* graph) {
    printf("Adjacency List Representation:\n");
    for (int i = 0; i < graph->vertices; ++i) {
        struct Node* current = graph->adjList[i];
        printf("Vertex %d: ", i);
        while (current != NULL) {
            printf("%d -> ", current->data);
            current = current->next;
        }
        printf("NULL\n");
    }
}

// Breadth-First Search traversal on a graph represented by an adjacency matrix
void BFS(struct GraphMatrix *graph, int i) {
    int q[MAX_VERTICES];    // Queue to store vertices for BFS traversal
    int j;
    int visited[MAX_VERTICES];   // Array to mark visited vertices
    printf("start vertex %d", i);    // Print the starting vertex
    enqueue(i);   // Enqueue the starting vertex
    visited[i] = 1;   // Mark the starting vertex as visited

    // Perform BFS traversal using a while loop until the queue is empty
    while (!isEmpty(q)) {
        int current = dequeue(q);   // Dequeue a vertex from the front of the queue
        printf("%d", current);   // Print the visited vertex

        // Explore adjacent vertices of the current vertex
        for (j = 0; j < graph->vertices; ++j) {
            // Check if there is an edge to vertex j and it has not been visited
            if (graph->matrix[current][j] == 1 && visited[j] == 0) {
                visited[j] = 1;   // Mark vertex j as visited
                enqueue(j);   // Enqueue vertex j for further exploration
            }
        }
    }
}


// Depth-First Search traversal on a graph represented by an adjacency matrix
void DFS(struct GraphMatrix *graph, int i) {
    int j;
    int s[MAX_VERTICES];   // Stack to store vertices for DFS traversal
    int visited[MAX_VERTICES];   // Array to mark visited vertices
    printf("start vertex %d", i);   // Print the starting vertex
    push(s, i);   // Push the starting vertex onto the stack
    visited[i] = 1;   // Mark the starting vertex as visited

    // Perform DFS traversal using a while loop until the stack is empty
    while (isEmpty(s)) {
        int current = pop(s);   // Pop a vertex from the top of the stack
        printf("%d", current);   // Print the visited vertex

        // Explore adjacent vertices of the current vertex
        for (j = 0; j < graph->vertices; ++j) {
            // Check if there is an edge to vertex j and it has not been visited
            if (graph->matrix[current][j] == 1 && visited[j] == 0) {
                push(s, j);   // Push the unvisited adjacent vertex onto the stack
                visited[j] = 1;   // Mark vertex j as visited
            }
        }
    }
}


int main() {
    struct GraphMatrix graphMatrix;
    struct GraphList graphList;

    int vertices, edges, src, dest;

    // Get input for the number of vertices and edges
    printf("Enter the number of vertices: ");
    scanf("%d", &vertices);
    printf("Enter the number of edges: ");
    scanf("%d", &edges);

    // Initialize graph representations
    initGraphMatrix(&graphMatrix, vertices);
    initGraphList(&graphList, vertices);

    // Add edges to the graph representations
    for (int i = 0; i < edges; ++i) {  
        printf("Enter edge %d (source destination): ", i + 1);
        scanf("%d %d", &src, &dest);

        addEdgeMatrix(&graphMatrix, src, dest);
        addEdgeList(&graphList, src, dest);
    }

    // Display graph representations
    displayGraphMatrix(&graphMatrix);
    displayGraphList(&graphList);

    return 0;
}
