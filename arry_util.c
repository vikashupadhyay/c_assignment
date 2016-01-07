#include <stdio.h>
#include <stdlib.h>
#include "array_util.h"
int *ptr    = NULL;


ArrayUtil create(int size,int len){
	ArrayUtil newArr = *(ArrayUtil *)malloc(sizeof(ArrayUtil));
	newArr.base = (void *)calloc(len,size);
	newArr.typeSize = size;
	newArr.length = len;
	return newArr;
}
int areEqual(ArrayUtil arr1, ArrayUtil arr2){
	if(arr1.length!= arr2.length) return 0;
	if(arr1.typeSize!= arr2.typeSize) return 0;
	for (int i = 0; i < arr1.length; ++i){	
		if(*((unsigned char *)arr1.base+i)-*((unsigned char *)arr2.base+i)!=0) return 0;
	}
	return 1;
};

ArrayUtil resize(ArrayUtil util, int length){
	util.base = realloc(util.base,length);
	util.length = length;
	return util;
};

int findIndex(ArrayUtil util,void *element){
	for (int i = 0; i < util.length; i++){
		if((*((unsigned char *)util.base+i*util.typeSize)-*(unsigned char *)element)==0)return i;
	}
	return -1;
}

void dispose(ArrayUtil util){
	free(util.base);
};

void* findFirst(ArrayUtil util, MatchFunc* match, void* hint){
	for (int i = 0; i < util.length; ++i){
		if((*match)(hint,util.base+i*util.typeSize)){
			return util.base+i*util.typeSize;
		}
	}
	return NULL;
}

void* findLast(ArrayUtil util, MatchFunc* match, void* hint){
	for (int i = util.length-1; i>=0; --i)
		if((*match)(&hint,util.base+i*util.typeSize))
			return util.base+i*util.typeSize;
	 	return NULL;
}

int count(ArrayUtil util, MatchFunc* match, void* hint){
	int counter = 0; 
	for (int i = 0; i < util.length; ++i)
		if(match(&hint,util.base+i*util.typeSize))
			counter++;
	return counter;
};

int filter(ArrayUtil util, MatchFunc* match, void* hint, void** destination, int maxItems){	
	destination  = realloc(destination,maxItems);
	int counter =0;
	for (int i = 0; i < util.length; ++i){
		if(match(hint,util.base+i*util.typeSize) && maxItems>counter){
			destination[counter] =util.base+i*util.typeSize;
			counter++;
		}		
	}
	return counter;
}

void map(ArrayUtil source, ArrayUtil destination, ConvertFunc* convert, void* hint){
	for (int i = 0; i < source.length; ++i){
		convert(hint,(source.base+i*source.typeSize),(destination.base+i*destination.typeSize));
	}
}

void forEach(ArrayUtil util, OperationFunc* operation, void* hint){
	for (int i = 0; i < util.length; ++i){
		operation(hint,(util.base+i*util.typeSize));
	}
};
