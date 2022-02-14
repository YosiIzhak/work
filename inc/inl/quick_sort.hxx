#ifndef QUICK_SORT_HXX
#define QUICK_SORT_HXX
#include <cstdlib> //size_t
#include <iostream>
namespace cpp
{

template <typename T>

static void swap(T* a_array, size_t a_left, size_t a_right)
{
    T temp = a_array[a_left];
    a_array[a_left] = a_array[a_right];
    a_array[a_right] = temp;
}
template <typename T>
bool operator<(const Ball &x, const Ball &y)
{
    return x.getRadius() < y.getRadius();
}

template <typename T>
bool operator>(const Ball &x, const Ball &y)
{
    return x.getRadius() > y.getRadius();
}

template <typename T>
bool operator<=( Ball x,  Ball y)
{
    return x.getRadius() <= y.getRadius();
}
template <typename T>
static int partition(T* a_array, size_t a_begin, size_t a_end)
{
	size_t pivot = a_begin, left = a_begin + 1, right = a_end;
	T pivotVal = a_array[pivot];
    T leftVal = a_array[left];
    T rightVal = a_array[right];
	
	while(left <= right){
		while(left <= right && leftVal <= pivotVal)
        {
			left++;
			leftVal = a_array[left];
		}
		while(rightVal > pivotVal)
        {  
			right--;
            rightVal = a_array[right];
		}
		if(left < right)
        {
			swap(a_array, left, right);
            leftVal = a_array[left];
            rightVal = a_array[right];
		}			
	}

	swap(a_array, pivot, right);	
	pivot = right;
	return pivot;
}

template <typename T>
static void quickRec(T* a_array , size_t a_begin, size_t a_end)
{
	size_t pivot;	
	if(a_end <= a_begin ){
		return;
	}
	pivot = partition(a_array, a_begin, a_end);
	if(pivot > 0){
		quickRec(a_array, a_begin, pivot-1);
	}
	if(pivot < a_end){
		quickRec(a_array, pivot+1, a_end);	
	}
}

/******* QUICK_SORT ****************/
template <typename T>
ErrQuick quickSort (T* a_array, size_t a_size)
{
	if(a_array == NULL){
		return QUICK_NOT_INITIALIZED;
	}
	if(a_size <= 1){
		return QUICK_SIZE_TOO_SMALL;
	}
	quickRec(a_array, 0, a_size-1);
	return QUICK_OK;
}
template <typename T>
void charPrint(T* a_array,size_t a_size)
{
    for(size_t i = 0; i< a_size; i++)
    {
        printf("%c ", char(a_array[i]));
    }
}

template <typename T>
void quickPrint(T* a_array,size_t a_size)
{
    for(size_t i = 0; i< a_size; i++)
    {
        printf("%d ", a_array[i].getRadius());
    }
}

}//end of namespace

#endif