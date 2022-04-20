#pragma once
#pragma once
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include "GraphDS.h"
using namespace std;
struct Tree
{
	int size;
	int Parent;
	Ver* V;
};

class Disjoint
{
public:
	Disjoint(int _Size);
	void MakeSet(Ver* _ver);
	int Find(int u);
	void Union(int u, int v);
	~Disjoint();

	//Delete before submit
	void print();

private:
	Tree* A;
	int Size;

};

