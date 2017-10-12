#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
#include <conio.h>
#define _CRT_SECURE_NO_WARNINGS

typedef struct {
	int *array;
	size_t used;
	size_t size;
} Array;

void initArray(Array *a, size_t initialSize) {
	a->array = (int *)malloc(initialSize * sizeof(int));
	a->used = 0;
	a->size = initialSize;
}
void reallArray(Array *a, size_t initialSize) {
	a->array = (int *)realloc(initialSize * sizeof(int));
	a->used = 0;
	a->size = initialSize;
}
void insertArray(Array *a, int element) {
	// a->used is the number of used entries, because a->array[a->used++] updates a->used only *after* the array has been accessed.
	// Therefore a->used can go up to a->size
	if (a->used == a->size) {
		a->size *= 2;
		a->array = (int *)realloc(a->array, a->size * sizeof(int));
	}
	a->array[a->used++] = element;
}

void freeArray(Array *a) {
	free(a->array);
	a->array = NULL;
	a->used = a->size = 0;
}

/*void longestCommonPrefix(DNA_String1, DNA_string2) {
while(i < index1 && i < index2 && )
}*/
//Add some DNA prefixes like ATCG
int Memcheck() {
	int *sack, *sack1, ay1 = 0;
	printf("Loading...\n");
	sack = malloc(1 * sizeof(*sack));
	sack1 = malloc(1 * sizeof(*sack1));
	if (sack == NULL) {
		printf("Error, out of memory. Error Code: 1\n");
		getchar();
		ay1 = 2;
		free(sack);
		return 1;
	}
	else {
		printf("\n");
		int *temp = realloc(sack, 1 * sizeof(int));
		if (temp != NULL) {
			sack = temp;
		}
		else {
			free(sack);
			ay1 = 4;
			printf("Error, plumbing unsuccessful. Error Code 3.\n");
			getchar();
		}

	}
	if (sack1 == NULL) {
		printf("Error, out of memory.  Error Code 2\n");
		getchar();
		ay1 = 3;
		free(sack1);
		return 1;
	}
	else {
		printf("Load successful.\n");
		printf("Press any button to continue...\n");
		getchar();
		ay1 = 1;
		int *temp1 = realloc(sack1, 1 * sizeof(int));
		if (temp1 != NULL) {
			sack1 = temp1;
		}
		else {
			free(sack1);
			printf("Error, plumbing not successful.  Error Code 4.\n");
			getchar();
			ay1 = 5;
		}
	}
}

/*int fileOpen() {

FILE *fp, *fp1;
long lSize, lSize1;
char *buffer, *buffer1;

fp = fopen("G1.txt", "rb");
if (!fp) perror("G1.txt"), exit(1);

fseek(fp, 0L, SEEK_END);
lSize = ftell(fp);
rewind(fp);

// allocate memory for entire content
buffer = calloc(1, lSize + 1);
if (!buffer) fclose(fp), fputs("memory alloc fails", stderr), exit(1);

//copy the file into the buffer
if (1 != fread(buffer, lSize, 1, fp))
fclose(fp), free(buffer), fputs("entire read fails", stderr), exit(1);

fp1 = fopen("G2.txt", "rb");
if (!fp1) perror("G2.txt"), exit(1);

fseek(fp1, 0L, SEEK_END);
lSize1 = ftell(fp1);
rewind(fp1);

// allocate memory for entire content
buffer1 = calloc(1, lSize1 + 1);
if (!buffer1) fclose(fp1), fputs("memory alloc fails", stderr), exit(1);

//copy the file into the buffer
if (1 != fread(buffer1, lSize1, 1, fp1))
fclose(fp1), free(buffer1), fputs("entire read fails", stderr), exit(1);

fclose(fp);

fclose(fp1);
}*/

int match(int genomeSum) {

	FILE *fp, *fp1;
	long lSize, lSize1;
	char *DNA_String1;
	char *DNA_String2;
	int index1 = 15;
	int index2 = 15;
	int j = 0;
	int win = 0;
	int loss = 0;
	//int Rs = 0;
	int win_sum = 0;
	Array a;
	//int k;
	char G1[255];
	char G2[255];

	printf("Make sure the working directory is set properly.\nWhat is the filename for the first genome?\n");
	scanf("%s", G1);
	strcat(G1, ".txt");
	printf("What is the filename for the second genome?\n");
	scanf("%s", G2);
	strcat(G2, ".txt");
	fp = fopen(G1, "rb");
	if (!fp) perror(G1), exit(1);
	fp1 = fopen(G2, "rb");
	if (!fp1) perror(G2), exit(1);

	fseek(fp, 0L, SEEK_END);
	lSize = ftell(fp);
	rewind(fp);
	fseek(fp1, 0L, SEEK_END);
	lSize1 = ftell(fp1);
	rewind(fp1);

	/* allocate memory for entire content */
	DNA_String1 = calloc(1, lSize + 1);
	if (!DNA_String1) fclose(fp), fputs("memory alloc fails", stderr), getchar(), exit(1);

	/* copy the file into the buffer */
	if (1 != fread(DNA_String1, lSize, 1, fp))
		fclose(fp), free(DNA_String1), fputs("entire read fails", stderr), getchar(), exit(1);

	fp1 = fopen(G2, "rb");
	if (!fp1) perror(G2), getchar(), exit(1);

	/* allocate memory for entire content */
	DNA_String2 = calloc(1, lSize1 + 1);
	if (!DNA_String2) fclose(fp1), fputs("memory alloc fails", stderr), getchar(), exit(1);

	/* copy the file into the buffer */
	if (1 != fread(DNA_String2, lSize1, 1, fp1))
		fclose(fp1), free(DNA_String2), fputs("entire read fails", stderr), getchar(), exit(1);

	printf("This is a test.\n");
	if (strcmp(DNA_String1, DNA_String2) == 0) {
		printf("\n\nThis result will be a true match.\n\nIf you would like to recieve a score for the gnome, press enter.\n");
		getchar();
	}
	if (strlen(DNA_String1) != strlen(DNA_String2)) {
		printf("This result was a incompatible, due to different lengths of the genome.\n");
		return false;
	}
	else {
		for (int j = 0; j <= lSize - 1; ++j) {
			printf("The for-loops is in action on iteration %d.\n", j);
			if (DNA_String1[j] != DNA_String2[j]) {
				if (j > 80000) {
					freeArray(&a);
					reallArray(&a, lSize1);
					insertArray(&a, lSize1);
					//win_sum == j;
				}
				else {
					printf("Partial score noted\n");
					genomeSum = genomeSum + 1;
					++loss;
					printf("Mutation noted at iteration %d\n", j);
					printf("Loss is at: %d.\n", loss);
					initArray(&a, 6000);  // initially 1 element
										  //for (k = 0; k < 100; k++)
					insertArray(&a, j);  // automatically resizes as necessary
										 //printf("%d\n", a.array[9]);  // print 10th element
					printf("Used Elements in mutation array %d\n", a.used);  // print number of elements
					freeArray(&a);
				}
			}
			else if (DNA_String1[j] == DNA_String2[j]) {
				printf("\nSuccessful match for character %d.\n\n", j);
				genomeSum = genomeSum + 10;
				++win;
				printf("Win is at: %d.\n", win);
			}
		}
		printf("Score for the genome comparison: %d\n\n", genomeSum);
		return genomeSum;
	}
}

int score_Compare() {
	int G;
	int genomeSum = 0;

	G = match(genomeSum);

	printf("Here is the genome's score passed through the function: %d\n\nIs it correct?\n", G);
	return G;
}

int mutation_Analysis() {
	int G = 0;
	int mutate = 0;

	mutate = score_Compare(G);
	printf("Mutate is %d.\n", mutate);
	/*Here an ideal feature would be to have a function that would be able to use the values in found from the character positioning of mutations
	and be able to map out and compare the mutated strands of DNA.  my plan of this is simply to understand the significance of the mutated strand.
	This can be done with a similar character compare, but first an array unloading.  Something useful first for debug purposes would be to print out
	the array to make sure it is actually the mutated strands, offer a count of how many there are in the genome, then start to understand the
	significance of a pattern in the genome.  One at a time*/
	getchar();
}

int main() {

	char user_Input[255];
	char GC[] = "Genome Compare";
	char MA[] = "Mutation Analysis";

	Memcheck();
	/*printf("\nDEBUG MODE\n\nHello and welcome to WMU DNA.\nWhich mode would you like to use?\n");
	printf("Genome Compare\nMutation Analysis\n");
	scanf("%s", &user_Input);
	if (strcmp(user_Input, GC) == 0) {*/
	score_Compare();
	//}
	//else if (strcmp(user_Input, MA) == 0) {
	mutation_Analysis();
	//}
	//else {
	//printf("You got problems, yo.\n");
	getchar();
	//}
}
