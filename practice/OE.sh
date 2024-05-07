#display odd and even  numbers
echo "Enter number:"
read a
if [ $((a % 2)) -eq 0 ]
then
	echo "Even number"
else
	echo "Odd number"
fi
