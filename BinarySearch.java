import java.util.Random;
import java.util.Scanner;

class BinarySearch { 
	public static int binarysearch(int arr[], int l, int r, int x) 
	{ 
		if (r >= l) { 
			int mid = l + (r - l) / 2; 
			if (arr[mid] == x) 
				return mid; 
			if (arr[mid] > x) 
				return binarysearch(arr, l, mid - 1, x); 
			else
				return binarysearch(arr, mid + 1, r, x); 
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
    int result = binarysearch(arr, 0, length, x); 
    if(result == -1) 
        System.out.print("Element is not present in array"); 
    else
        System.out.print("Element is present at index " + result); 
} 
} 