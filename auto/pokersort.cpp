#include <iostream>
#include <cstdio>
using namespace std;
struct Poker
{
	char type;
	int  point;

};
enum 
{
	BLACK,
    HEART,
	CIUBS,
	DIAMONDS,
	JOKER
};
void inpointpoker(Poker *pk)
{
	 
	scanf("%c%d",&pk->type,&pk->point);
	 
	pk->type -= 'a';
	if (pk->type== JOKER)
	{
		pk->point += 13;
	}
 
}
void outputjocker(Poker *pk)
{
	const char * type[5] = { "黑桃","红桃","方片","梅花"," 大王" };
	const char *point[16] = {"", "A","2","3","4","5","6","7","8","9","10","J","Q","K" ,"",""};
	printf("%s%s\n", type[pk->type], point[pk->point]);
}
bool striol(const char *src, int &res)
{
	if (!src)
	{
		return false;
	}
	while (*src<=' ')
	{
		src++;
	}
	int flag = 1;
	if (*src=='-')
	{
		flag = -1;
		src++;
	}
	if (*src>='9'||*src<='0')
	{
		return false;
	}
	int sum = 0,tmp;
	int i;
	for (i=0;src[i]&&src[i]<='9'&&src[i]>='0';++i)
	{
		tmp = src[i] - '0';
		sum = sum * 10 + tmp;
	}
	res = sum * flag;
	return true;
}
bool dealsb(Poker a, Poker b)
{
	return (a.point < b.point) || (a.point = b.point) && (a.type > b.type);
}
void insertsort(Poker* src, int n)
{
	bool(*ps)(Poker, Poker) = dealsb;
	int i, j;
    Poker tmp;
	for (i = 1; i < n; ++i)
	{
		tmp = src[i];
		for (j = i; j > 0 && ps(src[j - 1], tmp); --j)
		{
			src[j] = src[j - 1];
		}
		src[j] = tmp;
	}
}
int main222()
{
 	Poker p;
	while (1)
	{
 		inpointpoker(&p);
 		while (getchar() != '\n')	
		outputjocker(&p);
		puts("");
	}
	/*
	Poker p[5];
	int i = 0;
	for (i = 0; i < 5; ++i)
	{
		inpointpoker(p + i);
		while (getchar() != '\n')
		{
		}
	}
	insertsort(p, 5);*/
	/*for (auto i : p)
	{
		outputjocker(p + i);
	}*/
	/*for (i=0;i<5;++i)
	{
		outputjocker(p + i);
	}*/
	system("pause");
	return 0;
}
