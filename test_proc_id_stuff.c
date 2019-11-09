#include "types.h"
#include "stat.h"
#include "fcntl.h"
#include "user.h"

int main()
{
	// int pid_parent;
	if(fork() == 0)
	{
		printf(1, "My parent pid is : %d\n", get_parent_id());
	}
	else
	{
		if(fork() != 0){
			get_children(getpid());
		wait();
		wait();
		
	}
	}
	exit();

}