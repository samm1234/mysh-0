#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "utils.h"
void mysh_parse_command(const char* command,
                        int *argc, char*** argv)
{	
	int len=strlen(command);	
	char* token=NULL;
	char tmp[8096];
	int i=0;
	*argc=0;
	
	*argv=(char**)malloc(10000*sizeof(char*));
	
	for(int i=0;i<=len;i++)
	{	
		if(i==len)
			tmp[i]='\0';
		else
			tmp[i]=command[i];
	}

	token=strtok(tmp," \t\n");

		if(token==NULL) 
		{
			(*argv)[*argc] = (char*)malloc(10000*sizeof(char));
			strcpy((*argv)[*argc],"");
			*argc+=1;
		}

		while(token!=NULL)
		{
			(*argv)[*argc] = (char*)malloc(10000*sizeof(char));
			strcpy((*argv)[*argc],token);
			*argc+=1;

		token=strtok(NULL," ");
		}
}
