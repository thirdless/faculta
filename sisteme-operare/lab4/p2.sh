proiect(){
        cd ~/
        mkdir -p $1
        cd $1
        mkdir -p bin
        mkdir -p obj
        mkdir -p src
        mkdir -p inc
        > "$1.c"
        > "$1.h"
        > build.sh
        cd src
        > "$1_src.c"
        cd ../inc
        > "$1_inc.h"
}

proiectbasic(){
	cd ~/
	mkdir -p $1
	cd $1
	mkdir -p bin
	mkdir -p obj
	mkdir -p src
	mkdir -p inc
	> "$1.c"
	> "$1.h"
	> build.sh
}

proiectsingur(){
	cd ~/
	cd $1
	cd src
	> "$1_src.c"
	cd ../inc
	> "$1_inc.h"	
}

proiectdublu(){
	cd ~/
	cd $1
	cd inc
	> "$1_inc.h"
	cd ../src
	if ["$2" = "c++"]; then
		> "$1_src.cpp"
	else
		> "$1_src.c"
	fi
}

x=1

proiecttriplu(){
	cd ~/
	cd $1
	cd inc
	while [x -lt $3]
	do

	done
}

ajutor(){
	echo
}

compressed="$(echo $1 | sed -e 's/[^[:alnum:]\_\-]//g')"

if [[ ! -n "$1" || -n "$4" || "$compressed" != "$1" ]]; then
        echo Parametrii sunt setati incorect
        exit 0
elif [[ ! -n "$2" && "$1" = "--help" ]]; then
	ajutor
elif [[ ! -n "$2" && "$1" = "-h" ]]; then
	ajutor	
elif [[ ! -n "$3" ]];then
	proiectbasic $1
	proiecttriplu $1 $2 $3
elif [[ ! -n "$2" ]];then
	proiectbasic $1
	proiectdublu $1 $2
else
        proiectbasic $1
	proiectsingur $1 
fi
