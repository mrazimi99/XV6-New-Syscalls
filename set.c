#include "types.h"
#include "stat.h"
#include "user.h"

static char global_path[4096]; // the PATH variable

int main(int argc, char *argv[])
{
  int path_length = 0;

  if(argc != 3){
    printf(1, "Unsuffiecient PATH command vars given! \n");
    exit();
  }

  //the first one must be PATH
  if(strcmp("PATH", argv[1]) != 0){
    printf(1, "First arg isn't PATH! Check your command! \n");
    exit();
  }

  path_length = strlen(argv[2]);
  
  if(path_length > 4095){
    printf(1, "Decrease PATH length!\n");
    exit();
  }
  memset(global_path, 0, 4096*sizeof(char));
  memmove(global_path, argv[2], path_length * sizeof(char));
  global_path[path_length] = '\0';

  //
  //set the PATH
  set_path(global_path);

  exit();
}