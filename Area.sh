n=8
while (( n!=0 ))
do
	echo 1: Area of circle
	echo 2: Circuference of Circle
	echo 3: Area of rectangle
	echo 4:Area of Square
	echo Enter your choice
	read n
	case $n in
		1)
		echo Enter radius
		read r
		area=`echo 3.14*$r*$r |bc`
		echo Area of circle:$area;;
		2)
		echo Enter radius
		read r
		C=`echo 2*3.14*$r |bc`
		echo Circumference of circle:$C;;
		3)
		echo Enter length and breadth
		read l
		read b
		(( A= $l*$b ))
		echo Area of rectangle : $A;;
		4)
		echo Enter Side
		read s
		(( A=$s*$s ))
		echo Area of square : $A;;
	esac
done

<<OUTPUT
1: Area of circle
2: Circuference of Circle
3: Area of rectangle
4:Area of Square
Enter your choice
1
Enter radius
10
Area of circle:314.00
1: Area of circle
2: Circuference of Circle
3: Area of rectangle
4:Area of Square
Enter your choice
2
Enter radius
10
Circumference of circle:62.80
1: Area of circle
2: Circuference of Circle
3: Area of rectangle
4:Area of Square
Enter your choice
3
Enter length and breadth
10
20
Area of rectangle : 200
1: Area of circle
2: Circuference of Circle
3: Area of rectangle
4:Area of Square
Enter your choice
4
Enter Side
5
Area of square : 25
1: Area of circle
2: Circuference of Circle
3: Area of rectangle
4:Area of Square
Enter your choice
0
OUTPUT
