#!/bin/sh
for i in $(seq 1 50);
do
	python3 map.py 25 25 50 > ./maps/map$i.txt
done
