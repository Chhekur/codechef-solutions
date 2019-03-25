import java.io.*;
public class BBRICKS{
	public static void main(String args[]) throws IOException{
		long chek[][] = new long[100005][1005];
		chek[1][0] = 1;chek[1][1] = 2;
		chek[2][0] = 1;chek[2][1] = 4;chek[2][2] = 2;
		for(int i = 3; i < 100005; i++){
			for(int j = 0; j < i + 1 && j < 1001; j++){
				if(j == 0) chek[i][j] = 1;
				else chek[i][j] = (chek[i - 1][j] + chek[i - 2][j - 1] + chek[i - 1][j - 1]) % 1000000007;
			}
		}
		BufferedReader input = new BufferedReader(new InputStreamReader(System.in));
		int t = Integer.parseInt(input.readLine());
		while(t -- > 0){
			String temp[] = input.readLine().split(" ");
			System.out.println(chek[Integer.parseInt(temp[0])][Integer.parseInt(temp[1])]);
		}
	}
}