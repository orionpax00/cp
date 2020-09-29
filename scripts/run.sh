for((i = 1; i <= 1000; ++i)); do
	echo $i
	./gen $i > int
	diff -w <(./brute_b < int) <(./b < int) || break; 
done
