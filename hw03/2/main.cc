# include <cstdio>
# include "util.h"

int main(){
// get user inputs

int a, b;
printf("initizlied as a, b: %d, %d\n", a, b);
printf("Enter int value for a and b:");
scanf("%d %d", &a, &b);

printf("input value..");
printf("a: %d\n", a);
printf("b: %d\n", b);

// call the function
swapValues(&a, &b);
printf("after swapping... value..");
printf("a: %d\n", a);
printf("b: %d\n", b);



}
