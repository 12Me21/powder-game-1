/*
 * Decompiled with CFR 0.151.
 */
/*
 * Exception performing whole class analysis ignored.
 */
final class e {
    private final dust c;
    float a;
    float b;

    e(dust dust2) {
        this.c = dust2;
        this.c = dust2;
        this.a = 0.0f;
        this.b = 0.0f;
    }

    e(dust dust2, float f, float f2) {
        this.c = dust2;
        this.c = dust2;
        this.a = f;
        this.b = f2;
    }

    e(dust dust2, e e2) {
        this.c = dust2;
        this.c = dust2;
        this.a = e2.a;
        this.b = e2.b;
    }

    final e a(float f, float f2) {
        this.a = f;
        this.b = f2;
        return this;
    }

    final e a(e e2) {
        this.a = e2.a;
        this.b = e2.b;
        return this;
    }

    final e b(e e2) {
        this.a += e2.a;
        this.b += e2.b;
        return this;
    }

    final e c(e e2) {
        this.a -= e2.a;
        this.b -= e2.b;
        return this;
    }

    final e a(e e2, e e3) {
        this.a = e2.a - e3.a;
        this.b = e2.b - e3.b;
        return this;
    }

    final e a(float f) {
        this.a *= f;
        this.b *= f;
        return this;
    }

    final e a(e e2, float f) {
        this.a = e2.a * f;
        this.b = e2.b * f;
        return this;
    }

    final e b(float f) {
        this.a /= f;
        this.b /= f;
        return this;
    }

    final float d(e e2) {
        return this.a * e2.a + this.b * e2.b;
    }

    final float a() {
        return dust.a(this.a, this.b);
    }

    final float b() {
        return this.a * this.a + this.b * this.b;
    }

    final float c() {
        return dust.c(this.a * this.a + this.b * this.b);
    }

    final float d() {
        float f = dust.a(this.a, this.b);
        if (f == 0.0f) {
            return 0.0f;
        }
        this.a /= f;
        this.b /= f;
        return f;
    }

    final float e() {
        float f = dust.c(this.a * this.a + this.b * this.b);
        if (f == 0.0f) {
            return 0.0f;
        }
        this.a /= f;
        this.b /= f;
        return f;
    }

    final float f() {
        float f = (float)Math.acos(this.a / dust.c(this.a * this.a + this.b * this.b));
        if (this.b > 0.0f) {
            f = (float)Math.PI * 2 - f;
        }
        return f;
    }
}
