long long int fun(long long int a) {
    long long int i, s = 0, r;
    for (i = a; i != 0; i /= 10) {
        r = i % 10;
        s = s + (r * r);
    }
    return s;
}
int main() {
    long long int k, n, m, fn[1000] = {
        0
    }, an[1000] = {
        0
    }, am[1000] = {
        0
    }, fm[1000] = {
        0
    }, c, d, j, i, sum, f;
    long long unsigned int min, p, q, x, y;
    while (scanf("%lld %lld", & n, & m) == 2) {
        if (n == 0 && m == 0) {
            break;
        }
        p = 0;
        q = 0;
        c = n;
        d = m;
        x = 0;
        y = 0;
        f = 0;
        min = -1;
        for (i = 0; i < 1000; i++) {
            fn[i] = 0;
            fm[i] = 0;
            an[i] = 0;
            am[i] = 0;
        }
        if (n == m) printf("%lld %lld %lld\n", n, m, 2);
        else {
            if (n == 1) {
                fn[n] = 1;
                an[n]++;
                p = 1;
            } else {
                if (n > 999) {
                    x = 1;
                } else {
                    fn[n] = 1;
                    an[n]++;
                    p = 1;
                }
                for (;;) {
                    k = fun(c);
                    an[k]++;
                    if (k == 1) {
                        p++;
                        fn[k] = p;
                        break;
                    } else if (an[k] > 1) {
                        an[k] = 1;
                        break;
                    } else {
                        p++;
                        fn[k] = p;
                    }
                    c = k;
                }
            }
            if (m == 1) {
                fm[m] = 1;
                am[m]++;
                q = 1;
            } else {
                if (m > 999) {
                    y = 1;
                } else {
                    fm[m] = 1;
                    am[m]++;
                    q = 1;
                }
                for (;;) {
                    j = fun(d);
                    am[j]++;
                    if (j == 1) {
                        q++;
                        fm[j] = q;
                        break;
                    } else if (am[j] > 1) {
                        am[j] = 1;
                        break;
                    } else {
                        q++;
                        fm[j] = q;
                    }
                    d = j;
                }
            }
            for (i = 1; i < 1000; i++) {
                if (an[i] & am[i]) {
                    f = 1;
                    sum = fn[i] + fm[i];
                    if (sum < min) {
                        min = sum;
                    }
                }
            }
            if (f == 1)
                printf("%lld %lld %lld\n", n, m, min + x + y);
            else printf("%lld %lld 0\n", n, m);
        }
    }
    return 0;
}
