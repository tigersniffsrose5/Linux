#include "client.h"

void chatgrouprecord()
{
    pack send_t;

    send_t.type = 15;
    printf("please enter the group's name which you enat to check the chat record:\n");
    scanf("%s", send_t.recv_name);
    strcpy(send_t.send_name, username);
    send(conn_fd, &send_t, sizeof(pack), 0);
}

void chatgroup_record( pack pack_t )
{
    printf("%s\n", pack_t.record);
}
