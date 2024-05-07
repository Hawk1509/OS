#simple calculator
echo "Enter numbers:"
read a
read b
while true
	do
		echo "1.Addition"
		echo "2.Subtraction"
		echo "3.Division"
		echo "4.Multiplication"
		echo "Enter choice:"
		read n
		case $n in
			1)
			s=$((a+b))
			echo "Sum is: $s"
			;;
			2)
			s=$((a-b))
			echo "Difference is: $s"
			;;
			3)
			s=$((a/b))
			echo "Division is: $s"
			;;
			4)
			s=$((a*b))
			echo "Product is: $s"
			;;
		esac
	done
