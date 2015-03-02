
#include <iostream>
#include <string>
#include <cstring>
#include <errno.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/socket.h>

using namespace std;

#define DEBUG_INFO(msg) \
    std::cerr << __FILE__ << ":" << __FUNCTION__ << ":" << __LINE__ << ":" << (msg) << std::endl

#define DEBUG_WARN(msg) \
    std::cerr << __FILE__ << ":" << __FUNCTION__ << ":" << __LINE__ << ":" << (msg) << std::endl; \
    if(errno) perror(msg)

#define DEBUG_EXIT(msg) \
    std::cerr << __FILE__ << ":" << __FUNCTION__ << ":" << __LINE__ << ":" << (msg) << std::endl; \
    if(errno) perror(msg); \
    exit(EXIT_FAILURE)

#define IPTRAVELER "127.0.0.1" 	/*Server IP */
#define IPTRAVELER_PORT 3600	/*Server TCP Port */
#define BUFFER_SIZE 1024 		/*size of buffer*/

int main(int argc,char *argv[])
{

    int fd = -1;
    int num1,num2;
    struct sockaddr_in server_addr;
    char buffer1[BUFFER_SIZE];
    string buffer2;
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(IPTRAVELER_PORT);
    server_addr.sin_addr.s_addr = inet_addr(IPTRAVELER);
    memset(&(server_addr.sin_zero), 0, 8);

    fd = socket(AF_INET, SOCK_STREAM, 0);


	if(connect(fd,(struct sockaddr *)&server_addr,sizeof(server_addr)) == -1){
        DEBUG_EXIT("connect");
		return 0;
	}
	/*===================ends start up of the network====================*/
    cout<< "Notice:"<<endl
    	<< "To ask for words explanations ,you may write them on" 	<< endl
    	<< "the screen and then press <Enter> key ."	<< endl
		<< "Once there are some new words appear on the screen,"	<< endl
		<< "they are answers the server sends you back , and  you"	<< endl
		<< "may ask for more words' explanations once you saw them."<< endl	<< endl ;
    while(true){
	memset(buffer1, 0, sizeof(buffer1));
        num1 = recv(fd,buffer1,sizeof(buffer1), 0);
	if(num1 >= 0)
	{
	  buffer1[num1] = 0;
        cout << "recv from server: " << buffer1 << endl;	  
	}
	else
	  {
	    DEBUG_EXIT("recv error");
	  }
    	cin>> buffer2;
       	num2 = send(fd,buffer2.c_str(),buffer2.length(),MSG_DONTWAIT);
	if(num2>=0)
	  {
	    buffer2[num2] = 0;
	    cout << "send string to server: " << buffer2 << endl;
	  }
	else
	  {
	    DEBUG_EXIT("send error");
	  }
       	if(buffer2.at(0)=='#')	break;
    }
	close(fd);
	return 0;
}
