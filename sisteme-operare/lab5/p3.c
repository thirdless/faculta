#include<fcntl.h>
#include "hdr.h"
int fdR, fdW;
char c;
void main( int argc, char * argv[])
{
	if ( argc != 3) exit(1);
	if (( fdR=open( argv[1], O_RDONLY)) == -1) err_sys( "Eroare open1\n"); 
	if (( fdW=open( argv[2], O_WRONLY)) == -1) err_sys( "Eroare open2\n"); 
	//fork(); 
	rd_wr(); exit(0); 
}
void rd_wr(){
	for ever{
		if ( read( fdR, &c, 1) == 0) return; 
		write( fdW, &c, 1);
	}
}
