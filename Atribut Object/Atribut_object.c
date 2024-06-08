#include <graphics.h>
#include <conio.h>
#include <stdio.h>

int main() {
    int gd = DETECT, gm;
    int x1, y1, x2, y2; // Koordinat titik awal dan akhir garis
    int lineType = 0; // Tipe garis (0: Solid, 1: Dash, 2: Dot)
    int lineWidth = 1; // Lebar garis
    int lineColor = WHITE; // Warna garis, default putih
    char c;

    initgraph(&gd, &gm, ""); // Inisialisasi mode grafis

    // Menggambar sumbu x dan y
    line(0, getmaxy() / 2, getmaxx(), getmaxy() / 2); // X-axis
    line(getmaxx() / 2, 0, getmaxx() / 2, getmaxy()); // Y-axis

    printf("Pilih titik awal (x1, y1): ");
    scanf("%d %d", &x1, &y1);

    printf("Pilih titik akhir (x2, y2): ");
    scanf("%d %d", &x2, &y2);

    while (1) {
        // Memilih jenis pen (style) garis berdasarkan tipe yang dipilih
        switch (lineType) {
            case 0: setlinestyle(SOLID_LINE, 0, 1); break;
            case 1: setlinestyle(DASHED_LINE, 0, 1); break;
            case 2: setlinestyle(DOTTED_LINE, 0, 1); break;
        }

        setcolor(lineColor); // Mengatur warna garis
        setlinewidth(lineWidth); // Mengatur lebar garis

        // Menggambar garis dari titik (x1, y1) ke titik (x2, y2)
        line(x1 + getmaxx() / 2, getmaxy() / 2 - y1, x2 + getmaxx() / 2, getmaxy() / 2 - y2);

        printf("\nTekan 's' untuk solid, 'd' untuk dash, 't' untuk dot, 'c' untuk mengubah warna, 'l' untuk mengubah lebar garis, 'q' untuk keluar: ");
        scanf(" %c", &c);

        switch (c) {
            case 's': lineType = 0; break;
            case 'd': lineType = 1; break;
            case 't': lineType = 2; break;
            case 'c': printf("\nMasukkan kode warna (misalnya: 1 untuk BLUE, 2 untuk GREEN, dst.): ");
                      scanf("%d", &lineColor);
                      break;
            case 'l': printf("\nMasukkan lebar garis: ");
                      scanf("%d", &lineWidth);
                      break;
            case 'q': closegraph(); // Menutup mode grafis
                      return 0;
        }
    }

    getch();
    closegraph(); // Menutup mode grafis
    return 0;
}