# include <cstdio>

int main(){
// using file I/O to keep track of how manhy times the program is ran

// MAKE SURE the file exist before opening!, or it'll throw seg fault
FILE* fp = fopen("log.txt", "r");
if(fp==NULL){ // first time, file don't exist

}

// now read in teh value
int count;
while(fscanf(fp, "%d", &count) != EOF){
    printf("reading in the input: %d\n", count);
}

count += 1; // increment

fclose(fp); // close the file opener

// now write the result to the file
FILE* fw = fopen("log.txt", "w");
fprintf(fw, "%d", count);
fclose(fw);






}
