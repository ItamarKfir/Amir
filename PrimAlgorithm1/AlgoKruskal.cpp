#include "AlgoKruskal.h"

void AlgoKruskal::SetVars(Graph* _Gr, int _NumberOfNodes)
{
	Gr = _Gr;
	MST_Arr_i = 0;
	MST = new Edge * [_NumberOfNodes - 1];
	NumberOfNodes = _NumberOfNodes;
	CalNumberOfGraphEdges();
	SetEdgeArray();
}
void AlgoKruskal::Swap(int First_i, int Second_i)
{
	Edge* temp = EdgeArr[First_i];
	EdgeArr[First_i] = EdgeArr[Second_i];
	EdgeArr[Second_i] = temp;
}
int AlgoKruskal::Partition(int Start, int End)
{
	int pivot = EdgeArr[Start]->ArcSize;
	int count = 0;
	for (int i = Start + 1; i <= End; i++) {
		if (EdgeArr[i]->ArcSize <= pivot)
			count++;
	}

	int pivotIndex = Start + count;
	Swap(pivotIndex, Start);

	int i = Start, j = End;

	while (i < pivotIndex && j > pivotIndex) {

		while (EdgeArr[i]->ArcSize <= pivot) {
			i++;
		}

		while (EdgeArr[j]->ArcSize > pivot) {
			j--;
		}

		if (i < pivotIndex && j > pivotIndex) {
			Swap(i++, j--);
		}
	}
	return pivotIndex;
}

void AlgoKruskal::QuickSort(int Start, int End)
{
	if (Start >= End)
		return;
	int p = Partition(Start, End);

	QuickSort(Start, p - 1);
	QuickSort(p + 1, End);
}
void AlgoKruskal::SetEdgeArray()
{
	Edge* Ed = nullptr;
	EdgeArr = new Edge * [NumberOfEdges];
	int EdgeArrIndex = 0;
	for (int i = 0; i < NumberOfNodes; i++)
	{
		Ver* v = Gr->GetVertex(i + 1);
		Ed = v->Next;
		for (int j = 0; j < v->NumOfEdges; j++)
		{
			if (Ed->Ver_u < Ed->Ver_v)
			{
				EdgeArr[EdgeArrIndex] = Ed;
				EdgeArrIndex++;
			}
			Ed = Ed->Next;
		}
	}
	NumberOfEdges = EdgeArrIndex;
}
void AlgoKruskal::CalNumberOfGraphEdges()
{
	NumberOfEdges = 0;
	Ver* v;
	for (int i = 0; i < NumberOfNodes; i++)
	{
		Ver* v = Gr->GetVertex(i + 1);
		NumberOfEdges += v->NumOfEdges;
	}
}
void AlgoKruskal::SetDisjointSets()
{
	UF = new Disjoint(NumberOfNodes);
	for (int i = 0; i < NumberOfNodes; i++)
	{
		UF->MakeSet(Gr->GetVertex(i + 1));
	}
}

void AlgoKruskal::PrintEdgeArr()
{
	for (int i = 0; i < NumberOfEdges; i++)
	{
		cout << EdgeArr[i]->ArcSize << " <-> (" << EdgeArr[i]->Ver_u << " , " << EdgeArr[i]->Ver_v << ")." << endl;
	}
}

void AlgoKruskal::PrintMSTEdges()
{
	for (int i = 0; i < MST_Arr_i; i++)
	{
		cout << MST[i]->ArcSize << " <-> (" << EdgeArr[i]->Ver_u << " , " << EdgeArr[i]->Ver_v << ")." << endl;
	}
}
int AlgoKruskal::RunKruskalAlgo()
{
	int TotalEdgesWeight = 0;
	SetDisjointSets();//Forest
	QuickSort(0, NumberOfEdges - 1); //Sort Edges
	for (int i = 0; i < NumberOfEdges; i++)
	{

		int _u = UF->Find(EdgeArr[i]->Ver_u);
		int _v = UF->Find(EdgeArr[i]->Ver_v);
		if (_u != _v)
		{
			MST[MST_Arr_i] = EdgeArr[i];
			UF->Union(_u, _v);
			TotalEdgesWeight += EdgeArr[i]->ArcSize;
			MST_Arr_i++;
		}
	}
	return TotalEdgesWeight;
}

AlgoKruskal::~AlgoKruskal()
{
	delete EdgeArr;
	delete UF;
	delete MST;
}
