#define INT_SIZE sizeof(int)
#define CHAR_SIZE sizeof(char)
#define FLOAT_SIZE sizeof(float)
#define DOUBLE_SIZE sizeof(double)
#include <stdio.h>
#include <stdlib.h>
#include "expr_assert.h"
#include "arrayUtil.h"
#include <string.h>

struct arrayUtil a;
struct arrayUtil b;
struct arrayUtil util;

void test_one_plus_one_is_equal_to_2(){
	assertEqual(add(1,1),2);
};



void test_create_a_array_int(){
	int *aBase;
	a = create(INT_SIZE,3);
	aBase = (int*)(a.base);
	assertEqual(aBase[0],0);
	assertEqual(a.length,3);
	assertEqual(a.typeSize,4);
}

void test_create_a_array_char(){
	char *aBase;
	a = create(CHAR_SIZE,3);
	aBase = (char*)(a.base);
	assertEqual(aBase[0],0);
	assertEqual(a.length,3);
	assertEqual(a.typeSize,1);
}

void test_create_a_array_float(){
	float *aBase;
	a = create(FLOAT_SIZE,3);
	aBase = (float*)(a.base);
	assertEqual(aBase[0],0);
	assertEqual(a.length,3);
	assertEqual(a.typeSize,4);
}

void test_create_a_array_DOUBLE(){
	double *aBase;
	a = create(DOUBLE_SIZE,3);
	aBase = (double*)(a.base);
	assertEqual(aBase[0],0);
	assertEqual(a.length,3);
	assertEqual(a.typeSize,8);
}


void test_create_a_array_of_int_data_type(){
	int x[] = {1,2,3,4,5,6,7,9,10};
	int *bigArray = x;
	a = create(INT_SIZE*10,3);
	bigArray = (int*)a.base;
	assertEqual(bigArray[0],0);
	assertEqual(a.length,3);
	assertEqual(a.typeSize,40);
}

void test_two_arrayUtil_of_array_integer_are_equal(){
	int int_arr[] = {1,2,3,4,5,6,7,8,9,10};
	int *big_arr1 = int_arr;
	int *big_arr2 = int_arr;

	void *aBase,*bBase;
	aBase = (void*)(big_arr1);
	bBase = (void*)(big_arr2);

	a = (struct arrayUtil){aBase,INT_SIZE*10,1};
	b = (struct arrayUtil){bBase,INT_SIZE*10,1};
 	assertEqual(isEqual(a,b),1);
}

void test_two_arrayUtil_of_array_char_are_equal(){
	char char_arr[] = {'a','b','c'};
	char *big_arr1 = char_arr;
	char *big_arr2 = char_arr;

	void *aBase,*bBase;
	aBase = (void*)(big_arr1);
	bBase = (void*)(big_arr2);

	a = (struct arrayUtil){aBase,CHAR_SIZE*3,1};
	b = (struct arrayUtil){bBase,CHAR_SIZE*3,1};
 	assertEqual(isEqual(a,b),1);
}

void test_two_array_of_integer_are_equal(){
	int A[] = {1,2,3};
	int B[] = {1,2,3};
	
	void *aBase,*bBase;
	aBase = (void*)(A);
	bBase = (void*)(B);

	a = (struct arrayUtil){aBase,sizeof(int),3};
	b = (struct arrayUtil){bBase,sizeof(int),3};

	assertEqual(isEqual(a,b),1);
}

void test_two_array_of_float_is_equal(){
	float A[] = {1.111111,2.222222};
	float B[] = {3.333333,4.444444};

	void *aBase,*bBase;
	aBase = (void*)(A);
	bBase = (void*)(B);	

	a = (struct arrayUtil){aBase,sizeof(float),2};
	b = (struct arrayUtil){bBase,sizeof(float),2};

	assertEqual(isEqual(a,b),1);
}

void test_two_array_of_char_is_equal(){
	char A[] = {'a','b'};
	char B[] = {'a','b'};

	void *aBase,*bBase;
	aBase = (void*)(A);
	bBase = (void*)(B);	

	a = (struct arrayUtil){aBase,CHAR_SIZE,2};
	b = (struct arrayUtil){bBase,CHAR_SIZE,2};

	assertEqual(isEqual(a,b),1);
}

void test_two_array_of_double_is_equal(){
	double A[] = {'0','0'};
	double B[] = {'0','0'};

	void *aBase,*bBase;
	aBase = (void*)(A);
	bBase = (void*)(B);	

	a = (struct arrayUtil){aBase,DOUBLE_SIZE,2};
	b = (struct arrayUtil){bBase,DOUBLE_SIZE,2};

	assertEqual(isEqual(a,b),1);
}

void test_resizeArray_shrinked_the_array_of_char_when_new_size_is_less_then_the_current_size(){
	int len = 2;
	struct arrayUtil util = create(CHAR_SIZE,3);
	char *aBase = (char*)malloc(CHAR_SIZE*3);
	aBase[0] = 'a';
	aBase[1] = 'b';
	aBase[2] = 'c';
	util.base = (void*)aBase;

	util = resize(util,len);
	assertEqual(util.length,2);
	free(util.base);
}

void test_resizeArray_shrinked_the_array_of_float_when_new_size_is_less_then_the_current_size(){
	int len = 2;
	struct arrayUtil util = create(FLOAT_SIZE,3);
	float *aBase = (float*)malloc(FLOAT_SIZE*3);
	aBase[0] = 1.11111111;
	aBase[1] = 2.22222222;
	aBase[2] = 3.33333333;
	util.base = (void*)aBase;

	util = resize(util,len);
	assertEqual(util.length,2);
	free(util.base);
}

void test_resizeArray_shrinked_the_array_of_double_when_new_size_is_less_then_the_current_size(){
	int len = 2;
	struct arrayUtil util = create(DOUBLE_SIZE,3);
	double *aBase = (double*)malloc(DOUBLE_SIZE*3);
	aBase[0] = 0;
	aBase[1] = 0;
	aBase[2] = 0;
	util.base = (void*)aBase;

	util = resize(util,len);
	assertEqual(util.length,2);
	free(util.base);
}

void test_resizeArray_shrinked_the_array_when_new_size_is_less_then_the_current_size(){
	int len = 2;
	struct arrayUtil util = create(INT_SIZE,3);
	int *aBase = (int*)malloc(INT_SIZE*3);
	aBase[0] = 1;
	aBase[1] = 2;
	aBase[2] = 3;
	util.base = (void*)aBase;

	util = resize(util,len);
	assertEqual(util.length,2);
	free(util.base);
}


void test_resizeArray_expend_the_array_when_new_size_is_more_then_the_current_size(){
	int len = 6;
	struct arrayUtil util = create(INT_SIZE,3);
	int *aBase = (int*)malloc(INT_SIZE*3);
	aBase[0] = 1;
	aBase[1] = 2;
	aBase[2] = 3;
	util.base = (void*)aBase;

	util = resize(util,len);
	assertEqual(util.length,6);
	free(util.base);
}

void test_resizeArray_expend_the_array_of_char_when_new_size_is_more_then_the_current_size(){
	int len = 6;
	struct arrayUtil util = create(CHAR_SIZE,3);
	char *aBase = (char*)malloc(CHAR_SIZE*3);
	aBase[0] = 'a';
	aBase[1] = 'b';
	aBase[2] = 'c';
	util.base = (void*)aBase;

	util = resize(util,len);
	assertEqual(util.length,6);
	free(util.base);
}

void test_resizeArray_expend_the_array_of_float_when_new_size_is_more_then_the_current_size(){
	int len = 6;
	struct arrayUtil util = create(FLOAT_SIZE,3);
	float *aBase = (float*)malloc(FLOAT_SIZE*3);
	aBase[0] = 0.0000000;
	aBase[1] = 0.0000000;
	aBase[2] = 0.0000000;
	util.base = (void*)aBase;

	util = resize(util,len);
	assertEqual(util.length,6);
	free(util.base);
}

void test_resizeArray_expend_the_array_of_double_when_new_size_is_more_then_the_current_size(){
	int len = 6;
	struct arrayUtil util = create(DOUBLE_SIZE,3);
	double *aBase = (double*)malloc(DOUBLE_SIZE*3);
	aBase[0] = 0.0000000;
	aBase[1] = 0.0000000;
	aBase[2] = 0.0000000;
	util.base = (void*)aBase;

	util = resize(util,len);
	assertEqual(util.length,6);
	free(util.base);
}

void test_resizeArray_expend_the_array_and_intialized_the_new_element_with_zero(){
	int len = 6;
	struct arrayUtil util = create(INT_SIZE,3);
	int *aBase = (int*)malloc(INT_SIZE*3);
	aBase[0] = 1;
	aBase[1] = 2;
	aBase[2] = 3;
	util.base = (void*)aBase;

	util = resize(util,len);
	assertEqual(aBase[3],0);
	assertEqual(aBase[4],0);
	assertEqual(aBase[5],0);
}


void test_findIndex_gives_index_if_element_is_present_in_array_of_int(){
	int x=4,index;
	int A[] = {1,260,4};
	struct arrayUtil util = create(INT_SIZE,4);
	util.base = (void*)(A);
	
	index = findIndex(util,&x);
	assertEqual(index,2);
}

void test_findIndex_gives_index_if_element_is_present_in_array_of_float(){
	float x=8.111111;
	int index;
	float A[] = {4.111111,8.111111,12.111111,16.111111};
	struct arrayUtil util = create(INT_SIZE,4);
	util.base = (void*)(A);
	
	index = findIndex(util,&x);
	assertEqual(index,1);
}

void test_findIndex_gives_minusOne_if_element_is_not_present_in_array_of_float(){
	float x=9.111111;
	int index;
	float A[] = {4.111111,8.111111,12.111111,16.111111};
	struct arrayUtil util = create(INT_SIZE,4);
	util.base = (void*)(A);
	
	index = findIndex(util,&x);
	assertEqual(index,-1);
}

void test_findIndex_gives_index_if_element_is_present_in_array_of_char(){
	int index;
	char x = 'a';
	char A[] = {'a','b','c'};
	struct arrayUtil util = create(CHAR_SIZE,3);
	util.base = (void*)(A);
	
	index = findIndex(util,&x);
	assertEqual(index,1);
}

void test_findIndex_gives_index_if_element_is_present_in_array_of_double(){
	int index;
	double x = 1.1111111;
	double A[] = {1.1111111,2.2222222,3.3333333};
	struct arrayUtil util = create(DOUBLE_SIZE,4);
	util.base = (void*)(A);
	
	index = findIndex(util,&x);
	assertEqual(index,0);
}


// void test_findIndex_gives_minusOne_if_element_is_not_present_in_array_of_string(){
// 	char *a1 = "abc";
// 	char *a2 = "def";
// 	int index;
// 	char item[] = "abc";
// 	char *A[] = {a1,a2};
// 	struct arrayUtil util = create(CHAR_SIZE*3,2);
// 	printf("A = %p\n",*A);
// 	util.base = (void*)(A);
// 	index = findIndex(util,item);
// 	assertEqual(index,1);
// }

void test_findIndex_gives_minusOne_if_element_is_not_present_in_array(){
	struct arrayUtil a = create(4,3);
	int *aBase;
	int x=9,index;
	aBase = (int*)(a.base);
	aBase[0] = 4;
	aBase[1] = 8;
	aBase[2] = 12;

	index = findIndex(a,(void*)&x);
	assertEqual(index,-1);
}

void test_find_first_match_of_int_array(){
	int A[] = {3,16,24};
	void *first_ele;
	int hint = 4;
	struct arrayUtil util = create(4,3);
	int (*matchFunc)(void*, void*);
	matchFunc = &(isDivisable);
	util.base = (void*)A;
	first_ele = find_first_element(util,matchFunc,(void*)(&hint));
	assertEqual(*(int*)first_ele,16);
}

// void test_find_first_match_float(){
// 	float A[] = {8.160000,16.320000,24.480000};
// 	void *first_ele;
// 	float hint = 4.000000;
// 	struct arrayUtil util = create(sizeof(float),3);
// 	int (*matchFunc)(void*, void*);
// 	matchFunc = &(isDivisable);
// 	util.base = (void*)A;
// 	first_ele = findFirst(util,matchFunc,(void*)(&hint));

// 	assertEqual(*(float*)first_ele,8.1600000);
// }

void test_find_first_match_char_array(){
	char A[] = {'a','b','c'};
	void *first_ele;
	char hint = 'b';
	struct arrayUtil util = create(sizeof(char),3);
	int (*matchFunc)(void*, void*);
	matchFunc = &(isMatch);
	util.base = (void*)A;
	first_ele = find_first_element(util,matchFunc,(void*)(&hint));
	assertEqual(*(char*)first_ele,'b');
}

void test_find_last_match_in_char_array(){
	char A[] = {'a','b','c'};
	void *last_ele;
	char hint = 'a';
	struct arrayUtil util = create(sizeof(char),3);
	int (*matchFunc)(void*, void*);
	matchFunc = &(isMatch);
	util.base = (void*)A;
	last_ele = find_first_last_element(util,matchFunc,(void*)(&hint));
	assertEqual(*(char*)last_ele,'a');
}

void test_find_last_match_in_int_array(){
	int A[] = {3,16,9};
	void *last_ele;
	int hint = 8;
	struct arrayUtil util = create(sizeof(int),3);
	int (*matchFunc)(void*, void*);
	matchFunc = &(isDivisable);
	util.base = (void*)A;
	last_ele = find_first_last_element(util,matchFunc,(void*)(&hint));
	assertEqual(*(int*)last_ele,16);
}

void test_count_the_element_of_matching_criteria_in_int_array(){
	int A[] = {3,16,24};
	int count;
	int hint = 4;
	struct arrayUtil util = create(INT_SIZE,3);
	int (*matchFunc)(void*, void*);
	matchFunc = &(isDivisable);
	util.base = (void*)A;
	count = count_element(util,matchFunc,(void*)(&hint));
	assertEqual(count,2);
}

void test_count_the_element_of_matching_criteria_in_char_array(){
	char A[] = {'a','b','c'};
	int count;
	char hint = 'a';
	struct arrayUtil util = create(sizeof(char),3);
	int (*matchFunc)(void*, void*);
	matchFunc = &(isMatch);
	util.base = (void*)A;
	count = count_element(util,matchFunc,(void*)(&hint));
	assertEqual(count,1);	
}

