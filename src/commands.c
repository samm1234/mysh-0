#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include "commands.h"

#define MAX 10000

int do_cd(int argc, char** argv) {
  if (!validate_cd_argv(argc, argv))
	return -1;


	int return_stat;
	struct stat file_info;
	mode_t file_mode;

  
  if((return_stat=stat(argv[1],&file_info))==-1)
	return -1;


  file_mode=file_info.st_mode;
  if (S_ISDIR(file_mode)) 
	int a = chdir(argv[1]);

  return 0;
}

int do_pwd(int argc, char** argv) {
  	char name[MAX];
  if (!validate_pwd_argv(argc, argv))
    return -1;
  else
	getcwd(name,MAX);
  printf("now directory name : %s\n",name);
  return 0;
}

int validate_cd_argv(int argc, char** argv) {
  if(argc==2)
{
	if((strcmp(argv[0],"cd"))==0)
 	return 1;
  else
	return 0;	
}
else
return 0;
}

int validate_pwd_argv(int argc, char** argv) {
  if(argc==1)
{
	if((strcmp(argv[0],"pwd"))==0)
	return 1;
  else
  	return 0;
}
else
return 0;
}
