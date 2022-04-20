#include "PrioritiesQueue.h"

PrioritiesQueue::PrioritiesQueue(int _heapSize)
{
	heapSize = _heapSize;
	InitHeap();
}

void PrioritiesQueue::Build(int heapSize, int* minArray)
{
	for (int i = 0; i < heapSize; i++) 
	{
		dataArray[i].SetPriority(minArray[i]);
		dataArray[i].SetVertex(i+1);  // includes the arbitrary 0 vertex
	}

	for (size_t i = 0; i < heapSize; i++)
	{
		indexesArray[i] = i;
	}

	for (int i = (heapSize / 2) - 1; i >= 0; i--) // Floyed algorithm
	{
		FixHeap(i); 
	}
}

void PrioritiesQueue::DecreaseKey(int index, int newPriority)
{
	dataArray[indexesArray[index]].SetPriority(newPriority); 
	FixHeapUpWards(indexesArray[index]); 
}

void PrioritiesQueue::InitHeap()
{
	dataArray = new Node[heapSize];
	indexesArray = new int[heapSize]; 
}

int PrioritiesQueue::Parent(int i)
{
	if (i == 0)
		return 0;

	if (i % 2)
	{
		return i / 2;
	}
	else
		return (i / 2) - 1;
}

void PrioritiesQueue::Swap(int a, int b)
{
	Node tempNode = dataArray[a];
	dataArray[a] = dataArray[b];
	dataArray[b] = tempNode;

	int tempIndex = indexesArray[dataArray[a].GetVertex() - 1];
	indexesArray[dataArray[a].GetVertex() - 1] = indexesArray[dataArray[b].GetVertex() - 1];
	indexesArray[dataArray[b].GetVertex() - 1] = tempIndex;
}

Node PrioritiesQueue::DeleteMin()
{
	Node temp = dataArray[0];
	heapSize--;

	dataArray[0] = dataArray[heapSize];
	indexesArray[dataArray[heapSize].GetVertex()-1] = 0;

	FixHeap(0);
	return temp;
}

void PrioritiesQueue::FixHeapUpWards(int idx)
{
	while(idx > 0 && dataArray[Parent(idx)].GetPriority() > dataArray[idx].GetPriority())
	{
		Swap(idx, Parent(idx));
		idx = Parent(idx);
	}
}

void PrioritiesQueue::FixHeap(int idx)
{
	int min;
	int L = Left(idx);
	int R = Right(idx);

	if (L != -1 && (dataArray[L].GetPriority() < dataArray[idx].GetPriority()))
		min = L;
	else
		min = idx;

	if (R != -1 && (dataArray[R].GetPriority() < dataArray[min].GetPriority()))
		min = R;

	if (min != idx)
	{
		Swap(idx, min);
		FixHeap(min);
	}
}

int PrioritiesQueue::Left(int i)
{
	if ((2 * i + 1) < heapSize)
	{
		return ((2 * i) + 1);
	}
	return -1;
}

int PrioritiesQueue::Right(int i)
{
	if ((2 * i + 2) < heapSize)
	{
		return ((2 * i) + 2);
	}

	return -1;
}

PrioritiesQueue::~PrioritiesQueue()
{
	delete dataArray;
	delete indexesArray;
}