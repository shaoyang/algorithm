#include<stdio.h>
#include<ctype.h>

main()
{
	int c;	
	while((c=getchar())!='E'){
		printf("%d",isdigit(c));
	}
	return 0;
}
