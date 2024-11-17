#include "Heap.h"
int main()
{
	HP hp;
	InitHP(&hp);
	HPPush(&hp, 15);
	HPPush(&hp, 18);
	HPPush(&hp, 19);
	HPPush(&hp, 25);
	HPPush(&hp, 28);
	HPPush(&hp, 34);
	HPPush(&hp, 65);
	HPPush(&hp, 49);
	HPPush(&hp, 27);
	HPPush(&hp, 37);
	HPPush(&hp, 10);
	HPPop(&hp);

	return 0;
}