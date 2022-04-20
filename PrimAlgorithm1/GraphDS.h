#pragma once

struct Edge
{
	int Ver_u;
	int Ver_v;
	int ArcSize;
	Edge* Next;
};

struct Ver
{
	int Ver;
	int NumOfEdges;
	Edge* Next;
};
