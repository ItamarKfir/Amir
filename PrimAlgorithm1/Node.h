#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
#include <String> 

using namespace std;

class Node
{
private:
	int vertex;
	int priority;
public:
	Node(int _vertex = -1, int _priority = INT32_MAX) { vertex = _vertex; priority = _priority; }
	int GetPriority() { return priority; }
	int GetVertex() { return vertex; }
	void SetPriority(int _p) { priority = _p; }
	void SetVertex(int _v) { vertex = _v; }
};

