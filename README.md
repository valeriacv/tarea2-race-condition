# tarea2-race-condition

## Tarea 1  
El programa busca explotar una debilidad de condición de carrera de el programa vulp, tratando de cambiar un archivo de root y consiguiendo permisos de root 

## Tarea 2 
Se le hace una modificación al archivo vulp, tratando de crear más codiciones de carrera con el archivo, preguntando constantemente si se tiene acceso a el

## Tarea 2
Se le hace una modificación al archivo vulp original, removiendo los permisos de root del usuario y dandoselos justa antes del momento en que los va a necesitar


## Como se ejecuta
- Se corre el programa de ataque.c en background para que de forma constante este intentando crear un link de un archivo x a un archivo de root 

- Se corre el script de monitor.sh para que que corra el programa vulp e inserte la información que queremos.