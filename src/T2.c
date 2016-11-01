#include <stdio.h>
#include <stdlib.h>

#define LEN sizeof(struct Student)
int main()
{
		//struct Student * pt;
		//struct Student * create(void);
		//pt = create();
		//printf("%ld , %5.1f" ,pt->num, pt->score);
	return 0;
};
//全局变量
struct Student
	{
		long num;
		float score;
		int anum;
		struct Student * next;
	};
//全局变量
int n;
struct Student * create(void)
{
	struct Student * head,* p1, * p2;
	n = 0;
	p1 = p2 = (struct Student *)malloc(LEN);
	scanf("%ld,%f" , &p1->num , &p1->score);
	head = NULL;
	while (p1->num != 0)
	{
		n = n+1;
		if(n == 1)
		{
			head = p1;
		}
		else
		{
			p2->next = p1;
			p2 = p1;
			p1 = (struct Student *)malloc(LEN);
			scanf("%ld,%f" , &p1->num,&p1->score);
		}
		p2->next = NULL;
		return head;
	}
	
}
