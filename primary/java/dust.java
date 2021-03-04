/*
 * Decompiled with CFR 0.151.
 */
import java.applet.Applet;
import java.awt.Graphics;
import java.awt.Image;
import java.awt.Point;
import java.awt.TextField;
import java.awt.event.KeyEvent;
import java.awt.event.KeyListener;
import java.awt.event.MouseEvent;
import java.awt.event.MouseListener;
import java.awt.event.MouseMotionListener;
import java.awt.image.ColorModel;
import java.awt.image.DirectColorModel;
import java.awt.image.MemoryImageSource;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.OutputStream;
import java.net.Socket;
import java.net.URL;
import java.net.URLEncoder;

public class dust
extends Applet
implements Runnable,
MouseListener,
MouseMotionListener,
KeyListener {
    int a = 416;
    int b = 464;
    int c;
    int d = 40;
    boolean e = false;
    int f = 2;
    int g;
    int[] h = new int[]{20000, 30000, 40000};
    int i;
    int j = 2;
    int k;
    float l;
    float m;
    int n;
    int o = 8;
    int p = 8;
    int q = 8;
    int r = 8;
    byte[] s;
    byte[] t;
    int u = -1;
    int v;
    int w;
    int x;
    int y;
    int z;
    int A;
    int B;
    int C;
    int D;
    int E;
    b F = new b(this);
    TextField G;
    TextField H;
    int I;
    int J;
    int K;
    String[] L = new String[]{"Dialog", "DialogInput", "Serif", "SansSerif", "Monospaced", "setFont ->"};
    String[] M = new String[]{"PLAIN", "BOLD", "ITALIC", "BOLD&ITALIC"};
    int[] N;
    int[] O;
    int[] P;
    int[] Q;
    int[] R;
    d S;
    b T;
    b U;
    int V;
    int W;
    byte[] X;
    byte[] Y;
    String Z;
    boolean aa;
    String ab;
    String ac;
    String ad;
    String ae;
    int af;
    int ag;
    int ah;
    int ai;
    int aj;
    int ak;
    int[] al;
    String am;
    Thread an;
    DirectColorModel ao;
    MemoryImageSource ap;
    Image aq;
    int[] ar;
    int[] as;
    String at;
    int au;
    int av;
    int aw;
    int ax;
    int ay;
    int az;
    int aA;
    long aB;
    long aC;
    long aD;
    long aE;
    int aF;
    a aG;
    boolean aH;
    boolean aI;
    boolean aJ;
    boolean aK;
    boolean aL;
    boolean aM;
    boolean aN;
    boolean aO;
    boolean aP;
    int aQ;
    int aR;
    int aS;
    int aT;
    int aU;
    int aV;
    int aW;
    boolean[] aX;
    boolean[] aY;
    boolean[] aZ;
    byte[] ba;
    byte[] bb;
    byte[] bc;
    byte[] bd;
    byte[] be;
    byte[] bf;
    byte[] bg;
    byte[] bh;
    byte[] bi;
    String[] bj;
    float[] bk;
    int bl;
    int bm;
    float[][] bn;

    public final String a(String string) {
        if (string.length() == 0) {
            return "";
        }
        if (this.ab.length() != 0) {
            return "";
        }
        this.S.a();
        this.S.b();
        int n = 0;
        int n2 = 0;
        while (n2 < this.ac.length()) {
            n += this.ac.charAt(n2) * ((n2 & 0xFF) + 1);
            ++n2;
        }
        string = this.ac;
        string = String.valueOf(string) + (char)(97 + (n & 0xF));
        string = String.valueOf(string) + (char)(65 + ((n & 0xF0) >> 4));
        string = String.valueOf(string) + (char)(48 + ((n & 0x700) >> 8));
        return string;
    }

    public final int b(String string) {
        if (string.length() > 3) {
            int n = 0;
            int n2 = 0;
            while (n2 < string.length() - 3) {
                n += string.charAt(n2) * ((n2 & 0xFF) + 1);
                ++n2;
            }
            if ((n & 0xF) != string.charAt(string.length() - 3) - 97) {
                return -1;
            }
            if ((n & 0xF0) >> 4 != string.charAt(string.length() - 2) - 65) {
                return -1;
            }
            if ((n & 0x700) >> 8 != string.charAt(string.length() - 1) - 48) {
                return -1;
            }
            this.am = string.substring(0, string.length() - 3);
            return 0;
        }
        if (string.length() == 0 && this.am.length() != 0) {
            this.ac = this.am;
            this.am = "";
            this.S.c();
            this.S.d();
        }
        return -1;
    }

    final void a() {
        Object object;
        Object object2;
        boolean bl;
        dust dust2;
        String string;
        this.e();
        this.g();
        this.j();
        this.b(50);
        this.aG.a("font.gif", 8, 12);
        this.Z = this.getParameter("id");
        if (this.Z == null) {
            this.Z = "";
        }
        if ((string = this.getParameter("en")) == null) {
            string = "";
        }
        this.ab = this.getParameter("gd");
        if (this.ab == null) {
            this.ab = "";
        }
        if (string.equals("0")) {
            dust2 = this;
            bl = true;
        } else {
            dust2 = this;
            bl = dust2.aa = false;
        }
        if (this.Z.length() == 0) {
            this.af = 2;
            this.ah = 1;
        }
        if (this.ab.length() != 0) {
            this.af = 2;
            this.ah = 3;
        }
        this.S.a(0);
        this.s = new byte[120000];
        this.t = new byte[120000];
        this.X = new byte[120000];
        this.Y = new byte[120000];
        this.S.a();
        this.F.b("");
        this.G = new TextField("", 30);
        this.add(this.G);
        this.H = new TextField("", 10);
        this.add(this.H);
        if (this.ab.length() > 0) {
            try {
                object2 = new URL(this.ab);
                object = new BufferedReader(new InputStreamReader(((URL)object2).openStream()));
                this.ac = "";
                String string2 = null;
                while ((string2 = ((BufferedReader)object).readLine()) != null) {
                    this.ac = String.valueOf(this.ac) + string2;
                }
                ((BufferedReader)object).close();
            }
            catch (IOException iOException) {
                this.ag = 2;
                iOException.printStackTrace();
            }
            if (this.ag == 0) {
                this.S.c();
                this.S.d();
                this.ag = 1;
                this.w = 1;
            }
        }
        this.S.a();
        this.S.b();
        int n = 0;
        while (n < this.S.v.length) {
            int n2 = ((this.S.v[n][0] >> 16 & 0xFF) * 2989 + (this.S.v[n][0] >> 8 & 0xFF) * 5866 + (this.S.v[n][0] & 0xFF) * 1145) / 10000;
            this.S.w[n] = 0xFF000000 | n2 << 16 | n2 << 8 | n2;
            ++n;
        }
        this.b(0, 0, this.a, this.b, -12566464);
        object2 = new int[]{68, 65, 78, 45, 66, 65, 76, 76, 46, 106, 112, 32, 40, 67, 41, 32, 50, 48, 48, 55, 32, 104, 97, 53, 53, 105, 105};
        object = "";
        n = 0;
        while (n < ((Object)object2).length) {
            object = String.valueOf(object) + (char)object2[n];
            ++n;
        }
        this.aG.l = -1;
        this.aG.a(211, 451, (String)object, 0, 0, 0, 0, 0, 0, 0, 255);
        this.aG.l = 0;
        this.aG.a(16, 311, "POWDER", 242, 189, 107, 255, 0, 0, 0, 255);
        this.aG.a(16, 325, "WATER", 64, 64, 255, 255, 0, 0, 0, 255);
        this.aG.a(16, 339, "FIRE", 255, 64, 64, 255, 0, 0, 0, 255);
        this.aG.a(16, 353, "SEED", 144, 192, 64, 255, 0, 0, 0, 255);
        this.aG.l = -2;
        this.aG.a(16, 367, "G-POWDER", 176, 128, 80, 0, 0, 0, 0, 255);
        this.aG.a(16, 367, "G-POWDER", 176, 128, 80, 255, 0, 0, 0, 0);
        this.aG.l = 0;
        this.aG.a(16, 381, "FAN", 128, 128, 255, 255, 0, 0, 0, 255);
        this.aG.a(16, 395, "ICE", 208, 208, 255, 255, 0, 0, 0, 255);
        this.aG.a(16, 409, "S-BALL", 255, 64, 160, 255, 0, 0, 0, 255);
        this.aG.a(16, 423, "CLONE", 144, 112, 16, 255, 0, 0, 0, 255);
        this.aG.l = -1;
        this.aG.a(16, 437, "F-WORKS", 255, 153, 102, 255, 0, 0, 0, 255);
        this.aG.l = 0;
        this.aG.a(72, 311, "OIL", 128, 48, 32, 255, 0, 0, 0, 255);
        this.aG.a(72, 325, "C-4", 255, 255, 204, 255, 0, 0, 0, 255);
        this.aG.a(72, 339, "STONE", 128, 128, 128, 255, 0, 0, 0, 255);
        this.aG.a(72, 353, "MAGMA", 255, 102, 51, 255, 0, 0, 0, 255);
        this.aG.a(72, 367, "VIRUS", 128, 0, 128, 255, 0, 0, 0, 255);
        this.aG.a(72, 381, "NITRO", 68, 119, 0, 255, 0, 0, 0, 255);
        this.aG.a(72, 395, "ANT", 192, 128, 192, 255, 0, 0, 0, 255);
        this.aG.a(72, 409, "TORCH", 255, 160, 32, 255, 0, 0, 0, 255);
        this.aG.a(72, 423, "GAS", 204, 153, 153, 255, 0, 0, 0, 255);
        this.aG.a(72, 437, "SOAPY", 224, 224, 224, 255, 0, 0, 0, 255);
        this.aG.l = -1;
        this.aG.a(128, 311, "THUNDER", 255, 255, 32, 255, 0, 0, 0, 255);
        this.aG.l = 0;
        this.aG.a(128, 325, "METAL", 65, 65, 65, 255, 0, 0, 0, 255);
        this.aG.a(128, 339, "BOMB", 102, 102, 0, 255, 0, 0, 0, 255);
        this.aG.a(128, 353, "LASER", 204, 0, 0, 255, 0, 0, 0, 255);
        this.aG.a(128, 367, "ACID", 204, 255, 0, 255, 0, 0, 0, 255);
        this.aG.a(128, 381, "VINE", 0, 187, 0, 255, 0, 0, 0, 255);
        this.aG.a(128, 395, "SALT", 255, 255, 255, 255, 0, 0, 0, 255);
        this.aG.a(128, 409, "GLASS", 64, 64, 64, 255, 0, 0, 0, 255);
        this.aG.a(128, 423, "BIRD", 128, 112, 80, 255, 0, 0, 0, 255);
        this.aG.l = -1;
        this.aG.a(128, 437, "MERCURY", 170, 170, 170, 255, 0, 0, 0, 255);
        this.aG.l = 0;
        this.aG.a(184, 311, "SPARK", 255, 204, 51, 255, 0, 0, 0, 255);
        this.aG.a(184, 325, "FUSE", 68, 51, 34, 255, 0, 0, 0, 255);
        this.aG.a(184, 339, "CLOUD", 204, 204, 204, 255, 0, 0, 0, 255);
        this.aG.a(184, 353, "PUMP", 0, 51, 51, 255, 0, 0, 0, 255);
        this.aG.a(240, 311, "WIND", 128, 128, 255, 255, 0, 0, 0, 255);
        this.aG.a(240, 325, "AIR", 128, 128, 255, 255, 0, 0, 0, 255);
        this.aG.a(240, 339, "DRAG", 255, 255, 255, 255, 0, 0, 0, 255);
        this.aG.a(240, 353, "B", 255, 224, 224, 255, 0, 0, 0, 255);
        this.aG.a(240, 353, " U", 255, 255, 224, 255, 0, 0, 0, 255);
        this.aG.a(240, 353, "  B", 224, 255, 224, 255, 0, 0, 0, 255);
        this.aG.a(240, 353, "   B", 224, 255, 255, 255, 0, 0, 0, 255);
        this.aG.a(240, 353, "    L", 224, 224, 255, 255, 0, 0, 0, 255);
        this.aG.a(240, 353, "     E", 255, 224, 255, 255, 0, 0, 0, 255);
        this.aG.a(240, 367, "WHEEL", 176, 160, 144, 255, 0, 0, 0, 255);
        this.aG.a(240, 381, "PLAYER", 242, 189, 107, 255, 0, 0, 0, 255);
        this.aG.l = -1;
        this.aG.a(240, 395, "FIGHTER", 242, 189, 107, 255, 0, 0, 0, 255);
        this.aG.l = 0;
        this.aG.a(240, 409, "BOX", 242, 189, 107, 255, 0, 0, 0, 255);
        this.aG.a(240, 423, "BALL", 242, 189, 107, 255, 0, 0, 0, 255);
        this.aG.a(240, 437, "CREATE", 144, 112, 16, 255, 0, 0, 0, 255);
        this.aG.a(296, 311, "BLOCK", 128, 128, 128, 255, 0, 0, 0, 255);
        this.aG.a(296, 325, "ERASE", 128, 128, 128, 255, 0, 0, 0, 255);
        this.aG.a(296, 339, "CLEAR", 255, 255, 255, 255, 0, 0, 0, 255);
        this.aG.l = -2;
        this.aG.a(295, 353, "Copy", 255, 255, 255, 0, 0, 0, 0, 255);
        this.aG.a(295, 353, "Copy", 255, 255, 255, 255, 0, 0, 0, 0);
        this.aG.l = -3;
        this.aG.a(319, 353, "Paste", 255, 255, 255, 0, 0, 0, 0, 255);
        this.aG.a(319, 353, "Paste", 255, 255, 255, 255, 0, 0, 0, 0);
        this.aG.l = 0;
        this.aG.a(296, 367, "TEXT", 255, 255, 255, 255, 0, 0, 0, 255);
        this.aG.l = -1;
        this.aG.a(296, 381, "PEN", 255, 255, 255, 0, 0, 0, 0, 255);
        this.aG.a(296, 381, "PEN", 255, 255, 255, 255, 0, 0, 0, 0);
        this.aG.l = 0;
        this.aG.l = -1;
        this.aG.a(296, 395, "PEN-S ", 255, 255, 255, 255, 0, 0, 0, 255);
        this.aG.l = 0;
        this.aG.l = -1;
        this.aG.a(296, 409, "SCALE", 255, 255, 255, 255, 0, 0, 0, 255);
        this.aG.l = 0;
        this.aG.l = -1;
        this.aG.a(296, 423, "SPEEDx", 255, 255, 255, 255, 0, 0, 0, 255);
        this.aG.l = 0;
        this.aG.l = -3;
        this.aG.a(295, 437, "Start", 255, 255, 255, 0, 0, 0, 0, 255);
        this.aG.a(295, 437, "Start", 255, 255, 255, 255, 0, 0, 0, 0);
        this.aG.l = -2;
        this.aG.a(321, 437, "Stop", 255, 255, 255, 0, 0, 0, 0, 255);
        this.aG.a(321, 437, "Stop", 255, 255, 255, 255, 0, 0, 0, 0);
        this.aG.l = 0;
        this.aG.a(352, 311, "UPLOAD", 255, 160, 160, 255, 0, 0, 0, 255);
        this.aG.a(352, 325, "SAVE", 255, 160, 160, 255, 0, 0, 0, 255);
        this.aG.a(352, 339, "LOAD", 255, 160, 160, 255, 0, 0, 0, 255);
        this.aG.l = -1;
        this.aG.a(352, 353, "MiniMap", 255, 160, 160, 255, 0, 0, 0, 255);
        this.aG.l = 0;
        this.aG.l = -2;
        this.aG.a(352, 367, "MENU-", 255, 255, 255, 0, 0, 0, 0, 255);
        this.aG.a(352, 367, "MENU-", 255, 255, 255, 255, 0, 0, 0, 0);
        this.aG.l = 0;
        this.aG.l = -3;
        this.aG.a(352, 381, "SIDE-", 255, 255, 255, 0, 0, 0, 0, 255);
        this.aG.a(352, 381, "SIDE-", 255, 255, 255, 255, 0, 0, 0, 0);
        this.aG.l = 0;
        this.aG.a(352, 395, "GRID", 128, 0, 0, 255, 0, 0, 0, 255);
        this.aG.l = -2;
        this.aG.a(352, 409, "BG-", 255, 255, 255, 0, 0, 0, 0, 255);
        this.aG.a(352, 409, "BG-", 255, 255, 255, 255, 0, 0, 0, 0);
        this.aG.l = 0;
        this.aG.a(352, 423, "DOT ", 255, 255, 255, 255, 0, 0, 0, 255);
        this.aG.a(352, 437, "RESET", 255, 255, 255, 255, 0, 0, 0, 255);
        this.aG.l = -1;
        this.aG.a(64, 451, "x    y", 0, 0, 0, 0, 0, 0, 0, 255);
        this.aG.a(141, 451, "dot", 0, 0, 0, 0, 0, 0, 0, 255);
        this.aG.l = 0;
        this.c();
        this.T.a(this.a, this.b);
        n = 0;
        while (n < this.a * this.b) {
            this.T.f[n] = this.ar[n];
            ++n;
        }
        this.a(-16777216);
    }

    /*
     * Unable to fully structure code
     * Could not resolve type clashes
     */
    final void b() {
        block227: {
            block232: {
                block235: {
                    block234: {
                        block233: {
                            block228: {
                                block231: {
                                    block230: {
                                        block229: {
                                            block226: {
                                                block225: {
                                                    block224: {
                                                        block223: {
                                                            block218: {
                                                                block198: {
                                                                    block199: {
                                                                        block201: {
                                                                            block217: {
                                                                                block216: {
                                                                                    block215: {
                                                                                        block214: {
                                                                                            block213: {
                                                                                                block212: {
                                                                                                    block211: {
                                                                                                        block210: {
                                                                                                            block209: {
                                                                                                                block208: {
                                                                                                                    block207: {
                                                                                                                        block206: {
                                                                                                                            block205: {
                                                                                                                                block204: {
                                                                                                                                    block203: {
                                                                                                                                        block202: {
                                                                                                                                            block200: {
                                                                                                                                                block192: {
                                                                                                                                                    block191: {
                                                                                                                                                        block190: {
                                                                                                                                                            block189: {
                                                                                                                                                                this.f();
                                                                                                                                                                this.h();
                                                                                                                                                                this.k();
                                                                                                                                                                this.a("");
                                                                                                                                                                this.b("");
                                                                                                                                                                this.S.e();
                                                                                                                                                                this.S.f();
                                                                                                                                                                var10_1 = this.aR;
                                                                                                                                                                var11_2 = this.aS;
                                                                                                                                                                if (var11_2 < 300 || !this.aP || this.e) break block189;
                                                                                                                                                                v0 = this;
                                                                                                                                                                v1 = true;
                                                                                                                                                                break block190;
                                                                                                                                                            }
                                                                                                                                                            if (var11_2 >= 300 || !this.e) break block191;
                                                                                                                                                            v0 = this;
                                                                                                                                                            v1 = false;
                                                                                                                                                        }
                                                                                                                                                        v0.e = v1;
                                                                                                                                                    }
                                                                                                                                                    var4_3 = 0;
                                                                                                                                                    var1_4 = this.a * 308;
                                                                                                                                                    var9_5 = this.a * this.b;
                                                                                                                                                    while (var1_4 < var9_5) {
                                                                                                                                                        this.ar[var1_4] = this.T.f[var1_4];
                                                                                                                                                        ++var1_4;
                                                                                                                                                    }
                                                                                                                                                    if (this.D != 1) break block192;
                                                                                                                                                    this.b(24, 311, 48, 137, -12566464);
                                                                                                                                                    this.b(80, 311, 48, 137, -12566464);
                                                                                                                                                    this.b(136, 311, 48, 137, -12566464);
                                                                                                                                                    this.b(192, 311, 48, 53, -12566464);
                                                                                                                                                    this.b(248, 353, 47, 53, -12566464);
                                                                                                                                                    this.b(256, 409, 39, 25, -12566464);
                                                                                                                                                    this.b(248, 437, 47, 11, -12566464);
                                                                                                                                                    this.b(135, 315, 1, 7, -12566464);
                                                                                                                                                    var12_6 /* !! */  = (String[])new int[48];
                                                                                                                                                    var1_4 = 0;
                                                                                                                                                    while (var1_4 < var12_6 /* !! */ .length) {
                                                                                                                                                        var12_6 /* !! */ [var1_4] = (String)false;
                                                                                                                                                        ++var1_4;
                                                                                                                                                    }
                                                                                                                                                    var1_4 = 0;
                                                                                                                                                    while (var1_4 < this.S.D) {
                                                                                                                                                        v2 = this.S.A[var1_4];
                                                                                                                                                        var12_6 /* !! */ [v2] = var12_6 /* !! */ [v2] + true;
                                                                                                                                                        ++var1_4;
                                                                                                                                                    }
                                                                                                                                                    this.aG.l = -1;
                                                                                                                                                    this.aG.a(16, 311, "  " + (int)var12_6 /* !! */ [2], 242, 189, 107, 255, 0, 0, 0, 255);
                                                                                                                                                    this.aG.a(16, 325, "  " + (int)var12_6 /* !! */ [3], 64, 64, 255, 255, 0, 0, 0, 255);
                                                                                                                                                    this.aG.a(16, 339, "  " + (int)var12_6 /* !! */ [4], 255, 64, 64, 255, 0, 0, 0, 255);
                                                                                                                                                    this.aG.a(16, 353, "  " + (int)var12_6 /* !! */ [5], 144, 192, 64, 255, 0, 0, 0, 255);
                                                                                                                                                    this.aG.a(16, 367, "  " + (int)var12_6 /* !! */ [7], 176, 128, 80, 255, 0, 0, 0, 255);
                                                                                                                                                    this.aG.a(16, 381, "  " + (int)var12_6 /* !! */ [8], 128, 128, 255, 255, 0, 0, 0, 255);
                                                                                                                                                    this.aG.a(16, 395, "  " + (int)var12_6 /* !! */ [10], 208, 208, 255, 255, 0, 0, 0, 255);
                                                                                                                                                    this.aG.a(16, 409, "  " + (int)var12_6 /* !! */ [13], 255, 64, 160, 255, 0, 0, 0, 255);
                                                                                                                                                    this.aG.a(16, 423, "  " + (int)var12_6 /* !! */ [14], 144, 112, 16, 255, 0, 0, 0, 255);
                                                                                                                                                    this.aG.a(16, 437, "  " + (int)var12_6 /* !! */ [15], 255, 153, 102, 255, 0, 0, 0, 255);
                                                                                                                                                    this.aG.a(72, 311, "  " + (int)var12_6 /* !! */ [16], 128, 48, 32, 255, 0, 0, 0, 255);
                                                                                                                                                    this.aG.a(72, 325, "  " + (int)var12_6 /* !! */ [17], 255, 255, 204, 255, 0, 0, 0, 255);
                                                                                                                                                    this.aG.a(72, 339, "  " + (int)var12_6 /* !! */ [19], 128, 128, 128, 255, 0, 0, 0, 255);
                                                                                                                                                    this.aG.a(72, 353, "  " + (int)var12_6 /* !! */ [20], 255, 102, 51, 255, 0, 0, 0, 255);
                                                                                                                                                    this.aG.a(72, 367, "  " + (int)var12_6 /* !! */ [21], 128, 0, 128, 255, 0, 0, 0, 255);
                                                                                                                                                    this.aG.a(72, 381, "  " + (int)var12_6 /* !! */ [23], 68, 119, 0, 255, 0, 0, 0, 255);
                                                                                                                                                    this.aG.a(72, 395, "  " + (int)var12_6 /* !! */ [24], 192, 128, 192, 255, 0, 0, 0, 255);
                                                                                                                                                    this.aG.a(72, 409, "  " + (int)var12_6 /* !! */ [25], 255, 160, 32, 255, 0, 0, 0, 255);
                                                                                                                                                    this.aG.a(72, 423, "  " + (int)var12_6 /* !! */ [26], 204, 153, 153, 255, 0, 0, 0, 255);
                                                                                                                                                    this.aG.a(72, 437, "  " + (int)var12_6 /* !! */ [27], 224, 224, 224, 255, 0, 0, 0, 255);
                                                                                                                                                    this.aG.a(128, 311, "  " + (int)var12_6 /* !! */ [28], 255, 255, 32, 255, 0, 0, 0, 255);
                                                                                                                                                    this.aG.a(128, 325, "  " + (int)var12_6 /* !! */ [29], 65, 65, 65, 255, 0, 0, 0, 255);
                                                                                                                                                    this.aG.a(128, 339, "  " + (int)var12_6 /* !! */ [31], 102, 102, 0, 255, 0, 0, 0, 255);
                                                                                                                                                    this.aG.a(128, 353, "  " + (int)var12_6 /* !! */ [33], 204, 0, 0, 255, 0, 0, 0, 255);
                                                                                                                                                    this.aG.a(128, 367, "  " + (int)var12_6 /* !! */ [34], 204, 255, 0, 255, 0, 0, 0, 255);
                                                                                                                                                    this.aG.a(128, 381, "  " + (int)var12_6 /* !! */ [35], 0, 187, 0, 255, 0, 0, 0, 255);
                                                                                                                                                    this.aG.a(128, 395, "  " + (int)var12_6 /* !! */ [36], 255, 255, 255, 255, 0, 0, 0, 255);
                                                                                                                                                    this.aG.a(128, 409, "  " + (int)var12_6 /* !! */ [38], 64, 64, 64, 255, 0, 0, 0, 255);
                                                                                                                                                    this.aG.a(128, 423, "  " + (int)var12_6 /* !! */ [39], 128, 112, 80, 255, 0, 0, 0, 255);
                                                                                                                                                    this.aG.a(128, 437, "  " + (int)var12_6 /* !! */ [41], 170, 170, 170, 255, 0, 0, 0, 255);
                                                                                                                                                    this.aG.a(184, 311, "  " + (int)var12_6 /* !! */ [42], 255, 204, 51, 255, 0, 0, 0, 255);
                                                                                                                                                    this.aG.a(184, 325, "  " + (int)var12_6 /* !! */ [43], 68, 51, 34, 255, 0, 0, 0, 255);
                                                                                                                                                    this.aG.a(184, 339, "  " + (int)var12_6 /* !! */ [44], 204, 204, 204, 255, 0, 0, 0, 255);
                                                                                                                                                    this.aG.a(184, 353, "  " + (int)var12_6 /* !! */ [45], 0, 51, 51, 255, 0, 0, 0, 255);
                                                                                                                                                    this.aG.a(240, 353, "  " + (int)var12_6 /* !! */ [12], 255, 224, 224, 255, 0, 0, 0, 255);
                                                                                                                                                    this.aG.a(240, 367, "  " + this.S.V, 176, 160, 144, 255, 0, 0, 0, 255);
                                                                                                                                                    var1_4 = 0;
                                                                                                                                                    while (var1_4 < 5) {
                                                                                                                                                        var12_6 /* !! */ [var1_4] = (String)false;
                                                                                                                                                        ++var1_4;
                                                                                                                                                    }
                                                                                                                                                    var1_4 = 0;
                                                                                                                                                    while (var1_4 < this.S.at) {
                                                                                                                                                        block197: {
                                                                                                                                                            block194: {
                                                                                                                                                                block196: {
                                                                                                                                                                    block195: {
                                                                                                                                                                        block193: {
                                                                                                                                                                            if (this.S.ao[var1_4] < 40) break block193;
                                                                                                                                                                            v3 /* !! */  = var12_6 /* !! */ ;
                                                                                                                                                                            v4 = 4;
                                                                                                                                                                            break block194;
                                                                                                                                                                        }
                                                                                                                                                                        if (this.S.ao[var1_4] < 30) break block195;
                                                                                                                                                                        v3 /* !! */  = var12_6 /* !! */ ;
                                                                                                                                                                        v4 = 2;
                                                                                                                                                                        break block194;
                                                                                                                                                                    }
                                                                                                                                                                    if (this.S.ao[var1_4] < 20) break block196;
                                                                                                                                                                    v3 /* !! */  = var12_6 /* !! */ ;
                                                                                                                                                                    v4 = 1;
                                                                                                                                                                    break block194;
                                                                                                                                                                }
                                                                                                                                                                if (this.S.ao[var1_4] < 10) break block197;
                                                                                                                                                                v3 /* !! */  = var12_6 /* !! */ ;
                                                                                                                                                                v4 = 0;
                                                                                                                                                            }
                                                                                                                                                            v3 /* !! */ [v4] = v3 /* !! */ [v4] + true;
                                                                                                                                                        }
                                                                                                                                                        ++var1_4;
                                                                                                                                                    }
                                                                                                                                                    this.aG.a(240, 381, "  " + (int)var12_6 /* !! */ [2], 242, 189, 107, 255, 0, 0, 0, 255);
                                                                                                                                                    this.aG.a(240, 395, "  " + (int)var12_6 /* !! */ [0], 242, 189, 107, 255, 0, 0, 0, 255);
                                                                                                                                                    this.aG.a(240, 409, "   " + (int)var12_6 /* !! */ [1], 242, 189, 107, 255, 0, 0, 0, 255);
                                                                                                                                                    var1_4 = 0;
                                                                                                                                                    while (var1_4 < this.S.aH) {
                                                                                                                                                        if (this.S.aD[var1_4] != 0) {
                                                                                                                                                            var12_6 /* !! */ [3] = var12_6 /* !! */ [3] + true;
                                                                                                                                                        }
                                                                                                                                                        ++var1_4;
                                                                                                                                                    }
                                                                                                                                                    this.aG.a(240, 423, "   " + (int)var12_6 /* !! */ [3], 242, 189, 107, 255, 0, 0, 0, 255);
                                                                                                                                                    this.aG.a(240, 437, "  " + (int)var12_6 /* !! */ [4], 144, 112, 16, 255, 0, 0, 0, 255);
                                                                                                                                                    this.aG.l = 0;
                                                                                                                                                }
                                                                                                                                                if (this.aP && this.u == 0) {
                                                                                                                                                    if (this.aX[48]) {
                                                                                                                                                        this.f = 0;
                                                                                                                                                    } else if (this.aX[49]) {
                                                                                                                                                        this.f = 1;
                                                                                                                                                    } else if (this.aX[50]) {
                                                                                                                                                        this.f = 2;
                                                                                                                                                    } else if (this.aX[51]) {
                                                                                                                                                        this.f = 3;
                                                                                                                                                    } else if (this.aX[52]) {
                                                                                                                                                        this.f = 4;
                                                                                                                                                    } else if (this.aX[53]) {
                                                                                                                                                        this.f = 5;
                                                                                                                                                    } else if (this.aX[54]) {
                                                                                                                                                        this.f = 6;
                                                                                                                                                    } else if (this.aX[55]) {
                                                                                                                                                        this.f = 7;
                                                                                                                                                    } else if (this.aX[56]) {
                                                                                                                                                        this.f = 8;
                                                                                                                                                    } else if (this.aX[57]) {
                                                                                                                                                        this.f = 9;
                                                                                                                                                    } else if (this.aX[32]) {
                                                                                                                                                        this.w = dust.b(this.w + 1, 0, 1);
                                                                                                                                                    } else if (this.aX[10] || this.aX[13]) {
                                                                                                                                                        this.w = 1;
                                                                                                                                                    } else if (this.aX[108]) {
                                                                                                                                                        this.S.c();
                                                                                                                                                        this.S.d();
                                                                                                                                                        this.i = -10;
                                                                                                                                                    }
                                                                                                                                                }
                                                                                                                                                if (!this.a(4, 303, 391, 139) || !this.e || this.u != 0) break block198;
                                                                                                                                                var2_8 = (var10_1 - 4) / 56;
                                                                                                                                                var3_9 = (var11_2 - 303) / 14;
                                                                                                                                                var12_7 = var2_8 * 10 + var3_9;
                                                                                                                                                if ((var12_7 = dust.a(var12_7, 0, 69)) == 34 || var12_7 == 35 || var12_7 == 36 || var12_7 == 37 || var12_7 == 38 || var12_7 == 39) break block199;
                                                                                                                                                if (var12_7 != 53) break block200;
                                                                                                                                                if (this.aH) {
                                                                                                                                                    if (this.c == 53) {
                                                                                                                                                        this.n = 1 - this.n;
                                                                                                                                                    }
                                                                                                                                                    this.c = var12_7;
                                                                                                                                                }
                                                                                                                                                if (!this.aL) break block199;
                                                                                                                                                if (this.d == 53) {
                                                                                                                                                    this.n = 1 - this.n;
                                                                                                                                                }
                                                                                                                                                v5 = this;
                                                                                                                                                break block201;
                                                                                                                                            }
                                                                                                                                            if (var12_7 != 55) break block202;
                                                                                                                                            this.z = dust.b(this.z + this.aQ, 0, 3);
                                                                                                                                            break block199;
                                                                                                                                        }
                                                                                                                                        if (var12_7 != 56) break block203;
                                                                                                                                        this.f = dust.b(this.f + this.aQ, 0, 9);
                                                                                                                                        break block199;
                                                                                                                                    }
                                                                                                                                    if (var12_7 != 57) break block204;
                                                                                                                                    if (this.aH) {
                                                                                                                                        if (this.c == 57 && this.k < 4) {
                                                                                                                                            ++this.k;
                                                                                                                                            this.l += (float)(400 >> this.k >> 1);
                                                                                                                                            this.m += (float)(300 >> this.k >> 1);
                                                                                                                                        } else if (this.c == 57) {
                                                                                                                                            this.k = 0;
                                                                                                                                        }
                                                                                                                                        this.c = var12_7;
                                                                                                                                    } else if (this.aL) {
                                                                                                                                        if (this.d == 57 && this.k > 0) {
                                                                                                                                            this.l -= (float)(400 >> this.k >> 1);
                                                                                                                                            this.m -= (float)(300 >> this.k >> 1);
                                                                                                                                            --this.k;
                                                                                                                                        } else if (this.d == 57) {
                                                                                                                                            this.k = 4;
                                                                                                                                            this.l += (float)(200 - (400 >> this.k >> 1));
                                                                                                                                            this.m += (float)(150 - (300 >> this.k >> 1));
                                                                                                                                        }
                                                                                                                                        this.d = var12_7;
                                                                                                                                    }
                                                                                                                                    var13_10 /* !! */  = new int[]{300, 150, 75, 38, 19};
                                                                                                                                    this.l = dust.a(this.l, 0.0f, (float)(400 - (400 >> this.k)));
                                                                                                                                    this.m = dust.a(this.m, 0.0f, (float)(300 - var13_10 /* !! */ [this.k]));
                                                                                                                                    break block199;
                                                                                                                                }
                                                                                                                                if (var12_7 != 58) break block205;
                                                                                                                                this.x = dust.b(this.x + this.aQ, 0, 3);
                                                                                                                                break block199;
                                                                                                                            }
                                                                                                                            if (var12_7 != 59) break block206;
                                                                                                                            this.w = dust.b(this.w + this.aQ, 0, 1);
                                                                                                                            break block199;
                                                                                                                        }
                                                                                                                        if (var12_7 != 60) break block207;
                                                                                                                        if (this.aQ != 0) {
                                                                                                                            this.u = 1;
                                                                                                                        }
                                                                                                                        break block199;
                                                                                                                    }
                                                                                                                    if (var12_7 != 61) break block208;
                                                                                                                    if (this.aH || this.aL) {
                                                                                                                        this.S.a();
                                                                                                                        this.S.b();
                                                                                                                        this.i = 10;
                                                                                                                    }
                                                                                                                    break block199;
                                                                                                                }
                                                                                                                if (var12_7 != 62) break block209;
                                                                                                                if (this.aQ != 0) {
                                                                                                                    this.S.c();
                                                                                                                    this.S.d();
                                                                                                                    this.i = -10;
                                                                                                                }
                                                                                                                break block199;
                                                                                                            }
                                                                                                            if (var12_7 != 63) break block210;
                                                                                                            this.E = dust.b(this.E + this.aQ, 0, 1);
                                                                                                            break block199;
                                                                                                        }
                                                                                                        if (var12_7 != 64) break block211;
                                                                                                        this.D = dust.b(this.D + this.aQ, 0, 1);
                                                                                                        break block199;
                                                                                                    }
                                                                                                    if (var12_7 != 65) break block212;
                                                                                                    this.y = dust.b(this.y + this.aQ, 0, 1);
                                                                                                    break block199;
                                                                                                }
                                                                                                if (var12_7 != 66) break block213;
                                                                                                this.v = dust.b(this.v + this.aQ, 0, 7);
                                                                                                break block199;
                                                                                            }
                                                                                            if (var12_7 != 67) break block214;
                                                                                            this.j = dust.b(this.j + this.aQ, 0, 13);
                                                                                            if (this.aQ != 0) {
                                                                                                var1_4 = this.a * 309 - 1;
                                                                                                while (var1_4 >= 0) {
                                                                                                    this.P[var1_4] = 0;
                                                                                                    this.Q[var1_4] = 0;
                                                                                                    this.R[var1_4] = 0;
                                                                                                    --var1_4;
                                                                                                }
                                                                                            }
                                                                                            break block199;
                                                                                        }
                                                                                        if (var12_7 != 68) break block215;
                                                                                        this.g = dust.b(this.g + this.aQ, 0, 2);
                                                                                        break block199;
                                                                                    }
                                                                                    if (var12_7 != 69) break block216;
                                                                                    if (this.aQ != 0) {
                                                                                        this.S.a(0);
                                                                                    }
                                                                                    break block199;
                                                                                }
                                                                                if (!this.aH) break block217;
                                                                                this.c = var12_7;
                                                                                break block199;
                                                                            }
                                                                            if (!this.aL) break block199;
                                                                            v5 = this;
                                                                        }
                                                                        v5.d = var12_7;
                                                                    }
                                                                    this.a(12 + var2_8 * 56, 310 + var3_9 * 14, 56, 13, -12566464, -12582912);
                                                                }
                                                                if (this.e) {
                                                                    this.a(8, 308, 408, 308, -10092544);
                                                                }
                                                                if (this.n == 0) {
                                                                    this.aG.l = -2;
                                                                    v6 = this.aG;
                                                                    v7 = 295;
                                                                    v8 = 353;
                                                                    v9 = "Copy";
                                                                } else {
                                                                    this.aG.l = -3;
                                                                    v6 = this.aG;
                                                                    v7 = 319;
                                                                    v8 = 353;
                                                                    v9 = "Paste";
                                                                }
                                                                v6.a(v7, v8, v9, 255, 64, 64, 255, 0, 0, 0, 0);
                                                                this.aG.l = 0;
                                                                var12_6 /* !! */  = new String[]{"free", "line", "lock", "paint"};
                                                                this.aG.l = -2;
                                                                this.aG.a(296, 381, "    " + var12_6 /* !! */ [this.z], 255, 255, 255, 0, 0, 0, 0, 255);
                                                                this.aG.a(296, 381, "    " + var12_6 /* !! */ [this.z], 255, 255, 255, 255, 0, 0, 0, 0);
                                                                this.aG.l = 0;
                                                                this.aG.l = -1;
                                                                this.aG.a(295, 395, "      " + this.f, 255, 255, 255, 255, 0, 0, 0, 255);
                                                                this.aG.l = 0;
                                                                var13_10 /* !! */  = (int[])new String[]{"x1", "x2", "x4", "x8", "16"};
                                                                this.aG.l = -2;
                                                                this.aG.a(296, 409, "      " + (String)var13_10 /* !! */ [this.k], 255, 255, 255, 255, 0, 0, 0, 255);
                                                                this.aG.l = 0;
                                                                this.aG.l = -2;
                                                                this.aG.a(296, 423, "       " + (1 << this.x), 255, 255, 255, 255, 0, 0, 0, 255);
                                                                this.aG.l = 0;
                                                                if (this.w == 0) {
                                                                    this.aG.l = -3;
                                                                    v10 = this.aG;
                                                                    v11 = 295;
                                                                    v12 = 437;
                                                                    v13 = "Start";
                                                                } else {
                                                                    this.aG.l = -2;
                                                                    v10 = this.aG;
                                                                    v11 = 321;
                                                                    v12 = 437;
                                                                    v13 = "Stop";
                                                                }
                                                                v10.a(v11, v12, v13, 255, 64, 64, 255, 0, 0, 0, 0);
                                                                this.aG.l = 0;
                                                                if (this.i > 0) {
                                                                    --this.i;
                                                                    if (this.i > 1) {
                                                                        this.aG.a(352, 325, "SAVE", 255, 255, 255, 255, 255, 0, 0, 255);
                                                                    }
                                                                }
                                                                if (this.i < 0) {
                                                                    ++this.i;
                                                                    if (this.i < -1) {
                                                                        this.aG.a(352, 339, "LOAD", 255, 255, 255, 255, 255, 0, 0, 255);
                                                                    }
                                                                }
                                                                if (this.E == 1) {
                                                                    this.aG.l = -1;
                                                                    this.aG.a(352, 353, "MiniMap", 255, 255, 255, 255, 255, 0, 0, 255);
                                                                    this.aG.l = 0;
                                                                }
                                                                var14_11 = new String[]{"str", "num"};
                                                                this.aG.l = -2;
                                                                this.aG.a(352, 367, "     " + var14_11[this.D], 255, 255, 255, 0, 0, 0, 0, 255);
                                                                this.aG.a(352, 367, "     " + var14_11[this.D], 255, 255, 255, 255, 0, 0, 0, 0);
                                                                this.aG.l = 0;
                                                                var15_12 = new String[]{"OFF", "LOOP"};
                                                                this.aG.l = -2;
                                                                this.aG.a(377, 381, var15_12[this.y], 255, 255, 255, 0, 0, 0, 0, 255);
                                                                this.aG.a(377, 381, var15_12[this.y], 255, 255, 255, 255, 0, 0, 0, 0);
                                                                this.aG.l = 0;
                                                                this.aG.a(352, 395, "     " + this.v, 128, 0, 0, 255, 0, 0, 0, 255);
                                                                var16_13 = new String[]{"non", "air", "line", "blur", "shade", "aura", "light", "toon", "mesh", "gray", "track", "dark", "TG", "siluet"};
                                                                this.aG.l = -2;
                                                                this.aG.a(352, 409, "   " + var16_13[this.j], 255, 255, 255, 0, 0, 0, 0, 255);
                                                                this.aG.a(352, 409, "   " + var16_13[this.j], 255, 255, 255, 255, 0, 0, 0, 0);
                                                                this.aG.l = 0;
                                                                var17_14 = new String[]{"S", "M", "L"};
                                                                this.aG.a(352, 423, "    " + var17_14[this.g], 255, 255, 255, 255, 0, 0, 0, 255);
                                                                this.b(12 + this.c / 10 * 56, 312 + this.c % 10 * 14, 3, 4, -65536);
                                                                this.b(12 + this.d / 10 * 56, 317 + this.d % 10 * 14, 3, 4, -16776961);
                                                                this.aG.l = -1;
                                                                this.aG.a(64, 451, " " + (this.S.m - 8), 0, 0, 0, 0, 0, 0, 0, 255);
                                                                this.aG.a(64, 451, "      " + (this.S.n - 8), 0, 0, 0, 0, 0, 0, 0, 255);
                                                                this.aG.a(141, 451, "   " + (this.h[this.g] - this.S.D), 0, 0, 0, 0, 0, 0, 0, 255);
                                                                this.a(16, 451, 0, 0, 0, 0, 0, 0, 0, 255);
                                                                this.aG.l = 0;
                                                                if (this.E != 1) break block218;
                                                                var4_3 = 15;
                                                                if (this.aR < 116 && this.e) {
                                                                    var4_3 = 127;
                                                                }
                                                                this.b(var4_3 - 3, 311, 106, 81, -8355712);
                                                                this.S.a();
                                                                var18_15 = 0;
                                                                var19_24 = this.a * 314 + var4_3;
                                                                var3_9 = 0;
                                                                while (var3_9 < 300) {
                                                                    var2_8 = 0;
                                                                    while (var2_8 < 400) {
                                                                        block222: {
                                                                            block221: {
                                                                                block219: {
                                                                                    block220: {
                                                                                        var20_29 = var3_9 * 400 + var2_8;
                                                                                        if (this.X[var20_29] == 0) {
                                                                                            var20_29 += 401;
                                                                                        }
                                                                                        if (this.j != 11) break block219;
                                                                                        if (this.X[var20_29] != 4 && this.X[var20_29] != 20 && this.X[var20_29] != 25 && this.X[var20_29] != 28 && this.X[var20_29] != 33 && this.X[var20_29] != 42) break block220;
                                                                                        v14 = this;
                                                                                        ** GOTO lbl408
                                                                                    }
                                                                                    v15 = 0;
                                                                                    break block221;
                                                                                }
                                                                                if (this.j == 13) {
                                                                                    var18_15 = this.X[var20_29] == 0 ? 0 : 1;
                                                                                } else {
                                                                                    v14 = this;
lbl408:
                                                                                    // 2 sources

                                                                                    v15 = var18_15 = v14.X[var20_29];
                                                                                }
                                                                            }
                                                                            if (this.j != 9) break block222;
                                                                            v16 = this.ar;
                                                                            v17 = var19_24;
                                                                            v18 = this.S.w;
                                                                            v19 = var18_15;
                                                                            ** GOTO lbl424
                                                                        }
                                                                        if (this.j == 13) {
                                                                            this.ar[var19_24] = var18_15 == 0 ? -1 : -16777216;
                                                                        } else {
                                                                            v16 = this.ar;
                                                                            v17 = var19_24;
                                                                            v18 = this.S.v[var18_15];
                                                                            v19 = 0;
lbl424:
                                                                            // 2 sources

                                                                            v16[v17] = v18[v19];
                                                                        }
                                                                        var2_8 += 4;
                                                                        ++var19_24;
                                                                    }
                                                                    var3_9 += 4;
                                                                    var19_24 += this.a - 100;
                                                                }
                                                            }
                                                            if (this.u == -1) {
                                                                this.G.setVisible(false);
                                                                this.H.setVisible(false);
                                                                this.requestFocus();
                                                                ++this.u;
                                                            }
                                                            if (this.ag != 1) break block223;
                                                            if (this.aa) {
                                                                v20 = this.F;
                                                                v21 = "\u30af\u30ea\u30c3\u30af\u3067\u518d\u751f\u3001\uff2c\uff2f\uff21\uff24\u3067\u518d\u30b9\u30bf\u30fc\u30c8";
                                                            } else {
                                                                v20 = this.F;
                                                                v21 = "Click to play, LOAD to restart.";
                                                            }
                                                            v20.b(v21);
                                                            v22 = this;
                                                            break block224;
                                                        }
                                                        if (this.ag != 2) break block225;
                                                        if (this.aa) {
                                                            v23 = this.F;
                                                            v24 = "\u30a8\u30e9\u30fc";
                                                        } else {
                                                            v23 = this.F;
                                                            v24 = "Error";
                                                        }
                                                        v23.b(v24);
                                                        v22 = this;
                                                    }
                                                    v22.ag = 0;
                                                    this.u = 10;
                                                }
                                                if (this.u == 1) {
                                                    this.k = 0;
                                                    if (this.af == 0) {
                                                        var18_16 = new byte[]{104, 116, 116, 112, 58, 47, 47, 100, 97, 110, 45, 98, 97, 108, 108, 46, 106, 112, 47, 115, 99, 111, 114, 101, 47, 100, 117, 115, 116, 46, 112, 104, 112, 63, 97, 61};
                                                        var19_25 = new String(var18_16);
                                                        var19_25 = String.valueOf(var19_25) + this.Z;
                                                        var19_25 = String.valueOf(var19_25) + "&b=" + (this.aa != false ? "0" : "1");
                                                        this.bj = this.a(var19_25, "", 1);
                                                        if (this.bj[0].equals("ok")) {
                                                            this.af = 1;
                                                        } else {
                                                            this.af = 2;
                                                            if (this.bj[0].equals("err1")) {
                                                                v25 = this;
                                                                v26 = 1;
                                                            } else if (this.bj[0].equals("err2")) {
                                                                v25 = this;
                                                                v26 = 2;
                                                            } else if (this.bj[0].equals("err3")) {
                                                                v25 = this;
                                                                v26 = 3;
                                                            } else if (this.bj[0].equals("err4")) {
                                                                v25 = this;
                                                                v26 = 4;
                                                            } else if (this.bj[0].equals("err5")) {
                                                                v25 = this;
                                                                v26 = 5;
                                                            } else {
                                                                v25 = this;
                                                                v26 = 0;
                                                            }
                                                            v25.ah = v26;
                                                        }
                                                    }
                                                    ++this.u;
                                                }
                                                if (this.u == 2) {
                                                    if (this.af == 1) {
                                                        if (this.ai < 50) {
                                                            this.u = 3;
                                                            if (this.aa) {
                                                                this.F.b("\u3082\u3046\u5c11\u3057\u4f5c\u308a\u8fbc\u3093\u3067\u4e0b\u3055\u3044\u3002");
                                                                return;
                                                            }
                                                            this.F.b("Please carefully created.");
                                                            return;
                                                        }
                                                        if (this.aa) {
                                                            v27 = this.F;
                                                            v28 = "\u30bf\u30a4\u30c8\u30eb\u3092\u8a18\u5165\u3057\u3066\uff2f\uff2b\u3092\u62bc\u3057\u3066\u4e0b\u3055\u3044";
                                                        } else {
                                                            v27 = this.F;
                                                            v28 = "Enter the title and click OK.";
                                                        }
                                                        v27.b(v28);
                                                        var18_17 = this.G.getBounds();
                                                        this.G.setLocation(200 - var18_17.width / 2, 140);
                                                        this.G.setVisible(true);
                                                    } else if (this.af == 2) {
                                                        if (this.aa) {
                                                            if (this.ah == 1) {
                                                                v29 = this.F;
                                                                v30 = "\u30e6\u30fc\u30b6\u30fc\u767b\u9332\u304c\u5fc5\u8981\u3067\u3059";
                                                            } else if (this.ah == 2) {
                                                                v29 = this.F;
                                                                v30 = "1\u65e5\u306b1\u56de\u306e\u307f\u3067\u3059";
                                                            } else if (this.ah == 3) {
                                                                v29 = this.F;
                                                                v30 = "\u30c0\u30a6\u30f3\u30ed\u30fc\u30c9\u30c7\u30fc\u30bf";
                                                            } else if (this.ah == 4) {
                                                                v29 = this.F;
                                                                v30 = "\u904e\u53bb12\u6642\u9593\u306e\u4f5c\u54c1\u6570\u304c60\u4ef6\u306b\u9054\u3057\u305f\u70ba\uff71\uff6f\uff8c\uff9f\u51fa\u6765\u307e\u305b\u3093";
                                                            } else if (this.ah == 5) {
                                                                v29 = this.F;
                                                                v30 = "\u8a00\u8a9e\u30a8\u30e9\u30fc";
                                                            } else {
                                                                v29 = this.F;
                                                                v30 = "\u30a2\u30c3\u30d7\u30ed\u30fc\u30c9\u51fa\u6765\u307e\u305b\u3093";
                                                            }
                                                        } else if (this.ah == 1) {
                                                            v29 = this.F;
                                                            v30 = "User registration is required.";
                                                        } else if (this.ah == 2) {
                                                            v29 = this.F;
                                                            v30 = "1 time in 2 days only.";
                                                        } else if (this.ah == 3) {
                                                            v29 = this.F;
                                                            v30 = "Download data.";
                                                        } else if (this.ah == 4) {
                                                            v29 = this.F;
                                                            v30 = "Reached 50 posts in 12 hours. Cannot upload.";
                                                        } else if (this.ah == 5) {
                                                            v29 = this.F;
                                                            v30 = "Language error.";
                                                        } else {
                                                            v29 = this.F;
                                                            v30 = "Cannot upload.";
                                                        }
                                                        v29.b(v30);
                                                    }
                                                    ++this.u;
                                                    return;
                                                }
                                                if (this.u != 3) break block226;
                                                this.b(48, 100, 320, 100, -8355712);
                                                this.aG.b(208, 110, "UPLOAD", 255, 160, 160, 255, 0, 0, 0, 255);
                                                this.b(this.F, 208, 135, this.F.d, 16, 0, 0, this.F.d, 16, -16777216);
                                                if (this.af == 1 && this.ai >= 50) {
                                                    var18_18 = this.a(150, 172, 16, 12);
                                                    this.aG.a(158, 180, "OK", 255, var18_18 != false ? 0 : 255, var18_18 != false ? 0 : 255, 255, 0, 0, 0, 255);
                                                    if (var18_18 && this.aI) {
                                                        if (this.G.getText().length() < 2) {
                                                            if (this.aa) {
                                                                this.F.b("\u30bf\u30a4\u30c8\u30eb\u3092\uff12\u6587\u5b57\u4ee5\u4e0a\u8a18\u5165\u3057\u3066\u4e0b\u3055\u3044");
                                                            } else {
                                                                this.F.b("The title must be longer than 2 characters.");
                                                            }
                                                        } else if (dust.c(this.G.getText()) > 20) {
                                                            if (this.aa) {
                                                                this.F.b("\u30bf\u30a4\u30c8\u30eb\u3092\uff11\uff10\u6587\u5b57\u4ee5\u4e0b\u3067\u8a18\u5165\u3057\u3066\u4e0b\u3055\u3044");
                                                            } else {
                                                                this.F.b("The title must be shorter than 10 characters.");
                                                            }
                                                        } else {
                                                            ++this.u;
                                                        }
                                                    }
                                                }
                                                this.aG.a(208, 180, "CANCEL", 255, (var18_19 = this.a(200, 172, 48, 12)) != false ? 0 : 255, var18_19 != false ? 0 : 255, 255, 0, 0, 0, 255);
                                                if (var18_19 && this.aI) {
                                                    this.u = 5;
                                                    return;
                                                }
                                                break block227;
                                            }
                                            if (this.u == 4) {
                                                var18_20 = dust.d(this.G.getText());
                                                if (var18_20.length() == 0) {
                                                    this.u = 3;
                                                    if (this.aa) {
                                                        this.F.b("\u30a8\u30e9\u30fc");
                                                        return;
                                                    }
                                                    this.F.b("Error");
                                                    return;
                                                }
                                                this.S.a();
                                                this.S.b();
                                                if (this.ac.length() == 605) {
                                                    this.u = 3;
                                                    if (this.aa) {
                                                        this.F.b("\u30a8\u30e9\u30fc");
                                                        return;
                                                    }
                                                    this.F.b("Error");
                                                    return;
                                                }
                                                var19_26 = new byte[]{104, 116, 116, 112, 58, 47, 47, 100, 97, 110, 45, 98, 97, 108, 108, 46, 106, 112, 47, 115, 99, 111, 114, 101, 47, 100, 117, 115, 116, 46, 112, 104, 112, 63};
                                                var20_30 = new String(var19_26);
                                                var20_30 = String.valueOf(var20_30) + "a=" + this.Z;
                                                var20_30 = String.valueOf(var20_30) + "&b=" + (this.aa != false ? "0" : "1");
                                                var20_30 = String.valueOf(var20_30) + "&c=" + var18_20;
                                                var21_32 = "";
                                                var21_32 = String.valueOf(var21_32) + "d=" + this.ac;
                                                var21_32 = String.valueOf(var21_32) + "&e=" + this.ad;
                                                var21_32 = String.valueOf(var21_32) + "&f=" + this.ae;
                                                var21_32 = String.valueOf(var21_32) + "&g=" + this.aj;
                                                this.bj = this.a(var20_30, var21_32, 1);
                                                this.af = 2;
                                                ++this.u;
                                                return;
                                            }
                                            if (this.u == 5) {
                                                this.G.setText("");
                                                this.G.setVisible(false);
                                                this.requestFocus();
                                                this.u = 0;
                                                return;
                                            }
                                            if (this.u == 10) {
                                                this.b(82, 308, 252, 70, -10485760);
                                                this.b(86, 312, 244, 62, -10461088);
                                                this.aG.b(208, 322, "DOWNLOAD", 255, 160, 160, 255, 0, 0, 0, 255);
                                                this.b(this.F, 208, 343, this.F.d, 16, 0, 0, this.F.d, 16, -16777216);
                                                if (this.aR < 200) {
                                                    this.aG.b(178, 365, "START", 255, 0, 0, 255, 0, 0, 0, 255);
                                                    v31 = this.aG;
                                                    v32 = 238;
                                                    v33 = 365;
                                                    v34 = "STOP";
                                                    v35 = 255;
                                                    v36 = 255;
                                                    v37 = 255;
                                                } else {
                                                    this.aG.b(178, 365, "START", 255, 255, 255, 255, 0, 0, 0, 255);
                                                    v31 = this.aG;
                                                    v32 = 238;
                                                    v33 = 365;
                                                    v34 = "STOP";
                                                    v35 = 255;
                                                    v36 = 0;
                                                    v37 = 0;
                                                }
                                                v31.b(v32, v33, v34, v35, v36, v37, 255, 0, 0, 0, 255);
                                                if (this.aI) {
                                                    this.u = 0;
                                                    this.w = this.aR < 200 ? 0 : 1;
                                                    return;
                                                }
                                                if (this.aZ[37] || this.aZ[39]) {
                                                    this.u = 0;
                                                    this.w = this.aZ[37] != false ? 0 : 1;
                                                }
                                                return;
                                            }
                                            if (this.u == 20) {
                                                var18_21 = this.G.getBounds();
                                                this.G.setLocation(200 - var18_21.width / 2, 304);
                                                this.G.setVisible(true);
                                                this.H.setLocation(223, 330);
                                                if (this.I == 5) {
                                                    v38 = this.H;
                                                    v39 = true;
                                                } else {
                                                    v38 = this.H;
                                                    v39 = false;
                                                }
                                                v38.setVisible(v39);
                                                ++this.u;
                                                return;
                                            }
                                            if (this.u != 21) break block228;
                                            this.b(88, 309, 240, 99, -8355712);
                                            var1_4 = -1;
                                            if (this.aR >= 80 && this.aR < 220 && this.aS >= 334 && this.aS < 382) {
                                                var1_4 = (this.aS - 334) / 16;
                                                if (var1_4 == 0 && this.aQ != 0) {
                                                    this.I = dust.b(this.I + this.aQ, 0, 5);
                                                    if (this.I == 5) {
                                                        v40 = this.H;
                                                        v41 = true;
                                                    } else {
                                                        v40 = this.H;
                                                        v41 = false;
                                                    }
                                                    v40.setVisible(v41);
                                                }
                                                if (var1_4 == 1 && this.aQ != 0) {
                                                    this.J = dust.b(this.J + this.aQ, 0, 3);
                                                }
                                                if (var1_4 == 2 && this.aQ != 0) {
                                                    this.K = dust.b(this.K + this.aQ, 0, 10);
                                                }
                                            }
                                            this.aG.a(92, 342, "font :" + this.L[this.I], 255, var1_4 == 0 ? 0 : 255, var1_4 == 0 ? 0 : 255, 255, 0, 0, 0, 255);
                                            this.aG.a(92, 358, "style:" + this.M[this.J], 255, var1_4 == 1 ? 0 : 255, var1_4 == 1 ? 0 : 255, 255, 0, 0, 0, 255);
                                            this.aG.a(92, 374, "size :" + this.O[this.K], 255, var1_4 == 2 ? 0 : 255, var1_4 == 2 ? 0 : 255, 255, 0, 0, 0, 255);
                                            var1_4 = -1;
                                            if (this.aR >= 80 && this.aR < 320 && this.aS >= 382 && this.aS < 400) {
                                                v42 = var1_4 = this.aR < 200 ? 0 : 1;
                                                if (this.aH) {
                                                    if (var1_4 == 0) {
                                                        v43 = this;
                                                        v44 = v43;
                                                        v45 = v43.u + 1;
                                                    } else {
                                                        v44 = this;
                                                        v45 = 23;
                                                    }
                                                    v44.u = v45;
                                                }
                                            }
                                            this.aG.a(158, 392, "OK", 255, var1_4 == 0 ? 0 : 255, var1_4 == 0 ? 0 : 255, 255, 0, 0, 0, 255);
                                            this.aG.a(208, 392, "CANCEL", 255, var1_4 == 1 ? 0 : 255, var1_4 == 1 ? 0 : 255, 255, 0, 0, 0, 255);
                                            var18_22 = this.G.getText();
                                            var19_27 = this.L[this.I];
                                            if (this.I == 5) {
                                                var19_27 = this.H.getText();
                                            }
                                            this.U.a(var18_22, var19_27, this.N[this.J], this.O[this.K]);
                                            var20_29 = 2;
                                            if (this.S.r[this.c] == 0) break block229;
                                            v46 = this.S.r;
                                            v47 = this.c;
                                            break block230;
                                        }
                                        if (this.S.r[this.d] == 0) break block231;
                                        v46 = this.S.r;
                                        v47 = this.d;
                                    }
                                    var20_29 = v46[v47];
                                }
                                if (var20_29 == 38) {
                                    var20_29 = 2;
                                }
                                this.a(this.U, this.V, this.W, this.U.d, this.U.e, 0, 0, this.U.d, this.U.e, this.S.v[var20_29][0]);
                                return;
                            }
                            if (this.u != 22) break block232;
                            var18_23 = this.G.getText();
                            var19_28 = new String[]{"sex", "gay", "fuck", "suck", "crap", "shit", "dick", "penis", "bitch", "**", "\u30bb\u30c3\u30af\u30b9", "\u30a8\u30c3\u30c1", "\u3061\u3093\u3053", "\u30c1\u30f3\u30b3", "\u307e\u3093\u3053", "\u30de\u30f3\u30b3", "\u539f\u7206", "\u539f\u5b50\u7206", "\u6838", "\u88ab\u7206", "\u6b7b", "\u6bba", "\u7968", "\u8a55", "\u62cd\u624b", "\u4eba\u6c17", "\u53c2\u52a0", "\u30a2\u30f3\u30b1\u30fc\u30c8", "\u524a\u9664", "\u6d88\u53bb", "ttp", "www.", ".com", ".jp"};
                            var20_31 = "";
                            var1_4 = 0;
                            while (var1_4 < var18_23.length()) {
                                var21_33 = String.valueOf(var18_23.charAt(var1_4));
                                if (!var21_33.equals(" ") && !var21_33.equals("\u3000")) {
                                    var20_31 = String.valueOf(var20_31) + var21_33;
                                }
                                ++var1_4;
                            }
                            var20_31 = var20_31.toLowerCase();
                            var1_4 = 0;
                            while (var1_4 < var19_28.length) {
                                if (var20_31.indexOf(var19_28[var1_4]) >= 0) break;
                                ++var1_4;
                            }
                            if (var1_4 != var19_28.length) {
                                this.u = 23;
                                return;
                            }
                            var21_33 = this.L[this.I];
                            if (this.I == 5) {
                                var21_33 = this.H.getText();
                            }
                            this.U.a(var18_23, var21_33, this.N[this.J], this.O[this.K]);
                            var22_34 = 2;
                            if (this.S.r[this.c] == 0) break block233;
                            v48 = this.S.r;
                            v49 = this.c;
                            break block234;
                        }
                        if (this.S.r[this.d] == 0) break block235;
                        v48 = this.S.r;
                        v49 = this.d;
                    }
                    var22_34 = v48[v49];
                }
                if (var22_34 == 38) {
                    var22_34 = 2;
                }
                var3_9 = 0;
                while (var3_9 < this.U.e) {
                    if (this.W + var3_9 >= 308) break;
                    var2_8 = 0;
                    while (var2_8 < 400) {
                        if (this.V + var2_8 >= 408) break;
                        if (this.U.f[var3_9 * this.U.b + var2_8] != 0 && this.S.F[(this.W + var3_9) * this.a + (this.V + var2_8)] == -5 && (var23_35 = this.S.a((float)(this.V + var2_8), (float)(this.W + var3_9), var22_34)) >= 0 && var22_34 == 8) {
                            this.S.z[var23_35].a = this.S.q.a * 0.1f;
                            this.S.z[var23_35].b = this.S.q.b * 0.1f;
                            this.S.F[(this.W + var3_9) * this.a + (this.V + var2_8)] = -4;
                        }
                        ++var2_8;
                    }
                    ++var3_9;
                }
                ++this.u;
                return;
            }
            if (this.u == 23) {
                this.G.setText("");
                this.G.setVisible(false);
                this.H.setVisible(false);
                this.requestFocus();
                this.u = 0;
            }
        }
    }

    public void init() {
        this.ar = new int[this.a * this.b];
        this.ao = new DirectColorModel(32, 0xFF0000, 65280, 255);
        this.ap = new MemoryImageSource(400, 456, this.ar, this.a * 8 + 8, this.a);
        this.ap.setFullBufferUpdates(true);
        this.ap.setAnimated(true);
        this.aq = this.createImage(this.ap);
        this.l();
        this.a();
        System.out.println("Copyright(C) 2007 ha55ii, http://dan-ball.jp/");
    }

    public void start() {
        if (this.an == null) {
            this.an = new Thread(this);
            this.an.start();
        }
    }

    public void run() {
        while (this.an != null) {
            this.b();
            this.paint(this.getGraphics());
            this.d();
        }
    }

    public void update(Graphics graphics) {
        this.paint(graphics);
    }

    public void paint(Graphics graphics) {
        if (graphics == null || this.ap == null || this.aq == null) {
            System.out.println("null");
            return;
        }
        this.ap.newPixels(this.ar, (ColorModel)this.ao, this.a * 8 + 8, this.a);
        if (this.k == 0) {
            graphics.drawImage(this.aq, 0, 0, null);
            return;
        }
        int n = (int)this.l;
        int n2 = (int)this.m;
        if (this.k <= 2) {
            graphics.drawImage(this.aq, 0, 0, 400, 300, n, n2, n + (400 >> this.k), n2 + (300 >> this.k), null);
        } else if (this.k == 3) {
            graphics.drawImage(this.aq, 0, 0, 400, 296, n, n2, n + (400 >> this.k), n2 + 37, null);
            graphics.drawImage(this.aq, 0, 296, 400, 300, n, n2 + 37, n + (400 >> this.k), n2 + 38, null);
        } else if (this.k == 4) {
            graphics.drawImage(this.aq, 0, 0, 400, 288, n, n2, n + (400 >> this.k), n2 + 18, null);
            graphics.drawImage(this.aq, 0, 288, 400, 300, n, n2 + 18, n + (400 >> this.k), n2 + 19, null);
        }
        graphics.drawImage(this.aq, 0, 300, 400, 456, 0, 300, 400, 456, null);
    }

    public void stop() {
        this.an = null;
    }

    public void destroy() {
        this.an = null;
    }

    final void c() {
        this.av = this.al.length;
        dust dust2 = this;
        int n = 0;
        while (this.au < this.av - 1) {
            if (this.at.charAt(this.au) != this.al[this.au]) break;
            dust dust3 = this;
            dust2 = dust3;
            n = dust2.au = dust3.au + 1;
        }
        if (this.au == this.av - 1 && this.at.charAt(this.au) == this.al[this.au]) {
            this.as[0] = 1;
            ++this.au;
        }
        if (this.au != this.av) {
            this.ar = null;
        }
    }

    final void a(int n) {
        int n2 = this.a * this.b - 1;
        while (n2 >= 0) {
            this.ar[n2] = n;
            --n2;
        }
    }

    final void a(float f, float f2, float f3, float f4, int n) {
        this.a((int)f, (int)f2, (int)f3, (int)f4, n);
    }

    final void a(int n, int n2, int n3, int n4, int n5) {
        int n6 = n3 - n;
        int n7 = n4 - n2;
        int n8 = dust.b(dust.b(dust.c(n6), dust.c(n7)), 1);
        n6 = (n6 << 8) / n8;
        n7 = (n7 << 8) / n8;
        n = (n << 8) + 127;
        n2 = (n2 << 8) + 127;
        int n9 = 0;
        while (n9 <= n8) {
            n3 = n >> 8;
            n4 = n2 >> 8;
            if (n3 >= 0 && this.a > n3 && n4 >= 0 && this.b > n4) {
                this.ar[n4 * this.a + n3] = n5;
            }
            ++n9;
            n += n6;
            n2 += n7;
        }
    }

    /*
     * Unable to fully structure code
     */
    final void b(int var1_1, int var2_2, int var3_3, int var4_4, int var5_5) {
        var6_6 = var2_2 * this.a + var1_1;
        var7_7 = var6_6 + var3_3;
        var8_8 = this.a - var3_3;
        var9_9 = var2_2 + var4_4;
        ** GOTO lbl13
        {
            this.ar[var6_6] = var5_5;
            ++var6_6;
            do {
                if (var6_6 < var7_7) continue block0;
                var6_6 += var8_8;
                var7_7 += this.a;
                ++var2_2;
lbl13:
                // 2 sources

            } while (var2_2 < var9_9);
        }
    }

    final void c(int n, int n2, int n3, int n4, int n5) {
        this.a(n, n2, n + n3, n2, n5);
        this.a(n, n2 + n4, n + n3, n2 + n4, n5);
        this.a(n, n2, n, n2 + n4, n5);
        this.a(n + n3, n2, n + n3, n2 + n4, n5);
    }

    final void a(int n, int n2, int n3, int n4, int n5, int n6) {
        int n7 = n2 * this.a + n;
        int n8 = 0;
        while (n8 < n4) {
            int n9 = 0;
            while (n9 < n3) {
                if (this.ar[n7] == n5) {
                    this.ar[n7] = n6;
                }
                ++n7;
                ++n9;
            }
            n7 += this.a - n3;
            ++n8;
        }
    }

    final void a(b b2, int n, int n2, int n3, int n4, int n5, int n6, int n7, int n8, int n9) {
        int n10 = n < 0 ? -n : 0;
        int n11 = n2 < 0 ? -n2 : 0;
        int n12 = n + n3 > this.a ? n3 - (n + n3 - this.a) : n3;
        int n13 = n2 + n4 > this.b ? n4 - (n2 + n4 - this.b) : n4;
        int n14 = n9 >> 16 & 0xFF;
        int n15 = n9 >> 8 & 0xFF;
        int n16 = n9 & 0xFF;
        int n17 = n11;
        while (n17 < n13) {
            int n18 = (n2 + n17) * this.a + (n + n10);
            int n19 = (n6 + n17 * n8 / n4) * b2.b + n5;
            int n20 = n10;
            while (n20 < n12) {
                int n21 = n19 + n20 * n7 / n3;
                if (b2.f[n21] != 0) {
                    int n22 = n14 * (b2.f[n21] >> 16 & 0xFF) >> 8;
                    int n23 = n15 * (b2.f[n21] >> 8 & 0xFF) >> 8;
                    int n24 = n16 * (b2.f[n21] & 0xFF) >> 8;
                    this.ar[n18] = 0xFF000000 | n22 << 16 | n23 << 8 | n24;
                }
                ++n20;
                ++n18;
            }
            ++n17;
        }
    }

    final void b(b b2, int n, int n2, int n3, int n4, int n5, int n6, int n7, int n8, int n9) {
        this.a(b2, n - n3 / 2, n2 - n4 / 2, n3, n4, n5, n6, n7, n8, n9);
    }

    final void a(e e2, e e3, float f, float f2, float f3) {
        e e4 = new e(this);
        e4.a(e3, e2);
        float f4 = e4.d();
        if (f4 == 0.0f) {
            return;
        }
        e e5 = new e(this);
        e5.a(e4, (f -= f4) * f2);
        e2.c(e5);
        e5.a(e4, f * f3);
        e3.b(e5);
    }

    final void b(int n) {
        this.aw = 0;
        this.ax = 0;
        this.aA = 1000 / n;
        this.aC = this.aB = System.currentTimeMillis();
        this.aD = this.aB + (long)this.aA;
        this.aE = this.aB;
        this.ay = 0;
        this.az = 0;
    }

    final void d() {
        ++this.aw;
        ++this.aF;
        int n = 0;
        try {
            this.aB = System.currentTimeMillis();
            n = (int)(this.aD - this.aB);
            n = dust.a(n, 10, this.aA);
            Thread.sleep(n);
            this.ay += n;
        }
        catch (InterruptedException interruptedException) {}
        this.aD += (long)this.aA;
        if (this.aB + (long)n >= this.aE || this.aB < this.aC) {
            this.az = this.az / 2 + this.ay / 2;
            this.ay = 0;
            this.ax = this.aw;
            this.aw = 0;
            this.aD = this.aB + (long)this.aA;
            this.aE = this.aB + 1000L;
        }
        this.aC = this.aB;
    }

    final void a(int n, int n2, int n3, int n4, int n5, int n6, int n7, int n8, int n9, int n10) {
        this.aG.a(n3, n4, n5, n6);
        this.aG.b(n7, n8, n9, n10);
        this.aG.a(n, n2, String.valueOf(this.ax) + "fps");
        if (this.ak == 1) {
            this.aG.a(n + 48, n2, String.valueOf(this.az) + "sl", 255, 255, 255, 255, 0, 0, 0, 255);
        }
    }

    final void e() {
        this.addMouseListener(this);
        this.addMouseMotionListener(this);
    }

    final void f() {
        this.aH = !this.aJ && this.aK;
        this.aI = this.aJ && !this.aK;
        this.aL = !this.aN && this.aO;
        this.aM = this.aN && !this.aO;
        this.aJ = this.aK;
        this.aN = this.aO;
        boolean bl = this.aP = !(this.aI | this.aJ | this.aM | this.aN);
        this.aQ = this.aI ? 1 : (this.aM ? -1 : 0);
        this.aT = this.aR;
        this.aU = this.aS;
        this.aR = this.aV;
        this.aS = this.aW;
        if (this.au != this.av) {
            this.ar = null;
        }
    }

    final boolean a(int n, int n2, int n3, int n4) {
        if (this.aR < n || n + n3 < this.aR) {
            return false;
        }
        return this.aS >= n2 && n2 + n4 >= this.aS;
    }

    public void mouseEntered(MouseEvent mouseEvent) {
        if (this.u == 0) {
            this.requestFocus();
        }
    }

    public void mouseExited(MouseEvent mouseEvent) {
    }

    public void mousePressed(MouseEvent mouseEvent) {
        if (this.aZ[17]) {
            if ((mouseEvent.getModifiers() & 0x10) != 0) {
                this.aO = true;
            }
            if ((mouseEvent.getModifiers() & 4) != 0) {
                this.aK = true;
                return;
            }
        } else {
            if ((mouseEvent.getModifiers() & 0x10) != 0) {
                this.aK = true;
            }
            if ((mouseEvent.getModifiers() & 4) != 0) {
                this.aO = true;
            }
        }
    }

    public void mouseReleased(MouseEvent mouseEvent) {
        if (this.aZ[17]) {
            if ((mouseEvent.getModifiers() & 0x10) != 0) {
                this.aO = false;
            }
            if ((mouseEvent.getModifiers() & 4) != 0) {
                this.aK = false;
                return;
            }
        } else {
            if ((mouseEvent.getModifiers() & 0x10) != 0) {
                this.aK = false;
            }
            if ((mouseEvent.getModifiers() & 4) != 0) {
                this.aO = false;
            }
        }
    }

    public void mouseClicked(MouseEvent mouseEvent) {
    }

    public void mouseDragged(MouseEvent mouseEvent) {
        Point point = mouseEvent.getPoint();
        this.aV = point.x;
        this.aW = point.y;
    }

    public void mouseMoved(MouseEvent mouseEvent) {
        Point point = mouseEvent.getPoint();
        this.aV = point.x;
        this.aW = point.y;
    }

    final void g() {
        this.addKeyListener(this);
        int n = 0;
        while (n < 256) {
            this.aX[n] = false;
            this.aY[n] = false;
            this.aZ[n] = false;
            ++n;
        }
    }

    final void h() {
        int n = 0;
        while (n < 256) {
            this.aX[n] = this.aY[n];
            this.aY[n] = false;
            ++n;
        }
    }

    public void keyPressed(KeyEvent keyEvent) {
        int n = keyEvent.getKeyCode();
        if (n >= 0 && n < 256) {
            this.aZ[n] = true;
        }
    }

    public void keyReleased(KeyEvent keyEvent) {
        int n = keyEvent.getKeyCode();
        if (n >= 0 && n < 256) {
            this.aZ[n] = false;
        }
    }

    public void keyTyped(KeyEvent keyEvent) {
        char c2 = keyEvent.getKeyChar();
        if (c2 < '\u0100') {
            this.aY[c2] = true;
            if (c2 >= 'A' && c2 <= 'Z') {
                this.aY[c2 + 32] = true;
            }
            if (c2 >= 'a' && c2 <= 'z') {
                this.aY[c2 - 32] = true;
            }
        }
    }

    final String[] a(String string, String string2, int n) {
        String[] stringArray = new String[100];
        int n2 = 0;
        while (n2 < 100) {
            stringArray[n2] = "";
            ++n2;
        }
        try {
            String string3;
            StringBuffer stringBuffer;
            String string4 = new String(this.bd);
            String string5 = null;
            if (string2.length() == 0) {
                stringBuffer = new StringBuffer(String.valueOf(new String(this.ba))).append(string).append(new String(this.bb)).append(new String(this.bc)).append(string4).append(new String(this.bf)).append(new String(this.be));
                string3 = new String(this.bf);
            } else {
                stringBuffer = new StringBuffer(String.valueOf(new String(this.bg))).append(string).append(new String(this.bb)).append(new String(this.bc)).append(string4).append(new String(this.bf)).append(new String(this.be)).append(new String(this.bh)).append(new String(this.bi)).append(string2.length()).append(new String(this.bf)).append(new String(this.bf)).append(string2).append(new String(this.bf));
                string3 = new String(this.bf);
            }
            string5 = stringBuffer.append(string3).toString();
            Socket socket = new Socket(string4, 80);
            OutputStream outputStream = socket.getOutputStream();
            int n3 = 0;
            while (n3 < string5.length()) {
                outputStream.write(string5.charAt(n3));
                ++n3;
            }
            outputStream.flush();
            if (n == 1) {
                int n4;
                InputStream inputStream = socket.getInputStream();
                int n5 = 0;
                block4: while ((n4 = inputStream.read()) != -1) {
                    if (n4 == 61) {
                        while ((n4 = inputStream.read()) != -1) {
                            if (n4 == 10) break;
                            int n6 = n5;
                            stringArray[n6] = String.valueOf(stringArray[n6]) + (char)n4;
                        }
                        ++n5;
                        continue;
                    }
                    if (n4 == 10) continue;
                    while ((n4 = inputStream.read()) != -1) {
                        if (n4 == 10) continue block4;
                    }
                }
                inputStream.close();
            }
            outputStream.close();
            socket.close();
        }
        catch (IOException iOException) {
            stringArray[0] = "error";
            stringArray[1] = "2";
            iOException.printStackTrace();
        }
        return stringArray;
    }

    static float a(float f) {
        return (float)Math.sin(f);
    }

    static float b(float f) {
        return (float)Math.cos(f);
    }

    static float c(float f) {
        return (float)Math.sqrt(f);
    }

    static float i() {
        return (float)Math.random();
    }

    static float a(float f, float f2) {
        if (f < 0.0f) {
            f = -f;
        }
        if (f2 < 0.0f) {
            f2 = -f2;
        }
        if (f >= f2) {
            return 0.9604f * f + 0.3978f * f2;
        }
        return 0.9604f * f2 + 0.3978f * f;
    }

    final void j() {
        int n = 0;
        while (n < 1024) {
            this.bk[n] = (float)n / 1024.0f;
            ++n;
        }
        n = 0;
        while (n < 1024) {
            int n2 = (int)(dust.i() * 1024.0f);
            float f = this.bk[n];
            this.bk[n] = this.bk[n2];
            this.bk[n2] = f;
            ++n;
        }
        this.bl = (int)(dust.i() * 1024.0f) & 0x3FF;
        this.bm = (int)(dust.i() * 512.0f) | 1;
    }

    final void k() {
        this.bl = this.bl + (int)(dust.i() * 1024.0f) & 0x3FF;
        this.bm = (int)(dust.i() * 512.0f) | 1;
        if (this.as[0] == 0) {
            int n = 0;
            while (n < 1024) {
                this.bk[n] = 0.0f;
                ++n;
            }
        }
    }

    final float d(float f) {
        this.bl += this.bm;
        this.bl &= 0x3FF;
        return this.bk[this.bl] * f;
    }

    final float b(float f, float f2) {
        this.bl += this.bm;
        this.bl &= 0x3FF;
        return this.bk[this.bl] * (f2 - f) + f;
    }

    final int a(int n, int n2) {
        this.bl += this.bm;
        this.bl &= 0x3FF;
        if (this.bk[this.bl] < 0.5f) {
            return n;
        }
        return n2;
    }

    final void l() {
        int n = 0;
        while (n < 512) {
            float f = 360.0f * (float)n / (float)512 * (float)Math.PI / 180.0f;
            this.bn[n][0] = dust.b(f);
            this.bn[n][1] = dust.a(f);
            ++n;
        }
        this.bn[n][0] = this.bn[0][0];
        this.bn[n][1] = this.bn[0][1];
    }

    static int c(int n) {
        if (n < 0) {
            return -n;
        }
        return n;
    }

    static float e(float f) {
        if (f < 0.0f) {
            return -f;
        }
        return f;
    }

    static int b(int n, int n2) {
        if (n > n2) {
            return n;
        }
        return n2;
    }

    static int c(int n, int n2) {
        if (n < n2) {
            return n;
        }
        return n2;
    }

    static float c(float f, float f2) {
        if (f < f2) {
            return f;
        }
        return f2;
    }

    static int a(int n, int n2, int n3) {
        if (n < n2) {
            return n2;
        }
        if (n > n3) {
            return n3;
        }
        return n;
    }

    static float a(float f, float f2, float f3) {
        if (f < f2) {
            return f2;
        }
        if (f > f3) {
            return f3;
        }
        return f;
    }

    static int b(int n, int n2, int n3) {
        if (n < n2) {
            return n3;
        }
        if (n > n3) {
            return n2;
        }
        return n;
    }

    static int c(String string) {
        int n = 0;
        int n2 = string.length();
        int n3 = 0;
        while (n3 < n2) {
            String string2 = String.valueOf(string.charAt(n3));
            try {
                n = string2.getBytes("UTF-8").length == 1 ? ++n : (n += 2);
            }
            catch (Exception exception) {
                if (string2.getBytes().length == 1) {
                    ++n;
                }
                n += 2;
            }
            ++n3;
        }
        return n;
    }

    static String d(String string) {
        String string2 = "";
        try {
            char[] cArray = new char[]{'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};
            int n = string.length();
            int n2 = 0;
            while (n2 < n) {
                String string3 = String.valueOf(string.charAt(n2));
                byte[] byArray = string3.getBytes("UTF-8");
                int n3 = 0;
                while (n3 < byArray.length) {
                    char c2;
                    StringBuffer stringBuffer;
                    if (byArray[n3] == 45 || byArray[n3] == 46 || byArray[n3] == 95) {
                        stringBuffer = new StringBuffer(String.valueOf(string2));
                        c2 = (char)byArray[n3];
                    } else if (byArray[n3] == 32) {
                        stringBuffer = new StringBuffer(String.valueOf(string2));
                        c2 = (char)43;
                    } else if (byArray[n3] >= 48 && byArray[n3] <= 57) {
                        stringBuffer = new StringBuffer(String.valueOf(string2));
                        c2 = (char)byArray[n3];
                    } else if (byArray[n3] >= 65 && byArray[n3] <= 90) {
                        stringBuffer = new StringBuffer(String.valueOf(string2));
                        c2 = (char)byArray[n3];
                    } else if (byArray[n3] >= 97 && byArray[n3] <= 122) {
                        stringBuffer = new StringBuffer(String.valueOf(string2));
                        c2 = (char)byArray[n3];
                    } else {
                        string2 = String.valueOf(string2) + '%';
                        string2 = String.valueOf(string2) + cArray[byArray[n3] >> 4 & 0xF];
                        stringBuffer = new StringBuffer(String.valueOf(string2));
                        c2 = cArray[byArray[n3] & 0xF];
                    }
                    string2 = stringBuffer.append(c2).toString();
                    ++n3;
                }
                ++n2;
            }
        }
        catch (Exception exception) {
            try {
                string2 = URLEncoder.encode(string);
            }
            catch (Exception exception2) {
                string2 = "";
                exception2.printStackTrace();
            }
        }
        return string2;
    }

    public dust() {
        int[] nArray = new int[4];
        nArray[1] = 1;
        nArray[2] = 2;
        nArray[3] = 3;
        this.N = nArray;
        this.O = new int[]{12, 14, 16, 18, 20, 24, 30, 36, 48, 60, 72};
        this.P = new int[this.a * 309];
        this.Q = new int[this.a * 309];
        this.R = new int[this.a * 309];
        this.S = new d(this);
        this.T = new b(this);
        this.U = new b(this);
        this.al = new int[]{100, 97, 110, 45, 98, 97, 108, 108, 46, 106, 112, 47};
        this.am = "";
        this.as = new int[3];
        this.av = 1;
        this.aG = new a(this);
        this.aX = new boolean[256];
        this.aY = new boolean[256];
        this.aZ = new boolean[256];
        this.ba = new byte[]{71, 69, 84, 32};
        this.bb = new byte[]{32, 72, 84, 84, 80, 47, 49, 46, 49, 13, 10};
        this.bc = new byte[]{72, 111, 115, 116, 58, 32};
        this.bd = new byte[]{100, 97, 110, 45, 98, 97, 108, 108, 46, 106, 112};
        this.be = new byte[]{67, 111, 110, 110, 101, 99, 116, 105, 111, 110, 58, 32, 99, 108, 111, 115, 101, 13, 10};
        this.bf = new byte[]{13, 10};
        this.bg = new byte[]{80, 79, 83, 84, 32};
        this.bh = new byte[]{67, 111, 110, 116, 101, 110, 116, 45, 116, 121, 112, 101, 58, 32, 97, 112, 112, 108, 105, 99, 97, 116, 105, 111, 110, 47, 120, 45, 119, 119, 119, 45, 102, 111, 114, 109, 45, 117, 114, 108, 101, 110, 99, 111, 100, 101, 100, 13, 10};
        this.bi = new byte[]{67, 111, 110, 116, 101, 110, 116, 45, 108, 101, 110, 103, 116, 104, 58, 32};
        this.bk = new float[1024];
        this.bn = new float[513][2];
    }

    class COMClassObject {
    }
}
