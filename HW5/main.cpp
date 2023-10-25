#include <iostream>
#include <cmath>
#include <GL/glut.h>

float startX, startY, endX, endY;

void setupTampilan(void) {
    glClearColor(1.0, 1.0, 1.0, 1.0);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(-20, 30, -20, 30);
}

void aturPixel(GLint x, GLint y) {
    glBegin(GL_POINTS);
    glVertex2i(x, y);
    glEnd();
    glFlush();
}

void translasi(GLint x0, GLint y0, GLint dx, GLint dy) {
    aturPixel(x0, y0);
    GLint xAkhir = x0 + dx;
    GLint yAkhir = y0 + dy;
    GLint xSementara = x0;
    GLint ySementara = y0;

    while (xSementara < xAkhir || ySementara < yAkhir) {
        if (xSementara < xAkhir) {
            xSementara++;
        } else if (ySementara < yAkhir) {
            ySementara++;
        }
        aturPixel(xSementara, ySementara);
    }
}

void skala(GLint x0, GLint y0, GLint sx, GLint sy) {
    aturPixel(x0, y0);
    GLint xAkhir = x0 * sx;
    GLint yAkhir = y0 * sy;
    GLint xSementara = x0;
    GLint ySementara = y0;

    while (xSementara < xAkhir || ySementara < yAkhir) {
        if (xSementara < xAkhir) {
            xSementara++;
        } else if (ySementara < yAkhir) {
            ySementara++;
        }
        aturPixel(xSementara, ySementara);
    }
}

void rotasi(GLint x0, GLint y0, GLint xp, GLint yp) {
    aturPixel(x0, y0);
    GLint x1 = -xp;
    GLint y1 = -yp;
    GLint xPivot = x0 - xp;
    GLint yPivot = y0 - yp;
    GLint x2 = (0 * xPivot) + (-1 * yPivot);
    GLint y2 = (1 * xPivot) + (0 * yPivot);
    GLint xAkhir, yAkhir;

    if (x1 < 0) {
        xAkhir = x2 + x1;
    } else if (x1 > 0) {
        xAkhir = x2 - x1;
    }
    if (y1 < 0) {
        yAkhir = y2 + y1;
    } else if (y1 > 0) {
        yAkhir = y2 - y1;
    }

    GLint xSementara = x0;
    GLint ySementara = y0;

    while (xSementara < xAkhir || ySementara < yAkhir) {
        if (xSementara < xAkhir) {
            xSementara++;
        } else if (ySementara < yAkhir) {
            ySementara++;
        }
        aturPixel(xSementara, ySementara);
    }

    while (xSementara > xAkhir || ySementara > yAkhir) {
        if (xSementara > xAkhir) {
            xSementara--;
        } else if (ySementara > yAkhir) {
            ySementara--;
        }
        aturPixel(xSementara, ySementara);
    }
}

void tampilkanTranslasi(void) {
    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(0.0, 0.0, 0.0);
    glPointSize(2.0);
    translasi(startX, startY, endX, endY);
}

void tampilkanSkala(void) {
    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(0.0, 0.0, 0.0);
    glPointSize(2.0);
    skala(startX, startY, endX, endY);
}

void tampilkanRotasi(void) {
    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(0.0, 0.0, 0.0);
    glPointSize(2.0);
    rotasi(startX, startY, endX, endY);
}

int main(int argc, char** argv) {
    int pilihan;
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(0, 0);
    glutCreateWindow("Transformasi 2D");
    setupTampilan();

    std::cout << "1. Translasi\n2. Skala\n3. Rotasi\nPilih transformasi yang ingin di gunakan: ";
    std::cin >> pilihan;
    switch(pilihan) {
        case 1:
            std::cout << "Masukkan koordinat titik awal (x0 y0): ";
            std::cin >> startX >> startY;
            std::cout << "Masukkan jarak translasi (dx dy): ";
            std::cin >> endX >> endY;
            glutDisplayFunc(tampilkanTranslasi);
            glutMainLoop();
            break;
        case 2:
            std::cout << "Masukkan koordinat titik awal (x0 y0): ";
            std::cin >> startX >> startY;
            std::cout << "Masukkan faktor skala (sx sy): ";
            std::cin >> endX >> endY;
            glutDisplayFunc(tampilkanSkala);
            glutMainLoop();
            break;
        case 3:
            std::cout << "Masukkan koordinat titik awal (x0 y0): ";
            std::cin >> startX >> startY;
            std::cout << "Masukkan titik pivot rotasi (xp yp): ";
            std::cin >> endX >> endY;
            glutDisplayFunc(tampilkanRotasi);
            glutMainLoop();
            break;
        default:
            std::cout << "Pilihan tidak valid.\n";
            return 1;
    }
    return 0;
}
