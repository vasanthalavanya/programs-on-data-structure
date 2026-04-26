#include<stdio.h>
#include<stdlib.h>
int main(int argc, char*argv[])
{
	char*name;
	int m1,m2,m3,total;
	if(argc!=5){
		printf("usage:program_name name mark1 mark2 mark3\n");
		return 1;
	}
	name = argv[1];
	m1 = atoi(argv[2]);
	m2 = atoi(argv[3]);
	m3 = atoi(argv[4]);
	
	total = m1+m2+m3;
	
	printf("\nstudent details\n");
	printf("name : %s\n",name);
	printf("marks : %d %d %d\n",m1,m2,m3);
	printf("total : %d\n",total);
	return 0;
	
}
