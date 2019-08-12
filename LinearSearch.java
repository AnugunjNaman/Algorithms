import java.util.Random;
import java.util.Scanner;

class LinearSearch 
{  
public static int search(int arr[], int x) 
{ 
    int n = arr.length; 
    for(int i = 0; i < n; i++) 
    { 
        if(arr[i] == x) 
            return i; 
    } 
    return -1; 
} 
  
public static void main(String args[]) 
{ 
    Random rd = new Random();
    Scanner sc = new Scanner(System.in);
    int length = sc.nextInt();
    int[] arr = new int[length];
    for(int i = 0; i < length; i++)
    {
        arr[i] = rd.nextInt(51);
        System.out.println(arr[i]);
    }
    int x;
    x = sc.nextInt(); 
    sc.close();
    int result = search(arr, x); 
    if(result == -1) 
        System.out.print("Element is not present in array"); 
    else
        System.out.print("Element is present at index " + result); 
} 
} 