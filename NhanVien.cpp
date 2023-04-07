#include "header.h"

void menu_NV()
{



    ShowCur(0);
    int x = 38;
    int y = 5;
    int w_box = 44;
    int h_box = 6;
    int h = 2;
    int t_color = 15;
    int b_color_hl = 118;
    int n_cot = 3;
    gotoXY(50, 3);
    textcolor(6);
    box(50, 1, 20, 2, 6);
    gotoXY(51, 2);
    SetColor(15);
    printf("    Nhan Vien    ");

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
    printf("               Xem nhan vien               ");
     

    gotoXY(48, 7);
    for (int i = 10; i < 34; i++)
    {
        SetColor(t_color);
        printf("%c", char(196));
    }
    gotoXY(x + 1, y + 3);
    textcolor(14);
    printf("            Them nhan vien moi             ");
    gotoXY(48, 9);
    for (int i = 10; i < 34; i++)
    {
        SetColor(t_color);
        printf("%c", char(196));
    }
    gotoXY(x + 1, y + 5);
    textcolor(14);
    printf("            Xoa mot nhan vien              ");

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
             select_box_NV(xcu, ycu, x, y, 14);

            xcu = xp;
            ycu = yp;

            select_box_NV(xp, yp, x, y, b_color_hl);
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
                else if (c == 80 && yp != y + h*(n_cot - 1)) 
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
                select_menu_NV(yp, y);
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
void select_box_NV(int xp, int yp, int x, int y, int b_color_hl)
{
    textcolor(b_color_hl);
    gotoXY(xp + 1, yp + 1);
    if (yp == y)
    {
        printf("          Xem danh sach nha vien           ");
    }
    else if (yp == y + 2)
    {
        printf("            Them nhan vien moi             ");
    }
    else if (yp == y + 4)
    {
        printf("            Xoa mot nhan vien              ");
    }
}
void select_menu_NV(int yp, int y)
{
    if (yp == y)
    {
        textcolor(15);
        system("cls");
    }
    else if ((yp == y + 2))
    {
        textcolor(15);
        system("cls");
    }
}

