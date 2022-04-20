#include "Graph.h"

void Graph::MakeEmptyGraph(int n)
{
	Gr = new Ver * [n];
	GraphSize = n;
	for (int i = 0; i < GraphSize; i++)
	{
		Gr[i] = new Ver;
		Gr[i]->Ver = i + 1;
		Gr[i]->NumOfEdges = 0;
		Gr[i]->Next = nullptr;
	}
}

bool Graph::IsAdjacent(int u, int v)
{
	Edge* temp = Gr[u - 1]->Next;
	while (temp != nullptr)
	{
		if (temp->Ver_v == v)
			return true;
		temp = temp->Next;
	}
	return false;
}

Edge* Graph::GetAdjList(int u)
{
	return Gr[u - 1]->Next;
}

Edge* Graph::GenerateEdge(int u, int v, int s)
{
	Edge* NewEdge = new Edge;
	NewEdge->Ver_v = v;
	NewEdge->Ver_u = u;
	NewEdge->ArcSize = s;
	NewEdge->Next = nullptr;
	return NewEdge;
}
void Graph::AddOneDirEdge(int u, int v, int s)
{
	Edge* temp = Gr[u - 1]->Next;
	if (temp == nullptr)
	{
		Gr[u - 1]->Next = GenerateEdge(u, v, s);
	}
	else
	{
		for (int i = 0; i < Gr[u - 1]->NumOfEdges - 1; i++)
		{
			temp = temp->Next;
		}
		temp->Next = GenerateEdge(u, v, s);
	}
	Gr[u - 1]->NumOfEdges++;
}
void Graph::AddEdge(int u, int v, int s)
{
	if (!IsDuplicateEdge(u, v))
	{
		AddOneDirEdge(u, v, s);
		AddOneDirEdge(v, u, s);
	}
}
void Graph::RemoveOneDirEdge(int u, int v)
{
	Edge* next = Gr[u - 1]->Next;
	Edge* prev = nullptr;
	Edge* DelVer = nullptr;
	if (Gr[u - 1]->NumOfEdges == 1)
	{
		DelVer = next;
		Gr[u - 1]->Next = nullptr;
	}
	else
	{
		if (next->Ver_v == v)
		{
			DelVer = next;
			Gr[u - 1]->Next = next->Next;
		}
		else
		{
			while (next->Ver_v != v)
			{
				prev = next;
				next = next->Next;
			}
			prev->Next = next->Next;
		}
	}
	delete DelVer;
	Gr[u - 1]->NumOfEdges--;
}
void Graph::RemoveEdge(int u, int v)
{
	if (GetEdgeWeight(u, v) != -1)
	{
		RemoveOneDirEdge(u, v);
		RemoveOneDirEdge(v, u);
	}
}

void Graph::print()
{
	Edge* temp = nullptr;
	for (int i = 0; i < GraphSize; i++)
	{
		temp = Gr[i]->Next;
		cout << i + 1 << ": ";

		while (temp != nullptr)
		{
			cout << " --> (" << temp->Ver_v << " , " << temp->ArcSize << ")";
			temp = temp->Next;
		}
		cout << endl;
	}
}

bool Graph::IsDuplicateEdge(int u, int v)
{
	Edge* next = Gr[u - 1]->Next;
	for (int i = 0; i < Gr[u - 1]->NumOfEdges; i++)
	{
		if (next->Ver_v == v)
			return true;
		else
			next = next->Next;
	}
	return false;
}
Ver* Graph::GetVertex(int u)
{
	return Gr[u - 1];
}
Graph::~Graph()
{
	Edge* next = nullptr;
	Edge* prev = nullptr;

	for (int i = 0; i < GraphSize; i++)
	{
		next = Gr[i]->Next;
		for (int j = 0; j < Gr[i]->NumOfEdges; j++)
		{
			prev = next;
			next = next->Next;
			delete prev;
		}
		delete Gr[i];
	}
	delete Gr;
}

int Graph::GetEdgeWeight(int u, int v)
{
	Edge* Ed = GetAdjList(u);
	while (Ed != nullptr)
	{
		if (Ed->Ver_v == v)
			return Ed->ArcSize;
		Ed = Ed->Next;
	}
	return -1;
}
