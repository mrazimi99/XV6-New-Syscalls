#include "types.h"
#include "stat.h"
#include "fcntl.h"
#include "user.h"

int main()
{
	if(fork() == 0) // child
	{
		if(fork())
		{
			printf(1, "My parent pid is : %d\n", get_parent_id());
			printf(1, "My pid is : %d\n", getpid());
			printf(1, "Children of process %d :\n", getpid());
			get_children(getpid());
			printf(1, "-----------\n");
		}
		else
		{
			sleep(100);
			exit();
		}
		
	}
	else
	{
		if(fork() != 0) // parent
		{
			sleep(10);
			printf(1, "Children of process %d :\n", getpid());
			get_children(getpid());
			printf(1, "-----------\n");
			printf(1, "All grandchildren of process %d :\n", getpid());
			get_grandchild(getpid());
			printf(1, "-----------\n");
			wait();
			wait();
		}
	}
	wait();
	exit();
}

// int main()
// {
// 	if(fork() == 0) // child
// 	{
// 		fork();
// 		printf(1, "My parent pid is : %d\n", get_parent_id());
// 	}
// 	else
// 	{
// 		if(fork() != 0) // parent
// 		{
// 			get_grandchild(getpid());
// 		}
// 	}

// 	if(getpid() == 3)
// 	{
// 		get_grandchild(getpid());
// 		wait();
// 		wait();
// 	}
// 	if (getpid() == 4)
// 	{
// 		get_grandchild(getpid());
// 		get_grandchild(3);
// 		wait();
// 	}
// 	exit();
// }