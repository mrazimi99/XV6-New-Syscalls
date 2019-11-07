#include "types.h"
#include "stat.h"
#include "user.h"
#include "fcntl.h"

int main(int argc, char* argv[])
{
	write(1, "Testing count number of digits!\n", 33);
	int num = atoi(argv[1]);
	write(1, "The number is ", 15);
	write(1, argv[1], sizeof(argv[1]));
	write(1, "\n", 2);

	int temp_val;
	__asm ("movl %%edx, %0" : "=r"(temp_val));
	__asm("movl %0, %%edx" : :  "r"(num));
	__asm("movl $22, %eax");
	__asm("int $64");
	__asm("movl %0, %%edx" : : "r"(temp_val));
	
	exit();
}