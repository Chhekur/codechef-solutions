#include<iostream>
#include<algorithm>
using namespace std;
string photo1,photo2;

int isPixelSame(long i,long j,int new_pixel_photo1_row, int new_pixel_photo1_col, int new_pixel_photo2_row, int new_pixel_photo2_col, int h1, int w1, int h2, int w2){
	int new_i_photo1 = int(i / new_pixel_photo1_row);
	int new_j_photo1 = int(j / new_pixel_photo1_col);
	int new_i_photo2 = int(i / new_pixel_photo2_row);
	int new_j_photo2 = int(j / new_pixel_photo2_col);
	// cout<<i<<" " << j <<" " << (new_i_photo1 * (w1)) + (new_j_photo1)<<" " << (new_i_photo2 * (w2)) + (new_j_photo2)<<endl;
	return photo1[(new_i_photo1 * (w1)) + (new_j_photo1)] == photo2[(new_i_photo2 * (w2)) + (new_j_photo2)];
}


int main(void){
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;cin>>t;
	while(t--){
		int h1,w1;cin>>h1>>w1;
		photo1;cin>>photo1;
		int h2,w2;cin>>h2>>w2;
		photo2;cin>>photo2;
		long new_photo_row = long((h1 * h2) / __gcd(h1,h2));
		long new_photo_col = long((w1 * w2) / __gcd(w1,w2));
		int new_size_of_pixel_photo1_row = int(new_photo_row / h1);
		int new_size_of_pixel_photo1_col = int(new_photo_col / w1);
		int new_size_of_pixel_photo2_row = int(new_photo_row / h2);
		int new_size_of_pixel_photo2_col = int(new_photo_col / w2);
		// cout<<h1<<" "<<h2<<endl;
		// cout<<w1<<" "<<w2<<endl;
		// cout<<__gcd(h1,h2)<<endl;
		// cout<<new_photo_row<<" "<<new_photo_col<<endl;
		long count = 0;
		int i = 0, j = 0;
		int a = new_size_of_pixel_photo1_col,b = new_size_of_pixel_photo2_col, c = new_size_of_pixel_photo1_row, d = new_size_of_pixel_photo2_row;
		while(i < new_photo_row){
			while(j < new_photo_col){
				int temp = isPixelSame(i,j,new_size_of_pixel_photo1_row,new_size_of_pixel_photo1_col,new_size_of_pixel_photo2_row,new_size_of_pixel_photo2_col,h1,w1,h2,w2);
				if(temp == 1){
					long m1 = min(a,b);
					long m2 = min(c,d);
					count += m1 + m2;
					j += m1;
					i += m2;
					a -= m1;
					b -= m1;
					c -= m2;
					d -= m2;
					if(a == 0) a = new_size_of_pixel_photo1_col;
					if(b == 0) b = new_size_of_pixel_photo2_col;
					if(c == 0) c = new_size_of_pixel_photo1_row;
					if(d == 0) d = new_size_of_pixel_photo2_row;
				}else{
					j ++;
				}
			}
			i ++;
		}
		// for(long i = 0; i < new_photo_row; i++){
		// 	for(long j = 0; j < new_photo_col; j++){
		// 		count += isPixelSame(i,j,new_size_of_pixel_photo1_row,new_size_of_pixel_photo1_col,new_size_of_pixel_photo2_row,new_size_of_pixel_photo2_col,h1,w1,h2,w2);
		// 		// cout<<i<<" " << j<<" ";
		// 	}
		// 	// cout<<endl;
		// }
		cout<<count<<endl;
	}
}
