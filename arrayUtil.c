#include <stdio.h>
#include <stdlib.h>
#include "arrayUtil.h"
#include <string.h>

int add(int a,int b){
	return a+b;
}

struct arrayUtil create(int typeSize,int length){
	struct arrayUtil a;
	a.base = calloc(typeSize,length);
	a.typeSize = typeSize;
	a.length = length;
	return a;
}

int isEqual(struct arrayUtil a1,struct arrayUtil a2){
	int flag = 0;
	int *a1Base;
	int *a2Base,i;
	a1Base = (int*)(a1.base);
	a2Base = (int*)(a2.base);
	if(a1.typeSize == a2.typeSize && a1.length == a2.length){
		for(i = 0; i< a1.length ; i++){
			if(a1Base[i] == a2Base[i]){
				flag = 1;
			}
			else
				flag = 0;
		}
	}
	return flag;
}

struct arrayUtil resize(struct arrayUtil a1,int length){
	int i,size;
	int *a1Base;
	
	a1.base = realloc(a1.base,length);
	a1Base = (int*)(a1.base);

	if(length>a1.length){
		for(i = a1.length; i<length ; i++){
			a1Base[i] = 0;
		}
	}

	a1.length = length;	
	return a1;
}

void dispose(struct arrayUtil a1){
	int *a1Base;
	a1Base = (int*)(a1.base);
	free(a1Base);	
} 

int findIndex(struct arrayUtil a,void *x){
	int *aBase,i,index;
	int *ele;
	ele = (int*)x;
	aBase = (int*)(a.base);
	index = -1;
	for(i = 0; i<a.length; i++){
		if(aBase[i] == *ele)
			index = i;
	}
	return index;

}

int *isDivisable(void *hint, void *item){

}


void* findFirst(struct arrayUtil a, int *(*matchFunc)(void*,void*), void* hint){
	int i;
	void *ele;

	for( i = 0 ; i<a.length ; i++){
		
	}
	return 0;
}





