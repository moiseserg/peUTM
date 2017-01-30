#include <curses.h> //Incluiremos una librería a nuestro sistemas
#include <stdio.h>
#include <stdlib.h>
void salir (void);  //Esta función se utiliza al Salir del programa
int main(void)
{
   initscr();   /*Esta función inicializa los ncurses
   start_color(); //Esta función inicia los colores
//Define pares de colores que serán definidos en el programa
init_pair(1,COLOR_WHITE,COLOR_BLUE); //Texto(Blanco) | Fondo(Azul)
   init_pair(2,COLOR_BLUE,COLOR_WHITE); //Texto(Azul) | Fondo(Branco)
   init_pair(3,COLOR_RED,COLOR_WHITE);  //Texto(rojo) | Fundo(Blanco)
   bkgd(COLOR_PAIR(1));  /*Aqui define el color de fondo del programa
   attron(COLOR_PAIR(3));
   move(2,1);  //Aqui mueve el cursor a linea 2 columna 1.
   printw("Olá mundo!!!");  //Imprimimos el texto en la posición especificada 
                              en la linea anterior.
   attroff(COLOR_PAIR(3));  /*Esta alterando el par de colores por omisión*/
   attron(COLOR_PAIR(2));
   move(3,1);
   printw("Cualquier tecla para salir"); /*Imprime el texto en la posición
                                         especificada en la línea anterior */
   attroff(COLOR_PAIR(2));
   refresh();    //Actualiza la ventana
   getch();      //Espera que el usuario presione un tecla
   salir();    // llama a la función salir
}
/*********************************************************************/
void salir()
{
   endwin(); /*Siempre que finalizamos un programa con una biblioteca curses,
                    debemos ejecutar este comando.*/
   exit(0);
}