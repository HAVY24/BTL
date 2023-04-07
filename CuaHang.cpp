#include "header.h"

void menu_CH()
{
    gotoXY(50, 3);
    textcolor(6);
    box(50, 3, 20, 2, 6);
    gotoXY(51, 4);
    SetColor(15);
    printf("     Cua Hang    ");
    textcolor(103);
    gotoXY(51, 7);
    printf("  1. Nhap lieu     ");
    gotoXY(51, 9); 
    printf("  2. Xem Cua Hang  ");
}

void menu_SanPham()
{
    strcpy(sanphamCuaHang[0].ten, "AMERICANO");
    sanphamCuaHang[0].gia = 5;
    strcpy(sanphamCuaHang[1].ten, "CAPPUCCINO");
    sanphamCuaHang[1].gia = 5;
    strcpy(sanphamCuaHang[2].ten, "MACCHIATO");
    sanphamCuaHang[2].gia = 5;
    strcpy(sanphamCuaHang[3].ten, "Tra Dao");
    sanphamCuaHang[3].gia = 4;
    strcpy(sanphamCuaHang[4].ten, "Tra Vai");
    sanphamCuaHang[4].gia = 4;
    strcpy(sanphamCuaHang[5].ten, "Tra Buoi");
    sanphamCuaHang[5].gia = 4;
    strcpy(sanphamCuaHang[6].ten, "Tiramisu");
    sanphamCuaHang[6].gia = 2;
    strcpy(sanphamCuaHang[7].ten, "Mousse Cacao");
    sanphamCuaHang[7].gia = 2;
    strcpy(sanphamCuaHang[8].ten, "Pho Mai Ca Phe");
    sanphamCuaHang[8].gia = 2;
    for (int i = 0; i < 9; i++)
    {
        sanphamCuaHang[i].soluong = 0;
    }
}