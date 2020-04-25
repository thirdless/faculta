void main(){
	int pid;
	printf("Fiul: incepe executia \n"); 
	pid = getpid();
	printf("Fiul: %d se termina\n", pid);
	exit(pid);
}
