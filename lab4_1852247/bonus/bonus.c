#include <stdio.h>
#include <stddef.h>

#define MEMORY_SIZE 10000

char memory[MEMORY_SIZE];

struct myBlock{
	size_t size;
	struct myBlock *next;
	int isFree;
};

struct myBlock *myList = (void *)memory;

void init() {
	myList->size = MEMORY_SIZE - sizeof(struct myBlock);
	myList->isFree = 1;
	myList->next = NULL;
}

void split(struct myBlock *available, size_t size) {
	struct myBlock *pNew = (void *)((void *)available + size + sizeof(struct myBlock));
	pNew->isFree = 1;
	pNew->next = available->next;

	available->size = size;
	available->isFree = 0;
	available->next = pNew;
}

void *MyMalloc(size_t bytes) {
	struct myBlock *cur, *prev;
	void *result;

	// if there is nothing, initializing the memory
	if(myList->size == 0) {
		init();
	}

	cur = myList;

	// Check if the block can be used for the allocation or not
	while(((cur->size < bytes) || (cur->isFree == 0)) && (cur->next != NULL)) {
		prev = cur;
		cur = cur->next;
	}

	if (cur->size == bytes) {
		// the available memory equals to the required size
		result = (void *)(++cur);
		cur->isFree = 0;
		return result;
	} else if(cur->size > (bytes + sizeof(struct myBlock))) {
		// the available memory larger than the required size
		split(cur, bytes);
		result = (void *)(++cur);
		return result;
	} else {
		result = NULL;
		return result;
	}
}

// merge the two consecutive free block
void merge() {
	struct myBlock *cur, *prev;
	cur = myList;
	while(cur->next != NULL) {
		if(cur->isFree != 0 && cur->next->isFree != 0) {
			cur->size += cur->next->size + sizeof(struct myBlock);
			cur->next = cur->next->next;
		}
		prev = cur;
		cur = cur->next;
	}
}

void MyFree(void* ptr) {
	if (((void *)memory <= ptr) && (ptr <= (void *)(memory + 10000))) {
		struct myBlock *cur = ptr;
		cur--;
		cur->isFree = 1;
		merge();
	}
	ptr = NULL;
}



int main() {
	char *p = MyMalloc(200);
	char *p2 = MyMalloc(100);
	MyFree(p2);
	printf("%p\n", p);
	

	return 0;
}