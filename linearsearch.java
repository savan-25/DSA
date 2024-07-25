import java.util.*;

import javax.sound.midi.Soundbank; 
class main{
public static int linear_search(int arr[],int target){
     if (arr.length==0){       return -1;
     }     for (int i = 0; i < arr.length; i++) {  
       int element=arr[i];
       if(element==arr[i]){
         return i;
      
       }
}
    return -1;
    
   }
   public static void main(String[] args){
      int nums[]={1,2,3,4,5};
      int target;
     Scanner sc=new Scanner(System.in);
      System.out.println("enter the target value");
      target=sc.nextInt();
      int ans=linear_search(nums, target);
      System.out.println(ans);


   }
 }
