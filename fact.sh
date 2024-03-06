echo Enter your number
read n
f=1
for (( i=1;i<=n;i++ ))
{
	(( f=$f*$i))
}
echo Factorial of n is : $f

<<OUTPUT
Enter your number
5
Factorial of n is : 120
OUTPUT
