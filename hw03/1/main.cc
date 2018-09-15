# include <cstdio>

int main(){
// using file I/O to keep track of how manhy times the program is ran
char FILE_NAME [] = {'l', 'o', 'g', '.', 't', 'x','t'};
// MAKE SURE the file exist before opening!, or it'll throw seg fault
FILE* fp = fopen(FILE_NAME, "r");

if(fp==NULL){ // first time, file don't exist
	printf("This is %d time this program is ran.\n", 1); // print out how many times (1st time obviously)
	// then create file and put the number in there ;)
	FILE* fw = fopen(FILE_NAME, "w");
	fprintf(fw, "%d", 1); // write first time
}
// else not the first time
// now read in teh value
else{
	int count;
	while(fscanf(fp, "%d", &count) != EOF){
	    count += 1; // increment

	    printf("This is %d time this program is ran.\n", count); 
	}
	
	
	fclose(fp); // close the file opener
	
	// now write the result to the file
	FILE* fw = fopen(FILE_NAME, "w");
	fprintf(fw, "%d", count);
	fclose(fw);
}
}
