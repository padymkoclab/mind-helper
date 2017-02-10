
#ifndef __WINDOW_H__
#define __WINDOW_H__


#define WINDOW_MAIN_TITLE "Helper for your mind"
#define WINDOW_ICON_PATH "./data/icon.png"


void app(int argc, char *argv[]);

GdkPixbuf* create_pixbuf(const char *filename);

GtkWidget * get_main_window();

GdkPixbuf * get_window_icon(GtkWidget *window);

int show_popup_menu(GtkWidget *context_menu, GdkEvent *event);


#endif // __WINDOW_H__
