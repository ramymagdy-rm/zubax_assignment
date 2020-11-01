#include <iostream>

using namespace std;

#define MAX_1e6 1000000
#define MAX_1e9 1000000000

unsigned long long int rsa_equation(unsigned int n, unsigned int e, unsigned long int m){
   unsigned long long int value = 1;
   for(unsigned int i = e; i > 0; i--){
      value *= n;
      value %= m;
   }
   return value;
}

bool in_range(unsigned long int n, unsigned int low, unsigned long int high){
    return n >= low && n <= high;
}

int main(){
   unsigned int b = 0;
   unsigned int p = 0;
   unsigned long int m = 0;
   cout << "Calculating  c = (b^p) (mod m) please enter b, p, and m: " << endl;
   try{
      cout << "b = "; cin >> b;
      if (in_range(b, 0, MAX_1e9) == false)
         throw out_of_range("out of range b");
      cout << "p = "; cin >> p;
      if (in_range(p, 0, MAX_1e6) == false)
         throw out_of_range("out of range p");
      cout << "m = "; cin >> m;
      if (in_range(m, 0, MAX_1e9) == false)
         throw out_of_range("out of range m");
   }
   catch (out_of_range & e){
      cout<< e.what() << endl;
      return 1;
   }
   cout << "Result is " << rsa_equation(b, p, m) << endl;
   return 0;
}