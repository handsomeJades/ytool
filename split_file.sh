#! /bin/sh
CHUNK=30000
MAX=130691

i=0
while (($i<=$MAX))
do
   ((s=$i+1))
   ((e=$i+$CHUNK))
   #cho $s - $e

   cmd="sed -n '${s},${e}p' kyb.csv > kyb${s}-${e}.csv"
   eval $cmd
#   echo $command
#exec $command

   i=$e
done
