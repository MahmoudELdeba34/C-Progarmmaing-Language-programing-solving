#include <iostream>
using namespace std;

class Complex {
private:
    double real; // Real part
    double img;  // Imaginary part

public:
    // Default constructor
    Complex() : real(0), img(0) {}

    // Constructor with parameters
    Complex(double r, double i) : real(r), img(i) {}

    // Function to set real and imaginary parts
    void setValues(double r, double i) {
        real = r;
        img = i;
    }

    // Member function to add another complex number to the current complex number
    Complex add(const Complex& other) const {
        return Complex(real + other.real, img + other.img);
    }

    // Function to print the complex number
    void print() const {
        if (real != 0 && img != 0) {
            // Check for +i or -i cases
            if (img == 1) {
                cout << real << " + i" << endl;
            } else if (img == -1) {
                cout << real << " - i" << endl;
            } else if (img > 0) {
                cout << real << " + " << img << "i" << endl;
            } else {
                cout << real << " - " << -img << "i" << endl;
            }
        } else if (real != 0) {
            cout << real << endl;
        } else if (img != 0) {
            // Handle i and -i cases
            if (img == 1) {
                cout << "i" << endl;
            } else if (img == -1) {
                cout << "-i" << endl;
            } else {
                cout << img << "i" << endl;
            }
        } else {
            cout << 0 << endl;
        }
    }
};

int main() {
    Complex c1, c2, result;
    double realPart, imgPart;

    // Input for c1
    cout << "Enter the real part of c1: ";
    cin >> realPart;
    cout << "Enter the imaginary part of c1: ";
    cin >> imgPart;
    c1.setValues(realPart, imgPart);

    // Input for c2
    cout << "Enter the real part of c2: ";
    cin >> realPart;
    cout << "Enter the imaginary part of c2: ";
    cin >> imgPart;
    c2.setValues(realPart, imgPart);

    // Using member function to add c1 and c2 and store in result
    result = c1.add(c2);

    // Display results
    cout << "Result of c1: ";
    c1.print();
    cout << "Result of c2: ";
    c2.print();
    cout << "Sum (result): ";
    result.print();

    return 0;
}
