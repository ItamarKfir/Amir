#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
#include "Node.h"

using namespace std;

class PrioritiesQueue
{
private:
	int heapSize;
	Node* dataArray = nullptr;
	int* indexesArray = nullptr;

public:
	PrioritiesQueue(int _heapSize);

	void Build(int HeapSize, int* minArray);
	bool IsEmpty() { return heapSize == 0; }
	void DecreaseKey(int index, int newPriority);
	Node DeleteMin();// Return and Delete the min Node vertex

	void InitHeap();
	void Swap(int i, int j);
	void FixHeap(int i);
	void FixHeapUpWards(int idx);

	int Parent(int i);
	int Left(int i);
	int Right(int i);
	~PrioritiesQueue();
};