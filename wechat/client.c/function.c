#include "client.h"

//typedef void Function();

void work()
{
    printf("*********************************\n");
    printf("*****  0.exit               *****\n");
    printf("*****  1.message box        *****\n");
    printf("*****  2.add friend         *****\n");
    printf("*****  3.delete friend      *****\n");
    printf("*****  4.show friends       *****\n");
    printf("*****  5.chatone            *****\n");
    printf("*****  6.create group       *****\n");
    printf("*****  7.invite person      *****\n");
    printf("*****  8.add group          *****\n");
    printf("*****  9.chat in group      *****\n");
    printf("*****  10.send file         *****\n");
    printf("*****  11.show groups       *****\n");
    printf("*****  12.kick person       *****\n");
    printf("*****  13.quit group        *****\n");
    printf("*****  14.chatone record    *****\n");
    printf("*****  15.chatgroup record  *****\n");
    printf("*********************************\n");
}

int function()
{
    char choice_t[101];
    int choice;
    void (* Work[])() = {deal_pack, addfriend, deletefriend, showfriends, chatone, creategroup, inviteperson, addgroup, chatgroup, sendfile, showgroups, 
    kickperson, quitgroup, chatonerecord, chatgrouprecord};

    do {
        work();
        printf("*****choice:\n");
        scanf("%s", choice_t);getchar();
        choice = get_choice(choice_t);
        
        if ( choice <= 15 && choice >= 1 ) {
            Work[choice]();
        }

    }while (choice != 0);
    return 0;
}

