
#ifndef __MENU_H__
#define __MENU_H__


int set_menu_File(GtkWidget *menubar);

int set_menu_Edit(GtkWidget *menubar);

int set_menu_View(GtkWidget *menubar, GtkWidget *statusbar);

int set_menu_Preferences(GtkWidget *menubar);

int set_menu_Help(GtkWidget *menubar);

void toggle_statusbar(GtkWidget *widget, gpointer statusbar);


#endif // __MENU_H__

