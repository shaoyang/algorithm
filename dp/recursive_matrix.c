#include<stdio.h>

#define max_len 7
#define MAX  999999
int p[max_len] = {30,35,15,5,10,20,25};

int s[ max_len][max_len];

int m[ max_len][max_len];

int lookup_chain(int i , int j){
       
        int k,q;
        
        if(m[i][j] < MAX){
                return m[i][j];
        }
        if(i == j){
                m[i][j] = 0;
        }else{
                for(k = i ; k <= j-1; k++){
                        q = lookup_chain(i,k) + lookup_chain(k+1,j) + p[i-1] * p[k] * p[j];
                        if( q < m[i][j]){
                                m[i][j] = q;
                                s[i][j] = k;
                        }
                } 
        }
        return m[i][j];
                
}

int memoized_matrix_chain(){
        int i = 1 , n = max_len - 1 , j ;
        //使用MAX标记该点未被访问
        for(;i <= n ; i++){
                for(j = i;j <= n ; j++){
                        m[i][j] = MAX;
                }
        }

        return lookup_chain(1,n);
}

void print_optimal_parens(int i, int j){
       
        if(i == j){
                printf("A");
        }else{
                printf("(");
                print_optimal_parens(i,s[i][j]);
                print_optimal_parens(s[i][j]+1,j);
                printf(")");
        }
}

void main(){
        memoized_matrix_chain();
        print_optimal_parens(1,max_len - 1);
}
