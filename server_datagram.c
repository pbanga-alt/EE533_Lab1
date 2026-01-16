/* A simple server in the internet domain using TCP
   The port number is passed as an argument */
#include <stdio.h>
#include <sys/types.h> 
#include <sys/socket.h>
#include <netinet/in.h>

void error(char *msg)
{
    perror(msg);
    exit(1);
}

/*void dostuff(int sockfd)
{
     bzero(buffer,256);
     n = read(newsockfd,buffer,255);
     if (n < 0) error("ERROR reading from socket");
     printf("Here is the message: %s\n",buffer);
     n = write(newsockfd,"I got your message",18);
     if (n < 0) error("ERROR writing to socket");

}*/


int main(int argc, char *argv[])
{
     int pid, sock, portno, clilen, fromlen;
     char buf[256];
     struct sockaddr_in serv_addr, cli_addr, from;
     int n;
     if (argc < 2) {
         fprintf(stderr,"ERROR, no port provided\n");
         exit(1);
     }
     sock = socket(AF_INET, SOCK_DGRAM, 0);
     if (sock < 0) 
        error("ERROR opening socket");
     bzero((char *) &serv_addr, sizeof(serv_addr));
     portno = atoi(argv[1]);
     serv_addr.sin_family = AF_INET;
     serv_addr.sin_addr.s_addr = INADDR_ANY;
     serv_addr.sin_port = htons(portno);
     if (bind(sock, (struct sockaddr *) &serv_addr,
              sizeof(serv_addr)) < 0) 
              error("ERROR on binding");
     listen(sock,5);
     clilen = sizeof(cli_addr);
     fromlen = sizeof(struct sockaddr_in); 
     while (1)
     {
       n = recvfrom(sock,buf,1024,0,(struct sockaddr *)&serv_addr,&fromlen); 
       if (n < 0) error("recvfrom"); 
       printf("Here is the message: %s\n",buf);
       n = sendto(sock,"Got your message ",17, 0,(struct sockaddr *)&serv_addr,fromlen);
       if (n  < 0) error("sendto"); 
     } /* end of while */
return 0;
}
