// Last updated: 8/30/2026, 9:58:51 PM
1import java.util.ArrayList;
2import java.util.Collections;
3import java.util.List;
4
5class Solution {
6    public int[] plusOne(int[] digits) {
7        int carry  = 0;
8        for(int i = digits.length-1; i >= 0; i--){
9            if(i != digits.length-1)
10                digits[i] = (digits[i] + carry);
11            else 
12                digits[i] = (digits[i]+1);
13            carry = digits[i]/10;
14            digits[i] = digits[i] % 10;
15        }
16        
17        if(carry > 0) {
18            int[] newArray = new int[digits.length+1];
19            for(int i = 0; i < digits.length; i++)
20                    newArray[i+1] = digits[i];
21            newArray[0] = carry;
22            return newArray;
23        }
24        
25        return digits;
26    }
27}