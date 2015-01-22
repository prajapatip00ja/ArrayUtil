#include <stdio.h>
int main(int argc, char const *argv[])
{
	int a=10;
	float *ptr;
	printf("%p",(void*)a);

	//float c= (float)ptr;
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


void *find_first_last_element(struct arrayUtil util,int (*matchFunc)(void*,void*),void* hint){
	void *ele;
	int i,status;
	char *utilBase = (char*)(util.base);

	for( i=(util.length*util.typeSize); i>0; i = i-util.typeSize){
		printf("===item = %d\n",*(utilBase+(i-1)));

		status = (*matchFunc)(hint,(void*)(utilBase+(i-1)));
		if(status == 1){
			ele = (utilBase+(i-1));
			break;
		}
	}
	return ele;
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
	//assertEqual(*(int*)first_ele,16);
}

