void printIntArray(const int* array, int size);
void printCharArray(const char* array, int size);
int** readPpm(const char* f_name, int* width, int* height);
void writePpm(int** array, char* magic, int width, int height, int max_pix);
int** horizFlip(int** picture, int height, int width);
int** dot_product(int** mat1, int** mat2, int width1, int height1, int width2, int height2);
int** create_mat(int width, int height);
int** reverse_identity(int size);

