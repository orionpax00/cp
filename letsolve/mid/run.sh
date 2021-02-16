for((i = 10; i <= 1000; ++i)); do
	echo $i
	./gen $i > int
	diff -w <(./brute < int) <(./binary-search < int) || break; 
done
