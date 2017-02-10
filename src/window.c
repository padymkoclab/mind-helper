
#include <gtk/gtk.h>

#include <window.h>
#include <menu.h>


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


GtkWidget *
get_main_window()
{
    GtkWidget *window;
    gint window_width;
    gint window_height;
    GdkScreen *screen;

    // determination default window`s size
    screen = gdk_screen_get_default();
    window_width = gdk_screen_get_width(screen);
    window_height = gdk_screen_get_height(screen);

    // preparation a new window
    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(window), WINDOW_MAIN_TITLE);
    gtk_window_set_default_size(GTK_WINDOW(window), window_width / 2, window_height / 2);
    gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);

    return window;
}


GdkPixbuf *
get_window_icon(GtkWidget *window)
{
    GdkPixbuf *icon;
    icon = create_pixbuf(WINDOW_ICON_PATH);
    gtk_window_set_icon(GTK_WINDOW(window), icon);
    return icon;
}


int
show_popup_menu(GtkWidget *context_menu, GdkEvent *event)
{
    // right click code number is 3, left is 1

    if (event->type == GDK_BUTTON_PRESS) {
        GdkEventButton *btn_event = (GdkEventButton *) event;

        // click on right mouse button (or touchpad or something else)
        if (btn_event->button == 3) {
            gtk_menu_popup(GTK_MENU(context_menu), NULL, NULL, NULL, NULL,
                btn_event->button, btn_event->time);
            return TRUE;
        }
    }
    return FALSE;
}


void
add_context_menu(GtkWidget *window)
{
    static const char menu_item_help_text[] = "Help";
    static const char menu_item_quit_text[] = "Quit";

    GtkWidget *ebox;
    GtkWidget *menu;
    GtkWidget *menu_item_help;
    GtkWidget *menu_item_quit;

    menu = gtk_menu_new();

    menu_item_help = gtk_menu_item_new_with_label(menu_item_help_text);
    menu_item_quit = gtk_menu_item_new_with_label(menu_item_quit_text);

    gtk_widget_show(menu_item_help);
    gtk_widget_show(menu_item_quit);

    gtk_menu_shell_append(GTK_MENU_SHELL(menu), menu_item_help);
    gtk_menu_shell_append(GTK_MENU_SHELL(menu), menu_item_quit);

    ebox = gtk_event_box_new();
    gtk_container_add(GTK_CONTAINER(window), ebox);

    g_signal_connect_swapped(G_OBJECT(ebox), "button-press-event", G_CALLBACK(show_popup_menu), menu);

}



/*
    A main application
 */
void
app(int argc, char *argv[])
{
    gtk_init(&argc, &argv);

    GtkWidget *window;
    GtkWidget *menubar;
    GtkWidget *vbox;
    GtkWidget *statusbar;
    GtkWidget *toolbar;

    GdkPixbuf *icon;

    GtkToolItem *new_tab;
    GtkToolItem *close_tab;

    window = get_main_window();

    vbox = gtk_box_new(GTK_ORIENTATION_VERTICAL, 0);
    gtk_container_add(GTK_CONTAINER(window), vbox);

    toolbar = gtk_toolbar_new();
    new_tab = gtk_tool_button_new_from_stock(GTK_STOCK_NEW);
    close_tab = gtk_tool_button_new_from_stock(GTK_STOCK_CLOSE);
    gtk_toolbar_insert(GTK_TOOLBAR(toolbar), new_tab, -1);
    gtk_toolbar_insert(GTK_TOOLBAR(toolbar), close_tab, -1);

    // need add context menu to inner window
    // because it has conflit with top menu
    //
    // add_context_menu(inner widget window);

    statusbar = gtk_statusbar_new();

    menubar = gtk_menu_bar_new();
    set_menu_File(menubar);
    set_menu_Edit(menubar);
    set_menu_View(menubar, statusbar);
    set_menu_Preferences(menubar);
    // set_menu_Convert(menubar);
    // set_menu_Email(menubar);
    // set_menu_Browser(menubar);
    // set_menu_Markups(menubar);
    set_menu_Help(menubar);

    gtk_box_pack_start(GTK_BOX(vbox), menubar, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(vbox), toolbar, FALSE, FALSE, 0);

    gtk_box_pack_end(GTK_BOX(vbox), statusbar, FALSE, FALSE, 0);

    icon = get_window_icon(window);

    gtk_widget_show_all(window);

    g_signal_connect(G_OBJECT(window), "destroy", G_CALLBACK(gtk_main_quit), NULL);

    // unref for a file-object
    g_object_unref(icon);

    // run this application
    gtk_main();
}
