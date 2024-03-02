//Easy:
//Check for valid quotation marks
//Design a function called "isValidQuotations" to determine if a given string containing quotations is valid. 
//The function should return True if the quotations within the string are properly paired and balanced, 
//and False otherwise.


//Example:
//Input: "This is a 'valid' string with 'balanced' quotations." 
//Output: True


#include <iostream>
#include <string>
#include <stack>

using namespace std;

bool isValidQuotations (const string & str){
stack <char> quotes ;

for(char C : str){
 if (C == '\'' || C == '"') {
  if (quotes.empty() || quotes.top() !=C){
        quotes.push(C);
  } else {
                quotes.pop();
            }
        }
    }
    return quotes.empty();
}

int main() {
      string in = "21'5444'''";
      bool result = isValidQuotations(in);
      cout << boolalpha << result << endl; 

    return 0;
}