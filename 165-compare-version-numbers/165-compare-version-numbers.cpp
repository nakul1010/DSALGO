class Solution {
public:
    int compareVersion(string str1, string str2) 
    {
        int n1 = str1.length(), n2 = str2.length();
        int i=0,j=0;
        
        while(i<n1 || j<n2)
        {
            int number1 = 0, number2 = 0;
            while(i<n1 && str1[i]!='.')
            {
                number1 = (number1 * 10) + (str1[i]-'0');//leading zeros handled 
                i++;
            }
            
            while(j<n2 && str2[j]!='.')
            {
                number2 = (number2 * 10) + (str2[j]-'0');
                j++;
            }
            
            if(number1 > number2)
                return 1;
            if(number1 < number2)
                return -1;
            
            i++,j++;
        }
        return 0;
    }
};