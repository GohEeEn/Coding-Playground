package Ciphers;
import java.util.InputMismatchException;
import java.util.Scanner;

/**
 * @author Ee En Goh, referring to the content on freecodecamp
 *	Caesar cipher implemented in Java
 *	1. Identify the character within the message
 *	2. Find that character's location within the alphabet
 *	3. Identify the characters location and the key in the alphabet, if location + key > 26 then loop back around and begin counting at 1 
 *	4. Build a new sentence using the new characters in place of the original characters
 *	5. Repeat until sentence length is reached by using for loop
 *	6. Return result
 */
public class CaesarCipher{
	
	/**
	 * Encryption method : Caesar cipher method, a kind of transition cipher
	 * @param message	Plain text / Message in characters
	 * @param key		Transition key in integer
	 * @return			Cipher
	 */
	public static String encryption(String message, int key) {
		
		// Local Variables Declaration
		
		String upper_alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"; // Upper-case alphabet dictionary string
		String lower_alphabet = upper_alphabet.toLowerCase(); // Lower-case alphabet dictionary string
		
		StringBuilder encrypted = new StringBuilder(message); // Using an object type to modify the character of messages easier
		
		// Transformed alphabet sequence : transition key applied
		String keyedalphabet = upper_alphabet.substring(key) + upper_alphabet.substring(0, key);
		
		// Repeat the transformation of characters until the end of message reached
		for(int i = 0 ; i < encrypted.length() ; i++) {
			
			// Read each character in the plain text / message
			char current_char = encrypted.charAt(i);
			int index = upper_alphabet.indexOf(current_char);
			
			// Statement index != -1 is used to confirm the spot is a valid letter (case-sensitive)
			
			// Encrypt uppercase letter
			if(index != -1) { 
				char newChar = keyedalphabet.charAt(index);  
				encrypted.setCharAt(i, newChar); // Encryption, replace the original char with new char
			}
			
			// Indicate the index of current char in the lowercase sequence, else -1
			index = lower_alphabet.indexOf(current_char);
			
			// Encrypt lowercase letter
			if(index != -1) {
				String keyedalphabet2 = keyedalphabet.toLowerCase();
				char newChar = keyedalphabet2.charAt(index);
				encrypted.setCharAt(i, newChar);
			}
		}
		
		// Return result 
		return encrypted.toString();
	}
	
	/**
	 * Decryption of cipher, by using the cyclic property of Caesar cipher
	 * @param cipher	The encrypted message / cipher
	 * @param key		The transition key
	 * @return			Original plain text
	 */
	public static String decryption(String cipher, int key) {
		
		String decipher = encryption(cipher, 26 - key);
		
		return decipher;
	}
	
	public static void insertion() {
			// Insert plain text
			Scanner scanner = new Scanner(System.in);
				
			System.out.println("\t<< Caesar Cipher Encryption >>");
			System.out.print("\tInsert your plain text here : ");
			String plain = scanner.nextLine();	// Record given plain text
			int key = 27 ;
			
			try {
				do {
					System.out.print("\tInsert your key here : ");
				
					key = scanner.nextInt();
				
					if(key >= 0 && key < 26) {
						System.out.println();
						System.out.println("\tCipher: " + encryption(plain,key));					// Encryption result
						System.out.println("\tPlain : " + decryption(encryption(plain,key),key));	// Decryption result
					}
					else
						System.out.println("\tError : Your key input is invalid, try again");
				}while(!(key >= 0 && key < 26));
			
			}catch(InputMismatchException e) {
				System.out.println("\n\tError : Your key input is not an integer");
			}
			
			scanner.close();
	}
	
	public static void main(String[] args) {
		
		insertion();
	}
}