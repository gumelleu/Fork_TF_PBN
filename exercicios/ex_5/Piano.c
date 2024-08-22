#include <stdio.h>
#include <stdlib.h>
#include<ncurses.h>

void playsound(char nota) {
    switch (nota) {
        case 'a':
            system("play -q /usr/share/sounds/sf2/FluidR3_GM.sf2 -P 0 -p 20 -n 'Piano' -r 44100 -c 2 -f 32 -t 1000 -s 1 -a 0.5 -q 1 -L -12 -T 1 -O 1 -E 1 -X 0 -g 0 -z 0 -b 0 -C 0 -R 0 -Q 0 -w 0 -D 0 -V 0 -Y 0 -Z 0 -m 0 -K 0 -o 0 -l 0 -J 0 -F 0 -H 0 -I 0 -M 0 -N 0 -W 0 -U 0 -S 0 -B 0 -A 0 -j 0 -d 0 -e 0 -f 0 -k 0 -i 0 -h 0 -c 0 -v 0 -u 0 -t 0 -s 0 -r 0 -q 0 -p 0 -x 0 -y 0 -n 0 -a 0 -l 0 -j 0 -f 0 -d 0 -c 0 -b 0 -a 0 -q 0 -r 0 -s 0 -t 0 -u 0 -v 0 -w 0 -x 0 -y 0 -z 0 -A 0 -B 0 -C 0 -D 0 -E 0 -F 0 -G 0 -H 0 -I 0 -J 0 -K 0 -L 0 -M 0 -N 0 -O 0 -P 0 -Q 0 -R 0 -S 0 -T 0 -U 0 -V 0 -W 0 -X 0 -Y 0 -Z 0 -a 0 -b 0 -c 0 -d 0 -e 0 -f 0 -g 0 -h 0 -i 0 -j 0 -k 0