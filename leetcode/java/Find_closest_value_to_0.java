/*
* a list of numbers (+or -) , find the closest number from 0, if tow the same, return the +
*/
public class Find_closest_value_to_0{
	public static int find(int[] nums){
		int a = Integer.MIN_VALUE;
		int b = Integer.MAX_VALUE;
		int minDistance = Integer.MAX_VALUE;
		for(int i : nums){
			if(i==0){
				return 0;
			}
			if(i<0){
				if(i>minDistance*(-1)){
					a = i;
					minDistance = -a;
				}
			}else{
				if(i<minDistance){
					b = i;
					minDistance = b;
				}
			}
			
		}
		return (a+b>0) ? a : b;
		
	}
	
	public static void main(String[] args){
		int[] nums1 = {1,-2,2,-4,3,4,5};
		System.out.println(find(nums1));
		int[] nums2 = {1,-1,2,-4,3,4,5};
		System.out.println(find(nums2));
	}
}
