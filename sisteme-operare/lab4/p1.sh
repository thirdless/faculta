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

compressed="$(echo $1 | sed -e 's/[^[:alnum:]\_\-]//g')"

if [[ ! -n "$1" || -n "$2" || "$compressed" != "$1" ]]; then
        echo Parametrii sunt setati incorect
        exit 0
else
        proiect $1      
fi

