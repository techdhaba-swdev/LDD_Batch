//function to take two numbers to divide
float div2(int num1, int num2){
	if(num2 != 0){
	return (float)num1/num2;
	}
	else{
		return 0;
	}
}
//function to take three numbers to divide
float div3( int num1, int num2, int num3){
	if(num2 != 0 || num3 !=0){
        return (float)num1 / (num2 * num3); //if condition satisfy then only it will print result of divide
	}
	else{
		return 0; //return 0 if condition not satisfy
	}
}
//function to take 4 numbers to divide
float div4(int num1, int num2, int num3,int num4){

         if(num2 != 0 || num3 != 0 || num4 != 0){
        return (float)num1 / (num2 * num3 * num4); //if condition satisfy then only it will print result of divide
        }
        else{
                return 0; //return 0 if condition not satisfy
        }

}
