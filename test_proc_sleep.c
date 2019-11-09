#include "types.h"
#include "stat.h"
#include "fcntl.h"
#include "user.h"
#include "date.h"
// #include "defs.h"

int main()
{
	printf(1, "Testing Process Sleep!\n");
	int sec = 1000;
	set_sleep(sec);
	exit();
}