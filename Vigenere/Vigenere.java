import java.util.Scanner;
public class Vigenere
{
	public static final String LETTERS = " ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	public static void main(String[] args) 
	{
		Scanner s = new Scanner(System.in);
		String mode, msg;
		String key;
		while(true)
		{
			System.out.println("Would you like to encrypt, decrypt, or quit? Enter 'e', 'd', or 'q': ");
			mode = s.next();
			if (mode.equalsIgnoreCase("e"))
			{
				s.nextLine();
				System.out.println("Enter the message to encrypt: ");
				msg = s.nextLine();
				System.out.println("Enter the key: ");
				key = s.nextLine();
				System.out.println("\n\nCipher Text: "+encrypt(msg, key)+"\n\n");
			}
			else if (mode.equalsIgnoreCase("d"))
			{
				s.nextLine();
				System.out.println("Enter the message to decrypt: ");
				msg = s.nextLine();
				System.out.println("Enter the key: ");
				key = s.nextLine();
				System.out.println("\n\nPlain Text: "+decrypt(msg, key)+"\n\n");
			}
			else if (mode.equalsIgnoreCase("q")) {
				System.out.println("Goodbye.");
				System.exit(0);
			}
			else
				continue;
		}
	}
	public static String encrypt(String message, String key)
	{
		String cipher = "";
		String msg = message.toUpperCase();
		String phrase = key.toUpperCase();
		int index;
		int keyIndex = 0;
		for (int i = 0; i < msg.length(); i++)
		{
			index = (LETTERS.indexOf(msg.charAt(i)) + LETTERS.indexOf(phrase.charAt(keyIndex))) % LETTERS.length();
			cipher += Character.toString(LETTERS.charAt(index));
			keyIndex++;
			if (keyIndex == key.length())
				keyIndex = 0;
		}
		return cipher;
	}
	public static String decrypt(String message, String key)
	{
		String plainText = "";
		String msg = message.toUpperCase();
		String phrase = key.toUpperCase();
		int index;
		int keyIndex = 0;
		for (int i = 0; i < msg.length(); i++)
		{
			index = (LETTERS.indexOf(msg.charAt(i)) - LETTERS.indexOf(phrase.charAt(keyIndex))) % LETTERS.length();
			plainText += Character.toString(LETTERS.charAt(index));
			keyIndex++;
			if (keyIndex == key.length())
				keyIndex = 0;
		}
		return plainText;
	}
}
