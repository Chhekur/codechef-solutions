using System;
using System.Linq;
					
public class BadSuffle {
	public static void Main() {
		int n = Convert.ToInt32(Console.ReadLine());
		int mid = Convert.ToInt32(n / 2);
		for(int i = 2; i <= mid; i++) Console.Write(i + ' ');
		Console.Write(1 + ' ');
		for(int i = mid + 2; i < n + 1; i++) Console.Write(i + ' ');
		Console.WriteLine(mid + 1);
		Console.Write(n + ' ');
		for(int i = 0; i < n + 1; i++) Console.Write(i + ' ');
		// while(t-- > 0){
		// 	int[] a = Console.ReadLine().Split(' ').Select(int.Parse).ToArray();
		// 	for (int i = 0; i < a[2]; i++){
		// 		int[] b = Console.ReadLine().Split().Select(int.Parse).ToArray();
		// 		if(a[1] == b[0]) a[1] = b[1];
		// 		else if(a[1] == b[1]) a[1] = b[0];
		// 	}
		// 	Console.WriteLine(a[1]);
		// }
		
	}
}