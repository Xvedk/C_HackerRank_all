double calculate_area(const struct triangle* tr) {
    double s = (tr->a + tr->b + tr->c) / 2.0;
    return sqrt(s * (s - tr->a) * (s - tr->b) * (s - tr->c));
}

// Compare function for qsort to sort triangles by area
int compare(const void* a, const void* b) {
    const struct triangle* triangleA = (struct triangle*)a;
    const struct triangle* triangleB = (struct triangle*)b;
    double areaA = calculate_area(triangleA);
    double areaB = calculate_area(triangleB);

    if (areaA < areaB) {
        return -1;
    } else if (areaA > areaB) {
        return 1;
    } else {
        return 0;
    }
}

void sort_by_area(struct triangle* tr, int n) {
    // Sort triangles by area using qsort
    qsort(tr, n, sizeof(struct triangle), compare);
}
