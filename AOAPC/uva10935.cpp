/** /
#include <cstdio>
#include <list>

int main()
{
	int n;
	FILE* fin = fopen("in", "r");
	while (fscanf(fin, "%d", &n) == 1 && n)
	{
		std::list<int> cards(n);
		int i = 1;
		for (auto it = cards.begin(); it != cards.end(); ++it)
			*it = i++;

		printf("Discarded cards:");
		int first = 1;
		for (;;)
		{
			if (cards.size() < 2)
				break;
			if (!first)	printf(",");
			printf(" %d", cards.front());
			cards.pop_front();
			cards.push_back(cards.front());
			cards.pop_front();
			first = 0;
		}
		printf("\nRemaining card: %d\n", cards.front());
	}
	return 0;
}
/**/