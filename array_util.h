typedef int(MatchFunc)(void *,void *);

typedef void(ConvertFunc)(void *,void *,void *);

typedef void(OperationFunc)(void* , void*);

typedef void*ReducerFunc(void* hint, void* previousItem, void* item);


typedef struct array_util{
	void *base;
	int typeSize;
	int length;
}ArrayUtil;


int areEqual(ArrayUtil, ArrayUtil);

int findIndex(ArrayUtil, void* element);

void dispose(ArrayUtil);

int isEven(void*, void*);

void* findFirst(ArrayUtil util, MatchFunc* match, void* hint);

void* findLast(ArrayUtil util, MatchFunc* match, void* hint);

int count(ArrayUtil util, MatchFunc* match, void* hint);

int filter(ArrayUtil util, MatchFunc* match, void* hint, void** destination, int);

void map(ArrayUtil, ArrayUtil, ConvertFunc*, void*);

void forEach(ArrayUtil, OperationFunc*, void*);

void* reduce(ArrayUtil, ReducerFunc*, void*, void*);
