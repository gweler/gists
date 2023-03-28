#include <iostream>

using namespace std;

const int MAX = 1000;

int N = 13;
int centres[] = {82, 3, 91, 33, 48, 17, 33, 2, 86, 17, 59, 45, 99};
int radii[] = {24, 77, 36, 73, 55, 45, 23, 44, 52, 23, 53, 91, 24};
int intersections[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
int solution = 8;

bool circles_intersect(int c1, int r1, int c2, int r2) {
    int d = abs(c2 - c1);
    int upper = r1 + r2;
    int lower = max(r1, r2) - 1 * min(r1, r2); // can be done with abs

    if (d < upper && d > lower) {
        return true;
    } else {
        return false;
    }
}

void count_intersections() {
    for (int i = 0; i < N; i++) {
        intersections[i] = 0;
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (i != j && centres[i] != 0 && centres[j] != 0) {
                if (circles_intersect(centres[i], radii[i], centres[j], radii[j])) {
                    intersections[i]++;
                }
            }
        }
    }
}

int add_intersections() {
    int total_intersections = 0;
    for (int i = 0; i < N; i++) {
        total_intersections += intersections[i];
    }
    return total_intersections;
}

int main() {
    int most_intersections;
    int total_intersections;
    int numof_circles_removed = 0;
    int circle_with_most_intersections;

    /*
    for (int i = 0; i < MAX; i++) {
        centres[i] = 0;
        radii[i] = 0;
        intersections[i] = 0;
    }

    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> centres[i];
        cin >> radii[i];
    }
    */

    count_intersections();
    total_intersections = add_intersections();
    while (total_intersections > 0) {
        most_intersections = 0;
        for (int i = 0; i < N; i++) {
            if (intersections[i] > most_intersections) {
                most_intersections = intersections[i];
                circle_with_most_intersections = i;
            }
        }
        cout << "Removed circle: " << centres[circle_with_most_intersections] << ", " << radii[circle_with_most_intersections];
        cout << endl;
        centres[circle_with_most_intersections] = 0;
        numof_circles_removed++;
        count_intersections();
        total_intersections = add_intersections();
    }

    cout << numof_circles_removed;

    if (numof_circles_removed == solution) {
        cout << endl << "PASS" << endl;
    } else {
        cout << endl << "FAIL" << endl;
    }

    return 0;
}
