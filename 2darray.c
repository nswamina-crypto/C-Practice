#include <stdio.h>
int main()
{
	int x[5][5]={{1,2,3,4,5},{6,7,8,9,10},{11,12,13,14,15},{16,17,18,19,20},{21,21,23,24,25}};
	int *ptr = (int *)x;
	int i, j;
	for (i = 0; i < 5; i++) {
	  for (j = 0; j < 5; j++) {
	    printf("%d ", *(ptr+(i*5+j)));
	  }
	  printf("\n");
	}
	return 0;
}
//x[i][j]
