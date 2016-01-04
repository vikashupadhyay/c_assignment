#include <stdio.h>
#include <stdlib.h>
#include "array_util.h"

int main(void){
	ArrayUtil arr1 = create(sizeof(int),10);
	ArrayUtil arr2 = create(sizeof(int),10);
	for (int i = 0; i < arr1.length; ++i){
		int *a = arr1.base;
		a[i] = i;
	}
	for (int i = 0; i < arr2.length; ++i){
		int *b = arr2.base;
		b[i] = i+1;
	}
	// printf("%d\n",areEqual(arr1,arr2));
	ArrayUtil newArr = resize(arr1,4);
	int *a = newArr.base;
	// printf("%d\n",*a);
	return 0;
}

