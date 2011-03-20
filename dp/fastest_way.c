#include<stdio.h>

int e0 = 2, e1 = 4;
int x0 = 3, x1 = 2;
int a[2][6] = {
                {7,9,3,4,8,4},
                {8,5,6,4,5,7}
             };

int t[2][6] = {
                {2,3,1,3,4},
                {2,1,2,2,1}
             };

int f[2][6];

int l[2][6];

int max_len = 6;

int fbest = -1 , lbest = -1;

void fastest_way(){
        int i = 1;
        f[0][0] = e0 + a[0][0];
        f[1][0] = e1 + a[1][0];
        for(;i < max_len;i++){
                
                if(f[0][i-1] <= f[1][i-1] + t[1][i-1]){
                        f[0][i] = f[0][i-1] + a[0][i];
                        l[0][i] = 0;
                }else{
                        f[0][i] = f[1][i-1] + t[1][i-1] + a[0][i];
                        l[0][i] = 1;
                }

                if(f[1][i-1]  <= f[0][i-1] + t[0][i-1]){
                        f[1][i] = f[1][i-1] + a[1][i];
                        l[1][i] = 1;
                }else{
                        f[1][i] = f[0][i-1] + t[0][i-1] + a[1][i];
                        l[1][i] = 0;
                }
                        
        }
        if( f[0][max_len-1] + x0 <= f[1][max_len-1] + x1){
                fbest = f[0][max_len - 1] + x0;
                lbest = 0;
        }else{
                fbest = f[1][max_len - 1] + x1;
                lbest = 1;
        }       
}

void print_path(){
        int i = max_len - 1;
        int j = lbest;
        printf("fastest time:%d\n",fbest);
        printf("Line: %d, Station: %d\n", j + 1 , max_len);
        for(;i > 0 ; i--){
                j = l[j][i];
                printf("Line: %d, Station: %d\n", j + 1 , i + 1);
        }
}

void main(){
        fastest_way();
        if(lbest != -1)
                print_path();
}
