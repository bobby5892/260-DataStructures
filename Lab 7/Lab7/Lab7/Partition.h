#pragma once
//
int findMedian(int values[], int SIZE);
int recFindMedian(int a[], int first, int last);

int findMedian(int values[], int SIZE) {
	 recFindMedian(values, 0, SIZE-1);
	 return values[SIZE / 2];
}

void recQuickSort(int a[], int first, int last)
{
	// if the array is longer than length 1
	// partition it, then QuickSort each sub-array
	if (first < last)
	{
		// partition, then get index of properly placed pivot
		int pivot = recFindMedian(a, first, last);

		//now sort each sub-array
		recQuickSort(a, first, pivot - 1);
		recQuickSort(a, pivot + 1, last);
	}
}  
int recFindMedian(int a[], int first, int last)
{
	int  p = first;
	int pivotElement = a[first];

	for (int i = first + 1; i <= last; i++)
	{
		/* If you want to sort the list in the other order, change "<=" to ">" */
		if (a[i] <= pivotElement)
		{
			p++;
			std::swap(a[i], a[p]);
		}
	}
		std::swap(a[p], a[first]);
	return p;
}
