#include "Vector.h"

template<typename T>
bool Vector<T>::bubble(Rank lo, Rank hi)
{
	bool sorted = true;
	while (++lo < hi)
	{
		if (_elem[lo - 1] > _elem[lo])
		{
			sorted = false;
			swap_elem(_elem[lo - 1], _elem[lo]);
		}
	}
	return sorted;
}

template<typename T>
inline void Vector<T>::bubbleSort(Rank lo, Rank hi)
{
	while (!bubble(lo, hi--));
}
