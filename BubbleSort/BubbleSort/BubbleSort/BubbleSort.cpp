// BubbleSort.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"
#include <stdio.h>

void BubbleSort(int DataSet[], int Length)
{
	int i = 0;
	int j = 0;
	int temp = 0;

	for ( i = 0; i < Length - 1; i++)
	{
		for ( j = 0; j < Length - (i+1); j++)
		{
			if (DataSet[j] > DataSet[j+1])
			{
				temp = DataSet[j + 1];
				DataSet[j + 1] = DataSet[j];
				DataSet[j] = temp;
			}
		}
	}
}

int main()
{
	int DataSet[] = { 6,4,2,3,1,5 };
	int Length = sizeof(DataSet) / sizeof(DataSet[0]);
	int i = 0;
	BubbleSort(DataSet, Length);

	for ( i = 0; i < Length; i++)
	{
		printf("%d", DataSet[i]);
	}

	printf("\n");

    return 0;
}

