/*
 * Decompiled with CFR 0.151.
 */
/*
 * Exception performing whole class analysis ignored.
 */
final class a {
    private final dust m;
    b a;
    int b;
    int c;
    int d;
    int e;
    int f;
    float g;
    int h;
    int i;
    int j;
    float k;
    int l;

    final void a(String string, int n, int n2) {
        this.a.a(string);
        this.b = n;
        this.c = n2;
        this.f = 255;
        this.e = 255;
        this.d = 255;
        this.g = 0.0f;
        this.j = 0;
        this.i = 0;
        this.h = 0;
        this.k = 0.0f;
        this.l = 0;
    }

    final void a(int n, int n2, int n3, int n4) {
        this.g = (float)n4 / 255.0f;
        this.d = (int)((float)n * this.g);
        this.e = (int)((float)n2 * this.g);
        this.f = (int)((float)n3 * this.g);
        this.g = 1.0f - this.g;
    }

    final void b(int n, int n2, int n3, int n4) {
        this.k = (float)n4 / 255.0f;
        this.h = (int)((float)n * this.k);
        this.i = (int)((float)n2 * this.k);
        this.j = (int)((float)n3 * this.k);
        this.k = 1.0f - this.k;
    }

    final void a(int n, int n2, String string) {
        int n3 = string.length();
        int n4 = 0;
        while (n4 < n3) {
            block5: {
                int n5 = (string.charAt(n4) - 32) * this.b;
                int n6 = n2 * this.m.a + n;
                if (n5 == 0) break block5;
                int n7 = 0;
                while (n7 < this.c) {
                    int n8 = 0;
                    while (n8 < this.b) {
                        block6: {
                            float f;
                            float f2;
                            int n9;
                            int n10;
                            block8: {
                                int n11;
                                int[] nArray;
                                int n12;
                                block7: {
                                    n12 = this.a.f[n5];
                                    if (n12 == 0) break block6;
                                    if (n12 != -1) break block7;
                                    n12 = this.m.ar[n6];
                                    nArray = this.m.ar;
                                    n11 = n6;
                                    n10 = 0xFF000000 | this.d + (int)((float)(n12 >> 16 & 0xFF) * this.g) << 16 | this.e + (int)((float)(n12 >> 8 & 0xFF) * this.g) << 8;
                                    n9 = this.f;
                                    f2 = n12 & 0xFF;
                                    f = this.g;
                                    break block8;
                                }
                                if (n12 != -16777216) break block6;
                                n12 = this.m.ar[n6];
                                nArray = this.m.ar;
                                n11 = n6;
                                n10 = 0xFF000000 | this.h + (int)((float)(n12 >> 16 & 0xFF) * this.k) << 16 | this.i + (int)((float)(n12 >> 8 & 0xFF) * this.k) << 8;
                                n9 = this.j;
                                f2 = n12 & 0xFF;
                                f = this.k;
                            }
                            nArray[n11] = n10 | n9 + (int)(f2 * f);
                        }
                        ++n8;
                        ++n6;
                        ++n5;
                    }
                    ++n7;
                    n6 += this.m.a - this.b;
                    n5 += this.a.b - this.b;
                }
            }
            ++n4;
            n += this.b + this.l;
        }
    }

    private void b(int n, int n2, String string) {
        this.a(n -= string.length() * this.b / 2, n2 -= this.c / 2, string);
    }

    final void a(int n, int n2, String string, int n3, int n4, int n5, int n6, int n7, int n8, int n9, int n10) {
        this.a(n3, n4, n5, n6);
        this.b(n7, n8, n9, n10);
        this.a(n, n2, string);
    }

    final void b(int n, int n2, String string, int n3, int n4, int n5, int n6, int n7, int n8, int n9, int n10) {
        this.a(n3, n4, n5, n6);
        this.b(n7, n8, n9, n10);
        this.b(n, n2, string);
    }

    a(dust dust2) {
        this.m = dust2;
        this.m = dust2;
        this.a = new b(this.m);
    }
}
