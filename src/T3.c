#include <stdio.h>
#include <stdlib.h>
#define LEN sizeof(struct Y)
int main(void)
{
	void create(void);
	create();
	return 0;
}
struct Y
{
	int num;
	char name[2];
	struct Y * next;
};
void create(void)
{
	//定义指针变量时 *不能分
	struct Y * p1 ,* p2;
	struct Y * head;
	int n = 0;
	int i;
	p1 = p2 = (struct Y *) malloc(LEN);
	while (n < 4)
	{
		if(n == 0)
		{
			head = p1;
			head->num = n;
		}
		else
		{
			
			p2 = (struct Y *)malloc(LEN);
			p1->next = p2;
			p2->num = n;
			p1 = p2;
		}
		n++;		
	}
	p2->next = NULL;
	
	struct Y * temp = NULL;
	for (i = 0; i<n ; i++)
	{
		if(i == 0)
		{
			printf("ini-address: %d , number: %d , next: %d\n" , head , head->num,head->next);
			temp = head->next;
		}
		else
		{
			printf("address: %d , number: %d ,next:%d\n" , temp , temp->num,temp->next);
			temp = temp->next;
		}	
	}
	return ;
}
