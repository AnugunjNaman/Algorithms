// C++ implementation of Karatsuba algorithm for bit string multiplication. 
#include<iostream> 
#include<stdio.h> 
#include<cmath>

using namespace std; 
// Makes strings of equal length
int makeEqualLength(string &str1, string &str2) 
{ 
	int len1 = str1.size(); 
	int len2 = str2.size(); 
	if (len1 < len2) 
	{ 
		for (int i = 0 ; i < len2 - len1 ; i++) 
			str1 = '0' + str1; 
		return len2; 
	} 
	else if (len1 > len2) 
	{ 
		for (int i = 0 ; i < len1 - len2 ; i++) 
			str2 = '0' + str2; 
	} 
	return len1; // If len1 >= len2 
} 

// The main function that adds two bit sequences and returns the addition 
string addBitStrings( string first, string second ) 
{ 
	string result; // To store the sum bits 

	// make the lengths same before adding 
	int length = makeEqualLength(first, second); 
	int carry = 0; // Initialize carry 

	// Add all bits one by one 
	for (int i = length-1 ; i >= 0 ; i--) 
	{ 
		int firstBit = first.at(i) - '0'; 
		int secondBit = second.at(i) - '0'; 

		// boolean expression for sum of 3 bits 
		int sum = (firstBit ^ secondBit ^ carry)+'0'; 

		result = (char)sum + result; 

		// boolean expression for 3-bit addition 
		carry = (firstBit&secondBit) | (secondBit&carry) | (firstBit&carry); 
	} 

	// if overflow, then add a leading 1 
	if (carry) result = '1' + result; 

	return result; 
} 

// A utility function to multiply single bits of strings a and b 
int multiplyiSingleBit(string a, string b) 
{ return (a[0] - '0')*(b[0] - '0'); } 

// The main function that multiplies two bit strings X and Y and returns result as long integer 
long int multiply(string X, string Y) 
{ 
	// Find the maximum of lengths of x and Y and make length of smaller string same as that of larger string 
	int n = makeEqualLength(X, Y); 

	// Base cases 
	if (n == 0) return 0; 
	if (n == 1) return multiplyiSingleBit(X, Y); 

	int fh = n/2; // First half of string, floor(n/2) 
	int sh = (n-fh); // Second half of string, ceil(n/2) 

	// Find the first half and second half of first string. 
	string Xl = X.substr(0, fh); 
	string Xr = X.substr(fh, sh); 

	// Find the first half and second half of second string 
	string Yl = Y.substr(0, fh); 
	string Yr = Y.substr(fh, sh); 

	// Recursively calculate the three products of inputs of size n/2 
	long int P1 = multiply(Xl, Yl); 
	long int P2 = multiply(Xr, Yr); 
	long int P3 = multiply(addBitStrings(Xl, Xr), addBitStrings(Yl, Yr)); 

	// Combine the three products to get the final result. 
	return P1*(1<<(2*sh)) + (P3 - P1 - P2)*(1<<sh) + P2; 
} 

// function to convert decimal to binary 
long long int decimalToBinary(int n) 
{ 
	// array to store binary number 
	int binaryNum[32]; 
    long long int num = 0;
	// counter for binary array 
	int i = 0; 
	while (n > 0) { 

		// storing remainder in binary array 
		binaryNum[i] = n % 2; 
		n = n / 2; 
		i++; 
	} 
    int k = i-1;
  
	// printing binary array in reverse order 
	for (int j = i - 1; j >= 0; j--) 
    {
        num = num + (binaryNum[j]*pow(10, k));
        k--;
     
    }
    return num;
}  


int main() 
{ 
	cout << "Input Number of Test Cases in First Line \nInput Two Intergers to be Multiplied in Second Line\nExample:\n1\n120 10\n1200\n";
    int t;
    cin >> t;
    while(t--)
    {
        int a, b;
        cin >> a >> b;
        long long int x = decimalToBinary(a);
        long long int y = decimalToBinary(b);
        string stri = to_string(x);
        string strj = to_string(y);
        cout << multiply(stri, strj) << endl;
        
    }
    return 0;
} 
