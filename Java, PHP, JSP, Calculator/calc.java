// Jeremiah S Kleiber Calculator in Java 10/12/20 assignment 2 ISP

import java.util.Scanner;  // Import the Scanner class
import java.util.InputMismatchException;
import java.util.* ;

public class calc {
 	public static void main(String[] args) 
	{
		menu();// calls menu to start
	
  	}
	//menu displays all options, call memeber functions, and validates
	static void menu()
	{
		Scanner inObj = new Scanner(System.in);  // Create a Scanner object
		System.out.println("Calculator in java");
		System.out.println("Enter + to add");
		System.out.println("Enter - to subtract");
		System.out.println("Enter * to multiply");
		System.out.println("Enter / to divide");
		System.out.println("Enter % to find remainder");
		System.out.println("Enter q to quit");
		String menuOption = inObj.nextLine(); 
		
		switch(menuOption)// checks input
		{
			case "+": // adding
			{
				System.out.println("Enter 1st number");
				float val1 = 0;
				float val2 = 0;

				if(inObj.hasNextInt() || inObj.hasNextFloat()) // validation
				{ 
					val1 = inObj.nextFloat();
				}
				else
				{
					System.out.println("Incorrect entry, returning to menu");
					menu();
					return;
			
				}

				System.out.println("Enter 2nd number");

				if(inObj.hasNextInt() || inObj.hasNextFloat()) // validation
				{ 
					val2 = inObj.nextFloat();
				}
				else
				{
					System.out.println("Incorrect entry, returning to menu");
					menu();
					return;
				}

				add(val1,val2);
				menu();
				
				break;
			}
			case "-": //subtract
			{
				System.out.println("Enter 1st number");
				float val1 = 0;
				float val2 = 0;

				if(inObj.hasNextInt() || inObj.hasNextFloat())// validation
				{ 
					val1 = inObj.nextFloat();
				}
				else
				{
					System.out.println("Incorrect entry, returning to menu");
					menu();
					return;
				}

				System.out.println("Enter 2nd number");

				if(inObj.hasNextInt() || inObj.hasNextFloat())// validation
				{ 
					val2 = inObj.nextFloat();
				}
				else
				{
					System.out.println("Incorrect entry, returning to menu");
					menu();
					return;
				}

				sub(val1,val2);
				menu();

				break;
			}
			case "*": // multiply
			{
				System.out.println("Enter 1st number");
				float val1 = 0;
				float val2 = 0;

				if(inObj.hasNextInt() || inObj.hasNextFloat())// validation
				{ 
					val1 = inObj.nextFloat();
				}
				else
				{
					System.out.println("Incorrect entry, returning to menu");
					menu();
					return;
			
				}

				System.out.println("Enter 2nd number");
				if(inObj.hasNextInt() || inObj.hasNextFloat())// validation
				{ 
					val2 = inObj.nextFloat();
				}
				else
				{
					System.out.println("Incorrect entry, returning to menu");
					menu();
					return;
				}

				mult(val1,val2);
				menu();

				break;
			}
			case "/": // divide
			{
				System.out.println("Enter 1st number");
				float val1 = 0;
				float val2 = 0;

				if(inObj.hasNextInt() || inObj.hasNextFloat())// validation
				{ 
					val1 = inObj.nextFloat();
				}
				else
				{
					System.out.println("Incorrect entry, returning to menu");
					menu();
					return;
			
				}

				System.out.println("Enter 2nd number");

				if(inObj.hasNextInt() || inObj.hasNextFloat())// validation
				{ 
					val2 = inObj.nextFloat();
				}
				else
				{
					System.out.println("Incorrect entry, returning to menu");
					menu();
					return;
				}

				divide(val1,val2);
				menu();

				break;
			}
			case "%": // remainder
			{
				System.out.println("Enter 1st number");
				int val1 = 0;
				int val2 = 0;

				if(inObj.hasNextInt() )// validation
				{ 
					val1 = inObj.nextInt();
				}
				else
				{
					System.out.println("Incorrect entry, returning to menu");
					menu();
					return;
				}

				System.out.println("Enter 2nd number");

				if(inObj.hasNextInt() )// validation
				{ 
					val2 = inObj.nextInt();
				}
				else
				{
					System.out.println("Incorrect entry, returning to menu");
					menu();
					return;
				}

				remainder(val1,val2);
				menu();

				break;
			}
			case "q": // exits
			{
				System.out.println("Ending program");
				break;
			}
			default: // validation for menu
			{
				System.out.println("Incorrect value entered, only enter +,-,*,/,%,q");
				menu();
			}
		}
	}
	// adds 2 values and returns them
	static void add(float val1, float val2) 
	{
		float val3 = val1 + val2;
		System.out.println(val3);
	}
	//subtract 2 values and returns them
	static void sub(float val1, float val2) 
	{
		float val3 = val1 - val2;
		System.out.println(val3);
	}
	//multiply 2 values and returns them
	static void mult(float val1, float val2) 
	{
		float val3 = val1 * val2;
		System.out.println(val3);
	}
	//divides 2 values and returns them
	static void divide(float val1, float val2) 
	{
		if(val2 == 0)// extra step in validation
		{
			System.out.println("Can't divide by 0, setting it to one");
			val2 = 1;	
		}
		float val3 = val1 / val2;
		System.out.println(val3);
	}
	//finds the remainder of 2 values and returns them
	static void remainder(int val1, int val2) 
	{
		if(val2 == 0)// extra step in validation
		{
			System.out.println("Can't divide by 0, setting it to one");
			val2 = 1;	
		}
		int val3 = val1 % val2;
		System.out.println(val3);
	}

}