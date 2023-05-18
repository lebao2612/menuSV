#include"header.h"

int main() {
	//CHUA CAN CHINH DUOC COT KHI XUAT

	int n = demSV();
	SinhVien* sv = new SinhVien[n];
	khoiTao(sv, n);
	luuMonHocvaoList(sv, n);
	AccountList accountlistGV, accountlistSV;
	InitAccountListGV(accountlistGV);
	InitAccountListSV(accountlistSV);
	saveAccountGV(accountlistGV);
	saveAccountSV(accountlistSV);
	login(accountlistGV, accountlistSV, sv, n);
	return 0;
}