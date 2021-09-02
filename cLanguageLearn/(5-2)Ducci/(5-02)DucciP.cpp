#include <string>
#include <set>
#include <cmath>
#include <iostream>
#include <sstream>
#include <cstring>

using namespace std;

#define maxn 20

int groupElements[maxn];
int absElements[maxn];
char allZero[maxn];
string elementsChangedString;
set<string> stringSet;

//转换成字符串存在集合里面，从而比较数组是否相等
void change(int *groupElements, int elementSum)
{
	stringstream elements;
	for (int i = 0; i < elementSum; i++)
	{
		elements << groupElements[i];
		elementsChangedString = elements.str();
	}
}

int main()
{
	int totalGroupCount = 0; int elementCount = 0;
	cin >> totalGroupCount;
	while (totalGroupCount--)
	{
		cin >> elementCount; int i = 0; int elementSum = 0;
		elementSum = elementCount;
		while (elementCount--)
		{
			cin >> groupElements[i];
			i++;
		}

		change(groupElements, elementSum);//转换成字符串存在集合里面
		stringSet.insert(elementsChangedString);

		for (int i = 0; i < elementSum; i++)//构造全0的字符串
		{
			allZero[i] = '0';
		}

		while (1)
		{
			for (int i = 0; i < elementSum; i++)
			{
				if (i != elementSum - 1) absElements[i] = abs(groupElements[i] - groupElements[i + 1]);
				if (i == elementSum - 1) absElements[i] = abs(groupElements[i] - groupElements[0]);
			}
			change(absElements, elementSum);//转换成字符串存在集合里面
			memcpy(groupElements, absElements, sizeof(absElements));//copy new abs
			if (elementsChangedString == allZero) { cout << "ZERO" << endl; break; }
			if (find(stringSet.begin(), stringSet.end(), elementsChangedString) == stringSet.end()) { stringSet.insert(elementsChangedString); }
			else { cout << "LOOP" << endl; break; }
		}
	}
	return 0;
}
