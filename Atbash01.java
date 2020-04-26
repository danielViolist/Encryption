//William Daniel Rochester

import java.util.Scanner;

public class Atbash01 {

	public static void main(String[] args) 
	{
		Scanner key = new Scanner(System.in);
		System.out.println("Do you want to encode, decode, or quit? Eneter \'E\' to encode, \'D\' to decode, or \'Q\' to quit."); 
		
		String first = key.next();
		key.nextLine();
	do {
		if (first.equalsIgnoreCase("E"))
		{
			System.out.println("Enter the message you want to encode:");
			String message = key.nextLine();
			System.out.println("This is the message encoded:");
			System.out.println();
			System.out.println(encode(message));
		} else if (first.equalsIgnoreCase("D"))
		{
			System.out.println("Enter the Atbash cipher that needed to be decoded:");
			String needsDC = key.nextLine();
			System.out.println("Here is the decoded message:\n");
			System.out.println(decode(needsDC));
		} else {
			System.out.println("Closing the program. Goodbye!");
			System.exit(0);
		}
		System.out.println();
		System.out.println("Do you want to encode, decode, or quit? Eneter \'E\' to encode, \'D\' to decode, or \'Q\' to quit.");
		first = key.next();
		key.nextLine();
	} while(first.equalsIgnoreCase("E") || first.equalsIgnoreCase("D"));
	System.out.println("Goodbye.");
	System.exit(0);
	key.close();
	}
	
	public static String encode(String xMessage) //this method encodes the message entered by using ASCII numbers to convert the letters to Atbash
	{
		String encodedMsg = "";
		for (int i = 0; i < xMessage.length(); i++)
		{
			if (xMessage.charAt(i) >= 65 && xMessage.charAt(i) < 97) //ASCII 65-96 are all uppercase letter numbers
			{
				int temp = xMessage.charAt(i) - 'A'; //determining the distance from capital A 
				encodedMsg = encodedMsg + (char)('Z' - temp); //converting to Atbash letter by subtracting the distance from a from ASCII Z
			} else if (xMessage.charAt(i) >= 97 && xMessage.charAt(i) < 123) {
				int temp = xMessage.charAt(i) - 'a'; //same as above except with lower case
				encodedMsg = encodedMsg + (char)('z' - temp);
			} else {
				encodedMsg = encodedMsg + xMessage.charAt(i); //if it's not a letter, don't change it, like spaces or numbers 
			}
		}
		
		return encodedMsg;
		
	}
	
	public static String decode(String xxMessage) 
	{
		String decodeMsg = "";
		for (int i = 0; i < xxMessage.length(); i++)
		{
			if (xxMessage.charAt(i) >= 65 && xxMessage.charAt(i) < 97)
			{
				int temp = 'Z' - xxMessage.charAt(i);  //same as encode except backwards to decode
				decodeMsg = decodeMsg + (char)('A' + temp);
			} else if (xxMessage.charAt(i) >= 97 && xxMessage.charAt(i) < 123) {
				int temp = 'z' - xxMessage.charAt(i);
				decodeMsg = decodeMsg + (char)('a' + temp);
			} else {
				decodeMsg = decodeMsg + xxMessage.charAt(i);
			}
		}
		
		return decodeMsg;
		
	}
	

}
