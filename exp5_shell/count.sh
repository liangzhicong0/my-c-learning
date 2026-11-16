#!/bin/bash
# 统计 /etc/passwd 中 root、system、normal 三类账户数量
source_file="/etc/passwd"
root=0; system=0; normal=0
for uid in $(cut -d: -f3 "$source_file"); do
    if [ "$uid" -eq 0 ]; then
        root=$((root + 1))
    elif [ "$uid" -lt 1000 ]; then
        system=$((system + 1))
    elif [ "$uid" -le 59999 ]; then
        normal=$((normal + 1))
    fi
	
done
echo "root=$root system=$system normal=$normal"

