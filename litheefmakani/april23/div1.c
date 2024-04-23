int div(int x,int y,int z){
	int result;
	if(y==0){
		return 0;
	}
	else{
       		result=x/y;
		if(z == 0){
			return 0;
		}
		else{
			return result/z;
		}
	}
}       
