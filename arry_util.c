#include <stdio.h>
#include <stdlib.h>
#include "array_util.h"


ArrayUtil create(int size,int len){
	ArrayUtil newArr = *(ArrayUtil *)malloc(sizeof(ArrayUtil));
	newArr.base = (void *)calloc(len,size);
	newArr.typeSize = size;
	newArr.length = len;
	return newArr;
}
int areEqual(ArrayUtil arr1, ArrayUtil arr2){
	int *a = arr1.base;
	int *b = arr2.base;
	if(arr1.length!= arr2.length) return 0;
	if(arr1.typeSize!= arr2.typeSize) return 0;
	for (int i = 0; i < arr1.length; ++i)
		if(a[i]!= b[i])
			return 0;
	return 1;
};

ArrayUtil resize(ArrayUtil util, int length){
	util.base = realloc(util.base,length);
	util.length = length;
	return util;
}; 
