//copying structure
#include<stdio.h>
struct student
{
	int rno;
	int m1,m2;
};
int main()
{
	 student s1,s2;
	s1.rno=1;
	s1.m1=95;
	s1.m2=98;
	s2=s1;
	printf("After copying s2 data \n");
	printf("rno %d\n",s2.rno);
	printf("m1 %d\n",s2.m1);
	printf("m2 %d",s2.m2);
	return 0;
}



