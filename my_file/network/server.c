#include <stdio.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <netinet/in.h>

int main (void )
{
    int socket_d;
	int new_socket_d;
    struct sockaddr_in sock;
    socklen_t addr ;
    char *buf = NULL;

    sock.sin_family = AF_INET;
    sock.sin_port = 54032;
    sock.sin_addr.s_addr = INADDR_ANY;

	addr = sizeof(sock);

    buf = (char *)malloc(sizeof(char)*1024);

    socket_d = socket( AF_INET, SOCK_STREAM, IPPROTO_TCP );
    if( -1 == socket_d){
        perror("sockrt failed\n");
        exit( 0 );
        }
	
	if( -1 == (bind(socket_d,(struct sockaddr *)&sock, addr))){
		perror("bind failed\n");
		exit( 0 );
		}
	
	if(	-1 == (listen(socket_d,50))){
		perror("listen failed\n");
		exit( 0 );
		}

	if(-1 == (new_socket_d = (accept(socket_d, (struct sockaddr *)&sock, &addr)))){
		perror("accept failed\n");
		exit( 0 );
		}
	
	if( -1 == (read(new_socket_d, buf, 1024))){
        perror("read failed\n");
        exit( 0 );
        }
	
	printf("%s\n",buf);
    printf("Enter the message to be sent\n");
    fgets(buf, 1024, stdin);

	
	 if( -1 ==(write(new_socket_d, buf, 1024))){
        perror("write failed\n");
        exit( 0 );
        }

	close( new_socket_d);
	close ( socket_d);
	return 0;
}













