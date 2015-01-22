#define INT_SIZE sizeof(int)
#include <stdio.h>
#include <stdlib.h>
#include "expr_assert.h"
#include "arrayUtil.h"
#include <string.h>

struct arrayUtil a;
struct arrayUtil b;

void test_one_plus_one_is_equal_to_2(){
	assertEqual(add(1,1),2);
};



void test_create_a_array(){
	int *aBase;
	a = create(INT_SIZE,3);
	aBase = (int*)(a.base);
	assertEqual(aBase[0],0);
	assertEqual(a.length,3);
	assertEqual(a.typeSize,4);
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


void test_findIndex_gives_index_if_element_is_present_in_array(){
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

// void test_findIndex_gives_minusOne_if_element_is_not_present_in_array_of_string(){
// 	char *a = "str";
// 	int index;
// 	char *A[] = {"str","mtr","iop","tyu"};
// 	struct arrayUtil util = create(INT_SIZE,4);
// 	util.base = (void*)(A);
	
// 	index = findIndex(util,a);
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

