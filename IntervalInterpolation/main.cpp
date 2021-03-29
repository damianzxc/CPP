#include <iostream>
#include <iomanip>

using namespace std;

struct Point {
    double x;
    double y;
};

void getThreeElArr(Point *arr, double x, int n, Point *newArr) {

    if(x<arr[1].x) {
        newArr[0] = arr[0];
        newArr[1] = arr[1];
        newArr[2] = arr[2];
    }

    else if(x>arr[n-1].x) {
        newArr[0] = arr[n-2];
        newArr[1] = arr[n-1];
        newArr[2] = arr[n];
    }
    else {
        for(int i=1; i<(n-1); i++) {
            if(x>arr[i].x) {
                newArr[0] = arr[i];
                newArr[1] = arr[i+1];
                if((x - newArr[0].x) < 0.5) {
                    newArr[2] = arr[i-1];
                }
                else {
                    newArr[2] = arr[i+2];
                }
            }
        }

    }

}

void getFiveElArr(Point *arr, double x, int n, Point *newArr) {

    if(x<arr[2].x) {
        newArr[0] = arr[0];
        newArr[1] = arr[1];
        newArr[2] = arr[2];
        newArr[3] = arr[3];
        newArr[4] = arr[4];
    }

    else if(x>arr[n-2].x) {
        newArr[0] = arr[n-4];
        newArr[1] = arr[n-3];
        newArr[2] = arr[n-2];
        newArr[3] = arr[n-1];
        newArr[4] = arr[n];
    }
    else {
        for(int i=2; i<(n-2); i++) {
            if(x>arr[i].x) {
                newArr[0] = arr[i-1];
                newArr[1] = arr[i];
                newArr[2] = arr[i+1];
                newArr[3] = arr[i+2];
                if((x - newArr[0].x) < 0.5) {
                    newArr[4] = arr[i-2];
                }
                else {
                    newArr[4] = arr[i+3];
                }
            }
        }

    }

}


double lagrangeInterpolation(Point *arr, double x, int numberOfPoints) {
    double y = 0;

    for(int k = 0; k < numberOfPoints; k++) {
        double tmp = 1;
        for (int i = 0; i < numberOfPoints; i++) {
            if (i != k)
                tmp = tmp * ((x - arr[i].x) / (arr[k].x - arr[i].x));
        }
        y += tmp * arr[k].y;
    }
    return y;
}

int main() {

    int n = 23; //number of points
    Point *arr =  new Point[n];
    arr[0].x = 1.0;
    arr[0].y = 0.1;
    arr[1].x = 2.0;
    arr[1].y = 0.11;
    arr[2].x = 3.0;
    arr[2].y = 0.9;
    arr[3].x = 4.0;
    arr[3].y = 0.12;
    arr[4].x = 5.0;
    arr[4].y = 0.42;
    arr[5].x = 6.0;
    arr[5].y = 0.1;
    arr[6].x = 7.0;
    arr[6].y = 1.02;
    arr[7].x = 8.0;
    arr[7].y = 4.0;
    arr[8].x = 9.0;
    arr[8].y = 5.27;
    arr[9].x = 10.0;
    arr[9].y = 4.09;
    arr[10].x = 11.0;
    arr[10].y = 8.0;
    arr[11].x = 12.0;
    arr[11].y = 8.0;
    arr[12].x = 13.0;
    arr[12].y = 3.2;
    arr[13].x = 14.0;
    arr[13].y = 8.0;
    arr[14].x = 15.0;
    arr[14].y = 6.5;
    arr[15].x = 16.0;
    arr[15].y = 1.2;
    arr[16].x = 17.0;
    arr[16].y = 1.9;
    arr[17].x = 18.0;
    arr[17].y = 0.9;
    arr[18].x = 19.0;
    arr[18].y = 1.1;
    arr[19].x = 20.0;
    arr[19].y = 0.25;
    arr[20].x = 21.0;
    arr[20].y = 0.2;
    arr[21].x = 22.0;
    arr[21].y = 0.19;
    arr[22].x = 23.0;
    arr[22].y = 0.2;

    int hour;
    int minute;
    cout << "Podaj godzinę: " ;
    cin >> hour;
    cout << "Podaj minutę: " ;
    cin >> minute;
    double timeToCheck = hour + minute/60.0;
    cout << "o godzinie " << hour << ":" << minute << " wykorzystywano: " << endl;
    Point *newArr3 = new Point[3];
    Point *newArr5 = new Point[5];
    getThreeElArr(arr, timeToCheck, n, newArr3);
    getFiveElArr(arr, timeToCheck, n, newArr5);
    cout << setprecision(2) << lagrangeInterpolation(newArr3, timeToCheck, 3) << " Mb/s (wielomian st. 2)" << endl;
    cout << setprecision(2) << lagrangeInterpolation(newArr5, timeToCheck, 5) << " Mb/s (wielomian st. 4)" << endl;
    delete arr;
    delete newArr3;
    delete newArr5;
    return 0;
}
