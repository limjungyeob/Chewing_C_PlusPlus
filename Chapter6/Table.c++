#include<iostream>
#include<fstream>
#include "utils.h"
class Cell;
class Table;
class Cell {
    protected:
        //어느 위치에 있는지에 대한 x,y값
        int x,y;
        Table* table;
        //해당 내용을 보관하는 문자열 data
        string data;

    public:
        virtual string stringify();
        virtual int to_numeric();

        Cell(string data, int x, int y, Table * table);
};

Cell::Cell(string data, int x, int y, Table* table) 
    : data(data), x(x), y(y), table(table) {}

//해당 셀값을 문자열로 변환하는 stringify함수
string Cell::stringify() { return data; }
//정수 데이터로 변환하는 to_numberic함수
int Cell::to_numeric() { return 0; }

class Table {
    protected:
        //행 및 열의 최대 크기
        int max_row_size, max_col_size;

        //데이터를 보관하는 테이블
        //cell*을 보관하는 2차원 배열이라 생각하면 편하다.
        Cell*** data_table;

    public:
        Table(int max_row_size, int max_col_size);

        ~Table();

        //새로운 셀을 row행 col열에 등록한다.
        void reg_cell(Cell* c,int row, int col);

        //해당 셀의 정수값을 반환한다.
        //s: 셀 이름(Ex. A3, B6과 같이)
        int to_numeric(const string& s);

        //행 및 열 번호로 셀을 호출한다.
        int to_numeric(int row, int col);
        // 해당셀의문자열을반환한다.
        string stringify(const string& s);
        string stringify(int row, int col);
        //순수 가상 함수
        virtual string print_table() = 0;
};

//객체는 필요할 때 마다 동적으로 생성하고, 그 객체에 대한 포인터를 2차원 배열로 보관하고 있게한다.
//동적 할당으로 Cell* 배열을 생성한 후에, Cell 객체가 필요할 때마다 생성해서 배열의 원소들이 
//이를 가리킬 수 있게한다.
Table::Table(int max_row_size, int max_col_size)
    : max_row_size(max_row_size), max_col_size(max_col_size) {
        data_table = new Cell**[max_row_size];
        for (int i = 0; i < max_row_size; i++) {
            data_table[i] = new Cell*[max_col_size];
                for (int j = 0; j < max_col_size; j++) {
                    data_table[i][j] = NULL;
                }
        }
}
//Table 소멸자도 이와 비슷, 동적으로 생성된 Cell 객체를 모두 지워야 하고 
// Cell 배열(1차원) 삭제 -> 2차원 테이블 자체를 메모리에서 삭제
Table::~Table() {
	for (int i = 0; i < max_row_size; i++) {
		for (int j = 0; j < max_col_size; j++) {
			if (data_table[i][j]) delete data_table[i][j];
		}
	}
	for (int i = 0; i < max_row_size; i++) {
		delete[] data_table[i];
	}
	delete[] data_table;
}
//Table의 셀을 등록하는 함수.
// 등록하고자 하는 위치를 인자로 받는데, 해당 위치에 이미 다른 셀 객체가 있다면 객체를 delete하고 등록
void Table::reg_cell(Cell* c, int row, int col) {
	if (!(row < max_row_size && col < max_col_size)) return;

	if (data_table[row][col]) {
		delete data_table[row][col];
	}
	data_table[row][col] = c;
}
//셀의 이름에 해당하는 값을 반환하는 함수
int Table::to_numeric(const string& s) {
	// Cell 이름으로 받는다.
	int col = s[0] - 'A';
	int row = atoi(s.c_str() + 1) - 1;

	if (row < max_row_size && col < max_col_size) {
		if (data_table[row][col]) {
			return data_table[row][col]->to_numeric();
		}
	}
	return 0;
}
//셀의 행과 열값에 해당하는 값을 반환하는 함수
int Table::to_numeric(int row, int col) {
	if (row < max_row_size && col < max_col_size && data_table[row][col]) {
		return data_table[row][col]->to_numeric();
	}
	return 0;
}

string Table::stringify(const string& s) {
	// Cell 이름으로 받는다.
	int col = s[0] - 'A';
	int row = atoi(s.c_str() + 1) - 1;

	if (row < max_row_size && col < max_col_size) {
		if (data_table[row][col]) {
			return data_table[row][col]->stringify();
		}
	}
	return 0;
}

string Table::stringify(int row, int col) {
	if (row < max_row_size && col < max_col_size && data_table[row][col]) {
		return data_table[row][col]->stringify();
	}
	return "";
}
//표준 스트림 입출력
std::ostream& operator<<(std::ostream& o, Table& table) {
	o << table.print_table();
	return o;
}

class TxtTable : public Table {
    string repeat_char(int n, char c);

    //숫자로 된 열 번호를 A, B , ..... Z, AA, AB, ... 이런순으로 매겨준다.
    string col_num_to_str(int n);
    public:
        TxtTable(int row, int col);

        //텍스트로 표를 깨끗하게 출력해준다.
        string print_table();
};
TxtTable::TxtTable(int row,int col) : Table(row,col){}
//텍스트로 표를 깨끗하게 출력해준다.
string TxtTable::print_table(){
    string total_table;

    int* col_max_wide = new int[max_col_size];

    for(int i=0; i< max_col_size; i++){
        unsigned int max_wide = 2;
        for(int j=0; j<max_row_size; j++) {
            if(data_table[j][i] && 
                data_table[j][i] -> stringify().length() > max_wide) {
                    max_wide = data_table[j][i]->stringify().length();
                }
        }
        col_max_wide[i] = max_wide;
    }
    // 맨상단에 열 정보 표시
    total_table += "   ";
    int total_wide = 4;
    for(int i=0; i<max_col_size; i++) {
        if(col_max_wide[i]) {
            int max_len = std::max(2,col_max_wide[i]);
            total_table += " | " + col_num_to_str(i);
            total_table += repeat_char(max_len - col_num_to_str(i).length(), ' ');

            total_wide += (max_len + 3);
        }
    }

    total_table += "\n";
    //일단 기본적으로 최대 9999번째 행까지 지원한다고 생각한다.
    for(int i=0; i<max_row_size; i++) {
        total_table += repeat_char(total_wide, '-');
        total_table += "\n" + std::to_string(i+1);
        total_table += repeat_char(4 - std::to_string(i+1).length(), ' ');

        for(int j=0; j<max_col_size; j++) {
            if(col_max_wide[j]) {
                int max_len = std::max(2,col_max_wide[j]);

                string s= "";
                if(data_table[i][j]) {
                    s = data_table[i][j] -> stringify();
                }
                total_table +=" | " + s;
                total_table += repeat_char(max_len - s.length(), ' ');
            }
        }
        total_table += "\n";
    }
    return total_table;
}

string TxtTable::repeat_char(int n, char c) {
    string s = "";
    for (int i = 0; i < n; i++) s.push_back(c);
        return s;
}

 // 숫자로된열번호를A, B, .... Z, AA, AB, ... 이런순으로매겨준다.
string TxtTable::col_num_to_str(int n) {
    string s = "";
    if (n < 26) {
        s.push_back('A' + n);
    } else {
        char first = 'A' + n / 26- 1;
        char second = 'A' + n % 26;
        s.push_back(first);
        s.push_back(second);
    }
    return s;
}

int main() {
    TxtTable table1(5,5);
    std::ofstream out("C:\\Users\\ehdtk\\Desktop\\other.txt");
    table1.reg_cell(new Cell("Hello~", 0, 0, &table1), 0, 0);
	table1.reg_cell(new Cell("C++", 0, 1, &table1), 0, 1);

	table1.reg_cell(new Cell("Programming", 1, 1, &table1), 1, 1);
	std::cout << std::endl << table1;
	out << table1;
}