#include"header.h"

void khoiTao(SinhVien sv[], int n) {
	for (int i = 0; i < n; i++) {
		sv[i].data.Head = NULL;
		sv[i].data.Tail = NULL;
	}
}

bool checkLoginGV(string a, string b) {
	fstream f;
	string c, d;
	f.open("AccountGV.txt", ios::in);
	if (f.fail())
		return false;
	while (!f.eof()) {
		getline(f, c, ',');
		getline(f, d, '\n');
		if (a == c && b == d) {
			f.close();
			return true;
		}
	}
	f.close();
	return false;
}

bool checkLoginSV(string a, string b) {
	fstream f;
	string c, d;
	f.open("AccountSV.txt", ios::in);
	if (f.fail())
		return false;
	while (!f.eof()) {
		getline(f, c, ',');
		getline(f, d, '\n');
		if (a == c && b == d) {
			f.close();
			return true;
		}
	}
	f.close();
	return false;
}

void changePass(string a, string c, AccountList& accountlist) {
	fstream f;
	f.open(c, ios::out);
	if (f.fail())
		return;
	Account* t = accountlist.Head;
	while (a != t->user) {
		t = t->pnext;
	}
	if (t == NULL)
		return;
	cout << "Nhap mat khau moi: ";
	cin >> t->pass;
	for (Account* temp = accountlist.Head; temp != NULL; temp = temp->pnext) {
		f << temp->user << "," << temp->pass << endl;
	}
	cout << "Thay doi thanh cong" << endl;
	f.close();
}


void InitAccountListGV(AccountList& accountlistGV) {
	accountlistGV.Head = accountlistGV.Tail = NULL;
}

void InitAccountListSV(AccountList& accountlistSV) {
	accountlistSV.Head = accountlistSV.Tail = NULL;
}

Account* CreateAccount(string a, string b) {
	Account* newAccount = new Account;
	newAccount->user = a;
	newAccount->pass = b;
	newAccount->pnext = NULL;
	return newAccount;
}

bool checkAccountListGV(AccountList accountlistGV) {
	if (accountlistGV.Head == NULL)
		return true;
	return false;
}

bool checkAccountListSV(AccountList accountlistSV) {
	if (accountlistSV.Head == NULL)
		return true;
	return false;
}

void saveAccountGV(AccountList& accountlistGV) {
	fstream f;
	f.open("AccountGV.txt");
	while (!f.eof()) {
		string a, b;
		getline(f, a, ',');
		getline(f, b, '\n');
		Account* temp = CreateAccount(a, b);
		if (checkAccountListGV(accountlistGV)) {
			accountlistGV.Head = temp;
			accountlistGV.Tail = temp;
		}
		else {
			accountlistGV.Tail->pnext = temp;
			accountlistGV.Tail = temp;
		}
	}
}

void saveAccountSV(AccountList& accountlistSV) {
	fstream f;
	f.open("AccountSV.txt");
	while (!f.eof()) {
		string a, b;
		getline(f, a, ',');
		getline(f, b, '\n');
		Account* temp = CreateAccount(a, b);
		if (checkAccountListGV(accountlistSV)) {
			accountlistSV.Head = temp;
			accountlistSV.Tail = temp;
		}
		else {
			accountlistSV.Tail->pnext = temp;
			accountlistSV.Tail = temp;
		}
	}
}

void login(AccountList& accountlistGV, AccountList& accountlistSV, SinhVien sv[], int n) {
	fstream f1, f2;
	f1.open("AccountGV.txt", ios::in | ios::out);
	f2.open("AccountSV.txt", ios::in | ios::out);
	string a, b;
	int t;
	while (true) {
		cout << "1. Giao Vien" << endl;
		cout << "2. Sinh Vien" << endl;
		cout << "Ban dang nhap voi tu cach: ";
		cin >> t;
		if (t == 1) {
			do {
				system("cls");
				cout << "Nhap tai khoan: ";
				cin >> a;
				cout << "Nhap mat khau: ";
				cin >> b;
			} while (!checkLoginGV(a, b));
			if (checkLoginGV(a, b)) {
				cout << "Dang nhap thanh cong" << endl;
				string c = "AccountGV.txt";
				changePass(a, c, accountlistGV);
			}
			else {
				cout << "Dang nhap that bai" << endl;
			}
		}
		if (t == 2) {
			do {
				system("cls");
				cout << "Nhap tai khoan: ";
				cin >> a;
				cout << "Nhap mat khau: ";
				cin >> b;
			} while (!checkLoginSV(a, b));
			system("cls");
			menuHS(a, sv, n, accountlistSV);
		}
	}
}


//a la MSSV, n la tong so tat ca sinh vien
//DOC TAI KHOAN SINH VIEN KHI DANG NHAP, DOC CAC MON HO DANG HOC 14
void readAccount(string a, SinhVien sv[], int n) {
	fstream f;
	string b, c, d, e, g, h;
	f.open("studentlist.csv", ios::in);
	if (f.fail()) {
		cout << "Khong mo duoc file" << endl;
		return;
	}
	while (!f.eof()) {
		string hoten;
		getline(f, b, ',');
		getline(f, c, ',');
		getline(f, d, ',');
		getline(f, e, ',');
		getline(f, g, ',');
		getline(f, h, '\n');
		hoten = d + " " + c;
		if (a == b) {
			cout << "Ma so sinh vien: " << b << endl;
			cout << "Ho va ten: " << hoten << endl;
			cout << "Gioi tinh: " << e << endl;
			cout << "Ngay sinh: " << g << endl;
			cout << "Gioi tinh: " << h << endl;
			break;
		}
	}
	f.close();
}

void readCourseAccount(string a, SinhVien sv[], int n) {
	fstream f1;
	string ma, ten, lop, gv, sotin, hsmax, nam, thoigian;
	cout << "Cac mon hoc da dang ki: " << endl;
	cout << "Ma mon hoc" << setw(20) << "Ten mon hoc" << setw(30) << "Lop hoc" << setw(15) << "Giao vien" << setw(20) << "So tin" << setw(10) << "Toi da" << setw(10) << "Nam hoc" << setw(10) << "Thoi gian hoc" << endl;
	for (int i = 0; i < n; i++) {
		if (a == sv[i].MSSV) {
			Node* temp = sv[i].data.Head;
			f1.open("courselist.csv", ios::in);
			if (f1.fail()) {
				cout << "Khong mo duoc file courseslist" << endl;
				return;
			}
			string line;
			while (getline(f1, line) && temp != NULL) {
				stringstream ss(line);
				getline(ss, ma, ',');
				if (ma == temp->MaMH) {
					cout << ma << setw(20);
					getline(ss, ten, ',');
					cout << ten << setw(30);
					getline(ss, lop, ',');
					cout << lop << setw(15);
					getline(ss, gv, ',');
					cout << gv << setw(20);
					getline(ss, sotin, ',');
					cout << sotin << setw(10);
					getline(ss, hsmax, ',');
					cout << hsmax << setw(10);
					getline(ss, nam, ',');
					cout << nam << setw(10);
					getline(ss, thoigian, '\n');
					cout << thoigian << endl;
					temp = temp->pnext;
				}
				else
					continue;
			}
		}
	}
}

int demSV() {
	fstream f;
	f.open("CourseofStudent.csv");
	int n = 0;
	string line;
	while (getline(f, line)) {
		if (line != "")
			n++;
	}
	f.close();
	return n;
}


void luuMonHocvaoList(SinhVien sv[], int n) {
	fstream f;
	f.open("CourseofStudent.csv", ios::in);
	if (f.fail()) {
		cout << "Can't open this file";
		return;
	}
	for (int i = 0; i < n; i++) {
		string line, a, b;
		getline(f, line);
		stringstream ss(line);
		string element;
		getline(ss, sv[i].MSSV, ',');
		while (getline(ss, element, ',')) {
			if (sv[i].data.Head == NULL) {
				Node* temp = new Node;
				temp->MaMH = element;
				temp->pnext = NULL;
				sv[i].data.Head = temp;
				sv[i].data.Tail = temp;
			}
			else {
				Node* temp = new Node;
				temp->MaMH = element;
				temp->pnext = NULL;
				sv[i].data.Tail->pnext = temp;
				sv[i].data.Tail = temp;
			}
		}
	}
	f.close();
}

//a la MSSV, b la Ma mon hoc
//HAM NAY DE GIAO VIEN XOA BAN RA KHOI KHOA HOC (BEN KIA CO 1 FUNC NUA)  12
void xoaMonHocSV(string a, string b, SinhVien sv[], int n) {
	for (int i = 0; i < n; i++) {
		if (a == sv[i].MSSV) {
			Node* temp = sv[i].data.Head;
			if (sv[i].data.Head->MaMH == b) {
				sv[i].data.Head = sv[i].data.Head->pnext;
				delete temp;
				break;
			}
			if (sv[i].data.Tail->MaMH == b) {
				while (temp->pnext != sv[i].data.Tail) {
					temp = temp->pnext;
				}
				sv[i].data.Tail = temp;
				delete temp->pnext;
				temp->pnext = NULL;
				break;
			}
			while (temp->pnext != NULL) {
				if (temp->pnext->MaMH == b) {
					temp->pnext = temp->pnext->pnext;
					break;
				}
				temp = temp->pnext;
			}

		}
	}
}

void luuMonHocvaoFile(SinhVien sv[], int n) {
	fstream f;
	f.open("CourseofStudent.csv", ios::out);
	if (f.fail()) {
		cout << "Can't open this file";
		return;
	}
	for (int i = 0; i < n; i++) {
		f << sv[i].MSSV << ",";
		Node* temp = sv[i].data.Head;
		while (temp != NULL) {
			f << temp->MaMH << ",";
			temp = temp->pnext;
		}
		f << endl;
	}
	f.close();
}

void menuHS(string a, SinhVien sv[], int n, AccountList& accountlistSV) {
	int luachon;
	do {
		system("cls");
		cout << "1. Xem thong tin" << endl;
		cout << "2. Xem danh sach mon hoc dang ky" << endl;
		cout << "3. Thay doi mat khau" << endl;
		cout << "4. Dang xuat" << endl;
		cout << "Nhap lua chon: ";
		cin >> luachon;
		switch (luachon) {
		case 4:
			system("cls");
			break;
		case 1:
			system("cls");
			readAccount(a, sv, n);
			system("pause");
			break;
		case 2:
			system("cls");
			readCourseAccount(a, sv, n);
			system("pause");
			break;
		case 3:
			system("cls");
			string c = "AccountSV.txt";
			changePass(a, c, accountlistSV);
			system("pause");
			break;
		}
	} while (luachon != 4);
}

void menuGV(string a, SinhVien sv[], int n, AccountList& accountlistGV) {
	int luachon;
	do {
		system("cls");
		cout << "1. Tao nam hoc moi" << endl;
		cout << "2. Xem danh sach mon hoc dang ky" << endl;
		cout << "3. Thay doi mat khau" << endl;
		cout << "4. Dang xuat" << endl;
		cout << "Nhap lua chon: ";
		cin >> luachon;
		switch (luachon) {
		case 4:
			system("cls");
			break;
		case 1:
			system("cls");
			readAccount(a, sv, n);
			system("pause");
			break;
		case 2:
			system("cls");
			readCourseAccount(a, sv, n);
			system("pause");
			break;
		case 3:
			system("cls");
			string c = "AccountSV.txt";
			changePass(a, c, accountlistGV);
			system("pause");
			break;
		}
	} while (luachon != 4);
}