double factorial(int n)
{
    double num = 1;
    for(int i = 2; i <= n; i++)
        num *= i;
    return num;
}

int uniquePaths(int m, int n)
{
    int steps = m + n - 2;
    double ans = 1;
    for(int i = m; i <= steps; i++)
        ans *= i;
    ans /= factorial(n-1);
    return (int)ans;
}
