template<typename T>
void merge(const T* A, int lo, int mi, int hi)
{
	int len_b = mi - lo; T* B = new T[len_b];
	for (int i = 0; i < lb; B[i] = A[i++]); // 复制前子向量
	int len_c = hi - mi; T* C = A + mi;
	for (int a = 0, b = 0, c = 0; (b < len_b) || (c < len_c);)
	{						// 短路求值	
		if ((b < len_b) && (len_c <= c || (B[b] <= C[c])))
			A[a++] = B[b++];
		if ((c < len_c) && (len_b <= b || (B[b] > C[c])))
			A[a++] = C[c++];
	}
	delete[] B;
}

template<typename T>
void merge_sort(const T* A, int lo, int hi)
{
	if (hi - lo < 2)
		return;
	int mi = (hi - lo) >> 2;
	merge_sort(lo, mi);
	merge_sort(mi, hi);
	merge(T, lo, mi, hi);
}
