#include <iostream>

const int INSIDE = 0;
const int LEFT = 1;
const int RIGHT = 2;
const int BOTTOM = 4;
const int TOP = 8;

int computeOutCode(double x, double y, double xmin, double ymin, double xmax, double ymax) {
    int code = INSIDE;
    if (x < xmin) code |= LEFT;
    if (x > xmax) code |= RIGHT;
    if (y < ymin) code |= BOTTOM;
    if (y > ymax) code |= TOP;
    return code;
}

bool clipLine(double& x0, double& y0, double& x1, double& y1, double xmin, double ymin, double xmax, double ymax) {
    int outcode0 = computeOutCode(x0, y0, xmin, ymin, xmax, ymax);
    int outcode1 = computeOutCode(x1, y1, xmin, ymin, xmax, ymax);
    bool accept = false;

    while (true) {
        if (!(outcode0 | outcode1)) {
            accept = true;
            break;
        } else if (outcode0 & outcode1) {
            break;
        } else {
            double x, y;
            int outcodeOut = outcode0 ? outcode0 : outcode1;
            if (outcodeOut & TOP) {
                x = x0 + (x1 - x0) * (ymax - y0) / (y1 - y0);
                y = ymax;
            } else if (outcodeOut & BOTTOM) {
                x = x0 + (x1 - x0) * (ymin - y0) / (y1 - y0);
                y = ymin;
            } else if (outcodeOut & RIGHT) {
                y = y0 + (y1 - y0) * (xmax - x0) / (x1 - x0);
                x = xmax;
            } else { // outcodeOut & LEFT
                y = y0 + (y1 - y0) * (xmin - x0) / (x1 - x0);
                x = xmin;
            }
            if (outcodeOut == outcode0) {
                x0 = x;
                y0 = y;
                outcode0 = computeOutCode(x0, y0, xmin, ymin, xmax, ymax);
            } else {
                x1 = x;
                y1 = y;
                outcode1 = computeOutCode(x1, y1, xmin, ymin, xmax, ymax);
            }
        }
    }
    return accept;
}

int main() {
    using namespace std;

    double x0, y0, x1, y1, xmin, ymin, xmax, ymax;

    cout << "Masukkan titik x0: ";
    cin >> x0;
    cout << "Masukkan titik y0: ";
    cin >> y0;
    cout << "Masukkan titik x1: ";
    cin >> x1;
    cout << "Masukkan titik y1: ";
    cin >> y1;

    cout << "Masukkan batas xmin: ";
    cin >> xmin;
    cout << "Masukkan batas ymin: ";
    cin >> ymin;
    cout << "Masukkan batas xmax: ";
    cin >> xmax;
    cout << "Masukkan batas ymax: ";
    cin >> ymax;

    if (clipLine(x0, y0, x1, y1, xmin, ymin, xmax, ymax)) {
        cout << "Titik potong adalah (" << x0 << ", " << y0 << ") dan (" << x1 << ", " << y1 << ")\n";
    } else {
        cout << "Garis tidak terpotong\n";
    }

    return 0;
}
