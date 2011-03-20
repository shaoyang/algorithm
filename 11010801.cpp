#include<stdio.h>

#define	ALLOCSIZE 10000

static char allocbuf[ALLOCSIZE];
static char *allocp = allocbuf;

char *alloc(int n)
{
	if( allocbuf + ALLOCSIZE - allocp -n >=0){
		allocp += n;
		return allocp -n;
	} else{/*c语言保证，0永远不是有效的数据地址，返回0意味着可用来表示发生了异常事件*/
		return 0;
	}
}
void afree(char* p)
{
	if(p >= allocbuf && p < allocbuf + ALLOCSIZE)
		allocp = p;
}
main()
{

	char* p;
	int i;
	if((p = alloc(100))){
		for(i=0;i<100;i++,p++){
			*p = 'A';
		}	
	}
	afree(p - 100);
	return 0;
}
