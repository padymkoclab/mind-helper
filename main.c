
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Posix headers
#include <pthread.h>
#include <unistd.h>

// GTK+
#include <gtk/gtk.h>
#include <glib.h>
#include <glib/gprintf.h>


#define MAIN_WINDOW_TITLE "All worked?"

// http://www.bravegnu.org/gtktext/gtktext-0.4.html
// https://github.com/incessantmeraki/sedit/blob/master/sedit.c
// https://cboard.cprogramming.com/c-programming/151019-graphical-text-editor-gtkplus.html
// https://developer.gnome.org/gtk3/stable/TextWidget.html


void
app(int argc, char *argv[]) {
    char version[10];

    g_sprintf(version, "GTK+ %d.%d.%d", gtk_major_version, gtk_minor_version, gtk_micro_version);

    GtkWidget *window;
    GtkWidget *label;

    gtk_init(&argc, &argv);

    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(window), MAIN_WINDOW_TITLE);
    gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);
    gtk_window_set_default_size(GTK_WINDOW(window), 200, 100);

    g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);

    label = gtk_label_new(version);
    gtk_container_add(GTK_CONTAINER(window), label);

    gtk_widget_show_all(window);

    gtk_main();
}


int main(int argc, char *argv[])
{

    // app(argc, argv);
    GdkScreen *screen;

    // https://developer.gnome.org/search?q=_GdkScreen
    // https://developer.gnome.org/gdk3/stable/GdkScreen.html
    // https://www.x.org/releases/X11R7.6/doc/libX11/specs/libX11/libX11.html#Screen_Information_Macros
    // http://zetcode.com/gui/gtk2/firstprograms/
    screen = gdk_screen_get_default();

    // screen->ints;

    return EXIT_SUCCESS;
}


// http://stackoverflow.com/questions/26957506/how-to-open-and-save-a-file-in-gtk
// http://zetcode.com/gfx/cairo/cairodefinitions/
