#include <stdio.h>

int main () {
    
    int intValue = sizeof(int);
    printf("%d\n",intValue);
    
    int PAGESIZE = 4096;
    int salto = PAGESIZE / sizeof(int);
    printf("%d\n",salto);
    
    int npags = 100;
    int v[npags*salto];


    int count = 0;

    for (int i =0; i<npags*salto; i +=salto){
        v[i]+=1;
        count++;
    }
    printf("\n%d",count);


}