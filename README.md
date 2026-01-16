# EE533_Lab1
Setting up network and communication between server and client VMs

server.c -> Professor provided server side code, which kills after recieving and acknowledging one message

server -> C compiled executable file for server.c

server_real.c -> Modified server.c code for keeping the communication going after recieving one message. Server doesnt exit

server_real -> C compiled executable file for server_real.c

server_datagram.c -> server_real.c modified to support datagram socket instead of stream socket

server_datagram -> C compiled executable file for server_datagram.c
