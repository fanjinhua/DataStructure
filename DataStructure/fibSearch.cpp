typedef size_t Rank;

class Fib 
{ //Fibonacci������
private:
	int f, second; //f = fib(k - 1), g = fib(k)����Ϊint�ͣ��ܿ�ͻ���ֵ���
public:
	Fib(int n) //��ʼ��Ϊ��С��n����СFibonacci��
	{
		f = 1; second = 0; while (second < n) next();
	} //fib(-1), fib(0)��O(log_phi(n))ʱ��
	int get() { return second; } //��ȡ��ǰFibonacci�O(1)ʱ��
	int next() { second += f; f = second - f; return second; } //ת����һFibonacci�O(1)ʱ��
	int prev() { f = second - f; second -= f; return second; } //ת����һFibonacci�O(1)ʱ��
};
template<typename T>
static Rank fibSearch(T* A, const T& e, Rank lo, Rank hi)
{
	Fib fib(hi - lo);
	while (lo < hi)
	{
		while (hi - lo < fib.get())
			fib.prev();
		Rank mi = lo + fib.get() - 1;
		if (e < A[mi])
			hi = mi;
		else if (A[mi] < e)
			lo = mi + 1;
		else
			return mi;
	}
	return -1;
}
/** /
int main()
{
	int A[] = { 1, 2, 3, 4, 5, 6, 7 };
	Rank ret = fibSearch<int>(A, 1, 0, 7);
	return 0;
}
/**/