#pragma once
#include "Graph.h"
#include "Disjoint.h"

class AlgoKruskal
{

public:
	void SetVars(Graph* _Gr, int _NumberOfNodes);
	void QuickSort(int Start, int End);
	int Partition(int Start, int End);
	void Swap(int First_i, int Second_i);
	void SetEdgeArray();
	void SetDisjointSets();
	void CalNumberOfGraphEdges();
	int RunKruskalAlgo();

	~AlgoKruskal();
	//Delete before Submit
	void PrintEdgeArr();
	void PrintMSTEdges();

private:
	Edge** EdgeArr;
	Edge** MST;

	Graph* Gr;
	Disjoint* UF;
	int NumberOfNodes;
	int NumberOfEdges;
	int MST_Arr_i;

};

