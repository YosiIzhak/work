#ifndef QUICK_SORT_HXX
#define QUICK_SORT_HXX

#include <cassert>
#include <iostream>

namespace cpp
{

namespace details_impl
{

template <typename T>
static void swap(T& a, T& b)
{
	T temp = a;
	a = b;
	b = temp;
}

template <typename T>
static int partition(T* a_array, size_t a_start, size_t a_last, T& a_pivot)
{
    size_t start = a_start + 1;
    size_t last = a_last;
	T leftItem;
	T rightItem;
   
	while(start <= last)
	{
		rightItem =  a_array[last];
    	leftItem =  a_array[start];
		
		while(start <= a_last && leftItem <= a_pivot)
		{
			start++;
            leftItem = a_array[start];
		}
		
		while(last > a_start && rightItem > a_pivot)
		{
			last--;
            rightItem = a_array[last];
		}

		if(start <= last)
		{
			a_array[last] = leftItem;
            a_array[start] = rightItem;
		}	
	}

	swap(a_pivot,  a_array[last]);
	return last;
}

template <typename T>
T& selectPivot(T* a_array, size_t a_start, size_t a_last)
{
	return a_array[a_start];
}

template <typename T>
static void quickSortRec(T* a_array, size_t a_start, size_t a_last)
{
	if(a_start >= a_last)
	{
		return;
	}
	
	T& pivot = selectPivot(a_array, a_start, a_last);
	size_t pivotIndex = partition(a_array, a_start, a_last, pivot);
	if(pivotIndex >= 1)
	{
		quickSortRec(a_array, a_start, pivotIndex -1);
	}
	quickSortRec(a_array, pivotIndex + 1, a_last);
}


} //details_impl namespace

template <typename T>
inline void quickSort(T* a_array, size_t a_length)
{
	details_impl::quickSortRec(a_array, 0, a_length -1);	
}


} //cpp namespace

#endif // QUICK_SORT_HXX