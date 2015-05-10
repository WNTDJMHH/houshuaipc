#include <sys/types.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

#define BUFF_LEN 1024

int main()
{
   char filename[]="word.txt";
   int fd=-1;
   char buff[BUFF_LEN];
   fd=open(filename,O_CREAT|O_RDWR,S_IRWXU|S_IRWXG);
   if(-1==fd)
   {
     perror("open file:");
     return -1;   
   }
   
   //ssize_t rd_size=read(fd,buff,BUFF_LEN);
   //fprintf(stdout,"read size is %d, and the buff is %s",rd_size,buff);
   
   char buffc[]="this is the data from write buff";
   ssize_t wr_size=write(fd,buffc,sizeof(buffc));
   if(wr_size!=sizeof(buffc))
      perror("write file fiaile:"); 
   off_t offset=-1;
   offset=lseek(fd,100,SEEK_SET);
   if(-1==offset)
   {
      perror("lseek file:");
      exit(1);
   }
   printf("offset :%d\n",offset);
   wr_size=write(fd,"houshuai",10 );
    
   if(wr_size!=10)
      perror("write2 file fiaile:");
   
   int res_cl=close(fd);
   if(-1==res_cl)
   {
     perror("close file:");
     return -1;
   }
   return 0;
}
