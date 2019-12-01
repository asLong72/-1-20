#include <stdio.h>

typedef struct date
{
	int year;
	int month;
	int day;
}date;

typedef struct student
{
	int num;
	char name[7];
	int score[3];
}student;

//int main()
//{
//	date aday;
//	int sum = 0;
//	int month[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
//	scanf("%d%d%d", &aday.year, &aday.month, &aday.day);
//	if ((aday.year%4==0&& aday.year%100!=0)||( aday.year%400==0))
//	{
//		for (int i = 0; i < aday.month-1; i++)
//		{
//			sum += month[i];
//		}
//		sum += aday.day;
//		if (aday.month > 2)
//		{
//			sum++;
//		}
//	}
//	else
//	{
//		for (int i = 0; i < aday.month - 1; i++)
//		{
//			sum += month[i];
//		}
//		sum += aday.day;
//	}
//	printf("%d\n", sum);
//	return 0;
//}

void print(student std[]);
int main()
{
	student std[5] = { NULL };
	int b = 0,n=5;
	for (int i = 0; i < n; i++)
	{
		char c[72] = { NULL };
		scanf("%s", c);
		for (int j = 0,k=0; c[j] != 0; j++)
		{
			if (c[j] >= '0' && c[j] <= '9')
			{
				switch (b)
				{
				case 0:
					std[i].num = std[i].num * 10 + c[j] - 48;
					b = 1;
					break;
				case 1:
					for (int l = 0; l < 3; l++)
					{
						while (c[j])
						{
							if (c[j] == ',')
							{
								j++;
								break;
							}
							else
							{
								std[i].score[l] = std[i].score[l] * 10 + c[j] - 48;
								j++;
							}
						}
					}
					b = 0;
					break;
				}
			}
			else if (c[j] < 0)
			{
				std[i].name[k] = c[j];
				k++;
			}
		}
	}
	print(std);
	return 0;
}
void print(student std[])
{
	for (int i = 0; i < 5; i++)
	{
		printf("%d\t%s\t%d\t%d\t%d\n", std[i].num, std[i].name, std[i].score[0], std[i].score[1], std[i].score[2]);
	}
}