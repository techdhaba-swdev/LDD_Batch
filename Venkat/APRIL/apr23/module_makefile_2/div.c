float div2(float x ,float y)
{
	if (y == 0){
		return 0;
	}
	return x/y;
}
float div3(float x ,float y,float z){
	if (y==0 || z==0){
		return 0;
	}
	return x/y/z;
}
float div4(float x ,float y ,float z,float w){
	if(y==0 || z ==0 || w ==0){
		return 0;
	}
	return x/y/z/w;


}
