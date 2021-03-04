/*
 * Decompiled with CFR 0.151.
 */
import java.awt.Color;
import java.awt.Font;
import java.awt.Graphics;
import java.awt.Image;
import java.awt.MediaTracker;
import java.awt.image.PixelGrabber;
import java.net.URL;

/*
 * Exception performing whole class analysis ignored.
 */
final class b {
    private final dust g;
    Image a;
    int b;
    int c;
    int d;
    int e;
    int[] f;

    final void a(int n, int n2) {
        this.b = n;
        this.c = n2;
        this.f = new int[this.b * this.c];
    }

    final void a(String string) {
        URL uRL = this.g.getCodeBase();
        Image image = this.g.getImage(uRL, string);
        MediaTracker mediaTracker = new MediaTracker(new c());
        mediaTracker.addImage(image, 0);
        try {
            mediaTracker.waitForAll();
        }
        catch (Exception exception) {}
        this.b = image.getWidth(null);
        this.c = image.getHeight(null);
        this.f = new int[this.b * this.c];
        PixelGrabber pixelGrabber = new PixelGrabber(image, 0, 0, this.b, this.c, this.f, 0, this.b);
        try {
            pixelGrabber.grabPixels();
        }
        catch (Exception exception) {}
        uRL = this.g.getDocumentBase();
        this.g.at = uRL.toString();
        byte[] byArray = new byte[]{104, 116, 116, 112, 58, 47, 47};
        byte[] byArray2 = new byte[]{104, 116, 116, 112, 115, 58, 47, 47};
        byte[] byArray3 = new byte[]{104, 116, 116, 112, 58, 47, 47, 98, 111, 120, 46};
        byte[] byArray4 = new byte[]{104, 116, 116, 112, 115, 58, 47, 47, 98, 111, 120, 46};
        String string2 = new String(byArray4);
        String string3 = new String(byArray3);
        String string4 = new String(byArray2);
        String string5 = new String(byArray);
        if (this.g.at.indexOf(string2) == 0) {
            this.g.at = this.g.at.substring(string2.length());
            return;
        }
        if (this.g.at.indexOf(string3) == 0) {
            this.g.at = this.g.at.substring(string3.length());
            return;
        }
        if (this.g.at.indexOf(string4) == 0) {
            this.g.at = this.g.at.substring(string4.length());
            return;
        }
        if (this.g.at.indexOf(string5) == 0) {
            this.g.at = this.g.at.substring(string5.length());
        }
    }

    final void b(String string) {
        this.a(string, "", 0, 12);
    }

    final void a(String string, String string2, int n, int n2) {
        if (this.a == null) {
            this.a(this.g.a, 128);
            this.a = this.g.createImage(this.b, this.c);
        }
        Graphics graphics = this.a.getGraphics();
        graphics.setFont(new Font(string2, n, n2));
        graphics.setColor(Color.white);
        graphics.fillRect(0, 0, this.b, this.c);
        graphics.setColor(Color.black);
        graphics.drawString(string, n, n2);
        PixelGrabber pixelGrabber = new PixelGrabber(this.a, 0, 0, this.b, this.c, this.f, 0, this.b);
        try {
            pixelGrabber.grabPixels();
        }
        catch (Exception exception) {}
        int n3 = 0;
        while (n3 < this.b * this.c) {
            int n4;
            int n5;
            int[] nArray;
            if (this.f[n3] == -16777216) {
                nArray = this.f;
                n5 = n3;
                n4 = -1;
            } else {
                nArray = this.f;
                n5 = n3;
                n4 = 0;
            }
            nArray[n5] = n4;
            ++n3;
        }
        n3 = 0;
        this.d = 0;
        this.e = 0;
        int n6 = 0;
        while (n6 < this.c) {
            int n7 = 0;
            while (n7 < this.b) {
                if (this.f[n3] == -1) {
                    if (this.d <= n7) {
                        this.d = n7 + 1;
                    }
                    if (this.e <= n6) {
                        this.e = n6 + 1;
                    }
                }
                ++n7;
                ++n3;
            }
            ++n6;
        }
    }

    b(dust dust2) {
        this.g = dust2;
        this.g = dust2;
    }
}
