#!/bin/bash

cat /etc/passwd | sed '/#/d' | awk 'NR%2==0{ print$0 }' | cut -f 1 -d ":" | rev | sort -r | awk -v line1=$FT_LINE1 -v line2=$FT_LINE2 'NR>=line1 && NR<=line2' | tr '\n' ',' | sed 's/,/, /g' | sed 's/, $/./g' | tr -d '\n' 
