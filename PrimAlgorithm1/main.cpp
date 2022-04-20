#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
#include "Graph.h"
#include "PrioritiesQueue.h"

int primAlgorithm(int size, Graph g);

void main()
{
	int* edges; // Vertex '0' is not an actual Vertex in the graph, buy indicates the father of the arbitrary
	Graph g;
	int V = 8;

	g.MakeEmptyGraph(V);
	g.AddEdge(8,7,4);
	g.AddEdge(7,6,3);
	g.AddEdge(6,5,1);
	g.AddEdge(5,8,5);
	g.AddEdge(5,4,1);
	g.AddEdge(5,2,2);
	g.AddEdge(1,2,2);
	g.AddEdge(4,2,4);
	g.AddEdge(4,3,4);
	g.AddEdge(2,3,3);

	primAlgorithm(V, g);

	/*Graph* g = new Graph;
	g->MakeEmptyGraph(6);
	g->AddEdge(1, 2, 9);
	g->AddEdge(1, 3, 19);
	g->AddEdge(1, 4, 29);
	g->AddEdge(1, 6, 3);
	g->AddEdge(2, 3, 5);
	g->AddEdge(2, 4, 12);
	g->AddEdge(4, 5, 1);
	g->AddEdge(6, 5, 17);
	g->AddEdge(6, 1, 21);
	cout << g->GetEdgeWeight(1, 5) << endl;
	//g->print();
	AlgoKruskal A;
	A.SetVars(g, 6);
	A.RunKruskalAlgo();
	A.PrintMSTEdges();
	delete g;*/
	
}


int primAlgorithm(int V, Graph g)
{
	srand(time(nullptr));
	PrioritiesQueue q(V);
	bool* inTree = new bool[V]();
	int* minWeightsArray = new int[V];
	int randomVertexToStart = (rand() % V) +1;
	int* parentsArray = new int[V]();
 	constexpr int INF = INT32_MAX;
	Edge* currEdge;
	int tempVertex = -2;

	for (size_t i = 0; i < V; i++)
	{
		minWeightsArray[i] = INF; // initiate to infinity
		parentsArray[i] = 0;
	}

	minWeightsArray[randomVertexToStart-1] = 0;

	q.Build(V, minWeightsArray);

	while (!q.IsEmpty())
	{
		tempVertex = q.DeleteMin().GetVertex();
		inTree[tempVertex - 1] = true;
		currEdge = g.GetAdjList(tempVertex);

		while (currEdge != NULL)
		{
			/*cout << currEdge->Ver;*/

			if (!inTree[currEdge->Ver_v-1] && currEdge->ArcSize < minWeightsArray[currEdge->Ver_v - 1])
			{
				minWeightsArray[currEdge->Ver_v - 1] = currEdge->ArcSize;
				parentsArray[currEdge->Ver_v - 1] = tempVertex;
				q.DecreaseKey(currEdge->Ver_v - 1, minWeightsArray[currEdge->Ver_v - 1]);
			}
			currEdge = currEdge->Next;
		}
	}

	cout << endl;
	for (size_t i = 0; i < V; i++)
	{
		cout << parentsArray[i] << "-->" << i + 1 << endl;
	}

	//delete inTree;
	//delete minWeightsArray;

	return 0;
}
