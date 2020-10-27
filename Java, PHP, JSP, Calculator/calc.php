<!--Calculator using php. Jeremiah S Kleiber 10/15/20 jsk84@zips.uakron.edu assignment 2-->
<!DOCTYPE html>
<html>

<head><title>Calculator</title></head>
<body><h1>A basic calculator</h1>
<form method=POST>Please enter numbers here: 
<input name=number1>
<input name=number2>
<br/>
	<input type="submit" name="+" value="+" />
	<input type="submit" name="-" value="-" />
	<input type="submit" name="*" value="*" />
	<input type="submit" name="/" value="/" />
	<input type="submit" name="%" value="%" />
</form>


<?php

#setting the user entries into a variable
$val1 = $_POST["number1"];
$val2 = $_POST["number2"]; 

if($_POST["number1"] != null && $_POST["number2"] != null) # seeing if the user entered 2 values
{
	# testing or validating the values to make sure they are an int other wise program wont run
	if ( (filter_var($val1, FILTER_VALIDATE_INT) === 0 || filter_var($val1, FILTER_VALIDATE_INT))
		&& (filter_var($val2, FILTER_VALIDATE_INT) === 0 || filter_var($val2, FILTER_VALIDATE_INT)) )  
	{
		echo "<br>";
		
		if($_POST["+"] != null) # adding
		{
			echo $val1 + $val2;
		}
		else if($_POST["-"] != null) # subtracting
		{
			echo $val1 - $val2;
		}
		else if($_POST["*"] != null) # mult
		{
			echo $val1 * $val2;
		}
		else if($_POST["/"] != null) # division
		{
			if($val2 == 0)
			{
				echo "Can't Divide by zero, setting val2 equal to 1, : ";
				$val2 = 1;
			}
			echo $val1 / $val2;
		}
		else if($_POST["%"] != null) # remainder
		{
			if($val2 == 0)
			{
				echo "Can't Divide by zero, setting val2 equal to 1. : ";
				$val2 = 1;
			}
			if($val1 < $val2)
			{
				echo "Can't find the remainder of a fraction, setting first number to the second. : ";
				$val1 = $val2;
			}
			echo $val1 % $val2;
		}
	}
	else # if one or more values wasnt an interger
	{
		echo "<br>";
		echo("Variable is not an integer");
	}
}
else if($_POST["number1"] != null || $_POST["number2"] != null) # if the user only entered 1 value
{
	echo "<br>";
	echo "Only one value was entered";
}
echo "<br>";


?>
<br/>
<p1> Made by Jeremiah S Kleiber </p1>
</body>
</html>