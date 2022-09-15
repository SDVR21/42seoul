
val1=2
if [ $# -ne ${val1} ] ; then
        echo "./test.sh [BS] [filename]"
        exit 1
fi

make BS=$1
./get_next_line $2 > gnl.txt
diff -a --suppress-common-lines $2 gnl.txt
echo "origin text ---------------------------------------------"
cat $2
echo "gnl text ---------------------------------------------"
cat gnl.txt
echo "---------------------------------------------"
make clean
