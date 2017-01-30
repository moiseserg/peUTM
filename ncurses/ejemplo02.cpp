/*Este ejemplo captura las teclas y muestra el valor devuelto
por cada uno de ellas. La tecla <Esc> parece más lenta pero eso
es debido a que existe la necesidad de distinguir un caracter <Esc>
aislado de una secuencia de caracteres que empiece por <Esc> y que
podría venir de una tecla de función por ejemplo.*/
#include <stdio.h>
#include <stdlib.h>
#include <curses.h>
WINDOW *win; /** manejaremos una única ventana de pantalla completa **/
/*********************************************************************/
void IniVideo(){
       win=initscr(); /* Crea la ventana */
       clear();  /* Borra la pantalla entera bajo ncurses */
       refresh(); /* Actualiza la ventana con los cambios */
       noecho();
       cbreak();
       keypad(win, TRUE);
}
/*************************/
void Exit(){
       refresh();
       endwin();
       exit(1);
}
/*****************************************************************/
int main () {
       IniVideo();
       move(7, 30); /* x , y */
       printw("Ctrl-C  para terminar");
       for(;;){
               move(12, 30); /* x , y */
               printw("%3d", getch());
               refresh();
       }
       Exit();
}