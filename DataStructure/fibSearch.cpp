typedef size_t Rank;

class Fib 
{ //Fibonacci数列类
private:
	int f, second; //f = fib(k - 1), g = fib(k)。均为int型，很快就会数值溢出
public:
	Fib(int n) //初始化为不小于n的最小Fibonacci项
	{
		f = 1; second = 0; while (second < n) next();
	} //fib(-1), fib(0)，O(log_phi(n))时间
	int get() { return second; } //获取当前Fibonacci项，O(1)时间
	int next() { second += f; f = second - f; return second; } //转至下一Fibonacci项，O(1)时间
	int prev() { f = second - f; second -= f; return second; } //转至上一Fibonacci项，O(1)时间
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