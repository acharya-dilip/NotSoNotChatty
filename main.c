#include <stdio.h>
#include <gtk/gtk.h>
#include <curl/curl.h>

struct widgetMain {
    GtkWidget *windowMain;
    GtkWidget *gridParent;
}widgetMain;
static void activate (GtkApplication *app,gpointer user_data) {

    //Init of windowMain
    widgetMain.windowMain = gtk_application_window_new(app);
    gtk_window_set_title(GTK_WINDOW(widgetMain.windowMain),"NotSoNotChatty");
    gtk_window_set_default_size(GTK_WINDOW(widgetMain.windowMain),800,700);
    gtk_window_present(GTK_WINDOW(widgetMain.windowMain));

    //Init of gridParent
    widgetMain.gridParent = gtk_grid_new();
    gtk_window_set_child(GTK_WINDOW(widgetMain.windowMain),widgetMain.gridParent);



}

int main(int argc, char **argv) {
    GtkApplication *app;
    int status;
    app= gtk_application_new ("org.gtk.example", G_APPLICATION_DEFAULT_FLAGS);
    g_signal_connect (app, "activate", G_CALLBACK (activate), NULL);
    status = g_application_run (G_APPLICATION (app), argc, argv);
    g_object_unref (app);

    return status;
}