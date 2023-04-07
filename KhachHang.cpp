#include "header.h"
void menu_KH()
{

    ShowCur(0);
    int x = 38;
    int y = 5;
    int w_box = 44;
    int h_box = 4;
    int h = 2;
    int t_color = 15;
    int b_color_hl = 118;
    int n_cot = 2;
    gotoXY(50, 3);
    textcolor(6);
    box(50, 1, 20, 2, 6);
    gotoXY(51, 2);
    SetColor(15);
    printf("     Khach Hang    ");

    // int control = 0;

    // iN menu
    box(x, y, w_box, h_box, t_color);
    textcolor(6);
    gotoXY(48, y);
    printf("< Moi ban chon Dich Vu >");
    gotoXY(50, 13);
    SetColor(t_color);
    printf("NHAN ");
    SetColor(6);
    printf("ESC");
    SetColor(t_color);
    printf(" DE QUAY LAI");
    textcolor(14);
    gotoXY(x + 1, y + 1);
    printf("                 Chon Hang                 ");
    gotoXY(48, 7);
    for (int i = 10; i < 34; i++)
    {
        SetColor(t_color);
        printf("%c", char(196));
    }
    gotoXY(x + 1, y + 3);
    textcolor(14);
    printf("            Loai bo mot mat hang           ");
    int xp = x;
    int yp = y; // Toa do select_box

    int xcu = xp;
    int ycu = yp; // Toa do select_box cu

    bool kt = true;
    bool kt_ENTER = false;
    bool control_menu_main = true;
    while (true)
    {
        if (kt == true && control_menu_main == true)
        {
            gotoXY(xcu, ycu);
            select_box_KH(xcu, ycu, x, y, 14);
            xcu = xp;
            ycu = yp;
            select_box_KH(xp, yp, x, y, b_color_hl);
            kt = false;
        }
        // Dieu khien
        char c = _getch();
        if (_kbhit())
        {
            if (c == -32)
            {
                kt = true;
                c = _getch();
                if (c == 72 && yp != y)
                {
                    yp -= 2;
                }
                else if (c == 80 && yp != y + h * (n_cot - 1))
                {
                    yp += 2;
                }
            }
        }
        else if (c == 13)
        {
            kt_ENTER = !kt_ENTER;
            if (kt_ENTER)
            {
                textcolor(15);
                system("cls");
                select_menu_KH(yp, y);
                kt_ENTER = !kt_ENTER;
                control_menu_main = false;
            }
        }
        else if (c == 27)
        {
            textcolor(15);
            system("cls");
            menu_main();
        }
    }

}
void chonhang()
{
    menu_KH_oder();
    ShowCur(0);
    int x = 5;
    int y = 10;
    int h = 3;
    int w = 20;
    int t_color = 15;
    int b_color_hl = 118;
    int n_cot = 3;
    int n_hang = 3;
    int stt = 0;
    int vitri[9];

    int xp = x;
    int yp = y; // Toa do select_box

    int xcu = xp;
    int ycu = yp; // Toa do select_box cu

    bool kt = true;
    bool kt_ENTER = false;
    bool control_menu_main = true;
    while (true)
    {
        if (kt == true && control_menu_main == true)
        {
            gotoXY(xcu, ycu);
            select_menu_KH_oder(xcu, ycu, x, y, 14);

            xcu = xp;
            ycu = yp;

            select_menu_KH_oder(xp, yp, x, y, b_color_hl);
            kt = false;
        }
        // Dieu khien
        /*  Mui t�n sang tr�i: 75
            Mui t�n sang ph?i: 77*/
        char c = _getch();
        if (_kbhit())
        {
            if (c == -32)
            {
                kt = true;
                c = _getch();
                if (c == 72 && yp != y) // Len
                {
                    yp -= 6;
                }
                else if (c == 80 && yp != y + h * (n_cot + 1)) // Xuong
                {
                    yp += 6;
                }
                else if (c == 75 && xp != x) // Trai
                {
                    xp -= 25;
                }
                else if (c == 77 && xp != 55) // xp != xMax -> Phai
                {
                    xp += 25;
                }
            }
        }
        else if (c == 13)
        {
            kt_ENTER = !kt_ENTER;
            if (kt_ENTER)
            {
                sttKH++;
                select_object(xp, yp, x, y);
                kt_ENTER = !kt_ENTER;
                control_menu_main = false;
            }
        }
        else if (c == 27)
        {
            textcolor(15);
            system("cls");
            menu_KH();
        }
    }

    // select_menu_KH_oder();
}
void select_box_KH(int xp, int yp, int x, int y, int b_color_hl)
{
    textcolor(b_color_hl);
    gotoXY(xp + 1, yp + 1);
    if (yp == y)
    {
        printf("                 Chon Hang                 ");
    }
    else if (yp == y + 2)
    {
        printf("            Loai bo mot mat hang           ");
    }
}
void select_menu_KH(int yp, int y)
{

    
    menu_SanPham();
    if (yp == y)
    {
        khoiTaoGioHang();
        textcolor(15);
        system("cls");
        chonhang();
    }
    else if ((yp == y + 2))
    {
        // xoamotmathang);
    }
 
}
void select_menu_KH_oder(int xp, int yp, int x, int y, int b_color_hl)
{
    textcolor(b_color_hl);
    gotoXY(xp + 1, yp + 1);
    if (xp == x && yp == y)
    {
        printf("  AMERICANO        ");
        gotoXY(xp + 1, yp + 2);
        printf("          Gia: 5$  ");
    }
    else if (xp == x + 25 && yp == y)
    {
        printf("  CAPPUCCINO       ");
        gotoXY(xp + 1, yp + 2);
        printf("          Gia: 5$  ");
    }
    else if (xp == x + 50 && yp == y)
    {
        printf("  MACCHIATO        ");
        gotoXY(xp + 1, yp + 2);
        printf("          Gia: 5$  ");
    }
    else if (xp == x && yp == y + 6)
    {
        printf("   Tra Dao         ");
        gotoXY(xp + 1, yp + 2);
        printf("          Gia: 4$  ");
    }
    else if (xp == x + 25 && yp == y + 6)
    {
        printf("   Tra Vai         ");
        gotoXY(xp + 1, yp + 2);
        printf("          Gia: 4$  ");
    }
    else if (xp == x + 50 && yp == y + 6)
    {
        printf("   Tra Buoi        ");
        gotoXY(xp + 1, yp + 2);
        printf("          Gia: 4$  ");
    }
    else if (xp == x && yp == y + 12)
    {
        printf("   Tiramisu        ");
        gotoXY(xp + 1, yp + 2);
        printf("          Gia: 2$  ");
    }
    else if (xp == x + 25 && yp == y + 12)
    {
        printf(" Mousse Cacao      ");
        gotoXY(xp + 1, yp + 2);
        printf("          Gia: 2$  ");
    }
    else if (xp == x + 50 && yp == y + 12)
    {
        printf(" Pho Mai Ca Phe    ");
        gotoXY(xp + 1, yp + 2);
        printf("          Gia: 2$  ");
    }
}
void select_object(int xp, int yp, int x, int y)
{
    ShowCur(0);

    for (int j = 0; j <= 12; j += 6)
    {

        for (int i = 0; i <= 50; i += 25)
        {
            if (xp == x + i && yp == y + j)
            {
                vitri_object[sttKH] = i / 25 + j / 2;
                xacnhanGH(x, y);
            }
        }
    }
}
void check( )
{
    int stt = danhsachKH[sttKH].soluongSP;
    int found = 0;
    for (int i = 1; i < stt; i++) {
        if (strcmp(danhsachKH[sttKH].GH[stt].ten, danhsachKH[sttKH].GH[i].ten) == 0) {
            // Nếu sản phẩm đã tồn tại, tăng số lượng lên
            danhsachKH[sttKH].GH[i].soluong += 1;
            danhsachKH[sttKH].soluongSP--;

            found = 1;
            break;
        }
    }
    if (!found)
    {
        strcpy(danhsachKH[sttKH].GH[stt].ten, sanphamCuaHang[vitri_object[sttKH]].ten);
        danhsachKH[sttKH].GH[stt].gia = sanphamCuaHang[vitri_object[sttKH]].gia;
        danhsachKH[sttKH].GH[stt].soluong = 1;
    }
}
void xacnhanGH(int x, int y)
{
    check();
    int stt = danhsachKH[sttKH].soluongSP;

    for (int i = 1; i <= stt; i++)
    {
        gotoXY(81, 11 + i);
        centerText(danhsachKH[sttKH].GH[i].ten, 14);
        gotoXY(81 + 14, 11 + i);
        printf("       %d         %d$", danhsachKH[sttKH].GH[i].soluong, danhsachKH[sttKH].GH[i].gia);
    }
    gotoXY(111, 26);
    printf("%d $", tinhGH(sttKH));
    chonhang();
}
void centerText(char* str, int length) {
    int str_len = strlen(str);
    int padlen = (length - str_len) / 2;
    for (int i = 0; i < padlen; i++) {
        printf(" ");
    }
    printf("%s", str);
    for (int i = 0; i < (length - str_len - padlen); i++) {
        printf(" ");
    }
}
void xoamotmathang()
{
    int y;
    int stt = danhsachKH[sttKH].soluongSP;
    if (stt == 0)
    {
        printf("Ban chua co san pham trong gio hang!");
        Sleep(2000);
    }

    else
    {
        printf("Ban can loai bo san pham thu may? ");
        cin >> y;
        while (y < 1 || y > stt)
        {
            printf("Loi!\nVui long chon lai thu tu san pham: ");
            cin >> y;
        }
        for (int i = y; i < stt; i++)
        {
            danhsachKH[sttKH].GH[i - 1] = danhsachKH[sttKH].GH[i]; 
        }
        danhsachKH[sttKH].soluongSP--;
        printf("Ban da xoa mat hang thu %d!", y);
    }

    // Ham quay lai menu_KH
    system("cls");
    menu_KH();
}
void khoiTaoGioHang() {
    danhsachKH[sttKH].soluongSP = 0; // Khởi tạo số lượng sản phẩm trong giỏ hàng = 0
    for (int i = 0; i < MAX_ITEMS; i++) {
        strcpy(danhsachKH[sttKH].GH[i].ten, " ");
        danhsachKH[sttKH].GH[i].soluong = 0; // Khởi tạo số lượng sản phẩm trong giỏ hàng là 0
        danhsachKH[sttKH].GH[i].gia = 0; // Khởi tạo giá tiền của sản phẩm trong giỏ hàng là 0
    }
    printf("Nhap Ten Khach Hang: ");
    gets_s(danhsachKH[sttKH].ten);
    printf("Nhap Tuoi Khach Hang: ");
    scanf("%d", &danhsachKH[sttKH].tuoi);
}