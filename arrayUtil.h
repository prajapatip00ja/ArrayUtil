int add(int a,int b);

struct arrayUtil {
	void *base;
	int typeSize;
	int length;
};

struct arrayUtil create(int typeSize,int length);
int isEqual(struct arrayUtil a1,struct arrayUtil a2);
struct arrayUtil resize(struct arrayUtil a1,int length);
int findIndex(struct arrayUtil a1,void *x);
int (isDivisable)(void*, void*);
int (isMatch)(void*,void*);
void *find_first_element(struct arrayUtil a, int (*matchFunc)(void*,void*), void* hint);
void *find_first_last_element(struct arrayUtil util,int (*matchFunc)(void*,void*),void* hint);
int count_element(struct arrayUtil util,int (*matchFunc)(void*,void*),void* hint);