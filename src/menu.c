
#include <gtk/gtk.h>


void
toggle_statusbar(GtkWidget *widget, gpointer statusbar)
{
    if (gtk_check_menu_item_get_active(GTK_CHECK_MENU_ITEM(widget))) {
        gtk_widget_show(statusbar);
    } else {
        gtk_widget_hide(statusbar);
    }
}


int
set_menu_File(GtkWidget *menubar)
{
    static const char menu_item_text[] = "_File";
    static const char menu_item_new_file_text[] = "New file";
    static const char menu_item_open_file_text[] = "Open file";
    static const char menu_item_reopen_recent_text[] = "Reopen recent";
    static const char menu_item_reopen_recent_reopen_all_text[] = "Reopen all";
    static const char menu_item_reopen_recent_clear_all_text[] = "Clear all";
    static const char menu_item_save_file_text[] = "Save file";
    static const char menu_item_close_file_text[] = "Close file";
    static const char menu_item_quit_text[] = "Quit";

    GtkWidget *menu;
    GtkWidget *menu_item;
    GtkWidget *menu_item_new_file;
    GtkWidget *menu_item_open_file;
    GtkWidget *menu_item_reopen_recent_item;
    GtkWidget *menu_item_reopen_recent_menu;
    GtkWidget *menu_item_reopen_recent_reopen_all;
    GtkWidget *menu_item_reopen_recent_clear_all;
    GtkWidget *menu_item_save_file;
    GtkWidget *menu_item_close_file;
    GtkWidget *menu_item_quit;

    GtkWidget *separator;
    separator = gtk_separator_menu_item_new();

    menu = gtk_menu_new();

    menu_item = gtk_menu_item_new_with_mnemonic(menu_item_text);
    menu_item_new_file = gtk_menu_item_new_with_label(menu_item_new_file_text);
    menu_item_open_file = gtk_menu_item_new_with_label(menu_item_open_file_text);

    menu_item_reopen_recent_menu = gtk_menu_new();
    menu_item_reopen_recent_item = gtk_menu_item_new_with_label(menu_item_reopen_recent_text);
    menu_item_reopen_recent_reopen_all = gtk_menu_item_new_with_label(menu_item_reopen_recent_reopen_all_text);
    menu_item_reopen_recent_clear_all = gtk_menu_item_new_with_label(menu_item_reopen_recent_clear_all_text);

    menu_item_save_file = gtk_menu_item_new_with_label(menu_item_save_file_text);
    menu_item_close_file = gtk_menu_item_new_with_label(menu_item_close_file_text);
    menu_item_quit = gtk_menu_item_new_with_label(menu_item_quit_text);

    gtk_menu_item_set_submenu(GTK_MENU_ITEM(menu_item_reopen_recent_item), menu_item_reopen_recent_menu);
    gtk_menu_shell_append(GTK_MENU_SHELL(menu_item_reopen_recent_menu), menu_item_reopen_recent_reopen_all);
    gtk_menu_shell_append(GTK_MENU_SHELL(menu), separator);
    gtk_menu_shell_append(GTK_MENU_SHELL(menu_item_reopen_recent_menu), menu_item_reopen_recent_clear_all);

    gtk_menu_item_set_submenu(GTK_MENU_ITEM(menu_item), menu);
    gtk_menu_shell_append(GTK_MENU_SHELL(menu), menu_item_new_file);
    gtk_menu_shell_append(GTK_MENU_SHELL(menu), menu_item_open_file);
    gtk_menu_shell_append(GTK_MENU_SHELL(menu), menu_item_reopen_recent_item);
    gtk_menu_shell_append(GTK_MENU_SHELL(menu), menu_item_save_file);
    gtk_menu_shell_append(GTK_MENU_SHELL(menu), menu_item_close_file);
    gtk_menu_shell_append(GTK_MENU_SHELL(menu), menu_item_quit);
    gtk_menu_shell_append(GTK_MENU_SHELL(menubar), menu_item);

    g_signal_connect(G_OBJECT(menu_item_quit), "activate", G_CALLBACK(gtk_main_quit), NULL);

    return 0;
}


int
set_menu_Edit(GtkWidget *menubar)
{
    static const char menu_item_text[] = "_Edit";
    static const char menu_item_copy_text[] = "Copy";
    static const char menu_item_cut_text[] = "Cut";
    static const char menu_item_paste_text[] = "Paste";

    GtkWidget *menu;
    GtkWidget *menu_item;
    GtkWidget *menu_item_cut;
    GtkWidget *menu_item_copy;
    GtkWidget *menu_item_paste;

    menu = gtk_menu_new();
    menu_item = gtk_menu_item_new_with_mnemonic(menu_item_text);
    menu_item_cut = gtk_menu_item_new_with_label(menu_item_cut_text);
    menu_item_copy = gtk_menu_item_new_with_label(menu_item_copy_text);
    menu_item_paste = gtk_menu_item_new_with_label(menu_item_paste_text);

    gtk_menu_item_set_submenu(GTK_MENU_ITEM(menu_item), menu);
    gtk_menu_shell_append(GTK_MENU_SHELL(menu), menu_item_cut);
    gtk_menu_shell_append(GTK_MENU_SHELL(menu), menu_item_copy);
    gtk_menu_shell_append(GTK_MENU_SHELL(menu), menu_item_paste);
    gtk_menu_shell_append(GTK_MENU_SHELL(menubar), menu_item);

    return 0;
}


int
set_menu_View(GtkWidget *menubar, GtkWidget *statusbar)
{
    static const char menu_item_text[] = "_View";
    static const char menu_item_view_statusbar_text[] = "View status bar";
    static const char menu_item_view_console_text[] = "View console";

    GtkWidget *menu;
    GtkWidget *menu_item;
    GtkWidget *menu_item_view_console;
    GtkWidget *menu_item_view_statusbar;

    menu = gtk_menu_new();

    menu_item = gtk_menu_item_new_with_mnemonic(menu_item_text);
    menu_item_view_statusbar = gtk_check_menu_item_new_with_label(menu_item_view_statusbar_text);
    menu_item_view_console = gtk_check_menu_item_new_with_label(menu_item_view_console_text);

    gtk_menu_item_set_submenu(GTK_MENU_ITEM(menu_item), menu);
    gtk_menu_shell_append(GTK_MENU_SHELL(menu), menu_item_view_console);
    gtk_menu_shell_append(GTK_MENU_SHELL(menu), menu_item_view_statusbar);
    gtk_menu_shell_append(GTK_MENU_SHELL(menubar), menu_item);

    gtk_check_menu_item_set_active(GTK_CHECK_MENU_ITEM(menu_item_view_statusbar), TRUE);

    g_signal_connect(G_OBJECT(menu_item_view_statusbar), "activate", G_CALLBACK(toggle_statusbar), statusbar);

    return 0;
}


int
set_menu_Preferences(GtkWidget *menubar)
{
    static const char menu_item_text[] = "_Preferences";

    GtkWidget *menu;
    GtkWidget *menu_item;

    menu = gtk_menu_new();
    menu_item = gtk_menu_item_new_with_mnemonic(menu_item_text);

    gtk_menu_item_set_submenu(GTK_MENU_ITEM(menu_item), menu);
    gtk_menu_shell_append(GTK_MENU_SHELL(menubar), menu_item);

    return 0;
}


int
set_menu_Help(GtkWidget *menubar)
{
    static const char menu_item_text[] = "_Help";

    GtkWidget *menu;
    GtkWidget *menu_item;

    menu = gtk_menu_new();
    menu_item = gtk_menu_item_new_with_mnemonic(menu_item_text);

    gtk_menu_item_set_submenu(GTK_MENU_ITEM(menu_item), menu);
    gtk_menu_shell_append(GTK_MENU_SHELL(menubar), menu_item);

    return 0;
}

