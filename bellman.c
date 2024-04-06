#include <stdio.h>
#include <stdlib.h>
#define INFINITY 9999
struct edge
{
    int u ,v,w;
};

struct graph
{
    int V , E;
    struct edge *ed;
};

void bellmanford(struct graph *g, int source);
void display(int arr[], int size);

int main()
{
    struct graph *g;
    printf("\n");
    g = (struct graph *) malloc (sizeof(struct graph));
    g -> E = 9;
    g -> V = 5;
   
    g -> ed = (struct edge *) malloc(g -> E * sizeof(struct edge));
   
    //edge 0
    //0 to 1
   
    g -> ed[0].u = 0;
    g -> ed[0].v = 1;
    g -> ed[0].w = 4;
   
    //edge 1
    //0 to 2
   
    g -> ed[1].u = 0;
    g -> ed[1].v = 2;
    g -> ed[1].w = 5;
   
    //edge 2
    //2 to 1
   
    g -> ed[2].u = 2;
    g -> ed[2].v = 1;
    g -> ed[2].w = -2;
   
    //edge 3
    //2 to 3
   
    g -> ed[3].u = 2;
    g -> ed[3].v = 3;
    g -> ed[3].w = 4;
   
    //edge 4
    //1 to 4
    g -> ed[4].u = 1;
    g -> ed[4].v = 4;
    g -> ed[4].w = -3;

    //edge 5
    //1 to 3
    g -> ed[5].u = 1;
    g -> ed[5].v = 3;
    g -> ed[5].w = 5;
   
    //edge 6
    //3 to 2
    g -> ed[6].u = 3;
    g -> ed[6].v = 2;
    g -> ed[6].w = -2;
   
    //edge 7
    //4 to 3
   
    g -> ed[7].u = 4;
    g -> ed[7].v = 3;
    g -> ed[7].w = 6;
   
    //edge 8
    //2 to 4
   
    g -> ed[8].u = 2;
    g -> ed[8].v = 4;
    g -> ed[8].w = -3;
   
    bellmanford(g, 0);
   
    return 0;
}

void bellmanford(struct graph *g, int source)
{
    int i , j , u , v , w;
    int tV , tE; //total vertices and total edges
   
    tV = g->V;
    tE = g->E;
   
    int d[tV];
   
    for(i=0; i<tV;i++)
    {
        d[i] = INFINITY;
    }
    d[source] = 0;
   
    for (i = 1; i <= tV - 1; i++)
    {
       for (j = 0; j < tE; j++)
        {
     
            u = g->ed[j].u;
            v = g->ed[j].v;
            w = g->ed[j].w;

            if (d[v] > d[u] + w)
            {
                d[v] = d[u] + w;
            }
        }
    }
    printf("Array :");
    display(d, tV);
}

void display(int arr[], int size)
{
  int i;
  for (i = 0; i < size; i++)
  {
    printf("%d ", arr[i]);
  }
  printf("\n");
}

