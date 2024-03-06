n=8
while (( n!=0 ))
do
	echo 1: ADDITION
	echo 2: SUBTRACTION
	echo 3: MULTIPLICATION
	echo 4: DIVISION
	echo 5: MODULUS
	echo ENTER CHOICE: 
	read n
	case $n in
		1)
		echo Enter num1
		read a
		echo Enter num2
		read b
		area=`echo $a+$b |bc`
		echo Sum of the $a and $b = $area;;
		2)
		echo Enter num1
		read a
		echo Enter num2
		read b
		C=`echo $a-$b |bc`
		echo Difference between $a and $b = $C;;
		3)
		echo Enter num1
		read a
		echo Enter num2
		read b
		(( A= $a*$b ))
		echo Product of $a and $b = $A;;
		4)
		echo Enter num1
		read a
		echo Enter num2
		read b
		(( A=$a/$b ))
		echo Result = $A;;
		5)
		echo Enter num1
		read a
		echo Enter num2
		read b
		(( A=$a%$b ))
		echo Modulus of $a and $b = $A;;
	esac
done

<<OUTPUT
1: ADDITION
2: SUBTRACTION
3: MULTIPLICATION
4: DIVISION
5: MODULUS
ENTER CHOICE:
1
Enter num1
10
Enter num2
10
Sum of the 10 and 10 = 20
1: ADDITION
2: SUBTRACTION
3: MULTIPLICATION
4: DIVISION
5: MODULUS
ENTER CHOICE:
2
Enter num1
10
Enter num2
3
Difference between 10 and 3 = 7
1: ADDITION
2: SUBTRACTION
3: MULTIPLICATION
4: DIVISION
5: MODULUS
ENTER CHOICE:
3
Enter num1
10
Enter num2
20
Product of 10 and 20 = 200
1: ADDITION
2: SUBTRACTION
3: MULTIPLICATION
4: DIVISION
5: MODULUS
ENTER CHOICE:
4
Enter num1
50
Enter num2
2
Result = 25
1: ADDITION
2: SUBTRACTION
3: MULTIPLICATION
4: DIVISION
5: MODULUS
ENTER CHOICE:
5
Enter num1
100
Enter num2
28
Modulus of 100 and 28 = 16
1: ADDITION
2: SUBTRACTION
3: MULTIPLICATION
4: DIVISION
5: MODULUS
ENTER CHOICE:
0
OUTPUT

