
#include "server.h"


void *work( void *recv )
{
    pack *p = (pack *)recv;

    void (* WorkFunction[])( pack * ) = {registe, login, addfriend, deletefriend, showfriends, chatone, creategroup, inviteperson,
    addgroup, chatgroup, sendfile, showgroups, kickperson, quitgroup, chatonerecord, chatgrouprecord};

    if ( p->type >= 0 && p->type <= 15 ) {
        WorkFunction[p->type](p);
    }

}
