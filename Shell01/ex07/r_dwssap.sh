cat /etc/passwd | sed '/^#/'d | awk '!(NR%2)' | cut -d ":" -f1 | rev | sort -r | awk "NR >= $FT_LINE1 && NR <= $FT_LINE2" | xargs | sed 's/ /, /g' | sed 's/$/./' | tr -d '\n'
