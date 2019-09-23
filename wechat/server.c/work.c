
#include "server.h"

typedef void WorkFunction( pack * );

void *work( void *recv )
{
    pack *p = (pack *)recv;

    WorkFunction menu[] = {registe, login, addfriend, deletefriend, showfriends, chatone, creategroup, inviteperson,
    addgroup, chatgroup, sendfile, showgroups, kickperson, quitgroup, chatonerecord, chatgrouprecord};

    if ( p->type >= 0 && p->type <= 15 ) {
        menu[p->type](p);
    }

}
