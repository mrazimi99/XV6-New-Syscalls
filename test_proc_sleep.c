#include "types.h"
#include "stat.h"
#include "fcntl.h"
#include "user.h"

int main()
{
	printf(1, "Testing Process Sleep!\n");
	int sec = 10;
	set_sleep(sec*100);
	exit();
}