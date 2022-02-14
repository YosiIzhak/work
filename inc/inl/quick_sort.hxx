#ifndef QUICK_SORT_HXX
#define QUICK_SORT_HXX

#include <cassert>
#include <iostream>
#include <iomanip>
#include <algorithm>

namespace cpp
{

namespace details_impl
{

template <typename T>
static void findBigger(T* a_array, T& a_pivot, size_t& a_start, size_t& a_last)
{
	while(a_start <= a_last && a_array[a_start] < a_pivot)
	{
		a_start++;
	}
}

template <typename T>
static void findSmaller(T* a_array, T& a_pivot, size_t& a_start, size_t& a_last)
{
	while(!(a_last <= a_start) && !(a_array[a_last] < a_pivot)) 
	{
		a_last--;
	}
}

template <typename T>
static int partition(T* a_array, size_t a_start, size_t a_last, T& a_pivot)
{
    size_t start = a_start + 1;
    size_t last = a_last;

	while(start <= last)
	{
		findBigger( a_array,  a_pivot, start, a_last);	
		
		findSmaller(a_array, a_pivot, a_start, last);

		if(start <= last)
		{
			using std::swap;
			swap(a_array[start], a_array[last]);
		}	
	}

	using std::swap;
	swap(a_pivot,  a_array[last]);
	return last;
}

template <typename T>
T& selectPivot(T* a_array, size_t a_start, size_t a_last)
{
	return a_array[a_start];
}

template <typename T>
static void quickRec(T* a_array, size_t a_start, size_t a_last)
{
	if(a_start >= a_last)
	{
		return;
	}
	
	T& pivot = selectPivot(a_array, a_start, a_last);
	size_t pivotIndex = partition(a_array, a_start, a_last, pivot);
	if(pivotIndex >= 1)
	{
		quickRec(a_array, a_start, pivotIndex -1);
	}
	quickRec(a_array, pivotIndex + 1, a_last);
}


} //details_impl namespace

template <typename T>
inline void quickSort(T* a_array, size_t a_length)
{
	if(!a_array || a_length < 2)
	{
		return;
	}

	details_impl::quickRec(a_array, 0, a_length -1);	
}


} //cpp namespace

#endif // QUICK_SORT_HXX