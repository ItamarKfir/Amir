#pragma once
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include "GraphDS.h"
using namespace std;

class Graph
{
public:
	void MakeEmptyGraph(int n);
	bool IsAdjacent(int u, int v);
	Edge* GetAdjList(int u);
	void AddEdge(int u, int v, int s);
	void RemoveEdge(int u, int v);
	Ver* GetVertex(int u);
	int GetEdgeWeight(int u, int v);
	~Graph();
	//Delete Before submit project
	void print();

private:
	Edge* GenerateEdge(int u, int v, int s);
	void AddOneDirEdge(int u, int v, int s);
	void RemoveOneDirEdge(int u, int v);
	bool IsDuplicateEdge(int u, int v);



private:
	Ver** Gr;
	int GraphSize;
};

