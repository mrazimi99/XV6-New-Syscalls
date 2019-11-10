#include "types.h"
#include "x86.h"
#include "defs.h"
#include "date.h"
#include "param.h"
#include "memlayout.h"
#include "mmu.h"
#include "proc.h"
#include "stat.h"

int
sys_fork(void)
{
  return fork();
}

int
sys_exit(void)
{
  exit();
  return 0;  // not reached
}

int
sys_wait(void)
{
  return wait();
}

int
sys_kill(void)
{
  int pid;

  if(argint(0, &pid) < 0)
    return -1;
  return kill(pid);
}

int
sys_getpid(void)
{
  return myproc()->pid;
}

int
sys_sbrk(void)
{
  int addr;
  int n;

  if(argint(0, &n) < 0)
    return -1;
  addr = myproc()->sz;
  if(growproc(n) < 0)
    return -1;
  return addr;
}

int
sys_sleep(void)
{
  int n;
  uint ticks0;

  if(argint(0, &n) < 0)
    return -1;

  acquire(&tickslock);
  ticks0 = ticks;
  while(ticks - ticks0 < n){
    if(myproc()->killed){
      release(&tickslock);
      return -1;
    }
    sleep(&ticks, &tickslock);
  }
  release(&tickslock);
  return 0;
}

// return how many clock tick interrupts have occurred
// since start.
int
sys_uptime(void)
{
  uint xticks;

  acquire(&tickslock);
  xticks = ticks;
  release(&tickslock);
  return xticks;
}

int sys_count_num_of_digits(void)
{
	struct proc* proceess_current = myproc();
	int num = proceess_current->tf->edx;

	int result = 1;
	while(num /= 10)
		++result;

	cprintf("Num of digits are : %d\n", result);
	
	return 1;
}

int sys_set_sleep(void)
{
  int time_secs;
  uint ticks_;

  struct rtcdate past, now;
  cmostime(&past);

  ticks_ = ticks;

  if(argint(0, &time_secs) < 0)
    return -1;

  while(ticks - ticks_ < time_secs)
  {
	sti();
  }
  cmostime(&now);
  cprintf("Differnce time is : %d\n", now.second - past.second);
  return 0;
}

int sys_get_parent_id(void)
{
	struct proc* cur = myproc();
	return cur->parent->pid;
}

int sys_get_children(void)
{
	int pid;
	if(argint(0, &pid) < 0)
    	return -1;
	
	int* children = get_children(pid);
	int i = 0;

	while (children[i])
	{
		cprintf("%d", children[i++]);
	}
	cprintf("\n");
	return 1;
}

int sys_get_grandchild(void)
{
	int pid;
	if(argint(0, &pid) < 0)
    	return -1;
	
	int* children = get_grandchild(pid);
	int i = 0;

	while (children[i])
	{
		cprintf("%d", children[i++]);
	}
	cprintf("\n");
	return 1;
}