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
else
        echo "?"
        #proiect $1 
fi
