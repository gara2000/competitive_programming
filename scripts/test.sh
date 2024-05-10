DIRNAME=$(dirname $0)
cd $DIRNAME/../data

for i in *.in; do
	echo  "=== $i ==="
	../a.out < $i 
	echo
	echo "---Comparison:"
	../a.out < $i > ${i%%in}ans
	diff ${i%%in}ans ${i%%in}out
done