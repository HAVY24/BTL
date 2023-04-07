#pragma once
#include <stdio.h>
#include <time.h>	
#include "windows.h" 
#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <cstdio>
#include <iomanip>
#include "mylib.h"
#include "CuaHang.h"
#include "KhachHang.h"
#include "menu_main.h"
#include "DoanhThu.h"
#include "NhanVien.h"


#define MAX_ITEMS 10

using namespace std;

struct SanPham {
    char ten[30];
    int gia;
    int soluong;  
};
struct KhachHang {
    char ten[30];
    int tuoi;
    SanPham GH[MAX_ITEMS];
    int soluongSP;
};

SanPham sanphamCuaHang[MAX_ITEMS];
KhachHang danhsachKH[100];
int sttKH = 0;
int vitri_object[9];



