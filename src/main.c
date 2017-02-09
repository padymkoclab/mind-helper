
// #include <stdio.h>
// #include <time.h>

// Posix headers
// #include <pthread.h>
// #include <unistd.h>

// The C standart library
#include <stdlib.h>

// GTK+
#include <gtk/gtk.h>
#include <glib.h>
#include <glib/gprintf.h>

#include "main_window.c"

// http://www.bravegnu.org/gtktext/gtktext-0.4.html
// https://github.com/incessantmeraki/sedit/blob/master/sedit.c
// https://cboard.cprogramming.com/c-programming/151019-graphical-text-editor-gtkplus.html
// https://developer.gnome.org/gtk3/stable/TextWidget.html
// http://stackoverflow.com/questions/26957506/how-to-open-and-save-a-file-in-gtk
// http://zetcode.com/gfx/cairo/cairodefinitions/


int main(int argc, char *argv[])
{
    app(argc, argv);
    return EXIT_SUCCESS;
}
