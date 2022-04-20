#include "Disjoint.h"

Disjoint::Disjoint(int _Size)
{
	Size = _Size;
	A = new Tree[Size];
	for (int i = 0; i < Size; i++)
	{
		A[i].Parent = -1;
		A[i].size = 0;
		A[i].V = nullptr;
	}
}
void Disjoint::MakeSet(Ver* _ver)
{
	A[_ver->Ver - 1].Parent = _ver->Ver;
	A[_ver->Ver - 1].size = 1;
}
int Disjoint::Find(int u)
{
	if (A[u - 1].Parent == u)
	{
		return u;
	}
	else
	{
		return (A[u - 1].Parent = Find(A[u - 1].Parent));
	}
}
void Disjoint::Union(int u, int v)
{
	int Rep_u = Find(u);
	int Rep_v = Find(v);
	if (A[Rep_u].size > A[Rep_v].size)
	{
		A[Rep_v - 1].Parent = Rep_u;
		A[Rep_u - 1].size += A[Rep_v - 1].size;
	}
	else
	{
		A[Rep_u - 1].Parent = Rep_v;
		A[Rep_v - 1].size += A[Rep_u - 1].size;
	}
}

void Disjoint::print()
{
	for (int i = 0; i < Size; i++)
	{
		if (A[i].Parent != -1)
			cout << i + 1 << ": " << "Parent: " << A[i].Parent << "   , Size: " << A[i].size << endl;
	}
}
Disjoint::~Disjoint()
{
	delete A;
}
