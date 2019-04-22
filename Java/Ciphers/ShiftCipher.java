package Ciphers;
/**
 * Shift Cipher
 * @author Ee En Goh
 */
import java.util.Scanner;
import java.util.ArrayList;
import java.util.Random;

public class ShiftCipher{
	
	private static String encryption(String original) {
		
		Scanner scanner = new Scanner(System.in);
 
		// int key = 5 ;
		int key = scanner.nextInt() ;
		String encrypted = "";
		
		displayEncryptionTable(key);
		
		scanner.close();
		
		return encrypted;
	}
	
	private static String decryption(String encrypted) {
		
		String decrypted = "";
		
		return decrypted;
	}
	
	private static void displayEncryptionTable(int key) {
		
	}
	
	/**
	 * Method to store and return the original message given
	 * @return
	 */
	public static String original() {
		
		Scanner scanner = new Scanner(System.in);
		
		System.out.println("Insert your original message here :");
		String original = scanner.nextLine();
		
		scanner.close();
		
		return original;
	}
	
	@SuppressWarnings("unused")
	public static void platform() {
		
		String original = original();
		String encrypted = ""; 
		String decrypted = "";
		
		int choice = 0;
		
		switch(choice) {
			
			case 0: // New message
			{
				original = original();
				break;
			}
				
			case 1: // Encryption	
			{	
				if(original != null) {
					encrypted = encryption(original);
					System.out.println("Your encrypted message : " + encrypted);
				}
				else
					System.out.println("Error : No message found");
				break;
			}
			
			case 2: // Decryption
			{
				if(encrypted != null) {
					decrypted = decryption(encrypted);
					System.out.println("Your encrypted message : " + decrypted);
					break;
				} 
				else
					System.out.println("Error : No encrypted message found");
				break;
			}
			
			default:
				break;
		}
	}
	
	// Main function
	public static void main(String[] agrs){
		platform();
	}
}