#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

int main()
{

int n,fd,fd1;
char buf[50]; //Buffer of size 50

fd=open("test.txt",O_RDONLY); // opening a text file to read from it only
n=read(fd,buf,10); // reading buffer size of 10

//write(1,buf,10);// writing the buffer to the display

fd1 = open("target",O_CREAT|O_WRONLY,0642); // creating a new file in write only mode and giving the file permission parameters (0642)

write(fd1,buf,n);//writing into the new file
}
