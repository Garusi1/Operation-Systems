/****

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

***/

#include <stdio.h>
#include <stdlib.h>
// // #include <unistd.h>
// #include <string.h>

// #include <stdio.h>

// #include <stdlib.h>

// #include <fcntl.h>

 

// #include <sys/uio.h>

// #include <sys/types.h>

// #include <unistd.h>

// #include <signal.h>
// #include <string.h>

// #include <stdio.h>

// #include <stdlib.h>

// #include <fcntl.h>

// #include <sys/uio.h>

// #include <sys/types.h>

// #include <unistd.h>

// #include <signal.h>

// #include <sys/fcntl.h>
// #include "md5.h"

int isMD5=0;

void isMd5 (char md []){
    int j=0;
    int count=0;
   while(md[j]!='\0'){
       count++;
       j++;

   }
   
    if (count==32) isMD5= 1;
    else isMD5= 0;
    
}


int main()
{
    int pid=0;
    int mypipedf[2];
    char buf [32];
    char str [20];
    
    int ret;
    ret = pipe(mypipedf);
    if(ret==-1)
    {
        perror("error");
        exit(-1);
    }
    
    
    
    pid = fork();
    
    if(pid==0){ 
    //child process
    sleep(2);
    read(mypipedf[0],buf,32);
    const char* ans = md5(buf).c_str;

    signal (SIGTERM, isMd5(ans));

    
    write(mypipedf[1], ans, 32);
    printf ("ans: %s ",ans);
    
    
    }
    else{
    //parent process
        printf("pls enter num");
        scanf("%s", str);
        write(mypipedf[1], str, 20);
        sleep(2);
        read(mypipedf[0],buf,32);
        
            printf("%s",buf);
    }
    
    printf("Hello World");

    return 0;

}