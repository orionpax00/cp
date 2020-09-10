#diff -w <(./sorted_segment < in1) ans1 || break
#diff -w <(./sorted_segment < in2) ans2 || break

for((i = 1; i <= 1000; ++i)); do
	echo $i
	./gen i > inp
	diff -w <(./sorted_segment < inp) <(./brute < inp) || break
done
