/*
 * Decompiled with CFR 0.151.
 */
/*
 * Exception performing whole class analysis ignored.
 */
final class d {
    private final dust aR;
    int a;
    int b;
    int c;
    int d;
    e[] e;
    e[] f;
    float[] g;
    float[] h;
    float i;
    int[] j;
    int[] k;
    int[] l;
    int m;
    int n;
    int o;
    int p;
    e q;
    int[] r;
    int[] s;
    int[] t;
    int[] u;
    int[][] v;
    int[] w;
    int[] x;
    e[] y;
    e[] z;
    int[] A;
    int[] B;
    byte[] C;
    int D;
    int E;
    int[] F;
    int[] G;
    boolean[] H;
    int[] I;
    int[] J;
    int[] K;
    int[] L;
    float[] M;
    float[] N;
    int[] O;
    int[] P;
    b Q;
    int[] R;
    int[] S;
    float[] T;
    float[] U;
    int V;
    int W;
    int[] X;
    float[] Y;
    float[] Z;
    int aa;
    float[] ab;
    float[] ac;
    int[] ad;
    int ae;
    int af;
    int ag;
    int ah;
    float ai;
    int[] aj;
    e[] ak;
    e[] al;
    int[] am;
    e[] an;
    int[] ao;
    int[] ap;
    int[] aq;
    int[] ar;
    int[] as;
    int at;
    int au;
    int av;
    float[] aw;
    int[] ax;
    int[] ay;
    int[] az;
    int[] aA;
    e[] aB;
    e[] aC;
    int[] aD;
    int[] aE;
    int[] aF;
    int[] aG;
    int aH;
    int aI;
    int[] aJ;
    float[] aK;
    float[] aL;
    int[] aM;
    int[] aN;
    float[] aO;
    float[] aP;
    int[] aQ;

    final void a() {
        int n;
        int n2;
        int n3 = 0;
        while (n3 < 120000) {
            this.aR.X[n3] = 0;
            this.aR.Y[n3] = 0;
            ++n3;
        }
        int n4 = 0;
        while (n4 < 300) {
            n2 = 0;
            while (n2 < 400) {
                n = ((n4 >> 2) + 2) * this.a + ((n2 >> 2) + 2);
                if (this.l[n] == 1) {
                    this.aR.X[n4 * 400 + n2] = 1;
                }
                ++n2;
            }
            ++n4;
        }
        n3 = 0;
        while (n3 < this.D) {
            block16: {
                int n5;
                block18: {
                    int n6;
                    byte[] byArray;
                    block17: {
                        n2 = (int)this.y[n3].a;
                        n4 = (int)this.y[n3].b;
                        if (n2 < 8 || n2 >= 408 || n4 < 8 || n4 >= 308) break block16;
                        n = (n4 -= 8) * 400 + (n2 -= 8);
                        this.aR.X[n] = (byte)this.A[n3];
                        if (this.A[n3] != 8) break block17;
                        byArray = this.aR.Y;
                        n6 = n;
                        n5 = dust.b((int)(64.0f * this.z[n3].f() / ((float)Math.PI * 2)), 0, 63);
                        break block18;
                    }
                    if (this.A[n3] != 15) break block16;
                    byArray = this.aR.Y;
                    n6 = n;
                    n5 = this.B[n3] % 100;
                }
                byArray[n6] = (byte)n5;
            }
            ++n3;
        }
        n3 = 0;
        while (n3 < this.V) {
            n = (this.S[n3] - 8) * 400 + (this.R[n3] - 8);
            this.aR.X[n] = 9;
            this.aR.Y[n] = 0;
            ++n3;
        }
        n3 = 0;
        while (n3 < this.at) {
            block20: {
                byte by;
                block21: {
                    int n7;
                    byte[] byArray;
                    block23: {
                        block22: {
                            block19: {
                                n = n3 * this.av;
                                if (this.ao[n3] != 10 && this.ao[n3] != 11) break block19;
                                n2 = (int)this.ak[n + 4].a;
                                n4 = (int)this.ak[n + 4].b;
                                if (n2 < 8 || this.aR.a - 8 <= n2 || n4 < 8 || n4 >= 308) break block20;
                                n2 = n2 >> 2 << 2;
                                n4 = n4 >> 2 << 2;
                                n = (n4 - 8) * 400 + (n2 - 8);
                                this.aR.X[n] = 18;
                                byArray = this.aR.Y;
                                n7 = n;
                                by = 0;
                                break block21;
                            }
                            if (this.ao[n3] != 20) break block22;
                            n2 = (int)this.ak[n].a;
                            n4 = (int)this.ak[n].b;
                            if (n2 < 8 || this.aR.a - 8 <= n2 || n4 < 8 || n4 >= 308) break block20;
                            n2 = n2 >> 2 << 2;
                            n4 = n4 >> 2 << 2;
                            n = (n4 - 8) * 400 + (n2 - 8);
                            this.aR.X[n] = 22;
                            byArray = this.aR.Y;
                            n7 = n;
                            by = (byte)this.ar[n3];
                            break block21;
                        }
                        if (this.ao[n3] != 30) break block23;
                        n2 = (int)this.ak[n + 4].a;
                        n4 = (int)this.ak[n + 4].b;
                        if (n2 < 8 || this.aR.a - 8 <= n2 || n4 < 8 || n4 >= 308) break block20;
                        n2 = n2 >> 2 << 2;
                        n4 = n4 >> 2 << 2;
                        n = (n4 - 8) * 400 + (n2 - 8);
                        this.aR.X[n] = 30;
                        byArray = this.aR.Y;
                        n7 = n;
                        by = (byte)this.ar[n3];
                        break block21;
                    }
                    if (this.ao[n3] != 40) break block20;
                    n2 = (int)this.ak[n].a;
                    n4 = (int)this.ak[n].b;
                    if (n2 < 8 || this.aR.a - 8 <= n2 || n4 < 8 || n4 >= 308) break block20;
                    n2 = n2 >> 2 << 2;
                    n4 = n4 >> 2 << 2;
                    n = (n4 - 8) * 400 + (n2 - 8);
                    this.aR.X[n] = 22;
                    byArray = this.aR.Y;
                    n7 = n;
                    by = (byte)10;
                }
                byArray[n7] = by;
            }
            ++n3;
        }
        n3 = 0;
        while (n3 < this.aH) {
            if (this.aD[n3] != 0) {
                n2 = (int)this.aB[n3].a;
                n4 = (int)this.aB[n3].b;
                if (n2 >= 8 && this.aR.a - 8 > n2 && n4 >= 8 && n4 < 308 && this.aR.X[n = (n4 - 8) * 400 + (n2 - 8)] == 0) {
                    this.aR.X[n] = 40;
                    this.aR.Y[n] = (byte)this.aG[n3];
                }
            }
            ++n3;
        }
        this.aR.aj = this.aR.ai;
    }

    /*
     * Unable to fully structure code
     */
    final void b() {
        var5_1 = new int[120000];
        var6_2 = 0;
        var9_3 = 120000;
        var1_4 = 0;
        while (var1_4 < var9_3) {
            block28: {
                block27: {
                    block26: {
                        var7_5 = this.aR.X[var1_4];
                        var8_6 = 1;
                        if (var7_5 != 8 && var7_5 != 15 && var7_5 != 22 && var7_5 != 40) break block26;
                        var5_1[var6_2++] = var7_5;
                        v0 = var5_1;
                        v1 = var6_2++;
                        v2 = this.aR.Y[var1_4];
                        break block27;
                    }
                    if (var7_5 != 30) ** GOTO lbl26
                    var5_1[var6_2++] = 32;
                    v0 = var5_1;
                    v1 = var6_2++;
                    v2 = this.aR.Y[var1_4];
                    break block27;
                    while (var7_5 == this.aR.X[var1_4 + 1]) {
                        if (++var8_6 == 255) {
                            ++var1_4;
                            break;
                        }
                        ++var1_4;
lbl26:
                        // 2 sources

                        if (var1_4 < var9_3 - 1) continue;
                    }
                    var5_1[var6_2++] = var7_5;
                    if (var8_6 == true) break block28;
                    if (var8_6 < 16) {
                        v0 = var5_1;
                        v1 = var6_2++;
                        v3 = 48;
                        v4 = var8_6;
                    } else {
                        var5_1[var6_2++] = 48 + (var8_6 & 15);
                        v0 = var5_1;
                        v1 = var6_2++;
                        v3 = 48;
                        v4 = var8_6 >> 4;
                    }
                    v2 = v3 + v4;
                }
                v0[v1] = v2;
            }
            ++var1_4;
        }
        var10_7 = new int[]{48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79, 80, 81, 82, 83, 84, 85, 86, 87, 88, 89, 90, 97, 98, 99, 100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119, 120, 121, 122, 46, 42};
        var11_8 = new char[var6_2 * 2];
        var12_9 = 0;
        ++var12_9;
        var11_8[0] = 49;
        ++var12_9;
        var11_8[1] = 48;
        var13_10 = new int[]{48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 65, 66, 67, 68, 69, 70};
        ++var12_9;
        var11_8[2] = (char)var13_10[this.aR.j + 1];
        ++var12_9;
        var11_8[3] = (char)(48 + this.aR.g);
        ++var12_9;
        var11_8[4] = (char)(48 + this.aR.v);
        ++var12_9;
        var11_8[5] = (char)(48 + this.aR.x);
        ++var12_9;
        var11_8[6] = (char)(48 + this.aR.y);
        ++var12_9;
        var11_8[7] = 48;
        ++var12_9;
        var11_8[8] = (char)var10_7[this.aR.aj & 63];
        ++var12_9;
        var11_8[9] = (char)var10_7[this.aR.aj >> 6];
        ++var12_9;
        var11_8[10] = 48;
        ++var12_9;
        var11_8[11] = 48;
        ++var12_9;
        var11_8[12] = 48;
        ++var12_9;
        var11_8[13] = 48;
        ++var12_9;
        var11_8[14] = 48;
        ++var12_9;
        var11_8[15] = 48;
        var14_11 = new int[4096][];
        var15_12 = 1;
        v5 = 0;
        while (v5 < var6_2) {
            var16_14 = 0;
            var17_16 = 1;
            var18_18 = 1;
            while (var18_18 < var15_12) {
                if (var14_11[var18_18].length == var17_16) {
                    var4_13 = 0;
                    while (var4_13 < var17_16) {
                        if (var14_11[var18_18][var4_13] != var5_1[var1_4 + var4_13]) break;
                        ++var4_13;
                    }
                    if (var4_13 == var17_16) {
                        var16_14 = var18_18;
                        if (var1_4 + ++var17_16 >= var6_2) break;
                    }
                }
                ++var18_18;
            }
            var11_8[var12_9++] = (char)var10_7[var16_14 >> 6];
            var11_8[var12_9++] = (char)var10_7[var16_14 & 63];
            var11_8[var12_9++] = (char)var10_7[var5_1[var1_4 + var17_16 - 1]];
            if (var15_12 < 4096) {
                var14_11[var15_12] = new int[var17_16];
                var4_13 = 0;
                while (var4_13 < var17_16) {
                    var14_11[var15_12][var4_13] = var5_1[var1_4 + var4_13];
                    ++var4_13;
                }
                ++var15_12;
            }
            v5 = var1_4 = var1_4 + var17_16;
        }
        this.aR.ac = new String(var11_8, 0, var12_9);
        var16_15 = new char[7500];
        var1_4 = 0;
        var3_20 = 0;
        while (var3_20 < 300) {
            var2_21 = 0;
            while (var2_21 < 400) {
                block29: {
                    block30: {
                        var4_13 = var3_20 * 400 + var2_21;
                        if (this.aR.X[var4_13] == 0) {
                            var4_13 += 401;
                        }
                        if (this.aR.j != 11) break block29;
                        if (this.aR.X[var4_13] != 4 && this.aR.X[var4_13] != 20 && this.aR.X[var4_13] != 25 && this.aR.X[var4_13] != 28 && this.aR.X[var4_13] != 33 && this.aR.X[var4_13] != 42) break block30;
                        v6 = var16_15;
                        ** GOTO lbl138
                    }
                    v6 = var16_15;
                    v7 = var1_4++;
                    v8 = (char)48;
                    ** GOTO lbl140
                }
                if (this.aR.j == 13) {
                    var16_15[var1_4++] = this.aR.X[var4_13] == 0 ? 48 : 49;
                } else {
                    v6 = var16_15;
lbl138:
                    // 2 sources

                    v7 = var1_4++;
                    v8 = (char)var10_7[this.aR.X[var4_13]];
lbl140:
                    // 2 sources

                    v6[v7] = v8;
                }
                var2_21 += 4;
            }
            var3_20 += 4;
        }
        this.aR.ad = new String(var16_15, 0, 7500);
        var17_17 = new char[]{'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'a', 'b', 'c', 'd', 'e', 'f'};
        if (this.aR.j == 9) {
            var18_19 = this.aR.S.w;
        } else if (this.aR.j == 13) {
            var18_19 = new int[]{-1, -16777216};
        } else {
            var18_19 = new int[this.aR.S.v.length];
            var1_4 = 0;
            while (var1_4 < this.aR.S.v.length) {
                var18_19[var1_4] = this.aR.S.v[var1_4][0];
                ++var1_4;
            }
        }
        this.aR.ae = "";
        var1_4 = 0;
        while (var1_4 < var18_19.length) {
            this.aR.ae = String.valueOf(this.aR.ae) + var17_17[var18_19[var1_4] >> 20 & 15];
            this.aR.ae = String.valueOf(this.aR.ae) + var17_17[var18_19[var1_4] >> 16 & 15];
            this.aR.ae = String.valueOf(this.aR.ae) + var17_17[var18_19[var1_4] >> 12 & 15];
            this.aR.ae = String.valueOf(this.aR.ae) + var17_17[var18_19[var1_4] >> 8 & 15];
            this.aR.ae = String.valueOf(this.aR.ae) + var17_17[var18_19[var1_4] >> 4 & 15];
            this.aR.ae = String.valueOf(this.aR.ae) + var17_17[var18_19[var1_4] & 15];
            ++var1_4;
        }
    }

    final void c() {
        int n;
        int n2;
        int n3;
        int n4;
        char[] cArray = new char[240000];
        int n5 = this.aR.ac.length();
        int[] nArray = new int[120000];
        int n6 = 0;
        int n7 = 0;
        while (n7 < this.aR.ac.length()) {
            cArray[n7] = this.aR.ac.charAt(n7);
            ++n7;
        }
        int[] nArray2 = new int[128];
        nArray2[42] = 63;
        nArray2[46] = 62;
        nArray2[49] = 1;
        nArray2[50] = 2;
        nArray2[51] = 3;
        nArray2[52] = 4;
        nArray2[53] = 5;
        nArray2[54] = 6;
        nArray2[55] = 7;
        nArray2[56] = 8;
        nArray2[57] = 9;
        nArray2[65] = 10;
        nArray2[66] = 11;
        nArray2[67] = 12;
        nArray2[68] = 13;
        nArray2[69] = 14;
        nArray2[70] = 15;
        nArray2[71] = 16;
        nArray2[72] = 17;
        nArray2[73] = 18;
        nArray2[74] = 19;
        nArray2[75] = 20;
        nArray2[76] = 21;
        nArray2[77] = 22;
        nArray2[78] = 23;
        nArray2[79] = 24;
        nArray2[80] = 25;
        nArray2[81] = 26;
        nArray2[82] = 27;
        nArray2[83] = 28;
        nArray2[84] = 29;
        nArray2[85] = 30;
        nArray2[86] = 31;
        nArray2[87] = 32;
        nArray2[88] = 33;
        nArray2[89] = 34;
        nArray2[90] = 35;
        nArray2[97] = 36;
        nArray2[98] = 37;
        nArray2[99] = 38;
        nArray2[100] = 39;
        nArray2[101] = 40;
        nArray2[102] = 41;
        nArray2[103] = 42;
        nArray2[104] = 43;
        nArray2[105] = 44;
        nArray2[106] = 45;
        nArray2[107] = 46;
        nArray2[108] = 47;
        nArray2[109] = 48;
        nArray2[110] = 49;
        nArray2[111] = 50;
        nArray2[112] = 51;
        nArray2[113] = 52;
        nArray2[114] = 53;
        nArray2[115] = 54;
        nArray2[116] = 55;
        nArray2[117] = 56;
        nArray2[118] = 57;
        nArray2[119] = 58;
        nArray2[120] = 59;
        nArray2[121] = 60;
        nArray2[122] = 61;
        int[] nArray3 = nArray2;
        int n8 = cArray[0] - 48;
        int[] nArray4 = new int[]{48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 65, 66, 67, 68, 69, 70};
        n7 = 0;
        while (n7 < nArray4.length) {
            if (cArray[2] == nArray4[n7]) break;
            ++n7;
        }
        this.aR.j = n7 - 1;
        if (this.aR.j == -1) {
            this.aR.j = 2;
        }
        this.aR.g = cArray[3] - 48;
        this.aR.v = cArray[4] - 48;
        this.aR.x = cArray[5] - 48;
        this.aR.y = cArray[6] - 48;
        if (n8 == 0) {
            this.aR.aj = 100;
        }
        if (n8 >= 1) {
            this.aR.aj = nArray3[cArray[8]];
            this.aR.aj += nArray3[cArray[9]] << 6;
        }
        int[][] nArray5 = new int[4096][];
        int n9 = 1;
        n7 = n8 == 0 ? 8 : 16;
        while (n7 < n5) {
            n4 = 1;
            n3 = nArray3[cArray[n7]] << 6;
            n3 += nArray3[cArray[++n7]];
            n2 = nArray3[cArray[++n7]];
            ++n7;
            if (n3 > 0) {
                n = 0;
                while (n < nArray5[n3].length) {
                    nArray[n6++] = nArray5[n3][n];
                    ++n;
                }
                n4 = 1 + nArray5[n3].length;
            }
            nArray[n6++] = n2;
            if (n9 >= 4096) continue;
            nArray5[n9] = new int[n4];
            n2 = 0;
            while (n2 < n4) {
                nArray5[n9][n2] = nArray[n6 - n4 + n2];
                ++n2;
            }
            ++n9;
        }
        nArray[n6++] = 0;
        nArray[n6] = 0;
        n2 = 0;
        n7 = 0;
        while (n2 < 120000) {
            if ((n3 = nArray[n7++]) == 8 || n3 == 15 || n3 == 22 || n3 == 40) {
                this.aR.X[n2] = (byte)n3;
                this.aR.Y[n2] = (byte)nArray[n7++];
                ++n2;
                continue;
            }
            if (n3 == 32) {
                this.aR.X[n2] = 30;
                this.aR.Y[n2] = (byte)nArray[n7++];
                ++n2;
                continue;
            }
            if (nArray[n7] < 48) {
                this.aR.X[n2] = (byte)n3;
                ++n2;
                continue;
            }
            if (nArray[n7 + 1] < 48) {
                n4 = nArray[n7++] - 48;
                n = 0;
                while (n < n4) {
                    this.aR.X[n2++] = (byte)n3;
                    ++n;
                }
                continue;
            }
            n4 = nArray[n7++] - 48;
            int n10 = n7++;
            n = 0;
            while (n < (n4 += nArray[n10] - 48 << 4)) {
                this.aR.X[n2++] = (byte)n3;
                ++n;
            }
        }
    }

    final void d() {
        int n;
        int n2 = 0;
        this.a(1);
        int n3 = 0;
        while (n3 < 300) {
            int n4 = 0;
            while (n4 < 400) {
                block16: {
                    int n5;
                    block13: {
                        int n6;
                        int[] nArray;
                        int n7;
                        block21: {
                            block20: {
                                block19: {
                                    block18: {
                                        block17: {
                                            block15: {
                                                block14: {
                                                    block12: {
                                                        n7 = n3 * 400 + n4;
                                                        if (this.aR.X[n7] != 0) break block12;
                                                        n7 = (n3 + 8) * this.aR.a + (n4 + 8);
                                                        nArray = this.F;
                                                        n6 = n7;
                                                        n5 = -5;
                                                        break block13;
                                                    }
                                                    if (this.aR.X[n7] != 1) break block14;
                                                    n7 = ((n3 >> 2) + 2) * this.a + ((n4 >> 2) + 2);
                                                    this.l[n7] = 1;
                                                    n7 = (n3 + 8) * this.aR.a + (n4 + 8);
                                                    nArray = this.F;
                                                    n6 = n7;
                                                    n5 = -1;
                                                    break block13;
                                                }
                                                if (this.aR.X[n7] != 9) break block15;
                                                this.a(n4 + 8, n3 + 8);
                                                break block16;
                                            }
                                            if (this.aR.X[n7] != 18) break block17;
                                            this.c(n4 + 8, n3 + 8, 0, 0);
                                            break block16;
                                        }
                                        if (this.aR.X[n7] != 22) break block18;
                                        this.c(n4 + 8, n3 + 8, 22, this.aR.Y[n7]);
                                        break block16;
                                    }
                                    if (this.aR.X[n7] != 30) break block19;
                                    this.c(n4 + 8, n3 + 8, 32, this.aR.Y[n7]);
                                    break block16;
                                }
                                if (this.aR.X[n7] != 40) break block20;
                                this.b(n4 + 8, n3 + 8, this.aR.Y[n7]);
                                break block16;
                            }
                            if (this.aR.g <= 0 && ++n2 > this.aR.h[0]) {
                                this.aR.g = 1;
                            }
                            if (this.aR.g <= 1 && n2 > this.aR.h[1]) {
                                this.aR.g = 2;
                            }
                            n = this.a((float)(n4 + 8), (float)(n3 + 8), (int)this.aR.X[n7]);
                            if (this.aR.X[n7] != 8) break block21;
                            this.z[n].a = dust.b((float)this.aR.Y[n7] * (float)Math.PI / 32.0f) * 0.1f;
                            this.z[n].b = -dust.a((float)this.aR.Y[n7] * (float)Math.PI / 32.0f) * 0.1f;
                            nArray = this.F;
                            n6 = (n3 + 8) * this.aR.a + (n4 + 8);
                            n5 = -4;
                            break block13;
                        }
                        if (this.aR.X[n7] != 15) break block16;
                        nArray = this.B;
                        n6 = n;
                        n5 = this.aR.Y[n7];
                    }
                    nArray[n6] = n5;
                }
                ++n4;
            }
            ++n3;
        }
        e e2 = new e(this.aR);
        n = 0;
        while (n < this.D) {
            int n8;
            int n9;
            int[] nArray;
            int n10;
            int n11;
            int[] nArray2;
            int n12 = (int)(dust.i() * (float)this.D);
            e2.a(this.y[n]);
            this.y[n].a(this.y[n12]);
            this.y[n12].a(e2);
            e2.a(this.z[n]);
            this.z[n].a(this.z[n12]);
            this.z[n12].a(e2);
            int n13 = this.A[n];
            this.A[n] = this.A[n12];
            this.A[n12] = n13;
            n13 = this.B[n];
            this.B[n] = this.B[n12];
            this.B[n12] = n13;
            n13 = this.C[n];
            this.C[n] = this.C[n12];
            this.C[n12] = (byte)n13;
            n13 = this.G[n];
            this.G[n] = this.G[n12];
            this.G[n12] = n13;
            if (this.A[n] == 8) {
                nArray2 = this.F;
                n11 = this.G[n];
                n10 = -4;
            } else {
                nArray2 = this.F;
                n11 = this.G[n];
                n10 = nArray2[n11] = n;
            }
            if (this.A[n12] == 8) {
                nArray = this.F;
                n9 = this.G[n12];
                n8 = -4;
            } else {
                nArray = this.F;
                n9 = this.G[n12];
                n8 = n12;
            }
            nArray[n9] = n8;
            ++n;
        }
        this.aR.ai = this.aR.aj;
    }

    private void g() {
        int n;
        int n2;
        if (this.aR.o > this.aR.q) {
            n2 = this.aR.o;
            this.aR.o = this.aR.q;
            this.aR.q = n2;
        }
        if (this.aR.p > this.aR.r) {
            n = this.aR.p;
            this.aR.p = this.aR.r;
            this.aR.r = n;
        }
        int n3 = this.m - (this.aR.q - this.aR.o) / 2 - this.aR.o;
        int n4 = this.n - (this.aR.r - this.aR.p) / 2 - this.aR.p;
        n = this.aR.p - 8;
        while (n <= this.aR.r - 8) {
            block7: {
                if (n + n4 < 0 || n + n4 >= 300) break block7;
                n2 = this.aR.o - 8;
                while (n2 <= this.aR.q - 8) {
                    block8: {
                        int n5;
                        block10: {
                            int n6;
                            int[] nArray;
                            int n7;
                            int n8;
                            block9: {
                                if (n2 + n3 < 0 || n2 + n3 >= 400 || this.aR.s[n8 = n * 400 + n2] == 0 || this.F[(n4 + n + 8) * this.aR.a + (n3 + n2 + 8)] != -5 || (n7 = this.a((float)(n3 + n2 + 8), (float)(n4 + n + 8), (int)this.aR.s[n8])) < 0) break block8;
                                if (this.aR.s[n8] != 8) break block9;
                                this.z[n7].a = dust.b((float)this.aR.t[n8] * (float)Math.PI / 32.0f) * 0.1f;
                                this.z[n7].b = -dust.a((float)this.aR.t[n8] * (float)Math.PI / 32.0f) * 0.1f;
                                nArray = this.F;
                                n6 = (n4 + n + 8) * this.aR.a + (n3 + n2 + 8);
                                n5 = -4;
                                break block10;
                            }
                            if (this.aR.s[n8] != 15) break block8;
                            nArray = this.B;
                            n6 = n7;
                            n5 = this.aR.t[n8];
                        }
                        nArray[n6] = n5;
                    }
                    ++n2;
                }
            }
            ++n;
        }
    }

    private void h() {
        int n = 0;
        while (n < 120000) {
            this.aR.s[n] = 0;
            this.aR.t[n] = 0;
            ++n;
        }
        n = 0;
        while (n < this.D) {
            block4: {
                int n2;
                block6: {
                    int n3;
                    byte[] byArray;
                    int n4;
                    block5: {
                        int n5 = (int)this.y[n].a;
                        int n6 = (int)this.y[n].b;
                        if (n5 < 8 || n5 >= 408 || n6 < 8 || n6 >= 308) break block4;
                        n4 = (n6 -= 8) * 400 + (n5 -= 8);
                        this.aR.s[n4] = (byte)this.A[n];
                        if (this.A[n] != 8) break block5;
                        byArray = this.aR.t;
                        n3 = n4;
                        n2 = dust.b((int)(64.0f * this.z[n].f() / ((float)Math.PI * 2)), 0, 63);
                        break block6;
                    }
                    if (this.A[n] != 15) break block4;
                    byArray = this.aR.t;
                    n3 = n4;
                    n2 = this.B[n] % 100;
                }
                byArray[n3] = (byte)n2;
            }
            ++n;
        }
    }

    /*
     * Handled impossible loop by duplicating code
     * Enabled aggressive block sorting
     */
    final void a(int n) {
        int n2;
        int n3;
        int n4;
        int n5;
        block30: {
            int n6;
            int n7;
            block29: {
                block26: {
                    block28: {
                        int n8;
                        int n9;
                        block27: {
                            this.a = 104;
                            this.b = 79;
                            this.c = 4;
                            this.d = this.a * this.b;
                            this.e = new e[this.d];
                            this.f = new e[this.d];
                            this.g = new float[this.d];
                            this.h = new float[this.d];
                            n5 = 0;
                            while (n5 < this.d) {
                                this.e[n5] = new e(this.aR, 0.0f, 0.0f);
                                ++n5;
                            }
                            n5 = 0;
                            while (n5 < this.d) {
                                this.f[n5] = new e(this.aR, 0.0f, 0.0f);
                                ++n5;
                            }
                            n5 = 0;
                            while (n5 < this.d) {
                                this.g[n5] = 0.0f;
                                ++n5;
                            }
                            n5 = 0;
                            while (n5 < this.d) {
                                this.h[n5] = 0.0f;
                                ++n5;
                            }
                            this.i = 0.0f;
                            this.j = new int[this.d];
                            this.k = new int[this.d];
                            n4 = 0;
                            n3 = 0;
                            while (n3 < this.b) {
                                n2 = 0;
                                while (n2 < this.a) {
                                    this.j[n4] = n2 * this.c;
                                    this.k[n4] = n3 * this.c;
                                    ++n2;
                                    ++n4;
                                }
                                ++n3;
                            }
                            this.l = new int[this.d];
                            n5 = 0;
                            while (n5 < this.d) {
                                this.l[n5] = 0;
                                ++n5;
                            }
                            if (n != 0) break block26;
                            n5 = 0;
                            n4 = this.a * 2 + 2;
                            while (n5 < this.a - 4) {
                                this.l[n4] = 1;
                                ++n5;
                                ++n4;
                            }
                            n5 = 0;
                            n4 = this.a * (this.b - 3) + 2;
                            while (n5 < this.a - 4) {
                                this.l[n4] = 1;
                                ++n5;
                                ++n4;
                            }
                            n5 = 0;
                            n9 = this.a * 2;
                            n8 = 2;
                            if (!true) break block27;
                            n4 = n9 + n8;
                            if (n5 >= this.b - 4) break block28;
                        }
                        do {
                            this.l[n4] = 1;
                            ++n5;
                            n9 = n4;
                            n8 = this.a;
                            n4 = n9 + n8;
                        } while (n5 < this.b - 4);
                    }
                    n5 = 0;
                    int n10 = this.a * 3 - 3;
                    while (n5 < this.b - 4) {
                        this.l[n4] = 1;
                        ++n5;
                        n10 = n4 = n4 + this.a;
                    }
                }
                n5 = 0;
                n4 = this.a + 1;
                while (n5 < this.a - 2) {
                    this.l[n4] = -1;
                    ++n5;
                    ++n4;
                }
                n5 = 0;
                n4 = this.a * (this.b - 2) + 1;
                while (n5 < this.a - 2) {
                    this.l[n4] = -1;
                    ++n5;
                    ++n4;
                }
                n5 = 0;
                n7 = this.a;
                n6 = 1;
                if (!true) break block29;
                n4 = n7 + n6;
                if (n5 >= this.b - 2) break block30;
            }
            do {
                this.l[n4] = -1;
                ++n5;
                n7 = n4;
                n6 = this.a;
                n4 = n7 + n6;
            } while (n5 < this.b - 2);
        }
        n5 = 0;
        int n11 = this.a * 2 - 2;
        while (n5 < this.b - 2) {
            this.l[n4] = -1;
            ++n5;
            n11 = n4 = n4 + this.a;
        }
        n5 = 0;
        n4 = 0;
        while (n5 < this.a) {
            this.l[n4] = -1;
            ++n5;
            ++n4;
        }
        n5 = 0;
        n4 = this.a * (this.b - 1);
        while (n5 < this.a) {
            this.l[n4] = -1;
            ++n5;
            ++n4;
        }
        n5 = 0;
        int n12 = 0;
        while (n5 < this.b) {
            this.l[n4] = -1;
            ++n5;
            n12 = n4 = n4 + this.a;
        }
        n5 = 0;
        int n13 = this.a - 1;
        while (n5 < this.b) {
            this.l[n4] = -1;
            ++n5;
            n13 = n4 = n4 + this.a;
        }
        this.m = this.c * 2;
        this.n = this.c * 2;
        this.o = this.m;
        this.p = this.n;
        this.q.a(0.0f, 0.0f);
        this.j();
        this.m();
        this.q();
        this.u();
        this.x();
        if (n == 0) {
            n4 = 8 * this.aR.a + 8;
            n3 = 8;
            while (n3 < 308) {
                n2 = 8;
                while (n2 < 408) {
                    int n14 = (n3 >> 2) * this.a + (n2 >> 2);
                    if (this.l[n14] == 1) {
                        this.F[n4] = -1;
                    }
                    ++n2;
                    ++n4;
                }
                ++n3;
                n4 += 16;
            }
        }
        n5 = this.aR.a * 309 - 1;
        while (n5 >= 0) {
            this.aR.P[n5] = 0;
            this.aR.Q[n5] = 0;
            this.aR.R[n5] = 0;
            --n5;
        }
        this.aR.ai = 0;
    }

    private void a(int n, int n2, int n3, int n4) {
        int n5 = n;
        while (this.F[n5] >= 0 && this.A[this.F[n5]] == n2) {
            this.A[this.F[n5]] = n3;
            this.B[this.F[n5]] = n4;
            this.C[this.F[n5]] = 0;
            --n5;
        }
        ++n5;
        int n6 = n + 1;
        while (this.F[n6] >= 0 && this.A[this.F[n6]] == n2) {
            this.A[this.F[n6]] = n3;
            this.B[this.F[n6]] = n4;
            this.C[this.F[n6]] = 0;
            ++n6;
        }
        n = n5;
        while (n <= --n6) {
            if (this.F[n - this.aR.a] >= 0 && this.A[this.F[n - this.aR.a]] == n2) {
                this.a(n - this.aR.a, n2, n3, n4);
            }
            if (this.F[n + this.aR.a] >= 0 && this.A[this.F[n + this.aR.a]] == n2) {
                this.a(n + this.aR.a, n2, n3, n4);
            }
            ++n;
        }
    }

    final void e() {
        e e2;
        e e3;
        e e4;
        block53: {
            block55: {
                block59: {
                    int n;
                    dust dust2;
                    d d2;
                    block57: {
                        block58: {
                            block56: {
                                block54: {
                                    e4 = new e(this.aR);
                                    e3 = new e(this.aR);
                                    e2 = new e(this.aR);
                                    if (this.aR.e || this.aR.u != 0) break block53;
                                    this.o = this.m;
                                    this.p = this.n;
                                    this.m = dust.a(this.aR.aR + this.c * 2, this.c * 2, this.c * (this.a - 2) - 1);
                                    this.n = dust.a(this.aR.aS + this.c * 2, this.c * 2, this.c * (this.b - 2) - 1);
                                    if (this.aR.k > 0) {
                                        this.m = this.c * 2 + (int)this.aR.l + (this.aR.aR >> this.aR.k);
                                        this.n = this.c * 2 + (int)this.aR.m + (this.aR.aS >> this.aR.k);
                                        this.m = dust.a(this.m, this.c * 2, this.c * (this.a - 2) - 1);
                                        this.n = dust.a(this.n, this.c * 2, this.c * (this.b - 2) - 1);
                                    }
                                    if (this.aR.z != 1) break block54;
                                    if (this.aR.aH || this.aR.aL) {
                                        this.aR.B = this.m;
                                        this.aR.C = this.n;
                                    } else if (this.aR.aI || this.aR.aM) {
                                        this.o = this.aR.B;
                                        this.p = this.aR.C;
                                    }
                                    break block55;
                                }
                                if (this.aR.z != 2) break block55;
                                if (!this.aR.aH && !this.aR.aL) break block56;
                                d2 = this;
                                break block57;
                            }
                            if (!this.aR.aJ && !this.aR.aN) break block58;
                            if (this.aR.A == 0) {
                                if (dust.c(this.m - this.o) > dust.c(this.n - this.p)) {
                                    dust2 = this.aR;
                                    n = 1;
                                } else if (dust.c(this.m - this.o) < dust.c(this.n - this.p)) {
                                    dust2 = this.aR;
                                    n = 2;
                                }
                            }
                            break block59;
                        }
                        if (!this.aR.aI && !this.aR.aM) break block59;
                        d2 = this;
                    }
                    dust2 = d2.aR;
                    n = dust2.A = 0;
                }
                if (this.aR.A == 1) {
                    this.n = this.p;
                } else if (this.aR.A == 2) {
                    this.m = this.o;
                }
            }
            e4.a(this.m, (float)this.n);
            this.q.a((float)this.o - this.q.a * 5.0f, (float)this.p - this.q.b * 5.0f);
            this.aR.a(e4, this.q, 5.0f, 0.5f, 0.5f);
            this.q.a(e4, this.q);
            this.q.d();
            this.b(0);
            this.b(1);
            if (this.aR.aH || this.aR.aL) {
                this.aR.ai = dust.a(this.aR.ai + 1, 0, 4095);
            }
        }
        int[] nArray = new int[]{1, 2, 4, 8};
        int n = 0;
        while (n < nArray[this.aR.x]) {
            int n2;
            int n3 = 0;
            int n4 = 0;
            while (n4 < this.d) {
                if (this.l[n4] == 0) {
                    ++n3;
                }
                ++n4;
            }
            if (n3 > 0) {
                this.i /= (float)n3;
                n4 = 0;
                while (n4 < this.d) {
                    if (this.l[n4] == 0) {
                        int n5 = n4;
                        this.g[n5] = this.g[n5] + this.i;
                    }
                    ++n4;
                }
                this.i = 0.0f;
            }
            if (!(this.aR.w != 1 || this.aR.aP && this.aR.u == 0 && this.aR.aX[10] | this.aR.aX[13])) {
                return;
            }
            n4 = 0;
            while (n4 < this.d) {
                this.f[n4].a(this.e[n4]);
                ++n4;
            }
            int n6 = this.a * 2 + 2;
            int n7 = 2;
            while (n7 < this.b - 2) {
                n2 = 2;
                while (n2 < this.a - 2) {
                    if (this.l[n6] != 1) {
                        e4.a(this.e[n6]);
                        float f = e4.d();
                        if (f != 0.0f) {
                            int n8;
                            float f2 = dust.e(e4.a);
                            float f3 = dust.e(e4.b);
                            float f4 = f2 / (f2 + f3) * f * 0.5f;
                            float f5 = f3 / (f2 + f3) * f * 0.5f;
                            e3.a(e4, f4);
                            e2.a(e4, f5);
                            int n9 = e4.a < 0.0f ? -1 : 1;
                            int n10 = n8 = e4.b < 0.0f ? -this.a : this.a;
                            if (f2 > f3) {
                                if (this.l[n6 + n9] <= 0) {
                                    this.f[n6].c(e3);
                                    this.f[n6 + n9].b(e3);
                                    int n11 = n6 + n9;
                                    this.g[n11] = this.g[n11] + f4;
                                    int n12 = n6;
                                    this.g[n12] = this.g[n12] - f4;
                                } else {
                                    this.f[n6].c(e3);
                                    this.f[n6].c(e3);
                                }
                                if (this.l[n6 + n9 + n8] <= 0) {
                                    this.f[n6].c(e2);
                                    this.f[n6 + n9 + n8].b(e2);
                                    int n13 = n6;
                                    this.g[n13] = this.g[n13] - f5;
                                    int n14 = n6 + n9 + n8;
                                    this.g[n14] = this.g[n14] + f5;
                                } else {
                                    this.f[n6].c(e2);
                                    this.f[n6].c(e2);
                                }
                            } else {
                                if (this.l[n6 + n8] <= 0) {
                                    this.f[n6].c(e2);
                                    this.f[n6 + n8].b(e2);
                                    int n15 = n6;
                                    this.g[n15] = this.g[n15] - f5;
                                    int n16 = n6 + n8;
                                    this.g[n16] = this.g[n16] + f5;
                                } else {
                                    this.f[n6].c(e2);
                                    this.f[n6].c(e2);
                                }
                                if (this.l[n6 + n8 + n9] <= 0) {
                                    this.f[n6].c(e3);
                                    this.f[n6 + n8 + n9].b(e3);
                                    int n17 = n6;
                                    this.g[n17] = this.g[n17] - f4;
                                    int n18 = n6 + n8 + n9;
                                    this.g[n18] = this.g[n18] + f4;
                                } else {
                                    this.f[n6].c(e3);
                                    this.f[n6].c(e3);
                                }
                            }
                        }
                    }
                    ++n2;
                    ++n6;
                }
                ++n7;
                n6 += 4;
            }
            n4 = 0;
            while (n4 < this.d) {
                this.h[n4] = this.g[n4];
                ++n4;
            }
            n6 = this.a * 2 + 2;
            int n19 = -1 - this.a;
            int n20 = 1 - this.a;
            int n21 = -1 + this.a;
            int n22 = 1 + this.a;
            n7 = 2;
            while (n7 < this.b - 2) {
                n2 = 2;
                while (n2 < this.a - 2) {
                    if (this.l[n6] != 1) {
                        if (this.l[n6 - 1] <= 0) {
                            this.f[n6].a -= (this.g[n6] - this.g[n6 - 1]) * 0.0625f;
                            int n23 = n6;
                            this.h[n23] = this.h[n23] - (this.g[n6] - this.g[n6 - 1]) * 0.0625f;
                        }
                        if (this.l[n6 + 1] <= 0) {
                            this.f[n6].a += (this.g[n6] - this.g[n6 + 1]) * 0.0625f;
                            int n24 = n6;
                            this.h[n24] = this.h[n24] - (this.g[n6] - this.g[n6 + 1]) * 0.0625f;
                        }
                        if (this.l[n6 - this.a] <= 0) {
                            this.f[n6].b -= (this.g[n6] - this.g[n6 - this.a]) * 0.0625f;
                            int n25 = n6;
                            this.h[n25] = this.h[n25] - (this.g[n6] - this.g[n6 - this.a]) * 0.0625f;
                        }
                        if (this.l[n6 + this.a] <= 0) {
                            this.f[n6].b += (this.g[n6] - this.g[n6 + this.a]) * 0.0625f;
                            int n26 = n6;
                            this.h[n26] = this.h[n26] - (this.g[n6] - this.g[n6 + this.a]) * 0.0625f;
                        }
                        if (this.l[n6 + n19] <= 0) {
                            this.f[n6].a -= (this.g[n6] - this.g[n6 + n19]) * 0.044194173f;
                            this.f[n6].b -= (this.g[n6] - this.g[n6 + n19]) * 0.044194173f;
                            int n27 = n6;
                            this.h[n27] = this.h[n27] - (this.g[n6] - this.g[n6 + n19]) * 0.044194173f;
                        }
                        if (this.l[n6 + n20] <= 0) {
                            this.f[n6].a += (this.g[n6] - this.g[n6 + n20]) * 0.044194173f;
                            this.f[n6].b -= (this.g[n6] - this.g[n6 + n20]) * 0.044194173f;
                            int n28 = n6;
                            this.h[n28] = this.h[n28] - (this.g[n6] - this.g[n6 + n20]) * 0.044194173f;
                        }
                        if (this.l[n6 + n21] <= 0) {
                            this.f[n6].a -= (this.g[n6] - this.g[n6 + n21]) * 0.044194173f;
                            this.f[n6].b += (this.g[n6] - this.g[n6 + n21]) * 0.044194173f;
                            int n29 = n6;
                            this.h[n29] = this.h[n29] - (this.g[n6] - this.g[n6 + n21]) * 0.044194173f;
                        }
                        if (this.l[n6 + n22] <= 0) {
                            this.f[n6].a += (this.g[n6] - this.g[n6 + n22]) * 0.044194173f;
                            this.f[n6].b += (this.g[n6] - this.g[n6 + n22]) * 0.044194173f;
                            int n30 = n6;
                            this.h[n30] = this.h[n30] - (this.g[n6] - this.g[n6 + n22]) * 0.044194173f;
                        }
                    }
                    ++n2;
                    ++n6;
                }
                ++n7;
                n6 += 4;
            }
            n4 = 0;
            while (n4 < this.d) {
                if (this.l[n4] != -1) {
                    this.e[n4].a(this.f[n4]);
                    this.g[n4] = this.h[n4];
                } else {
                    this.g[n4] = 0.0f;
                    this.e[n4].a(0.0f, 0.0f);
                }
                ++n4;
            }
            this.k();
            this.o();
            this.s();
            this.v();
            this.y();
            ++n;
        }
    }

    private void b(int n) {
        block105: {
            boolean bl;
            boolean bl2;
            boolean bl3;
            int n2;
            block118: {
                int n3;
                int n4;
                int n5;
                int n6;
                block117: {
                    block116: {
                        block115: {
                            block114: {
                                block113: {
                                    block112: {
                                        block111: {
                                            e e2;
                                            block104: {
                                                e2 = new e(this.aR);
                                                n2 = n == 0 ? this.aR.c : this.aR.d;
                                                bl3 = n == 0 ? this.aR.aH : this.aR.aL;
                                                bl2 = n == 0 ? this.aR.aI : this.aR.aM;
                                                boolean bl4 = bl = n == 0 ? this.aR.aJ : this.aR.aN;
                                                if (n2 >= 34) break block104;
                                                if (this.aR.z == 1) {
                                                    boolean bl5 = bl = n == 0 ? this.aR.aI : this.aR.aM;
                                                }
                                                if (!bl) break block105;
                                                int n7 = this.m - this.o;
                                                int n8 = this.n - this.p;
                                                if (this.aR.f <= 1 && this.aR.w == 1 && this.aR.k <= 1 && n7 == 0 && n8 == 0 && this.aR.z != 3) {
                                                    return;
                                                }
                                                int n9 = dust.b(dust.b(dust.c(n7), dust.c(n8)), 1);
                                                n7 = (n7 << 8) / n9;
                                                n8 = (n8 << 8) / n9;
                                                int n10 = (this.o << 8) + 127;
                                                int n11 = (this.p << 8) + 127;
                                                int n12 = 0;
                                                while (n12 <= n9) {
                                                    int n13 = this.aR.f;
                                                    int n14 = (n10 >> 8) - n13;
                                                    int n15 = (n11 >> 8) - n13;
                                                    int n16 = n14 + n13 * 2;
                                                    int n17 = n15 + n13 * 2;
                                                    if (n14 < 8) {
                                                        n14 = 8;
                                                    }
                                                    if (n15 < 8) {
                                                        n15 = 8;
                                                    }
                                                    if (n16 > this.aR.a - 8 - 1) {
                                                        n16 = this.aR.a - 8 - 1;
                                                    }
                                                    if (n17 > 307) {
                                                        n17 = 307;
                                                    }
                                                    int n18 = n15 * this.aR.a + n14;
                                                    int n19 = this.aR.a - (n16 - n14 + 1);
                                                    int n20 = n15;
                                                    while (n20 <= n17) {
                                                        int n21 = n14;
                                                        while (n21 <= n16) {
                                                            block106: {
                                                                int n22;
                                                                block109: {
                                                                    float f;
                                                                    int n23;
                                                                    int[] nArray;
                                                                    int n24;
                                                                    int n25;
                                                                    block110: {
                                                                        block108: {
                                                                            block107: {
                                                                                if (n13 * n13 + 1 < (n21 - (n10 >> 8)) * (n21 - (n10 >> 8)) + (n20 - (n11 >> 8)) * (n20 - (n11 >> 8))) break block106;
                                                                                if (this.aR.z != 3) break block107;
                                                                                n25 = this.r[n2] != 0 ? this.r[n2] : 2;
                                                                                int n26 = 0;
                                                                                if (n25 != 8) {
                                                                                    int n27;
                                                                                    if (n25 == 15) {
                                                                                        n27 = this.s[this.aR.c] != 0 ? this.s[this.aR.c] : (this.s[this.aR.d] != 0 ? this.s[this.aR.d] : 2);
                                                                                    } else if (n25 == 33) {
                                                                                        float f2;
                                                                                        float f3 = 8.0f * this.q.f() / ((float)Math.PI * 2) + 0.5f;
                                                                                        if (f2 >= 8.0f) {
                                                                                            f3 = 0.0f;
                                                                                        }
                                                                                        n27 = n26 = (int)f3 + 1;
                                                                                    }
                                                                                    if (this.F[n18] >= 0 && this.A[this.F[n18]] != n25) {
                                                                                        this.a(n18, this.A[this.F[n18]], n25, n26);
                                                                                    }
                                                                                }
                                                                                break block106;
                                                                            }
                                                                            if (this.F[n18] != -5) break block106;
                                                                            n25 = this.r[n2];
                                                                            if ((n == 0 && this.aR.aN && this.aR.d < 34 || n == 1 && this.aR.aJ && this.aR.c < 34) && this.aR.d(100.0f) < 50.0f) {
                                                                                n25 = this.r[n == 0 ? this.aR.d : this.aR.c];
                                                                            }
                                                                            if ((n24 = this.a((float)n21, (float)n20, n25)) < 0) break block106;
                                                                            if (n25 != 8) break block108;
                                                                            e2.a(this.q, 0.1f);
                                                                            this.z[n24].a(e2);
                                                                            nArray = this.F;
                                                                            n23 = n18;
                                                                            n22 = -4;
                                                                            break block109;
                                                                        }
                                                                        if (n25 != 15) break block110;
                                                                        if (this.s[this.aR.c] != 0) {
                                                                            nArray = this.B;
                                                                            n23 = n24;
                                                                            n22 = this.s[this.aR.c];
                                                                        } else if (this.s[this.aR.d] != 0) {
                                                                            nArray = this.B;
                                                                            n23 = n24;
                                                                            n22 = this.s[this.aR.d];
                                                                        } else {
                                                                            nArray = this.B;
                                                                            n23 = n24;
                                                                            n22 = 2;
                                                                        }
                                                                        break block109;
                                                                    }
                                                                    if (n25 != 33) break block106;
                                                                    float f4 = 8.0f * this.q.f() / ((float)Math.PI * 2) + 0.5f;
                                                                    if (f >= 8.0f) {
                                                                        f4 = 0.0f;
                                                                    }
                                                                    nArray = this.B;
                                                                    n23 = n24;
                                                                    n22 = (int)f4 + 1;
                                                                }
                                                                nArray[n23] = n22;
                                                            }
                                                            ++n21;
                                                            ++n18;
                                                        }
                                                        ++n20;
                                                        n18 += n19;
                                                    }
                                                    ++n12;
                                                    n10 += n7;
                                                    n11 += n8;
                                                }
                                                return;
                                            }
                                            if (n2 != 40) break block111;
                                            int n28 = (this.n >> 2) * this.a + (this.m >> 2);
                                            e2.a(this.q, 10.0f);
                                            if (bl && this.l[n28] == 0) {
                                                this.e[n28].b(e2);
                                                if (this.e[n28].a() > 10.0f && this.aR.w == 1) {
                                                    this.e[n28].d();
                                                    this.e[n28].a(10.0f);
                                                    return;
                                                }
                                            }
                                            break block105;
                                        }
                                        if (n2 != 41) break block112;
                                        int n29 = (this.n >> 2) * this.a + (this.m >> 2);
                                        if (bl) {
                                            float f = (float)((this.aR.f + 1) * (this.aR.f + 1)) * 0.25f;
                                            float f5 = f = n == 0 ? f : -f;
                                            if (this.l[n29] == 0) {
                                                int n30 = n29;
                                                this.g[n30] = this.g[n30] + f;
                                                this.i -= f;
                                            }
                                            if (this.l[n29 - 1] == 0) {
                                                int n31 = n29 - 1;
                                                this.g[n31] = this.g[n31] + f;
                                                this.i -= f;
                                            }
                                            if (this.l[n29 - this.a] == 0) {
                                                int n32 = n29 - this.a;
                                                this.g[n32] = this.g[n32] + f;
                                                this.i -= f;
                                            }
                                            if (this.l[n29 - this.a - 1] == 0) {
                                                int n33 = n29 - this.a - 1;
                                                this.g[n33] = this.g[n33] + f;
                                                this.i -= f;
                                                return;
                                            }
                                        }
                                        break block105;
                                    }
                                    if (n2 != 43) break block113;
                                    if (this.ae > this.af - 5) {
                                        return;
                                    }
                                    int n34 = this.m >> 2 << 2;
                                    int n35 = this.n >> 2 << 2;
                                    int n36 = (this.n >> 2) * this.a + (this.m >> 2);
                                    if (this.l[n36] != 0) {
                                        ++this.ag;
                                        return;
                                    }
                                    if (bl3) {
                                        ++this.ag;
                                    }
                                    if (bl) {
                                        int n37 = this.r();
                                        if (n37 < 5) {
                                            ++this.ag;
                                            this.a((float)(n34 + (int)this.aR.d(this.c)), (float)(n35 + (int)this.aR.d(this.c)));
                                            this.a((float)(n34 + (int)this.aR.d(this.c)), (float)(n35 + (int)this.aR.d(this.c)));
                                            this.a((float)(n34 + (int)this.aR.d(this.c)), (float)(n35 + (int)this.aR.d(this.c)));
                                            this.a((float)(n34 + (int)this.aR.d(this.c)), (float)(n35 + (int)this.aR.d(this.c)));
                                            this.a((float)(n34 + (int)this.aR.d(this.c)), (float)(n35 + (int)this.aR.d(this.c)));
                                            return;
                                        }
                                        this.a((float)(n34 + (int)this.aR.d(this.c)), (float)(n35 + (int)this.aR.d(this.c)));
                                        return;
                                    }
                                    break block105;
                                }
                                if (n2 != 44) break block114;
                                if (bl3) {
                                    int n38 = dust.a(this.m, 24, 391);
                                    int n39 = dust.a(this.n, 24, 291);
                                    boolean bl6 = false;
                                    int n40 = 0;
                                    while (n40 < this.V) {
                                        if (n38 == this.R[n40] && n39 == this.S[n40]) {
                                            bl6 = true;
                                            break;
                                        }
                                        ++n40;
                                    }
                                    if (!bl6) {
                                        this.a(n38, n39);
                                        return;
                                    }
                                }
                                break block105;
                            }
                            if (n2 != 45 && n2 != 46 && n2 != 47 && n2 != 49) break block115;
                            int n41 = this.m >> 2 << 2;
                            int n42 = this.n >> 2 << 2;
                            int n43 = (this.n >> 2) * this.a + (this.m >> 2);
                            if (this.l[n43] != 0) {
                                return;
                            }
                            if (bl3 && n2 == 46) {
                                this.c(n41, n42, 0, 0);
                                return;
                            }
                            if (bl3 && n2 == 47) {
                                this.c(n41, n42, 22, this.aR.f);
                                return;
                            }
                            if (bl3 && n2 == 45) {
                                int n44 = this.t[this.aR.c] != 0 ? this.t[this.aR.c] : (this.t[this.aR.d] != 0 ? this.t[this.aR.d] : 0);
                                this.c(n41, n42, 30, n44);
                                return;
                            }
                            if (bl3 && n2 == 49) {
                                this.c(n41, n42, 22, 10);
                                return;
                            }
                            break block105;
                        }
                        if (n2 != 48) break block116;
                        int n45 = (this.n >> 2) * this.a + (this.m >> 2);
                        if (this.l[n45] != 0) {
                            return;
                        }
                        if (bl3 && n2 == 48) {
                            int n46 = this.u[this.aR.c] != 0 ? this.u[this.aR.c] : (this.u[this.aR.d] != 0 ? this.u[this.aR.d] : 2);
                            this.b(this.m, this.n, n46);
                            return;
                        }
                        break block105;
                    }
                    if (n2 != 54) break block117;
                    this.aR.V = this.m;
                    this.aR.W = this.n - 14;
                    if (bl3) {
                        this.aR.u = 20;
                        return;
                    }
                    break block105;
                }
                if (n2 != 50 && n2 != 51 && n2 != 52) break block118;
                if (this.aR.z == 1) {
                    boolean bl7 = bl = n == 0 ? this.aR.aI : this.aR.aM;
                }
                if (!bl) {
                    return;
                }
                int n47 = this.m / this.c - this.o / this.c;
                int n48 = this.n / this.c - this.p / this.c;
                int n49 = dust.b(dust.b(dust.c(n47), dust.c(n48)), 1);
                n47 = (n47 << 8) / n49;
                n48 = (n48 << 8) / n49;
                int n50 = (this.o / this.c << 8) - 127;
                int n51 = (this.p / this.c << 8) - 127;
                int n52 = 0;
                while (n52 <= n49) {
                    n6 = (n50 >> 8) - this.aR.f / 2;
                    int n53 = (n51 >> 8) - this.aR.f / 2;
                    float f = (float)n6 + (float)this.aR.f / 2.0f + 0.5f;
                    float f6 = (float)n53 + (float)this.aR.f / 2.0f + 0.5f;
                    n5 = n53;
                    while (n5 <= n53 + this.aR.f) {
                        n4 = n6;
                        while (n4 <= n6 + this.aR.f) {
                            block119: {
                                block121: {
                                    block122: {
                                        block120: {
                                            if (((float)n4 - f) * ((float)n4 - f) + ((float)n5 - f6) * ((float)n5 - f6) > (float)(this.aR.f * this.aR.f / 4)) break block119;
                                            n3 = dust.a(n5, 2, this.b - 3) * this.a + dust.a(n4, 2, this.a - 3);
                                            if (n2 != 50) break block120;
                                            this.l[n3] = 1;
                                            this.e[n3].a(0.0f, 0.0f);
                                            break block121;
                                        }
                                        if (n2 != 51) break block122;
                                        this.l[n3] = -2;
                                        break block119;
                                    }
                                    if (n2 != 52 || this.l[n3] != 0) break block119;
                                    this.l[n3] = -2;
                                    this.e[n3].a(0.0f, 0.0f);
                                }
                                this.i += this.g[n3];
                                this.g[n3] = 0.0f;
                            }
                            ++n4;
                        }
                        ++n5;
                    }
                    ++n52;
                    n50 += n47;
                    n51 += n48;
                }
                if (n2 == 52 && this.aR.f == 0) {
                    n47 = this.m - this.o;
                    n48 = this.n - this.p;
                    n49 = dust.b(dust.b(dust.c(n47), dust.c(n48)), 1);
                    n47 = (n47 << 8) / n49;
                    n48 = (n48 << 8) / n49;
                    n50 = (this.o << 8) + 127;
                    n51 = (this.p << 8) + 127;
                    n52 = 0;
                    while (n52 <= n49) {
                        n3 = 0;
                        while (n3 < this.D) {
                            if (n50 >> 8 == (int)this.y[n3].a && n51 >> 8 == (int)this.y[n3].b) {
                                this.c(n3--);
                            }
                            ++n3;
                        }
                        ++n52;
                        n50 += n47;
                        n51 += n48;
                    }
                }
                if (n2 == 50 || n2 == 52) {
                    n52 = 0;
                    while (n52 < this.D) {
                        n3 = ((int)this.y[n52].b >> 2) * this.a + ((int)this.y[n52].a >> 2);
                        if (this.l[n3] != 0) {
                            this.c(n52--);
                        }
                        ++n52;
                    }
                }
                if (n2 == 51) {
                    n52 = 0;
                    while (n52 < this.V) {
                        n3 = (this.S[n52] >> 2) * this.a + (this.R[n52] >> 2);
                        if (this.l[n3] == -2) {
                            this.d(n52--);
                        }
                        ++n52;
                    }
                }
                if (n2 == 50 || n2 == 51) {
                    int n54;
                    n52 = 0;
                    while (n52 < this.at) {
                        if (this.ao[n52] == 10 || this.ao[n52] == 11 || this.ao[n52] == 30 || this.ao[n52] == 40) {
                            n54 = 4;
                            while (n54 < 6) {
                                n3 = ((int)this.ak[n52 * this.av + n54].b >> 2) * this.a + ((int)this.ak[n52 * this.av + n54].a >> 2);
                                if (this.l[n3] != 0) {
                                    this.e(n52--);
                                    break;
                                }
                                ++n54;
                            }
                        } else if (this.ao[n52] == 20) {
                            n54 = 0;
                            while (n54 < 4) {
                                n3 = ((int)this.ak[n52 * this.av + n54].b >> 2) * this.a + ((int)this.ak[n52 * this.av + n54].a >> 2);
                                if (this.l[n3] != 0) {
                                    this.e(n52--);
                                    break;
                                }
                                ++n54;
                            }
                        }
                        ++n52;
                    }
                    n52 = 0;
                    while (n52 < this.aH) {
                        if (this.aD[n52] != 0 && this.l[n3 = ((int)this.aB[n52].b >> 2) * this.a + ((int)this.aB[n52].a >> 2)] != 0) {
                            n3 = (int)this.aB[n52].b * this.aR.a + (int)this.aB[n52].a;
                            n54 = 0;
                            while (n54 < 21) {
                                if (this.F[n3 + this.aJ[n54]] == -2) {
                                    this.F[n3 + this.aJ[n54]] = -5;
                                }
                                ++n54;
                            }
                            this.aD[n52] = 0;
                        }
                        ++n52;
                    }
                }
                if (n2 == 51 || n2 == 52) {
                    n52 = 0;
                    while (n52 < this.d) {
                        if (this.l[n52] == -2) {
                            this.l[n52] = 0;
                        }
                        ++n52;
                    }
                }
                n3 = 8 * this.aR.a + 8;
                n5 = 8;
                while (n5 < 308) {
                    n4 = 8;
                    while (n4 < 408) {
                        block125: {
                            int n55;
                            block124: {
                                int n56;
                                int[] nArray;
                                block123: {
                                    n6 = (n5 >> 2) * this.a + (n4 >> 2);
                                    if (this.l[n6] != 0 || this.F[n3] != -1) break block123;
                                    nArray = this.F;
                                    n56 = n3;
                                    n55 = -5;
                                    break block124;
                                }
                                if (this.l[n6] != 1 || this.F[n3] >= -1) break block125;
                                nArray = this.F;
                                n56 = n3;
                                n55 = -1;
                            }
                            nArray[n56] = n55;
                        }
                        ++n4;
                        ++n3;
                    }
                    ++n5;
                    n3 += 16;
                }
                return;
            }
            if (n2 == 53) {
                if (bl3) {
                    if (this.aR.n == 0) {
                        this.aR.o = this.aR.q = this.m;
                        this.aR.p = this.aR.r = this.n;
                        return;
                    }
                    if (this.aR.w != 1 || this.aR.k > 1 || this.aR.o != this.aR.q || this.aR.p != this.aR.r) {
                        this.g();
                    }
                    return;
                }
                if (bl2 && this.aR.n == 0) {
                    this.h();
                    return;
                }
                if (bl && this.aR.n == 0) {
                    this.aR.q = this.m;
                    this.aR.r = this.n;
                    return;
                }
            } else if (n2 == 57) {
                if (this.aR.k == 0) {
                    return;
                }
                if (!bl) {
                    return;
                }
                this.aR.l -= (float)(this.aR.aR - this.aR.aT) / (float)(1 << this.aR.k);
                this.aR.m -= (float)(this.aR.aS - this.aR.aU) / (float)(1 << this.aR.k);
                int[] nArray = new int[]{300, 150, 75, 38, 19};
                this.aR.l = dust.a(this.aR.l, 0.0f, (float)(400 - (400 >> this.aR.k)));
                this.aR.m = dust.a(this.aR.m, 0.0f, (float)(300 - nArray[this.aR.k]));
            }
        }
    }

    /*
     * Unable to fully structure code
     */
    final void f() {
        block178: {
            block177: {
                block134: {
                    block164: {
                        block163: {
                            block162: {
                                block161: {
                                    block160: {
                                        block144: {
                                            block143: {
                                                block138: {
                                                    block137: {
                                                        block136: {
                                                            block135: {
                                                                block133: {
                                                                    var10_1 = new e(this.aR);
                                                                    if (this.aR.j != 0) break block133;
                                                                    var1_2 = 308 * this.aR.a;
                                                                    while (var1_2 >= 0) {
                                                                        if (this.F[var1_2] == -1) {
                                                                            v0 = this.aR.ar;
                                                                            v1 = var1_2;
                                                                            v2 = -10461088;
                                                                        } else {
                                                                            v0 = this.aR.ar;
                                                                            v1 = var1_2;
                                                                            v2 = -16777216;
                                                                        }
                                                                        v0[v1] = v2;
                                                                        --var1_2;
                                                                    }
                                                                    break block134;
                                                                }
                                                                if (this.aR.j != 1 && this.aR.j != 2) break block135;
                                                                var1_2 = 2 * this.a + 2;
                                                                var4_3 = 2;
                                                                while (var4_3 < 77) {
                                                                    var3_4 = 2;
                                                                    while (var3_4 < 102) {
                                                                        if (this.l[var1_2] == 1) {
                                                                            v3 = this.aR;
                                                                            v4 = this.j[var1_2];
                                                                            v5 = this.k[var1_2];
                                                                            v6 = this.c;
                                                                            v7 = this.c;
                                                                            v8 = -10461088;
                                                                        } else {
                                                                            var7_5 = 0;
                                                                            var8_6 = 0;
                                                                            if (this.g[var1_2] > 0.0f) {
                                                                                var7_5 = (int)dust.c(48.0f * this.g[var1_2], 96.0f);
                                                                            }
                                                                            if (this.g[var1_2] < 0.0f) {
                                                                                var8_6 = (int)dust.c(48.0f * -this.g[var1_2], 96.0f);
                                                                            }
                                                                            v3 = this.aR;
                                                                            v4 = this.j[var1_2];
                                                                            v5 = this.k[var1_2];
                                                                            v6 = this.c;
                                                                            v7 = this.c;
                                                                            v8 = -16777216 | var7_5 << 8 | var8_6;
                                                                        }
                                                                        v3.b(v4, v5, v6, v7, v8);
                                                                        ++var3_4;
                                                                        ++var1_2;
                                                                    }
                                                                    ++var4_3;
                                                                    var1_2 += 4;
                                                                }
                                                                if (this.aR.j == 2) {
                                                                    var1_2 = 0;
                                                                    while (var1_2 < this.d) {
                                                                        if (this.l[var1_2] == 0) {
                                                                            var10_1.a(this.e[var1_2]);
                                                                            var13_17 = var10_1.d();
                                                                            if (!(var13_17 < 0.2f)) {
                                                                                var11_8 = this.j[var1_2] + 2;
                                                                                var12_14 = this.k[var1_2] + 2;
                                                                                if (var13_17 > 8.0f) {
                                                                                    var13_17 = 8.0f;
                                                                                }
                                                                                var6_7 = (int)dust.c(48.0f * var13_17, 96.0f);
                                                                                this.aR.a((float)var11_8 + var10_1.a * var13_17 * 10.0f, (float)var12_14 + var10_1.b * var13_17 * 10.0f, (float)var11_8, (float)var12_14, -16777216 | var6_7 << 16);
                                                                            }
                                                                        }
                                                                        ++var1_2;
                                                                    }
                                                                }
                                                                break block134;
                                                            }
                                                            if (this.aR.j != 3) break block136;
                                                            var1_2 = 308 * this.aR.a;
                                                            while (var1_2 >= 3328) {
                                                                if (this.F[var1_2] == -1) {
                                                                    v9 = this.aR.ar;
                                                                    v10 = var1_2;
                                                                    v11 = -10461088;
                                                                } else {
                                                                    var6_7 = (this.aR.ar[var1_2] >> 16 & 255) * 230 >> 8;
                                                                    var7_5 = (this.aR.ar[var1_2] >> 8 & 255) * 230 >> 8;
                                                                    var8_6 = (this.aR.ar[var1_2] & 255) * 230 >> 8;
                                                                    v9 = this.aR.ar;
                                                                    v10 = var1_2;
                                                                    v11 = -16777216 | var6_7 << 16 | var7_5 << 8 | var8_6;
                                                                }
                                                                v9[v10] = v11;
                                                                --var1_2;
                                                            }
                                                            break block134;
                                                        }
                                                        if (this.aR.j != 4) break block137;
                                                        var4_3 = 8;
                                                        while (var4_3 < 308) {
                                                            var5_18 = var4_3 * this.aR.a + 8;
                                                            var3_4 = 8;
                                                            while (var3_4 < 407) {
                                                                var6_7 = (this.aR.ar[var5_18] >> 16 & 255) + (this.aR.ar[var5_18 + 1] >> 16 & 255) >> 1;
                                                                var7_5 = (this.aR.ar[var5_18] >> 8 & 255) + (this.aR.ar[var5_18 + 1] >> 8 & 255) >> 1;
                                                                var8_6 = (this.aR.ar[var5_18] & 255) + (this.aR.ar[var5_18 + 1] & 255) >> 1;
                                                                this.aR.ar[var5_18] = -16777216 | var6_7 << 16 | var7_5 << 8 | var8_6;
                                                                ++var3_4;
                                                                ++var5_18;
                                                            }
                                                            var5_18 = var4_3 * this.aR.a + 407;
                                                            var3_4 = 407;
                                                            while (var3_4 > 8) {
                                                                var6_7 = (this.aR.ar[var5_18] >> 16 & 255) + (this.aR.ar[var5_18 - 1] >> 16 & 255) >> 1;
                                                                var7_5 = (this.aR.ar[var5_18] >> 8 & 255) + (this.aR.ar[var5_18 - 1] >> 8 & 255) >> 1;
                                                                var8_6 = (this.aR.ar[var5_18] & 255) + (this.aR.ar[var5_18 - 1] & 255) >> 1;
                                                                this.aR.ar[var5_18] = -16777216 | var6_7 << 16 | var7_5 << 8 | var8_6;
                                                                --var3_4;
                                                                --var5_18;
                                                            }
                                                            ++var4_3;
                                                        }
                                                        var3_4 = 8;
                                                        while (var3_4 < 408) {
                                                            var5_18 = 8 * this.aR.a + var3_4;
                                                            var4_3 = 8;
                                                            while (var4_3 < 307) {
                                                                var6_7 = (this.aR.ar[var5_18] >> 16 & 255) + (this.aR.ar[var5_18 + this.aR.a] >> 16 & 255) >> 1;
                                                                var7_5 = (this.aR.ar[var5_18] >> 8 & 255) + (this.aR.ar[var5_18 + this.aR.a] >> 8 & 255) >> 1;
                                                                var8_6 = (this.aR.ar[var5_18] & 255) + (this.aR.ar[var5_18 + this.aR.a] & 255) >> 1;
                                                                this.aR.ar[var5_18] = -16777216 | var6_7 << 16 | var7_5 << 8 | var8_6;
                                                                ++var4_3;
                                                                var5_18 += this.aR.a;
                                                            }
                                                            var5_18 = 307 * this.aR.a + var3_4;
                                                            var4_3 = 307;
                                                            while (var4_3 > 8) {
                                                                var6_7 = (this.aR.ar[var5_18] >> 16 & 255) + (this.aR.ar[var5_18 - this.aR.a] >> 16 & 255) >> 1;
                                                                var7_5 = (this.aR.ar[var5_18] >> 8 & 255) + (this.aR.ar[var5_18 - this.aR.a] >> 8 & 255) >> 1;
                                                                var8_6 = (this.aR.ar[var5_18] & 255) + (this.aR.ar[var5_18 - this.aR.a] & 255) >> 1;
                                                                this.aR.ar[var5_18] = -16777216 | var6_7 << 16 | var7_5 << 8 | var8_6;
                                                                --var4_3;
                                                                var5_18 -= this.aR.a;
                                                            }
                                                            ++var3_4;
                                                        }
                                                        var1_2 = 308 * this.aR.a;
                                                        while (var1_2 >= 0) {
                                                            if (this.F[var1_2] == -1) {
                                                                this.aR.ar[var1_2] = -10461088;
                                                            }
                                                            --var1_2;
                                                        }
                                                        break block134;
                                                    }
                                                    if (this.aR.j != 5) break block138;
                                                    var11_9 = this.aR.a * 309;
                                                    var1_2 = 0;
                                                    while (var1_2 < var11_9) {
                                                        this.aR.R[var1_2] = 0;
                                                        this.aR.Q[var1_2] = 0;
                                                        this.aR.P[var1_2] = 0;
                                                        ++var1_2;
                                                    }
                                                    var12_15 = new int[]{1, 1, 1, this.aR.a - 3, 1, 1, 1, this.aR.a - 3, 1, 1, 1, this.aR.a - 3, 1, 1, 1, this.aR.a - 3};
                                                    var5_18 = this.a * 2 + 2;
                                                    var4_3 = 2;
                                                    while (var4_3 < this.b - 2) {
                                                        var3_4 = 2;
                                                        while (var3_4 < this.a - 2) {
                                                            block139: {
                                                                block142: {
                                                                    block141: {
                                                                        block140: {
                                                                            var13_17 = dust.e(this.e[var5_18].a);
                                                                            var14_19 = dust.e(this.e[var5_18].b);
                                                                            if (var13_17 == 0.0f && var14_19 == 0.0f) break block139;
                                                                            var15_20 = 1.0f / (var13_17 + var14_19);
                                                                            var16_21 = (int)(var13_17 * var15_20 * 65535.0f);
                                                                            var17_22 = (int)(var14_19 * var15_20 * 65535.0f);
                                                                            var18_23 = 0;
                                                                            var19_24 = 0;
                                                                            if (this.e[var5_18].a < 0.0f) {
                                                                                v12 = -1;
                                                                            } else if (this.e[var5_18].a > 0.0f) {
                                                                                v12 = var18_23 = 1;
                                                                            }
                                                                            if (!(this.e[var5_18].b < 0.0f)) break block140;
                                                                            v13 = -this.aR.a;
                                                                            break block141;
                                                                        }
                                                                        if (!(this.e[var5_18].b > 0.0f)) break block142;
                                                                        v13 = this.aR.a;
                                                                    }
                                                                    var19_24 = v13;
                                                                }
                                                                var20_25 = (var4_3 << 2) * this.aR.a + (var3_4 << 2);
                                                                var1_2 = 0;
                                                                while (var1_2 < 16) {
                                                                    var21_26 = this.aR.ar[var20_25] >> 16 & 255;
                                                                    v14 = var20_25 + var18_23;
                                                                    this.aR.P[v14] = this.aR.P[v14] + var21_26 * var16_21;
                                                                    v15 = var20_25 + var19_24;
                                                                    this.aR.P[v15] = this.aR.P[v15] + var21_26 * var17_22;
                                                                    var21_26 = this.aR.ar[var20_25] >> 8 & 255;
                                                                    v16 = var20_25 + var18_23;
                                                                    this.aR.Q[v16] = this.aR.Q[v16] + var21_26 * var16_21;
                                                                    v17 = var20_25 + var19_24;
                                                                    this.aR.Q[v17] = this.aR.Q[v17] + var21_26 * var17_22;
                                                                    var21_26 = this.aR.ar[var20_25] & 255;
                                                                    v18 = var20_25 + var18_23;
                                                                    this.aR.R[v18] = this.aR.R[v18] + var21_26 * var16_21;
                                                                    v19 = var20_25 + var19_24;
                                                                    this.aR.R[v19] = this.aR.R[v19] + var21_26 * var17_22;
                                                                    var20_25 += var12_15[var1_2];
                                                                    ++var1_2;
                                                                }
                                                            }
                                                            ++var3_4;
                                                            ++var5_18;
                                                        }
                                                        ++var4_3;
                                                        var5_18 += 4;
                                                    }
                                                    var5_18 = 8 * this.aR.a + 8;
                                                    var4_3 = 8;
                                                    while (var4_3 < 308) {
                                                        var3_4 = 8;
                                                        while (var3_4 < 408) {
                                                            if (this.F[var5_18] == -1) {
                                                                v20 = this.aR.ar;
                                                                v21 = var5_18;
                                                                v22 = -10461088;
                                                            } else {
                                                                v20 = this.aR.ar;
                                                                v21 = var5_18;
                                                                v22 = -16777216 | dust.c(this.aR.P[var5_18] >> 16, 255) << 16 | dust.c(this.aR.Q[var5_18] >> 16, 255) << 8 | dust.c(this.aR.R[var5_18] >> 16, 255);
                                                            }
                                                            v20[v21] = v22;
                                                            ++var3_4;
                                                            ++var5_18;
                                                        }
                                                        ++var4_3;
                                                        var5_18 += 16;
                                                    }
                                                    break block134;
                                                }
                                                if (this.aR.j != 6) break block143;
                                                var1_2 = 308 * this.aR.a;
                                                while (var1_2 >= 3328) {
                                                    if (this.F[var1_2] == -1) {
                                                        v23 = this.aR.ar;
                                                        v24 = var1_2;
                                                        v25 = -10461088;
                                                    } else {
                                                        var6_7 = (this.aR.ar[var1_2] >> 16 & 255) * 220 >> 8;
                                                        var7_5 = (this.aR.ar[var1_2] >> 8 & 255) * 220 >> 8;
                                                        var8_6 = (this.aR.ar[var1_2] & 255) * 220 >> 8;
                                                        v23 = this.aR.ar;
                                                        v24 = var1_2;
                                                        v25 = -16777216 | var6_7 << 16 | var7_5 << 8 | var8_6;
                                                    }
                                                    v23[v24] = v25;
                                                    --var1_2;
                                                }
                                                break block134;
                                            }
                                            if (this.aR.j != 7) break block144;
                                            var1_2 = 308 * this.aR.a;
                                            while (var1_2 >= 2912) {
                                                block159: {
                                                    block146: {
                                                        block151: {
                                                            block149: {
                                                                block158: {
                                                                    block157: {
                                                                        block156: {
                                                                            block155: {
                                                                                block154: {
                                                                                    block153: {
                                                                                        block152: {
                                                                                            block150: {
                                                                                                block148: {
                                                                                                    block147: {
                                                                                                        block145: {
                                                                                                            if (this.F[var1_2] != -1) break block145;
                                                                                                            v26 = this.aR.ar;
                                                                                                            v27 = var1_2;
                                                                                                            v28 = -10461088;
                                                                                                            break block146;
                                                                                                        }
                                                                                                        if (this.F[var1_2] != -2) break block147;
                                                                                                        v26 = this.aR.ar;
                                                                                                        v27 = var1_2;
                                                                                                        v28 = -16777216;
                                                                                                        break block146;
                                                                                                    }
                                                                                                    if (this.F[var1_2] != -4) break block148;
                                                                                                    v26 = this.aR.ar;
                                                                                                    v27 = var1_2;
                                                                                                    v28 = -8355585;
                                                                                                    break block146;
                                                                                                }
                                                                                                if (this.F[var1_2] != -5) break block149;
                                                                                                if (this.F[var1_2 + 1] < 0) break block150;
                                                                                                v26 = this.aR.ar;
                                                                                                v27 = var1_2;
                                                                                                v29 = this.v;
                                                                                                v30 = this.A;
                                                                                                v31 = this.F;
                                                                                                v32 = var1_2 + 1;
                                                                                                break block151;
                                                                                            }
                                                                                            if (this.F[var1_2 - 1] < 0) break block152;
                                                                                            v26 = this.aR.ar;
                                                                                            v27 = var1_2;
                                                                                            v29 = this.v;
                                                                                            v30 = this.A;
                                                                                            v31 = this.F;
                                                                                            v32 = var1_2 - 1;
                                                                                            break block151;
                                                                                        }
                                                                                        if (this.F[var1_2 + this.aR.a] < 0) break block153;
                                                                                        v26 = this.aR.ar;
                                                                                        v27 = var1_2;
                                                                                        v29 = this.v;
                                                                                        v30 = this.A;
                                                                                        v31 = this.F;
                                                                                        v32 = var1_2 + this.aR.a;
                                                                                        break block151;
                                                                                    }
                                                                                    if (this.F[var1_2 - this.aR.a] < 0) break block154;
                                                                                    v26 = this.aR.ar;
                                                                                    v27 = var1_2;
                                                                                    v29 = this.v;
                                                                                    v30 = this.A;
                                                                                    v31 = this.F;
                                                                                    v32 = var1_2 - this.aR.a;
                                                                                    break block151;
                                                                                }
                                                                                if (this.F[var1_2 + this.aR.a + 1] < 0) break block155;
                                                                                v26 = this.aR.ar;
                                                                                v27 = var1_2;
                                                                                v29 = this.v;
                                                                                v30 = this.A;
                                                                                v31 = this.F;
                                                                                v32 = var1_2 + this.aR.a + 1;
                                                                                break block151;
                                                                            }
                                                                            if (this.F[var1_2 + this.aR.a - 1] < 0) break block156;
                                                                            v26 = this.aR.ar;
                                                                            v27 = var1_2;
                                                                            v29 = this.v;
                                                                            v30 = this.A;
                                                                            v31 = this.F;
                                                                            v32 = var1_2 + this.aR.a - 1;
                                                                            break block151;
                                                                        }
                                                                        if (this.F[var1_2 - this.aR.a + 1] < 0) break block157;
                                                                        v26 = this.aR.ar;
                                                                        v27 = var1_2;
                                                                        v29 = this.v;
                                                                        v30 = this.A;
                                                                        v31 = this.F;
                                                                        v32 = var1_2 - this.aR.a + 1;
                                                                        break block151;
                                                                    }
                                                                    if (this.F[var1_2 - this.aR.a - 1] < 0) break block158;
                                                                    v26 = this.aR.ar;
                                                                    v27 = var1_2;
                                                                    v29 = this.v;
                                                                    v30 = this.A;
                                                                    v31 = this.F;
                                                                    v32 = var1_2 - this.aR.a - 1;
                                                                    break block151;
                                                                }
                                                                v26 = this.aR.ar;
                                                                v27 = var1_2;
                                                                v28 = -16777216;
                                                                break block146;
                                                            }
                                                            if (this.F[var1_2] < 0) break block159;
                                                            v26 = this.aR.ar;
                                                            v27 = var1_2;
                                                            v29 = this.v;
                                                            v30 = this.A;
                                                            v31 = this.F;
                                                            v32 = var1_2;
                                                        }
                                                        v28 = v29[v30[v31[v32]]][0];
                                                    }
                                                    v26[v27] = v28;
                                                }
                                                --var1_2;
                                            }
                                            var1_2 = 308 * this.aR.a;
                                            while (var1_2 >= 3328) {
                                                if (this.aR.ar[var1_2] == -16777216 && (this.aR.ar[var1_2 + 1] != -16777216 && this.aR.ar[var1_2 + 1] != -1118482 || this.aR.ar[var1_2 - 1] != -16777216 && this.aR.ar[var1_2 - 1] != -1118482 || this.aR.ar[var1_2 + this.aR.a] != -16777216 && this.aR.ar[var1_2 + this.aR.a] != -1118482 || this.aR.ar[var1_2 - this.aR.a] != -16777216 && this.aR.ar[var1_2 - this.aR.a] != -1118482)) {
                                                    this.aR.ar[var1_2] = -1118482;
                                                }
                                                --var1_2;
                                            }
                                            break block134;
                                        }
                                        if (this.aR.j != 8) break block160;
                                        var1_2 = 308 * this.aR.a;
                                        while (var1_2 >= 0) {
                                            if (this.F[var1_2] == -1) {
                                                v33 = this.aR.ar;
                                                v34 = var1_2;
                                                v35 = -10461088;
                                            } else {
                                                v33 = this.aR.ar;
                                                v34 = var1_2;
                                                v35 = -16777216;
                                            }
                                            v33[v34] = v35;
                                            --var1_2;
                                        }
                                        var1_2 = 2 * this.a + 2;
                                        var4_3 = 2;
                                        while (var4_3 < 77) {
                                            var3_4 = 2;
                                            while (var3_4 < 102) {
                                                if (this.l[var1_2] == 0) {
                                                    var10_1.a(this.e[var1_2]);
                                                    var15_20 = var10_1.a();
                                                    if (!(var15_20 < 0.2f)) {
                                                        if (var15_20 > 2.0f) {
                                                            var15_20 = 2.0f;
                                                        }
                                                        var7_5 = (int)dust.c(48.0f * var15_20, 96.0f);
                                                        var6_7 = 0;
                                                        if (this.g[var1_2] > 0.0f) {
                                                            var6_7 = (int)dust.c(48.0f * this.g[var1_2] * var15_20, 96.0f);
                                                        }
                                                        var8_6 = 0;
                                                        if (this.g[var1_2] < 0.0f) {
                                                            var8_6 = (int)dust.c(48.0f * -this.g[var1_2] * var15_20, 96.0f);
                                                        }
                                                        var11_10 = (float)this.j[var1_2] + this.e[var1_2].a * 5.0f;
                                                        var12_16 = (float)this.k[var1_2] + this.e[var1_2].b * 5.0f;
                                                        var13_17 = (float)this.j[var1_2 + 1] + this.e[var1_2 + 1].a * 5.0f;
                                                        var14_19 = (float)this.k[var1_2 + 1] + this.e[var1_2 + 1].b * 5.0f;
                                                        this.aR.a(var11_10, var12_16, var13_17, var14_19, -16777216 | var6_7 << 16 | var7_5 << 8 | var8_6);
                                                        var13_17 = (float)this.j[var1_2 + this.a] + this.e[var1_2 + this.a].a * 5.0f;
                                                        var14_19 = (float)this.k[var1_2 + this.a] + this.e[var1_2 + this.a].b * 5.0f;
                                                        this.aR.a(var11_10, var12_16, var13_17, var14_19, -16777216 | var6_7 << 16 | var7_5 << 8 | var8_6);
                                                    }
                                                }
                                                ++var3_4;
                                                ++var1_2;
                                            }
                                            ++var4_3;
                                            var1_2 += 4;
                                        }
                                        break block134;
                                    }
                                    if (this.aR.j != 9) break block161;
                                    var1_2 = 2 * this.a + 2;
                                    var4_3 = 2;
                                    while (var4_3 < 77) {
                                        var3_4 = 2;
                                        while (var3_4 < 102) {
                                            if (this.l[var1_2] == 1) {
                                                v36 = this.aR;
                                                v37 = this.j[var1_2];
                                                v38 = this.k[var1_2];
                                                v39 = this.c;
                                                v40 = this.c;
                                                v41 = -10461088;
                                            } else {
                                                var6_7 = 0;
                                                if (this.g[var1_2] > 0.0f) {
                                                    var6_7 = (int)dust.c(48.0f * this.g[var1_2], 72.0f);
                                                }
                                                if (this.g[var1_2] < 0.0f) {
                                                    var6_7 = (int)dust.c(48.0f * -this.g[var1_2], 24.0f);
                                                }
                                                v36 = this.aR;
                                                v37 = this.j[var1_2];
                                                v38 = this.k[var1_2];
                                                v39 = this.c;
                                                v40 = this.c;
                                                v41 = -16777216 | var6_7 << 16 | var6_7 << 8 | var6_7;
                                            }
                                            v36.b(v37, v38, v39, v40, v41);
                                            ++var3_4;
                                            ++var1_2;
                                        }
                                        ++var4_3;
                                        var1_2 += 4;
                                    }
                                    break block134;
                                }
                                if (this.aR.j != 10) break block162;
                                v42 = new int[16];
                                v42[1] = 1;
                                v42[2] = 2;
                                v42[3] = 3;
                                v42[4] = this.aR.a;
                                v42[5] = this.aR.a + 1;
                                v42[6] = this.aR.a + 2;
                                v42[7] = this.aR.a + 3;
                                v42[8] = this.aR.a * 2;
                                v42[9] = this.aR.a * 2 + 1;
                                v42[10] = this.aR.a * 2 + 2;
                                v42[11] = this.aR.a * 2 + 3;
                                v42[12] = this.aR.a * 3;
                                v42[13] = this.aR.a * 3 + 1;
                                v42[14] = this.aR.a * 3 + 2;
                                v42[15] = this.aR.a * 3 + 3;
                                var11_11 = v42;
                                var1_2 = 2 * this.a + 2;
                                var4_3 = 2;
                                while (var4_3 < 77) {
                                    var3_4 = 2;
                                    while (var3_4 < 102) {
                                        if (this.l[var1_2] == 1) {
                                            this.aR.b(this.j[var1_2], this.k[var1_2], this.c, this.c, -10461088);
                                        } else {
                                            var9_28 = 256 - (int)dust.c(dust.e(this.g[var1_2] * 12.0f), 32.0f);
                                            if (var9_28 != 256) {
                                                var5_18 = (var4_3 << 2) * this.aR.a + (var3_4 << 2);
                                                var2_27 = 0;
                                                while (var2_27 < 16) {
                                                    var6_7 = (this.aR.ar[var5_18 + var11_11[var2_27]] >> 16 & 255) * var9_28 >> 8;
                                                    var7_5 = (this.aR.ar[var5_18 + var11_11[var2_27]] >> 8 & 255) * var9_28 >> 8;
                                                    var8_6 = (this.aR.ar[var5_18 + var11_11[var2_27]] & 255) * var9_28 >> 8;
                                                    this.aR.ar[var5_18 + var11_11[var2_27]] = -16777216 | var6_7 << 16 | var7_5 << 8 | var8_6;
                                                    ++var2_27;
                                                }
                                            }
                                        }
                                        ++var3_4;
                                        ++var1_2;
                                    }
                                    ++var4_3;
                                    var1_2 += 4;
                                }
                                break block134;
                            }
                            if (this.aR.j != 11) break block163;
                            var1_2 = 308 * this.aR.a;
                            while (var1_2 >= 0) {
                                if (this.F[var1_2] < 0) ** GOTO lbl-1000
                                if (this.A[this.F[var1_2]] == 4) {
                                    v43 = this.aR.P;
                                    v44 = var1_2;
                                    v45 = 25500;
                                } else if (this.A[this.F[var1_2]] == 20) {
                                    v43 = this.aR.P;
                                    v44 = var1_2;
                                    v45 = 25500;
                                } else if (this.A[this.F[var1_2]] == 25) {
                                    v43 = this.aR.P;
                                    v44 = var1_2;
                                    v45 = 255000;
                                } else if (this.A[this.F[var1_2]] == 28) {
                                    v43 = this.aR.P;
                                    v44 = var1_2;
                                    v45 = 255000;
                                } else if (this.A[this.F[var1_2]] == 33) {
                                    v43 = this.aR.P;
                                    v44 = var1_2;
                                    v45 = 25500;
                                } else if (this.A[this.F[var1_2]] == 42) {
                                    v43 = this.aR.P;
                                    v44 = var1_2;
                                    v45 = 25500;
                                } else lbl-1000:
                                // 2 sources

                                {
                                    v43 = this.aR.P;
                                    v44 = var1_2;
                                    v45 = this.aR.P[var1_2] * 8 / 9;
                                }
                                v43[v44] = v45;
                                --var1_2;
                            }
                            var1_2 = 308 * this.aR.a;
                            while (var1_2 >= 0) {
                                if (this.F[var1_2] == -1) {
                                    v46 = this.aR.ar;
                                    v47 = var1_2;
                                    v48 = -10461088;
                                } else {
                                    v46 = this.aR.ar;
                                    v47 = var1_2;
                                    v48 = -16777216;
                                }
                                v46[v47] = v48;
                                --var1_2;
                            }
                            break block134;
                        }
                        if (this.aR.j != 12) break block164;
                        var1_2 = 0;
                        while (var1_2 < this.D) {
                            this.aR.P[this.G[var1_2]] = this.x[this.A[var1_2]];
                            ++var1_2;
                        }
                        var4_3 = 8;
                        while (var4_3 < 308) {
                            var5_18 = var4_3 * this.aR.a + 8;
                            var3_4 = 8;
                            while (var3_4 < 407) {
                                v49 = (this.aR.P[var5_18] + this.aR.P[var5_18 + 1]) / 2;
                                this.aR.P[var5_18 + 1] = v49;
                                this.aR.P[var5_18] = v49;
                                ++var3_4;
                                ++var5_18;
                            }
                            var3_4 = 407;
                            while (var3_4 > 8) {
                                v50 = (this.aR.P[var5_18] + this.aR.P[var5_18 - 1]) / 2;
                                this.aR.P[var5_18 - 1] = v50;
                                this.aR.P[var5_18] = v50;
                                --var3_4;
                                --var5_18;
                            }
                            ++var4_3;
                        }
                        var3_4 = 8;
                        while (var3_4 < 408) {
                            var5_18 = 8 * this.aR.a + var3_4;
                            var4_3 = 8;
                            while (var4_3 < 307) {
                                v51 = (this.aR.P[var5_18] + this.aR.P[var5_18 + this.aR.a]) / 2;
                                this.aR.P[var5_18 + this.aR.a] = v51;
                                this.aR.P[var5_18] = v51;
                                ++var4_3;
                                var5_18 += this.aR.a;
                            }
                            var4_3 = 307;
                            while (var4_3 > 8) {
                                v52 = (this.aR.P[var5_18] + this.aR.P[var5_18 - this.aR.a]) / 2;
                                this.aR.P[var5_18 - this.aR.a] = v52;
                                this.aR.P[var5_18] = v52;
                                --var4_3;
                                var5_18 -= this.aR.a;
                            }
                            ++var3_4;
                        }
                        var1_2 = 308 * this.aR.a;
                        while (var1_2 >= 0) {
                            block166: {
                                block169: {
                                    block167: {
                                        block173: {
                                            block172: {
                                                block171: {
                                                    block170: {
                                                        block168: {
                                                            block165: {
                                                                var11_12 = this.aR.P[var1_2];
                                                                if (var11_12 >= 0) break block165;
                                                                var6_7 = 128 * -var11_12 >> 10;
                                                                if (var6_7 > 255) {
                                                                    var6_7 = 255;
                                                                }
                                                                var7_5 = 0;
                                                                var8_6 = 255 * -var11_12 >> 10;
                                                                if (var8_6 <= 255) break block166;
                                                                break block167;
                                                            }
                                                            if (var11_12 >= 1024) break block168;
                                                            var6_7 = 0;
                                                            var7_5 = 0;
                                                            v53 = 255 * var11_12 >> 10;
                                                            break block169;
                                                        }
                                                        if (var11_12 >= 2048) break block170;
                                                        var6_7 = 0;
                                                        var7_5 = 255 * (var11_12 - 1024) >> 10;
                                                        break block167;
                                                    }
                                                    if (var11_12 >= 3072) break block171;
                                                    var6_7 = 0;
                                                    var7_5 = 255;
                                                    v53 = 255 - (255 * (var11_12 - 2048) >> 10);
                                                    break block169;
                                                }
                                                if (var11_12 >= 4096) break block172;
                                                var6_7 = 255 * (var11_12 - 3072) >> 10;
                                                var7_5 = 255;
                                                v53 = 0;
                                                break block169;
                                            }
                                            if (var11_12 >= 6144) break block173;
                                            var6_7 = 255;
                                            var7_5 = 255 - (255 * (var11_12 - 4096) >> 11);
                                            v53 = 0;
                                            break block169;
                                        }
                                        var6_7 = 255;
                                        var7_5 = 255 * (var11_12 - 6144) >> 11;
                                        if (var7_5 > 255) {
                                            var7_5 = 255;
                                        }
                                        if ((var8_6 = 255 * (var11_12 - 6144) >> 11) <= 255) break block166;
                                    }
                                    v53 = 255;
                                }
                                var8_6 = v53;
                            }
                            this.aR.ar[var1_2] = -16777216 | var6_7 << 16 | var7_5 << 8 | var8_6;
                            --var1_2;
                        }
                        var1_2 = 308 * this.aR.a;
                        while (var1_2 >= 0) {
                            if (this.F[var1_2] == -1) {
                                this.aR.ar[var1_2] = -10461088;
                            }
                            --var1_2;
                        }
                        break block134;
                    }
                    if (this.aR.j != 13) break block134;
                    var1_2 = 308 * this.aR.a;
                    while (var1_2 >= 3328) {
                        block176: {
                            block175: {
                                block174: {
                                    if (this.F[var1_2] != -1) break block174;
                                    v54 = this.aR.ar;
                                    v55 = var1_2;
                                    v56 = -16777216;
                                    break block175;
                                }
                                if (this.F[var1_2] != -5) break block176;
                                var6_7 = 255 - (255 - (this.aR.ar[var1_2] >> 16 & 255) >> 1);
                                var7_5 = 255 - (255 - (this.aR.ar[var1_2] >> 8 & 255) >> 1);
                                var8_6 = 255 - (255 - (this.aR.ar[var1_2] & 255) >> 1);
                                v54 = this.aR.ar;
                                v55 = var1_2;
                                v56 = -16777216 | var6_7 << 16 | var7_5 << 8 | var8_6;
                            }
                            v54[v55] = v56;
                        }
                        --var1_2;
                    }
                }
                if (this.aR.v <= 1) break block177;
                v57 = new int[8];
                v57[2] = 100;
                v57[3] = 50;
                v57[4] = 25;
                v57[5] = 16;
                v57[6] = 8;
                v57[7] = 4;
                var11_13 = v57;
                v58 = 0;
                while (v58 < 400) {
                    var4_3 = 0;
                    v59 = 8 * this.aR.a + var1_2;
                    v60 = 8;
                    if (true) ** GOTO lbl709
                    do {
                        if (this.aR.ar[var5_18] != -10461088) {
                            this.aR.ar[var5_18] = -12566464;
                        }
                        ++var4_3;
                        v59 = var5_18;
                        v60 = this.aR.a;
lbl709:
                        // 2 sources

                        var5_18 = v59 + v60;
                    } while (var4_3 < 300);
                    v58 = var1_2 = var1_2 + var11_13[this.aR.v];
                }
                v61 = 0;
                while (v61 < 300) {
                    var3_4 = 0;
                    var5_18 = (var1_2 + 8) * this.aR.a + 8;
                    while (var3_4 < 400) {
                        if (this.aR.ar[var5_18] != -10461088) {
                            this.aR.ar[var5_18] = -12566464;
                        }
                        ++var3_4;
                        ++var5_18;
                    }
                    v61 = var1_2 = var1_2 + var11_13[this.aR.v];
                }
            }
            if (this.aR.v <= 0) break block178;
            var4_3 = 0;
            v62 = 8 * this.aR.a + 200;
            v63 = 8;
            if (true) ** GOTO lbl737
            do {
                if (this.aR.ar[var5_18] != -10461088) {
                    this.aR.ar[var5_18] = -12582912;
                }
                ++var4_3;
                v62 = var5_18;
                v63 = this.aR.a;
lbl737:
                // 2 sources

                var5_18 = v62 + v63;
            } while (var4_3 < 300);
            var3_4 = 0;
            var5_18 = 158 * this.aR.a + 8;
            while (var3_4 < 400) {
                if (this.aR.ar[var5_18] != -10461088) {
                    this.aR.ar[var5_18] = -12582912;
                }
                ++var3_4;
                ++var5_18;
            }
        }
        this.l();
        this.p();
        this.t();
        this.w();
        this.z();
        if (this.aR.j == 11) {
            var4_3 = 8;
            while (var4_3 < 308) {
                var5_18 = var4_3 * this.aR.a + 8;
                var3_4 = 8;
                while (var3_4 < 407) {
                    this.aR.P[var5_18] = this.aR.P[var5_18] + this.aR.P[var5_18 + 1] >> 1;
                    ++var3_4;
                    ++var5_18;
                }
                var3_4 = 407;
                while (var3_4 > 8) {
                    this.aR.P[var5_18] = this.aR.P[var5_18] + this.aR.P[var5_18 - 1] >> 1;
                    --var3_4;
                    --var5_18;
                }
                ++var4_3;
            }
            var3_4 = 8;
            while (var3_4 < 408) {
                var5_18 = 8 * this.aR.a + var3_4;
                var4_3 = 8;
                while (var4_3 < 307) {
                    this.aR.P[var5_18] = this.aR.P[var5_18] + this.aR.P[var5_18 + this.aR.a] >> 1;
                    ++var4_3;
                    var5_18 += this.aR.a;
                }
                var4_3 = 307;
                while (var4_3 > 8) {
                    this.aR.P[var5_18] = this.aR.P[var5_18] + this.aR.P[var5_18 - this.aR.a] >> 1;
                    --var4_3;
                    var5_18 -= this.aR.a;
                }
                ++var3_4;
            }
            var1_2 = 308 * this.aR.a;
            while (var1_2 >= 0) {
                if (this.aR.P[var1_2] < 1) {
                    v64 = this.aR.ar;
                    v65 = var1_2;
                    v66 = -16777216;
                } else {
                    var9_28 = dust.c(this.aR.P[var1_2], 255);
                    var6_7 = (this.aR.ar[var1_2] >> 16 & 255) * var9_28 >> 8;
                    var7_5 = (this.aR.ar[var1_2] >> 8 & 255) * var9_28 >> 8;
                    var8_6 = (this.aR.ar[var1_2] & 255) * var9_28 >> 8;
                    v64 = this.aR.ar;
                    v65 = var1_2;
                    v66 = -16777216 | var6_7 << 16 | var7_5 << 8 | var8_6;
                }
                v64[v65] = v66;
                --var1_2;
            }
        }
        this.i();
    }

    private void i() {
        block9: {
            block10: {
                int n;
                int n2;
                int n3;
                int n4;
                int n5;
                dust dust2;
                block12: {
                    int n6;
                    int n7;
                    int n8;
                    int n9;
                    block11: {
                        e e2 = new e(this.aR);
                        if (this.aR.e || this.aR.u != 0) break block9;
                        if (this.aR.c == 50 || this.aR.c == 51 || this.aR.c == 52 || this.aR.d == 50 || this.aR.d == 51 || this.aR.d == 52) {
                            n9 = (this.o >> 2) - 1 - this.aR.f / 2;
                            n8 = (this.p >> 2) - 1 - this.aR.f / 2;
                            int[] nArray = new int[11];
                            nArray[1] = 1;
                            nArray[2] = 1;
                            nArray[3] = 1;
                            nArray[4] = 2;
                            nArray[5] = 2;
                            nArray[6] = 2;
                            nArray[7] = 3;
                            nArray[8] = 3;
                            nArray[9] = 3;
                            nArray[10] = 4;
                            int[] nArray2 = nArray;
                            int[] nArray3 = new int[11];
                            nArray3[1] = 1;
                            nArray3[2] = 1;
                            nArray3[3] = 1;
                            nArray3[4] = 1;
                            nArray3[5] = 1;
                            nArray3[6] = 1;
                            nArray3[7] = 1;
                            nArray3[8] = 1;
                            nArray3[9] = 1;
                            nArray3[10] = 1;
                            int[] nArray4 = nArray3;
                            int[][] nArrayArray = new int[][]{new int[0], {1, 1, 1, 2, 2, 2, 3, 3, 3, 4, 4, 4}, {1, 1, 1, 1, 1, 1, 1, 2, 2, 2, 2, 2, 2, 2, 3, 3, 3, 3, 3, 3, 3, 4, 4, 4, 4, 4, 4, 4}, {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4}, {1, 1, 1, 1, 1, 1, 1, 2, 2, 2, 2, 1, 1, 1, 1, 2, 2, 2, 2, 2, 2, 2, 3, 3, 3, 3, 2, 2, 2, 2, 3, 3, 3, 3, 3, 3, 3, 4, 4, 4, 4, 3, 3, 3, 3, 4, 4, 4, 4, 4, 4, 4, 1, 1, 1, 1, 4, 4, 4, 4}, {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 2, 2, 2, 1, 1, 1, 1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 3, 3, 3, 3, 2, 2, 2, 2, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 4, 4, 4, 4, 3, 3, 3, 3, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 1, 1, 1, 1, 4, 4, 4, 4}, {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 2, 2, 2, 1, 1, 1, 1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 3, 3, 3, 3, 2, 2, 2, 2, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 4, 4, 4, 4, 3, 3, 3, 3, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 1, 1, 1, 1, 4, 4, 4, 4}, {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 2, 2, 2, 1, 1, 1, 1, 2, 2, 2, 2, 1, 1, 1, 1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 3, 3, 3, 3, 2, 2, 2, 2, 3, 3, 3, 3, 2, 2, 2, 2, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 4, 4, 4, 4, 3, 3, 3, 3, 4, 4, 4, 4, 3, 3, 3, 3, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 1, 1, 1, 1, 4, 4, 4, 4, 1, 1, 1, 1, 4, 4, 4, 4}, {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 2, 2, 2, 1, 1, 1, 1, 2, 2, 2, 2, 1, 1, 1, 1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 3, 3, 3, 3, 2, 2, 2, 2, 3, 3, 3, 3, 2, 2, 2, 2, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 4, 4, 4, 4, 3, 3, 3, 3, 4, 4, 4, 4, 3, 3, 3, 3, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 1, 1, 1, 1, 4, 4, 4, 4, 1, 1, 1, 1, 4, 4, 4, 4}, {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 2, 2, 2, 1, 1, 1, 1, 2, 2, 2, 2, 1, 1, 1, 1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 3, 3, 3, 3, 2, 2, 2, 2, 3, 3, 3, 3, 2, 2, 2, 2, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 4, 4, 4, 4, 3, 3, 3, 3, 4, 4, 4, 4, 3, 3, 3, 3, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 1, 1, 1, 1, 4, 4, 4, 4, 1, 1, 1, 1, 4, 4, 4, 4}, {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 2, 2, 2, 1, 1, 1, 1, 1, 1, 1, 1, 2, 2, 2, 2, 2, 2, 2, 2, 1, 1, 1, 1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 3, 3, 3, 3, 2, 2, 2, 2, 2, 2, 2, 2, 3, 3, 3, 3, 3, 3, 3, 3, 2, 2, 2, 2, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 4, 4, 4, 4, 3, 3, 3, 3, 3, 3, 3, 3, 4, 4, 4, 4, 4, 4, 4, 4, 3, 3, 3, 3, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 1, 1, 1, 1, 4, 4, 4, 4, 4, 4, 4, 4, 1, 1, 1, 1, 1, 1, 1, 1, 4, 4, 4, 4}};
                            int n10 = this.aR.f;
                            n7 = (n9 + nArray2[n10]) * this.c;
                            n6 = (n8 + nArray4[n10]) * this.c;
                            int n11 = 0;
                            while (n11 < nArrayArray[n10].length) {
                                int n12 = dust.a(n6, 0, 308) * this.aR.a + dust.a(n7, 0, this.aR.a - 1);
                                this.aR.ar[n12] = -4194304;
                                if (nArrayArray[n10][n11] == 1) {
                                    ++n7;
                                }
                                if (nArrayArray[n10][n11] == 2) {
                                    ++n6;
                                }
                                if (nArrayArray[n10][n11] == 3) {
                                    --n7;
                                }
                                if (nArrayArray[n10][n11] == 4) {
                                    --n6;
                                }
                                ++n11;
                            }
                        }
                        if (this.aR.c == 5 || this.aR.d == 5 || this.aR.c == 40 || this.aR.d == 40 || this.aR.c == 23 || this.aR.d == 23) {
                            e2.a(this.q, 30.0f);
                            this.aR.a((float)this.m + e2.a, (float)this.n + e2.b, (float)this.m, (float)this.n, -65536);
                        }
                        if (this.aR.c != 53 && this.aR.d != 53) break block10;
                        if (this.aR.n != 0) break block11;
                        if ((this.aR.c != 53 || !this.aR.aJ) && (this.aR.d != 53 || !this.aR.aN)) break block10;
                        this.aR.a(this.aR.o, this.aR.p, this.aR.q, this.aR.p, -16192);
                        this.aR.a(this.aR.o, this.aR.r, this.aR.q, this.aR.r, -16192);
                        this.aR.a(this.aR.o, this.aR.p, this.aR.o, this.aR.r, -16192);
                        dust2 = this.aR;
                        n5 = this.aR.q;
                        n4 = this.aR.p;
                        n3 = this.aR.q;
                        n2 = this.aR.r;
                        n = -16192;
                        break block12;
                    }
                    n7 = this.m - (this.aR.q - this.aR.o) / 2;
                    n6 = this.n - (this.aR.r - this.aR.p) / 2;
                    n9 = this.aR.q - this.aR.o;
                    n8 = this.aR.r - this.aR.p;
                    this.aR.a(n7, n6, n7 + n9, n6, -4144897);
                    this.aR.a(n7, n6 + n8, n7 + n9, n6 + n8, -4144897);
                    this.aR.a(n7, n6, n7, n6 + n8, -4144897);
                    dust2 = this.aR;
                    n5 = n7 + n9;
                    n4 = n6;
                    n3 = n7 + n9;
                    n2 = n6 + n8;
                    n = -4144897;
                }
                dust2.a(n5, n4, n3, n2, n);
            }
            if (this.aR.c == 54 || this.aR.d == 54) {
                this.aR.a(this.aR.V, this.aR.W, this.aR.V, this.aR.W + 13, -4194304);
                this.aR.a(this.aR.V, this.aR.W, this.aR.V + 200, this.aR.W, -4194304);
                this.aR.a(this.aR.V, this.aR.W + 13, this.aR.V + 200, this.aR.W + 13, -4194304);
            }
            if (this.aR.z == 1 && (this.aR.aJ && (this.aR.c < 34 || this.aR.c == 50 || this.aR.c == 51 || this.aR.c == 52) || this.aR.aN && (this.aR.d < 34 || this.aR.d == 50 || this.aR.d == 51 || this.aR.d == 52))) {
                this.aR.a(this.aR.B, this.aR.C, this.m, this.n, -65536);
            }
        }
    }

    private void j() {
        this.D = 0;
        this.E = 40000;
        this.y = new e[this.E];
        this.z = new e[this.E];
        this.A = new int[this.E];
        this.B = new int[this.E];
        this.C = new byte[this.E];
        this.F = new int[this.aR.a * 316];
        this.G = new int[this.E];
        this.H = new boolean[this.E];
        int n = 0;
        while (n < this.E) {
            this.y[n] = new e(this.aR, 0.0f, 0.0f);
            ++n;
        }
        n = 0;
        while (n < this.E) {
            this.z[n] = new e(this.aR, 0.0f, 0.0f);
            ++n;
        }
        n = 0;
        while (n < this.aR.a * 316) {
            this.F[n] = -5;
            ++n;
        }
        n = 0;
        while (n < this.E) {
            this.H[n] = false;
            ++n;
        }
    }

    final int a(float f, float f2, int n) {
        if (this.D >= this.aR.h[this.aR.g]) {
            return -1;
        }
        if (f < 7.0f || f >= 409.0f || f2 < 7.0f || f2 >= 309.0f) {
            return -1;
        }
        this.y[this.D].a(f, f2);
        this.z[this.D].a(0.0f, 0.0f);
        this.A[this.D] = n;
        this.B[this.D] = 0;
        this.C[this.D] = 0;
        this.H[this.D] = false;
        this.G[this.D] = (int)f2 * this.aR.a + (int)f;
        this.F[this.G[this.D]] = this.D;
        ++this.D;
        return this.D - 1;
    }

    private void c(int n) {
        if (this.D == 0) {
            return;
        }
        this.F[this.G[n]] = -5;
        --this.D;
        if (this.D == n) {
            return;
        }
        this.y[n].a(this.y[this.D]);
        this.z[n].a(this.z[this.D]);
        this.A[n] = this.A[this.D];
        this.B[n] = this.B[this.D];
        this.C[n] = this.C[this.D];
        this.H[n] = this.H[this.D];
        this.G[n] = this.G[this.D];
        if (this.A[n] == 8) {
            this.F[this.G[n]] = -4;
            return;
        }
        this.F[this.G[n]] = n;
    }

    private void b(int n, int n2, int n3, int n4) {
        e e2 = new e(this.aR);
        e2.a(this.y[n]);
        this.y[n].a(this.y[n2]);
        this.y[n2].a(e2);
        int n5 = this.F[n3];
        this.F[n3] = this.F[n4];
        this.F[n4] = n5;
        n5 = this.G[n];
        this.G[n] = this.G[n2];
        this.G[n2] = n5;
    }

    private void a(int n, float f, float f2) {
        this.F[this.G[n]] = -5;
        this.y[n].a(f, f2);
        this.G[n] = (int)f2 * this.aR.a + (int)f;
        this.F[this.G[n]] = n;
    }

    private int a(int n, e e2) {
        e2.a(3.8f / (e2.a() + 1.0f));
        int n2 = (int)this.y[n].b * this.aR.a + (int)(this.y[n].a + e2.a);
        if (this.F[n2] <= -4) {
            this.y[n].a += e2.a;
        }
        if (this.F[n2 = (int)(this.y[n].b + e2.b) * this.aR.a + (int)this.y[n].a] <= -4) {
            this.y[n].b += e2.b;
        }
        this.G[n] = (int)this.y[n].b * this.aR.a + (int)this.y[n].a;
        this.F[this.G[n]] = n;
        return this.G[n];
    }

    private void b(int n, e e2) {
        if (this.aR.e || this.aR.u != 0) {
            return;
        }
        if (!this.H[n]) {
            if (this.aR.c == 42 && this.aR.aH || this.aR.d == 42 && this.aR.aL) {
                if (this.A[n] == 8) {
                    return;
                }
                e2.a = (float)this.m - this.y[n].a;
                e2.b = (float)this.n - this.y[n].b;
                if (e2.a() < (float)(this.aR.f * 4)) {
                    this.H[n] = true;
                    return;
                }
            }
        } else {
            if (this.aR.c == 42 && this.aR.aJ || this.aR.d == 42 && this.aR.aN) {
                this.z[n].a += ((float)this.m - this.y[n].a) * 0.1f;
                this.z[n].b += ((float)this.n - this.y[n].b) * 0.1f;
                return;
            }
            this.H[n] = false;
        }
    }

    /*
     * Unable to fully structure code
     */
    private void k() {
        block16: {
            var2_1 = new e(this.aR);
            this.n();
            var1_2 = 0;
            while (var1_2 < this.D) {
                this.b(var1_2, var2_1);
                if (this.A[var1_2] <= 17) {
                    v0 = var1_2;
                    v1 = this.c(var1_2, var2_1);
                } else if (this.A[var1_2] <= 29) {
                    v0 = var1_2;
                    v1 = this.d(var1_2, var2_1);
                } else if (this.A[var1_2] <= 41) {
                    v0 = var1_2;
                    v1 = this.e(var1_2, var2_1);
                } else {
                    v0 = var1_2;
                    v1 = this.f(var1_2, var2_1);
                }
                var1_2 = v0 - v1;
                ++var1_2;
            }
            if (this.aR.y == 0) {
                var1_2 = 0;
                while (var1_2 < this.D) {
                    if (this.y[var1_2].a < 8.0f || this.y[var1_2].a >= 408.0f || this.y[var1_2].b < 8.0f || this.y[var1_2].b >= 308.0f) {
                        this.c(var1_2--);
                    }
                    ++var1_2;
                }
                return;
            }
            if (this.aR.y != 1) break block16;
            var1_2 = 0;
            while (var1_2 < this.D) {
                block19: {
                    block22: {
                        block23: {
                            block20: {
                                block21: {
                                    block17: {
                                        block18: {
                                            if (!(this.y[var1_2].a < 8.0f)) break block17;
                                            var3_3 = this.G[var1_2] + 400;
                                            if (this.F[var3_3] > -4 || this.y[var1_2].b < 8.0f || this.y[var1_2].b >= 308.0f) break block18;
                                            this.F[this.G[var1_2]] = -5;
                                            this.y[var1_2].a += 400.0f;
                                            this.F[var3_3] = var1_2;
                                            this.G[var1_2] = var3_3;
                                            break block19;
                                        }
                                        v2 = this;
                                        ** GOTO lbl79
                                    }
                                    if (!(this.y[var1_2].a >= 408.0f)) break block20;
                                    var3_3 = this.G[var1_2] - 400;
                                    if (this.F[var3_3] > -4 || this.y[var1_2].b < 8.0f || this.y[var1_2].b >= 308.0f) break block21;
                                    this.F[this.G[var1_2]] = -5;
                                    this.y[var1_2].a -= 400.0f;
                                    this.F[var3_3] = var1_2;
                                    this.G[var1_2] = var3_3;
                                    break block19;
                                }
                                v2 = this;
                                ** GOTO lbl79
                            }
                            if (!(this.y[var1_2].b < 8.0f)) break block22;
                            var3_3 = this.G[var1_2] + this.aR.a * 300;
                            if (this.F[var3_3] > -4) break block23;
                            this.F[this.G[var1_2]] = -5;
                            this.y[var1_2].b += 300.0f;
                            this.F[var3_3] = var1_2;
                            this.G[var1_2] = var3_3;
                            break block19;
                        }
                        v2 = this;
                        ** GOTO lbl79
                    }
                    if (!(this.y[var1_2].b >= 308.0f)) break block19;
                    var3_3 = this.G[var1_2] - this.aR.a * 300;
                    if (this.F[var3_3] <= -4) {
                        this.F[this.G[var1_2]] = -5;
                        this.y[var1_2].b -= 300.0f;
                        this.F[var3_3] = var1_2;
                        this.G[var1_2] = var3_3;
                    } else {
                        v2 = this;
lbl79:
                        // 4 sources

                        v2.c(var1_2--);
                    }
                }
                ++var1_2;
            }
        }
    }

    /*
     * Unable to fully structure code
     */
    private int c(int var1_1, e var2_2) {
        block145: {
            block170: {
                block163: {
                    block168: {
                        block169: {
                            block167: {
                                block165: {
                                    block166: {
                                        block164: {
                                            block162: {
                                                block161: {
                                                    block160: {
                                                        block159: {
                                                            block158: {
                                                                block157: {
                                                                    block156: {
                                                                        block147: {
                                                                            block151: {
                                                                                block155: {
                                                                                    block152: {
                                                                                        block154: {
                                                                                            block153: {
                                                                                                block150: {
                                                                                                    block149: {
                                                                                                        block148: {
                                                                                                            block146: {
                                                                                                                block144: {
                                                                                                                    var4_3 = ((int)this.y[var1_1].b >> 2) * this.a + ((int)this.y[var1_1].a >> 2);
                                                                                                                    var5_4 = this.G[var1_1];
                                                                                                                    if (this.A[var1_1] != 8) {
                                                                                                                        this.F[var5_4] = -5;
                                                                                                                    }
                                                                                                                    var2_2.a(this.e[var4_3]);
                                                                                                                    if (this.A[var1_1] != 2) break block144;
                                                                                                                    var2_2.b += this.aR.b(0.01f, 0.1f);
                                                                                                                    var2_2.b(this.z[var1_1]);
                                                                                                                    this.z[var1_1].a(0.7f);
                                                                                                                    this.a(var1_1, var2_2);
                                                                                                                    break block145;
                                                                                                                }
                                                                                                                if (this.A[var1_1] != 3) break block146;
                                                                                                                this.z[var1_1].a += this.e[var4_3].a * 0.2f;
                                                                                                                this.z[var1_1].b += this.e[var4_3].b * 0.2f;
                                                                                                                if (this.F[var5_4 + this.aR.a] != -5) {
                                                                                                                    if (this.F[var5_4 - 1] == -5) {
                                                                                                                        this.z[var1_1].a -= this.aR.b(0.1f, 0.2f);
                                                                                                                    }
                                                                                                                    if (this.F[var5_4 + 1] == -5) {
                                                                                                                        this.z[var1_1].a += this.aR.b(0.1f, 0.2f);
                                                                                                                    }
                                                                                                                }
                                                                                                                this.z[var1_1].a += this.aR.b(-0.01f, 0.01f);
                                                                                                                this.z[var1_1].b += this.aR.b(0.01f, 0.05f);
                                                                                                                this.z[var1_1].a(0.9f);
                                                                                                                var2_2.b(this.z[var1_1]);
                                                                                                                var5_4 = this.a(var1_1, var2_2);
                                                                                                                var6_5 = (int)this.aR.d(8.0f);
                                                                                                                if (var6_5 < 5) {
                                                                                                                    v0 = var5_4 - this.aR.a;
                                                                                                                } else if (var6_5 < 6) {
                                                                                                                    v0 = var5_4 - 1;
                                                                                                                } else {
                                                                                                                    if (var6_5 < 7) {
                                                                                                                        v1 = var5_4;
                                                                                                                        v2 = 1;
                                                                                                                    } else {
                                                                                                                        v1 = var5_4;
                                                                                                                        v2 = this.aR.a;
                                                                                                                    }
                                                                                                                    v0 = v1 + v2;
                                                                                                                }
                                                                                                                var7_21 = v0;
                                                                                                                var8_32 = this.F[var7_21];
                                                                                                                if (var8_32 >= 0) {
                                                                                                                    if (var6_5 < 7 && (this.P[this.A[var8_32]] == 1 && this.A[var8_32] != 19 || this.A[var8_32] == 23 || this.A[var8_32] == 27 || this.A[var8_32] == 37)) {
                                                                                                                        if (this.aR.d(100.0f) < 10.0f) {
                                                                                                                            this.b(var1_1, var8_32, var5_4, var7_21);
                                                                                                                        }
                                                                                                                    } else if (this.A[var8_32] == 10) {
                                                                                                                        if (this.aR.d(100.0f) < 50.0f) {
                                                                                                                            this.A[var1_1] = 10;
                                                                                                                        }
                                                                                                                    } else if (this.A[var8_32] == 45 && this.C[var8_32] == 0) {
                                                                                                                        var7_21 = var6_5 < 5 ? 2 : (var6_5 < 6 ? 1 : (var6_5 < 7 ? 3 : 0));
                                                                                                                        this.B[var8_32] = 4 | var7_21;
                                                                                                                        this.C[var8_32] = 3;
                                                                                                                        this.c(var1_1);
                                                                                                                        return 1;
                                                                                                                    }
                                                                                                                }
                                                                                                                break block145;
                                                                                                            }
                                                                                                            if (this.A[var1_1] != 4) break block147;
                                                                                                            if (this.B[var1_1] == 2) {
                                                                                                                this.z[var1_1].a(0.8f);
                                                                                                                var2_2.b(this.z[var1_1]);
                                                                                                            }
                                                                                                            var2_2.a(0.2f);
                                                                                                            if (this.B[var1_1] != 0 && this.B[var1_1] != 2) break block148;
                                                                                                            var6_6 = this.aR.b(-0.01f, -0.05f);
                                                                                                            this.e[var4_3].a += this.aR.b(-0.02f, 0.02f);
                                                                                                            this.e[var4_3].b += var6_6;
                                                                                                            break block149;
                                                                                                        }
                                                                                                        if (this.B[var1_1] != 1) break block150;
                                                                                                        var6_6 = this.aR.b(-0.01f, -0.05f);
                                                                                                    }
                                                                                                    v3 = var4_3;
                                                                                                    this.g[v3] = this.g[v3] + -var6_6;
                                                                                                    this.i -= -var6_6;
                                                                                                }
                                                                                                var5_4 = this.a(var1_1, var2_2);
                                                                                                var5_4 += (int)this.aR.d(5.0f) - 2;
                                                                                                var6_7 = this.F[(var5_4 += ((int)this.aR.d(5.0f) - 2) * this.aR.a) - this.aR.a];
                                                                                                if (var6_7 < 0) break block151;
                                                                                                if (this.A[var6_7] == 2) break block152;
                                                                                                if (this.A[var6_7] == 3 || this.A[var6_7] == 37) {
                                                                                                    this.c(var1_1);
                                                                                                    return 1;
                                                                                                }
                                                                                                if (this.A[var6_7] != 5) break block153;
                                                                                                if (!(this.aR.d(100.0f) < 50.0f)) break block151;
                                                                                                break block152;
                                                                                            }
                                                                                            if (this.A[var6_7] != 11) break block154;
                                                                                            v4 = this.A;
                                                                                            v5 = var6_7;
                                                                                            v6 = 3;
                                                                                            break block155;
                                                                                        }
                                                                                        if (this.A[var6_7] != 24 && this.A[var6_7] != 35) break block151;
                                                                                    }
                                                                                    v4 = this.A;
                                                                                    v5 = var6_7;
                                                                                    v6 = 4;
                                                                                }
                                                                                v4[v5] = v6;
                                                                            }
                                                                            var7_22 = 5;
                                                                            if (this.B[var1_1] == 1) {
                                                                                var7_22 = 20;
                                                                            }
                                                                            if (this.aR.d(100.0f) < (float)var7_22) {
                                                                                this.c(var1_1);
                                                                                return 1;
                                                                            }
                                                                            break block145;
                                                                        }
                                                                        if (this.A[var1_1] != 5) break block156;
                                                                        if (this.B[var1_1] == 0) {
                                                                            var2_2.b += this.aR.b(0.01f, 0.09f);
                                                                            var2_2.b(this.z[var1_1]);
                                                                            this.z[var1_1].a(0.8f);
                                                                        } else {
                                                                            var2_2.a(0.0f, 0.0f);
                                                                        }
                                                                        var5_4 = this.a(var1_1, var2_2);
                                                                        if (this.B[var1_1] == 0) {
                                                                            var6_8 = this.F[var5_4 + this.aR.a];
                                                                            if (var6_8 < 0) {
                                                                                return 0;
                                                                            }
                                                                            if (this.A[var6_8] != 2 && this.A[var6_8] != 6 && this.A[var6_8] != 35) {
                                                                                return 0;
                                                                            }
                                                                            if (this.aR.h[this.aR.g] - this.D < 1000) {
                                                                                return 0;
                                                                            }
                                                                        }
                                                                        this.B[var1_1] = 1;
                                                                        var6_8 = (int)this.y[var1_1].a + (int)this.aR.d(3.0f) - 1;
                                                                        var7_23 = (int)this.y[var1_1].b - (int)this.aR.d(1.5f);
                                                                        var8_33 = var7_23 * this.aR.a + var6_8;
                                                                        if (this.F[var8_33] <= -4) {
                                                                            if (this.F[var8_33 + this.aR.a] <= -4) {
                                                                                this.a(var1_1, (float)var6_8, (float)var7_23);
                                                                                this.a((float)var6_8, (float)(var7_23 + 1), 6);
                                                                            }
                                                                            if (this.aR.d(100.0f) < 5.0f) {
                                                                                this.c(var1_1);
                                                                                return 1;
                                                                            }
                                                                        }
                                                                        break block145;
                                                                    }
                                                                    if (this.A[var1_1] != 6) break block157;
                                                                    var2_2.a(this.z[var1_1]);
                                                                    this.z[var1_1].a(0.3f);
                                                                    var5_4 = this.a(var1_1, var2_2);
                                                                    if (this.B[var1_1] == 0) {
                                                                        var5_4 += (int)this.aR.d(5.0f) - 2;
                                                                        var6_9 = this.F[var5_4 += ((int)this.aR.d(7.0f) - 3) * this.aR.a];
                                                                        if (var6_9 >= 0) {
                                                                            if (this.A[var6_9] == 4 || this.A[var6_9] == 20) {
                                                                                if (this.aR.d(100.0f) < 50.0f) {
                                                                                    this.B[var1_1] = 1;
                                                                                }
                                                                            } else if (this.A[var6_9] == 3) {
                                                                                if (this.aR.h[this.aR.g] - this.D < 1000) {
                                                                                    return 0;
                                                                                }
                                                                                var7_24 = (int)this.y[var1_1].a + (int)this.aR.d(3.0f) - 1;
                                                                                var8_34 = (int)this.y[var1_1].b + (int)this.aR.d(3.0f) - 1;
                                                                                var5_4 = var8_34 * this.aR.a + var7_24;
                                                                                if (this.F[var5_4] <= -4 && this.aR.d(100.0f) < 10.0f) {
                                                                                    this.a((float)var7_24, (float)var8_34, 5);
                                                                                    ** GOTO lbl566
                                                                                }
                                                                            }
                                                                        }
                                                                    } else if (this.B[var1_1] == 1) {
                                                                        var6_10 = (int)this.y[var1_1].a + (int)this.aR.d(3.0f) - 1;
                                                                        var7_25 = (int)this.y[var1_1].b + (int)this.aR.d(3.0f) - 1;
                                                                        var5_4 = var7_25 * this.aR.a + var6_10;
                                                                        var8_35 = this.F[var5_4];
                                                                        if (this.F[var5_4] <= -4) {
                                                                            if (this.aR.d(100.0f) < 30.0f && (var5_4 = this.a((float)var6_10, (float)var7_25, 4)) >= 0) {
                                                                                v7 = this.B;
                                                                                v8 = var5_4;
                                                                                v9 = 1;
                                                                            }
                                                                        } else if (var8_35 >= 0 && this.A[var8_35] == 3) {
                                                                            this.B[var1_1] = 0;
                                                                            v7 = this.A;
                                                                            v8 = var1_1;
                                                                            v9 = v7[v8] = 2;
                                                                        }
                                                                        if (this.aR.d(1000.0f) < 5.0f) {
                                                                            this.A[var1_1] = 2;
                                                                        }
                                                                    }
                                                                    break block145;
                                                                }
                                                                if (this.A[var1_1] != 7) break block158;
                                                                var2_2.b += this.aR.b(0.01f, 0.2f);
                                                                var2_2.b(this.z[var1_1]);
                                                                this.z[var1_1].a(0.8f);
                                                                var5_4 = this.a(var1_1, var2_2);
                                                                var5_4 += (int)this.aR.d(5.0f) - 2;
                                                                var6_11 = this.F[var5_4 += ((int)this.aR.d(5.0f) - 2) * this.aR.a];
                                                                if (var6_11 < 0) {
                                                                    return 0;
                                                                }
                                                                if (this.P[this.A[var6_11]] != 3) {
                                                                    return 0;
                                                                }
                                                                var7_26 = false;
                                                                var8_36 = (int)this.y[var1_1].a & 65524;
                                                                var9_39 = (int)this.y[var1_1].b & 65524;
                                                                var10_42 = dust.b(var8_36 - 10, this.c);
                                                                var11_45 = dust.b(var9_39 - 10, this.c);
                                                                var12_47 = dust.c(var8_36 + 10, this.aR.a - this.c - 1);
                                                                var13_49 = dust.c(var9_39 + 10, (this.b - 1) * this.c - 1);
                                                                var14_51 = var11_45;
                                                                while (var14_51 <= var13_49) {
                                                                    var15_53 = var10_42;
                                                                    while (var15_53 <= var12_47) {
                                                                        var16_55 = (var15_53 - var8_36) * (var15_53 - var8_36) + (var14_51 - var9_39) * (var14_51 - var9_39);
                                                                        if (var16_55 <= 100) {
                                                                            var5_4 = var14_51 * this.aR.a + var15_53;
                                                                            var6_11 = this.F[var5_4];
                                                                            if (var6_11 >= 0 && this.A[var6_11] != 7) {
                                                                                this.z[var6_11].a += (float)((var15_53 - var8_36) * 10);
                                                                                this.z[var6_11].b += (float)((var14_51 - var9_39) * 10);
                                                                            }
                                                                            if ((var14_51 & 3) + (var15_53 & 3) == 0 && this.l[var5_4 = (var14_51 >> 2) * this.a + (var15_53 >> 2)] <= 0) {
                                                                                if (dust.c(var15_53 - var8_36) >= 1) {
                                                                                    this.e[var5_4].a += (float)(10 / (var15_53 - var8_36));
                                                                                }
                                                                                if (dust.c(var14_51 - var9_39) >= 1) {
                                                                                    this.e[var5_4].b += (float)(10 / (var14_51 - var9_39));
                                                                                }
                                                                            }
                                                                        }
                                                                        ++var15_53;
                                                                    }
                                                                    ++var14_51;
                                                                }
                                                                this.A[var1_1] = 4;
                                                                break block145;
                                                            }
                                                            if (this.A[var1_1] != 8) break block159;
                                                            this.e[var4_3].b(this.z[var1_1]);
                                                            if (this.F[var5_4] == -5) {
                                                                this.F[var5_4] = -4;
                                                            }
                                                            break block145;
                                                        }
                                                        if (this.A[var1_1] != 10) break block160;
                                                        if (var2_2.a() > 1.0f && this.aR.d(100.0f) < 50.0f) {
                                                            this.A[var1_1] = 11;
                                                        }
                                                        var2_2.a(0.0f, 0.0f);
                                                        var5_4 = this.a(var1_1, var2_2);
                                                        var5_4 += (int)this.aR.d(9.0f) - 4;
                                                        var6_12 = this.F[var5_4 += ((int)this.aR.d(9.0f) - 4) * this.aR.a];
                                                        if (var6_12 >= 0 && this.P[this.A[var6_12]] == 3) {
                                                            this.A[var1_1] = 3;
                                                        }
                                                        break block145;
                                                    }
                                                    if (this.A[var1_1] != 11) break block161;
                                                    var2_2.b += this.aR.b(0.01f, 0.08f);
                                                    var2_2.b(this.z[var1_1]);
                                                    this.z[var1_1].a(0.7f);
                                                    var5_4 = this.a(var1_1, var2_2);
                                                    var5_4 += (int)this.aR.d(3.0f) - 1;
                                                    var6_13 = this.F[var5_4 += ((int)this.aR.d(3.0f) - 1) * this.aR.a];
                                                    if (var6_13 >= 0 && this.A[var6_13] != 6 && this.A[var6_13] != 9 && this.A[var6_13] != 11 && this.A[var6_13] != 14 && this.A[var6_13] != 35 && this.A[var6_13] != 44) {
                                                        this.A[var1_1] = this.A[var6_13] == 10 ? 10 : 3;
                                                    }
                                                    break block145;
                                                }
                                                if (this.A[var1_1] != 12) break block162;
                                                var2_2.b(this.z[var1_1]);
                                                this.z[var1_1].a(0.7f);
                                                this.a(var1_1, var2_2);
                                                if (this.aR.d(100.0f) < 10.0f) {
                                                    this.c(var1_1);
                                                    return 1;
                                                }
                                                break block145;
                                            }
                                            if (this.A[var1_1] != 13) break block163;
                                            var2_2.a(0.05f);
                                            this.z[var1_1].b(var2_2);
                                            this.z[var1_1].b += 0.01f;
                                            this.z[var1_1].a(0.999f);
                                            var2_2.a(this.z[var1_1]);
                                            var2_2.a(3.8f / (var2_2.a() + 1.0f));
                                            var6_14 = (int)this.y[var1_1].b * this.aR.a + (int)(this.y[var1_1].a + var2_2.a);
                                            if (this.F[var6_14] > -4) break block164;
                                            this.y[var1_1].a += var2_2.a;
                                            break block165;
                                        }
                                        if (this.F[var6_14] > -1) break block166;
                                        this.z[var1_1].a *= -0.9f;
                                        v10 = this.z[var1_1];
                                        v11 = v10;
                                        v12 = v10.b;
                                        v13 = 0.9f;
                                        ** GOTO lbl337
                                    }
                                    if (this.F[var6_14] < 0) break block165;
                                    if (this.P[this.A[this.F[var6_14]]] == 2 && this.A[this.F[var6_14]] != 41) {
                                        this.z[this.F[var6_14]].a -= this.z[var1_1].a;
                                        this.z[var1_1].a *= 0.5f;
                                        var7_27 = this.y[var1_1].a;
                                        this.y[var1_1].a = this.y[this.F[var6_14]].a;
                                        this.y[this.F[var6_14]].a = var7_27;
                                        this.G[this.F[var6_14]] = var5_4;
                                        this.F[var5_4] = this.F[var6_14];
                                    } else if (this.A[this.F[var6_14]] == 4) {
                                        var7_27 = this.y[var1_1].a;
                                        this.y[var1_1].a = this.y[this.F[var6_14]].a;
                                        this.y[this.F[var6_14]].a = var7_27;
                                        this.G[this.F[var6_14]] = var5_4;
                                        this.F[var5_4] = this.F[var6_14];
                                    } else if (this.A[this.F[var6_14]] == 13) {
                                        var7_27 = this.z[var1_1].a * 0.9f;
                                        this.z[var1_1].a = this.z[this.F[var6_14]].a * 0.9f;
                                        this.z[this.F[var6_14]].a = var7_27;
                                    } else {
                                        this.z[var1_1].a *= -this.M[this.A[this.F[var6_14]]];
                                        v14 = this.z[var1_1];
                                        v11 = v14;
                                        v12 = v14.b;
                                        v13 = this.N[this.A[this.F[var6_14]]];
lbl337:
                                        // 2 sources

                                        v11.b = v12 * v13;
                                    }
                                }
                                var5_4 = (int)this.y[var1_1].b * this.aR.a + (int)this.y[var1_1].a;
                                this.F[var5_4] = -5;
                                var6_14 = (int)(this.y[var1_1].b + var2_2.b) * this.aR.a + (int)this.y[var1_1].a;
                                if (this.F[var6_14] > -4) break block167;
                                this.y[var1_1].b += var2_2.b;
                                break block168;
                            }
                            if (this.F[var6_14] > -1) break block169;
                            this.z[var1_1].b *= -0.9f;
                            v15 = this.z[var1_1];
                            v16 = v15;
                            v17 = v15.a;
                            v18 = 0.9f;
                            ** GOTO lbl388
                        }
                        if (this.F[var6_14] < 0) break block168;
                        if (this.P[this.A[this.F[var6_14]]] == 2 && this.A[this.F[var6_14]] != 41) {
                            this.z[this.F[var6_14]].b -= this.z[var1_1].b;
                            this.z[var1_1].b *= 0.5f;
                            var7_27 = this.y[var1_1].b;
                            this.y[var1_1].b = this.y[this.F[var6_14]].b;
                            this.y[this.F[var6_14]].b = var7_27;
                            this.G[this.F[var6_14]] = var5_4;
                            this.F[var5_4] = this.F[var6_14];
                        } else if (this.A[this.F[var6_14]] == 4) {
                            var7_27 = this.y[var1_1].b;
                            this.y[var1_1].b = this.y[this.F[var6_14]].b;
                            this.y[this.F[var6_14]].b = var7_27;
                            this.G[this.F[var6_14]] = var5_4;
                            this.F[var5_4] = this.F[var6_14];
                        } else if (this.A[this.F[var6_14]] == 13) {
                            if (this.z[var1_1].b > 0.0f) {
                                var7_27 = this.z[var1_1].b * 0.45f;
                                this.z[var1_1].b *= -0.45f;
                                this.z[var1_1].b += this.z[this.F[var6_14]].b;
                                this.z[this.F[var6_14]].b = var7_27;
                            } else {
                                var7_27 = this.z[this.F[var6_14]].b * 0.45f;
                                this.z[this.F[var6_14]].b *= -0.45f;
                                this.z[this.F[var6_14]].b += this.z[var1_1].b;
                                this.z[var1_1].b = var7_27;
                            }
                        } else {
                            this.z[var1_1].b *= -this.M[this.A[this.F[var6_14]]];
                            v19 = this.z[var1_1];
                            v16 = v19;
                            v17 = v19.a;
                            v18 = this.N[this.A[this.F[var6_14]]];
lbl388:
                            // 2 sources

                            v16.a = v17 * v18;
                        }
                    }
                    this.G[var1_1] = (int)this.y[var1_1].b * this.aR.a + (int)this.y[var1_1].a;
                    this.F[this.G[var1_1]] = var1_1;
                    break block145;
                }
                if (this.A[var1_1] != 14) break block170;
                var2_2.a(0.0f, 0.0f);
                var5_4 = this.a(var1_1, var2_2);
                if (this.B[var1_1] == 0) {
                    var5_4 += (int)this.aR.d(5.0f) - 1;
                    var6_15 = this.F[var5_4 += ((int)this.aR.d(5.0f) - 1) * this.aR.a];
                    if (var6_15 >= 0) {
                        this.B[var1_1] = this.A[var6_15] == 14 ? this.B[var6_15] : this.A[var6_15];
                    }
                } else {
                    if (this.aR.h[this.aR.g] - this.D < 1000) {
                        return 0;
                    }
                    var6_16 = (int)this.y[var1_1].a + (int)this.aR.d(3.0f) - 1;
                    var7_28 = (int)this.y[var1_1].b + (int)this.aR.d(3.0f) - 1;
                    var5_4 = var7_28 * this.aR.a + var6_16;
                    if (this.F[var5_4] <= -4 && this.aR.d(100.0f) < 10.0f) {
                        this.a((float)var6_16, (float)var7_28, this.B[var1_1]);
                    }
                }
                break block145;
            }
            if (this.A[var1_1] != 15) ** GOTO lbl459
            this.z[var1_1].a += this.e[var4_3].a * 0.1f;
            this.z[var1_1].b += this.e[var4_3].b * 0.1f;
            var2_2.b += this.aR.b(0.1f, 0.2f);
            this.z[var1_1].a(0.9f);
            var2_2.b(this.z[var1_1]);
            var5_4 = this.a(var1_1, var2_2);
            if (this.B[var1_1] == 0) {
                this.B[var1_1] = this.s[this.aR.c] != 0 ? this.s[this.aR.c] : (this.s[this.aR.d] != 0 ? this.s[this.aR.d] : 2);
            } else if (this.B[var1_1] < 100) {
                var5_4 += (int)this.aR.d(3.0f) - 1;
                if (this.F[var5_4 += ((int)this.aR.d(3.0f) - 1) * this.aR.a] >= 0 && this.P[this.A[this.F[var5_4]]] == 3) {
                    this.z[var1_1].b -= 0.1f;
                    this.z[var1_1].d();
                    this.z[var1_1].a(50.0f);
                    v20 = var1_1;
                    this.B[v20] = this.B[v20] + 100;
                }
            } else {
                if (this.B[var1_1] < 5000) {
                    v21 = var1_1;
                    this.B[v21] = this.B[v21] + 100;
                    return 0;
                }
                if (this.aR.d(100.0f) > 5.0f) {
                    return 0;
                }
                if (this.aR.h[this.aR.g] - this.D < 1000) {
                    this.c(var1_1);
                    return 1;
                }
                var3_57 = 0;
                while (var3_57 < 512) {
                    var6_17 = (int)(this.y[var1_1].a + this.aR.bn[var3_57][0] * 2.0f);
                    var7_29 = (int)(this.y[var1_1].b + this.aR.bn[var3_57][1] * 2.0f);
                    var6_17 = dust.a(var6_17, 8, 408);
                    var5_4 = (var7_29 = dust.a(var7_29, 8, 308)) * this.aR.a + var6_17;
                    if (this.F[var5_4] <= -4 && (var5_4 = this.a((float)var6_17, (float)var7_29, this.B[var1_1] % 100)) >= 0) {
                        this.z[var5_4].a += this.aR.bn[var3_57][0] * 20.0f;
                        this.z[var5_4].b += this.aR.bn[var3_57][1] * 20.0f;
                    }
                    var3_57 += 32;
                }
                this.c(var1_1);
                return 1;
lbl459:
                // 1 sources

                if (this.A[var1_1] == 16) {
                    this.z[var1_1].a += this.e[var4_3].a * 0.2f;
                    this.z[var1_1].b += this.e[var4_3].b * 0.2f;
                    if (this.F[var5_4 + this.aR.a] != -5) {
                        if (this.F[var5_4 - 1] == -5) {
                            this.z[var1_1].a -= this.aR.b(0.1f, 0.2f);
                        }
                        if (this.F[var5_4 + 1] == -5) {
                            this.z[var1_1].a += this.aR.b(0.1f, 0.2f);
                        }
                    }
                    this.z[var1_1].a += this.aR.b(-0.01f, 0.01f);
                    this.z[var1_1].b += this.aR.b(0.01f, 0.05f);
                    this.z[var1_1].a(0.9f);
                    var2_2.b(this.z[var1_1]);
                    var5_4 = this.a(var1_1, var2_2);
                    var6_18 = (int)this.aR.d(8.0f);
                    if (var6_18 < 5) {
                        v22 = var5_4 - this.aR.a;
                    } else if (var6_18 < 6) {
                        v22 = var5_4 - 1;
                    } else {
                        if (var6_18 < 7) {
                            v23 = var5_4;
                            v24 = 1;
                        } else {
                            v23 = var5_4;
                            v24 = this.aR.a;
                        }
                        v22 = v23 + v24;
                    }
                    var7_30 = v22;
                    var8_37 = this.F[var7_30];
                    if (var8_37 >= 0) {
                        if (var6_18 < 7 && (this.P[this.A[var8_37]] == 1 && this.A[var8_37] != 19 || this.A[var8_37] == 3 || this.A[var8_37] == 23 || this.A[var8_37] == 37)) {
                            if (this.aR.d(100.0f) < 10.0f) {
                                this.b(var1_1, var8_37, var5_4, var7_30);
                            }
                        } else if (this.P[this.A[var8_37]] == 3) {
                            this.B[var1_1] = 1;
                        } else {
                            if (this.A[var8_37] == 43 && this.B[var8_37] < 256) {
                                this.B[var8_37] = 16;
                                this.c(var1_1);
                                return 1;
                            }
                            if (this.A[var8_37] == 45 && this.C[var8_37] == 0) {
                                var7_30 = var6_18 < 5 ? 2 : (var6_18 < 6 ? 1 : (var6_18 < 7 ? 3 : 0));
                                this.B[var8_37] = 4 | var7_30;
                                this.C[var8_37] = 16;
                                this.c(var1_1);
                                return 1;
                            }
                        }
                    }
                    if (this.B[var1_1] == 1) {
                        var9_40 = (int)this.y[var1_1].a + (int)this.aR.d(3.0f) - 1;
                        var10_43 = (int)this.y[var1_1].b + (int)this.aR.d(3.0f) - 1;
                        var7_30 = var10_43 * this.aR.a + var9_40;
                        if (this.F[var7_30] <= -4) {
                            this.a((float)var9_40, (float)var10_43, 4);
                        }
                        if (this.aR.d(100.0f) < 10.0f) {
                            this.c(var1_1);
                            return 1;
                        }
                    }
                } else if (this.A[var1_1] == 17) {
                    var2_2.a(0.0f, 0.0f);
                    var5_4 = this.a(var1_1, var2_2);
                    if (this.B[var1_1] == 0) {
                        var5_4 += (int)this.aR.d(3.0f) - 1;
                        var6_19 = this.F[var5_4 += ((int)this.aR.d(3.0f) - 1) * this.aR.a];
                        if (var6_19 >= 0 && this.P[this.A[var6_19]] == 3) {
                            this.B[var1_1] = 1;
                        }
                    } else {
                        var3_58 = 0;
                        while (var3_58 < 8) {
                            var8_38 = var5_4 + this.I[var3_58];
                            var9_41 = this.F[var8_38];
                            if (var9_41 >= 0 && this.A[var9_41] == 17) {
                                this.B[var9_41] = 1;
                            }
                            ++var3_58;
                        }
                        var10_44 = false;
                        var11_46 = (int)this.y[var1_1].a & 65524;
                        var12_48 = (int)this.y[var1_1].b & 65524;
                        var13_50 = dust.b(var11_46 - 10, this.c);
                        var14_52 = dust.b(var12_48 - 10, this.c);
                        var15_54 = dust.c(var11_46 + 10, this.aR.a - this.c - 1);
                        var16_56 = dust.c(var12_48 + 10, (this.b - 1) * this.c - 1);
                        var7_31 = var14_52;
                        while (var7_31 <= var16_56) {
                            var6_20 = var13_50;
                            while (var6_20 <= var15_54) {
                                var17_59 = (var6_20 - var11_46) * (var6_20 - var11_46) + (var7_31 - var12_48) * (var7_31 - var12_48);
                                if (var17_59 <= 100) {
                                    var8_38 = var7_31 * this.aR.a + var6_20;
                                    var9_41 = this.F[var8_38];
                                    if (var9_41 >= 0) {
                                        this.z[var9_41].a += (float)((var6_20 - var11_46) * 10);
                                        this.z[var9_41].b += (float)((var7_31 - var12_48) * 10);
                                    }
                                    if ((var7_31 & 3) + (var6_20 & 3) == 0 && this.l[var8_38 = (var7_31 >> 2) * this.a + (var6_20 >> 2)] <= 0) {
                                        if (dust.c(var6_20 - var11_46) >= 1) {
                                            this.e[var8_38].a += 1.0f / (float)(var6_20 - var11_46);
                                        }
                                        if (dust.c(var7_31 - var12_48) >= 1) {
                                            this.e[var8_38].b += 1.0f / (float)(var7_31 - var12_48);
                                        }
                                    }
                                }
                                ++var6_20;
                            }
                            ++var7_31;
                        }
                        this.c(var1_1);
                        return 1;
                    }
                }
            }
        }
        return 0;
    }

    /*
     * Unable to fully structure code
     */
    private int d(int var1_1, e var2_2) {
        block173: {
            block161: {
                block213: {
                    block188: {
                        block207: {
                            block202: {
                                block189: {
                                    block201: {
                                        block197: {
                                            block200: {
                                                block199: {
                                                    block198: {
                                                        block196: {
                                                            block192: {
                                                                block194: {
                                                                    block195: {
                                                                        block190: {
                                                                            block193: {
                                                                                block191: {
                                                                                    block187: {
                                                                                        block186: {
                                                                                            block179: {
                                                                                                block185: {
                                                                                                    block184: {
                                                                                                        block183: {
                                                                                                            block182: {
                                                                                                                block181: {
                                                                                                                    block180: {
                                                                                                                        block178: {
                                                                                                                            block177: {
                                                                                                                                block174: {
                                                                                                                                    block176: {
                                                                                                                                        block175: {
                                                                                                                                            block162: {
                                                                                                                                                block163: {
                                                                                                                                                    block169: {
                                                                                                                                                        block172: {
                                                                                                                                                            block171: {
                                                                                                                                                                block170: {
                                                                                                                                                                    block168: {
                                                                                                                                                                        block167: {
                                                                                                                                                                            block166: {
                                                                                                                                                                                block165: {
                                                                                                                                                                                    block164: {
                                                                                                                                                                                        block160: {
                                                                                                                                                                                            var4_3 = ((int)this.y[var1_1].b >> 2) * this.a + ((int)this.y[var1_1].a >> 2);
                                                                                                                                                                                            var5_4 = this.G[var1_1];
                                                                                                                                                                                            this.F[var5_4] = -5;
                                                                                                                                                                                            var2_2.a(this.e[var4_3]);
                                                                                                                                                                                            if (this.A[var1_1] != 19) break block160;
                                                                                                                                                                                            this.z[var1_1].a += this.e[var4_3].a * 0.05f;
                                                                                                                                                                                            this.z[var1_1].b += this.e[var4_3].b * 0.05f;
                                                                                                                                                                                            this.z[var1_1].b += this.aR.b(0.01f, 0.05f);
                                                                                                                                                                                            this.z[var1_1].a(0.95f);
                                                                                                                                                                                            var2_2.a(this.z[var1_1]);
                                                                                                                                                                                            if (var2_2.a() > 10.0f && this.aR.d(100.0f) < 50.0f) {
                                                                                                                                                                                                this.A[var1_1] = 2;
                                                                                                                                                                                            }
                                                                                                                                                                                            var2_2.a(3.8f / (var2_2.a() + 1.0f));
                                                                                                                                                                                            var6_5 = (int)this.y[var1_1].b * this.aR.a + (int)(this.y[var1_1].a + var2_2.a);
                                                                                                                                                                                            if (this.F[var6_5] <= -4) {
                                                                                                                                                                                                v0 = this.y[var1_1];
                                                                                                                                                                                                v1 = v0;
                                                                                                                                                                                                v2 = v0.a + var2_2.a;
                                                                                                                                                                                            } else {
                                                                                                                                                                                                if (this.F[var6_5] >= 0) {
                                                                                                                                                                                                    if (this.P[this.A[this.F[var6_5]]] == 2 && this.A[this.F[var6_5]] != 41 || this.A[this.F[var6_5]] == 20) {
                                                                                                                                                                                                        this.z[this.F[var6_5]].a -= this.z[var1_1].a;
                                                                                                                                                                                                        var7_16 = this.y[var1_1].a;
                                                                                                                                                                                                        this.y[var1_1].a = this.y[this.F[var6_5]].a;
                                                                                                                                                                                                        this.y[this.F[var6_5]].a = var7_16;
                                                                                                                                                                                                        this.G[this.F[var6_5]] = var5_4;
                                                                                                                                                                                                        this.F[var5_4] = this.F[var6_5];
                                                                                                                                                                                                    } else if (this.A[this.F[var6_5]] == 2 || this.A[this.F[var6_5]] == 5 || this.A[this.F[var6_5]] == 7 || this.A[this.F[var6_5]] == 15 || this.A[this.F[var6_5]] == 24) {
                                                                                                                                                                                                        this.z[this.F[var6_5]].a += this.aR.d(this.z[var1_1].a);
                                                                                                                                                                                                    }
                                                                                                                                                                                                    v3 = this;
                                                                                                                                                                                                } else {
                                                                                                                                                                                                    v3 = this;
                                                                                                                                                                                                }
                                                                                                                                                                                                v4 = v3.z[var1_1];
                                                                                                                                                                                                v1 = v4;
                                                                                                                                                                                                v2 = v4.a * 0.5f;
                                                                                                                                                                                            }
                                                                                                                                                                                            v1.a = v2;
                                                                                                                                                                                            var5_4 = (int)this.y[var1_1].b * this.aR.a + (int)this.y[var1_1].a;
                                                                                                                                                                                            this.F[var5_4] = -5;
                                                                                                                                                                                            var6_5 = (int)(this.y[var1_1].b + var2_2.b) * this.aR.a + (int)this.y[var1_1].a;
                                                                                                                                                                                            if (this.F[var6_5] <= -4) {
                                                                                                                                                                                                v5 = this.y[var1_1];
                                                                                                                                                                                                v6 = v5;
                                                                                                                                                                                                v7 = v5.b + var2_2.b;
                                                                                                                                                                                            } else {
                                                                                                                                                                                                if (this.F[var6_5] >= 0) {
                                                                                                                                                                                                    if (this.P[this.A[this.F[var6_5]]] == 2 && this.A[this.F[var6_5]] != 41 || this.A[this.F[var6_5]] == 20) {
                                                                                                                                                                                                        this.z[this.F[var6_5]].b -= this.z[var1_1].b;
                                                                                                                                                                                                        var7_16 = this.y[var1_1].b;
                                                                                                                                                                                                        this.y[var1_1].b = this.y[this.F[var6_5]].b;
                                                                                                                                                                                                        this.y[this.F[var6_5]].b = var7_16;
                                                                                                                                                                                                        this.G[this.F[var6_5]] = var5_4;
                                                                                                                                                                                                        this.F[var5_4] = this.F[var6_5];
                                                                                                                                                                                                    } else if (this.A[this.F[var6_5]] == 2 || this.A[this.F[var6_5]] == 5 || this.A[this.F[var6_5]] == 7 || this.A[this.F[var6_5]] == 15 || this.A[this.F[var6_5]] == 24) {
                                                                                                                                                                                                        this.z[this.F[var6_5]].b += this.aR.d(this.z[var1_1].b);
                                                                                                                                                                                                    }
                                                                                                                                                                                                    v8 = this;
                                                                                                                                                                                                } else {
                                                                                                                                                                                                    v8 = this;
                                                                                                                                                                                                }
                                                                                                                                                                                                v9 = v8.z[var1_1];
                                                                                                                                                                                                v6 = v9;
                                                                                                                                                                                                v7 = v9.b * 0.5f;
                                                                                                                                                                                            }
                                                                                                                                                                                            v6.b = v7;
                                                                                                                                                                                            this.G[var1_1] = (int)this.y[var1_1].b * this.aR.a + (int)this.y[var1_1].a;
                                                                                                                                                                                            v10 = this.F;
                                                                                                                                                                                            v11 = this.G[var1_1];
                                                                                                                                                                                            v12 = var1_1;
                                                                                                                                                                                            break block161;
                                                                                                                                                                                        }
                                                                                                                                                                                        if (this.A[var1_1] != 20) break block162;
                                                                                                                                                                                        this.z[var1_1].a += this.e[var4_3].a * 0.1f;
                                                                                                                                                                                        this.z[var1_1].b += this.e[var4_3].b * 0.1f;
                                                                                                                                                                                        if (this.F[var5_4 + this.aR.a] != -5) {
                                                                                                                                                                                            if (this.F[var5_4 - 1] == -5) {
                                                                                                                                                                                                this.z[var1_1].a -= this.aR.b(0.0f, 0.1f);
                                                                                                                                                                                            }
                                                                                                                                                                                            if (this.F[var5_4 + 1] == -5) {
                                                                                                                                                                                                this.z[var1_1].a += this.aR.b(0.0f, 0.1f);
                                                                                                                                                                                            }
                                                                                                                                                                                        }
                                                                                                                                                                                        this.z[var1_1].a += this.aR.b(-0.01f, 0.01f);
                                                                                                                                                                                        this.z[var1_1].b += this.aR.b(0.01f, 0.1f);
                                                                                                                                                                                        this.z[var1_1].a(0.9f);
                                                                                                                                                                                        var2_2.b(this.z[var1_1]);
                                                                                                                                                                                        var5_4 = this.a(var1_1, var2_2);
                                                                                                                                                                                        var5_4 += (int)this.aR.d(5.0f) - 2;
                                                                                                                                                                                        var7_17 = this.F[(var5_4 += ((int)this.aR.d(5.0f) - 2) * this.aR.a) - this.aR.a];
                                                                                                                                                                                        if (var7_17 < 0) break block163;
                                                                                                                                                                                        if (this.A[var7_17] != 2) break block164;
                                                                                                                                                                                        v13 = this.A;
                                                                                                                                                                                        v14 = var7_17;
                                                                                                                                                                                        v15 = 4;
                                                                                                                                                                                        break block163;
                                                                                                                                                                                    }
                                                                                                                                                                                    if (this.A[var7_17] != 3 && this.A[var7_17] != 27) break block165;
                                                                                                                                                                                    this.A[var1_1] = 19;
                                                                                                                                                                                    this.A[var7_17] = 12;
                                                                                                                                                                                    if (this.aR.d(100.0f) < 50.0f) {
                                                                                                                                                                                        this.c(var1_1);
                                                                                                                                                                                        return 1;
                                                                                                                                                                                    }
                                                                                                                                                                                    break block163;
                                                                                                                                                                                }
                                                                                                                                                                                if (this.A[var7_17] != 5) break block166;
                                                                                                                                                                                v13 = this.A;
                                                                                                                                                                                v14 = var7_17;
                                                                                                                                                                                v15 = 4;
                                                                                                                                                                                break block163;
                                                                                                                                                                            }
                                                                                                                                                                            if (this.A[var7_17] != 13) break block167;
                                                                                                                                                                            v13 = this.A;
                                                                                                                                                                            v14 = var7_17;
                                                                                                                                                                            v15 = 4;
                                                                                                                                                                            break block163;
                                                                                                                                                                        }
                                                                                                                                                                        if (this.A[var7_17] != 19) break block168;
                                                                                                                                                                        this.z[var7_17].a += this.aR.b(-0.1f, 0.1f);
                                                                                                                                                                        if (!(this.aR.d(100.0f) < 5.0f)) break block163;
                                                                                                                                                                        break block169;
                                                                                                                                                                    }
                                                                                                                                                                    if (this.A[var7_17] != 24) break block170;
                                                                                                                                                                    v13 = this.A;
                                                                                                                                                                    v14 = var7_17;
                                                                                                                                                                    v15 = 4;
                                                                                                                                                                    break block163;
                                                                                                                                                                }
                                                                                                                                                                if (this.A[var7_17] != 35) break block171;
                                                                                                                                                                v13 = this.A;
                                                                                                                                                                v14 = var7_17;
                                                                                                                                                                v15 = 4;
                                                                                                                                                                break block163;
                                                                                                                                                            }
                                                                                                                                                            if (this.A[var7_17] != 37) break block172;
                                                                                                                                                            this.A[var1_1] = 19;
                                                                                                                                                            this.A[var7_17] = 36;
                                                                                                                                                            if (this.aR.d(100.0f) < 50.0f) {
                                                                                                                                                                this.c(var1_1);
                                                                                                                                                                return 1;
                                                                                                                                                            }
                                                                                                                                                            break block163;
                                                                                                                                                        }
                                                                                                                                                        if (!(this.A[var7_17] == 38 ? this.aR.d(100.0f) < 50.0f : this.A[var7_17] == 41 && this.aR.d(100.0f) < 1.0f)) break block163;
                                                                                                                                                    }
                                                                                                                                                    v13 = this.A;
                                                                                                                                                    v14 = var7_17;
                                                                                                                                                    v15 = v13[v14] = 20;
                                                                                                                                                }
                                                                                                                                                if ((var8_28 = (int)this.aR.d(4.0f)) < 1) {
                                                                                                                                                    v16 = var5_4 - this.aR.a;
                                                                                                                                                } else if (var8_28 < 2) {
                                                                                                                                                    v16 = var5_4 - 1;
                                                                                                                                                } else {
                                                                                                                                                    if (var8_28 < 3) {
                                                                                                                                                        v17 = var5_4;
                                                                                                                                                        v18 = 1;
                                                                                                                                                    } else {
                                                                                                                                                        v17 = var5_4;
                                                                                                                                                        v18 = this.aR.a;
                                                                                                                                                    }
                                                                                                                                                    v16 = v17 + v18;
                                                                                                                                                }
                                                                                                                                                var6_6 = v16;
                                                                                                                                                var7_17 = this.F[var6_6];
                                                                                                                                                if (var7_17 >= 0 && this.A[var7_17] == 45 && this.C[var7_17] == 0) {
                                                                                                                                                    var6_6 = var8_28 < 1 ? 2 : (var8_28 < 2 ? 1 : (var8_28 < 3 ? 3 : 0));
                                                                                                                                                    this.B[var7_17] = 4 | var6_6;
                                                                                                                                                    this.C[var7_17] = 20;
                                                                                                                                                    this.c(var1_1);
                                                                                                                                                    return 1;
                                                                                                                                                }
                                                                                                                                                break block173;
                                                                                                                                            }
                                                                                                                                            if (this.A[var1_1] != 21) break block174;
                                                                                                                                            var2_2.b += this.aR.b(0.0f, 0.1f);
                                                                                                                                            var2_2.b(this.z[var1_1]);
                                                                                                                                            this.z[var1_1].a(0.7f);
                                                                                                                                            var5_4 = this.a(var1_1, var2_2);
                                                                                                                                            if (this.B[var1_1] != 0) break block175;
                                                                                                                                            var6_7 = var5_4;
                                                                                                                                            var6_7 += (int)this.aR.d(3.0f) - 1;
                                                                                                                                            if (this.F[var6_7 += ((int)this.aR.d(3.0f) - 1) * this.aR.a] < 0 || this.A[this.F[var6_7]] == 21) break block173;
                                                                                                                                            v10 = this.B;
                                                                                                                                            v11 = var1_1;
                                                                                                                                            v12 = this.A[this.F[var6_7]];
                                                                                                                                            break block161;
                                                                                                                                        }
                                                                                                                                        if (this.B[var1_1] > 2048) break block176;
                                                                                                                                        var6_8 = var5_4;
                                                                                                                                        var6_8 += (int)this.aR.d(3.0f) - 1;
                                                                                                                                        if (var5_4 != (var6_8 += ((int)this.aR.d(3.0f) - 1) * this.aR.a) && this.F[var6_8] >= 0 && (this.A[this.F[var6_8]] != 21 || this.B[this.F[var6_8]] == 0)) {
                                                                                                                                            this.A[this.F[var6_8]] = 21;
                                                                                                                                            this.B[this.F[var6_8]] = this.B[var1_1] & 255;
                                                                                                                                            this.C[this.F[var6_8]] = 0;
                                                                                                                                        }
                                                                                                                                        v19 = var1_1;
                                                                                                                                        v11 = v19;
                                                                                                                                        v10 = this.B;
                                                                                                                                        v12 = this.B[v19] + 256;
                                                                                                                                        break block161;
                                                                                                                                    }
                                                                                                                                    v20 = var1_1;
                                                                                                                                    this.B[v20] = this.B[v20] + 256;
                                                                                                                                    if (this.B[var1_1] >= 32768) {
                                                                                                                                        this.A[var1_1] = this.B[var1_1] & 255;
                                                                                                                                        this.B[var1_1] = 0;
                                                                                                                                        this.z[var1_1].a(0.0f, 0.0f);
                                                                                                                                    }
                                                                                                                                    break block173;
                                                                                                                                }
                                                                                                                                if (this.A[var1_1] != 23) break block177;
                                                                                                                                this.z[var1_1].a += this.e[var4_3].a * 0.2f;
                                                                                                                                this.z[var1_1].b += this.e[var4_3].b * 0.2f;
                                                                                                                                if (this.F[var5_4 + this.aR.a] != -5) {
                                                                                                                                    if (this.F[var5_4 - 1] == -5) {
                                                                                                                                        this.z[var1_1].a -= this.aR.b(0.1f, 0.2f);
                                                                                                                                    }
                                                                                                                                    if (this.F[var5_4 + 1] == -5) {
                                                                                                                                        this.z[var1_1].a += this.aR.b(0.1f, 0.2f);
                                                                                                                                    }
                                                                                                                                }
                                                                                                                                this.z[var1_1].a += this.aR.b(-0.01f, 0.01f);
                                                                                                                                this.z[var1_1].b += this.aR.b(0.01f, 0.05f);
                                                                                                                                this.z[var1_1].a(0.9f);
                                                                                                                                var2_2.b(this.z[var1_1]);
                                                                                                                                var5_4 = this.a(var1_1, var2_2);
                                                                                                                                var7_18 = (int)this.aR.d(8.0f);
                                                                                                                                if (var7_18 < 5) {
                                                                                                                                    v21 = var5_4 - this.aR.a;
                                                                                                                                } else if (var7_18 < 6) {
                                                                                                                                    v21 = var5_4 - 1;
                                                                                                                                } else {
                                                                                                                                    if (var7_18 < 7) {
                                                                                                                                        v22 = var5_4;
                                                                                                                                        v23 = 1;
                                                                                                                                    } else {
                                                                                                                                        v22 = var5_4;
                                                                                                                                        v23 = this.aR.a;
                                                                                                                                    }
                                                                                                                                    v21 = v22 + v23;
                                                                                                                                }
                                                                                                                                var6_9 = v21;
                                                                                                                                var8_29 = this.F[var6_9];
                                                                                                                                if (var8_29 >= 0) {
                                                                                                                                    if (var7_18 < 7 && this.P[this.A[var8_29]] == 1 && this.A[var8_29] != 19) {
                                                                                                                                        if (this.aR.d(100.0f) < 10.0f) {
                                                                                                                                            this.b(var1_1, var8_29, var5_4, var6_9);
                                                                                                                                        }
                                                                                                                                    } else {
                                                                                                                                        if (this.A[var8_29] == 43 && this.B[var8_29] < 256) {
                                                                                                                                            this.B[var8_29] = 23;
                                                                                                                                            this.c(var1_1);
                                                                                                                                            return 1;
                                                                                                                                        }
                                                                                                                                        if (this.A[var8_29] == 45 && this.C[var8_29] == 0) {
                                                                                                                                            var6_9 = var7_18 < 5 ? 2 : (var7_18 < 6 ? 1 : (var7_18 < 7 ? 3 : 0));
                                                                                                                                            this.B[var8_29] = 4 | var6_9;
                                                                                                                                            this.C[var8_29] = 23;
                                                                                                                                            this.c(var1_1);
                                                                                                                                            return 1;
                                                                                                                                        }
                                                                                                                                    }
                                                                                                                                }
                                                                                                                                if (this.z[var1_1].a() < 10.0f) {
                                                                                                                                    var6_9 = var5_4;
                                                                                                                                    var6_9 += (int)this.aR.d(5.0f) - 2;
                                                                                                                                    if (this.F[var6_9 += ((int)this.aR.d(5.0f) - 2) * this.aR.a] < 0) {
                                                                                                                                        return 0;
                                                                                                                                    }
                                                                                                                                    if (this.P[this.A[this.F[var6_9]]] != 3) {
                                                                                                                                        return 0;
                                                                                                                                    }
                                                                                                                                }
                                                                                                                                var9_37 = false;
                                                                                                                                var10_44 = (int)this.y[var1_1].a & 65532;
                                                                                                                                var11_50 = (int)this.y[var1_1].b & 65532;
                                                                                                                                var12_56 = dust.b(var10_44 - 10, this.c);
                                                                                                                                var13_61 = dust.b(var11_50 - 10, this.c);
                                                                                                                                var14_66 = dust.c(var10_44 + 10, this.aR.a - this.c - 1);
                                                                                                                                var15_70 = dust.c(var11_50 + 10, (this.b - 1) * this.c - 1);
                                                                                                                                var16_74 = var13_61;
                                                                                                                                while (var16_74 <= var15_70) {
                                                                                                                                    var17_78 = var12_56;
                                                                                                                                    while (var17_78 <= var14_66) {
                                                                                                                                        var18_82 = (var17_78 - var10_44) * (var17_78 - var10_44) + (var16_74 - var11_50) * (var16_74 - var11_50);
                                                                                                                                        if (var18_82 <= 100) {
                                                                                                                                            var6_9 = var16_74 * this.aR.a + var17_78;
                                                                                                                                            if (this.F[var6_9] >= 0) {
                                                                                                                                                this.z[this.F[var6_9]].a += ((float)var17_78 - this.y[var1_1].a) * 10.0f;
                                                                                                                                                this.z[this.F[var6_9]].b += ((float)var16_74 - this.y[var1_1].b) * 10.0f;
                                                                                                                                            }
                                                                                                                                            if ((var16_74 & 3) + (var17_78 & 3) == 0 && this.l[var6_9 = (var16_74 >> 2) * this.a + (var17_78 >> 2)] <= 0) {
                                                                                                                                                if (dust.c(var17_78 - var10_44) >= 1) {
                                                                                                                                                    this.e[var6_9].a += (float)(10 / (var17_78 - var10_44));
                                                                                                                                                }
                                                                                                                                                if (dust.c(var16_74 - var11_50) >= 1) {
                                                                                                                                                    this.e[var6_9].b += (float)(10 / (var16_74 - var11_50));
                                                                                                                                                }
                                                                                                                                            }
                                                                                                                                        }
                                                                                                                                        ++var17_78;
                                                                                                                                    }
                                                                                                                                    ++var16_74;
                                                                                                                                }
                                                                                                                                v10 = this.A;
                                                                                                                                v11 = var1_1;
                                                                                                                                v12 = 4;
                                                                                                                                break block161;
                                                                                                                            }
                                                                                                                            if (this.A[var1_1] != 24) break block178;
                                                                                                                            var7_19 = this.F[var5_4 + this.aR.a];
                                                                                                                            if (this.B[var1_1] == 0 && var7_19 >= 0 && (this.A[var7_19] == 6 || this.A[var7_19] == 10 || this.A[var7_19] == 17 || this.A[var7_19] == 29 || this.A[var7_19] == 35 || this.A[var7_19] == 38 || this.A[var7_19] == 43 || this.A[var7_19] == 45)) {
                                                                                                                                this.B[var1_1] = this.A[var7_19] << 2;
                                                                                                                            }
                                                                                                                            if (this.B[var1_1] == 0) {
                                                                                                                                var2_2.b += this.aR.b(0.01f, 0.2f);
                                                                                                                                if (var7_19 != -5) {
                                                                                                                                    if (this.F[var5_4 - 1] == -5) {
                                                                                                                                        this.z[var1_1].a -= this.aR.b(0.0f, 0.1f);
                                                                                                                                    }
                                                                                                                                    if (this.F[var5_4 + 1] == -5) {
                                                                                                                                        this.z[var1_1].a += this.aR.b(0.0f, 0.1f);
                                                                                                                                    }
                                                                                                                                }
                                                                                                                            } else {
                                                                                                                                var2_2.a(0.0f, 0.0f);
                                                                                                                            }
                                                                                                                            var2_2.b(this.z[var1_1]);
                                                                                                                            this.z[var1_1].a(0.85f);
                                                                                                                            var5_4 = this.a(var1_1, var2_2);
                                                                                                                            if (this.B[var1_1] == 0) {
                                                                                                                                return 0;
                                                                                                                            }
                                                                                                                            if (this.aR.h[this.aR.g] - this.D < 1000) {
                                                                                                                                return 0;
                                                                                                                            }
                                                                                                                            var8_30 = new int[]{1, this.aR.a, -1, -this.aR.a};
                                                                                                                            var9_38 = this.B[var1_1] & 3;
                                                                                                                            var6_10 = var5_4 + var8_30[var9_38];
                                                                                                                            var7_19 = this.F[var6_10];
                                                                                                                            if (var7_19 <= -4) {
                                                                                                                                this.B[var1_1] = this.B[var1_1] & -4 | var9_38 + 1 & 3;
                                                                                                                                if ((var6_10 = this.a((float)(var6_10 % this.aR.a), (float)(var6_10 / this.aR.a), 24)) > 0) {
                                                                                                                                    this.B[var6_10] = this.B[var1_1];
                                                                                                                                }
                                                                                                                                this.A[var1_1] = this.B[var1_1] >> 2;
                                                                                                                                v10 = this.B;
                                                                                                                                v11 = var1_1;
                                                                                                                                v12 = 0;
                                                                                                                            } else {
                                                                                                                                if (var7_19 >= 0) {
                                                                                                                                    if (this.A[var7_19] == this.B[var1_1] >> 2) {
                                                                                                                                        this.B[var1_1] = this.B[var1_1] & -4 | var9_38 - 1 & 3;
                                                                                                                                    }
                                                                                                                                    this.A[var7_19] = this.A[var1_1];
                                                                                                                                    this.B[var7_19] = this.B[var1_1];
                                                                                                                                    this.C[var7_19] = 0;
                                                                                                                                    this.c(var1_1);
                                                                                                                                    return 1;
                                                                                                                                }
                                                                                                                                v10 = this.B;
                                                                                                                                v11 = var1_1;
                                                                                                                                v12 = this.B[var1_1] & -4 | var9_38 + 1 & 3;
                                                                                                                            }
                                                                                                                            break block161;
                                                                                                                        }
                                                                                                                        if (this.A[var1_1] != 25) break block179;
                                                                                                                        var2_2.a(0.0f, 0.0f);
                                                                                                                        var5_4 = this.a(var1_1, var2_2);
                                                                                                                        var5_4 += (int)this.aR.d(5.0f) - 2;
                                                                                                                        var7_20 = this.F[var5_4 += ((int)this.aR.d(5.0f) - 2) * this.aR.a];
                                                                                                                        if (var7_20 < 0) break block173;
                                                                                                                        if (this.A[var7_20] != 2) break block180;
                                                                                                                        v10 = this.A;
                                                                                                                        v11 = var7_20;
                                                                                                                        v12 = 4;
                                                                                                                        break block161;
                                                                                                                    }
                                                                                                                    if (this.A[var7_20] == 3 || this.A[var7_20] == 27 || this.A[var7_20] == 37) {
                                                                                                                        this.c(var1_1);
                                                                                                                        return 1;
                                                                                                                    }
                                                                                                                    if (this.A[var7_20] != 5) break block181;
                                                                                                                    v10 = this.A;
                                                                                                                    v11 = var7_20;
                                                                                                                    v12 = 4;
                                                                                                                    break block161;
                                                                                                                }
                                                                                                                if (this.A[var7_20] != 6) break block182;
                                                                                                                v10 = this.A;
                                                                                                                v11 = var7_20;
                                                                                                                v12 = 25;
                                                                                                                break block161;
                                                                                                            }
                                                                                                            if (this.A[var7_20] != 11) break block183;
                                                                                                            v10 = this.A;
                                                                                                            v11 = var7_20;
                                                                                                            v12 = 3;
                                                                                                            break block161;
                                                                                                        }
                                                                                                        if (this.A[var7_20] != 13) break block184;
                                                                                                        v10 = this.A;
                                                                                                        v11 = var7_20;
                                                                                                        v12 = 4;
                                                                                                        break block161;
                                                                                                    }
                                                                                                    if (this.A[var7_20] != 24) break block185;
                                                                                                    v10 = this.A;
                                                                                                    v11 = var7_20;
                                                                                                    v12 = 4;
                                                                                                    break block161;
                                                                                                }
                                                                                                if (this.A[var7_20] != 35) break block173;
                                                                                                v10 = this.A;
                                                                                                v11 = var7_20;
                                                                                                v12 = 4;
                                                                                                break block161;
                                                                                            }
                                                                                            if (this.A[var1_1] != 26) break block186;
                                                                                            var2_2.b += this.aR.b(0.0f, -0.02f);
                                                                                            var2_2.b(this.z[var1_1]);
                                                                                            this.z[var1_1].a(0.9f);
                                                                                            var5_4 = this.a(var1_1, var2_2);
                                                                                            var7_21 = (int)this.aR.d(4.0f);
                                                                                            if (var7_21 < 1) {
                                                                                                v24 = var5_4 - this.aR.a;
                                                                                            } else if (var7_21 < 2) {
                                                                                                v24 = var5_4 - 1;
                                                                                            } else {
                                                                                                if (var7_21 < 3) {
                                                                                                    v25 = var5_4;
                                                                                                    v26 = 1;
                                                                                                } else {
                                                                                                    v25 = var5_4;
                                                                                                    v26 = this.aR.a;
                                                                                                }
                                                                                                v24 = v25 + v26;
                                                                                            }
                                                                                            var6_11 = v24;
                                                                                            var8_31 = this.F[var6_11];
                                                                                            if (var8_31 >= 0) {
                                                                                                if (var7_21 < 3 && (this.P[this.A[var8_31]] == 1 || this.P[this.A[var8_31]] == 2)) {
                                                                                                    this.b(var1_1, var8_31, var5_4, var6_11);
                                                                                                } else if (this.A[var8_31] == 26) {
                                                                                                    this.z[var1_1].a += this.aR.b(-0.2f, 0.2f);
                                                                                                    this.z[var1_1].b += this.aR.b(-0.2f, 0.2f);
                                                                                                } else if (this.A[var8_31] == 45 && this.C[var8_31] == 0) {
                                                                                                    var6_11 = var7_21 < 1 ? 2 : (var7_21 < 2 ? 1 : (var7_21 < 3 ? 3 : 0));
                                                                                                    this.B[var8_31] = 4 | var6_11;
                                                                                                    this.C[var8_31] = 26;
                                                                                                    this.c(var1_1);
                                                                                                    return 1;
                                                                                                }
                                                                                            }
                                                                                            if (this.B[var1_1] == 0) {
                                                                                                var6_11 = var5_4;
                                                                                                var6_11 += (int)this.aR.d(5.0f) - 2;
                                                                                                if (this.F[var6_11 += ((int)this.aR.d(5.0f) - 2) * this.aR.a] < 0) {
                                                                                                    return 0;
                                                                                                }
                                                                                                if (this.P[this.A[this.F[var6_11]]] != 3) {
                                                                                                    return 0;
                                                                                                }
                                                                                            } else if (this.B[var1_1] < 2) {
                                                                                                v27 = var1_1;
                                                                                                this.B[v27] = this.B[v27] + 1;
                                                                                                return 0;
                                                                                            }
                                                                                            var9_39 = false;
                                                                                            var10_45 = (int)this.y[var1_1].a;
                                                                                            var11_51 = (int)this.y[var1_1].b;
                                                                                            var12_57 = dust.b(var10_45 - 10, this.c);
                                                                                            var13_62 = dust.b(var11_51 - 10, this.c);
                                                                                            var14_67 = dust.c(var10_45 + 10, this.aR.a - this.c - 1);
                                                                                            var15_71 = dust.c(var11_51 + 10, (this.b - 1) * this.c - 1);
                                                                                            var16_75 = var13_62;
                                                                                            while (var16_75 <= var15_71) {
                                                                                                var17_79 = var12_57;
                                                                                                while (var17_79 <= var14_67) {
                                                                                                    var18_83 = (var17_79 - var10_45) * (var17_79 - var10_45) + (var16_75 - var11_51) * (var16_75 - var11_51);
                                                                                                    if (var18_83 <= 100) {
                                                                                                        var6_11 = var16_75 * this.aR.a + var17_79;
                                                                                                        var8_31 = this.F[var6_11];
                                                                                                        if (var8_31 >= 0 && this.A[var8_31] == 26) {
                                                                                                            this.B[var8_31] = 1;
                                                                                                        }
                                                                                                        if (var8_31 <= -4 && this.aR.d(100.0f) < 1.0f) {
                                                                                                            this.a((float)var17_79, (float)var16_75, 4);
                                                                                                        }
                                                                                                    }
                                                                                                    ++var17_79;
                                                                                                }
                                                                                                ++var16_75;
                                                                                            }
                                                                                            v28 = var4_3;
                                                                                            this.g[v28] = this.g[v28] + 2.0f;
                                                                                            this.i -= 2.0f;
                                                                                            this.A[var1_1] = 4;
                                                                                            v10 = this.B;
                                                                                            v11 = var1_1;
                                                                                            v12 = 0;
                                                                                            break block161;
                                                                                        }
                                                                                        if (this.A[var1_1] != 27) break block187;
                                                                                        if (this.B[var1_1] == 1) {
                                                                                            this.c(var1_1);
                                                                                            return 1;
                                                                                        }
                                                                                        this.z[var1_1].a += this.e[var4_3].a * 0.3f;
                                                                                        this.z[var1_1].b += this.e[var4_3].b * 0.3f;
                                                                                        if (this.F[var5_4 + this.aR.a] != -5) {
                                                                                            if (this.F[var5_4 - 1] == -5) {
                                                                                                this.z[var1_1].a -= this.aR.b(0.1f, 0.2f);
                                                                                            }
                                                                                            if (this.F[var5_4 + 1] == -5) {
                                                                                                this.z[var1_1].a += this.aR.b(0.1f, 0.2f);
                                                                                            }
                                                                                        }
                                                                                        this.z[var1_1].a += this.aR.b(-0.01f, 0.01f);
                                                                                        this.z[var1_1].b += this.aR.b(0.01f, 0.05f);
                                                                                        this.z[var1_1].a(0.9f);
                                                                                        var2_2.b(this.z[var1_1]);
                                                                                        var5_4 = this.a(var1_1, var2_2);
                                                                                        var7_22 = (int)this.aR.d(8.0f);
                                                                                        if (var7_22 < 5) {
                                                                                            v29 = var5_4 - this.aR.a;
                                                                                        } else if (var7_22 < 6) {
                                                                                            v29 = var5_4 - 1;
                                                                                        } else {
                                                                                            if (var7_22 < 7) {
                                                                                                v30 = var5_4;
                                                                                                v31 = 1;
                                                                                            } else {
                                                                                                v30 = var5_4;
                                                                                                v31 = this.aR.a;
                                                                                            }
                                                                                            v29 = v30 + v31;
                                                                                        }
                                                                                        var6_12 = v29;
                                                                                        var8_32 = this.F[var6_12];
                                                                                        if (var8_32 >= 0) {
                                                                                            if (var7_22 < 7 && (this.P[this.A[var8_32]] == 1 && this.A[var8_32] != 19 || this.A[var8_32] == 23 || this.A[var8_32] == 37)) {
                                                                                                if (this.aR.d(100.0f) < 10.0f) {
                                                                                                    this.b(var1_1, var8_32, var5_4, var6_12);
                                                                                                }
                                                                                            } else if (this.A[var8_32] == 10) {
                                                                                                if (this.aR.d(100.0f) < 50.0f) {
                                                                                                    this.A[var1_1] = 10;
                                                                                                }
                                                                                            } else if (this.A[var8_32] == 16) {
                                                                                                this.A[var8_32] = 27;
                                                                                                this.B[var8_32] = 1;
                                                                                                this.B[var1_1] = 1;
                                                                                            } else {
                                                                                                if (this.A[var8_32] == 43 && this.B[var8_32] < 256) {
                                                                                                    this.B[var8_32] = 27;
                                                                                                    this.c(var1_1);
                                                                                                    return 1;
                                                                                                }
                                                                                                if (this.A[var8_32] == 45 && this.C[var8_32] == 0) {
                                                                                                    var6_12 = var7_22 < 5 ? 2 : (var7_22 < 6 ? 1 : (var7_22 < 7 ? 3 : 0));
                                                                                                    this.B[var8_32] = 4 | var6_12;
                                                                                                    this.C[var8_32] = 27;
                                                                                                    this.c(var1_1);
                                                                                                    return 1;
                                                                                                }
                                                                                            }
                                                                                        }
                                                                                        if (this.z[var1_1].a() > 2.0f) {
                                                                                            var9_40 = 0;
                                                                                            var10_46 = false;
                                                                                            var11_52 = (int)this.y[var1_1].a;
                                                                                            var12_58 = (int)this.y[var1_1].b;
                                                                                            var13_63 = dust.b(var11_52 - 4, this.c);
                                                                                            var14_68 = dust.b(var12_58 - 4, this.c);
                                                                                            var15_72 = dust.c(var11_52 + 4, this.aR.a - this.c - 1);
                                                                                            var16_76 = dust.c(var12_58 + 4, (this.b - 1) * this.c - 1);
                                                                                            var17_80 = var14_68;
                                                                                            while (var17_80 <= var16_76) {
                                                                                                var18_84 = var13_63;
                                                                                                while (var18_84 <= var15_72) {
                                                                                                    if ((var18_84 - var11_52) * (var18_84 - var11_52) + (var17_80 - var12_58) * (var17_80 - var12_58) <= 16 && (var8_32 = this.F[var17_80 * this.aR.a + var18_84]) >= 0 && this.A[var8_32] == 27 && this.B[var8_32] == 0) {
                                                                                                        this.B[var8_32] = 1;
                                                                                                        ++var9_40;
                                                                                                    }
                                                                                                    ++var18_84;
                                                                                                }
                                                                                                ++var17_80;
                                                                                            }
                                                                                            if ((var9_40 = dust.c(dust.b(5, var9_40), this.af - this.ae)) < 5) {
                                                                                                return 0;
                                                                                            }
                                                                                            var18_84 = ((int)dust.a(this.y[var1_1].a, 8.0f, 407.0f) >> 2 << 2) + 2;
                                                                                            var19_85 = ((int)dust.a(this.y[var1_1].b, 8.0f, 307.0f) >> 2 << 2) + 2;
                                                                                            ++this.ag;
                                                                                            var3_86 = 0;
                                                                                            while (var3_86 < var9_40) {
                                                                                                this.a((float)var18_84 + this.aR.bn[512 * var3_86 / var9_40][0] * 1.9f, (float)var19_85 + this.aR.bn[512 * var3_86 / var9_40][1] * 1.9f);
                                                                                                ++var3_86;
                                                                                            }
                                                                                            ++this.ag;
                                                                                            this.c(var1_1);
                                                                                            return 1;
                                                                                        }
                                                                                        break block173;
                                                                                    }
                                                                                    if (this.A[var1_1] != 28) break block188;
                                                                                    this.F[var5_4] = var1_1;
                                                                                    this.z[var1_1].a(0.0f, 0.0f);
                                                                                    if (this.B[var1_1] >= 4096) break block189;
                                                                                    if (this.B[var1_1] == 0) {
                                                                                        this.B[var1_1] = var4_3 % 1000;
                                                                                    }
                                                                                    var10_47 = this.B[var1_1] >> 10;
                                                                                    var11_53 = this.B[var1_1] & 1023;
                                                                                    var11_53 = var11_53 * 73 % 955 + 44;
                                                                                    if (var10_47 != 0) break block190;
                                                                                    var9_41 = var11_53 % 3;
                                                                                    if (var9_41 != 0) break block191;
                                                                                    var7_23 = -1;
                                                                                    var8_33 = false;
                                                                                    v32 = 1;
                                                                                    break block192;
                                                                                }
                                                                                if (var9_41 != 1) break block193;
                                                                                var7_23 = 1;
                                                                                var8_33 = false;
                                                                                v32 = 3;
                                                                                break block192;
                                                                            }
                                                                            v33 = 0;
                                                                            ** GOTO lbl615
                                                                        }
                                                                        if (var10_47 != 1) break block194;
                                                                        var9_41 = var11_53 % 2;
                                                                        if (var9_41 > 0) break block195;
                                                                        var7_23 = -1;
                                                                        var8_33 = false;
                                                                        v32 = 1;
                                                                        break block192;
                                                                    }
                                                                    v33 = 0;
                                                                    ** GOTO lbl615
                                                                }
                                                                var9_41 = var11_53 % 2;
                                                                if (var9_41 <= 0) {
                                                                    var7_23 = 1;
                                                                    var8_33 = false;
                                                                    v32 = 3;
                                                                } else {
                                                                    v33 = 0;
lbl615:
                                                                    // 3 sources

                                                                    var7_23 = v33;
                                                                    var8_33 = true;
                                                                    v32 = 0;
                                                                }
                                                            }
                                                            var10_47 = v32;
                                                            var6_13 = (int)(this.y[var1_1].b + (float)var8_33) * this.aR.a + (int)(this.y[var1_1].a + (float)var7_23);
                                                            var12_59 = var10_47 << 10 | var11_53;
                                                            var13_64 = this.F[var6_13];
                                                            if (var13_64 > -4) break block196;
                                                            this.F[var5_4] = -5;
                                                            this.y[var1_1].a += (float)var7_23;
                                                            this.y[var1_1].b += (float)var8_33;
                                                            this.F[var6_13] = var1_1;
                                                            this.B[var1_1] = var12_59;
                                                            v10 = this.G;
                                                            v11 = var1_1;
                                                            v12 = var6_13;
                                                            break block161;
                                                        }
                                                        if (var13_64 < 0) ** GOTO lbl668
                                                        if (this.A[var13_64] == 28 && this.B[var13_64] == var12_59) break block173;
                                                        if (this.A[var13_64] == 28) {
                                                            this.c(var1_1);
                                                            return 1;
                                                        }
                                                        if (this.A[var13_64] != 29 && this.A[var13_64] != 41) break block197;
                                                        if (this.A[var13_64] != 29) break block198;
                                                        v34 = this.B;
                                                        v35 = var13_64;
                                                        v36 = 6000;
                                                        break block199;
                                                    }
                                                    if (this.A[var13_64] != 41) break block200;
                                                    v34 = this.B;
                                                    v35 = var13_64;
                                                    v36 = 6100;
                                                }
                                                v34[v35] = v36 + var10_47;
                                            }
                                            this.A[var13_64] = 28;
                                            this.c(var1_1);
                                            return 1;
                                        }
                                        if (this.P[this.A[var13_64]] != 1 && this.P[this.A[var13_64]] != 2 && this.A[var13_64] != 20 && this.A[var13_64] != 6 && this.A[var13_64] != 10 && this.A[var13_64] != 35 && this.A[var13_64] != 38) break block201;
                                        v10 = this.B;
                                        v11 = var1_1;
                                        v12 = 5000;
                                        break block161;
                                    }
                                    if (this.A[var13_64] == 44) {
                                        this.b(var1_1, var13_64, var5_4, var6_13);
                                    } else {
                                        this.c(var1_1);
                                        return 1;
lbl668:
                                        // 1 sources

                                        if (var13_64 > -4) {
                                            this.c(var1_1);
                                            return 1;
                                        }
                                    }
                                    break block173;
                                }
                                if (this.B[var1_1] != 5000) break block202;
                                var7_24 = false;
                                var8_34 = (int)this.y[var1_1].a;
                                var9_42 = (int)this.y[var1_1].b;
                                var10_48 = dust.b(var8_34 - 6, this.c);
                                var11_54 = dust.b(var9_42 - 6, this.c);
                                var12_60 = dust.c(var8_34 + 6, this.aR.a - this.c - 1);
                                var13_65 = dust.c(var9_42 + 6, (this.b - 1) * this.c - 1);
                                var14_69 = var11_54;
                                while (var14_69 <= var13_65) {
                                    var15_73 = var10_48;
                                    while (var15_73 <= var12_60) {
                                        block203: {
                                            block206: {
                                                block205: {
                                                    block204: {
                                                        var16_77 = (var15_73 - var8_34) * (var15_73 - var8_34) + (var14_69 - var9_42) * (var14_69 - var9_42);
                                                        if (var16_77 > 36 || (var17_81 = this.F[var6_14 = var14_69 * this.aR.a + var15_73]) < 0 || this.A[var17_81] == 28) break block203;
                                                        if (this.A[var17_81] != 10) break block204;
                                                        v37 = this.A;
                                                        v38 = var17_81;
                                                        v39 = 11;
                                                        break block205;
                                                    }
                                                    if (this.A[var17_81] != 15 || this.B[var17_81] <= 0 || this.B[var17_81] >= 5000) break block206;
                                                    v40 = var17_81;
                                                    v38 = v40;
                                                    v37 = this.B;
                                                    v39 = this.B[v40] + 100;
                                                }
                                                v37[v38] = v39;
                                            }
                                            this.z[var17_81].a -= ((float)var15_73 - this.y[var1_1].a) * 3.0f;
                                            this.z[var17_81].b -= ((float)var14_69 - this.y[var1_1].b) * 3.0f;
                                        }
                                        ++var15_73;
                                    }
                                    ++var14_69;
                                }
                                this.c(var1_1);
                                return 1;
                            }
                            if (this.B[var1_1] < 7000) break block207;
                            if (this.B[var1_1] == 7000) {
                                var7_25 = new int[]{this.aR.a, -1, -this.aR.a, 1};
                                var3_87 = 0;
                                while (var3_87 < 4) {
                                    var8_35 = this.F[var5_4 + var7_25[var3_87]];
                                    if (var8_35 >= 0 && this.A[var8_35] == 38) {
                                        this.A[var8_35] = 28;
                                        this.B[var8_35] = 7000;
                                    }
                                    ++var3_87;
                                }
                            }
                            v41 = var1_1;
                            this.B[v41] = this.B[v41] + 1;
                            if (this.B[var1_1] <= 7020) break block173;
                            this.A[var1_1] = 38;
                            v10 = this.B;
                            v11 = var1_1;
                            v12 = 0;
                            break block161;
                        }
                        if (this.B[var1_1] < 6000) break block173;
                        var7_26 = this.B[var1_1] & 3;
                        var8_36 = (this.B[var1_1] & 65532) == 6000 ? 29 : 41;
                        var9_43 = new int[]{this.aR.a, -1, -this.aR.a, 1};
                        var3_88 = 0;
                        while (var3_88 < 4) {
                            block208: {
                                block209: {
                                    block212: {
                                        block211: {
                                            block210: {
                                                if (var3_88 == 2 || (var10_49 = this.F[var6_15 = var5_4 + var9_43[var7_26 + var3_88 & 3]]) < 0) break block208;
                                                if (this.A[var10_49] != 29 && this.A[var10_49] != 41) break block209;
                                                this.b(var1_1, var10_49, var5_4, var6_15);
                                                if (this.A[var10_49] != 29) break block210;
                                                v42 = this.B;
                                                v43 = var1_1;
                                                v44 = 6000;
                                                break block211;
                                            }
                                            if (this.A[var10_49] != 41) break block212;
                                            v42 = this.B;
                                            v43 = var1_1;
                                            v44 = 6100;
                                        }
                                        v42[v43] = v44 + (var7_26 + var3_88 & 3);
                                    }
                                    this.A[var10_49] = var8_36;
                                    this.B[var10_49] = 0;
                                    break;
                                }
                                if (this.A[var10_49] == 28 && this.B[var10_49] >= 6000 && this.B[var10_49] < 7000) {
                                    this.A[var1_1] = var8_36;
                                    this.B[var1_1] = 0;
                                    break;
                                }
                                if (this.A[var10_49] == 38) {
                                    this.A[var10_49] = 28;
                                    this.B[var10_49] = 7000;
                                }
                            }
                            ++var3_88;
                        }
                        if (var3_88 != 4) break block173;
                        if (this.F[var5_4 + var9_43[var7_26]] <= -4) {
                            var10_49 = (int)this.y[var1_1].a;
                            var11_55 = (int)this.y[var1_1].b;
                            if (var7_26 == 0) {
                                this.a((float)var10_49, (float)(var11_55 + 1), 28);
                            } else if (var7_26 == 1) {
                                this.a((float)(var10_49 - 1), (float)var11_55, 28);
                            } else if (var7_26 == 2) {
                                this.a((float)var10_49, (float)(var11_55 - 1), 28);
                            } else if (var7_26 == 3) {
                                this.a((float)(var10_49 + 1), (float)var11_55, 28);
                            }
                        }
                        this.A[var1_1] = var8_36;
                        v10 = this.B;
                        v11 = var1_1;
                        v12 = 0;
                        break block161;
                    }
                    if (this.A[var1_1] != 29) break block173;
                    this.F[var5_4] = var1_1;
                    this.z[var1_1].a(0.0f, 0.0f);
                    var5_4 += (int)this.aR.d(5.0f) - 2;
                    var7_27 = this.F[var5_4 += ((int)this.aR.d(5.0f) - 2) * this.aR.a];
                    if (var7_27 < 0) break block173;
                    if (this.A[var7_27] != 3) break block213;
                    if (!(this.aR.d(100.0f) < 2.0f)) break block173;
                    v10 = this.A;
                    v11 = var1_1;
                    v12 = 2;
                    break block161;
                }
                if (this.A[var7_27] != 20 || !(this.aR.d(100.0f) < 2.0f)) break block173;
                v10 = this.A;
                v11 = var1_1;
                v12 = 20;
            }
            v10[v11] = v12;
        }
        return 0;
    }

    private int e(int n, e e2) {
        block223: {
            int n2;
            int n3;
            block233: {
                int n4;
                int n5;
                block234: {
                    int n6;
                    block237: {
                        int n7;
                        int[] nArray;
                        block236: {
                            block235: {
                                block228: {
                                    block232: {
                                        int n8;
                                        block231: {
                                            int n9;
                                            int n10;
                                            float f;
                                            int n11;
                                            int[] nArray2;
                                            block229: {
                                                block230: {
                                                    block227: {
                                                        int n12;
                                                        int n13;
                                                        block226: {
                                                            block225: {
                                                                block224: {
                                                                    int n14;
                                                                    block215: {
                                                                        int n15;
                                                                        int n16;
                                                                        int n17;
                                                                        block213: {
                                                                            int n18;
                                                                            block220: {
                                                                                block222: {
                                                                                    int n19;
                                                                                    int[] nArray3;
                                                                                    int n20;
                                                                                    block214: {
                                                                                        int n21;
                                                                                        block216: {
                                                                                            block221: {
                                                                                                block219: {
                                                                                                    block218: {
                                                                                                        int n22;
                                                                                                        int n23;
                                                                                                        int n24;
                                                                                                        int n25;
                                                                                                        int n26;
                                                                                                        int n27;
                                                                                                        int n28;
                                                                                                        int n29;
                                                                                                        int n30;
                                                                                                        int n31;
                                                                                                        int n32;
                                                                                                        int n33;
                                                                                                        block217: {
                                                                                                            n3 = ((int)this.y[n].b >> 2) * this.a + ((int)this.y[n].a >> 2);
                                                                                                            n2 = this.G[n];
                                                                                                            this.F[n2] = -5;
                                                                                                            e2.a(this.e[n3]);
                                                                                                            if (this.A[n] == 31) {
                                                                                                                int n34;
                                                                                                                int n35;
                                                                                                                this.z[n].b += 0.03f;
                                                                                                                this.z[n].a(0.92f);
                                                                                                                e2.b(this.z[n]);
                                                                                                                n2 = this.a(n, e2);
                                                                                                                if (this.B[n] != 0) {
                                                                                                                    if (this.B[n] == 31) {
                                                                                                                        this.c(n);
                                                                                                                        return 1;
                                                                                                                    }
                                                                                                                    if (this.aR.d(100.0f) > 5.0f) {
                                                                                                                        return 0;
                                                                                                                    }
                                                                                                                    if (this.B[n] == 10) {
                                                                                                                        this.A[n] = 11;
                                                                                                                        this.B[n] = 0;
                                                                                                                    } else if (this.B[n] == 6 || this.B[n] == 19 || this.B[n] == 35) {
                                                                                                                        this.A[n] = 2;
                                                                                                                        this.B[n] = 0;
                                                                                                                    } else if (this.B[n] == 23 || this.B[n] == 25) {
                                                                                                                        this.A[n] = 4;
                                                                                                                        this.B[n] = 1;
                                                                                                                    } else if (this.B[n] == 27) {
                                                                                                                        this.A[n] = 12;
                                                                                                                        this.B[n] = 0;
                                                                                                                    } else if (this.B[n] == 29) {
                                                                                                                        this.A[n] = 29;
                                                                                                                        this.B[n] = 0;
                                                                                                                    } else if (this.B[n] == 38) {
                                                                                                                        this.A[n] = 19;
                                                                                                                        this.B[n] = 0;
                                                                                                                    } else if (this.B[n] == 45) {
                                                                                                                        this.A[n] = 42;
                                                                                                                        this.B[n] = 0;
                                                                                                                    } else {
                                                                                                                        this.c(n);
                                                                                                                        return 1;
                                                                                                                    }
                                                                                                                    return 0;
                                                                                                                }
                                                                                                                int n36 = n2;
                                                                                                                n36 += (int)this.aR.d(3.0f) - 1;
                                                                                                                int n37 = this.F[n36 += ((int)this.aR.d(3.0f) - 1) * this.aR.a];
                                                                                                                if (n37 < 0) {
                                                                                                                    return 0;
                                                                                                                }
                                                                                                                if (this.A[n37] == 31 || this.A[n37] == 14) {
                                                                                                                    return 0;
                                                                                                                }
                                                                                                                boolean bl = false;
                                                                                                                int n38 = (int)this.y[n].a;
                                                                                                                int n39 = (int)this.y[n].b;
                                                                                                                int n40 = dust.b(n38 - 4, this.c);
                                                                                                                int n41 = dust.b(n39 - 4, this.c);
                                                                                                                int n42 = dust.c(n38 + 4, this.aR.a - this.c - 1);
                                                                                                                int n43 = dust.c(n39 + 4, (this.b - 1) * this.c - 1);
                                                                                                                e2.a(0.0f, 0.0f);
                                                                                                                int n44 = n41;
                                                                                                                while (n44 <= n43) {
                                                                                                                    n35 = n40;
                                                                                                                    while (n35 <= n42) {
                                                                                                                        n34 = (n35 - n38) * (n35 - n38) + (n44 - n39) * (n44 - n39);
                                                                                                                        if (n34 <= 16 && (n37 = this.F[n36 = n44 * this.aR.a + n35]) >= 0 && this.A[n37] != 31) {
                                                                                                                            e2.a += this.y[n].a - (float)n35;
                                                                                                                            e2.b += this.y[n].b - (float)n44;
                                                                                                                        }
                                                                                                                        ++n35;
                                                                                                                    }
                                                                                                                    ++n44;
                                                                                                                }
                                                                                                                e2.d();
                                                                                                                n35 = n41;
                                                                                                                while (n35 <= n43) {
                                                                                                                    n34 = n40;
                                                                                                                    while (n34 <= n42) {
                                                                                                                        int n45 = (n34 - n38) * (n34 - n38) + (n35 - n39) * (n35 - n39);
                                                                                                                        if (n45 <= 16 && (n37 = this.F[n36 = n35 * this.aR.a + n34]) >= 0 && this.A[n37] != 14) {
                                                                                                                            this.z[n37].a += e2.a + (this.y[n].a - (float)n34);
                                                                                                                            this.z[n37].b += e2.b + (this.y[n].b - (float)n35);
                                                                                                                            if (this.A[n37] != 31 || this.B[n37] == 0) {
                                                                                                                                this.C[n37] = 0;
                                                                                                                                this.B[n37] = this.A[n37];
                                                                                                                                this.A[n37] = 31;
                                                                                                                            }
                                                                                                                        }
                                                                                                                        ++n34;
                                                                                                                    }
                                                                                                                    ++n35;
                                                                                                                }
                                                                                                                this.c(n);
                                                                                                                return 1;
                                                                                                            }
                                                                                                            if (this.A[n] != 33) break block215;
                                                                                                            this.F[n2] = n;
                                                                                                            this.z[n].a(0.0f, 0.0f);
                                                                                                            n17 = this.B[n] & 0xF;
                                                                                                            n16 = this.B[n] >> 4 & 0xF;
                                                                                                            n15 = this.B[n] >> 8;
                                                                                                            if (++n16 == 1) {
                                                                                                                this.B[n] = n15 << 8 | n16 << 4 | n17;
                                                                                                                return 0;
                                                                                                            }
                                                                                                            if (n16 > 12) {
                                                                                                                if (n15 == 38) {
                                                                                                                    this.A[n] = 38;
                                                                                                                    this.B[n] = 0;
                                                                                                                } else {
                                                                                                                    this.c(n);
                                                                                                                }
                                                                                                                return 1;
                                                                                                            }
                                                                                                            if (n16 > 8) {
                                                                                                                this.B[n] = n15 << 8 | n16 << 4 | n17;
                                                                                                                return 0;
                                                                                                            }
                                                                                                            if (n17 == 0) {
                                                                                                                int n46;
                                                                                                                n21 = this.F[n2 + this.L[0]];
                                                                                                                if (n21 >= 0 && this.A[n21] == 33) {
                                                                                                                    n21 = -1;
                                                                                                                }
                                                                                                                if ((n46 = this.F[n2 + this.L[1]]) >= 0 && this.A[n46] == 33) {
                                                                                                                    n46 = -1;
                                                                                                                }
                                                                                                                if ((n33 = this.F[n2 + this.L[2]]) >= 0 && this.A[n33] == 33) {
                                                                                                                    n33 = -1;
                                                                                                                }
                                                                                                                if ((n32 = this.F[n2 + this.L[3]]) >= 0 && this.A[n32] == 33) {
                                                                                                                    n32 = -1;
                                                                                                                }
                                                                                                                if ((n31 = this.F[n2 + this.L[4]]) >= 0 && this.A[n31] == 33) {
                                                                                                                    n31 = -1;
                                                                                                                }
                                                                                                                if ((n30 = this.F[n2 + this.L[5]]) >= 0 && this.A[n30] == 33) {
                                                                                                                    n30 = -1;
                                                                                                                }
                                                                                                                if ((n29 = this.F[n2 + this.L[6]]) >= 0 && this.A[n29] == 33) {
                                                                                                                    n29 = -1;
                                                                                                                }
                                                                                                                if ((n28 = this.F[n2 + this.L[7]]) >= 0 && this.A[n28] == 33) {
                                                                                                                    n28 = -1;
                                                                                                                }
                                                                                                                if (n32 >= 0 && n31 >= 0 && n30 >= 0) {
                                                                                                                    n17 = 1;
                                                                                                                } else if (n30 >= 0 && n29 >= 0 && n28 >= 0) {
                                                                                                                    n17 = 3;
                                                                                                                } else if (n28 >= 0 && n21 >= 0 && n46 >= 0) {
                                                                                                                    n17 = 5;
                                                                                                                } else if (n46 >= 0 && n33 >= 0 && n32 >= 0) {
                                                                                                                    n17 = 7;
                                                                                                                } else if (n30 >= 0) {
                                                                                                                    n17 = 2;
                                                                                                                } else if (n28 >= 0) {
                                                                                                                    n17 = 4;
                                                                                                                } else if (n46 >= 0) {
                                                                                                                    n17 = 6;
                                                                                                                } else if (n32 >= 0) {
                                                                                                                    n17 = 8;
                                                                                                                } else {
                                                                                                                    this.B[n] = 0xA0 | n17;
                                                                                                                    return 0;
                                                                                                                }
                                                                                                            }
                                                                                                            if ((n21 = this.F[n2 + this.L[--n17]]) < 0) break block216;
                                                                                                            if (this.A[n21] != 33) break block217;
                                                                                                            int n47 = 2;
                                                                                                            while (n47 <= 4) {
                                                                                                                n21 = this.F[n2 + this.L[n17] * n47];
                                                                                                                if (n21 >= 0) {
                                                                                                                    if (this.A[n21] != 33) break block213;
                                                                                                                } else {
                                                                                                                    if (n21 > -4 || this.aR.h[this.aR.g] - this.D < 1000 || (n20 = this.a((float)((int)this.y[n].a + this.J[n17] * n47), (float)((int)this.y[n].b + this.K[n17] * n47), 33)) <= 0) break block213;
                                                                                                                    break block214;
                                                                                                                }
                                                                                                                ++n47;
                                                                                                            }
                                                                                                            break block213;
                                                                                                        }
                                                                                                        if (this.A[n21] != 29 && this.A[n21] != 41) break block218;
                                                                                                        n33 = this.F[n2 + this.L[n17 + 1 & 7]];
                                                                                                        if (n33 >= 0 && this.A[n33] != 29 && this.A[n33] != 41) {
                                                                                                            n33 = -1;
                                                                                                        }
                                                                                                        if ((n32 = this.F[n2 + this.L[n17 + 2 & 7]]) >= 0 && this.A[n32] != 29 && this.A[n32] != 41) {
                                                                                                            n32 = -1;
                                                                                                        }
                                                                                                        if ((n31 = this.F[n2 + this.L[n17 + 3 & 7]]) >= 0 && this.A[n31] != 29 && this.A[n31] != 41) {
                                                                                                            n31 = -1;
                                                                                                        }
                                                                                                        if ((n30 = this.F[n2 + this.L[n17 + 4 & 7]]) >= 0 && this.A[n30] != 29 && this.A[n30] != 41) {
                                                                                                            n30 = -1;
                                                                                                        }
                                                                                                        if ((n29 = this.F[n2 + this.L[n17 + 5 & 7]]) >= 0 && this.A[n29] != 29 && this.A[n29] != 41) {
                                                                                                            n29 = -1;
                                                                                                        }
                                                                                                        if ((n28 = this.F[n2 + this.L[n17 + 6 & 7]]) >= 0 && this.A[n28] != 29 && this.A[n28] != 41) {
                                                                                                            n28 = -1;
                                                                                                        }
                                                                                                        if ((n27 = this.F[n2 + this.L[n17 + 7 & 7]]) >= 0 && this.A[n27] != 29 && this.A[n27] != 41) {
                                                                                                            n27 = -1;
                                                                                                        }
                                                                                                        boolean bl = false;
                                                                                                        int n48 = this.F[n2 + this.L[n17] + this.L[n17 + 1 & 7]];
                                                                                                        if (n48 >= 0 && this.A[n48] != 29 && this.A[n48] != 41) {
                                                                                                            n48 = -1;
                                                                                                        }
                                                                                                        if ((n26 = this.F[n2 + this.L[n17] + this.L[n17 + 2 & 7]]) >= 0 && this.A[n26] != 29 && this.A[n26] != 41) {
                                                                                                            n26 = -1;
                                                                                                        }
                                                                                                        if ((n25 = this.F[n2 + this.L[n17] + this.L[n17 + 3 & 7]]) >= 0 && this.A[n25] != 29 && this.A[n25] != 41) {
                                                                                                            n25 = -1;
                                                                                                        }
                                                                                                        if ((n24 = this.F[n2 + this.L[n17] + this.L[n17 + 5 & 7]]) >= 0 && this.A[n24] != 29 && this.A[n24] != 41) {
                                                                                                            n24 = -1;
                                                                                                        }
                                                                                                        if ((n23 = this.F[n2 + this.L[n17] + this.L[n17 + 6 & 7]]) >= 0 && this.A[n23] != 29 && this.A[n23] != 41) {
                                                                                                            n23 = -1;
                                                                                                        }
                                                                                                        if ((n22 = this.F[n2 + this.L[n17] + this.L[n17 + 7 & 7]]) >= 0 && this.A[n22] != 29 && this.A[n22] != 41) {
                                                                                                            n22 = -1;
                                                                                                        }
                                                                                                        if ((n17 & 1) == 0) {
                                                                                                            if (n29 >= 0 && n28 >= 0 && n33 < 0 && n32 < 0) {
                                                                                                                n17 = n17 + 1 & 7;
                                                                                                            } else if (n32 >= 0 && n31 >= 0 && n27 < 0 && n28 < 0) {
                                                                                                                n17 = n17 - 1 & 7;
                                                                                                            } else if (n33 >= 0 && n28 >= 0 && n32 < 0 && n31 < 0 && n29 < 0) {
                                                                                                                n17 = n17 + 3 & 7;
                                                                                                            } else if (n48 >= 0 && n23 >= 0 && n26 < 0 && n25 < 0 && n24 < 0) {
                                                                                                                n17 = n17 + 3 & 7;
                                                                                                            } else if (n32 >= 0 && n27 >= 0 && n31 < 0 && n29 < 0 && n28 < 0) {
                                                                                                                n17 = n17 - 3 & 7;
                                                                                                            } else if (n26 >= 0 && n22 >= 0 && n25 < 0 && n24 < 0 && n23 < 0) {
                                                                                                                n17 = n17 - 3 & 7;
                                                                                                            } else if (n28 >= 0 && n33 < 0 && n32 < 0 && n29 < 0) {
                                                                                                                n17 = n17 + 2 & 7;
                                                                                                            } else if (n32 >= 0 && n31 < 0 && n29 < 0 && n28 < 0) {
                                                                                                                n17 = n17 - 2 & 7;
                                                                                                            }
                                                                                                        } else {
                                                                                                            int n49;
                                                                                                            int n50 = this.F[n2 + this.L[n17] + this.L[n17 + 2 & 7] + this.L[n17 + 3 & 7]];
                                                                                                            if (n50 >= 0 && this.A[n50] != 29 && this.A[n50] != 41) {
                                                                                                                n50 = -1;
                                                                                                            }
                                                                                                            if ((n49 = this.F[n2 + this.L[n17] + this.L[n17 + 6 & 7] + this.L[n17 + 5 & 7]]) >= 0 && this.A[n49] != 29 && this.A[n49] != 41) {
                                                                                                                n49 = -1;
                                                                                                            }
                                                                                                            if (n27 >= 0 && n29 >= 0 && n33 < 0 && n30 < 0) {
                                                                                                                n17 = n17 + 1 & 7;
                                                                                                            } else if (n33 >= 0 && n31 >= 0 && n30 < 0 && n27 < 0) {
                                                                                                                n17 = n17 - 1 & 7;
                                                                                                            } else if (n33 >= 0 && n28 >= 0 && n27 >= 0 && n32 < 0 && n29 < 0) {
                                                                                                                n17 = n17 + 3 & 7;
                                                                                                            } else if (n48 >= 0 && n23 >= 0 && n26 < 0 && n25 < 0 && n24 < 0) {
                                                                                                                n17 = n17 + 3 & 7;
                                                                                                            } else if (n26 >= 0 && n24 >= 0 && n25 < 0 && n50 < 0) {
                                                                                                                n17 = n17 + 3 & 7;
                                                                                                            } else if (n33 >= 0 && n32 >= 0 && n27 >= 0 && n31 < 0 && n28 < 0) {
                                                                                                                n17 = n17 - 3 & 7;
                                                                                                            } else if (n26 >= 0 && n22 >= 0 && n25 < 0 && n24 < 0 && n23 < 0) {
                                                                                                                n17 = n17 - 3 & 7;
                                                                                                            } else if (n25 >= 0 && n23 >= 0 && n24 < 0 && n49 < 0) {
                                                                                                                n17 = n17 - 3 & 7;
                                                                                                            } else if (n27 >= 0 && n33 < 0) {
                                                                                                                n17 = n17 + 2 & 7;
                                                                                                            } else if (n33 >= 0 && n27 < 0) {
                                                                                                                n17 = n17 - 2 & 7;
                                                                                                            }
                                                                                                        }
                                                                                                        break block213;
                                                                                                    }
                                                                                                    if (this.A[n21] != 2 && this.A[n21] != 5 && this.A[n21] != 6 && this.A[n21] != 13 && this.A[n21] != 24 && this.A[n21] != 35) break block219;
                                                                                                    this.A[n21] = 4;
                                                                                                    nArray3 = this.B;
                                                                                                    n19 = n21;
                                                                                                    n18 = 0;
                                                                                                    break block220;
                                                                                                }
                                                                                                if (this.A[n21] != 3 && this.A[n21] != 16 && this.A[n21] != 27 && this.A[n21] != 34 && this.A[n21] != 37 && this.A[n21] != 44) break block221;
                                                                                                this.A[n21] = 33;
                                                                                                nArray3 = this.B;
                                                                                                n19 = n21;
                                                                                                break block222;
                                                                                            }
                                                                                            if (this.A[n21] != 38) break block213;
                                                                                            this.A[n21] = 33;
                                                                                            nArray3 = this.B;
                                                                                            n19 = n21;
                                                                                            n18 = 0x2600 | n17 + 1;
                                                                                            break block220;
                                                                                        }
                                                                                        if (n21 > -4 || this.aR.h[this.aR.g] - this.D < 1000 || (n20 = this.a((float)((int)this.y[n].a + this.J[n17]), (float)((int)this.y[n].b + this.K[n17]), 33)) <= 0) break block213;
                                                                                    }
                                                                                    nArray3 = this.B;
                                                                                    n19 = n20;
                                                                                }
                                                                                n18 = n17 + 1;
                                                                            }
                                                                            nArray3[n19] = n18;
                                                                        }
                                                                        this.B[n] = n15 << 8 | n16 << 4 | n17 + 1;
                                                                        break block223;
                                                                    }
                                                                    if (this.A[n] != 34) break block224;
                                                                    if (this.B[n] >= 100) {
                                                                        this.c(n);
                                                                        return 1;
                                                                    }
                                                                    this.z[n].a += this.e[n3].a * 0.2f;
                                                                    this.z[n].b += this.e[n3].b * 0.2f;
                                                                    if (this.F[n2 + this.aR.a] != -5) {
                                                                        if (this.F[n2 - 1] == -5) {
                                                                            this.z[n].a -= this.aR.b(0.0f, 0.1f);
                                                                        }
                                                                        if (this.F[n2 + 1] == -5) {
                                                                            this.z[n].a += this.aR.b(0.0f, 0.1f);
                                                                        }
                                                                    }
                                                                    this.z[n].a += this.aR.b(-0.01f, 0.01f);
                                                                    this.z[n].b += this.aR.b(0.02f, 0.05f);
                                                                    this.z[n].a(0.9f);
                                                                    e2.b(this.z[n]);
                                                                    n2 = this.a(n, e2);
                                                                    int n51 = (int)this.aR.d(8.0f);
                                                                    if (n51 < 5) {
                                                                        n14 = n2 - this.aR.a;
                                                                    } else if (n51 < 6) {
                                                                        n14 = n2 - 1;
                                                                    } else {
                                                                        int n52;
                                                                        int n53;
                                                                        if (n51 < 7) {
                                                                            n53 = n2;
                                                                            n52 = 1;
                                                                        } else {
                                                                            n53 = n2;
                                                                            n52 = this.aR.a;
                                                                        }
                                                                        n14 = n53 + n52;
                                                                    }
                                                                    int n54 = n14;
                                                                    int n55 = this.F[n54];
                                                                    if (n55 >= 0) {
                                                                        if (this.O[this.A[n55]] != 0) {
                                                                            if (this.aR.d(200.0f) < (float)(200 - this.B[n])) {
                                                                                this.B[n] = dust.a(this.B[n] + this.O[this.A[n55]], 0, 100);
                                                                                this.A[n55] = 34;
                                                                                this.B[n55] = 100;
                                                                            }
                                                                        } else if (this.A[n55] == 45 && this.C[n55] == 0) {
                                                                            n54 = n51 < 5 ? 2 : (n51 < 6 ? 1 : (n51 < 7 ? 3 : 0));
                                                                            this.B[n55] = 4 | n54;
                                                                            this.C[n55] = 34;
                                                                            this.c(n);
                                                                            return 1;
                                                                        }
                                                                    }
                                                                    break block223;
                                                                }
                                                                if (this.A[n] != 35) break block225;
                                                                e2.a(this.z[n]);
                                                                this.z[n].a(0.3f);
                                                                n2 = this.a(n, e2);
                                                                if (this.aR.h[this.aR.g] - this.D < 1000) {
                                                                    return 0;
                                                                }
                                                                if (this.B[n] == 0) {
                                                                    int n56 = (int)this.y[n].a + (int)this.aR.d(3.0f) - 1;
                                                                    int n57 = (int)this.y[n].b - (int)this.aR.d(2.0f);
                                                                    int n58 = n57 * this.aR.a + n56;
                                                                    int n59 = this.F[n58];
                                                                    if (n59 <= -4) {
                                                                        int n60 = 0;
                                                                        while (n60 < 8) {
                                                                            int n61 = n58 + this.I[n60];
                                                                            n59 = this.F[n61];
                                                                            if (n59 >= 0 && this.A[n59] != 35 && this.A[n59] != 24) {
                                                                                if (!(this.aR.d(100.0f) < 50.0f)) break;
                                                                                this.a((float)n56, (float)n57, 35);
                                                                                break;
                                                                            }
                                                                            ++n60;
                                                                        }
                                                                    }
                                                                    if (this.F[n2 + this.aR.a] <= -4 && this.F[n2 + this.aR.a * 2] <= -4 && this.F[n2 + this.aR.a - 1] <= -4 && this.F[n2 + this.aR.a + 1] <= -4 && this.aR.d(100.0f) < 8.0f && (n58 = this.a((float)((int)this.y[n].a), (float)((int)this.y[n].b + 1), 35)) > 0) {
                                                                        this.B[n58] = 1;
                                                                    }
                                                                } else if (this.B[n] == 1) {
                                                                    int n62;
                                                                    if (this.F[n2 + this.aR.a] <= -4 && this.F[n2 + this.aR.a * 2] <= -4 && this.F[n2 + this.aR.a - 1] <= -4 && this.F[n2 + this.aR.a + 1] <= -4 && this.aR.d(100.0f) < 20.0f && (n62 = this.a((float)((int)this.y[n].a), (float)((int)this.y[n].b + 1), 35)) > 0) {
                                                                        this.B[n62] = 1;
                                                                    }
                                                                    if (this.aR.d(100.0f) < 4.0f) {
                                                                        this.B[n] = 2;
                                                                    }
                                                                }
                                                                break block223;
                                                            }
                                                            if (this.A[n] != 36) break block226;
                                                            e2.b += this.aR.b(0.01f, 0.1f);
                                                            e2.b(this.z[n]);
                                                            this.z[n].a(0.75f);
                                                            n2 = this.a(n, e2);
                                                            n2 += (int)this.aR.d(3.0f) - 1;
                                                            int n63 = this.F[n2 += ((int)this.aR.d(3.0f) - 1) * this.aR.a];
                                                            if (n63 >= 0) {
                                                                if (this.A[n63] == 3) {
                                                                    this.A[n63] = 37;
                                                                    this.B[n63] = 0;
                                                                    this.c(n);
                                                                    return 1;
                                                                }
                                                                if (this.A[n63] == 20 && this.aR.d(100.0f) < 50.0f) {
                                                                    this.c(n);
                                                                    return 1;
                                                                }
                                                            }
                                                            break block223;
                                                        }
                                                        if (this.A[n] != 37) break block227;
                                                        this.z[n].a += this.e[n3].a * 0.2f;
                                                        this.z[n].b += this.e[n3].b * 0.2f;
                                                        if (this.F[n2 + this.aR.a] != -5) {
                                                            if (this.F[n2 - 1] == -5) {
                                                                this.z[n].a -= this.aR.b(0.1f, 0.2f);
                                                            }
                                                            if (this.F[n2 + 1] == -5) {
                                                                this.z[n].a += this.aR.b(0.1f, 0.2f);
                                                            }
                                                        }
                                                        this.z[n].a += this.aR.b(-0.01f, 0.01f);
                                                        this.z[n].b += this.aR.b(0.01f, 0.05f);
                                                        this.z[n].a(0.9f);
                                                        e2.b(this.z[n]);
                                                        int n64 = n2 = this.a(n, e2);
                                                        n64 = n2 + ((int)this.aR.d(5.0f) - 2);
                                                        int n65 = this.F[n64 += ((int)this.aR.d(5.0f) - 2) * this.aR.a];
                                                        if (n65 >= 0 && (this.A[n65] == 5 || this.A[n65] == 6 || this.A[n65] == 29)) {
                                                            this.A[n65] = 2;
                                                            this.B[n65] = 0;
                                                        }
                                                        if ((n13 = (int)this.aR.d(8.0f)) < 5) {
                                                            n12 = n2 - this.aR.a;
                                                        } else if (n13 < 6) {
                                                            n12 = n2 - 1;
                                                        } else {
                                                            int n66;
                                                            int n67;
                                                            if (n13 < 7) {
                                                                n67 = n2;
                                                                n66 = 1;
                                                            } else {
                                                                n67 = n2;
                                                                n66 = this.aR.a;
                                                            }
                                                            n12 = n67 + n66;
                                                        }
                                                        n64 = n12;
                                                        n65 = this.F[n64];
                                                        if (n65 >= 0) {
                                                            if (n13 < 7 && (this.P[this.A[n65]] == 1 && this.A[n65] != 19 || this.A[n65] == 23)) {
                                                                if (this.aR.d(100.0f) < 10.0f) {
                                                                    this.b(n, n65, n2, n64);
                                                                }
                                                            } else if (this.A[n65] == 35) {
                                                                this.A[n65] = 2;
                                                                this.B[n65] = 0;
                                                            } else if (this.A[n65] == 45 && this.C[n65] == 0) {
                                                                n64 = n13 < 5 ? 2 : (n13 < 6 ? 1 : (n13 < 7 ? 3 : 0));
                                                                this.B[n65] = 4 | n64;
                                                                this.C[n65] = 37;
                                                                this.c(n);
                                                                return 1;
                                                            }
                                                        }
                                                        break block223;
                                                    }
                                                    if (this.A[n] != 38) break block228;
                                                    if (this.B[n] != 0) break block229;
                                                    if (!(this.z[n].a() > 1.0f)) break block230;
                                                    nArray2 = this.B;
                                                    n11 = n;
                                                    n8 = 1;
                                                    break block231;
                                                }
                                                this.z[n].a(0.0f, 0.0f);
                                                break block232;
                                            }
                                            if (this.B[n] != 1) break block232;
                                            e2.a(this.z[n]);
                                            float f2 = e2.d() * 0.5f;
                                            if (f < 1.0f) {
                                                f2 = 1.0f;
                                            }
                                            int n68 = 1;
                                            while (n68 < 6) {
                                                n10 = (int)(this.y[n].b + 0.5f + e2.b * (float)n68) * this.aR.a + (int)(this.y[n].a + 0.5f + e2.a * (float)n68);
                                                n9 = this.F[n10];
                                                if (n9 < 0 || this.A[n9] != 38) break;
                                                this.B[n9] = 1;
                                                this.z[n9].a = this.z[n].a * 0.98f;
                                                this.z[n9].b = this.z[n].b * 0.98f;
                                                ++n68;
                                            }
                                            n68 = 0;
                                            while (n68 < 4) {
                                                n10 = n2 + this.I[n68];
                                                n9 = this.F[n10];
                                                if (n9 >= 0 && this.A[n9] == 38 && this.B[n9] == 0) {
                                                    this.B[n9] = 1;
                                                    int n69 = (int)this.aR.d(512.0f);
                                                    this.z[n9].a = this.aR.bn[n69][0] * f2;
                                                    this.z[n9].b = this.aR.bn[n69][1] * f2;
                                                }
                                                ++n68;
                                            }
                                            this.A[n] = 19;
                                            nArray2 = this.B;
                                            n11 = n;
                                            n8 = 0;
                                        }
                                        nArray2[n11] = n8;
                                    }
                                    this.F[n2] = n;
                                    break block223;
                                }
                                if (this.A[n] != 39) break block233;
                                if (this.B[n] == 0) {
                                    this.B[n] = 1;
                                    this.z[n].a = this.aR.b(-1.0f, 1.0f);
                                    this.z[n].b = this.aR.b(-1.0f, 1.0f);
                                } else if (this.B[n] == 2) {
                                    if (this.aR.d(100.0f) < 2.0f) {
                                        this.B[n] = 1;
                                        this.z[n].a(-1.0f);
                                    } else {
                                        this.F[n2] = n;
                                        return 0;
                                    }
                                }
                                e2.a += this.z[n].a * 0.5f;
                                e2.b += this.z[n].b * 0.5f;
                                n5 = this.a(n, e2);
                                if (n2 == n5) {
                                    if (this.aR.d(100.0f) < 50.0f) {
                                        this.z[n].a(this.z[n].b, -this.z[n].a);
                                    } else {
                                        this.z[n].a(-this.z[n].b, this.z[n].a);
                                    }
                                }
                                n2 = n5;
                                n5 += (int)this.aR.d(5.0f) - 2;
                                int n70 = (int)this.aR.d(5.0f);
                                n4 = this.F[n5 += (n70 - 2) * this.aR.a];
                                if (n4 < 0) break block234;
                                if (n70 >= 3 || this.P[this.A[n4]] != 2) break block235;
                                this.b(n, n4, n2, n5);
                                break block234;
                            }
                            if (this.A[n4] == 5 || this.A[n4] == 24) {
                                this.A[n4] = 39;
                                this.z[n4].a(this.z[n]);
                                this.B[n4] = 1;
                                this.c(n);
                                return 1;
                            }
                            if (this.A[n4] != 6) break block236;
                            nArray = this.B;
                            n7 = n;
                            n6 = 2;
                            break block237;
                        }
                        if (this.P[this.A[n4]] != 3) break block234;
                        nArray = this.A;
                        n7 = n;
                        n6 = 4;
                    }
                    nArray[n7] = n6;
                }
                boolean bl = false;
                int n71 = (int)(this.y[n].a + this.z[n].a * 4.0f);
                int n72 = (int)(this.y[n].b + this.z[n].b * 4.0f);
                int n73 = dust.b(n71 - 9, this.c);
                int n74 = dust.b(n72 - 9, this.c);
                int n75 = dust.c(n71 + 9, this.aR.a - this.c - 1);
                int n76 = dust.c(n72 + 9, (this.b - 1) * this.c - 1);
                e2.a(0.0f, 0.0f);
                int n77 = 0;
                float f = 0.0f;
                float f3 = 0.0f;
                int n78 = 0;
                int n79 = n74;
                while (n79 <= n76) {
                    n5 = n79 * this.aR.a;
                    int n80 = n73;
                    while (n80 <= n75) {
                        block238: {
                            float f4;
                            block241: {
                                block239: {
                                    block240: {
                                        int n81 = (n80 - n71) * (n80 - n71) + (n79 - n72) * (n79 - n72);
                                        if (n81 > 81) break block238;
                                        n4 = this.F[n5 + n80];
                                        if (n4 < 0) break block239;
                                        if (this.A[n4] != 39) break block240;
                                        e2.a += this.z[n4].a;
                                        e2.b += this.z[n4].b;
                                        ++n77;
                                        break block238;
                                    }
                                    if (this.A[n4] == 5 || this.A[n4] == 24 || this.A[n4] == 6) break block238;
                                    f4 = f;
                                    break block241;
                                }
                                if (n4 <= -4) break block238;
                                f4 = f;
                            }
                            f = f4 + (float)n80;
                            f3 += (float)n79;
                            ++n78;
                        }
                        ++n80;
                    }
                    ++n79;
                }
                if (n77 > 0) {
                    e2.a(1.0f / (float)n77);
                }
                this.z[n].d();
                this.z[n].a = this.z[n].a * 0.5f + e2.a * 0.5f;
                this.z[n].b = this.z[n].b * 0.5f + e2.b * 0.5f;
                this.z[n].a += this.aR.b(-0.1f, 0.1f);
                this.z[n].b += this.aR.b(-0.1f, 0.1f);
                if (n78 > 0) {
                    float f5;
                    f = f / (float)n78 - this.y[n].a;
                    f3 = f3 / (float)n78 - this.y[n].b;
                    float f6 = this.z[n].b * f - this.z[n].a * f3;
                    if (f5 < 0.0f) {
                        e2.a(this.z[n].b, -this.z[n].a);
                    } else {
                        e2.a(-this.z[n].b, this.z[n].a);
                    }
                    this.z[n].a = this.z[n].a * 0.9f + e2.a * 0.1f;
                    this.z[n].b = this.z[n].b * 0.9f + e2.b * 0.1f;
                }
                break block223;
            }
            if (this.A[n] == 41) {
                int n82;
                this.z[n].a += this.e[n3].a * 0.2f;
                this.z[n].b += this.e[n3].b * 0.2f;
                if (this.F[n2 + this.aR.a] != -5) {
                    if (this.F[n2 - 1] == -5) {
                        this.z[n].a -= this.aR.b(0.1f, 0.2f);
                    }
                    if (this.F[n2 + 1] == -5) {
                        this.z[n].a += this.aR.b(0.1f, 0.2f);
                    }
                }
                this.z[n].a += this.aR.b(-0.01f, 0.01f);
                this.z[n].b += this.aR.b(0.01f, 0.05f);
                this.z[n].a(0.9f);
                e2.b(this.z[n]);
                n2 = this.a(n, e2);
                int n83 = (int)this.aR.d(8.0f);
                if (n83 < 1) {
                    n82 = n2 - this.aR.a;
                } else if (n83 < 2) {
                    n82 = n2 - 1;
                } else {
                    int n84;
                    int n85;
                    if (n83 < 3) {
                        n85 = n2;
                        n84 = 1;
                    } else {
                        n85 = n2;
                        n84 = this.aR.a;
                    }
                    n82 = n85 + n84;
                }
                int n86 = n82;
                int n87 = this.F[n86];
                if (n87 >= 0) {
                    if (n83 > 0 && (this.P[this.A[n87]] == 1 || this.P[this.A[n87]] == 2 && this.A[n87] != 41)) {
                        this.b(n, n87, n2, n86);
                    } else if (this.A[n87] == 45 && this.C[n87] == 0) {
                        n86 = n83 < 1 ? 2 : (n83 < 2 ? 1 : (n83 < 3 ? 3 : 0));
                        this.B[n87] = 4 | n86;
                        this.C[n87] = 41;
                        this.c(n);
                        return 1;
                    }
                }
            }
        }
        return 0;
    }

    /*
     * Unable to fully structure code
     */
    private int f(int var1_1, e var2_2) {
        block67: {
            block78: {
                block79: {
                    block88: {
                        block87: {
                            block86: {
                                block85: {
                                    block84: {
                                        block83: {
                                            block82: {
                                                block81: {
                                                    block80: {
                                                        block68: {
                                                            block69: {
                                                                block71: {
                                                                    block70: {
                                                                        block63: {
                                                                            block64: {
                                                                                block65: {
                                                                                    block66: {
                                                                                        var4_3 = ((int)this.y[var1_1].b >> 2) * this.a + ((int)this.y[var1_1].a >> 2);
                                                                                        var5_4 = this.G[var1_1];
                                                                                        this.F[var5_4] = -5;
                                                                                        var2_2.a(this.e[var4_3]);
                                                                                        if (this.A[var1_1] != 42) break block63;
                                                                                        var2_2.a(0.05f);
                                                                                        this.z[var1_1].b(var2_2);
                                                                                        this.z[var1_1].b += 0.01f;
                                                                                        if (this.F[var5_4 + 1] >= -3) {
                                                                                            this.z[var1_1].a -= this.aR.d(0.5f);
                                                                                        }
                                                                                        if (this.F[var5_4 - 1] >= -3) {
                                                                                            this.z[var1_1].a += this.aR.d(0.5f);
                                                                                        }
                                                                                        if (this.F[var5_4 + this.aR.a] >= -3) {
                                                                                            this.z[var1_1].b -= this.aR.d(0.5f);
                                                                                        }
                                                                                        if (this.F[var5_4 + this.aR.a * 2] >= -3) {
                                                                                            this.z[var1_1].b -= this.aR.d(0.5f);
                                                                                        }
                                                                                        if (this.F[var5_4 - this.aR.a] >= -3) {
                                                                                            this.z[var1_1].b += this.aR.d(0.5f);
                                                                                        }
                                                                                        this.z[var1_1].a(0.98f);
                                                                                        var2_2.a(this.z[var1_1]);
                                                                                        var5_4 = this.a(var1_1, var2_2);
                                                                                        var5_4 += (int)this.aR.d(5.0f) - 2;
                                                                                        var7_5 = this.F[(var5_4 += ((int)this.aR.d(5.0f) - 2) * this.aR.a) - this.aR.a];
                                                                                        if (var7_5 < 0) break block64;
                                                                                        if (this.A[var7_5] == 2) break block65;
                                                                                        if (this.A[var7_5] == 3 || this.A[var7_5] == 37 || this.A[var7_5] == 27) {
                                                                                            this.c(var1_1);
                                                                                            return 1;
                                                                                        }
                                                                                        if (this.A[var7_5] != 11) break block66;
                                                                                        v0 = this.A;
                                                                                        v1 = var7_5;
                                                                                        v2 = 3;
                                                                                        break block64;
                                                                                    }
                                                                                    if (this.A[var7_5] != 24) break block64;
                                                                                }
                                                                                v0 = this.A;
                                                                                v1 = var7_5;
                                                                                v2 = v0[v1] = 4;
                                                                            }
                                                                            if (this.aR.d(100.0f) < 15.0f) {
                                                                                this.c(var1_1);
                                                                                return 1;
                                                                            }
                                                                            break block67;
                                                                        }
                                                                        if (this.A[var1_1] != 43) break block68;
                                                                        var2_2.a(0.0f, 0.0f);
                                                                        var5_4 = this.a(var1_1, var2_2);
                                                                        if (this.B[var1_1] >= 256) break block69;
                                                                        var5_4 += (int)this.aR.d(3.0f) - 1;
                                                                        var7_6 = this.F[var5_4 += ((int)this.aR.d(3.0f) - 1) * this.aR.a];
                                                                        if (var7_6 < 0) break block67;
                                                                        if (this.P[this.A[var7_6]] != 3 || this.A[var7_6] == 42) break block70;
                                                                        v3 = var1_1;
                                                                        v4 = v3;
                                                                        v5 = this.B;
                                                                        v6 = this.B[v3] + 256;
                                                                        ** GOTO lbl314
                                                                    }
                                                                    if (this.A[var7_6] != 3) break block71;
                                                                    v5 = this.A;
                                                                    v4 = var1_1;
                                                                    v6 = 7;
                                                                    ** GOTO lbl314
                                                                }
                                                                if (this.A[var7_6] != 37) break block67;
                                                                v5 = this.A;
                                                                v4 = var1_1;
                                                                v6 = 7;
                                                                ** GOTO lbl314
                                                            }
                                                            v7 = var1_1;
                                                            this.B[v7] = this.B[v7] + 256;
                                                            if (this.B[var1_1] < 768) break block67;
                                                            var7_7 = this.B[var1_1] & 255;
                                                            var8_10 = 42;
                                                            if (var7_7 == 16) {
                                                                v8 = 4;
                                                            } else if (var7_7 == 23) {
                                                                v8 = 23;
                                                            } else if (var7_7 == 27) {
                                                                v8 = var8_10 = 12;
                                                            }
                                                            if (this.F[var5_4 + 1] >= 0) {
                                                                if (this.F[var5_4 - 1] <= -4) {
                                                                    this.a((float)((int)this.y[var1_1].a - 1), (float)((int)this.y[var1_1].b), var8_10);
                                                                }
                                                                if (this.F[var5_4 - 1 - this.aR.a] <= -4) {
                                                                    this.a((float)((int)this.y[var1_1].a - 1), (float)((int)this.y[var1_1].b - 1), var8_10);
                                                                }
                                                                if (this.F[var5_4 - 1 + this.aR.a] <= -4) {
                                                                    this.a((float)((int)this.y[var1_1].a - 1), (float)((int)this.y[var1_1].b + 1), var8_10);
                                                                }
                                                            }
                                                            if (this.F[var5_4 - 1] >= 0) {
                                                                if (this.F[var5_4 + 1] <= -4) {
                                                                    this.a((float)((int)this.y[var1_1].a + 1), (float)((int)this.y[var1_1].b), var8_10);
                                                                }
                                                                if (this.F[var5_4 + 1 - this.aR.a] <= -4) {
                                                                    this.a((float)((int)this.y[var1_1].a + 1), (float)((int)this.y[var1_1].b - 1), var8_10);
                                                                }
                                                                if (this.F[var5_4 + 1 + this.aR.a] <= -4) {
                                                                    this.a((float)((int)this.y[var1_1].a + 1), (float)((int)this.y[var1_1].b + 1), var8_10);
                                                                }
                                                            }
                                                            if (this.F[var5_4 + this.aR.a] >= 0) {
                                                                if (this.F[var5_4 - this.aR.a] <= -4) {
                                                                    this.a((float)((int)this.y[var1_1].a), (float)((int)this.y[var1_1].b - 1), var8_10);
                                                                }
                                                                if (this.F[var5_4 - 1 - this.aR.a] <= -4) {
                                                                    this.a((float)((int)this.y[var1_1].a - 1), (float)((int)this.y[var1_1].b - 1), var8_10);
                                                                }
                                                                if (this.F[var5_4 + 1 - this.aR.a] <= -4) {
                                                                    this.a((float)((int)this.y[var1_1].a + 1), (float)((int)this.y[var1_1].b - 1), var8_10);
                                                                }
                                                            }
                                                            if (this.F[var5_4 - this.aR.a] >= 0) {
                                                                if (this.F[var5_4 + this.aR.a] <= -4) {
                                                                    this.a((float)((int)this.y[var1_1].a), (float)((int)this.y[var1_1].b + 1), var8_10);
                                                                }
                                                                if (this.F[var5_4 - 1 + this.aR.a] <= -4) {
                                                                    this.a((float)((int)this.y[var1_1].a - 1), (float)((int)this.y[var1_1].b + 1), var8_10);
                                                                }
                                                                if (this.F[var5_4 + 1 + this.aR.a] <= -4) {
                                                                    this.a((float)((int)this.y[var1_1].a + 1), (float)((int)this.y[var1_1].b + 1), var8_10);
                                                                }
                                                            }
                                                            var3_13 = 0;
                                                            while (var3_13 < 8) {
                                                                block72: {
                                                                    block74: {
                                                                        block76: {
                                                                            block77: {
                                                                                block75: {
                                                                                    block73: {
                                                                                        var6_15 = var5_4 + this.I[var3_13];
                                                                                        var9_18 = this.F[var6_15];
                                                                                        if (var9_18 < 0) break block72;
                                                                                        if (this.A[var9_18] != 43 || this.B[var9_18] >= 256) break block73;
                                                                                        v9 = var9_18;
                                                                                        v10 = v9;
                                                                                        v11 = this.B;
                                                                                        v12 = this.B[v9] + 256;
                                                                                        break block74;
                                                                                    }
                                                                                    if (this.A[var9_18] != 15) break block75;
                                                                                    this.z[var9_18].b -= 50.0f;
                                                                                    v13 = var9_18;
                                                                                    v10 = v13;
                                                                                    v11 = this.B;
                                                                                    v12 = this.B[v13] + 100;
                                                                                    break block74;
                                                                                }
                                                                                if (this.A[var9_18] == 16 || this.A[var9_18] == 17) break block76;
                                                                                if (this.A[var9_18] != 23) break block77;
                                                                                this.z[var9_18].b -= 20.0f;
                                                                                break block72;
                                                                            }
                                                                            if (this.A[var9_18] != 26) break block72;
                                                                        }
                                                                        v11 = this.B;
                                                                        v10 = var9_18;
                                                                        v12 = 1;
                                                                    }
                                                                    v11[v10] = v12;
                                                                }
                                                                ++var3_13;
                                                            }
                                                            this.A[var1_1] = var8_10;
                                                            v5 = this.B;
                                                            v4 = var1_1;
                                                            v6 = 0;
                                                            ** GOTO lbl314
                                                        }
                                                        if (this.A[var1_1] != 44) break block78;
                                                        var2_2.b += this.aR.b(-0.01f, -0.02f);
                                                        var2_2.b(this.z[var1_1]);
                                                        this.z[var1_1].a(0.9f);
                                                        var5_4 = this.a(var1_1, var2_2);
                                                        var7_8 = (int)this.aR.d(4.0f);
                                                        if (var7_8 < 1) {
                                                            v14 = var5_4 - this.aR.a;
                                                        } else if (var7_8 < 2) {
                                                            v14 = var5_4 - 1;
                                                        } else {
                                                            if (var7_8 < 3) {
                                                                v15 = var5_4;
                                                                v16 = 1;
                                                            } else {
                                                                v15 = var5_4;
                                                                v16 = this.aR.a;
                                                            }
                                                            v14 = v15 + v16;
                                                        }
                                                        var6_16 = v14;
                                                        var8_11 = this.F[var6_16];
                                                        if (var8_11 < 0) break block79;
                                                        if (var7_8 >= 3 || this.P[this.A[var8_11]] != 1 && this.P[this.A[var8_11]] != 2) break block80;
                                                        this.b(var1_1, var8_11, var5_4, var6_16);
                                                        break block67;
                                                    }
                                                    if (this.A[var8_11] != 44) break block81;
                                                    this.z[var1_1].a += this.aR.b(-0.1f, 0.1f);
                                                    this.z[var1_1].b += this.aR.b(-0.1f, 0.1f);
                                                    break block67;
                                                }
                                                if (this.A[var8_11] != 6) break block82;
                                                v5 = this.A;
                                                v4 = var1_1;
                                                v6 = 3;
                                                ** GOTO lbl314
                                            }
                                            if (this.A[var8_11] != 10) break block83;
                                            v5 = this.A;
                                            v4 = var1_1;
                                            v6 = 11;
                                            ** GOTO lbl314
                                        }
                                        if (this.A[var8_11] != 17) break block84;
                                        v5 = this.A;
                                        v4 = var1_1;
                                        v6 = 3;
                                        ** GOTO lbl314
                                    }
                                    if (this.A[var8_11] != 25) break block85;
                                    v5 = this.A;
                                    v4 = var1_1;
                                    v6 = 3;
                                    ** GOTO lbl314
                                }
                                if (this.A[var8_11] != 29) break block86;
                                v5 = this.A;
                                v4 = var1_1;
                                v6 = 28;
                                ** GOTO lbl314
                            }
                            if (this.A[var8_11] != 35) break block87;
                            v5 = this.A;
                            v4 = var1_1;
                            v6 = 3;
                            ** GOTO lbl314
                        }
                        if (this.A[var8_11] != 43) break block88;
                        v5 = this.A;
                        v4 = var1_1;
                        v6 = 3;
                        ** GOTO lbl314
                    }
                    if (this.A[var8_11] == 45 && this.C[var8_11] == 0) {
                        var6_16 = var7_8 < 1 ? 2 : (var7_8 < 2 ? 1 : (var7_8 < 3 ? 3 : 0));
                        this.B[var8_11] = 4 | var6_16;
                        this.C[var8_11] = 3;
                        this.c(var1_1);
                        return 1;
                    }
                    break block67;
                }
                if (var8_11 != -1) break block67;
                v5 = this.A;
                v4 = var1_1;
                v6 = 3;
                ** GOTO lbl314
            }
            if (this.A[var1_1] != 45) break block67;
            var2_2.a(0.0f, 0.0f);
            var5_4 = this.a(var1_1, var2_2);
            if (this.C[var1_1] == 0) {
                return 0;
            }
            var7_9 = this.B[var1_1] & 3;
            var8_12 = this.B[var1_1] >> 2;
            var9_19 = new int[]{this.aR.a, -1, -this.aR.a, 1};
            var10_20 = this.aR.a(1, -1);
            var3_14 = 0;
            while (var3_14 < 4) {
                if (var3_14 != 2 && (var11_21 = this.F[var6_17 = var5_4 + var9_19[var7_9 + var3_14 * var10_20 & 3]]) >= 0 && this.A[var11_21] == 45) {
                    if (this.C[var11_21] == 0) {
                        this.b(var1_1, var11_21, var5_4, var6_17);
                        this.B[var1_1] = var8_12 << 2 | var7_9 + var3_14 * var10_20 & 3;
                        break;
                    }
                    if (this.C[var1_1] == this.C[var11_21]) {
                        var7_9 = this.B[var11_21] & 3;
                        this.B[var11_21] = (var8_12 += this.B[var11_21] >> 2) << 2 | var7_9;
                        this.B[var1_1] = 0;
                        this.C[var1_1] = 0;
                        break;
                    }
                    this.B[var1_1] = var8_12 << 2 | var7_9 + 2 & 3;
                    break;
                }
                ++var3_14;
            }
            if (var3_14 != 4) break block67;
            if (this.F[var5_4 + var9_19[var7_9] * 2] <= -4 && this.aR.h[this.aR.g] - this.D >= 1000) {
                var11_22 = this.y[var1_1].a + 0.5f;
                var12_23 = this.y[var1_1].b + 0.5f;
                if (var7_9 == 0) {
                    this.a(var11_22, var12_23 + 2.0f, (int)this.C[var1_1]);
                } else if (var7_9 == 1) {
                    this.a(var11_22 - 2.0f, var12_23, (int)this.C[var1_1]);
                } else if (var7_9 == 2) {
                    this.a(var11_22, var12_23 - 2.0f, (int)this.C[var1_1]);
                } else if (var7_9 == 3) {
                    this.a(var11_22 + 2.0f, var12_23, (int)this.C[var1_1]);
                }
            }
            if (var8_12 <= 1) {
                this.B[var1_1] = 0;
                this.C[var1_1] = 0;
            } else {
                v5 = this.B;
                v4 = var1_1;
                v6 = var8_12 - 1 << 2 | var7_9;
lbl314:
                // 13 sources

                v5[v4] = v6;
            }
        }
        return 0;
    }

    private void l() {
        if (this.aR.j == 6) {
            int n = 0;
            while (n < this.D) {
                int n2;
                int n3;
                int n4 = ((this.v[this.A[n]][this.C[n]] & 0xFF0000) >> 18) + (this.aR.ar[this.G[n]] >> 16 & 0xFF);
                if (n4 > 255) {
                    n4 = 255;
                }
                if ((n3 = ((this.v[this.A[n]][this.C[n]] & 0xFF00) >> 10) + (this.aR.ar[this.G[n]] >> 8 & 0xFF)) > 255) {
                    n3 = 255;
                }
                if ((n2 = ((this.v[this.A[n]][this.C[n]] & 0xFF) >> 2) + (this.aR.ar[this.G[n]] & 0xFF)) > 255) {
                    n2 = 255;
                }
                this.aR.ar[this.G[n]] = 0xFF000000 | n4 << 16 | n3 << 8 | n2;
                ++n;
            }
            return;
        }
        if (this.aR.j != 7) {
            if (this.aR.j == 9) {
                int n = 0;
                while (n < this.D) {
                    this.aR.ar[this.G[n]] = this.w[this.A[n]];
                    ++n;
                }
                return;
            }
            if (this.aR.j == 13) {
                int n = 0;
                while (n < this.D) {
                    int n5;
                    int n6;
                    int n7 = (this.aR.ar[this.G[n]] >> 16 & 0xFF) - (255 - (this.v[this.A[n]][this.C[n]] >> 16 & 0xFF) + 10);
                    if (n7 < 0) {
                        n7 = 0;
                    }
                    if ((n6 = (this.aR.ar[this.G[n]] >> 8 & 0xFF) - (255 - (this.v[this.A[n]][this.C[n]] >> 8 & 0xFF) + 10)) < 0) {
                        n6 = 0;
                    }
                    if ((n5 = (this.aR.ar[this.G[n]] & 0xFF) - (255 - (this.v[this.A[n]][this.C[n]] & 0xFF) + 10)) < 0) {
                        n5 = 0;
                    }
                    this.aR.ar[this.G[n]] = 0xFF000000 | n7 << 16 | n6 << 8 | n5;
                    ++n;
                }
                return;
            }
            int n = 0;
            while (n < this.D) {
                this.aR.ar[this.G[n]] = this.v[this.A[n]][this.C[n]];
                ++n;
            }
        }
    }

    private void m() {
        this.Q.a("wheel.gif");
        this.V = 0;
        this.W = 100;
        this.R = new int[this.W];
        this.S = new int[this.W];
        this.T = new float[this.W];
        this.U = new float[this.W];
    }

    private int a(int n, int n2) {
        if (this.V == this.W) {
            return -1;
        }
        this.R[this.V] = n;
        this.S[this.V] = n2;
        this.T[this.V] = 0.5f;
        this.U[this.V] = 0.0f;
        ++this.V;
        return this.V - 1;
    }

    private void d(int n) {
        if (this.V == 0) {
            return;
        }
        int n2 = (this.S[n] - 16) * this.aR.a + (this.R[n] - 16);
        int n3 = 0;
        while (n3 < 32) {
            int n4 = 0;
            while (n4 < 32) {
                if (this.F[n2] == -3) {
                    this.F[n2] = -5;
                }
                ++n4;
                ++n2;
            }
            ++n3;
            n2 += this.aR.a - 32;
        }
        this.R[n] = this.R[this.V - 1];
        this.S[n] = this.S[this.V - 1];
        this.T[n] = this.T[this.V - 1];
        this.U[n] = this.U[this.V - 1];
        --this.V;
    }

    private void n() {
        int n;
        int n2;
        int n3;
        int n4 = 0;
        while (n4 < this.V) {
            n3 = (this.S[n4] - 16) * this.aR.a + (this.R[n4] - 16);
            n2 = 0;
            while (n2 < 32) {
                n = 0;
                while (n < 32) {
                    if (this.F[n3] == -3) {
                        this.F[n3] = -5;
                    }
                    ++n;
                    ++n3;
                }
                ++n2;
                n3 += this.aR.a - 32;
            }
            ++n4;
        }
        n4 = 0;
        while (n4 < this.V) {
            n3 = (this.S[n4] - 16) * this.aR.a + (this.R[n4] - 16);
            int n5 = (int)this.T[n4] * 32 * this.Q.b;
            n2 = 0;
            while (n2 < 32) {
                n = 0;
                while (n < 32) {
                    if (this.Q.f[n5] == -16777216 && this.F[n3] <= -4) {
                        this.F[n3] = -3;
                    }
                    ++n;
                    ++n3;
                    ++n5;
                }
                ++n2;
                n3 += this.aR.a - 32;
            }
            ++n4;
        }
    }

    private void o() {
        int n;
        int[] nArray = new int[46];
        nArray[2] = 1;
        nArray[3] = 4;
        nArray[4] = -3;
        nArray[5] = 1;
        nArray[7] = 2;
        nArray[10] = 4;
        nArray[11] = 1;
        nArray[12] = 1;
        nArray[13] = 8;
        nArray[14] = 3;
        nArray[15] = 8;
        nArray[16] = 3;
        nArray[17] = 4;
        nArray[19] = 9;
        nArray[20] = 9;
        nArray[21] = 1;
        nArray[23] = 5;
        nArray[24] = 1;
        nArray[26] = -1;
        nArray[27] = 4;
        nArray[28] = 100;
        nArray[29] = 9;
        nArray[31] = 10;
        nArray[34] = 6;
        nArray[35] = 1;
        nArray[36] = 1;
        nArray[37] = 5;
        nArray[38] = 8;
        nArray[41] = 20;
        nArray[42] = 1;
        nArray[43] = 4;
        nArray[44] = -2;
        nArray[45] = 9;
        int[] nArray2 = nArray;
        if (this.aR.c == 42 && this.aR.aJ || this.aR.d == 42 && this.aR.aN) {
            e e2 = new e(this.aR);
            n = 0;
            while (n < this.V) {
                e2.a = this.m - this.R[n];
                e2.b = this.n - this.S[n];
                if (e2.a() < 16.0f) {
                    float f = this.m - this.o;
                    float f2 = this.n - this.p;
                    int n2 = n;
                    this.U[n2] = this.U[n2] - (e2.a * f2 - e2.b * f);
                }
                ++n;
            }
        }
        n = 0;
        while (n < this.V) {
            int n3;
            int n4;
            int n5 = (this.S[n] - 16) * this.aR.a + (this.R[n] - 16);
            int n6 = (int)this.T[n] * 32 * this.Q.b;
            int n7 = 0;
            while (n7 < 32) {
                n4 = 0;
                while (n4 < 32) {
                    float f;
                    if (this.Q.f[n6] == -16777216) {
                        int n8 = (this.S[n] + n7 - 16 >> 2) * this.a + (this.R[n] + n4 - 16 >> 2);
                        f = this.e[n8].a * ((float)n7 - 15.5f) - this.e[n8].b * ((float)n4 - 15.5f);
                        int n9 = n;
                        this.U[n9] = this.U[n9] + f * 1.0E-4f;
                    }
                    if ((n3 = this.F[n5]) >= 0 && this.Q.f[n6] == -8355712 && this.Q.f[n6 + this.Q.b] == -16777216 && n7 != 31) {
                        f = 0.0f * ((float)n7 - 15.5f) - ((float)n4 - 15.5f);
                        int n10 = n;
                        this.U[n10] = this.U[n10] + f * (float)nArray2[this.A[n3]] * 1.0E-4f;
                    }
                    ++n4;
                    ++n5;
                    ++n6;
                }
                ++n7;
                n5 += this.aR.a - 32;
            }
            int n11 = n;
            this.U[n11] = this.U[n11] * 0.99f;
            this.U[n] = dust.a(this.U[n], -2.0f, 2.0f);
            int n12 = (int)(this.T[n] + 16.0f);
            int n13 = n;
            this.T[n13] = this.T[n13] + this.U[n];
            n12 = (int)(this.T[n] + 16.0f) - n12;
            if (this.T[n] < 0.0f) {
                int n14 = n;
                this.T[n14] = this.T[n14] + 16.0f;
            }
            if (this.T[n] >= 16.0f) {
                int n15 = n;
                this.T[n15] = this.T[n15] - 16.0f;
            }
            if (n12 != 0) {
                this.aa = 0;
                n5 = (this.S[n] - 16) * this.aR.a + (this.R[n] - 16);
                n6 = (int)this.T[n] * 32 * this.Q.b;
                n7 = 0;
                while (n7 < 32) {
                    n4 = 0;
                    while (n4 < 32) {
                        if (this.Q.f[n6] == -8355712 && (n3 = this.F[n5]) >= 0) {
                            this.X[this.aa] = n3;
                            this.Y[this.aa] = ((float)n7 - 15.5f) * (float)n12 * 8.0f * 0.015625f * 0.8f;
                            this.Z[this.aa] = -((float)n4 - 15.5f) * (float)n12 * 8.0f * 0.015625f * 0.8f;
                            ++this.aa;
                        }
                        ++n4;
                        ++n5;
                        ++n6;
                    }
                    ++n7;
                    n5 += this.aR.a - 32;
                }
                n5 = 0;
                while (n5 < this.aa) {
                    this.F[this.G[this.X[n5]]] = -5;
                    int n16 = (int)this.y[this.X[n5]].b * this.aR.a + (int)(this.y[this.X[n5]].a + this.Y[n5]);
                    if (this.F[n16] < -1) {
                        this.y[this.X[n5]].a += this.Y[n5];
                    }
                    if (this.F[n16 = (int)(this.y[this.X[n5]].b + this.Z[n5]) * this.aR.a + (int)this.y[this.X[n5]].a] < -1) {
                        this.y[this.X[n5]].b += this.Z[n5];
                    }
                    this.G[this.X[n5]] = (int)this.y[this.X[n5]].b * this.aR.a + (int)this.y[this.X[n5]].a;
                    this.F[this.G[this.X[n5]]] = this.X[n5];
                    if (this.A[this.X[n5]] == 6) {
                        if (this.aR.d(100.0f) < 20.0f) {
                            this.A[this.X[n5]] = 2;
                        }
                    } else if (this.A[this.X[n5]] == 10) {
                        this.A[this.X[n5]] = 11;
                    } else if (this.A[this.X[n5]] == 43) {
                        this.A[this.X[n5]] = 7;
                    } else if (this.A[this.X[n5]] == 45 && this.aR.d(100.0f) < 10.0f) {
                        this.A[this.X[n5]] = 42;
                        this.C[this.X[n5]] = 0;
                    }
                    ++n5;
                }
            }
            ++n;
        }
    }

    private void p() {
        int n = -5201776;
        if (this.aR.j == 13) {
            n = -16777216;
        }
        int n2 = 0;
        while (n2 < this.V) {
            int n3 = (this.S[n2] - 16) * this.aR.a + (this.R[n2] - 16);
            int n4 = (int)this.T[n2] * 32 * this.Q.b;
            int n5 = 0;
            while (n5 < 32) {
                int n6 = 0;
                while (n6 < 32) {
                    if (this.Q.f[n4] == -16777216) {
                        this.aR.ar[n3] = n;
                    }
                    ++n6;
                    ++n3;
                    ++n4;
                }
                ++n5;
                n3 += this.aR.a - 32;
            }
            ++n2;
        }
    }

    private void q() {
        this.ae = 0;
        this.af = 2000;
        this.ag = 0;
        this.ah = 5;
        this.ai = (float)this.ah / ((float)Math.PI * 2) * 2.0f;
        this.ab = new float[this.af];
        this.ac = new float[this.af];
        this.ad = new int[this.af];
        this.aj = new int[this.af];
    }

    private void a(float f, float f2) {
        if (this.ae == this.af) {
            return;
        }
        this.ab[this.ae] = f;
        this.ac[this.ae] = f2;
        this.ad[this.ae] = this.ag;
        this.aj[this.ae] = 0;
        ++this.ae;
    }

    private int r() {
        int n = 0;
        int n2 = this.ae - 1;
        while (n2 >= 0) {
            if (this.ad[n2] != this.ag) break;
            ++n;
            --n2;
        }
        return n;
    }

    private void a(int n, int n2, float f) {
        e e2 = new e(this.aR);
        new e(this.aR).a = this.ab[n2] - this.ab[n];
        e2.b = this.ac[n2] - this.ac[n];
        float f2 = e2.d();
        if (f2 != 0.0f) {
            f2 = f - f2;
            int n3 = n;
            this.ab[n3] = this.ab[n3] - e2.a * f2 * 0.5f;
            int n4 = n;
            this.ac[n4] = this.ac[n4] - e2.b * f2 * 0.5f;
            int n5 = n2;
            this.ab[n5] = this.ab[n5] + e2.a * f2 * 0.5f;
            int n6 = n2;
            this.ac[n6] = this.ac[n6] + e2.b * f2 * 0.5f;
        }
    }

    /*
     * Unable to fully structure code
     */
    private void s() {
        var3_1 = new e(this.aR);
        var1_2 = 0;
        while (var1_2 < this.ae) {
            var2_3 = ((int)this.ac[var1_2] >> 2) * this.a + ((int)this.ab[var1_2] >> 2);
            var3_1.a(this.e[var2_3]);
            var3_1.a(3.8f / (var3_1.a() + 1.0f));
            v0 = var1_2;
            this.ab[v0] = this.ab[v0] + var3_1.a;
            v1 = var1_2++;
            this.ac[v1] = this.ac[v1] + var3_1.b;
        }
        var1_2 = 0;
        while (var1_2 < this.ae) {
            block17: {
                block16: {
                    if (this.aj[var1_2] != 0) break block16;
                    if ((this.aR.c != 42 || !this.aR.aH) && (this.aR.d != 42 || !this.aR.aL)) break block17;
                    var3_1.a = (float)this.m - this.ab[var1_2];
                    var3_1.b = (float)this.n - this.ac[var1_2];
                    if (!(var3_1.a() < 10.0f)) break block17;
                    v2 = this.aj;
                    v3 = var1_2;
                    v4 = 1;
                    ** GOTO lbl35
                }
                if (this.aR.c == 42 && this.aR.aJ || this.aR.d == 42 && this.aR.aN) {
                    v5 = var1_2;
                    this.ab[v5] = this.ab[v5] + ((float)this.m - this.ab[var1_2]) * 0.9f;
                    v6 = var1_2;
                    this.ac[v6] = this.ac[v6] + ((float)this.n - this.ac[var1_2]) * 0.9f;
                } else {
                    v2 = this.aj;
                    v3 = var1_2;
                    v4 = 0;
lbl35:
                    // 2 sources

                    v2[v3] = v4;
                }
            }
            ++var1_2;
        }
        v7 = 0;
        while (v7 < this.ae - 1) {
            var5_5 = this.ad[var1_2];
            var6_6 = 0;
            var2_3 = var1_2;
            while (var2_3 < this.ae) {
                if (var5_5 != this.ad[var2_3]) break;
                ++var2_3;
                ++var6_6;
            }
            var3_1.a(0.0f, 0.0f);
            var2_3 = var1_2;
            while (var2_3 < var1_2 + var6_6) {
                var3_1.a += this.ab[var2_3];
                var3_1.b += this.ac[var2_3];
                ++var2_3;
            }
            var3_1.b(var6_6);
            var2_3 = var1_2;
            while (var2_3 < var1_2 + var6_6) {
                var7_7 = new e(this.aR);
                new e(this.aR).a = var3_1.a - this.ab[var2_3];
                var7_7.b = var3_1.b - this.ac[var2_3];
                var4_4 = var7_7.d();
                if (var4_4 != 0.0f) {
                    var4_4 = (float)var6_6 * this.ai - var4_4;
                    v8 = var2_3;
                    this.ab[v8] = this.ab[v8] - var7_7.a * var4_4 * 0.1f;
                    v9 = var2_3;
                    this.ac[v9] = this.ac[v9] - var7_7.b * var4_4 * 0.1f;
                }
                ++var2_3;
            }
            var2_3 = var1_2;
            while (var2_3 < var1_2 + var6_6 - 1) {
                this.a(var2_3, var2_3 + 1, (float)this.ah);
                ++var2_3;
            }
            this.a(var2_3, var1_2, (float)this.ah);
            v7 = var1_2 = var1_2 + var6_6;
        }
        var1_2 = 0;
        while (var1_2 < this.ae) {
            var2_3 = 0;
            if (!(this.ab[var1_2] >= 0.0f && this.ab[var1_2] < (float)this.aR.a && this.ac[var1_2] >= 0.0f && this.ac[var1_2] < 316.0f && (this.F[var2_3 = (int)this.ac[var1_2] * this.aR.a + (int)this.ab[var1_2]] <= -4 || this.F[var2_3] >= 0 && this.A[this.F[var2_3]] == 27))) {
                var5_5 = this.ad[var1_2];
                var6_6 = var1_2;
                while (var6_6 > 0) {
                    if (var5_5 != this.ad[var6_6 - 1]) break;
                    --var6_6;
                }
                var7_8 = var6_6 + 1;
                while (var7_8 < this.ae) {
                    if (var5_5 != this.ad[var7_8]) break;
                    ++var7_8;
                }
                var8_9 = this.F[var2_3];
                var8_9 = var8_9 >= 0 ? this.A[var8_9] : 12;
                var2_3 = var6_6;
                while (var2_3 < var7_8 - 1) {
                    this.a(this.ab[var2_3], this.ac[var2_3], this.ab[var2_3 + 1], this.ac[var2_3 + 1], var8_9);
                    ++var2_3;
                }
                this.a(this.ab[var2_3], this.ac[var2_3], this.ab[var6_6], this.ac[var6_6], var8_9);
                var1_2 = var6_6 - 1;
                while (var7_8 < this.ae) {
                    this.ab[var6_6] = this.ab[var7_8];
                    this.ac[var6_6] = this.ac[var7_8];
                    this.ad[var6_6] = this.ad[var7_8];
                    this.aj[var6_6] = this.aj[var7_8];
                    ++var6_6;
                    ++var7_8;
                }
                this.ae -= var7_8 - var6_6;
            }
            ++var1_2;
        }
    }

    private void a(float f, float f2, float f3, float f4, int n) {
        int n2;
        float f5 = f3 - f;
        float f6 = f4 - f2;
        if (dust.e(f5) >= dust.e(f6)) {
            n2 = (int)dust.e(f5);
            if (f5 != 0.0f) {
                f6 /= dust.e(f5);
            }
            f5 = f5 >= 0.0f ? 1 : -1;
        } else {
            n2 = (int)dust.e(f6);
            if (f6 != 0.0f) {
                f5 /= dust.e(f6);
            }
            f6 = f6 >= 0.0f ? 1 : -1;
        }
        f += 0.5f;
        f2 += 0.5f;
        int n3 = 0;
        while (n3 <= n2) {
            int n4;
            if (!(f < 8.0f || f >= 408.0f || f2 < 8.0f || f2 >= 308.0f || this.F[n4 = (int)f2 * this.aR.a + (int)f] > -4)) {
                this.a((float)((int)f), (float)((int)f2), n);
            }
            ++n3;
            f += f5;
            f2 += f6;
        }
    }

    private void t() {
        int[] nArray = new int[]{-7968, -3872, -32, -2031648, -2031617, -2035457, -2039553, -7937};
        if (this.aR.j == 13) {
            nArray = new int[]{-16777216, -16777216, -16777216, -16777216, -16777216, -16777216, -16777216, -16777216};
        }
        int n = 0;
        int n2 = 0;
        while (n2 < this.ae - 1) {
            int n3 = n2;
            int n4 = this.ad[n2];
            while (n2 < this.ae - 1) {
                if (n4 != this.ad[n2 + 1]) break;
                this.aR.a(this.ab[n2], this.ac[n2], this.ab[n2 + 1], this.ac[n2 + 1], nArray[n]);
                ++n;
                n &= 7;
                ++n2;
            }
            this.aR.a(this.ab[n2], this.ac[n2], this.ab[n3], this.ac[n3], nArray[n]);
            ++n;
            n &= 7;
            ++n2;
        }
    }

    private void u() {
        this.at = 0;
        this.au = 50;
        this.av = 28;
        this.ak = new e[this.au * this.av];
        this.al = new e[this.au * this.av];
        this.am = new int[this.au * this.av];
        this.an = new e[this.au];
        this.ao = new int[this.au];
        this.ap = new int[this.au];
        this.aq = new int[this.au];
        this.ar = new int[this.au];
        this.as = new int[this.au];
        int n = 0;
        while (n < this.au * this.av) {
            this.ak[n] = new e(this.aR, 0.0f, 0.0f);
            ++n;
        }
        n = 0;
        while (n < this.au * this.av) {
            this.al[n] = new e(this.aR, 0.0f, 0.0f);
            ++n;
        }
        n = 0;
        while (n < this.au * this.av) {
            this.am[n] = 0;
            ++n;
        }
        n = 0;
        while (n < this.au) {
            this.an[n] = new e(this.aR, 0.0f, 0.0f);
            ++n;
        }
        n = 0;
        while (n < this.au) {
            this.ao[n] = 0;
            ++n;
        }
        n = 0;
        while (n < this.au) {
            this.ap[n] = 0;
            ++n;
        }
        n = 0;
        while (n < this.au) {
            this.aq[n] = 0;
            ++n;
        }
        n = 0;
        while (n < this.au) {
            this.ar[n] = 0;
            ++n;
        }
        n = 0;
        while (n < this.au) {
            this.as[n] = 0;
            ++n;
        }
    }

    private void c(int n, int n2, int n3, int n4) {
        block19: {
            int n5;
            block20: {
                int n6;
                int[] nArray;
                int n7;
                int n8;
                block21: {
                    int n9;
                    block17: {
                        block18: {
                            int n10;
                            if (this.at == this.au) {
                                return;
                            }
                            n8 = 0;
                            n9 = 0;
                            n7 = 0;
                            if (n3 == 30 || n3 == 32) {
                                n10 = 0;
                                while (n10 < this.at) {
                                    if (this.ao[n10] == 30) {
                                        ++n8;
                                        n9 = 1 - this.as[n10];
                                        n7 = n10;
                                    }
                                    ++n10;
                                }
                                if (n8 >= 2) {
                                    return;
                                }
                                if (n4 != 0 && this.ax[n4] == 0) {
                                    return;
                                }
                            }
                            int n11 = this.at * this.av;
                            n10 = 0;
                            while (n10 < 20) {
                                this.ak[n11 + n10].a((float)n + this.aR.d(4.0f), (float)n2 + this.aR.d(4.0f));
                                this.al[n11 + n10].a(this.ak[n11 + n10]);
                                ++n10;
                            }
                            n10 = 0;
                            while (n10 < this.av) {
                                this.am[n11 + n10] = 0;
                                ++n10;
                            }
                            this.an[this.at].a(0.0f, 0.0f);
                            this.ao[this.at] = 10;
                            this.ap[this.at] = 0;
                            this.aq[this.at] = 0;
                            this.ar[this.at] = n4;
                            this.as[this.at] = 0;
                            if (n3 != 22) break block17;
                            if (n4 != 10) break block18;
                            this.ao[this.at] = 40;
                            this.ar[this.at] = 0;
                            this.ak[n11].a(n, (float)n2);
                            this.al[n11].a(this.ak[n11]);
                            break block19;
                        }
                        nArray = this.ao;
                        n6 = this.at;
                        n5 = 20;
                        break block20;
                    }
                    if (n3 != 30) break block21;
                    this.ao[this.at] = 30;
                    nArray = this.as;
                    n6 = this.at;
                    n5 = n9;
                    break block20;
                }
                if (n3 != 32) break block19;
                this.ao[this.at] = 30;
                if (n8 == 0) {
                    nArray = this.as;
                    n6 = this.at;
                    n5 = 0;
                } else {
                    int n12 = (int)this.ak[n7 * this.av].a >> 2 << 2;
                    int n13 = (int)this.ak[n7 * this.av].b >> 2 << 2;
                    if (n < n12) {
                        this.as[this.at] = 1;
                        nArray = this.as;
                        n6 = n7;
                        n5 = 0;
                    } else if (n <= n12 && n2 < n13) {
                        this.as[this.at] = 1;
                        nArray = this.as;
                        n6 = n7;
                        n5 = 0;
                    } else {
                        this.as[this.at] = 0;
                        nArray = this.as;
                        n6 = n7;
                        n5 = 1;
                    }
                }
            }
            nArray[n6] = n5;
        }
        ++this.at;
    }

    private void e(int n) {
        if (this.at == 0) {
            return;
        }
        int n2 = n * this.av;
        int n3 = (this.at - 1) * this.av;
        int n4 = 0;
        while (n4 < this.av) {
            this.ak[n2].a(this.ak[n3]);
            this.al[n2].a(this.al[n3]);
            this.am[n2] = this.am[n3];
            ++n4;
            ++n2;
            ++n3;
        }
        this.an[n].a(this.an[this.at - 1]);
        this.ao[n] = this.ao[this.at - 1];
        this.ap[n] = this.ap[this.at - 1];
        this.aq[n] = this.aq[this.at - 1];
        this.ar[n] = this.ar[this.at - 1];
        this.as[n] = this.as[this.at - 1];
        --this.at;
    }

    private void b(int n, float f, float f2) {
        e e2 = new e(this.aR);
        e2.a(this.ak[n], this.al[n]);
        this.al[n].a(this.ak[n]);
        e2.b += f;
        e2.a(f2);
        this.ak[n].b(e2);
    }

    private void a(int n, int n2, float f, float f2, float f3) {
        e e2 = new e(this.aR);
        e2.a(this.ak[n2], this.ak[n]);
        float f4 = e2.d();
        if (f4 == 0.0f) {
            return;
        }
        e e3 = new e(this.aR);
        e3.a(e2, (f -= f4) * f2);
        this.ak[n].c(e3);
        e3.a(e2, f * f3);
        this.ak[n2].b(e3);
    }

    /*
     * Unable to fully structure code
     */
    private void a(int var1_1, float var2_2, int var3_3, int var4_4) {
        var5_5 = new e(this.aR);
        var5_5.a(this.ak[var1_1], this.al[var1_1]);
        this.ak[var1_1].a(this.al[var1_1]);
        if (var2_2 != 0.0f) {
            var6_6 = ((int)this.ak[var1_1].b >> 2) * this.a + ((int)this.ak[var1_1].a >> 2);
            var5_5.a += this.e[var6_6].a * var2_2;
            var5_5.b += this.e[var6_6].b * var2_2;
        }
        if (var4_4 == 0) {
            var7_7 = var5_5.a() + 1.0f;
            if (v0 >= 8.0f) {
                var5_5.a(3.8f / var7_7);
                var6_6 = 2;
            } else if (var7_7 >= 4.0f) {
                var5_5.a(0.5f);
                var6_6 = 2;
            } else {
                var6_6 = 1;
            }
        } else {
            var6_6 = (int)(var5_5.a() / 3.0f) + 1;
            var5_5.a(1.0f / (float)var6_6);
        }
        this.am[var1_1] = 0;
        if (var3_3 == 1) {
            var5_5.a(var6_6);
            this.ak[var1_1].b(var5_5);
            this.ak[var1_1].a = dust.a(this.ak[var1_1].a, 4.0f, (float)(this.aR.a - 5));
            this.ak[var1_1].b = dust.a(this.ak[var1_1].b, 4.0f, 311.0f);
            return;
        }
        var9_9 = 0;
        while (var9_9 < var6_6) {
            block23: {
                block21: {
                    block22: {
                        block20: {
                            var8_10 = this.ak[var1_1].b + var5_5.b;
                            if (var8_10 < 4.0f || var8_10 >= 312.0f) {
                                this.am[var1_1] = -5;
                                return;
                            }
                            var7_8 = (int)var8_10 * this.aR.a + (int)this.ak[var1_1].a;
                            if (this.F[var7_8] > -4) break block20;
                            v1 = this.ak[var1_1];
                            v2 = var8_10;
                            ** GOTO lbl65
                        }
                        if (this.F[var7_8] <= -1) {
                            var5_5.a *= 0.5f;
                            var5_5.b = -var5_5.b;
                            this.am[var1_1] = this.F[var7_8];
                        } else {
                            var5_5.a *= this.aw[this.A[this.F[var7_8]]];
                            this.am[var1_1] = this.A[this.F[var7_8]];
                            if (var5_5.b < 0.0f) {
                                v1 = this.ak[var1_1];
                                v2 = var8_10;
                            } else if (this.P[this.A[this.F[var7_8]]] == 2 && this.A[this.F[var7_8]] != 41) {
                                v1 = this.ak[var1_1];
                                v2 = var8_10;
                            } else {
                                v1 = var5_5;
                                v2 = -var5_5.b;
                            }
lbl65:
                            // 4 sources

                            v1.b = v2;
                        }
                        var8_10 = this.ak[var1_1].a + var5_5.a;
                        if (var8_10 < 4.0f || (float)(this.aR.a - 4) <= var8_10) {
                            this.am[var1_1] = -5;
                            return;
                        }
                        var7_8 = (int)this.ak[var1_1].b * this.aR.a + (int)var8_10;
                        if (this.F[var7_8] <= -4) break block21;
                        if (this.F[var7_8] > -1) break block22;
                        var5_5.b *= 0.5f;
                        var5_5.a = -var5_5.a;
                        this.am[var1_1] = this.F[var7_8];
                        break block23;
                    }
                    var5_5.b *= this.aw[this.A[this.F[var7_8]]];
                    var5_5.a = -var5_5.a;
                    this.am[var1_1] = this.A[this.F[var7_8]];
                    if (this.P[this.A[this.F[var7_8]]] != 2 && this.A[this.F[var7_8]] != 6) break block23;
                }
                this.ak[var1_1].a = var8_10;
            }
            ++var9_9;
        }
    }

    private int b(int n, int n2) {
        int n3 = 0;
        int n4 = n;
        while (n4 < n2) {
            block8: {
                block7: {
                    if (this.am[n4] == -5) {
                        return -5;
                    }
                    if (this.am[n4] < 0) break block7;
                    if (this.P[this.am[n4]] == 3) {
                        return 3;
                    }
                    if (this.am[n4] == 34) {
                        return -5;
                    }
                    if (this.am[n4] == 0) break block8;
                }
                n3 = 1;
            }
            ++n4;
        }
        return n3;
    }

    private void a(int n, int n2, int n3) {
        e e2 = new e(this.aR);
        if (this.aq[n] == 0) {
            if (this.aR.c == 42 && this.aR.aH || this.aR.d == 42 && this.aR.aL) {
                float f = 20.0f;
                int n4 = n2;
                while (n4 < n3) {
                    float f2;
                    e2.a = (float)this.m - this.al[n4].a;
                    e2.b = (float)this.n - this.al[n4].b;
                    float f3 = e2.a();
                    if (f2 < 20.0f && f3 < f) {
                        f = f3;
                        this.aq[n] = n4 - n2 + 1;
                    }
                    ++n4;
                }
                return;
            }
        } else {
            if (this.aR.c == 42 && this.aR.aJ || this.aR.d == 42 && this.aR.aN) {
                this.ak[n2 + this.aq[n] - 1].a += ((float)this.m - this.ak[n2 + this.aq[n] - 1].a) * 0.2f;
                this.ak[n2 + this.aq[n] - 1].b += ((float)this.n - this.ak[n2 + this.aq[n] - 1].b) * 0.2f;
                return;
            }
            this.aq[n] = 0;
        }
    }

    private void v() {
        int n = 0;
        while (n < this.at) {
            this.f(n);
            ++n;
        }
    }

    /*
     * Unable to fully structure code
     */
    private void f(int var1_1) {
        block147: {
            block171: {
                block170: {
                    block169: {
                        block153: {
                            block164: {
                                block154: {
                                    block160: {
                                        block158: {
                                            block162: {
                                                block159: {
                                                    block163: {
                                                        block155: {
                                                            block161: {
                                                                block156: {
                                                                    block157: {
                                                                        block152: {
                                                                            block133: {
                                                                                block142: {
                                                                                    block146: {
                                                                                        block145: {
                                                                                            block144: {
                                                                                                block143: {
                                                                                                    block136: {
                                                                                                        block137: {
                                                                                                            block138: {
                                                                                                                block134: {
                                                                                                                    block135: {
                                                                                                                        var4_2 = new e(this.aR);
                                                                                                                        var3_3 = var1_1 * this.av;
                                                                                                                        if (this.ao[var1_1] != 30) break block133;
                                                                                                                        if (this.as[var1_1] == 0) {
                                                                                                                            v0 = this.aR.aZ;
                                                                                                                            v1 = 37;
                                                                                                                        } else {
                                                                                                                            v0 = this.aR.aZ;
                                                                                                                            v1 = 65;
                                                                                                                        }
                                                                                                                        var5_4 = v0[v1];
                                                                                                                        if (this.as[var1_1] == 0) {
                                                                                                                            v2 = this.aR.aZ;
                                                                                                                            v3 = 39;
                                                                                                                        } else {
                                                                                                                            v2 = this.aR.aZ;
                                                                                                                            v3 = 68;
                                                                                                                        }
                                                                                                                        var6_14 = v2[v3];
                                                                                                                        if (this.as[var1_1] == 0) {
                                                                                                                            v4 = this.aR.aZ;
                                                                                                                            v5 = 38;
                                                                                                                        } else {
                                                                                                                            v4 = this.aR.aZ;
                                                                                                                            v5 = 87;
                                                                                                                        }
                                                                                                                        var7_24 = v4[v5];
                                                                                                                        if (this.as[var1_1] == 0) {
                                                                                                                            v6 = this.aR.aZ;
                                                                                                                            v7 = 40;
                                                                                                                        } else {
                                                                                                                            v6 = this.aR.aZ;
                                                                                                                            v7 = 83;
                                                                                                                        }
                                                                                                                        var8_32 = v6[v7];
                                                                                                                        var9_36 = this.as[var1_1] == 0 ? 0 : 1;
                                                                                                                        v8 = var1_1;
                                                                                                                        this.ap[v8] = this.ap[v8] + 1;
                                                                                                                        var10_38 = this.F[((int)this.al[var3_3 + 4].b + 1) * this.aR.a + (int)this.al[var3_3 + 4].a] > -4;
                                                                                                                        v9 = var11_40 = this.F[((int)this.al[var3_3 + 5].b + 1) * this.aR.a + (int)this.al[var3_3 + 5].a] > -4;
                                                                                                                        if (!var10_38) {
                                                                                                                            v10 = var10_38 = this.F[(int)this.al[var3_3 + 4].b * this.aR.a + (int)this.al[var3_3 + 4].a] > -4;
                                                                                                                        }
                                                                                                                        if (!var11_40) {
                                                                                                                            v11 = var11_40 = this.F[(int)this.al[var3_3 + 5].b * this.aR.a + (int)this.al[var3_3 + 5].a] > -4;
                                                                                                                        }
                                                                                                                        if (var8_32 && this.ar[var1_1] == 39) {
                                                                                                                            var2_41 = 0;
                                                                                                                            while (var2_41 < 6) {
                                                                                                                                this.b(var3_3 + var2_41, 0.01f, 0.997f);
                                                                                                                                ++var2_41;
                                                                                                                            }
                                                                                                                        } else {
                                                                                                                            this.b(var3_3, -0.2f, 0.995f);
                                                                                                                            this.b(var3_3 + 1, -0.1f, 0.995f);
                                                                                                                            this.b(var3_3 + 2, 0.0f, 0.995f);
                                                                                                                            this.b(var3_3 + 3, 0.0f, 0.995f);
                                                                                                                            this.b(var3_3 + 4, 0.3f, 0.995f);
                                                                                                                            this.b(var3_3 + 5, 0.3f, 0.995f);
                                                                                                                        }
                                                                                                                        this.ak[var3_3].b(this.an[var1_1]);
                                                                                                                        this.an[var1_1].a(0.5f);
                                                                                                                        if (this.an[var1_1].a != 0.0f) {
                                                                                                                            this.ao[var1_1] = 32;
                                                                                                                        }
                                                                                                                        if (this.ay[var9_36] > 0) {
                                                                                                                            v12 = var9_36;
                                                                                                                            this.ay[v12] = this.ay[v12] - 1;
                                                                                                                        }
                                                                                                                        if (this.ay[var9_36] != 0 || !var10_38 && !var11_40) break block134;
                                                                                                                        var12_47 = 0.8f;
                                                                                                                        if (!var6_14) break block135;
                                                                                                                        this.ay[var9_36] = 15;
                                                                                                                        if (this.ak[var3_3 + 4].a < this.ak[var3_3 + 5].a) {
                                                                                                                            this.ak[var3_3 + 2].a += 4.0f * var12_47;
                                                                                                                            v13 = this.ak;
                                                                                                                            v14 = var3_3;
                                                                                                                            v15 = 2;
                                                                                                                        } else {
                                                                                                                            this.ak[var3_3 + 3].a += 4.0f * var12_47;
                                                                                                                            v13 = this.ak;
                                                                                                                            v14 = var3_3;
                                                                                                                            v15 = 3;
                                                                                                                        }
                                                                                                                        v13[v14 + v15].b -= 3.0f * var12_47;
                                                                                                                        v16 = this.aA;
                                                                                                                        v17 = var9_36;
                                                                                                                        v18 = 1;
                                                                                                                        break block136;
                                                                                                                    }
                                                                                                                    if (!var5_4) break block136;
                                                                                                                    this.ay[var9_36] = 15;
                                                                                                                    if (this.ak[var3_3 + 4].a > this.ak[var3_3 + 5].a) {
                                                                                                                        this.ak[var3_3 + 2].a -= 4.0f * var12_47;
                                                                                                                        v19 = this.ak;
                                                                                                                        v20 = var3_3;
                                                                                                                        v21 = 2;
                                                                                                                    } else {
                                                                                                                        this.ak[var3_3 + 3].a -= 4.0f * var12_47;
                                                                                                                        v19 = this.ak;
                                                                                                                        v20 = var3_3;
                                                                                                                        v21 = 3;
                                                                                                                    }
                                                                                                                    v19[v20 + v21].b -= 3.0f * var12_47;
                                                                                                                    v22 = this;
                                                                                                                    break block137;
                                                                                                                }
                                                                                                                if (!var6_14) break block138;
                                                                                                                if (this.ak[var3_3 + 1].a - this.al[var3_3 + 1].a < 0.0f) {
                                                                                                                    this.ak[var3_3 + 1].a += 0.1f;
                                                                                                                }
                                                                                                                v16 = this.aA;
                                                                                                                v17 = var9_36;
                                                                                                                v18 = 1;
                                                                                                                break block136;
                                                                                                            }
                                                                                                            if (!var5_4) break block136;
                                                                                                            if (this.ak[var3_3 + 1].a - this.al[var3_3 + 1].a > 0.0f) {
                                                                                                                this.ak[var3_3 + 1].a -= 0.1f;
                                                                                                            }
                                                                                                            v22 = this;
                                                                                                        }
                                                                                                        v16 = v22.aA;
                                                                                                        v17 = var9_36;
                                                                                                        v18 = v16[v17] = 0;
                                                                                                    }
                                                                                                    if (this.az[var9_36] > 1) {
                                                                                                        v23 = var9_36;
                                                                                                        this.az[v23] = this.az[v23] - 1;
                                                                                                    }
                                                                                                    if (this.az[var9_36] > 0 && (var10_38 || var11_40)) {
                                                                                                        v24 = var9_36;
                                                                                                        this.az[v24] = this.az[v24] - 1;
                                                                                                    }
                                                                                                    if (this.az[var9_36] == 0 && var7_24) {
                                                                                                        this.az[var9_36] = 50;
                                                                                                        this.ak[var3_3 + 4].b -= 6.0f;
                                                                                                        this.ak[var3_3 + 5].b -= 6.0f;
                                                                                                    }
                                                                                                    var12_47 = 0.5f;
                                                                                                    this.a(var3_3, var3_3 + 1, 4.0f, var12_47, var12_47);
                                                                                                    this.a(var3_3 + 1, var3_3 + 2, 4.0f, var12_47, var12_47);
                                                                                                    this.a(var3_3 + 1, var3_3 + 3, 4.0f, var12_47, var12_47);
                                                                                                    this.a(var3_3 + 2, var3_3 + 4, 5.0f, var12_47, var12_47);
                                                                                                    this.a(var3_3 + 3, var3_3 + 5, 5.0f, var12_47, var12_47);
                                                                                                    this.a(var3_3 + 2, var3_3 + 3, 5.0f, 0.1f, 0.1f);
                                                                                                    var13_48 = 0.1f;
                                                                                                    var2_41 = 0;
                                                                                                    while (var2_41 < 4) {
                                                                                                        this.a(var3_3 + var2_41, var13_48, 1, this.aq[var1_1] > 0 ? 1 : 0);
                                                                                                        ++var2_41;
                                                                                                    }
                                                                                                    var2_41 = 4;
                                                                                                    while (var2_41 < 6) {
                                                                                                        this.a(var3_3 + var2_41, var13_48, 0, this.aq[var1_1] > 0 ? 1 : 0);
                                                                                                        ++var2_41;
                                                                                                    }
                                                                                                    var14_49 = 0;
                                                                                                    while (var14_49 < 3) {
                                                                                                        var15_50 = -1;
                                                                                                        while (var15_50 < 2) {
                                                                                                            block141: {
                                                                                                                block140: {
                                                                                                                    block139: {
                                                                                                                        var16_51 = this.F[((int)this.al[var3_3].b + var14_49) * this.aR.a + ((int)this.al[var3_3].a + var15_50)];
                                                                                                                        if (var16_51 != -4) break block139;
                                                                                                                        v25 = this.ar;
                                                                                                                        v26 = var1_1;
                                                                                                                        v27 = 8;
                                                                                                                        break block140;
                                                                                                                    }
                                                                                                                    if (var16_51 < 0 || this.ax[this.A[var16_51]] != 1) break block141;
                                                                                                                    v25 = this.ar;
                                                                                                                    v26 = var1_1;
                                                                                                                    v27 = this.A[var16_51];
                                                                                                                }
                                                                                                                v25[v26] = v27;
                                                                                                            }
                                                                                                            ++var15_50;
                                                                                                        }
                                                                                                        ++var14_49;
                                                                                                    }
                                                                                                    if (var7_24 && (var5_4 || var6_14) || !var8_32 || this.ar[var1_1] == 0) break block142;
                                                                                                    var15_50 = (int)this.ak[var3_3].a;
                                                                                                    var16_51 = (int)this.ak[var3_3].b + 1;
                                                                                                    if (this.ar[var1_1] == 23) {
                                                                                                        var15_50 += this.aA[var9_36] == 0 ? 8 : -8;
                                                                                                        var16_51 += 12;
                                                                                                    }
                                                                                                    var15_50 = dust.a(var15_50, 8, 407);
                                                                                                    var16_51 = dust.a(var16_51, 8, 307);
                                                                                                    if (this.ar[var1_1] != 8) break block143;
                                                                                                    var17_52 = (var16_51 >> 2) * this.a + (var15_50 >> 2);
                                                                                                    if (this.l[var17_52] == 0) {
                                                                                                        this.e[var17_52].a += (float)(this.aA[var9_36] == 0 ? -1 : 1);
                                                                                                    }
                                                                                                    break block142;
                                                                                                }
                                                                                                if (this.ar[var1_1] == 39 || this.F[var16_51 * this.aR.a + var15_50] != -5 || (var17_52 = this.a((float)var15_50, (float)var16_51, this.ar[var1_1])) < 0) break block142;
                                                                                                if (this.aA[var9_36] != 0) break block144;
                                                                                                v28 = this.z[var17_52];
                                                                                                v29 = v28;
                                                                                                v30 = v28.a - 20.0f;
                                                                                                break block145;
                                                                                            }
                                                                                            if (this.aA[var9_36] != 1) break block146;
                                                                                            v31 = this.z[var17_52];
                                                                                            v29 = v31;
                                                                                            v30 = v31.a + 20.0f;
                                                                                        }
                                                                                        v29.a = v30;
                                                                                        this.z[var17_52].b += this.aR.d(3.0f) - 1.0f;
                                                                                    }
                                                                                    if (this.ar[var1_1] == 4) {
                                                                                        this.z[var17_52].a *= 3.0f;
                                                                                        this.z[var17_52].b += 18.0f;
                                                                                        v32 = this.B;
                                                                                        v33 = var17_52;
                                                                                        v34 = 2;
                                                                                    } else if (this.ar[var1_1] == 13) {
                                                                                        this.z[var17_52].b = 20.0f;
                                                                                    } else if (this.ar[var1_1] == 19) {
                                                                                        this.z[var17_52].a *= 0.1f;
                                                                                        this.z[var17_52].b *= 0.1f;
                                                                                    } else if (this.ar[var1_1] == 33) {
                                                                                        if (this.aA[var9_36] == 0) {
                                                                                            v32 = this.B;
                                                                                            v33 = var17_52;
                                                                                            v34 = 5;
                                                                                        } else {
                                                                                            v32 = this.B;
                                                                                            v33 = var17_52;
                                                                                            v34 = v32[v33] = 1;
                                                                                        }
                                                                                    }
                                                                                }
                                                                                if (this.b(var3_3, var3_3 + 6) == 3 || this.b(var3_3, var3_3 + 6) == -5) {
                                                                                    this.ao[var1_1] = 32;
                                                                                }
                                                                                if (this.aR.y != 1) break block147;
                                                                                var18_53 = 4;
                                                                                while (var18_53 <= 5) {
                                                                                    block151: {
                                                                                        block150: {
                                                                                            block149: {
                                                                                                block148: {
                                                                                                    var16_51 = 0;
                                                                                                    var15_50 = 0;
                                                                                                    if (!(this.ak[var3_3 + var18_53].a < 8.0f)) break block148;
                                                                                                    v35 = 406;
                                                                                                    break block149;
                                                                                                }
                                                                                                if (!((float)(this.aR.a - 8) <= this.ak[var3_3 + var18_53].a)) break block150;
                                                                                                v35 = 10;
                                                                                            }
                                                                                            var15_50 = v35;
                                                                                            var16_51 = (int)this.al[var3_3 + var18_53].b;
                                                                                        }
                                                                                        if (var15_50 + var16_51 == 0) break block151;
                                                                                        this.ao[var1_1] = 30;
                                                                                        var17_52 = var16_51 * this.aR.a + var15_50;
                                                                                        if (this.F[var17_52] <= -4) ** GOTO lbl-1000
                                                                                        if (this.F[var17_52] <= -1) {
                                                                                            this.ak[var3_3 + var18_53].a(this.al[var3_3 + var18_53]);
                                                                                        } else if (this.P[this.A[this.F[var17_52]]] != 2) {
                                                                                            this.ak[var3_3 + var18_53].a(this.al[var3_3 + var18_53]);
                                                                                        } else lbl-1000:
                                                                                        // 2 sources

                                                                                        {
                                                                                            var4_2.a(this.ak[var3_3 + var18_53], this.al[var3_3 + var18_53]);
                                                                                            var4_2.d();
                                                                                            var1_1 = 0;
                                                                                            while (var1_1 <= 10) {
                                                                                                this.ak[var3_3 + var1_1].a = (float)var15_50 + var4_2.a + this.aR.b(-0.1f, 0.1f);
                                                                                                this.ak[var3_3 + var1_1].b = (float)var16_51 + var4_2.b + this.aR.b(-0.1f, 0.1f);
                                                                                                this.al[var3_3 + var1_1].a(var15_50, (float)var16_51);
                                                                                                ++var1_1;
                                                                                            }
                                                                                            return;
                                                                                        }
                                                                                    }
                                                                                    ++var18_53;
                                                                                }
                                                                                return;
                                                                            }
                                                                            if (this.ao[var1_1] == 32) {
                                                                                this.ak[var3_3 + 10].a(this.ak[var3_3 + 5]);
                                                                                this.al[var3_3 + 10].a(this.al[var3_3 + 5]);
                                                                                this.ak[var3_3 + 9].a(this.ak[var3_3 + 4]);
                                                                                this.al[var3_3 + 9].a(this.al[var3_3 + 4]);
                                                                                this.ak[var3_3 + 8].a(this.ak[var3_3 + 3]);
                                                                                this.al[var3_3 + 8].a(this.al[var3_3 + 3]);
                                                                                this.ak[var3_3 + 7].a(this.ak[var3_3 + 3]);
                                                                                this.al[var3_3 + 7].a(this.al[var3_3 + 3]);
                                                                                this.ak[var3_3 + 6].a(this.ak[var3_3 + 2]);
                                                                                this.al[var3_3 + 6].a(this.al[var3_3 + 2]);
                                                                                this.ak[var3_3 + 5].a(this.ak[var3_3 + 2]);
                                                                                this.al[var3_3 + 5].a(this.al[var3_3 + 2]);
                                                                                this.ak[var3_3 + 4].a(this.ak[var3_3 + 1]);
                                                                                this.al[var3_3 + 4].a(this.al[var3_3 + 1]);
                                                                                this.ak[var3_3 + 3].a(this.ak[var3_3 + 1]);
                                                                                this.al[var3_3 + 3].a(this.al[var3_3 + 1]);
                                                                                this.ak[var3_3 + 2].a(this.ak[var3_3 + 1]);
                                                                                this.al[var3_3 + 2].a(this.al[var3_3 + 1]);
                                                                                this.ak[var3_3 + 1].a(this.ak[var3_3]);
                                                                                this.al[var3_3 + 1].a(this.al[var3_3]);
                                                                                this.ak[var3_3].a(this.ak[var3_3]);
                                                                                this.al[var3_3].a(this.al[var3_3]);
                                                                                this.an[var1_1].b -= 1.0f;
                                                                                this.ap[var1_1] = 0;
                                                                                this.ao[var1_1] = 33;
                                                                                return;
                                                                            }
                                                                            if (this.ao[var1_1] != 33) break block152;
                                                                            v36 = var1_1;
                                                                            this.ap[v36] = this.ap[v36] + 1;
                                                                            var2_42 = 0;
                                                                            while (var2_42 < 11) {
                                                                                this.b(var3_3 + var2_42, 0.1f, 0.999f);
                                                                                this.ak[var3_3 + var2_42].b(this.an[var1_1]);
                                                                                ++var2_42;
                                                                            }
                                                                            this.an[var1_1].a(0.5f);
                                                                            var5_5 = 0.5f;
                                                                            var6_15 = (float)(150 - this.ap[var1_1]) / 150.0f;
                                                                            this.a(var3_3 + 1, var3_3 + 2, 4.0f * var6_15, var5_5, var5_5);
                                                                            this.a(var3_3 + 3, var3_3 + 5, 4.0f * var6_15, var5_5, var5_5);
                                                                            this.a(var3_3 + 4, var3_3 + 7, 4.0f * var6_15, var5_5, var5_5);
                                                                            this.a(var3_3 + 6, var3_3 + 9, 5.0f * var6_15, var5_5, var5_5);
                                                                            this.a(var3_3 + 8, var3_3 + 10, 5.0f * var6_15, var5_5, var5_5);
                                                                            var7_25 = 0.1f;
                                                                            var2_42 = 0;
                                                                            while (var2_42 < 11) {
                                                                                this.a(var3_3 + var2_42, var7_25, 0, 0);
                                                                                ++var2_42;
                                                                            }
                                                                            if (this.ap[var1_1] > 150) {
                                                                                this.e(var1_1);
                                                                                return;
                                                                            }
                                                                            break block147;
                                                                        }
                                                                        if (this.ao[var1_1] != 10 && this.ao[var1_1] != 11) break block153;
                                                                        v37 = var1_1;
                                                                        this.ap[v37] = this.ap[v37] + 1;
                                                                        if (this.ao[var1_1] == 10) {
                                                                            this.b(var3_3, -0.2f, 0.995f);
                                                                            this.b(var3_3 + 1, -0.1f, 0.995f);
                                                                            this.b(var3_3 + 2, 0.0f, 0.995f);
                                                                            this.b(var3_3 + 3, 0.0f, 0.995f);
                                                                            this.b(var3_3 + 4, 0.3f, 0.995f);
                                                                            v38 = this;
                                                                            v39 = var3_3 + 5;
                                                                            v40 = 0.3f;
                                                                        } else {
                                                                            this.b(var3_3, 0.1f, 0.995f);
                                                                            this.b(var3_3 + 1, 0.1f, 0.995f);
                                                                            this.b(var3_3 + 2, 0.1f, 0.995f);
                                                                            this.b(var3_3 + 3, 0.1f, 0.995f);
                                                                            this.b(var3_3 + 4, 0.1f, 0.995f);
                                                                            v38 = this;
                                                                            v39 = var3_3 + 5;
                                                                            v40 = 0.1f;
                                                                        }
                                                                        v38.b(v39, v40, 0.995f);
                                                                        this.a(var1_1, var3_3, var3_3 + 6);
                                                                        this.ak[var3_3].b(this.an[var1_1]);
                                                                        this.an[var1_1].a(0.5f);
                                                                        if (this.ao[var1_1] != 10) break block154;
                                                                        if (this.am[var3_3 + 4] == 0 || this.am[var3_3 + 5] == 0) break block155;
                                                                        var5_6 = (int)this.aR.d(100.0f);
                                                                        if (var5_6 >= 5) break block156;
                                                                        if (!(this.ak[var3_3 + 4].a < this.ak[var3_3 + 5].a)) break block157;
                                                                        this.ak[var3_3 + 4].a += 4.0f;
                                                                        v41 = this.ak;
                                                                        v42 = var3_3;
                                                                        v43 = 4;
                                                                        break block158;
                                                                    }
                                                                    v44 = this.ak[var3_3 + 5];
                                                                    v45 = v44;
                                                                    v46 = v44.a;
                                                                    v47 = 4.0f;
                                                                    break block159;
                                                                }
                                                                if (var5_6 >= 10) break block160;
                                                                if (!(this.ak[var3_3 + 4].a > this.ak[var3_3 + 5].a)) break block161;
                                                                this.ak[var3_3 + 4].a -= 4.0f;
                                                                v41 = this.ak;
                                                                v42 = var3_3;
                                                                v43 = 4;
                                                                break block158;
                                                            }
                                                            v48 = this.ak[var3_3 + 5];
                                                            v45 = v48;
                                                            v49 = v48.a - 4.0f;
                                                            break block162;
                                                        }
                                                        if (this.am[var3_3 + 4] == 0) break block163;
                                                        if (!(this.aR.d(100.0f) < 2.0f)) break block160;
                                                        this.ak[var3_3 + 4].a += this.aR.b(-4.0f, 4.0f);
                                                        v41 = this.ak;
                                                        v42 = var3_3;
                                                        v43 = 4;
                                                        break block158;
                                                    }
                                                    if (this.am[var3_3 + 5] == 0 || !(this.aR.d(100.0f) < 2.0f)) break block160;
                                                    v50 = this.ak[var3_3 + 5];
                                                    v45 = v50;
                                                    v46 = v50.a;
                                                    v47 = this.aR.b(-4.0f, 4.0f);
                                                }
                                                v49 = v46 + v47;
                                            }
                                            v45.a = v49;
                                            v41 = this.ak;
                                            v42 = var3_3;
                                            v43 = 5;
                                        }
                                        v41[v42 + v43].b -= 4.0f;
                                    }
                                    var5_6 = 0;
                                    while (var5_6 < this.at) {
                                        if (var1_1 != var5_6 && (this.ao[var5_6] == 10 || this.ao[var5_6] == 11 || this.ao[var5_6] == 30)) {
                                            var6_16 = var5_6 * this.av;
                                            var7_26 = dust.e(this.ak[var3_3 + 4].a - this.ak[var6_16].a);
                                            var8_33 = this.ak[var3_3 + 4].b - this.ak[var6_16].b;
                                            if (var7_26 <= 2.0f && var8_33 >= 0.0f && var8_33 <= 6.0f) {
                                                this.an[var5_6].a += this.ak[var3_3 + 4].a - this.al[var3_3 + 4].a;
                                                this.an[var5_6].b += (this.ak[var3_3 + 4].b - this.al[var3_3 + 4].b) * 2.0f;
                                                if (this.ao[var5_6] == 10) {
                                                    this.ao[var5_6] = 11;
                                                }
                                                this.ap[var5_6] = 0;
                                            }
                                            var7_26 = dust.e(this.ak[var3_3 + 5].a - this.ak[var6_16].a);
                                            var8_33 = this.ak[var3_3 + 5].b - this.ak[var6_16].b;
                                            if (var7_26 <= 2.0f && var8_33 >= 0.0f && var8_33 <= 6.0f) {
                                                this.an[var5_6].a += this.ak[var3_3 + 5].a - this.al[var3_3 + 5].a;
                                                this.an[var5_6].b += (this.ak[var3_3 + 5].b - this.al[var3_3 + 5].b) * 2.0f;
                                                if (this.ao[var5_6] == 10) {
                                                    this.ao[var5_6] = 11;
                                                }
                                                this.ap[var5_6] = 0;
                                            }
                                        }
                                        ++var5_6;
                                    }
                                    break block164;
                                }
                                if (this.ap[var1_1] > 10 && (this.am[var3_3 + 4] != 0 || this.am[var3_3 + 5] != 0) && this.aR.d(100.0f) < 10.0f) {
                                    this.ao[var1_1] = 10;
                                    this.ap[var1_1] = 0;
                                }
                            }
                            var5_7 = 0.5f;
                            this.a(var3_3, var3_3 + 1, 4.0f, var5_7, var5_7);
                            this.a(var3_3 + 1, var3_3 + 2, 4.0f, var5_7, var5_7);
                            this.a(var3_3 + 1, var3_3 + 3, 4.0f, var5_7, var5_7);
                            this.a(var3_3 + 2, var3_3 + 4, 5.0f, var5_7, var5_7);
                            this.a(var3_3 + 3, var3_3 + 5, 5.0f, var5_7, var5_7);
                            this.a(var3_3 + 2, var3_3 + 3, 5.0f, 0.1f, 0.1f);
                            var6_17 = 0.1f;
                            var2_43 = 0;
                            while (var2_43 < 4) {
                                this.a(var3_3 + var2_43, var6_17, 1, this.aq[var1_1] > 0 ? 1 : 0);
                                ++var2_43;
                            }
                            var2_43 = 4;
                            while (var2_43 < 6) {
                                this.a(var3_3 + var2_43, var6_17, 0, this.aq[var1_1] > 0 ? 1 : 0);
                                ++var2_43;
                            }
                            if (this.b(var3_3, var3_3 + 6) == 3 || this.b(var3_3, var3_3 + 6) == -5) {
                                this.ao[var1_1] = 12;
                            }
                            if (this.ao[var1_1] == 10) {
                                if (this.b(var3_3, var3_3 + 6) != 0) {
                                    v51 = this.ap;
                                    v52 = var1_1;
                                    v53 = 0;
                                } else if (this.ap[var1_1] > 50) {
                                    v51 = this.ao;
                                    v52 = var1_1;
                                    v53 = v51[v52] = 11;
                                }
                            }
                            if (this.aR.y != 1) break block147;
                            var10_39 = 4;
                            while (var10_39 <= 5) {
                                block168: {
                                    block167: {
                                        block166: {
                                            block165: {
                                                var8_34 = 0;
                                                var7_27 = 0;
                                                if (!(this.ak[var3_3 + var10_39].a < 8.0f)) break block165;
                                                v54 = 406;
                                                break block166;
                                            }
                                            if (!((float)(this.aR.a - 8) <= this.ak[var3_3 + var10_39].a)) break block167;
                                            v54 = 10;
                                        }
                                        var7_27 = v54;
                                        var8_34 = (int)this.al[var3_3 + var10_39].b;
                                    }
                                    if (var7_27 + var8_34 == 0) break block168;
                                    this.ao[var1_1] = 10;
                                    this.ap[var1_1] = 0;
                                    var9_37 = var8_34 * this.aR.a + var7_27;
                                    if (this.F[var9_37] <= -4) ** GOTO lbl-1000
                                    if (this.F[var9_37] <= -1) {
                                        this.ak[var3_3 + var10_39].a(this.al[var3_3 + var10_39]);
                                    } else if (this.P[this.A[this.F[var9_37]]] != 2) {
                                        this.ak[var3_3 + var10_39].a(this.al[var3_3 + var10_39]);
                                    } else lbl-1000:
                                    // 2 sources

                                    {
                                        var4_2.a(this.ak[var3_3 + var10_39], this.al[var3_3 + var10_39]);
                                        var4_2.d();
                                        var1_1 = 0;
                                        while (var1_1 <= 10) {
                                            this.ak[var3_3 + var1_1].a = (float)var7_27 + var4_2.a + this.aR.b(-0.1f, 0.1f);
                                            this.ak[var3_3 + var1_1].b = (float)var8_34 + var4_2.b + this.aR.b(-0.1f, 0.1f);
                                            this.al[var3_3 + var1_1].a(var7_27, (float)var8_34);
                                            ++var1_1;
                                        }
                                        return;
                                    }
                                }
                                ++var10_39;
                            }
                            return;
                        }
                        if (this.ao[var1_1] == 12) {
                            this.ak[var3_3 + 10].a(this.ak[var3_3 + 5]);
                            this.al[var3_3 + 10].a(this.al[var3_3 + 5]);
                            this.ak[var3_3 + 9].a(this.ak[var3_3 + 4]);
                            this.al[var3_3 + 9].a(this.al[var3_3 + 4]);
                            this.ak[var3_3 + 8].a(this.ak[var3_3 + 3]);
                            this.al[var3_3 + 8].a(this.al[var3_3 + 3]);
                            this.ak[var3_3 + 7].a(this.ak[var3_3 + 3]);
                            this.al[var3_3 + 7].a(this.al[var3_3 + 3]);
                            this.ak[var3_3 + 6].a(this.ak[var3_3 + 2]);
                            this.al[var3_3 + 6].a(this.al[var3_3 + 2]);
                            this.ak[var3_3 + 5].a(this.ak[var3_3 + 2]);
                            this.al[var3_3 + 5].a(this.al[var3_3 + 2]);
                            this.ak[var3_3 + 4].a(this.ak[var3_3 + 1]);
                            this.al[var3_3 + 4].a(this.al[var3_3 + 1]);
                            this.ak[var3_3 + 3].a(this.ak[var3_3 + 1]);
                            this.al[var3_3 + 3].a(this.al[var3_3 + 1]);
                            this.ak[var3_3 + 2].a(this.ak[var3_3 + 1]);
                            this.al[var3_3 + 2].a(this.al[var3_3 + 1]);
                            this.ak[var3_3 + 1].a(this.ak[var3_3]);
                            this.al[var3_3 + 1].a(this.al[var3_3]);
                            this.ak[var3_3].a(this.ak[var3_3]);
                            this.al[var3_3].a(this.al[var3_3]);
                            this.an[var1_1].b -= 1.0f;
                            this.ap[var1_1] = 0;
                            this.ao[var1_1] = 13;
                            return;
                        }
                        if (this.ao[var1_1] != 13) break block169;
                        v55 = var1_1;
                        this.ap[v55] = this.ap[v55] + 1;
                        var2_44 = 0;
                        while (var2_44 < 11) {
                            this.b(var3_3 + var2_44, 0.1f, 0.999f);
                            this.ak[var3_3 + var2_44].b(this.an[var1_1]);
                            ++var2_44;
                        }
                        this.an[var1_1].a(0.5f);
                        var5_8 = 0.5f;
                        var6_18 = (float)(150 - this.ap[var1_1]) / 150.0f;
                        this.a(var3_3 + 1, var3_3 + 2, 4.0f * var6_18, var5_8, var5_8);
                        this.a(var3_3 + 3, var3_3 + 5, 4.0f * var6_18, var5_8, var5_8);
                        this.a(var3_3 + 4, var3_3 + 7, 4.0f * var6_18, var5_8, var5_8);
                        this.a(var3_3 + 6, var3_3 + 9, 5.0f * var6_18, var5_8, var5_8);
                        this.a(var3_3 + 8, var3_3 + 10, 5.0f * var6_18, var5_8, var5_8);
                        var7_28 = 0.1f;
                        var2_44 = 0;
                        while (var2_44 < 11) {
                            this.a(var3_3 + var2_44, var7_28, 0, 0);
                            ++var2_44;
                        }
                        if (this.ap[var1_1] > 150) {
                            this.e(var1_1);
                            return;
                        }
                        break block147;
                    }
                    if (this.ao[var1_1] == 20) {
                        v56 = var1_1;
                        this.ap[v56] = this.ap[v56] + 1;
                        var2_45 = 0;
                        while (var2_45 < 4) {
                            this.b(var3_3 + var2_45, 0.1f, 1.0f);
                            ++var2_45;
                        }
                        this.a(var1_1, var3_3, var3_3 + 4);
                        var2_45 = 0;
                        while (var2_45 < 4) {
                            var5_9 = 0;
                            while (var5_9 < this.at) {
                                if (this.ao[var5_9] == 10 || this.ao[var5_9] == 11 || this.ao[var5_9] == 30) {
                                    var6_19 = var5_9 * this.av;
                                    var7_29 = dust.e(this.ak[var6_19 + 4].a - this.ak[var3_3 + var2_45].a);
                                    var8_35 = dust.e(this.ak[var6_19 + 4].b - this.ak[var3_3 + var2_45].b);
                                    if (var7_29 <= 3.0f && var8_35 <= 3.0f) {
                                        this.ak[var3_3 + var2_45].a += this.ak[var6_19 + 4].a - this.al[var6_19 + 4].a;
                                        this.ak[var3_3 + var2_45].b += (this.ak[var6_19 + 4].b - this.al[var6_19 + 4].b) * 2.0f;
                                    }
                                    var7_29 = dust.e(this.ak[var6_19 + 5].a - this.ak[var3_3 + var2_45].a);
                                    var8_35 = dust.e(this.ak[var6_19 + 5].b - this.ak[var3_3 + var2_45].b);
                                    if (var7_29 <= 3.0f && var8_35 <= 3.0f) {
                                        this.ak[var3_3 + var2_45].a += this.ak[var6_19 + 5].a - this.al[var6_19 + 5].a;
                                        this.ak[var3_3 + var2_45].b += (this.ak[var6_19 + 5].b - this.al[var6_19 + 5].b) * 2.0f;
                                    }
                                }
                                ++var5_9;
                            }
                            ++var2_45;
                        }
                        var5_10 = 0.5f;
                        var6_20 = (this.ar[var1_1] + 1) * 4;
                        var7_29 = 1.4142135f;
                        this.a(var3_3, var3_3 + 1, var6_20, var5_10, var5_10);
                        this.a(var3_3 + 1, var3_3 + 2, var6_20, var5_10, var5_10);
                        this.a(var3_3 + 2, var3_3 + 3, var6_20, var5_10, var5_10);
                        this.a(var3_3 + 3, var3_3, var6_20, var5_10, var5_10);
                        this.a(var3_3, var3_3 + 2, var6_20 * var7_29, var5_10, var5_10);
                        this.a(var3_3 + 1, var3_3 + 3, var6_20 * var7_29, var5_10, var5_10);
                        var8_35 = 0.5f;
                        var2_45 = 0;
                        while (var2_45 < 4) {
                            this.a(var3_3 + var2_45, var8_35, 0, 1);
                            ++var2_45;
                        }
                        if (this.b(var3_3, var3_3 + 6) == 3 || this.b(var3_3, var3_3 + 6) == -5) {
                            this.ao[var1_1] = 21;
                        }
                        return;
                    }
                    if (this.ao[var1_1] == 21) {
                        this.ak[var3_3 + 7].a(this.ak[var3_3]);
                        this.al[var3_3 + 7].a(this.al[var3_3]);
                        this.ak[var3_3 + 6].a(this.ak[var3_3 + 3]);
                        this.al[var3_3 + 6].a(this.al[var3_3 + 3]);
                        this.ak[var3_3 + 5].a(this.ak[var3_3 + 3]);
                        this.al[var3_3 + 5].a(this.al[var3_3 + 3]);
                        this.ak[var3_3 + 4].a(this.ak[var3_3 + 2]);
                        this.al[var3_3 + 4].a(this.al[var3_3 + 2]);
                        this.ak[var3_3 + 3].a(this.ak[var3_3 + 2]);
                        this.al[var3_3 + 3].a(this.al[var3_3 + 2]);
                        this.ak[var3_3 + 2].a(this.ak[var3_3 + 1]);
                        this.al[var3_3 + 2].a(this.al[var3_3 + 1]);
                        this.ak[var3_3 + 1].a(this.ak[var3_3 + 1]);
                        this.al[var3_3 + 1].a(this.al[var3_3 + 1]);
                        this.ak[var3_3].a(this.ak[var3_3]);
                        this.al[var3_3].a(this.al[var3_3]);
                        this.aq[var1_1] = 0;
                        this.ap[var1_1] = 0;
                        if (this.b(var3_3, var3_3 + 4) == -5) {
                            this.ao[var1_1] = 23;
                            return;
                        }
                        this.ao[var1_1] = 22;
                        return;
                    }
                    if (this.ao[var1_1] != 22 && this.ao[var1_1] != 23) break block170;
                    v57 = var1_1;
                    this.ap[v57] = this.ap[v57] + 1;
                    this.a(var1_1, var3_3, var3_3 + 8);
                    var2_46 = 0;
                    while (var2_46 < 8) {
                        this.b(var3_3 + var2_46, 0.1f, 0.999f);
                        ++var2_46;
                    }
                    var5_11 = 0.5f;
                    var6_21 = (float)(150 - this.ap[var1_1]) / 150.0f * (float)(this.ar[var1_1] + 1) * 4.0f;
                    this.a(var3_3, var3_3 + 1, var6_21, var5_11, var5_11);
                    this.a(var3_3 + 2, var3_3 + 3, var6_21, var5_11, var5_11);
                    this.a(var3_3 + 4, var3_3 + 5, var6_21, var5_11, var5_11);
                    this.a(var3_3 + 6, var3_3 + 7, var6_21, var5_11, var5_11);
                    if (this.ao[var1_1] == 22 && this.aR.h[this.aR.g] - this.D >= 1000) {
                        var2_46 = 0;
                        while (var2_46 < 8) {
                            var4_2.a(this.al[var3_3 + var2_46 + 1], this.al[var3_3 + var2_46]);
                            var4_2.a(this.aR.d(1.0f));
                            var4_2.b(this.al[var3_3 + var2_46]);
                            var7_30 = (int)var4_2.b * this.aR.a + (int)var4_2.a;
                            if (this.F[var7_30] <= -4) {
                                this.a((float)((int)var4_2.a), (float)((int)var4_2.b), 4);
                            }
                            var2_46 += 2;
                        }
                    }
                    var7_31 = 0.1f;
                    var2_46 = 0;
                    while (var2_46 < 8) {
                        this.a(var3_3 + var2_46, var7_31, 0, 0);
                        ++var2_46;
                    }
                    if (this.ap[var1_1] > 150) {
                        this.e(var1_1);
                        return;
                    }
                    break block147;
                }
                if (this.ao[var1_1] != 40) break block147;
                if (this.am[var3_3] != 0) break block171;
                var5_12 = 0;
                while (var5_12 < this.at) {
                    block172: {
                        block174: {
                            block173: {
                                if (this.ak[var3_3].a + 8.0f < this.ak[var5_12 * this.av].a || this.ak[var5_12 * this.av].a < this.ak[var3_3].a - 4.0f || this.ak[var3_3].b + 8.0f < this.ak[var5_12 * this.av].b || this.ak[var5_12 * this.av].b < this.ak[var3_3].b - 4.0f) break block172;
                                if (this.ao[var5_12] != 10 && this.ao[var5_12] != 20) break block173;
                                v58 = this;
                                break block174;
                            }
                            if (this.ao[var5_12] != 30) break block172;
                            var6_22 = 0;
                            while (var6_22 < this.at) {
                                if (this.ao[var6_22] == 40 && this.am[var6_22 * this.av] == 30) {
                                    this.am[var6_22 * this.av] = 0;
                                }
                                ++var6_22;
                            }
                            v58 = this;
                        }
                        v58.am[var3_3] = this.ao[var5_12];
                        this.ar[var1_1] = this.ar[var5_12];
                    }
                    ++var5_12;
                }
                var6_22 = 0;
                while (var6_22 < this.aH) {
                    if (!(this.aD[var6_22] == 0 || this.ak[var3_3].a + 8.0f < this.aB[var6_22].a || this.aB[var6_22].a < this.ak[var3_3].a - 4.0f || this.ak[var3_3].b + 8.0f < this.aB[var6_22].b || this.aB[var6_22].b < this.ak[var3_3].b - 4.0f)) {
                        this.am[var3_3] = -2;
                        this.ar[var1_1] = this.aG[var6_22];
                    }
                    ++var6_22;
                }
                return;
            }
            var5_13 = (int)this.ak[var3_3].a;
            var6_23 = (int)this.ak[var3_3].b;
            if (this.am[var3_3] == 30) {
                if (this.aR.d(100.0f) < 10.0f) {
                    this.c(var5_13, var6_23, 30, this.ar[var1_1]);
                    return;
                }
            } else if (this.aR.d(100.0f) < 1.0f) {
                if (this.am[var3_3] == 10) {
                    this.c(var5_13, var6_23, 0, 0);
                    return;
                }
                if (this.am[var3_3] == 20) {
                    this.c(var5_13, var6_23, 22, this.ar[var1_1]);
                    return;
                }
                if (this.am[var3_3] == -2) {
                    this.b(var5_13 + 2, var6_23 + 2, this.ar[var1_1]);
                }
            }
        }
    }

    /*
     * Unable to fully structure code
     */
    private void w() {
        new e(this.aR);
        var5_1 = -8018;
        var6_2 = -1;
        if (this.aR.j == 13) {
            var5_1 = -16777216;
            var6_2 = -16777216;
        }
        var1_3 = 0;
        while (var1_3 < this.at) {
            var3_5 = var1_3 * this.av;
            switch (this.ao[var1_3]) {
                case 10: 
                case 11: 
                case 12: {
                    this.aR.a(this.ak[var3_5].a, this.ak[var3_5].b, this.ak[var3_5 + 1].a, this.ak[var3_5 + 1].b, var5_1);
                    this.aR.a(this.ak[var3_5 + 1].a, this.ak[var3_5 + 1].b, this.ak[var3_5 + 2].a, this.ak[var3_5 + 2].b, var6_2);
                    this.aR.a(this.ak[var3_5 + 1].a, this.ak[var3_5 + 1].b, this.ak[var3_5 + 3].a, this.ak[var3_5 + 3].b, var6_2);
                    this.aR.a(this.ak[var3_5 + 2].a, this.ak[var3_5 + 2].b, this.ak[var3_5 + 4].a, this.ak[var3_5 + 4].b, var6_2);
                    this.aR.a(this.ak[var3_5 + 3].a, this.ak[var3_5 + 3].b, this.ak[var3_5 + 5].a, this.ak[var3_5 + 5].b, var6_2);
                    v0 = this.aR;
                    v1 = (int)this.ak[var3_5].a - 1;
                    v2 = (int)this.ak[var3_5].b - 1;
                    v3 = 3;
                    v4 = 3;
                    v5 = var5_1;
                    ** GOTO lbl148
                }
                case 13: {
                    this.aR.a(this.ak[var3_5 + 1].a, this.ak[var3_5 + 1].b, this.ak[var3_5 + 2].a, this.ak[var3_5 + 2].b, var6_2);
                    if (this.ap[var1_3] > 145) break;
                    this.aR.a(this.ak[var3_5 + 3].a, this.ak[var3_5 + 3].b, this.ak[var3_5 + 5].a, this.ak[var3_5 + 5].b, var6_2);
                    if (this.ap[var1_3] > 140) break;
                    this.aR.a(this.ak[var3_5 + 4].a, this.ak[var3_5 + 4].b, this.ak[var3_5 + 7].a, this.ak[var3_5 + 7].b, var6_2);
                    if (this.ap[var1_3] > 135) break;
                    this.aR.a(this.ak[var3_5 + 6].a, this.ak[var3_5 + 6].b, this.ak[var3_5 + 9].a, this.ak[var3_5 + 9].b, var6_2);
                    if (this.ap[var1_3] > 130) break;
                    this.aR.a(this.ak[var3_5 + 8].a, this.ak[var3_5 + 8].b, this.ak[var3_5 + 10].a, this.ak[var3_5 + 10].b, var6_2);
                    if (this.ap[var1_3] > 125) break;
                    v0 = this.aR;
                    v1 = (int)this.ak[var3_5].a - 1;
                    v2 = (int)this.ak[var3_5].b - 1;
                    v3 = 2;
                    v4 = 2;
                    v5 = var5_1;
                    ** GOTO lbl148
                }
                case 20: 
                case 21: {
                    this.aR.a(this.ak[var3_5].a, this.ak[var3_5].b, this.ak[var3_5 + 1].a, this.ak[var3_5 + 1].b, var5_1);
                    this.aR.a(this.ak[var3_5 + 1].a, this.ak[var3_5 + 1].b, this.ak[var3_5 + 2].a, this.ak[var3_5 + 2].b, var5_1);
                    this.aR.a(this.ak[var3_5 + 2].a, this.ak[var3_5 + 2].b, this.ak[var3_5 + 3].a, this.ak[var3_5 + 3].b, var5_1);
                    this.aR.a(this.ak[var3_5 + 3].a, this.ak[var3_5 + 3].b, this.ak[var3_5].a, this.ak[var3_5].b, var5_1);
                    break;
                }
                case 22: 
                case 23: {
                    this.aR.a(this.ak[var3_5].a, this.ak[var3_5].b, this.ak[var3_5 + 1].a, this.ak[var3_5 + 1].b, var5_1);
                    if (this.ap[var1_3] > 145) break;
                    this.aR.a(this.ak[var3_5 + 2].a, this.ak[var3_5 + 2].b, this.ak[var3_5 + 3].a, this.ak[var3_5 + 3].b, var5_1);
                    if (this.ap[var1_3] > 140) break;
                    this.aR.a(this.ak[var3_5 + 4].a, this.ak[var3_5 + 4].b, this.ak[var3_5 + 5].a, this.ak[var3_5 + 5].b, var5_1);
                    if (this.ap[var1_3] > 135) break;
                    this.aR.a(this.ak[var3_5 + 6].a, this.ak[var3_5 + 6].b, this.ak[var3_5 + 7].a, this.ak[var3_5 + 7].b, var5_1);
                    if (this.ap[var1_3] <= 130) break;
                    break;
                }
                case 30: 
                case 32: 
                case 33: {
                    if (this.ao[var1_3] != 33) {
                        this.aR.a(this.ak[var3_5 + 1].a, this.ak[var3_5 + 1].b, this.ak[var3_5 + 2].a, this.ak[var3_5 + 2].b, var6_2);
                        this.aR.a(this.ak[var3_5 + 1].a, this.ak[var3_5 + 1].b, this.ak[var3_5 + 3].a, this.ak[var3_5 + 3].b, var6_2);
                        this.aR.a(this.ak[var3_5 + 2].a, this.ak[var3_5 + 2].b, this.ak[var3_5 + 4].a, this.ak[var3_5 + 4].b, var6_2);
                        this.aR.a(this.ak[var3_5 + 3].a, this.ak[var3_5 + 3].b, this.ak[var3_5 + 5].a, this.ak[var3_5 + 5].b, var6_2);
                        var7_7 = -2;
                        var8_8 = 2;
                        v6 = 3;
                    } else {
                        this.aR.a(this.ak[var3_5 + 3].a, this.ak[var3_5 + 3].b, this.ak[var3_5 + 5].a, this.ak[var3_5 + 5].b, var6_2);
                        if (this.ap[var1_3] > 140) break;
                        this.aR.a(this.ak[var3_5 + 4].a, this.ak[var3_5 + 4].b, this.ak[var3_5 + 7].a, this.ak[var3_5 + 7].b, var6_2);
                        if (this.ap[var1_3] > 135) break;
                        this.aR.a(this.ak[var3_5 + 6].a, this.ak[var3_5 + 6].b, this.ak[var3_5 + 9].a, this.ak[var3_5 + 9].b, var6_2);
                        if (this.ap[var1_3] > 130) break;
                        this.aR.a(this.ak[var3_5 + 8].a, this.ak[var3_5 + 8].b, this.ak[var3_5 + 10].a, this.ak[var3_5 + 10].b, var6_2);
                        if (this.ap[var1_3] > 125) break;
                        var7_7 = -1;
                        var8_8 = 1;
                        v6 = 1;
                    }
                    var10_10 = v6;
                    v7 = var4_6 = this.v[this.ar[var1_3]][0] == 0 ? var5_1 : this.v[this.ar[var1_3]][0];
                    if (this.aR.j == 13) {
                        var4_6 = -16777216;
                    }
                    var11_11 = -1;
                    while (var11_11 <= var10_10) {
                        var12_12 = var7_7;
                        while (var12_12 <= var8_8) {
                            if (var7_7 + 1 > var12_12 || var12_12 > var8_8 - 1 || 0 > var11_11 || var11_11 > var10_10 - 1) {
                                var13_13 = (int)this.ak[var3_5].a + var12_12;
                                var14_14 = (int)this.ak[var3_5].b + var11_11;
                                if (!(var13_13 < 8 || var13_13 >= 408 || var14_14 < 8 || var14_14 >= 308 || this.as[var1_3] == 1 && var12_12 == var7_7 && var11_11 == -1 || this.as[var1_3] == 1 && var12_12 == var8_8 && var11_11 == -1 || this.as[var1_3] == 1 && var12_12 == var7_7 && var11_11 == var10_10 || this.as[var1_3] == 1 && var12_12 == var8_8 && var11_11 == var10_10)) {
                                    var15_15 = var14_14 * this.aR.a + var13_13;
                                    if (this.aR.ar[var15_15] == var4_6) {
                                        v8 = this.aR.ar;
                                        v9 = var15_15;
                                        v10 = -16777216;
                                    } else {
                                        v8 = this.aR.ar;
                                        v9 = var15_15;
                                        v10 = var4_6;
                                    }
                                    v8[v9] = v10;
                                }
                            }
                            ++var12_12;
                        }
                        ++var11_11;
                    }
                    if (this.aR.j != 11) break;
                    var7_7 = (int)dust.a(this.ak[var3_5].a, 8.0f, 407.0f);
                    var9_9 = (int)dust.a(this.ak[var3_5].b, 8.0f, 304.0f);
                    var11_11 = var9_9 - 4;
                    while (var11_11 <= var9_9 + 4) {
                        var12_12 = var7_7 - 4;
                        while (var12_12 <= var7_7 + 4) {
                            this.aR.P[var11_11 * this.aR.a + var12_12] = 0x1FFFFFFF;
                            var12_12 += 4;
                        }
                        var11_11 += 4;
                    }
                    break;
                }
                case 40: {
                    var4_6 = -7311344;
                    if (this.aR.j == 13) {
                        var4_6 = -16777216;
                    }
                    if (this.am[var3_5] == 10) {
                        this.aR.a(this.ak[var3_5].a, this.ak[var3_5].b, this.ak[var3_5].a, this.ak[var3_5].b + 3.0f, var4_6);
                        this.aR.a(this.ak[var3_5].a, this.ak[var3_5].b, this.ak[var3_5].a + 3.0f, this.ak[var3_5].b, var4_6);
                        this.aR.a(this.ak[var3_5].a, this.ak[var3_5].b + 2.0f, this.ak[var3_5].a + 2.0f, this.ak[var3_5].b + 2.0f, var4_6);
                        break;
                    }
                    if (this.am[var3_5] == 20) {
                        this.aR.c((int)this.ak[var3_5].a, (int)this.ak[var3_5].b, 3, 3, var4_6);
                        break;
                    }
                    if (this.am[var3_5] == 30) {
                        this.aR.a(this.ak[var3_5].a, this.ak[var3_5].b, this.ak[var3_5].a, this.ak[var3_5].b + 3.0f, var4_6);
                        this.aR.a(this.ak[var3_5].a, this.ak[var3_5].b, this.ak[var3_5].a + 2.0f, this.ak[var3_5].b, var4_6);
                        this.aR.a(this.ak[var3_5].a, this.ak[var3_5].b + 2.0f, this.ak[var3_5].a + 2.0f, this.ak[var3_5].b + 2.0f, var4_6);
                        this.aR.a(this.ak[var3_5].a + 3.0f, this.ak[var3_5].b, this.ak[var3_5].a + 3.0f, this.ak[var3_5].b + 2.0f, var4_6);
                        break;
                    }
                    if (this.am[var3_5] == -2) {
                        this.aR.a(this.ak[var3_5].a + 1.0f, this.ak[var3_5].b, this.ak[var3_5].a + 2.0f, this.ak[var3_5].b, var4_6);
                        this.aR.a(this.ak[var3_5].a, this.ak[var3_5].b + 1.0f, this.ak[var3_5].a, this.ak[var3_5].b + 2.0f, var4_6);
                        this.aR.a(this.ak[var3_5].a + 3.0f, this.ak[var3_5].b + 1.0f, this.ak[var3_5].a + 3.0f, this.ak[var3_5].b + 2.0f, var4_6);
                        this.aR.a(this.ak[var3_5].a + 1.0f, this.ak[var3_5].b + 3.0f, this.ak[var3_5].a + 2.0f, this.ak[var3_5].b + 3.0f, var4_6);
                        break;
                    }
                    v0 = this.aR;
                    v1 = (int)this.ak[var3_5].a;
                    v2 = (int)this.ak[var3_5].b;
                    v3 = 4;
                    v4 = 4;
                    v5 = var4_6;
lbl148:
                    // 3 sources

                    v0.b(v1, v2, v3, v4, v5);
                }
            }
            switch (this.ao[var1_3]) {
                case 10: 
                case 11: 
                case 12: 
                case 13: 
                case 30: 
                case 32: 
                case 33: {
                    if (this.aR.j != 12) break;
                    var2_4 = 0;
                    while (var2_4 < 6) {
                        var7_7 = (int)dust.a(this.ak[var3_5 + var2_4].a, 8.0f, 407.0f);
                        var8_8 = (int)dust.a(this.ak[var3_5 + var2_4].b, 8.0f, 304.0f);
                        this.aR.P[var8_8 * this.aR.a + var7_7] = 3000;
                        ++var2_4;
                    }
                    break;
                }
            }
            ++var1_3;
        }
    }

    private void x() {
        this.aH = 50;
        this.aB = new e[this.aH];
        this.aC = new e[this.aH];
        this.aD = new int[this.aH];
        this.aE = new int[this.aH];
        this.aF = new int[this.aH];
        this.aG = new int[this.aH];
        int n = 0;
        while (n < this.aH) {
            this.aB[n] = new e(this.aR, 0.0f, 0.0f);
            ++n;
        }
        n = 0;
        while (n < this.aH) {
            this.aC[n] = new e(this.aR, 0.0f, 0.0f);
            ++n;
        }
        n = 0;
        while (n < this.aH) {
            this.aD[n] = 0;
            ++n;
        }
        n = 0;
        while (n < this.aH) {
            this.aE[n] = 0;
            ++n;
        }
        n = 0;
        while (n < this.aH) {
            this.aF[n] = 0;
            ++n;
        }
        n = 0;
        while (n < this.aH) {
            this.aG[n] = 0;
            ++n;
        }
    }

    private void b(int n, int n2, int n3) {
        int n4 = 0;
        while (n4 < this.aH) {
            if (this.aD[n4] == 0) {
                this.aB[n4].a((float)n + 0.5f, (float)n2 + 0.5f);
                this.aC[n4].a(0.0f, 0.0f);
                this.aD[n4] = 1;
                this.aE[n4] = 0;
                this.aF[n4] = 0;
                this.aG[n4] = n3;
                return;
            }
            ++n4;
        }
    }

    private void g(int n) {
        e e2 = new e(this.aR);
        if (this.aF[n] == 0) {
            if (this.aR.c == 42 && this.aR.aH || this.aR.d == 42 && this.aR.aL) {
                e2.a = (float)this.m - this.aB[n].a;
                e2.b = (float)this.n - this.aB[n].b;
                if (e2.a() < 20.0f) {
                    this.aF[n] = 1;
                    return;
                }
            }
        } else {
            if (this.aR.c == 42 && this.aR.aJ || this.aR.d == 42 && this.aR.aN) {
                this.aC[n].a += ((float)this.m - this.aB[n].a) * 0.05f;
                this.aC[n].b += ((float)this.n - this.aB[n].b) * 0.05f;
                this.aC[n].a(0.9f);
                return;
            }
            this.aC[n].a(0.3f);
            this.aF[n] = 0;
        }
    }

    private void y() {
        e e2 = new e(this.aR, 0.0f, 0.0f);
        int n = 0;
        while (n < this.aH) {
            block182: {
                int n2;
                int n3;
                int n4;
                int n5;
                int n6;
                int n7;
                int n8;
                int n9;
                int n10;
                int n11;
                int[] nArray;
                int n12;
                float f;
                int n13;
                int n14;
                e e3;
                int n15;
                int n16;
                block199: {
                    int n17;
                    int n18;
                    int n19;
                    int n20;
                    d d2;
                    block201: {
                        block200: {
                            block193: {
                                float f2;
                                float f3;
                                float f4;
                                int n21;
                                int n22;
                                int n23;
                                int n24;
                                int n25;
                                d d3;
                                block192: {
                                    block195: {
                                        block198: {
                                            block197: {
                                                block196: {
                                                    block194: {
                                                        block190: {
                                                            block191: {
                                                                float f5;
                                                                float f6;
                                                                int n26;
                                                                int n27;
                                                                block183: {
                                                                    if (this.aD[n] == 0) break block182;
                                                                    if (this.aQ[this.aG[n]] != 0) break block183;
                                                                    this.aD[n] = 0;
                                                                    break block182;
                                                                }
                                                                n16 = (int)this.aB[n].b * this.aR.a + (int)this.aB[n].a;
                                                                n15 = 0;
                                                                while (n15 < 21) {
                                                                    if (this.F[n16 + this.aJ[n15]] == -2) {
                                                                        this.F[n16 + this.aJ[n15]] = -5;
                                                                    }
                                                                    ++n15;
                                                                }
                                                                float f7 = this.aO[this.aG[n]];
                                                                this.aC[n].b += f7;
                                                                float f8 = this.aP[this.aG[n]];
                                                                if (f8 != 0.0f) {
                                                                    n27 = ((int)this.aB[n].b >> 2) * this.a + ((int)this.aB[n].a >> 2);
                                                                    this.aC[n].a += this.e[n27].a * f8;
                                                                    this.aC[n].b += this.e[n27].b * f8;
                                                                    if (this.e[n27].a() > 0.3f) {
                                                                        this.aC[n].a(0.9f + (1.0f - f8) / 10.0f);
                                                                    }
                                                                }
                                                                this.g(n);
                                                                n27 = 0;
                                                                while (n27 < this.at) {
                                                                    if (this.ao[n27] == 10 || this.ao[n27] == 11 || this.ao[n27] == 30) {
                                                                        int n28 = n27 * this.av;
                                                                        n26 = 4;
                                                                        while (n26 <= 5) {
                                                                            f6 = dust.e(this.ak[n28 + n26].a - this.aB[n].a);
                                                                            f5 = dust.e(this.ak[n28 + n26].b - this.aB[n].b);
                                                                            if (f6 <= 9.0f && f5 <= 9.0f) {
                                                                                this.aC[n].a += (this.ak[n28 + n26].a - this.al[n28 + n26].a) * 0.1f;
                                                                                this.aC[n].b += (this.ak[n28 + n26].b - this.al[n28 + n26].b) * 0.2f;
                                                                            }
                                                                            ++n26;
                                                                        }
                                                                    }
                                                                    ++n27;
                                                                }
                                                                e3 = new e(this.aR, this.aC[n]);
                                                                this.aI = 0;
                                                                n26 = (int)(this.aC[n].c() / 2.0f) + 1;
                                                                f6 = 1.0f / (float)n26;
                                                                int n29 = 0;
                                                                e e4 = new e(this.aR, 0.0f, 0.0f);
                                                                n14 = 0;
                                                                int n30 = 0;
                                                                while (n30 < n26) {
                                                                    float f9;
                                                                    e e5;
                                                                    float f10;
                                                                    block184: {
                                                                        d d4;
                                                                        block189: {
                                                                            float f11;
                                                                            float f12;
                                                                            e e6;
                                                                            block188: {
                                                                                float f13;
                                                                                float f14;
                                                                                e e7;
                                                                                block187: {
                                                                                    d d5;
                                                                                    block186: {
                                                                                        float f15;
                                                                                        float f16;
                                                                                        e e8;
                                                                                        block185: {
                                                                                            float f17;
                                                                                            float f18;
                                                                                            e e9;
                                                                                            f5 = this.aB[n].a + this.aC[n].a * f6;
                                                                                            f10 = this.aB[n].b + this.aC[n].b * f6;
                                                                                            if (f5 < 4.0f || (float)(this.aR.a - 4) <= f5 || f10 < 4.0f || f10 >= 312.0f) {
                                                                                                this.aD[n] = 0;
                                                                                                break;
                                                                                            }
                                                                                            if (this.aR.y != 1) break block184;
                                                                                            if (!(f5 < 8.0f)) break block185;
                                                                                            if (this.F[(int)f10 * this.aR.a + (int)(f5 + 400.0f)] <= -4) {
                                                                                                this.aB[n].a += 400.0f;
                                                                                                e e10 = this.aC[n];
                                                                                                e9 = e10;
                                                                                                f18 = e10.a;
                                                                                                f17 = 0.8f;
                                                                                            } else {
                                                                                                e e11 = this.aC[n];
                                                                                                e9 = e11;
                                                                                                f18 = e11.a;
                                                                                                f17 = -0.8f;
                                                                                            }
                                                                                            e9.a = f18 * f17;
                                                                                            d5 = this;
                                                                                            break block186;
                                                                                        }
                                                                                        if (!(f5 >= 408.0f)) break block187;
                                                                                        if (this.F[(int)f10 * this.aR.a + (int)(f5 - 400.0f)] <= -4) {
                                                                                            this.aB[n].a -= 400.0f;
                                                                                            e e12 = this.aC[n];
                                                                                            e8 = e12;
                                                                                            f16 = e12.a;
                                                                                            f15 = 0.8f;
                                                                                        } else {
                                                                                            e e13 = this.aC[n];
                                                                                            e8 = e13;
                                                                                            f16 = e13.a;
                                                                                            f15 = -0.8f;
                                                                                        }
                                                                                        e8.a = f16 * f15;
                                                                                        d5 = this;
                                                                                    }
                                                                                    f5 = d5.aB[n].a + this.aC[n].a * f6;
                                                                                }
                                                                                if (!(f10 < 8.0f)) break block188;
                                                                                if (this.F[(int)(f10 + 300.0f) * this.aR.a + (int)f5] <= -4) {
                                                                                    this.aB[n].b += 300.0f;
                                                                                    e e14 = this.aC[n];
                                                                                    e7 = e14;
                                                                                    f14 = e14.b;
                                                                                    f13 = 0.8f;
                                                                                } else {
                                                                                    e e15 = this.aC[n];
                                                                                    e7 = e15;
                                                                                    f14 = e15.b;
                                                                                    f13 = -0.8f;
                                                                                }
                                                                                e7.b = f14 * f13;
                                                                                d4 = this;
                                                                                break block189;
                                                                            }
                                                                            if (!(f10 >= 308.0f)) break block184;
                                                                            if (this.F[(int)(f10 - 300.0f) * this.aR.a + (int)f5] <= -4) {
                                                                                this.aB[n].b -= 300.0f;
                                                                                e e16 = this.aC[n];
                                                                                e6 = e16;
                                                                                f12 = e16.b;
                                                                                f11 = 0.5f;
                                                                            } else {
                                                                                e e17 = this.aC[n];
                                                                                e6 = e17;
                                                                                f12 = e17.b;
                                                                                f11 = -0.8f;
                                                                            }
                                                                            e6.b = f12 * f11;
                                                                            d4 = this;
                                                                        }
                                                                        f10 = d4.aB[n].b + this.aC[n].b * f6;
                                                                    }
                                                                    n16 = (int)f10 * this.aR.a + (int)f5;
                                                                    n29 = 0;
                                                                    e4.a(0.0f, 0.0f);
                                                                    n15 = 0;
                                                                    while (n15 < 37) {
                                                                        n13 = this.F[n16 + this.aJ[n15]];
                                                                        if (n13 > -4) {
                                                                            n14 = n13;
                                                                            if (n13 < 0 || this.c(n, n14 = this.A[n13], n13) != 1) {
                                                                                e4.a -= this.aK[n15];
                                                                                e4.b -= this.aL[n15];
                                                                                ++n29;
                                                                            }
                                                                        }
                                                                        ++n15;
                                                                    }
                                                                    if (n29 == 0) {
                                                                        this.aB[n].a = f5;
                                                                        e5 = this.aB[n];
                                                                        f9 = f10;
                                                                    } else {
                                                                        e4.e();
                                                                        this.aC[n].b -= f7;
                                                                        f = this.aC[n].c() * 0.999f;
                                                                        float f19 = e4.d(this.aC[n]);
                                                                        e4.a(-f19);
                                                                        this.aC[n].b(e4);
                                                                        this.aC[n].a(0.999f);
                                                                        e4.a(0.1f);
                                                                        this.aC[n].b(e4);
                                                                        this.aC[n].e();
                                                                        this.aC[n].a(f);
                                                                        this.aB[n].a += this.aC[n].a * f6;
                                                                        this.aB[n].b += this.aC[n].b * f6;
                                                                        e e18 = this.aC[n];
                                                                        e5 = e18;
                                                                        f9 = e18.b + f7;
                                                                    }
                                                                    e5.b = f9;
                                                                    n16 = (int)this.aB[n].b * this.aR.a + (int)this.aB[n].a;
                                                                    n29 = 0;
                                                                    e4.a(0.0f, 0.0f);
                                                                    n15 = 0;
                                                                    while (n15 < 21) {
                                                                        n13 = this.F[n16 + this.aJ[n15]];
                                                                        if (!(n13 <= -4 || n13 >= 0 && (this.P[this.A[n13]] == 2 && this.P[this.aG[n]] == 2 && this.aG[n] != this.A[n13] || this.P[this.A[n13]] == 2 && this.P[this.aG[n]] != 2 || this.P[this.A[n13]] == 5 && this.P[this.aG[n]] != 5 || this.A[n13] == 33 && this.P[this.aG[n]] == 2 || this.A[n13] == 4 || this.A[n13] == 28 && this.aG[n] == 28))) {
                                                                            e4.a -= this.aK[n15];
                                                                            e4.b -= this.aL[n15];
                                                                            ++n29;
                                                                        }
                                                                        ++n15;
                                                                    }
                                                                    if (n29 != 0) {
                                                                        e4.e();
                                                                        this.aB[n].b(e4);
                                                                    }
                                                                    ++n30;
                                                                }
                                                                if (this.aB[n].a < 4.0f || (float)(this.aR.a - 4) <= this.aB[n].a || this.aB[n].b < 4.0f || this.aB[n].b >= 312.0f) {
                                                                    this.aD[n] = 0;
                                                                    return;
                                                                }
                                                                n16 = (int)this.aB[n].b * this.aR.a + (int)this.aB[n].a;
                                                                if (this.aG[n] != 2 || n14 < 0) break block190;
                                                                if (this.P[n14] != 2) break block191;
                                                                d3 = this;
                                                                n25 = n;
                                                                n24 = n16;
                                                                n23 = 0;
                                                                n22 = 2;
                                                                n21 = 0;
                                                                f4 = this.aC[n].a * 0.5f;
                                                                f3 = this.aC[n].b * 0.5f;
                                                                f2 = 0.5f;
                                                                break block192;
                                                            }
                                                            if (this.P[n14] != 3) break block193;
                                                            d3 = this;
                                                            n25 = n;
                                                            n24 = n16;
                                                            n23 = 0;
                                                            n22 = 4;
                                                            n21 = 0;
                                                            f4 = this.aC[n].a * 0.5f;
                                                            f3 = this.aC[n].b * 0.5f;
                                                            f2 = 0.5f;
                                                            break block192;
                                                        }
                                                        if (this.aG[n] != 3) break block194;
                                                        if (n14 != 20 && n14 != 28 && n14 != 34) break block193;
                                                        d3 = this;
                                                        n25 = n;
                                                        n24 = n16;
                                                        n23 = 0;
                                                        n22 = 3;
                                                        break block195;
                                                    }
                                                    if (this.aG[n] != 10) break block196;
                                                    f = e3.c();
                                                    if (n14 != 28 && n14 != 34 && (n14 != -1 && n14 != -3 && n14 != 19 && n14 != 29 && n14 != 31 || !(f > 5.0f))) break block193;
                                                    d3 = this;
                                                    n25 = n;
                                                    n24 = n16;
                                                    n23 = 0;
                                                    n22 = 11;
                                                    n21 = 0;
                                                    f4 = e3.a;
                                                    f3 = e3.b;
                                                    f2 = f;
                                                    break block192;
                                                }
                                                if (this.aG[n] != 37) break block197;
                                                if (n14 != 28 && n14 != 34) break block193;
                                                d3 = this;
                                                n25 = n;
                                                n24 = n16;
                                                n23 = 0;
                                                n22 = 37;
                                                break block195;
                                            }
                                            if (this.aG[n] != 36) break block198;
                                            if (n14 != 20 && n14 != 28 && n14 != 34) break block193;
                                            d3 = this;
                                            n25 = n;
                                            n24 = n16;
                                            n23 = 0;
                                            n22 = 36;
                                            break block195;
                                        }
                                        if (this.aG[n] != 4 || n14 != 3 && n14 != 27 && n14 != 37 && n14 != 34) break block193;
                                        d3 = this;
                                        n25 = n;
                                        n24 = n16;
                                        n23 = 0;
                                        n22 = 4;
                                    }
                                    n21 = 0;
                                    f4 = 0.0f;
                                    f3 = 0.0f;
                                    f2 = 0.0f;
                                }
                                d3.a(n25, n24, n23, n22, n21, f4, f3, f2);
                            }
                            if (this.aG[n] != 5 || n14 < 0) break block199;
                            if (n14 != 34) break block200;
                            d2 = this;
                            n20 = n;
                            n19 = n16;
                            n18 = 0;
                            n17 = 5;
                            break block201;
                        }
                        if (n14 == 42 || this.P[n14] != 3) break block199;
                        d2 = this;
                        n20 = n;
                        n19 = n16;
                        n18 = 0;
                        n17 = 4;
                    }
                    d2.a(n20, n19, n18, n17, 0, this.aC[n].a * 0.5f, this.aC[n].b * 0.5f, 0.5f);
                }
                if (this.aG[n] == 6 && n14 >= 0) {
                    if (n14 == 25) {
                        this.a(n, n16, 0, 25, 0, 0.0f, 0.0f, 0.0f);
                    } else if (n14 == 34) {
                        this.a(n, n16, 0, 2, 0, 0.0f, 0.0f, 0.0f);
                    } else if (n14 == 28) {
                        this.a(n, n16, 0, 2, 0, 0.0f, 0.0f, 1.0f);
                    } else if (n14 != 42) {
                        if (this.P[n14] == 3 && this.aE[n] == 1) {
                            this.a(n, n16, 0, 6, 1, 0.0f, 0.0f, 0.0f);
                        } else if (this.P[n14] == 3) {
                            this.a(n, n16, 0, 4, 0, 0.0f, 0.0f, 0.0f);
                        }
                    }
                } else if (this.aG[n] == 7 && n14 >= 0) {
                    if (this.P[n14] == 3 && this.aE[n] == 0) {
                        n15 = 0;
                        while (n15 < 37) {
                            n12 = this.F[n16 + this.aJ[n15]];
                            if (n12 <= -4 && (n13 = this.a((float)((int)this.aB[n].a + this.aM[n15]), (float)((int)this.aB[n].b + this.aN[n15]), 4)) > 0) {
                                float f20 = this.aR.d(20.0f);
                                this.z[n13].a += this.aC[n].a * f20 + this.aK[n15] * f20 / 2.0f;
                                this.z[n13].b += this.aC[n].b * f20 + this.aL[n15] * f20 / 2.0f;
                                this.B[n13] = 2;
                            }
                            ++n15;
                        }
                        nArray = this.aD;
                        n11 = n;
                        n10 = 0;
                    } else if (n14 == 34) {
                        this.a(n, n16, 0, 7, 0, 0.0f, 0.0f, 0.0f);
                    }
                } else if (this.aG[n] == 16 && n14 >= 0) {
                    if (this.P[n14] == 3) {
                        n15 = 9;
                        while (n15 < 21) {
                            n12 = this.F[n16 + this.aJ[n15]];
                            if (n12 <= -4 && this.aR.d(100.0f) < 50.0f) {
                                this.a((float)((int)this.aB[n].a + this.aM[n15]), (float)((int)this.aB[n].b + this.aN[n15]), 4);
                            }
                            ++n15;
                        }
                        if (this.aR.d(100.0f) < 1.0f) {
                            this.a(n, n16, 0, 16, 0, 0.0f, 0.0f, 0.0f);
                        }
                    } else if (n14 == 34) {
                        this.a(n, n16, 0, 16, 0, 0.0f, 0.0f, 0.0f);
                    }
                } else if (this.aG[n] == 27) {
                    if (n14 == 20 || n14 == 28 || n14 == 34) {
                        this.a(n, n16, 0, 27, 0, 0.0f, 0.0f, 0.0f);
                    }
                } else if (this.aG[n] == 8 && n14 > 0) {
                    int n31 = n16 = ((int)this.aB[n].b >> 2) * this.a + ((int)this.aB[n].a >> 2);
                    this.g[n31] = this.g[n31] + 10.0f;
                    this.i -= 10.0f;
                } else if (this.aG[n] == 14) {
                    if (this.aE[n] == 0 && n14 > 0) {
                        nArray = this.aE;
                        n11 = n;
                        n10 = n14;
                    } else if (this.aE[n] != 0 && this.aR.h[this.aR.g] - this.D >= 1000) {
                        n12 = (int)this.aB[n].a;
                        int n32 = (int)this.aB[n].b;
                        if (this.P[this.aE[n]] == 1 || this.aE[n] == 20 || this.aE[n] == 42) {
                            n32 += 4;
                        }
                        if (this.F[n9 = n32 * this.aR.a + n12] <= -4) {
                            this.a((float)n12, (float)n32, this.aE[n]);
                        }
                    }
                } else if ((this.aG[n] == 17 || this.aG[n] == 23) && n14 >= 0) {
                    if (this.P[n14] == 3) {
                        n12 = 0;
                        int n33 = (int)this.aB[n].a & 0xFFFC;
                        n9 = (int)this.aB[n].b & 0xFFFC;
                        n8 = dust.b(n33 - 10, this.c);
                        n7 = dust.b(n9 - 10, this.c);
                        n6 = dust.c(n33 + 10, this.aR.a - this.c - 1);
                        n5 = dust.c(n9 + 10, (this.b - 1) * this.c - 1);
                        n4 = n7;
                        while (n4 <= n5) {
                            n3 = n8;
                            while (n3 <= n6) {
                                if ((n3 - n33) * (n3 - n33) + (n4 - n9) * (n4 - n9) <= 100) {
                                    n2 = n4 * this.aR.a + n3;
                                    if (this.F[n2] >= 0) {
                                        this.z[this.F[n2]].a += (float)((n3 - n33) * 10);
                                        this.z[this.F[n2]].b += (float)((n4 - n9) * 10);
                                    }
                                    if (this.F[n2] <= -4 && this.aG[n] == 23) {
                                        this.a((float)n3, (float)n4, 4);
                                    }
                                    if ((n4 & 3) + (n3 & 3) == 0 && this.l[n2 = (n4 >> 2) * this.a + (n3 >> 2)] <= 0) {
                                        if (dust.c(n3 - n33) >= 1) {
                                            this.e[n2].a += (float)(100 / (n3 - n33));
                                        }
                                        if (dust.c(n4 - n9) >= 1) {
                                            this.e[n2].b += (float)(100 / (n4 - n9));
                                        }
                                    }
                                }
                                ++n3;
                            }
                            ++n4;
                        }
                        nArray = this.aD;
                        n11 = n;
                        n10 = 0;
                    } else if (n14 == 34) {
                        this.a(n, n16, 0, this.aG[n], 0, 0.0f, 0.0f, 0.0f);
                    }
                } else if (this.aG[n] == 26 && n14 >= 0) {
                    if (this.P[n14] == 3) {
                        this.a(n, n16, 0, this.aG[n], 0, 0.0f, 0.0f, 1.0f);
                        if (this.aE[n] < 2) {
                            int n34 = n;
                            this.aE[n34] = this.aE[n34] + 1;
                            nArray = this.aD;
                            n11 = n;
                            n10 = 1;
                        }
                    } else if (n14 == 34) {
                        this.a(n, n16, 0, this.aG[n], 0, 0.0f, 0.0f, 0.0f);
                    }
                } else if (this.aG[n] == 12 && n14 >= 0) {
                    if (this.P[n14] > 0) {
                        this.a(n, n16, 0, n14, 0, this.aC[n].a * 0.5f, this.aC[n].b * 0.5f, 0.5f);
                    }
                } else if (this.aG[n] == 31 && n14 >= 0) {
                    if (n14 != 31 && n14 != 4 && n14 != 26 && n14 != 33 && this.P[n14] > 0) {
                        n12 = 0;
                        int n35 = (int)this.aB[n].a;
                        n9 = (int)this.aB[n].b;
                        n8 = dust.b(n35 - 10, this.c);
                        n7 = dust.b(n9 - 10, this.c);
                        n6 = dust.c(n35 + 10, this.aR.a - this.c - 1);
                        n5 = dust.c(n9 + 10, (this.b - 1) * this.c - 1);
                        e2.a(0.0f, 0.0f);
                        n4 = n7;
                        while (n4 <= n5) {
                            n3 = n8;
                            while (n3 <= n6) {
                                if ((n3 - n35) * (n3 - n35) + (n4 - n9) * (n4 - n9) <= 100 && this.F[n2 = n4 * this.aR.a + n3] >= 0) {
                                    e2.a += this.aB[n].a - (float)n3;
                                    e2.b += this.aB[n].b - (float)n4;
                                }
                                ++n3;
                            }
                            ++n4;
                        }
                        e2.d();
                        n3 = n7;
                        while (n3 <= n5) {
                            n2 = n8;
                            while (n2 <= n6) {
                                int n36;
                                if ((n2 - n35) * (n2 - n35) + (n3 - n9) * (n3 - n9) <= 100 && this.F[n36 = n3 * this.aR.a + n2] >= 0) {
                                    this.B[this.F[n36]] = this.A[this.F[n36]];
                                    this.A[this.F[n36]] = 31;
                                    this.C[this.F[n36]] = 0;
                                    this.z[this.F[n36]].a += e2.a * 0.5f + (float)(n35 - n2) * 0.5f;
                                    this.z[this.F[n36]].b += e2.b * 0.5f + (float)(n9 - n3) * 0.5f;
                                }
                                ++n2;
                            }
                            ++n3;
                        }
                        nArray = this.aD;
                        n11 = n;
                        n10 = 0;
                    }
                } else if (this.aG[n] == 39 && n14 >= 0) {
                    if (this.P[n14] == 3) {
                        this.a(n, n16, 0, 4, 0, this.aC[n].a * 0.5f, this.aC[n].b * 0.5f, 0.5f);
                    } else if (n14 == 34) {
                        this.a(n, n16, 0, 39, 0, 0.0f, 0.0f, 0.0f);
                    }
                } else if (this.aG[n] == 19) {
                    f = e3.c();
                    if ((n14 == -1 || n14 == 29 || n14 == 31) && f > 7.0f) {
                        nArray = this.aG;
                        n11 = n;
                        n10 = 2;
                    } else if (n14 == 34) {
                        this.a(n, n16, 0, 19, 0, 0.0f, 0.0f, 0.0f);
                    }
                } else if (this.aG[n] == 29) {
                    if (n14 == 37) {
                        this.a(n, n16, 1, 2, 0, 0.0f, 0.0f, 0.0f);
                    } else if (n14 == 28) {
                        this.a(n, n16, 2, 29, 0, 0.0f, 0.0f, 0.0f);
                    } else if (n14 == 33) {
                        this.a(n, n16, 1, 29, 0, 0.0f, 0.0f, 0.0f);
                    } else if (n14 == 34) {
                        this.a(n, n16, 0, 29, 0, 0.0f, 0.0f, 0.0f);
                    }
                } else if (this.aG[n] == 38) {
                    f = e3.c();
                    if ((n14 == -1 || n14 == -3 || n14 == 19 || n14 == 29 || n14 == 31) && f > 5.0f) {
                        this.a(n, n16, 0, 19, 0, 0.0f, 0.0f, f * 0.1f);
                    } else if (n14 == 28) {
                        this.a(n, n16, 1, 38, 0, 0.0f, 0.0f, 0.0f);
                    } else if (n14 == 33) {
                        this.a(n, n16, 2, 38, 0, 0.0f, 0.0f, 0.0f);
                    } else if (n14 == 34) {
                        this.a(n, n16, 0, 38, 0, 0.0f, 0.0f, 0.0f);
                    }
                } else if (this.aG[n] == 25) {
                    if (n14 == 3) {
                        this.a(n, n16, 0, 25, 0, 0.0f, 0.0f, 0.0f);
                    } else if (n14 == 27) {
                        this.a(n, n16, 0, 25, 0, 0.0f, 0.0f, 0.0f);
                    } else if (n14 == 37) {
                        this.a(n, n16, 0, 25, 0, 0.0f, 0.0f, 0.0f);
                    } else if (n14 == 28) {
                        this.a(n, n16, 0, 4, 0, 0.0f, 0.0f, 0.0f);
                    } else if (n14 == 34) {
                        this.a(n, n16, 0, 25, 0, 0.0f, 0.0f, 0.0f);
                    }
                } else if (this.aG[n] == 43 && n14 >= 0) {
                    if (this.P[n14] == 3) {
                        if (this.aE[n] == 16) {
                            this.a(n, n16, 2, 4, 0, 0.0f, 0.0f, 0.0f);
                        } else if (this.aE[n] == 23) {
                            this.a(n, n16, 0, 23, 0, 0.0f, 0.0f, 1.0f);
                        } else if (this.aE[n] == 27) {
                            this.a(n, n16, 0, 12, 0, 0.0f, 0.0f, 1.0f);
                        } else {
                            this.a(n, n16, 0, 42, 0, 0.0f, 0.0f, 0.0f);
                        }
                    } else if (n14 == 3) {
                        this.a(n, n16, 0, 7, 0, 0.0f, 0.0f, 0.0f);
                    } else if (n14 == 37) {
                        this.a(n, n16, 0, 7, 0, 0.0f, 0.0f, 0.0f);
                    } else if (n14 == 34) {
                        this.a(n, n16, 0, 43, 0, 0.0f, 0.0f, 0.0f);
                    }
                } else if (this.aG[n] == 44) {
                    if (n14 == 34) {
                        this.a(n, n16, 0, 44, 0, 0.0f, 0.0f, 0.0f);
                    }
                } else if (this.aG[n] == 45 && this.aE[n] != 0 && this.aR.h[this.aR.g] - this.D >= 1000) {
                    e2.a(this.aC[n]);
                    e2.d();
                    e2.a(4.0f);
                    n12 = (int)(this.aB[n].a - e2.a);
                    int n37 = (int)(this.aB[n].b - e2.b);
                    n9 = n37 * this.aR.a + n12;
                    if (this.F[n9] <= -4) {
                        n8 = this.aE[n] & 0xFF;
                        n7 = this.aE[n] >> 8;
                        if (n7 > 0) {
                            this.a((float)n12, (float)n37, n8);
                            nArray = this.aE;
                            n11 = n;
                            n10 = nArray[n11] = n7 - 1 << 8 | n8;
                        }
                    }
                }
                if (this.aI != 0) {
                    this.aG[n] = this.aI;
                    this.aE[n] = 0;
                }
                if (this.aD[n] != 0) {
                    n16 = (int)this.aB[n].b * this.aR.a + (int)this.aB[n].a;
                    n15 = 0;
                    while (n15 < 21) {
                        if (this.F[n16 + this.aJ[n15]] <= -4) {
                            this.F[n16 + this.aJ[n15]] = -2;
                        }
                        ++n15;
                    }
                }
            }
            ++n;
        }
    }

    private int c(int n, int n2, int n3) {
        block344: {
            block362: {
                block368: {
                    block366: {
                        int n4;
                        int[] nArray;
                        block364: {
                            d d2;
                            block367: {
                                block365: {
                                    block363: {
                                        block361: {
                                            block360: {
                                                block359: {
                                                    block358: {
                                                        block357: {
                                                            block356: {
                                                                block355: {
                                                                    block354: {
                                                                        block353: {
                                                                            block352: {
                                                                                block351: {
                                                                                    block350: {
                                                                                        block349: {
                                                                                            block348: {
                                                                                                block347: {
                                                                                                    block346: {
                                                                                                        block345: {
                                                                                                            if (this.aG[n] == 2) break block344;
                                                                                                            if (this.aG[n] != 3) break block345;
                                                                                                            if (n2 == 4) {
                                                                                                                this.c(n3);
                                                                                                                return 1;
                                                                                                            }
                                                                                                            if (n2 == 6) {
                                                                                                                this.A[n3] = 5;
                                                                                                                this.B[n3] = 0;
                                                                                                            } else if (n2 == 10) {
                                                                                                                this.aI = 10;
                                                                                                            } else if (n2 == 11) {
                                                                                                                int n5 = n;
                                                                                                                this.aE[n5] = this.aE[n5] + 1;
                                                                                                                if (this.aE[n5] >= 20) {
                                                                                                                    this.aI = 10;
                                                                                                                }
                                                                                                            } else {
                                                                                                                if (n2 == 20) {
                                                                                                                    return 1;
                                                                                                                }
                                                                                                                if (n2 == 25) {
                                                                                                                    this.c(n3);
                                                                                                                } else {
                                                                                                                    if (n2 == 28) {
                                                                                                                        return 1;
                                                                                                                    }
                                                                                                                    if (n2 == 29) {
                                                                                                                        if (this.aR.d(100.0f) < 10.0f) {
                                                                                                                            this.A[n3] = 2;
                                                                                                                            this.B[n3] = 0;
                                                                                                                        }
                                                                                                                    } else {
                                                                                                                        if (n2 == 33) {
                                                                                                                            return 1;
                                                                                                                        }
                                                                                                                        if (n2 == 36) {
                                                                                                                            int n6 = n;
                                                                                                                            this.aE[n6] = this.aE[n6] + 1;
                                                                                                                            if (this.aE[n6] >= 20) {
                                                                                                                                this.aI = 37;
                                                                                                                            }
                                                                                                                            this.c(n3);
                                                                                                                        } else if (n2 == 43) {
                                                                                                                            this.A[n3] = 7;
                                                                                                                            this.B[n3] = 0;
                                                                                                                        }
                                                                                                                    }
                                                                                                                }
                                                                                                            }
                                                                                                            break block344;
                                                                                                        }
                                                                                                        if (this.aG[n] != 10) break block346;
                                                                                                        if (n2 == 3) {
                                                                                                            this.A[n3] = 10;
                                                                                                            this.B[n3] = 0;
                                                                                                        } else if (n2 == 4) {
                                                                                                            int n7 = n;
                                                                                                            this.aE[n7] = this.aE[n7] + 1;
                                                                                                            if (this.aE[n7] >= 20) {
                                                                                                                this.aI = 3;
                                                                                                            }
                                                                                                        } else if (n2 == 10) {
                                                                                                            this.aE[n] = 0;
                                                                                                        } else if (n2 == 11) {
                                                                                                            this.aE[n] = 0;
                                                                                                        } else if (n2 == 20) {
                                                                                                            this.aI = 3;
                                                                                                        } else if (n2 == 25) {
                                                                                                            int n8 = n;
                                                                                                            this.aE[n8] = this.aE[n8] + 1;
                                                                                                            if (this.aE[n8] >= 20) {
                                                                                                                this.aI = 3;
                                                                                                            }
                                                                                                        } else {
                                                                                                            if (n2 == 28) {
                                                                                                                return 1;
                                                                                                            }
                                                                                                            if (n2 == 33) {
                                                                                                                int n9 = n;
                                                                                                                this.aE[n9] = this.aE[n9] + 1;
                                                                                                                if (this.aE[n9] >= 20) {
                                                                                                                    this.aI = 3;
                                                                                                                }
                                                                                                            } else if (n2 == 42) {
                                                                                                                int n10 = n;
                                                                                                                this.aE[n10] = this.aE[n10] + 1;
                                                                                                                if (this.aE[n10] >= 20) {
                                                                                                                    this.aI = 3;
                                                                                                                }
                                                                                                            }
                                                                                                        }
                                                                                                        break block344;
                                                                                                    }
                                                                                                    if (this.aG[n] != 37) break block347;
                                                                                                    if (n2 == 3) {
                                                                                                        this.aE[n] = 0;
                                                                                                    } else {
                                                                                                        if (n2 == 4) {
                                                                                                            int n11 = n;
                                                                                                            this.aE[n11] = this.aE[n11] + 1;
                                                                                                            if (this.aE[n11] >= 20) {
                                                                                                                this.aI = 36;
                                                                                                            }
                                                                                                            this.c(n3);
                                                                                                            return 1;
                                                                                                        }
                                                                                                        if (n2 == 5) {
                                                                                                            this.A[n3] = 2;
                                                                                                            this.B[n3] = 0;
                                                                                                        } else if (n2 == 6) {
                                                                                                            this.A[n3] = 2;
                                                                                                            this.B[n3] = 0;
                                                                                                        } else if (n2 == 10) {
                                                                                                            this.aI = 10;
                                                                                                        } else if (n2 == 11) {
                                                                                                            int n12 = n;
                                                                                                            this.aE[n12] = this.aE[n12] + 1;
                                                                                                            if (this.aE[n12] >= 20) {
                                                                                                                this.aI = 10;
                                                                                                            }
                                                                                                        } else if (n2 == 20) {
                                                                                                            this.aI = 36;
                                                                                                        } else if (n2 == 25) {
                                                                                                            int n13 = n;
                                                                                                            this.aE[n13] = this.aE[n13] + 1;
                                                                                                            if (this.aE[n13] >= 20) {
                                                                                                                this.aI = 36;
                                                                                                            }
                                                                                                            this.c(n3);
                                                                                                        } else {
                                                                                                            if (n2 == 28) {
                                                                                                                return 1;
                                                                                                            }
                                                                                                            if (n2 == 29) {
                                                                                                                this.A[n3] = 2;
                                                                                                                this.B[n3] = 0;
                                                                                                            } else {
                                                                                                                if (n2 == 33) {
                                                                                                                    int n14 = n;
                                                                                                                    this.aE[n14] = this.aE[n14] + 1;
                                                                                                                    if (this.aE[n14] >= 20) {
                                                                                                                        this.aI = 36;
                                                                                                                    }
                                                                                                                    return 1;
                                                                                                                }
                                                                                                                if (n2 == 35) {
                                                                                                                    this.A[n3] = 2;
                                                                                                                    this.B[n3] = 0;
                                                                                                                } else if (n2 == 36) {
                                                                                                                    if (this.aE[n] < 20) {
                                                                                                                        this.c(n3);
                                                                                                                        int n15 = n;
                                                                                                                        this.aE[n15] = this.aE[n15] + 1;
                                                                                                                    }
                                                                                                                } else if (n2 == 42) {
                                                                                                                    int n16 = n;
                                                                                                                    this.aE[n16] = this.aE[n16] + 1;
                                                                                                                    if (this.aE[n16] >= 20) {
                                                                                                                        this.aI = 36;
                                                                                                                    }
                                                                                                                    this.c(n3);
                                                                                                                } else if (n2 == 43) {
                                                                                                                    this.A[n3] = 7;
                                                                                                                    this.B[n3] = 0;
                                                                                                                }
                                                                                                            }
                                                                                                        }
                                                                                                    }
                                                                                                    break block344;
                                                                                                }
                                                                                                if (this.aG[n] != 36) break block348;
                                                                                                if (n2 == 3) {
                                                                                                    this.aI = 37;
                                                                                                } else {
                                                                                                    if (n2 == 20) {
                                                                                                        return 1;
                                                                                                    }
                                                                                                    if (n2 == 28) {
                                                                                                        return 1;
                                                                                                    }
                                                                                                }
                                                                                                break block344;
                                                                                            }
                                                                                            if (this.aG[n] != 4) break block349;
                                                                                            if (n2 == 2) {
                                                                                                this.A[n3] = 4;
                                                                                                this.B[n3] = 0;
                                                                                            } else if (n2 == 5) {
                                                                                                this.A[n3] = 4;
                                                                                                this.B[n3] = 0;
                                                                                            } else if (n2 == 6) {
                                                                                                this.A[n3] = 4;
                                                                                                this.B[n3] = 0;
                                                                                            } else if (n2 == 7) {
                                                                                                this.A[n3] = 4;
                                                                                                this.B[n3] = 0;
                                                                                            } else if (n2 == 10) {
                                                                                                this.A[n3] = 3;
                                                                                                this.B[n3] = 0;
                                                                                            } else if (n2 == 11) {
                                                                                                this.A[n3] = 3;
                                                                                                this.B[n3] = 0;
                                                                                            } else if (n2 == 15) {
                                                                                                if (this.A[n3] == 15 && this.B[n3] > 0 && this.B[n3] < 100) {
                                                                                                    this.z[n3].b -= 50.0f;
                                                                                                    int n17 = n3;
                                                                                                    this.B[n17] = this.B[n17] + 100;
                                                                                                }
                                                                                            } else if (n2 == 16) {
                                                                                                this.A[n3] = 4;
                                                                                                this.B[n3] = 0;
                                                                                            } else if (n2 == 17) {
                                                                                                this.A[n3] = 4;
                                                                                                this.B[n3] = 0;
                                                                                            } else if (n2 == 23) {
                                                                                                this.A[n3] = 4;
                                                                                                this.B[n3] = 0;
                                                                                            } else if (n2 == 24) {
                                                                                                this.A[n3] = 4;
                                                                                                this.B[n3] = 0;
                                                                                            } else if (n2 == 26) {
                                                                                                this.A[n3] = 4;
                                                                                                this.B[n3] = 0;
                                                                                            } else if (n2 == 35) {
                                                                                                this.A[n3] = 4;
                                                                                                this.B[n3] = 0;
                                                                                            } else if (n2 == 39) {
                                                                                                this.A[n3] = 4;
                                                                                                this.B[n3] = 0;
                                                                                            } else if (n2 == 43) {
                                                                                                this.A[n3] = 4;
                                                                                                this.B[n3] = 0;
                                                                                            }
                                                                                            break block344;
                                                                                        }
                                                                                        if (this.aG[n] != 5) break block350;
                                                                                        if (n2 == 2) {
                                                                                            if (this.aE[n] == 1) {
                                                                                                this.aI = 6;
                                                                                            } else {
                                                                                                this.A[n3] = 5;
                                                                                                this.B[n3] = 0;
                                                                                            }
                                                                                        } else if (n2 == 3) {
                                                                                            this.aE[n] = 1;
                                                                                        } else if (n2 == 35) {
                                                                                            this.A[n3] = 6;
                                                                                            this.B[n3] = 0;
                                                                                        }
                                                                                        break block344;
                                                                                    }
                                                                                    if (this.aG[n] != 6) break block351;
                                                                                    if (n2 == 5) {
                                                                                        this.B[n3] = 1;
                                                                                    } else if (n2 == 16) {
                                                                                        this.aE[n] = 1;
                                                                                    }
                                                                                    break block344;
                                                                                }
                                                                                if (this.aG[n] != 7) break block352;
                                                                                if (n2 == 3) {
                                                                                    if (this.aE[n] < 20) {
                                                                                        int n18 = n;
                                                                                        this.aE[n18] = this.aE[n18] + 1;
                                                                                    }
                                                                                } else if (n2 == 4) {
                                                                                    if (this.aE[n] > 0) {
                                                                                        int n19 = n;
                                                                                        this.aE[n19] = this.aE[n19] - 1;
                                                                                    }
                                                                                } else if (n2 == 20) {
                                                                                    if (this.aE[n] > 0) {
                                                                                        int n20 = n;
                                                                                        this.aE[n20] = this.aE[n20] - 1;
                                                                                    }
                                                                                } else if (n2 == 25) {
                                                                                    if (this.aE[n] > 0) {
                                                                                        int n21 = n;
                                                                                        this.aE[n21] = this.aE[n21] - 1;
                                                                                    }
                                                                                } else if (n2 == 27) {
                                                                                    if (this.aE[n] < 20) {
                                                                                        int n22 = n;
                                                                                        this.aE[n22] = this.aE[n22] + 1;
                                                                                    }
                                                                                } else if (n2 == 28) {
                                                                                    if (this.aE[n] > 0) {
                                                                                        int n23 = n;
                                                                                        this.aE[n23] = this.aE[n23] - 1;
                                                                                    }
                                                                                } else if (n2 == 33) {
                                                                                    if (this.aE[n] > 0) {
                                                                                        int n24 = n;
                                                                                        this.aE[n24] = this.aE[n24] - 1;
                                                                                    }
                                                                                } else if (n2 == 37) {
                                                                                    if (this.aE[n] < 20) {
                                                                                        int n25 = n;
                                                                                        this.aE[n25] = this.aE[n25] + 1;
                                                                                    }
                                                                                } else if (n2 == 42 && this.aE[n] > 0) {
                                                                                    int n26 = n;
                                                                                    this.aE[n26] = this.aE[n26] - 1;
                                                                                }
                                                                                break block344;
                                                                            }
                                                                            if (this.aG[n] != 16) break block353;
                                                                            if (n2 == 20) {
                                                                                return 1;
                                                                            }
                                                                            if (n2 == 27) {
                                                                                this.c(n3);
                                                                            } else {
                                                                                if (n2 == 28) {
                                                                                    return 1;
                                                                                }
                                                                                if (n2 == 33) {
                                                                                    return 1;
                                                                                }
                                                                                if (n2 == 43 && this.B[n3] < 256) {
                                                                                    this.B[n3] = 16;
                                                                                }
                                                                            }
                                                                            break block344;
                                                                        }
                                                                        if (this.aG[n] != 27) break block354;
                                                                        if (n2 == 10) {
                                                                            this.aI = 10;
                                                                        } else if (n2 == 16) {
                                                                            this.c(n3);
                                                                        } else {
                                                                            if (n2 == 20) {
                                                                                return 1;
                                                                            }
                                                                            if (n2 == 25) {
                                                                                this.c(n3);
                                                                            } else {
                                                                                if (n2 == 28) {
                                                                                    return 1;
                                                                                }
                                                                                if (n2 == 33) {
                                                                                    return 1;
                                                                                }
                                                                                if (n2 == 42) {
                                                                                    this.c(n3);
                                                                                } else if (n2 == 43 && this.B[n3] < 256) {
                                                                                    this.B[n3] = 27;
                                                                                }
                                                                            }
                                                                        }
                                                                        break block344;
                                                                    }
                                                                    if (this.aG[n] == 8) break block344;
                                                                    if (this.aG[n] != 14) break block355;
                                                                    if (n2 == 28) {
                                                                        return 1;
                                                                    }
                                                                    if (n2 == 33) {
                                                                        return 1;
                                                                    }
                                                                    break block344;
                                                                }
                                                                if (this.aG[n] != 21) break block356;
                                                                if (this.aE[n] == 0 && n2 > 0) {
                                                                    this.aE[n] = n2;
                                                                } else if (this.aE[n] != 0 && n2 > 0) {
                                                                    this.A[n3] = this.aE[n];
                                                                    this.B[n3] = 0;
                                                                    this.C[n3] = 0;
                                                                }
                                                                break block344;
                                                            }
                                                            if (this.aG[n] != 23) break block357;
                                                            if (n2 == 43 && this.B[n3] < 256) {
                                                                this.B[n3] = 23;
                                                            }
                                                            break block344;
                                                        }
                                                        if (this.aG[n] != 34) break block358;
                                                        if (this.O[n2] != 0 || n2 == 14) {
                                                            this.c(n3);
                                                        }
                                                        if (n2 == 28) {
                                                            return 1;
                                                        }
                                                        if (n2 == 33) {
                                                            return 1;
                                                        }
                                                        break block344;
                                                    }
                                                    if (this.aG[n] != 39) break block359;
                                                    if (n2 == 5 || n2 == 24) {
                                                        this.c(n3);
                                                    }
                                                    if (n2 == 6) {
                                                        this.aC[n].a(0.9f);
                                                    }
                                                    break block344;
                                                }
                                                if (this.aG[n] != 28) break block360;
                                                if (n2 == 37) {
                                                    this.A[n3] = 28;
                                                    this.B[n3] = 0;
                                                    return 0;
                                                }
                                                if (n2 == 28) {
                                                    return 1;
                                                }
                                                if (n2 == 29) {
                                                    this.A[n3] = 28;
                                                    this.B[n3] = 6000;
                                                } else if (n2 == 41) {
                                                    this.A[n3] = 28;
                                                    this.B[n3] = 6100;
                                                    return 1;
                                                }
                                                break block344;
                                            }
                                            if (this.aG[n] != 19) break block361;
                                            if (n2 == 3) {
                                                this.aE[n] = 0;
                                            } else if (n2 == 20) {
                                                int n27 = n;
                                                this.aE[n27] = this.aE[n27] + 1;
                                                if (this.aE[n27] >= 20) {
                                                    this.aI = 20;
                                                }
                                            } else if (n2 == 19) {
                                                if (this.aR.h[this.aR.g] - this.D >= 1000 && this.aC[n].b() > 10.0f) {
                                                    int n28 = (int)this.aB[n].a + (int)this.aR.d(5.0f) - 2;
                                                    int n29 = (int)this.aB[n].b + (int)this.aR.d(5.0f) - 2;
                                                    int n30 = n29 * this.aR.a + n28;
                                                    if (this.F[n30] <= -4) {
                                                        this.a((float)n28, (float)n29, 42);
                                                    }
                                                }
                                            } else if (n2 == 42) {
                                                return 1;
                                            }
                                            break block344;
                                        }
                                        if (this.aG[n] != 20) break block362;
                                        if (n2 != 3) break block363;
                                        int n31 = n;
                                        this.aE[n31] = this.aE[n31] + 1;
                                        if (this.aE[n31] >= 20) {
                                            this.aI = 29;
                                        }
                                        d2 = this;
                                        break block364;
                                    }
                                    if (n2 != 20) break block365;
                                    nArray = this.aE;
                                    n4 = n;
                                    break block366;
                                }
                                if (n2 != 27) break block367;
                                int n32 = n;
                                this.aE[n32] = this.aE[n32] + 1;
                                if (this.aE[n32] >= 20) {
                                    this.aI = 38;
                                }
                                d2 = this;
                                break block364;
                            }
                            if (n2 != 37) break block368;
                            int n33 = n;
                            this.aE[n33] = this.aE[n33] + 1;
                            if (this.aE[n33] >= 20) {
                                this.aI = 19;
                            }
                            d2 = this;
                        }
                        d2.A[n3] = 12;
                        nArray = this.B;
                        n4 = n3;
                    }
                    nArray[n4] = 0;
                }
                if (n2 == 2) {
                    this.A[n3] = 4;
                    this.B[n3] = 0;
                } else if (n2 == 5) {
                    this.A[n3] = 4;
                    this.B[n3] = 0;
                } else if (n2 == 6) {
                    this.A[n3] = 4;
                    this.B[n3] = 0;
                } else if (n2 == 7) {
                    this.A[n3] = 4;
                    this.B[n3] = 0;
                } else if (n2 == 10) {
                    this.A[n3] = 3;
                    this.B[n3] = 0;
                } else if (n2 == 11) {
                    this.A[n3] = 3;
                    this.B[n3] = 0;
                } else if (n2 == 13) {
                    this.A[n3] = 4;
                    this.B[n3] = 0;
                } else if (n2 == 15) {
                    if (this.A[n3] == 15 && this.B[n3] > 0 && this.B[n3] < 100) {
                        this.z[n3].b -= 50.0f;
                        int n34 = n3;
                        this.B[n34] = this.B[n34] + 100;
                    }
                } else if (n2 == 16) {
                    this.A[n3] = 4;
                    this.B[n3] = 0;
                } else if (n2 == 17) {
                    this.A[n3] = 4;
                    this.B[n3] = 0;
                } else if (n2 != 19) {
                    if (n2 == 23) {
                        this.A[n3] = 4;
                        this.B[n3] = 0;
                    } else if (n2 == 24) {
                        this.A[n3] = 4;
                        this.B[n3] = 0;
                    } else if (n2 == 26) {
                        this.A[n3] = 4;
                        this.B[n3] = 0;
                    } else if (n2 != 29) {
                        if (n2 == 35) {
                            this.A[n3] = 4;
                            this.B[n3] = 0;
                        } else if (n2 != 38) {
                            if (n2 == 39) {
                                this.A[n3] = 4;
                                this.B[n3] = 0;
                            } else if (n2 != 41 && n2 == 43) {
                                this.A[n3] = 4;
                                this.B[n3] = 0;
                            }
                        }
                    }
                }
                break block344;
            }
            if (this.aG[n] == 29) {
                if (n2 == 3) {
                    this.aE[n] = 0;
                } else if (n2 == 20) {
                    int n35 = n;
                    this.aE[n35] = this.aE[n35] + 1;
                    if (this.aE[n35] >= 20) {
                        this.aI = 20;
                    }
                } else if (n2 == 29) {
                    if (this.aR.h[this.aR.g] - this.D >= 1000 && this.aC[n].b() > 10.0f) {
                        int n36 = (int)this.aB[n].a + (int)this.aR.d(5.0f) - 2;
                        int n37 = (int)this.aB[n].b + (int)this.aR.d(5.0f) - 2;
                        int n38 = n37 * this.aR.a + n36;
                        if (this.F[n38] <= -4) {
                            this.a((float)n36, (float)n37, 42);
                        }
                    }
                } else {
                    if (n2 == 28) {
                        return 1;
                    }
                    if (n2 == 33) {
                        return 1;
                    }
                    if (n2 == 42) {
                        return 1;
                    }
                }
            } else if (this.aG[n] == 38) {
                if (n2 == 3) {
                    this.aE[n] = 0;
                } else if (n2 == 20) {
                    int n39 = n;
                    this.aE[n39] = this.aE[n39] + 1;
                    if (this.aE[n39] >= 20) {
                        this.aI = 20;
                    }
                } else {
                    if (n2 == 28) {
                        return 1;
                    }
                    if (n2 == 33) {
                        return 1;
                    }
                }
            } else if (this.aG[n] == 25) {
                if (n2 == 2) {
                    this.A[n3] = 4;
                    this.B[n3] = 0;
                } else if (n2 == 5) {
                    this.A[n3] = 4;
                    this.B[n3] = 0;
                } else if (n2 == 6) {
                    this.A[n3] = 25;
                    this.B[n3] = 0;
                } else if (n2 == 7) {
                    this.A[n3] = 4;
                    this.B[n3] = 0;
                } else if (n2 == 10) {
                    this.A[n3] = 3;
                    this.B[n3] = 0;
                } else if (n2 == 11) {
                    this.A[n3] = 3;
                    this.B[n3] = 0;
                } else if (n2 == 13) {
                    this.A[n3] = 4;
                    this.B[n3] = 0;
                } else if (n2 == 15) {
                    if (this.A[n3] == 15 && this.B[n3] > 0 && this.B[n3] < 100) {
                        this.z[n3].b -= 50.0f;
                        int n40 = n3;
                        this.B[n40] = this.B[n40] + 100;
                    }
                } else if (n2 == 16) {
                    this.A[n3] = 4;
                    this.B[n3] = 0;
                } else if (n2 == 17) {
                    this.A[n3] = 4;
                    this.B[n3] = 0;
                } else if (n2 == 23) {
                    this.A[n3] = 4;
                    this.B[n3] = 0;
                } else if (n2 == 24) {
                    this.A[n3] = 4;
                    this.B[n3] = 0;
                } else if (n2 == 26) {
                    this.A[n3] = 4;
                    this.B[n3] = 0;
                } else if (n2 == 35) {
                    this.A[n3] = 4;
                    this.B[n3] = 0;
                } else if (n2 == 39) {
                    this.A[n3] = 4;
                    this.B[n3] = 0;
                } else if (n2 == 43) {
                    this.A[n3] = 4;
                    this.B[n3] = 0;
                } else if (n2 == 44) {
                    this.A[n3] = 3;
                    this.B[n3] = 0;
                }
            } else if (this.aG[n] == 43) {
                if (n2 == 16) {
                    this.aE[n] = 16;
                } else if (n2 == 23) {
                    this.aE[n] = 23;
                } else if (n2 == 27) {
                    this.aE[n] = 27;
                }
            } else if (this.aG[n] == 44) {
                if (n2 == 6) {
                    this.aI = 3;
                } else if (n2 == 10) {
                    this.aI = 10;
                } else if (n2 == 17) {
                    this.aI = 3;
                } else if (n2 == 25) {
                    this.aI = 3;
                } else if (n2 == 29) {
                    this.aI = 28;
                } else if (n2 == 35) {
                    this.aI = 3;
                } else if (n2 == 43) {
                    this.aI = 3;
                } else {
                    if (n2 == 28) {
                        return 1;
                    }
                    if (n2 == 33) {
                        return 1;
                    }
                }
            } else if (this.aG[n] == 45) {
                if (this.aE[n] == 0) {
                    if (n2 == 3) {
                        this.aE[n] = 3;
                    } else if (n2 == 16) {
                        this.aE[n] = 16;
                    } else if (n2 == 20) {
                        this.aE[n] = 20;
                    } else if (n2 == 23) {
                        this.aE[n] = 23;
                    } else if (n2 == 26) {
                        this.aE[n] = 26;
                    } else if (n2 == 27) {
                        this.aE[n] = 27;
                    } else if (n2 == 34) {
                        this.aE[n] = 34;
                    } else if (n2 == 37) {
                        this.aE[n] = 37;
                    } else if (n2 == 41) {
                        this.aE[n] = 41;
                    } else if (n2 == 44) {
                        this.aE[n] = 44;
                    }
                } else {
                    int n41 = this.aE[n] & 0xFF;
                    int n42 = this.aE[n] >> 8;
                    if (n2 == n41) {
                        this.aE[n] = n42 + 1 << 8 | n41;
                        this.c(n3);
                    }
                }
                if (n2 == 20) {
                    return 1;
                }
                if (n2 == 28) {
                    return 1;
                }
                if (n2 == 33) {
                    return 1;
                }
            }
        }
        if (this.P[n2] == 2 && this.P[this.aG[n]] == 2 && this.aG[n] != n2) {
            return 1;
        }
        if (this.P[n2] == 2 && this.P[this.aG[n]] != 2) {
            return 1;
        }
        if (this.P[n2] == 5 && this.P[this.aG[n]] != 5) {
            return 1;
        }
        if (n2 == 4) {
            return 1;
        }
        return 0;
    }

    private void a(int n, int n2, int n3, int n4, int n5, float f, float f2, float f3) {
        if (n3 == 0) {
            int n6 = 9;
            while (n6 < 21) {
                int n7;
                int n8 = this.F[n2 + this.aJ[n6]];
                if (n8 <= -4 && (n7 = this.a((float)((int)this.aB[n].a + this.aM[n6]), (float)((int)this.aB[n].b + this.aN[n6]), n4)) > 0) {
                    this.z[n7].a += f + this.aK[n6] * f3;
                    this.z[n7].b += f2 + this.aL[n6] * f3;
                    this.B[n7] = n5;
                }
                ++n6;
            }
            this.aD[n] = 0;
            return;
        }
        if (n3 == 1 || n3 == 2) {
            int n9 = n3 == 1 ? 9 : 0;
            while (n9 < 21) {
                int n10 = this.F[n2 + this.aJ[n9]];
                if (n10 <= -4) {
                    this.a((float)((int)this.aB[n].a + this.aM[n9]), (float)((int)this.aB[n].b + this.aN[n9]), n4);
                } else if (n10 >= 0) {
                    this.A[n10] = n4;
                    this.B[n10] = 0;
                    this.C[n10] = 0;
                }
                ++n9;
            }
            this.aD[n] = 0;
        }
    }

    private void z() {
        int n = 0;
        while (n < this.aH) {
            block6: {
                int n2;
                block8: {
                    int n3;
                    int[] nArray;
                    int n4;
                    block7: {
                        if (this.aD[n] == 0) break block6;
                        n4 = (int)this.aB[n].b * this.aR.a + (int)this.aB[n].a;
                        int n5 = this.v[this.aG[n]][0];
                        if (this.aR.j == 13) {
                            n5 = -16777216;
                        }
                        int n6 = 9;
                        while (n6 < 21) {
                            this.aR.ar[n4 + this.aJ[n6]] = n5;
                            ++n6;
                        }
                        if (!(this.aB[n].b < 308.0f)) break block6;
                        if (this.aR.j != 11) break block7;
                        if (this.aG[n] != 4 && this.aG[n] != 20 && this.aG[n] != 25 && this.aG[n] != 28 && this.aG[n] != 33 && this.aG[n] != 42) break block6;
                        nArray = this.aR.P;
                        n3 = n4;
                        n2 = 255000;
                        break block8;
                    }
                    if (this.aR.j != 12) break block6;
                    nArray = this.aR.P;
                    n3 = n4;
                    n2 = this.x[this.aG[n]] * 2;
                }
                nArray[n3] = n2;
            }
            ++n;
        }
    }

    d(dust dust2) {
        this.aR = dust2;
        this.aR = dust2;
        this.q = new e(this.aR);
        int[] nArray = new int[70];
        nArray[0] = 2;
        nArray[1] = 3;
        nArray[2] = 4;
        nArray[3] = 5;
        nArray[4] = 7;
        nArray[5] = 8;
        nArray[6] = 10;
        nArray[7] = 13;
        nArray[8] = 14;
        nArray[9] = 15;
        nArray[10] = 16;
        nArray[11] = 17;
        nArray[12] = 19;
        nArray[13] = 20;
        nArray[14] = 21;
        nArray[15] = 23;
        nArray[16] = 24;
        nArray[17] = 25;
        nArray[18] = 26;
        nArray[19] = 27;
        nArray[20] = 28;
        nArray[21] = 29;
        nArray[22] = 31;
        nArray[23] = 33;
        nArray[24] = 34;
        nArray[25] = 35;
        nArray[26] = 36;
        nArray[27] = 38;
        nArray[28] = 39;
        nArray[29] = 41;
        nArray[30] = 42;
        nArray[31] = 43;
        nArray[32] = 44;
        nArray[33] = 45;
        nArray[43] = 12;
        this.r = nArray;
        int[] nArray2 = new int[70];
        nArray2[0] = 2;
        nArray2[1] = 3;
        nArray2[2] = 4;
        nArray2[3] = 5;
        nArray2[4] = 7;
        nArray2[6] = 11;
        nArray2[7] = 13;
        nArray2[10] = 16;
        nArray2[12] = 19;
        nArray2[13] = 20;
        nArray2[14] = 21;
        nArray2[15] = 23;
        nArray2[16] = 24;
        nArray2[17] = 4;
        nArray2[18] = 26;
        nArray2[19] = 12;
        nArray2[22] = 31;
        nArray2[23] = 33;
        nArray2[24] = 34;
        nArray2[26] = 36;
        nArray2[28] = 39;
        nArray2[29] = 41;
        nArray2[30] = 42;
        nArray2[32] = 44;
        nArray2[43] = 12;
        this.s = nArray2;
        int[] nArray3 = new int[70];
        nArray3[0] = 2;
        nArray3[1] = 3;
        nArray3[2] = 4;
        nArray3[3] = 5;
        nArray3[4] = 7;
        nArray3[5] = 8;
        nArray3[6] = 11;
        nArray3[7] = 13;
        nArray3[9] = 15;
        nArray3[10] = 16;
        nArray3[12] = 19;
        nArray3[13] = 20;
        nArray3[14] = 21;
        nArray3[15] = 23;
        nArray3[16] = 24;
        nArray3[18] = 26;
        nArray3[19] = 27;
        nArray3[22] = 31;
        nArray3[23] = 33;
        nArray3[24] = 34;
        nArray3[26] = 36;
        nArray3[28] = 39;
        nArray3[29] = 41;
        nArray3[30] = 42;
        nArray3[32] = 44;
        nArray3[43] = 12;
        this.t = nArray3;
        int[] nArray4 = new int[70];
        nArray4[0] = 2;
        nArray4[1] = 3;
        nArray4[2] = 4;
        nArray4[3] = 5;
        nArray4[4] = 7;
        nArray4[5] = 8;
        nArray4[6] = 10;
        nArray4[8] = 14;
        nArray4[10] = 16;
        nArray4[11] = 17;
        nArray4[12] = 19;
        nArray4[13] = 20;
        nArray4[14] = 21;
        nArray4[15] = 23;
        nArray4[17] = 25;
        nArray4[18] = 26;
        nArray4[19] = 27;
        nArray4[20] = 28;
        nArray4[21] = 29;
        nArray4[22] = 31;
        nArray4[24] = 34;
        nArray4[26] = 36;
        nArray4[27] = 38;
        nArray4[28] = 39;
        nArray4[31] = 43;
        nArray4[32] = 44;
        nArray4[33] = 45;
        nArray4[43] = 12;
        this.u = nArray4;
        int[][] nArrayArray = new int[46][];
        nArrayArray[0] = new int[1];
        nArrayArray[1] = new int[]{-10461088};
        nArrayArray[2] = new int[]{-869013};
        nArrayArray[3] = new int[]{-12566273};
        nArrayArray[4] = new int[]{-49088};
        nArrayArray[5] = new int[]{-7290816};
        nArrayArray[6] = new int[]{-8368096};
        nArrayArray[7] = new int[]{-5210032};
        nArrayArray[8] = new int[]{-8355585};
        nArrayArray[9] = new int[]{-5201776};
        nArrayArray[10] = new int[]{-3092225};
        nArrayArray[11] = new int[]{-1};
        nArrayArray[12] = new int[]{-2039584};
        nArrayArray[13] = new int[]{-48992};
        nArrayArray[14] = new int[]{-7311344};
        nArrayArray[15] = new int[]{-26266};
        nArrayArray[16] = new int[]{-8376288};
        nArrayArray[17] = new int[]{-52};
        nArrayArray[18] = new int[]{-8018};
        nArrayArray[19] = new int[]{-8355712};
        nArrayArray[20] = new int[]{-39373};
        nArrayArray[21] = new int[]{-8388480};
        nArrayArray[22] = new int[]{-8018};
        nArrayArray[23] = new int[]{-12290304};
        nArrayArray[24] = new int[]{-4161344};
        nArrayArray[25] = new int[]{-24544};
        nArrayArray[26] = new int[]{-3368551};
        nArrayArray[27] = new int[]{-2039584};
        nArrayArray[28] = new int[]{-224};
        nArrayArray[29] = new int[]{-12566464};
        nArrayArray[30] = new int[]{-8018};
        nArrayArray[31] = new int[]{-10066432};
        nArrayArray[32] = new int[]{-8018};
        nArrayArray[33] = new int[]{-3407872};
        nArrayArray[34] = new int[]{-3342592};
        nArrayArray[35] = new int[]{-16729344};
        nArrayArray[36] = new int[]{-1};
        nArrayArray[37] = new int[]{-13395457};
        nArrayArray[38] = new int[]{-16711423};
        nArrayArray[39] = new int[]{-8359856};
        nArrayArray[40] = new int[]{-8018};
        nArrayArray[41] = new int[]{-5592406};
        nArrayArray[42] = new int[]{-13261};
        nArrayArray[43] = new int[]{-12307678};
        nArrayArray[44] = new int[]{-3355444};
        int[] nArray5 = new int[46];
        nArray5[0] = -16764109;
        nArray5[2] = -869013;
        nArray5[3] = -12566273;
        nArray5[4] = -49088;
        nArray5[5] = -7290816;
        nArray5[6] = -8368096;
        nArray5[7] = -5210032;
        nArray5[8] = -8355585;
        nArray5[10] = -3092225;
        nArray5[11] = -1;
        nArray5[12] = -2039584;
        nArray5[13] = -48992;
        nArray5[14] = -7311344;
        nArray5[15] = -26266;
        nArray5[16] = -8376288;
        nArray5[17] = -52;
        nArray5[19] = -8355712;
        nArray5[20] = -39373;
        nArray5[21] = -8388480;
        nArray5[23] = -12290304;
        nArray5[24] = -4161344;
        nArray5[25] = -24544;
        nArray5[26] = -3368551;
        nArray5[27] = -2039584;
        nArray5[28] = -224;
        nArray5[29] = -12566464;
        nArray5[31] = -10066432;
        nArray5[33] = -3407872;
        nArray5[34] = -3342592;
        nArray5[35] = -16729344;
        nArray5[36] = -1;
        nArray5[37] = -13395457;
        nArray5[38] = -16711423;
        nArray5[39] = -8359856;
        nArray5[41] = -5592406;
        nArray5[42] = -13261;
        nArray5[43] = -12307678;
        nArray5[44] = -3355444;
        nArrayArray[45] = nArray5;
        this.v = nArrayArray;
        this.w = new int[this.v.length];
        int[] nArray6 = new int[46];
        nArray6[4] = 5000;
        nArray6[5] = 500;
        nArray6[6] = 500;
        nArray6[10] = -1000;
        nArray6[11] = -500;
        nArray6[20] = 10000;
        nArray6[24] = 1500;
        nArray6[25] = 4000;
        nArray6[26] = 500;
        nArray6[28] = 2000;
        nArray6[33] = 5500;
        nArray6[35] = 500;
        nArray6[39] = 2000;
        nArray6[42] = 3000;
        this.x = nArray6;
        this.I = new int[]{1, -1, this.aR.a, -this.aR.a, this.aR.a + 1, this.aR.a - 1, -this.aR.a + 1, -this.aR.a - 1};
        int[] nArray7 = new int[8];
        nArray7[0] = 1;
        nArray7[1] = 1;
        nArray7[3] = -1;
        nArray7[4] = -1;
        nArray7[5] = -1;
        nArray7[7] = 1;
        this.J = nArray7;
        int[] nArray8 = new int[8];
        nArray8[1] = -1;
        nArray8[2] = -1;
        nArray8[3] = -1;
        nArray8[5] = 1;
        nArray8[6] = 1;
        nArray8[7] = 1;
        this.K = nArray8;
        this.L = new int[]{1, -this.aR.a + 1, -this.aR.a, -this.aR.a - 1, -1, this.aR.a - 1, this.aR.a, this.aR.a + 1};
        float[] fArray = new float[46];
        fArray[2] = 0.2f;
        fArray[5] = 0.2f;
        fArray[6] = 0.7f;
        fArray[7] = 0.2f;
        fArray[10] = 0.8f;
        fArray[11] = 0.2f;
        fArray[12] = 0.2f;
        fArray[14] = 0.2f;
        fArray[15] = 0.5f;
        fArray[17] = 0.5f;
        fArray[19] = 0.9f;
        fArray[20] = 0.2f;
        fArray[24] = 0.3f;
        fArray[29] = 0.9f;
        fArray[31] = 0.9f;
        fArray[35] = 0.8f;
        fArray[36] = 0.2f;
        fArray[38] = 0.9f;
        fArray[39] = 0.1f;
        fArray[41] = 0.9f;
        fArray[42] = 0.9f;
        fArray[43] = 0.5f;
        fArray[45] = 0.9f;
        this.M = fArray;
        float[] fArray2 = new float[46];
        fArray2[2] = 0.2f;
        fArray2[5] = 0.2f;
        fArray2[6] = 0.7f;
        fArray2[7] = 0.2f;
        fArray2[10] = 1.0f;
        fArray2[11] = 0.2f;
        fArray2[12] = 0.2f;
        fArray2[14] = 0.2f;
        fArray2[15] = 0.5f;
        fArray2[17] = 0.5f;
        fArray2[19] = 0.9f;
        fArray2[20] = 0.2f;
        fArray2[24] = 0.3f;
        fArray2[27] = 1.0f;
        fArray2[29] = 0.9f;
        fArray2[31] = 0.9f;
        fArray2[35] = 0.2f;
        fArray2[36] = 0.2f;
        fArray2[38] = 0.5f;
        fArray2[39] = 0.1f;
        fArray2[41] = 0.9f;
        fArray2[42] = 0.9f;
        fArray2[43] = 0.5f;
        fArray2[45] = 0.9f;
        this.N = fArray2;
        int[] nArray9 = new int[46];
        nArray9[2] = 5;
        nArray9[3] = 40;
        nArray9[4] = 10;
        nArray9[5] = 5;
        nArray9[6] = 10;
        nArray9[7] = 10;
        nArray9[10] = 40;
        nArray9[11] = 10;
        nArray9[12] = 30;
        nArray9[13] = 10;
        nArray9[15] = 10;
        nArray9[16] = 30;
        nArray9[17] = 100;
        nArray9[19] = 20;
        nArray9[20] = 50;
        nArray9[21] = 10;
        nArray9[23] = 100;
        nArray9[24] = 5;
        nArray9[25] = 10;
        nArray9[26] = 5;
        nArray9[27] = 30;
        nArray9[29] = 10;
        nArray9[31] = 10;
        nArray9[33] = 5;
        nArray9[35] = 10;
        nArray9[36] = 5;
        nArray9[37] = 40;
        nArray9[39] = 10;
        nArray9[41] = 20;
        nArray9[42] = 5;
        nArray9[43] = 50;
        nArray9[44] = 5;
        this.O = nArray9;
        int[] nArray10 = new int[46];
        nArray10[2] = 1;
        nArray10[3] = 2;
        nArray10[4] = 3;
        nArray10[5] = 1;
        nArray10[6] = 4;
        nArray10[7] = 1;
        nArray10[10] = 4;
        nArray10[11] = 1;
        nArray10[13] = 1;
        nArray10[14] = 4;
        nArray10[15] = 1;
        nArray10[16] = 2;
        nArray10[17] = 4;
        nArray10[19] = 1;
        nArray10[20] = 3;
        nArray10[21] = 1;
        nArray10[23] = 2;
        nArray10[24] = 1;
        nArray10[25] = 3;
        nArray10[26] = 5;
        nArray10[27] = 2;
        nArray10[28] = 3;
        nArray10[29] = 4;
        nArray10[31] = 1;
        nArray10[33] = 3;
        nArray10[34] = 2;
        nArray10[35] = 4;
        nArray10[36] = 1;
        nArray10[37] = 2;
        nArray10[38] = 4;
        nArray10[39] = 5;
        nArray10[41] = 2;
        nArray10[42] = 3;
        nArray10[43] = 4;
        nArray10[44] = 5;
        nArray10[45] = 4;
        this.P = nArray10;
        this.Q = new b(this.aR);
        this.X = new int[1024];
        this.Y = new float[1024];
        this.Z = new float[1024];
        float[] fArray3 = new float[46];
        fArray3[1] = 0.5f;
        fArray3[2] = 0.5f;
        fArray3[3] = 0.8f;
        fArray3[4] = 1.0f;
        fArray3[5] = 0.5f;
        fArray3[6] = 0.5f;
        fArray3[7] = 0.5f;
        fArray3[8] = 1.0f;
        fArray3[9] = 0.5f;
        fArray3[10] = 1.0f;
        fArray3[11] = 0.5f;
        fArray3[12] = 1.0f;
        fArray3[13] = 0.5f;
        fArray3[14] = 0.5f;
        fArray3[15] = 0.5f;
        fArray3[16] = 0.8f;
        fArray3[17] = 0.5f;
        fArray3[19] = 0.5f;
        fArray3[20] = 0.5f;
        fArray3[21] = 0.5f;
        fArray3[23] = 0.8f;
        fArray3[24] = 0.5f;
        fArray3[26] = 1.0f;
        fArray3[27] = 1.0f;
        fArray3[29] = 0.5f;
        fArray3[31] = 0.5f;
        fArray3[34] = 0.8f;
        fArray3[35] = 0.5f;
        fArray3[36] = 0.5f;
        fArray3[37] = 0.8f;
        fArray3[38] = 0.9f;
        fArray3[39] = 0.1f;
        fArray3[41] = 1.0f;
        fArray3[42] = 0.5f;
        fArray3[43] = 0.5f;
        fArray3[44] = 1.0f;
        fArray3[45] = 0.5f;
        this.aw = fArray3;
        int[] nArray11 = new int[46];
        nArray11[2] = 1;
        nArray11[3] = 1;
        nArray11[4] = 1;
        nArray11[5] = 1;
        nArray11[7] = 1;
        nArray11[8] = 1;
        nArray11[11] = 1;
        nArray11[12] = 1;
        nArray11[13] = 1;
        nArray11[15] = 1;
        nArray11[16] = 1;
        nArray11[19] = 1;
        nArray11[20] = 1;
        nArray11[21] = 1;
        nArray11[23] = 1;
        nArray11[24] = 1;
        nArray11[26] = 1;
        nArray11[27] = 1;
        nArray11[31] = 1;
        nArray11[33] = 1;
        nArray11[34] = 1;
        nArray11[36] = 1;
        nArray11[37] = 1;
        nArray11[39] = 1;
        nArray11[41] = 1;
        nArray11[42] = 1;
        nArray11[44] = 1;
        this.ax = nArray11;
        this.ay = new int[2];
        this.az = new int[2];
        this.aA = new int[2];
        int[] nArray12 = new int[37];
        nArray12[0] = -this.aR.a - 1;
        nArray12[1] = -this.aR.a;
        nArray12[2] = -this.aR.a + 1;
        nArray12[3] = -1;
        nArray12[5] = 1;
        nArray12[6] = this.aR.a - 1;
        nArray12[7] = this.aR.a;
        nArray12[8] = this.aR.a + 1;
        nArray12[9] = -this.aR.a * 2 - 1;
        nArray12[10] = -this.aR.a * 2;
        nArray12[11] = -this.aR.a * 2 + 1;
        nArray12[12] = this.aR.a * 2 - 1;
        nArray12[13] = this.aR.a * 2;
        nArray12[14] = this.aR.a * 2 + 1;
        nArray12[15] = -2 - this.aR.a;
        nArray12[16] = -2;
        nArray12[17] = -2 + this.aR.a;
        nArray12[18] = 2 - this.aR.a;
        nArray12[19] = 2;
        nArray12[20] = 2 + this.aR.a;
        nArray12[21] = -this.aR.a * 3 - 1;
        nArray12[22] = -this.aR.a * 3;
        nArray12[23] = -this.aR.a * 3 + 1;
        nArray12[24] = this.aR.a * 3 - 1;
        nArray12[25] = this.aR.a * 3;
        nArray12[26] = this.aR.a * 3 + 1;
        nArray12[27] = -3 - this.aR.a;
        nArray12[28] = -3;
        nArray12[29] = -3 + this.aR.a;
        nArray12[30] = 3 - this.aR.a;
        nArray12[31] = 3;
        nArray12[32] = 3 + this.aR.a;
        nArray12[33] = -2 - this.aR.a * 2;
        nArray12[34] = 2 - this.aR.a * 2;
        nArray12[35] = -2 + this.aR.a * 2;
        nArray12[36] = 2 + this.aR.a * 2;
        this.aJ = nArray12;
        float[] fArray4 = new float[37];
        fArray4[0] = -0.7f;
        fArray4[2] = 0.7f;
        fArray4[3] = -1.0f;
        fArray4[5] = 1.0f;
        fArray4[6] = -0.7f;
        fArray4[8] = 0.7f;
        fArray4[9] = -0.44f;
        fArray4[11] = 0.44f;
        fArray4[12] = -0.44f;
        fArray4[14] = 0.44f;
        fArray4[15] = -0.89f;
        fArray4[16] = -1.0f;
        fArray4[17] = -0.89f;
        fArray4[18] = 0.89f;
        fArray4[19] = 1.0f;
        fArray4[20] = 0.89f;
        fArray4[21] = -0.31f;
        fArray4[23] = 0.31f;
        fArray4[24] = -0.31f;
        fArray4[26] = 0.31f;
        fArray4[27] = -0.94f;
        fArray4[28] = -1.0f;
        fArray4[29] = -0.94f;
        fArray4[30] = 0.94f;
        fArray4[31] = 1.0f;
        fArray4[32] = 0.94f;
        fArray4[33] = -0.7f;
        fArray4[34] = 0.7f;
        fArray4[35] = -0.7f;
        fArray4[36] = 0.7f;
        this.aK = fArray4;
        float[] fArray5 = new float[37];
        fArray5[0] = -0.7f;
        fArray5[1] = -1.0f;
        fArray5[2] = -0.7f;
        fArray5[6] = 0.7f;
        fArray5[7] = 1.0f;
        fArray5[8] = 0.7f;
        fArray5[9] = -0.89f;
        fArray5[10] = -1.0f;
        fArray5[11] = -0.89f;
        fArray5[12] = 0.89f;
        fArray5[13] = 1.0f;
        fArray5[14] = 0.89f;
        fArray5[15] = -0.44f;
        fArray5[17] = 0.44f;
        fArray5[18] = -0.44f;
        fArray5[20] = 0.44f;
        fArray5[21] = -0.94f;
        fArray5[22] = -1.0f;
        fArray5[23] = -0.94f;
        fArray5[24] = 0.94f;
        fArray5[25] = 1.0f;
        fArray5[26] = 0.94f;
        fArray5[27] = -0.31f;
        fArray5[29] = 0.31f;
        fArray5[30] = -0.31f;
        fArray5[32] = 0.31f;
        fArray5[33] = -0.7f;
        fArray5[34] = -0.7f;
        fArray5[35] = 0.7f;
        fArray5[36] = 0.7f;
        this.aL = fArray5;
        int[] nArray13 = new int[37];
        nArray13[0] = -1;
        nArray13[2] = 1;
        nArray13[3] = -1;
        nArray13[5] = 1;
        nArray13[6] = -1;
        nArray13[8] = 1;
        nArray13[9] = -1;
        nArray13[11] = 1;
        nArray13[12] = -1;
        nArray13[14] = 1;
        nArray13[15] = -2;
        nArray13[16] = -2;
        nArray13[17] = -2;
        nArray13[18] = 2;
        nArray13[19] = 2;
        nArray13[20] = 2;
        nArray13[21] = -1;
        nArray13[23] = 1;
        nArray13[24] = -1;
        nArray13[26] = 1;
        nArray13[27] = -3;
        nArray13[28] = -3;
        nArray13[29] = -3;
        nArray13[30] = 3;
        nArray13[31] = 3;
        nArray13[32] = 3;
        nArray13[33] = -2;
        nArray13[34] = 2;
        nArray13[35] = -2;
        nArray13[36] = 2;
        this.aM = nArray13;
        int[] nArray14 = new int[37];
        nArray14[0] = -1;
        nArray14[1] = -1;
        nArray14[2] = -1;
        nArray14[6] = 1;
        nArray14[7] = 1;
        nArray14[8] = 1;
        nArray14[9] = -2;
        nArray14[10] = -2;
        nArray14[11] = -2;
        nArray14[12] = 2;
        nArray14[13] = 2;
        nArray14[14] = 2;
        nArray14[15] = -1;
        nArray14[17] = 1;
        nArray14[18] = -1;
        nArray14[20] = 1;
        nArray14[21] = -3;
        nArray14[22] = -3;
        nArray14[23] = -3;
        nArray14[24] = 3;
        nArray14[25] = 3;
        nArray14[26] = 3;
        nArray14[27] = -1;
        nArray14[29] = 1;
        nArray14[30] = -1;
        nArray14[32] = 1;
        nArray14[33] = -2;
        nArray14[34] = -2;
        nArray14[35] = 2;
        nArray14[36] = 2;
        this.aN = nArray14;
        float[] fArray6 = new float[46];
        fArray6[2] = 0.1f;
        fArray6[3] = 0.1f;
        fArray6[4] = -0.03f;
        fArray6[5] = 0.1f;
        fArray6[6] = 0.1f;
        fArray6[7] = 0.1f;
        fArray6[8] = 0.1f;
        fArray6[10] = 0.1f;
        fArray6[11] = 0.02f;
        fArray6[12] = 0.05f;
        fArray6[13] = 0.1f;
        fArray6[14] = 0.1f;
        fArray6[15] = 0.1f;
        fArray6[16] = 0.1f;
        fArray6[17] = 0.1f;
        fArray6[19] = 0.1f;
        fArray6[20] = 0.1f;
        fArray6[21] = 0.1f;
        fArray6[23] = 0.1f;
        fArray6[24] = 0.1f;
        fArray6[25] = 0.1f;
        fArray6[26] = -0.01f;
        fArray6[27] = 0.1f;
        fArray6[28] = 0.1f;
        fArray6[29] = 0.2f;
        fArray6[31] = 0.1f;
        fArray6[33] = 0.1f;
        fArray6[34] = 0.1f;
        fArray6[35] = 0.1f;
        fArray6[36] = 0.1f;
        fArray6[37] = 0.1f;
        fArray6[38] = 0.1f;
        fArray6[39] = 0.05f;
        fArray6[41] = 0.2f;
        fArray6[42] = 0.1f;
        fArray6[43] = 0.1f;
        fArray6[44] = -0.02f;
        fArray6[45] = 0.1f;
        this.aO = fArray6;
        float[] fArray7 = new float[46];
        fArray7[2] = 0.5f;
        fArray7[3] = 0.4f;
        fArray7[4] = 0.5f;
        fArray7[5] = 0.5f;
        fArray7[6] = 0.4f;
        fArray7[7] = 0.4f;
        fArray7[8] = 0.9f;
        fArray7[10] = 0.3f;
        fArray7[11] = 0.5f;
        fArray7[12] = 0.5f;
        fArray7[13] = 0.3f;
        fArray7[14] = 0.3f;
        fArray7[15] = 0.3f;
        fArray7[17] = 0.2f;
        fArray7[19] = 0.1f;
        fArray7[21] = 0.5f;
        fArray7[23] = 0.3f;
        fArray7[24] = 0.5f;
        fArray7[25] = 0.3f;
        fArray7[26] = 0.5f;
        fArray7[27] = 0.4f;
        fArray7[31] = 0.1f;
        fArray7[34] = 0.4f;
        fArray7[35] = 0.4f;
        fArray7[36] = 0.5f;
        fArray7[37] = 0.4f;
        fArray7[38] = 0.2f;
        fArray7[39] = 0.5f;
        fArray7[42] = 0.5f;
        fArray7[43] = 0.2f;
        fArray7[44] = 0.5f;
        this.aP = fArray7;
        int[] nArray15 = new int[46];
        nArray15[2] = 1;
        nArray15[3] = 1;
        nArray15[4] = 1;
        nArray15[5] = 1;
        nArray15[6] = 1;
        nArray15[7] = 1;
        nArray15[8] = 1;
        nArray15[10] = 1;
        nArray15[12] = 1;
        nArray15[14] = 1;
        nArray15[16] = 1;
        nArray15[17] = 1;
        nArray15[19] = 1;
        nArray15[20] = 1;
        nArray15[21] = 1;
        nArray15[23] = 1;
        nArray15[25] = 1;
        nArray15[26] = 1;
        nArray15[27] = 1;
        nArray15[28] = 1;
        nArray15[29] = 1;
        nArray15[31] = 1;
        nArray15[34] = 1;
        nArray15[36] = 1;
        nArray15[37] = 1;
        nArray15[38] = 1;
        nArray15[39] = 1;
        nArray15[43] = 1;
        nArray15[44] = 1;
        nArray15[45] = 1;
        this.aQ = nArray15;
    }
}
