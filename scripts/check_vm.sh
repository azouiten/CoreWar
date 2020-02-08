
#!/bin/sh
$1 $3 $4 $5 $6 > ourfile
tail -2 ourfile > sub
head -1 sub > sub1
var=`cat sub1`
tail -67 ourfile > sub
head -64 sub > ourfile
rm sub sub1
#cat ourfile
$2 $3 $4 $5 $6 -d $var > file
tail -64 file > tfile
diff -q tfile ourfile
