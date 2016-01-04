#include <stdio.h>
#include <stdlib.h>
#include "array_util.h"
#ifndef NULL
#define NULL 0;
#endif

ArrayUtil create(int size,int len){
	ArrayUtil newArr = *(ArrayUtil *)malloc(sizeof(ArrayUtil));
	newArr.base = NULL;
	newArr.typeSize = size;
	newArr.length = len;
	return newArr;
}
int areEqual(ArrayUtil arr1, ArrayUtil arr2){
	return 1;
};