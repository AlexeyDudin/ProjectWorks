#include <cstdio>
#include <cmath>

int main()
{
    // 1. prompt user to enter coefficients
    std::puts("please enter a b and c for ax^2+bx + c = 0:");

	// 2. read coefficients for equation `ax + b = 0`
    int a = 0;
    int b = 0;
    int c = 0;
    std::scanf("%d %d %d", &a, &b, &c);

	// 3. solve equation `ax + b = 0`
    float discriminant = b * b - 4 * a * c;
    std::printf("Discriminant %f\n", discriminant);
    if (discriminant < 0)
        std::printf("no roots");
    else if (discriminant == 0)
        std::printf("solution: %f\n", (float)(-b / (2 * a)));
    else
    {
        std::printf("first solution: %f\n", ((b * (-1)) - std::sqrt(discriminant))/(2 * a));
        std::printf("first solution: %f\n", ((b * (-1)) + std::sqrt(discriminant))/(2 * a));
    }
}
