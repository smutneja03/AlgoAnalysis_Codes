#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
  
// a structure to represent a weighted edge in graph
struct Edge
{
  int src, dest, weight;
};
 
// a structure to represent a connected, undirected and weighted graph
struct Graph
{
    // V-> Number of vertices, E-> Number of edges
    int V, E;
 
    // graph is represented as an array of edges. Since the graph is
    // undirected, the edge from src to dest is also edge from dest
    // to src. Both are counted as 1 edge here.
    struct Edge* edge;
};
 
// Creates a graph with V vertices and E edges
struct Graph* createGraph(int V, int E)
{
    struct Graph* graph = (struct Graph*) malloc( sizeof(struct Graph) );
    graph->V = V;
    graph->E = E;
 
    graph->edge = (struct Edge*) malloc( graph->E * sizeof( struct Edge ) );
 
    return graph;
}
 
// A structure to represent a subset for union-find
struct subset
{
    int parent;
    int rank;
};
 
// A utility function to find set of an element i
// (uses path compression technique)
int find(struct subset subsets[], int i)
{
    // find root and make root as parent of i (path compression)
    if (subsets[i].parent != i)
        subsets[i].parent = find(subsets, subsets[i].parent);
 
    return subsets[i].parent;
}
 
// A function that does union of two sets of x and y
// (uses union by rank)
void Union(struct subset subsets[], int x, int y)
{
    int xroot = find(subsets, x);
    int yroot = find(subsets, y);
 
    // Attach smaller rank tree under root of high rank tree
    // (Union by Rank)
    if (subsets[xroot].rank < subsets[yroot].rank)
        subsets[xroot].parent = yroot;
    else if (subsets[xroot].rank > subsets[yroot].rank)
        subsets[yroot].parent = xroot;
 
    // If ranks are same, then make one as root and increment
    // its rank by one
    else
    {
        subsets[yroot].parent = xroot;
        subsets[xroot].rank++;
    }
}
 
// Compare two edges according to their weights.
// Used in qsort() for sorting an array of edges
int myComp(const void* a, const void* b)
{
    struct Edge* a1 = (struct Edge*)a;
    struct Edge* b1 = (struct Edge*)b;
    return a1->weight > b1->weight;
}
 
// The main function to construct MST using Kruskal's algorithm
int KruskalMST(struct Graph* graph,struct Edge result[])
{
    int V = graph->V;
    // struct Edge result[V];  // Tnis will store the resultant MST
    int e = 0;  // An index variable, used for result[]
    int i = 0;  // An index variable, used for sorted edges
 
    // Step 1:  Sort all the edges in non-decreasing order of their weight
    // If we are not allowed to change the given graph, we can create a copy of
    // array of edges
    qsort(graph->edge, graph->E, sizeof(graph->edge[0]), myComp);
 
    // Allocate memory for creating V ssubsets
    struct subset *subsets =
        (struct subset*) malloc( V * sizeof(struct subset) );
 
    // Create V subsets with single elements
    int v;
    for (v = 0; v < V; ++v)
    {
        subsets[v].parent = v;
        subsets[v].rank = 0;
    }
 
    // Number of edges to be taken is equal to V-1
    while (e < V - 1)
    {
        // Step 2: Pick the smallest edge. And increment the index
        // for next iteration
        struct Edge next_edge = graph->edge[i++];
 
        int x = find(subsets, next_edge.src);
        int y = find(subsets, next_edge.dest);
 
        // If including this edge does't cause cycle, include it
        // in result and increment the index of result for next edge
        if (x != y)
        {
            result[e++] = next_edge;
            Union(subsets, x, y);
        }
        // Else discard the next_edge
    }
 
    // print the contents of result[] to display the built MST
    //printf("Following are the edges in the constructed MST\n");
    //for (i = 0; i < e; ++i)
   //printf("%d -- %d == %d\n", result[i].src, result[i].dest,result[i].weight);
    return e;
}
 
struct Graph *constructGraph(int V,int E)
{
  int i;
  struct Graph* graph = createGraph(V, E+(E/4));
  for(i=0;i<E;i++)
    {
      graph->edge[i].src=i;
      graph->edge[i].dest=i+1;
      graph->edge[i].weight=1+rand()%50;
    }
  /*for(i=0;i<E;i++)
    printf("%d-----(%d)----%d\n",graph->edge[i].src,graph->edge[i].weight,graph->edge[i].dest);*/
  return graph;
}

void constructRandom(struct Graph **graph,int maxweight,int newedges)
{
  int E=(*graph)->E;
  int V=(*graph)->V;
  E=E-newedges;
  int i;
  for(i=0;i<newedges;i++)
    {
      (*graph)->edge[E+i].src=rand()%V;
      (*graph)->edge[E+i].dest=rand()%V;
      (*graph)->edge[E+i].weight=maxweight+rand()%50;
    }
}

// Driver program to test above functions
int main()
{
  srand(time(NULL));
  int iteration=0;
  for(iteration=1;iteration<=100;iteration++)
    {
      int V=100+rand()%100;
      int E=V-1;
      struct Graph* graph=constructGraph(V,E);
      int maxweight=0,i,ctot=0,ctotg=0;
      for(i=0;i<E;i++)
	{
	  ctot+=graph->edge[i].weight;
	  if(graph->edge[i].weight>maxweight)
	    maxweight=graph->edge[i].weight;
	}
      int j=0;
      printf("%d ",iteration);
      for(j=0;j<E;j++)
	printf("(%d,%d,%d) ",graph->edge[j].src,graph->edge[j].dest,graph->edge[j].weight);
      printf("%d ",ctot);
      int newedges=E/4;
      constructRandom(&graph,maxweight,newedges);
      struct Edge result[V];
      int e=KruskalMST(graph,result);
      for(i=0;i<e;i++)
	ctotg+=result[i].weight;
      for(j=0;j<e;j++)
	printf("(%d,%d,%d) ",result[j].src,result[j].dest,result[j].weight);
       printf("%d ",ctotg);
      printf("\n----------------------------------------------------------\n");
    }
  return 0;
}
