echo Enter your limit
read n
a=0
b=1
for(( i=0;i<n;i++ )){
		if (( i<=1 ))
		then
			echo -n $i" "  
		else
			(( c=$a+$b ))
			t=$a
			a=$b
			b=$c
			echo -n $c" "
		fi
}

<<OUTPUT
Enter your limit
10
0 1 1 2 3 5 8 13 21 34 
OUTPUT
