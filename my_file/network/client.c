#include <stdio.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <netinet/in.h>

int main ( void )
{
	int socket_d;
	struct sockaddr_in sock;
	socklen_t addr ;
	char *buf = NULL;

	sock.sin_family = AF_INET;
	sock.sin_port = 8136;
	sock.sin_addr.s_addr = inet_addr("172.16.5.177");

	addr = sizeof(sock);

	buf = (char *)malloc(sizeof(char)*25);

	socket_d = socket( AF_INET, SOCK_STREAM, 0 );
	if( -1 == socket_d){
		perror("sockrt failed\n");
		exit( 0 );
		}

	if( -1 == (connect( socket_d,(struct sockaddr *)&sock, addr))){
		perror("connection failed\n");
		exit( 0 );
		}
	
	while(1){
	printf("Enter the message to be sent\n");
	fgets(buf, 255, stdin);


	if( -1 ==(write(socket_d, buf, 1024))){
		perror("write failed\n");
		exit( 0 );
		}

	if( -1 == (read(socket_d, buf, 1024))){
		perror("read failed\n");
		exit( 0 );
		}
	 printf("%s\n",buf);
	}
	close ( socket_d );
	
	return 0;
}
