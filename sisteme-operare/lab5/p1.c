#include<fcntl.h>
#define BUFSIZE 512
void mycopy( depe, pe)
char *depe, *pe;
{
	int depefd, pefd, nr, nw, n;
	char buf[BUFSIZE]; 
	if (( depefd=open( depe, O_RDONLY)) < 0) 
		err_sys( depe);
	if (( pefd=creat( pe, 0666)) < 0)
		err_sys( pe); 
	while(( nr=read( depefd, buf, sizeof( buf))) != 0) { 
		if ( nr < 0) err_sys("read");
		nw=0;
		do {
			if (( n=write( pefd, buf, nr))==1) 
			err_sys("write"); 
			nw += n;
		} while(nw < nr);
	}
	close(depefd);
	close(pefd);
}

void main(){
	mycopy("a.txt", "b.txt");
}
