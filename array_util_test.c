#include "assert.h"
#include <stdio.h>
#include "arry_util.c"

/*						 *************                                */
// for running test you have required array_util_test.c file you have give command node runTestForC.js array_util_test.c

void test_to_create_array(){
	ArrayUtil arr1 = create(sizeof(int),10);
	ArrayUtil arr2 = create(sizeof(char),5);
	assert(arr1.length==10);
	assert(arr1.typeSize==4);
	assert(arr2.length==5);
	assert(arr2.typeSize==1);

}

void test_for_equal_array_for_int(){
	ArrayUtil arr1 = create(sizeof(int),4);
	ArrayUtil arr2 = create(sizeof(int),4);
	ArrayUtil arr3 = create(sizeof(int),3);
	*((int *)arr1.base+0) = 1;
	*((int *)arr1.base+1) = 2;
	*((int *)arr1.base+2) = 3;
	*((int *)arr1.base+3) = 4;
	*((int *)arr2.base+0) = 1;
	*((int *)arr2.base+1) = 2;
	*((int *)arr2.base+2) = 3;
	*((int *)arr2.base+3) = 4;
	*((int *)arr3.base+1) = 2;
	*((int *)arr3.base+2) = 3;
	*((int *)arr3.base+3) = 4;
	assert(areEqual(arr1,arr2)==1);
	assert(areEqual(arr1,arr3)==0);
}

void test_for_equal_array_for_char(){
	ArrayUtil arr1 = create(sizeof(char),5);
	ArrayUtil arr2 = create(sizeof(char),5);
	ArrayUtil arr3 = create(sizeof(int),3);
	*((char *)arr1.base+0) = 'v';
	*((char *)arr1.base+1) = 'i';
	*((char *)arr1.base+2) = 'k';
	*((char *)arr1.base+3) = 'a';
	*((char *)arr1.base+4) = 's';

	*((char *)arr2.base+0) = 'v';
	*((char *)arr2.base+1) = 'i';
	*((char *)arr2.base+2) = 'k';
	*((char *)arr2.base+3) = 'a';
	*((char *)arr2.base+4) = 's';
	*((char *)arr3.base+1) = 'v';
	*((char *)arr3.base+2) = 'k';
	*((char *)arr3.base+3) = 'u';
	assert(areEqual(arr1,arr2)==1);
	assert(areEqual(arr1,arr3)==0);
}
void test_for_resize_array(){
	ArrayUtil arr1 = create(sizeof(int),5);
	ArrayUtil newArr  = resize(arr1,4);
	assert(newArr.length==4);
	assert(arr1.length==5);
}

void test_for_find_index_of_element_in_array(){
	ArrayUtil arr1 = create(sizeof(int),5);
	*((int *)arr1.base+0) = 1;
	*((int *)arr1.base+1) = 2;
	*((int *)arr1.base+2) = 3;
	*((int *)arr1.base+3) = 44444;
	*((int *)arr1.base+4) = 5;
	int input1 = 44444;
	int input2 = 9;
	assert(findIndex(arr1,&input1)==3);
	assert(findIndex(arr1,&input2)==-1);
}

void test_for_find_index_of_element_in_array_which_have_char(){
	ArrayUtil arr1 = create(sizeof(char),5);
	*((char *)arr1.base+0) = 'v';
	*((char *)arr1.base+1) = 'i';
	*((char *)arr1.base+2) = 'k';
	*((char *)arr1.base+3) = 'a';
	*((char *)arr1.base+4) = 's';
	char input  = 'k';
	assert(findIndex(arr1,&input)==2);
}
int isEven(void* hint, void* item){
	return *(int *)item%2==0;
}
void test_find_first_even_num(){
	int size = sizeof(int);
	int length = 4;
	MatchFunc iseven= isEven;
	ArrayUtil array_1 =  create(size, length);
	int *base = ( int *)(array_1.base);
	base[0] = 1;
	base[1] = 3;
	base[2] = 26;
	base[3] = 48;
	void *result = findFirst(array_1,&iseven,NULL);
	assert(*(int*)result==26);
}

void test_find_first_even_num_if_no_is_not_there(){
	int size = sizeof(int);
	int length = 4;
	MatchFunc iseven= isEven;
	ArrayUtil array_1 =  create(size, length);
	int *base = ( int *)(array_1.base);
	base[0] = 1;
	base[1] = 3;
	base[2] = 5;
	base[3] = 7;
	void *result = findFirst(array_1,&iseven,NULL);
	 assert((int*)result==0);
}

void test_last_even_num(){
	int length = 4;
	MatchFunc iseven= isEven;
	ArrayUtil arr_1 = create(sizeof(int),length);
	int *base = (int *)arr_1.base;
	base[0] = 2;
	base[1] = 4;
	base[2] = 6;
	base[3] = 8;
	void *result = findLast(arr_1,&iseven,NULL);
	assert(*(int*)result==8);
}
void test_find_last_even_num_if_no_is_not_there(){
	int length = 4;
	MatchFunc iseven= isEven;
	ArrayUtil arr_1 = create(sizeof(int),length);
	int *base = (int *)arr_1.base;
	base[0] = 1;
	base[1] = 3;
	base[2] = 5;
	base[3] = 7;
	void *result = findLast(arr_1,&iseven,NULL);
	assert((int*)result==0);
}
void test_count_num_which_are_matching_condition(){
	int length = 4;
	MatchFunc iseven= isEven;
	ArrayUtil arr_1 = create(sizeof(int),length);
	int *base = (int *)arr_1.base;
	base[0] = 2;
	base[1] = 4;
	base[2] = 6;
	base[3] = 8;
	int result = count(arr_1,&iseven,NULL);
	assert(result==4);
}
void test_count_num_which_are_not_matching_condition(){
	int length = 4;
	MatchFunc iseven= isEven;
	ArrayUtil arr_1 = create(sizeof(int),length);
	int *base = (int *)arr_1.base;
	base[0] = 1;
	base[1] = 3;
	base[2] = 5;
	base[3] = 7;
	int result = count(arr_1,&iseven,NULL);
	assert(result==0);
}

void test_for_filter_array_according_to_condition(){
	int length = 10;
	int maxItems = 5;
	MatchFunc iseven= isEven;
	ArrayUtil arr_1 = create(sizeof(int),length);
	int *base = (int *)arr_1.base;
	ArrayUtil _destination = create(sizeof(int),maxItems);
	void **destination = (void *)_destination.base;
	base[0] = 1;
	base[1] = 2;
	base[2] = 3;
	base[3] = 4;
	base[4] = 5;
	base[5] = 6;
	base[6] = 7;
	base[7] = 8;
	base[8] = 9;
	base[9] = 10;
	int result = filter(arr_1, &iseven, NULL, destination, maxItems);
	assert(result==5);
	// int *s = (int*)destination;
	// printf("%d num is \n",*(int*)(destination +24));
	// assert(*(int*)destination==2);
	// assert(*((int *)destination+1)==4);
	// for (int i = 0; i <=5; i++)
	// {	
	// 	printf("------------------%p\n", s);
	// 	s=s+4;
	// 	// assert(s[i]==2*i);
	// }
}