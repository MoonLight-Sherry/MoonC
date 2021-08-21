//用数组equiveClass[i]存放包含i的等价类



int* equiveClass;
int n;

void initialize(int NumOfElements)
{
	n = NumOfElements;
	equiveClass = new int[n + 1];
	for (int i = 0; i <= n; i++)
		equiveClass[i] = i;
}

void unite(int classA, int classB)
{
	for (int k = 1; k <= n; k++)
		if (equiveClass[k] == classB)
			equiveClass[k] = classA;

}


int find(int theElement)
{
	return equiveClass[theElement];
}

