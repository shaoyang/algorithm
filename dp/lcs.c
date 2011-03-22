#include<stdio.h>

#define alen 7
#define blen 6

char A[alen] = {'A','B','C','B','D','A','B'};
char B[blen] = {'B','D','C','A','B','A'};
//记录longest common string
static int c[alen+1][blen+1];

void lcs(){
        int i,j;

        for(i = 1; i < alen; i++){
                c[i][0] = 0;
        }
        for(j = 0; j < blen;j++){
                c[0][j] = 0;
        }

        for(i = 1; i <= alen; i++){
                for(j = 1;j <= blen; j++){
                        if(A[i-1] == B[j-1]){
                                c[i][j] = c[i-1][j-1] + 1;
                        }else if(c[i-1][j] >= c[i][j-1]){
                                c[i][j] = c[i-1][j];
                        }else{
                                c[i][j] = c[i][j-1];
                        }
                }
        }
}

void print_lcs(int i,int j){

        if(i==0 || j==0){
                return ;
        }

        if(c[i][j] == c[i-1][j]){
                print_lcs(i-1,j);
        }else if(c[i][j] == c[i][j-1]){
                print_lcs(i,j-1);
        }else{
                print_lcs(i-1,j-1);
                printf("%i,%c\n",i,A[i-1]);
        }
}

void main(){
        lcs();
        print_lcs(alen,blen);
}
