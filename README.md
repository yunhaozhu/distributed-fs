Distributed File System

run make to build udp library server

create a new image: 
    gcc mkfs.c -o mkfs
    ./mkfs -f test.img

to run client:
    make client
    export LD_LIBRARY_PATH=.
    client

test:
    sh runtests.sh