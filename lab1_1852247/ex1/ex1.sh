#!/bin/bash

if [[ -z $1 && -z $2 && -z $3 ]];
then
		echo "Your input is null"
else
		echo $1 $2 $3 > ex1.txt
		echo -e "$(uname -a)" "$(lscpu)"  >> ex1.txt
fi
