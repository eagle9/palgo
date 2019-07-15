# Read from the file file.txt and output all valid phone numbers to stdout.
#beats 100%, fishercode
#^ start, end$ . (o1|o2)
#\d digit 
#{reps}
grep -P '^(\d{3}-|\(\d{3}\) )\d{3}-\d{4}$' file.txt
