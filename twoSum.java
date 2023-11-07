/*Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.
You may assume that each input would have exactly one solution, and you may not use the same element twice.
You can return the answer in any order.*/
import java.util.Scanner;
import java.util.Arrays;
class Solution {
    public int[] twoSum(int[] nums, int target) {
        int[] result = new int[2];
        for(int i=0;i<nums.length;i++)
        {
            for(int j=0;j<i;j++)
            {
                if(target==nums[i]+nums[j])
                {
                    result[0]=j;
                    result[1]=i;
                }
            }			
        }
        return result;
    }
}
class Main
{
    public static void main(String args[])
    {
        int num,tar;
        Scanner sc=new Scanner(System.in);
        System.out.println("Enter the number of integers");
        //Number of integers to be checked
        num=sc.nextInt();
        System.out.println("Enter the target");
        tar=sc.nextInt();
        //Target number to be checked
        int[] array = new int[num];
        System.out.println("Enter the elements of the array: ");  
        for(int i=0; i<num; i++)  
        {  
        //reading array elements from the user   
        array[i]=sc.nextInt();  
        }  
        Solution myObj=new Solution();
        int[] a=myObj.twoSum(array,tar);
        //Getting input from the function
        System.out.println(Arrays.toString(a));
    }
}
