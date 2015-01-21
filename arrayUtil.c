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
	char *a1Base;
	char *a2Base,i;
	a1Base = (char*)(a1.base);
	a2Base = (char*)(a2.base);

	if(a1.typeSize == a2.typeSize && a1.length == a2.length){
		for(i = 0; i< (a1.length*a1.typeSize); i++){
			if(a1Base[i] == a2Base[i]){
				flag = 1;
			}
			else
				flag = 0;
		}
	}
	return flag;
}

struct arrayUtil resize(struct arrayUtil util,int length){
	int i;
	char *utilBase;
	utilBase = (char*)(util.base);
	utilBase = realloc(utilBase,length*util.typeSize);

	if(length>util.length){
		for( i = (util.length*util.typeSize); i<(length*util.typeSize); i++){
			utilBase[i] = 0;
		}
	}

	util.length = length;	
	return util;
}

void dispose(struct arrayUtil a1){
	int *a1Base;
	a1Base = (int*)(a1.base);
	free(a1Base);	
} 

int findIndex(struct arrayUtil a,void *x){
	int i,j,index = -1;
	char *ele = (char*)x;
	char *aBase = (char*)(a.base);

	for(i = 0; i<(a.length*a.typeSize); i = i+a.typeSize){
	int count = 0;
		for(j = 0 ; j< a.typeSize; j++,i++){
			if(aBase[i] == ele[j]){
				count = count+1;
			}
		}
		i = i-a.typeSize;
		if(count==a.typeSize)
			index = (i+1)/(a.typeSize);
	}
	return index;
}

int isDivisable(void* hint, void* item){
	if((int)item%*(int*)hint==0){
		return 1;
	}
	return 0;
}


void *findFirst(struct arrayUtil util, int (*matchFunc)(void*,void*), void* hint){
	int ele;
	int i,status;
	int *utilBase = (int*)(util.base);

	for( i = 0 ; i<(util.length); i++){
		status = (*matchFunc)(hint,(void*)utilBase[i]);
		if(status == 1){
			ele = utilBase[i];
			break;
		}
	}
	return (void*)ele;
}




