/** /
#include <stdio.h>	
#include <string.h>
#define maxn 100
#define max1 10
char* sid[maxn];
int cid[maxn];
char* name[maxn];
int score[maxn][5];
int removed[maxn];
int r = 0;

void print_menu()
{
	printf("Welcome to SPMS.\n");
	printf("1 - Add\n2 - Remove\n3 - Query\n4 - Show ranking\n5 - Show Statistics\n0 - Exit\n");
}

int rank(int r)
{
	return r;
}
void DQ(int isq)
{
	char s[max1];
	for (;;)
	{
		printf("Please enter SID or name. Enter 0 to finish.\n");
		scanf("%s", s);
		if (strcmp(s, "0") == 0)
			break;
		int r = 0;
		for (int i = 0; i < maxn; ++i)
		{
			if (!strcmp(sid[i], s) || !strcmp(name[i], s))
			{
				if (removed[i])
					return;
				if (isq)
				{
					score[i][4] += score[i][0] + score[i][1] + score[i][2] + score[i][3];
					printf("%d %s %d %s %d %d %d %d %d %.2f\n", rank(i), sid[i], cid[i], name[i], score[i][0],\
						score[i][1], score[i][2], score[i][3], score[i][4], score[i][4] / 4.0 + EPS);
				}
				else
				{
					removed[i] = 1; 
					r++;
				}
			}
			if (!isq)
				printf("%d student(s) removed.\n", r);
		}
	}
}

void add()
{
	printf("Please enter the SID, CID, name and four scores. Enter 0 to finish.\n");
	int ci;
	char* si, *nm;
	int sco[4];
	while (scanf("%s%d%s %d%d%d%d", si, &ci, nm, sco, sco + 1, sco + 2, sco + 3) == 7)
	{
		for (int i = 0; i < maxn; ++i)
			if (!strcmp(si, sid[i]))
			{
				printf("Duplicated SID.\n");
				break;
			}
		sid[r] = si; cid[r] = ci; name[r] = nm;
		for (int i = 0; i < 4; ++i)
			score[r][i] = sco[i];
	}
}

void stat()
{
	printf("Please enter class ID, 0 for the whole statistics.\n");

}

int main()
{
	memset(removed, 0, sizeof(removed));
	memset(score, 0, sizeof(score));
	for (;;)
	{
		int choice;
		print_menu();
		scanf("%d", &choice);
		if (choice == 0)
			break;
		switch (choice)
		{
		case 1:
			add();
			break;
		case 2:
			DQ(0);
			break;
		case 3:
			DQ(1);
			break;
		case 4:
			printf("Showing the ranklist hurts students' self-esteem. Don't do that.\n");
			break;
		case 5:
			stat();
			break;
		default:
			break;
		}
	}
	return 0;
}
/**/