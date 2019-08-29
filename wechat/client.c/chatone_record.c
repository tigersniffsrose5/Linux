#include "client.h"

void chatonerecord()
{
    pack send_t;
    
    send_t.type = 14;
    printf("please enter the person's name which you want to check the chat record:\n");
    scanf("%s", send_t.recv_name);
    strcpy(send_t.send_name, username);
    send(conn_fd, &send_t, sizeof(pack), 0);
}

void chatone_record( pack pack_t )
{
    printf("%s\n", pack_t.record);
}
