#include <stdio.h>
#include <stdlib.h>
#include "expr_assert.h"
#include "arrayUtil.h"
#include <string.h>

void test_one_plus_one_is_equal_to_2(){
	assertEqual(add(1,1),2);
};

void test_use_array_as_integer(){
	struct arrayUtil a1;
	int *aBase;
	a1.base = (int*)malloc(sizeof(int));
	aBase = (int *)(a1.base);
	aBase[0] = 5;
	assertEqual(aBase[0],5);
}

void test_create_a_array(){
	struct arrayUtil a = create(4,3);
	int *aBase;
	aBase = (int*)(a.base);
	assertEqual(aBase[0],0);
	assertEqual(a.length,3);
	assertEqual(a.typeSize,4);
}

void test_two_array_is_equal(){
	struct arrayUtil a1 = create(4,3);
	struct arrayUtil a2 = create(4,3);
	int *a1Base;
	int *a2Base;
	
	a1Base = (int*)(a1.base);
	a1Base[0] = 1;
	a1Base[1] = 2;
	a1Base[2] = 3;

	
	a2Base = (int*)(a2.base);
	a2Base[0] = 1;
	a2Base[1] = 2;
	a2Base[2] = 3;

	assertEqual(isEqual(a1,a2),1);

}

void test_resize_the_array(){
	struct arrayUtil a1 = create(4,3);
	int *a1Base;
	int len = 6;
	a1Base = (int*)(a1.base);

	a1Base[0] = 0;
	a1Base[1] = 1;
	a1Base[2] = 8;


	a1 = resize(a1,len);
	assertEqual(a1.length,6);
	assertEqual(a1Base[0],0);
	assertEqual(a1Base[1],1);
	assertEqual(a1Base[2],8);
	assertEqual(a1Base[3],0);
}

void test_findIndex_gives_index_if_element_is_present_in_array(){
	struct arrayUtil a = create(4,3);
	int *aBase;
	int x=8,index;
	aBase = (int*)(a.base);
	aBase[0] = 4;
	aBase[1] = 8;
	aBase[2] = 12;

	index = findIndex(a,&x);
	assertEqual(index,1);
}

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

void test_find_first_match(){
	struct arrayUtil a = create(4,3);
	int *aBase,hint;
	int *first_ele;
	aBase = (int*)(a.base);
	aBase[0] = 4;
	aBase[1] = 8;
	aBase[2] = 12;
	hint = 4;
	int *(*matchFunc)(void*, void*);
	matchFunc = &(isDivisable);

	first_ele = findFirst(a,matchFunc,(void*)(&hint));







}