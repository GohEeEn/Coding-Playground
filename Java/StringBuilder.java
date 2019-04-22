import java.util.Scanner;

public class StringBuilder {

	// ----- Backend Variables -----
	private static String previous ;
	private static int count = 0;
	
	private static void menu() {
		
		System.out.println();
		System.out.println("\t\t << Menu >>");
		System.out.println("\t1. Append ");
		System.out.println("\t2. Reverse ");
		System.out.println("\t3. Delete ");
		System.out.println("\t4. Insert ");
		System.out.println("\t5. Replace ");
		if(count > 0)
			System.out.println("\t6. Compare changes ");
		System.out.println("\tElse. Exit");
		System.out.println();
	}
	
	public static void main(String args[]){
		
		Scanner userInput = new Scanner(System.in);		
		
		System.out.println("Insert your input string :");
		String input = userInput.nextLine() + " ";
		StringBuffer string = new StringBuffer(input);
		
		menu();
		
		System.out.println("=======================================================");
		System.out.print("Make your choice here (Insert the reference integer) : ");
		System.out.println("=======================================================");
		
		int choice = userInput.nextInt();
		
		// labeling : available on both loop and switch cases, can be used to break from nested cases
		loop : while(choice >= 1 && choice <= 6) {
			
			// ----- Backend Work -----
			if(choice != 6)
				previous = string.toString(); // Convert StringBuffer to String
			++count;
			
			switch(choice) {
		
				case 1:{
					System.out.println("Insert your appending string : ");
					userInput.nextLine();
					String append = userInput.nextLine();	// Scanner input been eaten : nextLine() method will swallow the EOL sign
					string.append(append);
					break;
				}
				
				case 2 :{
					string.reverse();
					break;
				}
				
				case 3 :{
					System.out.println("Insert the starting and ending index of the characters you want to delete :");
					
					int start = userInput.nextInt();
					int end = userInput.nextInt();
					
					if(start > 0 || end < string.length())
						string.delete(start,end);
					else
						System.out.println("[ Inaccepted ] Max length of the current string : " + string.length());
					break;
				}
				
				case 4 :{
					System.out.println("Insert your external string and the index of offset :");
					System.out.print("External String : ");
					userInput.nextLine();
					String external = userInput.nextLine();
					System.out.print("Offset Index : ");
					int offset = userInput.nextInt();
					
					if(offset < string.length())
						string.insert(offset, external);
					else
						System.out.println("[ Inaccepted ] Max length of the current string : " + string.length());
					break;
				}
				
				case 5 :{
					System.out.println("Insert the new string you want to replace with : ");
					userInput.nextLine();	// Consume newline command given
					String replace = userInput.nextLine();
					System.out.println("Insert the starting and ending index of the characters you want to replace :");
					
					int start = userInput.nextInt();
					int end = userInput.nextInt();
					
					if(start > 0 || end < string.length())
						string.replace(userInput.nextInt(), userInput.nextInt(),replace);
					else
						System.out.println("[ Inaccepted ] Max length of the current string : " + string.length());
					
					break;
				}
				
				case 6 :{
					if(count > 1) {
						System.out.println("For the previous change : ");
						System.out.println("Before : " + previous);
						break;
					}else 
						break loop;
				}
				
				default :	// Default Case : Exit Program
					break;
			}
			 
			System.out.println("After  : " + string);
			
			// ----- New Round -----
			menu();
			System.out.print("Make your choice here again (Insert the referencing integer) : ");
			choice = userInput.nextInt();
		}
		
		userInput.close();
		System.out.println("\n==> Exit program successfully");
	}
}
