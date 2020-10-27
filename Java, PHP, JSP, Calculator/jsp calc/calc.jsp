<!--Calculator using jsp and java. Jeremiah S Kleiber 10/14/20 jsk84@zips.uakron.edu assignment 2-->

<html>
<head><title>Calculator</title></head>
<body><h1>A basic calculator</h1>
<form method=POST>Please enter number here: 
<input name=number1>
<input name=number2>
<br/>
	<input type="submit" name="+" value="+" />
	<input type="submit" name="-" value="-" />
	<input type="submit" name="*" value="*" />
	<input type="submit" name="/" value="/" />
	<input type="submit" name="%" value="%" />
</form>
<%
int value = 0;
int value2 =0;
boolean haveValue = false;
boolean haveValue2 = false;

//The big if allows the program to see if a button has been pressed
if( request.getParameter("+") != null || request.getParameter("-") != null || request.getParameter("*") != null ||
	request.getParameter("/") != null || request.getParameter("%") != null)
{
	try //testing to see if the parseInt fails
	{
		value = Integer.parseInt(request.getParameter("number1"));
		haveValue = true;
	} 
	catch (Exception e) 
	{
		out.println("Error in first number.");
	}
	
	try 
	{
		value2 = Integer.parseInt(request.getParameter("number2"));
		haveValue2 = true;
	} 
	catch (Exception e) 
	{
		out.println("Error in second number.");
	}
}
if (haveValue && haveValue2) // if there is a value in both entry points
{
		if (request.getParameter("+") != null) // if they clicked + 
		{
			int value3 = value + value2;
            		out.println(value3);
		}
		else if(request.getParameter("-") != null)// if they clicked -
		{
			int value3 = value - value2;
            		out.println(value3);
		}
		else if(request.getParameter("*") != null)// if they clicked *
		{
			int value3 = value * value2;
            		out.println(value3);
		}
		else if(request.getParameter("/") != null)// if they clicked /
		{
			if(value2 == 0) // cant divide by zero
			{
				out.println("Can't divide by zero setting second number to 1");
				value2 =1;
				%> <br/><%
			}
			if(value < value2)// cant display fractions 
			{
				out.println("Error, can't have fractions in this calculator. Setting second number to the first.");
				%> <br/><%
				value2 = value;
			}
				
			int value3 = value / value2;
            		out.println(value3);
		}
		else if(request.getParameter("%") != null)// if they clicked %
		{
			if(value2 == 0) // cant divide by zero
			{
				out.println("Can't divide by zero setting second number to 1");
				value2 =1;
				%> <br/><%
			}
			if(value < value2)// cant display fractions 
			{
				out.println("Error, can't have fractions in this calculator. Setting second number to the first.");
				%> <br/><%
				value2 = value;
			}
			int value3 = value % value2;
            		out.println(value3);
		}

} 
else 
{
%><br/><p1> Answer or Error Msg will go here!</p1> <%

} %>
	<br/><br/>
	<p1> Made By Jeremiah S Kleiber<br/> jsk84@zips.uakron.edu <br/> 10/14/20 </p1>
</body>
</html>