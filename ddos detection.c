#include <string.h>
#include <stdio.h>
#include <dirent.h>
#include <malloc.h>


size_t file_list(const char *path, char ***ls) {
    size_t count = 0;
    DIR *dp = NULL;
    struct dirent *ep = NULL;
	system("cls");
    dp = opendir(path);
    if(dp == NULL ){
        fprintf(stderr, "no such directory: '%s'", path);
        return 0;
    }

    *ls = NULL;
    ep = readdir(dp);
    while(NULL != ep){
        count++;
        ep = readdir(dp);
    }

    rewinddir(dp);
    *ls = calloc(count, sizeof(char *));
	closedir(dp);
    return count;
}
int main() {

    char **files;
    size_t count;
    int i,k,arrlen,det;
    char string[1000];	
	char *str[]={"document.getElementById","document.getElementsByTagName","document.getElementsByClassName","element.setAttribute"};
	char *str1[]={"href","src","document.createElement","XMLHttpRequest"};
    count = file_list("C:/Users/user/AppData/Local/Google/Chrome/User Data/Default/Extensions/test", &files);
    for (i = 0; i < count; i++) {
       // printf("%s\n", files[i]);
    }
       //printf("%d",count);
    for(i=0;i<4;i++)
    {
    	for(k=0;k<count;k++)
    	{    
			fgets(string,sizeof(string),fopen("C:/Users/user/AppData/Local/Google/Chrome/User Data/Default/Extensions/test/%s",files[k]));
    		if(strcmp(string,str[i]))
    		 {  
		  	 	 if(strcmp(string,".src"))
    				 { 
    	  					printf("\n\nMALLICUS ACTION");
    	  					return;
        		 
        			 }
        	 }
           if(strcmp(string,str1[i]))
    		 { 		
    	  		printf("\n\nMALLICUS ACTION");
    	  			return;      	 
        	 }
   	    }
    }
   printf("\n\n legistmate user");         
		
}
