#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include "common.h"
#include "input.h"
#include "save.h"
#include "render/draw.h"
#include "vector.h"

#include <gtk/gtk.h>

void Platform_frame(void);
void Platform_main(int argc, char** argv);

/*Display* D;
Window win;
XImage* simImage;
XImage* menuImage;*/

long Platform_nanosec(void) {
	struct timespec ts;
	timespec_get(&ts, TIME_UTC);
	return (long)ts.tv_sec * 1000000000L + ts.tv_nsec; // ONE MILLION
}

void redraw(void) {
	//	XPutImage(D, win, DefaultGC(D, 0), simImage, 0,0, 0,0, W,H);
	//	XPutImage(D, win, DefaultGC(D, 0), menuImage, 0,0, 0,H, W,MENU_HEIGHT);
}

//Atom wmDeleteMessage;

/*static bool processEvent(void) {
	while (1) {
		static union {
			XEvent event;
			XMotionEvent motion;
			XKeyEvent key;
			XButtonEvent button;
			XClientMessageEvent clientMessage;
		} ev;
		Bool t = XCheckWindowEvent(D, win, ~0L, &ev.event);
		if (!t)
			return true;
		switch (ev.event.type) {
			//case ClientMessage:
			//			if ((Atom)ev.clientMessage.data.l[0] == wmDeleteMessage)
			//				return false;
			//			break;
		case Expose:
			redraw();
			break;
		case ButtonPress:;
		case ButtonRelease:;
			ButtonState* btn = NULL;
			if (ev.button.button == Button1)
				btn = &mouse.left;
			if (ev.button.button == Button2)
				btn = &mouse.middle;
			if (ev.button.button == Button3)
				btn = &mouse.right;
			if (btn) {
				btn->heldNow = ev.event.type==ButtonPress;
				if (ev.event.type==ButtonPress)
					btn->gotPress = true;
				else
					btn->gotRelease = true;
			}
			break;
		case MotionNotify:;
			mouse.pos = (Point){ev.motion.x, ev.motion.y};
			break;
		case KeyPress:;
		case KeyRelease:;
			KeySym key = XLookupKeysym(&ev.key, 0);
			if (!key) break;
			int code = -1;
			switch (key) {
			when(XK_space): code = ' ';
			when(XK_w): case XK_W: code = 'W';
			when(XK_a): case XK_A: code = 'A';
			when(XK_s): case XK_S: code = 'S';
			when(XK_d): case XK_D: code = 'D';
			when(XK_Up): code = 38;
			when(XK_Down): code = 40;
			when(XK_Left): code = 37;
			when(XK_Right): code = 39;
			when(XK_Return): code = '\r';
			otherwise:;
				char* sym_name = XKeysymToString(key);
				printf("Got keysym: (%s)\n", sym_name);
			}
			if (code >= 0) {
				Keys[code].heldNow = ev.event.type == KeyPress;
				if (ev.event.type == KeyPress)
					Keys[code].gotPress = true;
				else
					Keys[code].gotRelease = true;
			}
		}
	}
	}*/

GtkApplication* app;
GtkWidget* window;

static gboolean on_window_draw(GtkWidget* da, GdkEvent* event, gpointer data) {
	GError *err = NULL;
	GdkPixbuf *pix = gdk_pixbuf_new_from_file("/home/twelve/Pictures/1614117539516.png", &err);
	if (err) {
		printf("Error: %s\n", err->message);
		g_error_free(err);
		return FALSE;
	}
	cairo_t* cr = gdk_cairo_create(gtk_widget_get_window(da));
	gdk_cairo_set_source_pixbuf(cr, pix, 0, 0);
	cairo_paint(cr);
	cairo_destroy(cr);
}

int main(int argc, char** argv) {
	GtkWidget* canvas;
	gtk_init(&argc, &argv);
	window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
	gtk_widget_set_size_request(window, WINDOW_WIDTH, WINDOW_HEIGHT);
	g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);
	canvas = gtk_drawing_area_new();
	gtk_container_add(GTK_CONTAINER(window), canvas);
	g_signal_connect(canvas, "draw", (GCallback)on_window_draw, NULL);
	gtk_widget_set_app_paintable(canvas, TRUE);
	gtk_widget_show_all(window);
	gtk_main();
	return 0;
	
	/*	// start
	Platform_main(argc, argv);
	Platform_frame();
	redraw();
	while (processEvent()) {
		Platform_frame();
		redraw();
		}*/
}

FILE* Platform_fopen(const void* name) {
	return fopen((const char*)name, "r");
}

void Platform_saveAs(char* text) {
	puts("starting");
	GtkFileChooserNative* native = gtk_file_chooser_native_new("Save File", NULL, GTK_FILE_CHOOSER_ACTION_SAVE, "_Save", "_Cancel");
	printf("native: %p\n", native);
	GtkFileChooser* chooser = GTK_FILE_CHOOSER(native);
	printf("chooser: %p\n", chooser);
	
	gtk_file_chooser_set_do_overwrite_confirmation(chooser, TRUE);

	gtk_file_chooser_set_current_name(chooser, "untitled.txt");
	
	gint res = gtk_native_dialog_run(GTK_NATIVE_DIALOG(native));
	if (res==GTK_RESPONSE_ACCEPT) {
		char* filename = gtk_file_chooser_get_filename(chooser);
		FILE* n = fopen(filename, "w+");
		fputs(text, n);
		fclose(n);
		g_free(filename);
	}
	g_object_unref(native);
}
