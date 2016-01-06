typedef int(*MatchFunc)(void *,void *);

typedef struct array_util{
	void *base;
	int typeSize;
	int length;
}ArrayUtil;

ArrayUtil create(int ,int );
int areEqual(ArrayUtil, ArrayUtil);
ArrayUtil resize(ArrayUtil, int);
int findIndex(ArrayUtil, void* element);
void dispose(ArrayUtil);
int isEven(void*, void*);
void* findFirst(ArrayUtil util, MatchFunc* match, void* hint);
void* findLast(ArrayUtil util, MatchFunc* match, void* hint);
int count(ArrayUtil util, MatchFunc* match, void* hint);
int filter(ArrayUtil util, MatchFunc* match, void* hint, void** destination, int);