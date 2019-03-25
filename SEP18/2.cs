using System;
using System.Linq;
					
public class ChefAdv {
	public static void Main() {
		// int n = Convert.ToInt32(Console.ReadLine());
		// int mid = Convert.ToInt32(n / 2);
		// for(int i = 2; i <= mid; i++) Console.Write(i + ' ');
		// Console.Write(1 + ' ');
		// for(int i = mid + 2; i < n + 1; i++) Console.Write(i + ' ');
		// Console.WriteLine(mid + 1);
		// Console.Write(n + ' ');
		// for(int i = 0; i < n + 1; i++) Console.Write(i + ' ');
		while(t-- > 0){
			int[] a = Console.ReadLine().Split(' ').Select(int.Parse).ToArray();
			int c = a[0] % a[2];
			int d = a[1] % a[3];
			c --;
			d --;
			if(c > 0 && d > 0){
				c--;
				d--;
			}
			if(c > 0 && d > 0){
				Console.WriteLine("Pofik");
			}else{
				Console.WriteLine("Chefirnemo");
			}
		}
		
	}
}