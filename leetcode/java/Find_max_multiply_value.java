/*
* a list of numbers (+ or -), find the biggest multiply result.
*/
public class Find_max_multiply_value{
	public static int find(int[] nums){
		int a = 0;
		int b = 0;
		
		int c = 0;
		int d = 0;
		
		for(int i : nums){
			if(i==0){
				continue;
			}
			if(i<0){
				if(c<d){
					d = d<=i?d:i;
				}else{
					c = c<=i?c:i;
				}				
			}else{
				if(a<b){
					a = a>=i?a:i;
				}else{
					b = b>=i?b:i;
				}	
			}
			
		}
		int p = a*b;
		int q = c*d;
		return p<q?q:p;
		
	}
	
	public static void main(String[] args){
		int[] nums6= {1,-1,2,-4,3,-4,5};
		System.out.println(find(nums6));
		int[] nums1 = {1,1};
		System.out.println(find(nums1));
		
		int[] nums2 = {1,2};
		System.out.println(find(nums2));
		
		int[] nums3 = {2,3,1};
		System.out.println(find(nums3));
		
		int[] nums4 = {2,-3,1};
		System.out.println(find(nums4));
		
		int[] nums5 = {2,-3,1,-1};
		System.out.println(find(nums5));
		
	}
}

