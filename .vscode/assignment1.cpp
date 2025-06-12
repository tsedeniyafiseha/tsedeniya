//overload
#include <iostream>
using namespace std;

int multiply(int firstNumber, int secondNumber) {
    return firstNumber * secondNumber;
}

double divide(double numerator, double denominator) {
    return numerator / denominator;
}

int main() {
    int wholeNumber1 = 5, wholeNumber2 = 2;
    double decimalNumber1 = 5.0, decimalNumber2 = 2.0;

    cout << "Multiplication result: " << multiply(wholeNumber1, wholeNumber2) << endl;
    cout << "Division result: " << divide(decimalNumber1, decimalNumber2) << endl;
    
    return 0;
}
//function templates



#include <iostream>
using namespace std;

template <class T>
T addValues(T x, T y) {
    T total;
    total = x + y;
    return total;
}

int main() {
    int num1 = 5, num2 = 6, intResult;
    double val1 = 2.0, val2 = 0.5, doubleResult;

    intResult = addValues<int>(num1, num2);
    doubleResult = addValues<double>(val1, val2);

    cout << intResult << '\n';
    cout << doubleResult << '\n';

    return 0;
}
//function namespace 1




#include <iostream>
using namespace std;

namespace first {
    int getNumber() { return 5; }
}

namespace second {
    const double pi = 3.1416;
    double getDouble() { return 2 * pi; }
}

int main() {
    cout << first::getNumber() << '\n';
    cout << second::getDouble() << '\n';
    cout << second::pi << '\n';
    return 0;
}




//function namespace 2
#include <iostream>
using namespace std;

namespace groupA {
    int num1 = 5;
    int num2 = 10;
}

namespace groupB {
    double num1 = 3.1416;
    double num2 = 2.7183;
}

int main() {
    using groupA::num1;
    using groupB::num2;
    
    cout << num1 << '\n';
    cout << num2 << '\n';
    cout << groupA::num2 << '\n';
    cout << groupB::num1 << '\n';
    
    return 0;
}


//struct example1
#include <iostream>

struct product {
  int weight;
  double price;
} ;
product apple;
product banana, melon;



//struct example2
#include <iostream>
struct product {
  int weight;
  double price;
} apple, banana, melon;

//pinter in structure


struct movies_t {
  string title;
  int year;
};
int main ()
{ 
  string mystr;
  movies_t amovie;
  movies_t * pmovie;
  pmovie = &amovie;

  cout << "Enter title: ";
  getline (cin, pmovie->title);
  cout << "Enter year: ";
  getline (cin, mystr);
  (stringstream) mystr >> pmovie->year;

  return 0;
}

// nesting structure
struct movies_title {
  string title;
  int year;
};
struct friends_t {
  string name;
  string email;
  movies_t favorite_movie;
} abebe, samri;

friends_t * pfriends = &abebe





