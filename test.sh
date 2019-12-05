#!/bin/bash

i="0"
ARG="0"
NUM_KO="0"
RES="x"
while [ "$i" -lt "$3" ]; do
	ARG="$(ruby -e "puts ("$1" .. "$2").to_a.shuffle.join(' ')")"
	RES="$(./push_swap "$ARG" | ./checker "$ARG")"
	if [ $RES == "KO" ]
	then
		NUM_KO=$[$NUM_KO+1]
	fi
	i=$[$i+1]
	echo $RES
done
echo $NUM_KO
