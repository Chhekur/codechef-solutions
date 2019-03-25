const rl = require('readline').createInterface({
  input: process.stdin,
  output: process.stdout
});

rl.question('', function(t){
	while(t-- > 0){
		rl.question('', function(temp){
			let a = temp.split(' ');
			for(let i = 0; i < parseInt(a[2]); i++){
				// console.log(parseInt(a[2]))
				rl.question('',function(temp){
					let b = temp.split(' ');
					console.log(b)
					if(a[1] == b[0]) a[1] = b[1]
					else if(a[1] == b[1]) a[1] = b[0];
					console.log(a[1])
					rl.close();
				});
				// console.log('hello')
			}
			rl.close();
			console.log(a[1])
		});
	}
	rl.close();
})