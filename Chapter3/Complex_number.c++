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
        //����
        if (isdigit(str[i]) && integer_part) {
            num *= 10.0;
            num += (str[i]- '0');
            //str[i] - '0'�� �ϴ� ����� ����� ���� ���̴µ�, ASCII ���̺� �󿡼� 0���� 9���� ���ڵ���
            // ũ�� ������ ���������� �迭�Ǿ� �ֱ� ������ �ܼ��� '0'�� �������� �� ���ڿ� �ش��ϴ� ���� ���� ����
            // ���� �� �ְ� �˴ϴ�.
            //ex) 123.45 -> num = 1, num = 12, num = 123
        } else if (str[i] == '.')
            integer_part = false;
        //�Ҽ���
        else if (isdigit(str[i]) && !integer_part) {
            decimal /= 10.0;
            num += ((str[i]- '0') * decimal);
        } else
            break; // ���̿����̻��ѹ��ڵ��̿ð��
    }
    if (minus) num *=-1.0;
    return num;
}
Complex Complex::operator+(const char* str) {
    // �Է¹������ڿ����м��Ͽ�real �κа�img �κ���ã�ƾ��Ѵ�.
    // ���ڿ��ǲ��������������ϴ�"[��ȣ](�Ǽ���)(��ȣ)i(�����)"
    // �̶��Ǿ��Ǻ�ȣ�»��������մϴ�. (������+ ����)
    int begin = 0, end = strlen(str);
    double str_img = 0.0, str_real = 0.0;
    // ������������̵Ǵ�'i' ����ġ��ã�´�.
    int pos_i =-1;
    for (int i = 0; i != end; i++) {
        if (str[i] == 'i') {
            pos_i = i;
            break;
        }
    }
    // ����'i' �����ٸ��̼��½Ǽ����̴�.
    if (pos_i ==-1) {
        str_real = get_number(str, begin, end- 1);
        Complex temp(str_real, str_img);
        return (*this) + temp;
    }
    // ����'i' ���ִٸ�, �Ǽ��ο�����θ������ó���ϸ�ȴ�.
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