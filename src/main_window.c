
#include <main_window.h>


/*
    Create and return a pointer on the GdkPixbuf object on a real file
 */
GdkPixbuf *
create_pixbuf(const char *filename)
{
    GdkPixbuf *pixbuf;
    GError *error = NULL;
    pixbuf = gdk_pixbuf_new_from_file(filename, &error);
    if (!pixbuf) {
        fprintf(stderr, "%s\n", error->message);
        g_error_free(error);
    }
    return pixbuf;
}


/*
    A main application
    http://zetcode.com/gui/gtk2/menusandtoolbars/
 */
void
app(int argc, char *argv[])
{
    gtk_init(&argc, &argv);

    GtkWidget *window;
    gint window_width;
    gint window_height;
    GdkScreen *screen;
    GdkPixbuf *icon;

    // determination default window`s size
    screen = gdk_screen_get_default();
    window_width = gdk_screen_get_width(screen);
    window_height = gdk_screen_get_height(screen);

    // preparation a new window
    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(window), MAIN_WINDOW_TITLE);
    gtk_window_set_default_size(GTK_WINDOW(window), window_width / 2, window_height / 2);
    gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);

    // set an icon
    icon = create_pixbuf(WINDOW_ICON_PATH);
    gtk_window_set_icon(GTK_WINDOW(window), icon);

    gtk_widget_show_all(window);

    // unref for a file-object
    g_object_unref(icon);

    // run this application
    gtk_main();
}
