#include<iostream>
#include<fstream>
#include "utils.h"
class Cell;
class Table;
class Cell {
    protected:
        //��� ��ġ�� �ִ����� ���� x,y��
        int x,y;
        Table* table;
        //�ش� ������ �����ϴ� ���ڿ� data
        string data;

    public:
        virtual string stringify();
        virtual int to_numeric();

        Cell(string data, int x, int y, Table * table);
};

Cell::Cell(string data, int x, int y, Table* table) 
    : data(data), x(x), y(y), table(table) {}

//�ش� ������ ���ڿ��� ��ȯ�ϴ� stringify�Լ�
string Cell::stringify() { return data; }
//���� �����ͷ� ��ȯ�ϴ� to_numberic�Լ�
int Cell::to_numeric() { return 0; }

class Table {
    protected:
        //�� �� ���� �ִ� ũ��
        int max_row_size, max_col_size;

        //�����͸� �����ϴ� ���̺�
        //cell*�� �����ϴ� 2���� �迭�̶� �����ϸ� ���ϴ�.
        Cell*** data_table;

    public:
        Table(int max_row_size, int max_col_size);

        ~Table();

        //���ο� ���� row�� col���� ����Ѵ�.
        void reg_cell(Cell* c,int row, int col);

        //�ش� ���� �������� ��ȯ�Ѵ�.
        //s: �� �̸�(Ex. A3, B6�� ����)
        int to_numeric(const string& s);

        //�� �� �� ��ȣ�� ���� ȣ���Ѵ�.
        int to_numeric(int row, int col);
        // �ش缿�ǹ��ڿ�����ȯ�Ѵ�.
        string stringify(const string& s);
        string stringify(int row, int col);
        //���� ���� �Լ�
        virtual string print_table() = 0;
};

//��ü�� �ʿ��� �� ���� �������� �����ϰ�, �� ��ü�� ���� �����͸� 2���� �迭�� �����ϰ� �ְ��Ѵ�.
//���� �Ҵ����� Cell* �迭�� ������ �Ŀ�, Cell ��ü�� �ʿ��� ������ �����ؼ� �迭�� ���ҵ��� 
//�̸� ����ų �� �ְ��Ѵ�.
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
//Table �Ҹ��ڵ� �̿� ���, �������� ������ Cell ��ü�� ��� ������ �ϰ� 
// Cell �迭(1����) ���� -> 2���� ���̺� ��ü�� �޸𸮿��� ����
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
//Table�� ���� ����ϴ� �Լ�.
// ����ϰ��� �ϴ� ��ġ�� ���ڷ� �޴µ�, �ش� ��ġ�� �̹� �ٸ� �� ��ü�� �ִٸ� ��ü�� delete�ϰ� ���
void Table::reg_cell(Cell* c, int row, int col) {
	if (!(row < max_row_size && col < max_col_size)) return;

	if (data_table[row][col]) {
		delete data_table[row][col];
	}
	data_table[row][col] = c;
}
//���� �̸��� �ش��ϴ� ���� ��ȯ�ϴ� �Լ�
int Table::to_numeric(const string& s) {
	// Cell �̸����� �޴´�.
	int col = s[0] - 'A';
	int row = atoi(s.c_str() + 1) - 1;

	if (row < max_row_size && col < max_col_size) {
		if (data_table[row][col]) {
			return data_table[row][col]->to_numeric();
		}
	}
	return 0;
}
//���� ��� ������ �ش��ϴ� ���� ��ȯ�ϴ� �Լ�
int Table::to_numeric(int row, int col) {
	if (row < max_row_size && col < max_col_size && data_table[row][col]) {
		return data_table[row][col]->to_numeric();
	}
	return 0;
}

string Table::stringify(const string& s) {
	// Cell �̸����� �޴´�.
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
//ǥ�� ��Ʈ�� �����
std::ostream& operator<<(std::ostream& o, Table& table) {
	o << table.print_table();
	return o;
}

class TxtTable : public Table {
    string repeat_char(int n, char c);

    //���ڷ� �� �� ��ȣ�� A, B , ..... Z, AA, AB, ... �̷������� �Ű��ش�.
    string col_num_to_str(int n);
    public:
        TxtTable(int row, int col);

        //�ؽ�Ʈ�� ǥ�� �����ϰ� ������ش�.
        string print_table();
};
TxtTable::TxtTable(int row,int col) : Table(row,col){}
//�ؽ�Ʈ�� ǥ�� �����ϰ� ������ش�.
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
    // �ǻ�ܿ� �� ���� ǥ��
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
    //�ϴ� �⺻������ �ִ� 9999��° ����� �����Ѵٰ� �����Ѵ�.
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

 // ���ڷεȿ���ȣ��A, B, .... Z, AA, AB, ... �̷������θŰ��ش�.
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