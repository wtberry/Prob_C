// creating swap function
# include <cstdio>
void swapValues(int* a, int* b){
#if 1
	int temp;
	temp = *a; // temp hold the value in a
	*a = *b; // now pointer a is pointing at the value in b
	*b = temp; // now pinter b is pointing at value in c/originally in a
#endif

}
