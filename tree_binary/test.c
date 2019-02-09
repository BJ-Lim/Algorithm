#include <stdio.h>

#define TEST char

int main(){
#if TEST == int
	printf("test!\n");
#endif
}
