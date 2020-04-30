import java.util.Scanner;
public class Caesar 
{
	public static final String LETTERS = " ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	public static void main(String[] args) 
	{
		Scanner s = new Scanner(System.in);
		String mode, msg;
		int shift;
		while(true)
		{
			System.out.println("Would you like to encrypt, decrypt, or quit? Enter 'e', 'd', or 'q': ");
			mode = s.next();
			if (mode.equalsIgnoreCase("e"))
			{
				s.nextLine();
				System.out.println("Enter the message to encrypt: ");
				msg = s.nextLine();
				System.out.println("Enter the number of shifts: ");
				shift = s.nextInt();
				System.out.println("\n\nCipher Text: "+encrypt(msg, shift)+"\n\n");
			}
			else if (mode.equalsIgnoreCase("d"))
			{
				s.nextLine();
				System.out.println("Enter the message to decrypt: ");
				msg = s.nextLine();
				System.out.println("Enter the number of shifts: ");
				shift = s.nextInt();
				System.out.println("\n\nPlain Text: "+decrypt(msg, shift)+"\n\n");
			}
			else if (mode.equalsIgnoreCase("q"))
				System.exit(0);
			else
				continue;
		}
	}
	public static String encrypt(String message, int key)
	{
		String cipher = "";
		String msg = message.toUpperCase();
		int index;
		for (int i = 0; i < msg.length(); i++)
		{
			index = (LETTERS.indexOf(msg.charAt(i)) + key) % LETTERS.length();
			cipher += Character.toString(LETTERS.charAt(index));
		}
		return cipher;
	}
	public static String decrypt(String message, int key)
	{
		String plainText = "";
		String msg = message.toUpperCase();
		int index;
		for (int i = 0; i < msg.length(); i++)
		{
			index = (LETTERS.indexOf(msg.charAt(i)) - key) % LETTERS.length();
			plainText += Character.toString(LETTERS.charAt(index));
		}
		return plainText;
	}
}
