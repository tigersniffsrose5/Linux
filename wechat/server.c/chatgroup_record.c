#include "server.h"

void chatgrouprecord(pack *recv)
{
    int flag = 0;
    MYSQL_RES *res;   
    MYSQL_ROW row;

    if (mysql_real_query(&mysql, "select * from group_info", (unsigned long)strlen("select * from group_info"))) {  
        printf("mysql_real_query select failure!\n"); 
        exit(0);  
    }
    res = mysql_store_result(&mysql);
    if (NULL == res) {  
        printf("mysql_store_result failure!\n");  
        exit(0);  
    }
    while ((row = mysql_fetch_row(res))) {
        if ( strcmp(recv->recv_name, row[0]) == 0 ) {
            flag = 1;
            break;
        }
    }

    if ( flag != 1 ) {
        sprintf(recv->record, "no this group which named %s!", recv->recv_name);
        send(recv->send_fd, recv, sizeof(pack), 0);
        return ;
    }
    mysql_free_result(res);

    if (mysql_real_query(&mysql, "select * from group_info", (unsigned long)strlen("select * from group_info"))) {  
        printf("mysql_real_query select failure!\n"); 
        exit(0);  
    }
    res = mysql_store_result(&mysql);
    if (NULL == res) {  
        printf("mysql_store_result failure!\n");  
        exit(0);  
    }
    while ((row = mysql_fetch_row(res))) {
        if ( strcmp(recv->recv_name, row[0]) == 0 && strcmp(recv->send_name, row[1]) == 0 ) {
            flag = 2;
            break;
        }
    }

    if ( flag != 2 ) {
        sprintf(recv->record, "you isn't in this group which named %s!", recv->recv_name);
        send(recv->send_fd, recv, sizeof(pack), 0);
        return ;
    }
    mysql_free_result(res);

    if (mysql_real_query(&mysql, "select * from chatgroup_record", (unsigned long)strlen("select * from chatgroup_record"))) {  
        printf("mysql_real_query select failure!\n"); 
        exit(0);  
    }
    res = mysql_store_result(&mysql);
    if (NULL == res) {  
        printf("mysql_store_result failure!\n");  
        exit(0);  
    }
    while ((row = mysql_fetch_row(res))) {
        if ( strcmp(row[0], recv->recv_name)==0 ) {
            strcat(recv->record, row[1]);
            strcat(recv->record, " ");
            strcat(recv->record, row[2]);
            strcat(recv->record, "\n");
        }
    }

    mysql_free_result(res);
    send(recv->send_fd, recv, sizeof(pack), 0);

}
