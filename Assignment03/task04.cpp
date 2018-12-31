/* Question 4)
Create  a class name it math ,it should contain the following functions
1) Calculate LCM of three numbers :
  int LCM(int a ,int b ,int c)
2) Calculate HCF of three numbers:
  int HCF(int a ,int b,int c)
3) A function which returns the nth prime number for example
  if inputs are 1,5,25 then the output should be :- 2,11,97 respectively.
*/
# include<iostream>
using namespace std;

class math{
  public:
    int LCM(int a, int b, int c){
      int lcm = 1;
      for(int i = 2 ; (a , b , c) > 2; i++){
        if (a%i == 0 or b%i == 0 or c%i == 0){
            lcm *= i;
          }
        if (a%i == 0){
          a /= i;
          if (a%i == 0 and i > 1)
            {i--;}
          }
        if (b%i == 0){
          b /= i;
          if (b%i == 0 and i > 1)
            {i--;}
          }
        if (c%i == 0){
          c /= i;
          if (c%i == 0 and i > 1)
            {i--;}
          }
        }
      return lcm;
    }

    int HCF(int a ,int b,int c){
      int hcf = 0;
      for(int i = 2 ; i < (a, b, c); i++)
        if (a%i == 0 and b%i == 0 and c%i == 0)
          hcf = i;

      return hcf;
    }

    bool is_prime(int n){
      if (n <= 1)
        return false;

      for(int i = n-1; i > 1; i--)
        if (n%i == 0)
          return false;

      return true;
    }

    int nth_prime(int num){
      if (num <= 0)
        return -1;

      int prime, p_count = 0;
      for (int i=0; p_count < num;i++)
        if (is_prime(i))
          prime = i, p_count++;

      return prime;
    }
};

int main(void){
  math m1;
  // nth prime
  cout << m1.nth_prime(100) << endl;
  // LCM
   cout << m1.LCM(2, 14, 7) << endl;
  // // HCF
   cout << m1.HCF(16, 8, 24) << endl;
  return 0;
}
