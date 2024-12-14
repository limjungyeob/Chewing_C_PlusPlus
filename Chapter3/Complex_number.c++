#include<iostream>
#include <cstring>
class Complex{
    private :
        double real, img;
        double get_number(const char* str, int from, int to);
    public :
        Complex(double real, double img) : real(real), img(img) {}
        Complex(const Complex& c) { real = c.real; img = c.img; }

        Complex operator+(const Complex& c);
        Complex operator+(const char* str);
        Complex operator-(const Complex& c);
        Complex operator*(const Complex& c);
        Complex operator/(const Complex& c);
        Complex& operator=(const Complex& c);
        Complex& operator+=(const Complex& c);
        Complex& operator-=(const Complex& c);
        Complex& operator*=(const Complex& c);
        Complex& operator/=(const Complex& c);

    void println() {
        std::cout<<"(" << real << "," <<img <<" )" <<std::endl;
    }
};
Complex Complex::operator+(const Complex& c) {
    Complex temp(real + c.real, img + c.img);
    return temp;
}
double Complex::get_number(const char* str, int from, int to) {
    bool minus = false;
    if (from > to) return 0;
    if (str[from] == '-') minus = true;
    if (str[from] == '-' || str[from] == '+') from++;
    double num = 0.0;
    double decimal = 1.0;
    bool integer_part = true;
    for (int i = from; i <= to; i++) {
        //정수
        if (isdigit(str[i]) && integer_part) {
            num *= 10.0;
            num += (str[i]- '0');
            //str[i] - '0'을 하는 기법은 상당히 자주 쓰이는데, ASCII 테이블 상에서 0부터 9까지 숫자들이
            // 크기 순으로 연속적으로 배열되어 있기 때문에 단순히 '0'을 빼버리면 그 숫자에 해당하는 실제 정수 값을
            // 구할 수 있게 됩니다.
            //ex) 123.45 -> num = 1, num = 12, num = 123
        } else if (str[i] == '.')
            integer_part = false;
        //소숫점
        else if (isdigit(str[i]) && !integer_part) {
            decimal /= 10.0;
            num += ((str[i]- '0') * decimal);
        } else
            break; // 그이외의이상한문자들이올경우
    }
    if (minus) num *=-1.0;
    return num;
}
Complex Complex::operator+(const char* str) {
    // 입력받은문자열을분석하여real 부분과img 부분을찾아야한다.
    // 문자열의꼴은다음과같습니다"[부호](실수부)(부호)i(허수부)"
    // 이때맨앞의부호는생략가능합니다. (생략시+ 라가정)
    int begin = 0, end = strlen(str);
    double str_img = 0.0, str_real = 0.0;
    // 먼저가장기준이되는'i' 의위치를찾는다.
    int pos_i =-1;
    for (int i = 0; i != end; i++) {
        if (str[i] == 'i') {
            pos_i = i;
            break;
        }
    }
    // 만일'i' 가없다면이수는실수뿐이다.
    if (pos_i ==-1) {
        str_real = get_number(str, begin, end- 1);
        Complex temp(str_real, str_img);
        return (*this) + temp;
    }
    // 만일'i' 가있다면, 실수부와허수부를나누어서처리하면된다.
    str_real = get_number(str, begin, pos_i- 1);
    str_img = get_number(str, pos_i + 1, end- 1);
    if (pos_i >= 1 && str[pos_i- 1] == '-') str_img *=-1.0;
    Complex temp(str_real, str_img);
    return (*this) + temp;
}
Complex Complex::operator-(const Complex& c) {
    Complex temp(real - c.real , img - c.img);
    return temp;
}
Complex Complex::operator*(const Complex& c) {
    Complex temp(real * c.real - img * c.img, real * c.img + img * c.real);
    return temp;
}
Complex Complex::operator/(const Complex& c) {
    Complex temp(
        (real * c.real + img * c.img) / (c.real * c.real + c.img * c.img),
    (img * c.real- real * c.img) / (c.real * c.real + c.img * c.img)
    );
    return temp;
}
Complex& Complex::operator=(const Complex& c) {
    real = c.real;
    img = c.img;
    return *this;
}

Complex& Complex::operator+=(const Complex& c) {
    (*this) = (*this) + c;
    return *this;
}

Complex& Complex::operator-=(const Complex& c) {
    (*this) = (*this)- c;
    return *this;
}

Complex& Complex::operator*=(const Complex& c) {
    (*this) = (*this) * c;
    return *this;
}

Complex& Complex::operator/=(const Complex& c) {
    (*this) = (*this) / c;
    return *this;
}


int main() { 
    Complex a(1.0, 2.0);
    Complex b(3.0, -2.0);

    Complex c = a*b;
    Complex d(0.0,0.0);
    Complex f(0.0, 0.0);
    c.println();
    d = a * b + a/ b + a + b;
    d.println();
    f +=b;
    f.println();
    a = a + "-1.1 + i3.923";
    a.println(); 
}