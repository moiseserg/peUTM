
Attachment articuloSSLvL02.pdf successfully uploaded and added.Conversation opened. 1 unread message.

Skip to content
Using Gmail with screen readers
3
Search



Gmail
COMPOSE
Labels
Inbox (60)
Important
Sent Mail
Drafts (17)
Spam (136)
Trash
Circles
acm (171)
alumnos
banco (88)
carnalito
Chistes
claves
compra
facturas
fastweb
futbol
Impuestos
moiseserg@hotmail.com
MTCA
Otros
pendientes
Prope Pseint
PSP
resdi
utm (87)
work
More 
Hangouts

 
 
 
 
  More 
3 of 10,523  
 
Print all In new window
Ramos Ortiz Juan Manuel
Inbox
x  
adj
x 

Juan Manuel Ramos Ortiz
AttachmentsDec 8 (1 day ago)

to me 
Buenas noches profesor, aquí están los dos códigos que me pidió el quicksort que había hecho aunque siento que no es tan rápido realmente, y el de hoy el segundo que dejó
2 Attachments 
 
	
Click here to Reply or Forward
12.4 GB (82%) of 15 GB used
Manage
Terms - Privacy
Last account activity: 0 minutes ago
Details
Juan Manuel Ramos Ortiz
Add to circles

Recent photos
View photo in messageView photo in messageView photo in message
Show details


#include <stdio.h>
void imp(int v[], int n){
	int i;
	for (i=0; i<n; i++)
		printf("%d ", v[i]);
	printf("\n");
}
void quick(int v[], int n, int iz, int der, int i,int j, int piv){
		if(piv<j){
			if (j<=i){
				if(v[piv]>v[i]){
					int t=v[i];
					v[i]=v[piv];
					v[piv]=t;
					imp(v, 8);
					printf("%d %d %d\n", i, j, piv);
					quick(v, n, iz, der, i-1, j, i);
				}
				else {
					if(i!=1)
						quick(v,n,iz,der,i-1, j, piv);
				}
			}
			else
				quick(v, n, iz, der, der, iz, 0);
		}
		else if (piv>i){
			if (j<=i){
				if (v[j]>v[piv]){
					int t=v[j];
					v[j]=v[piv];
					v[piv]= t;
					imp (v, n);
					printf("%d %d %d\n", i, j, piv);
					quick (v, n, iz, der, i, j+1, j);
				}
				else {
					quick (v, n, iz, der, i, j+1, piv);
					}
			}
			else 
				quick(v, n, iz, der, der, iz, 0);
		}
	}

int main(){
	int v[10]={100, 2, 15, 20, 75, 10, 7, 15};
	quick(v, 8, 1, 7, 7, 1, 0);
	quick(v, 8, 1, 7, 7, 1, 7);
	imp(v, 8);
	return 0;
}
quicksort.c
Open with
Displaying SN2.cpp.
