public class Find_the_x_position_of_binary_of_num{
	public static int binaryAt(int num, int position){
		return (num&(1<<position))==0?0:1;
	}
	
	public static void main(String[] args){
		System.out.println(binaryAt(1,0));
		System.out.println(binaryAt(2,0));
		System.out.println(binaryAt(2,1));
		System.out.print(binaryAt(7,0));
		System.out.print(binaryAt(7,1));
		System.out.print(binaryAt(7,2));
		System.out.print(binaryAt(7,3));
		System.out.print(binaryAt(7,4));
		System.out.print(binaryAt(7,5));
		System.out.println(binaryAt(7,6));
		System.out.println(binaryAt(7,9));
	}
}
