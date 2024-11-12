class Solution {
public:

   	string numberToWordsHelper(int num)
	{
	    map<int,string> mp;
	    mp[0] = "Zero";
        mp[1] = "One";
        mp[2] = "Two";
        mp[3] = "Three";
        mp[4] = "Four";
        mp[5] = "Five";
        mp[6] = "Six";
        mp[7] = "Seven";
        mp[8] = "Eight";
        mp[9] = "Nine";
	    mp[10] = "Ten";
        mp[11] = "Eleven";
        mp[12] = "Twelve";
        mp[13] = "Thirteen";
        mp[14] = "Fourteen";
        mp[15] = "Fifteen";
        mp[16] = "Sixteen";
        mp[17] = "Seventeen";
        mp[18] = "Eighteen";
        mp[19] = "Nineteen";
        mp[20] = "Twenty";
        mp[30] = "Thirty";
        mp[40] = "Forty";
        mp[50] = "Fifty";
        mp[60] = "Sixty";
        mp[70] = "Seventy";
        mp[80] = "Eighty";
        mp[90] = "Ninety";
	    mp[100] = "Hundred";
	      
	    vector<int> arr{100,90,80,70,60,50,40,30,20,19,18,17,16,15,14,13,12,11,10,9,8,7,6,5,4,3,2,1,0};
	    int i = 0;
	    string result;
	/*
	    932
	    i = 0;      1      
	    num = 932   32    2       0
	result: nine hundred thirty two
	*/
	    while ((i< arr.size()) && (num >0))
	    {
	        if (num>=100)
	        {
	           result+= mp[num/100] + " ";
	           result += mp[100] + " ";
	           num = num%100;
	        }
	        else if (num>=arr[i]) // arr[i] =30
	        {
	          result += mp[arr[i]] + " ";
	          num -=arr[i]; // 2
	        }
	        i++;
	    }
        return result;
	    
	}
	// Num from INT32_MIN to INT32_MAX
	string numberToWords(int num)
	{
	  string result;
	  if (num <0)
	  {
	    result += "Negative ";
	    num = -num;
	  }
	  // num 200000
	  if (num ==0)
	  {
	    return "Zero";
	  }
	  while (num >0)
	  {
	     if (num >= 1000000000) 
	     {
	        result += numberToWordsHelper(num/1000000000);
	        result += "Billion ";
	        num = num % 1000000000;
	     }
	     else  if (num >= 1000000) 
	     {
	        result += numberToWordsHelper(num/1000000);
	        result += "Million ";
	        num = num % 1000000;
	     }
	     else if (num >= 1000) 
	     {
	        result += numberToWordsHelper(num/1000);
	        result += "Thousand ";
	        num = num % 1000;
	        // two hundred thousand zero
	        // num 0;
	        // nine hundred eighty five  thousand
	        // num 345
	     }
	     else if (num >0)
	     {
	        result += numberToWordsHelper(num);
	        break;
	        // nine hundred eighty five  thousand three hundred fourty five
	     }
	  }
        while ((result.back() >='z') ||  (result.back() <='a')) result.pop_back();
        return result;
}
};