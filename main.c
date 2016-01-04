#include <stdio.h>
#include <stdlib.h>
#include "array_util.h"

int main(void){
	ArrayUtil arr1 = create(4,10);
	ArrayUtil arr2 = create(4,5);
	printf("typeSize %d\n",arr1.typeSize);
	printf("length %d\n",arr1.length);
	areEqual(arr1, arr2);
	return 0;
}

