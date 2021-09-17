#include <stdio.h>
 #include <stdlib.h>
 #include <windows.h>
 #define MAX_LONG 90
 #define ARRIBA 72
 #define ABAJO 80
 #define ENTER 13
 #define M 5
 HANDLE hCon;
 struct nodo
 {
   int n; // n < M nฐ de claves en el nodo siempre serแ menor que el orden del B tree
   int arreglo_claves[M-1]; //arreglo de claves
   struct nodo *p[M]; // (n+1 punteros que van a ser usados 
 }*root=NULL;//la raiz lo inicializamos en NULL

 enum Estado_Clave { Duplicado,SearchFailure,Exacto,Insertado,LessKeys };//estados de las claves
 void Insertar_Nodo(int clave);
 void Imprimir_ArbolB(struct nodo *root,int);
 void Borrar_Nodo(int x);
 void Buscar_Nodo(int x);
 enum Estado_Clave ins(struct nodo *r, int x, int* y, struct nodo** u);
 int  BuscarPosicion(int x,int *key_arr, int n);
 enum Estado_Clave del(struct nodo *r, int x);
 void SetColor(int i);

 int menu(char (*text)[MAX_LONG], int max)
 {
  int tecla, op=0, i;
  while(tecla!=ENTER)
  {
    system("CLS");
                 for(i=0;i<max;i++)
                 {
                   if(op==i)//si es igual coloreo la opci๓n
                   SetColor(10);
                   printf("\t%s\n",text[i]);
                   SetColor(15);
                 }
                 do
                 {
                    tecla=getch();//capturo la tecla mientras se presione 
                                  //diferente a arriba,abajo o enter
                 }while(tecla!=ARRIBA && tecla!= ABAJO && tecla!= ENTER);
    switch(tecla)
    {
      case ARRIBA:{
                   (op==0)? op=max-1 : op--; break;
                  }

      case ABAJO: {
                   (op==max-1)? op=0 : op++; break;
                  }
   }
  }
  op+=1;
  return op; //retorna la opcion +1 
 }

 int main()
 {
   int clave,op,band=0;
   char text[8][MAX_LONG]={
                             {"\t ษอออออออออออออออออออออออออออออออออออออออออออออออป "},
                             {"\t บ Implementacion de un Arbol B บ "},
                             {"\t ศอออออออออออออออออออออออออออออออออออออออออออออออผ\n"},
                             {"[1] Insertar elemento"},
                             {"[2] Eliminar elemento"},
                             {"[3] Buscar elemento"},
                             {"[4] Mostrar Arbol B"},
                             {"[5] Salir"}};//se inicializan
   while(op!=8)
     {
      switch(op=menu(text,8))
      {
       case 4:
                    {
                      band=1;
                      SetColor(15);printf("\n Insertar clave : ");SetColor(15);scanf("%d",&clave);
                      Insertar_Nodo(clave);
                      getch();
                      break;
                    }
       case 5:
                    {
                      if(band==1)
                      {
                      SetColor(15);printf("\n Insertar clave a eliminar : ");SetColor(15);scanf("%d",&clave);
                      Borrar_Nodo(clave);
                      }
                      else
                      printf(" El arbol esta vacio ");
                      getch();
                      break;
                    }
       case 6:
                    {
                      if(band==1)
                      {
                      SetColor(15);printf(" Insertar clave a buscar : ");SetColor(15);scanf("%d",&clave);
                      Buscar_Nodo(clave);
                      }
                      else
                      printf(" El arbol esta vacio ");
                      getch();
                      break;
                    }
       case 7:
                    {
                      if(band==1)
                      {
                      SetColor(15);printf("\t\t\t El Arbol B es : ");SetColor(15);
                      printf("\n");
                      Imprimir_ArbolB(root,0);
                      }
                      else
                      printf("\t\t\t El arbol esta vacio ");
                      getch();
                      break;
                    }
       case 8:
                    {
                      SetColor(15);printf("\t\t Hasta la proxima :3 ");
                      getch();
                      exit(1);
                      break;
                    }
       }
     }
     return 0;
 }

 void Insertar_Nodo(int clave)
 {
    struct nodo *newnodo;
    int upKey;
    enum Estado_Clave value;
    value = ins(root, clave, &upKey, &newnodo);
    if (value == Duplicado)//si ingresamos un valor duplicado
        printf("El elemento ya esta insertada\n");
    if (value == Insertado)//si es nuevo,asigno memoria y creo la clave
       {
        struct nodo *uproot = root;
        root=malloc(sizeof(struct nodo));
        root->n = 1;
        root->arreglo_claves[0] = upKey;
        root->p[0] = uproot;
        root->p[1] = newnodo;
       }
 }

 //le asignamos un estado a la clave(ya sea que esta duplicada,etc)
 enum Estado_Clave ins(struct nodo *ptr, int clave, int *upKey,struct nodo**newnodo)
 {
    struct nodo *newPtr, *lastPtr;
    int pos, i, n,splitPos;
    int nueva_clave, ultima_clave;
    enum Estado_Clave value;
    if (ptr == NULL)
       {
        *newnodo = NULL;
        *upKey = clave;
                                           return Insertado;
       }
    n = ptr->n;
    pos = BuscarPosicion(clave, ptr->arreglo_claves, n);
    if (pos < n && clave == ptr->arreglo_claves[pos])
                                          return Duplicado;
   value = ins(ptr->p[pos], clave, &nueva_clave, &newPtr);
   if (value != Insertado)
                                          return value;

   //Si la clave en el nodo es menor que M-1 donde M es el orden de B tree
   if (n < M - 1)
   {
       pos = BuscarPosicion(nueva_clave, ptr->arreglo_claves, n);
       //Desplazamiento de una clave y puntero(derecha) inserta una nueva clave
      for (i=n; i>pos; i--)
       {
       ptr->arreglo_claves[i] = ptr->arreglo_claves[i-1];
       ptr->p[i+1] = ptr->p[i];
       }
       //La clave es insertada en su puesto exacto
       ptr->arreglo_claves[pos] = nueva_clave;
       ptr->p[pos+1] = newPtr;
       ++ptr->n;//incrementamos el numero de claves en el nodo
                                           return Exacto;//exact0
   }
   //Si la clave es la mayor,la posici๓n del nodo es insertada al final
   if (pos == M - 1)
   {
      ultima_clave = nueva_clave;
      lastPtr = newPtr;
      }
   else /*If keys in node are maximum and position of node to be inserted is not last*/
   {
      ultima_clave = ptr->arreglo_claves[M-2];
      lastPtr = ptr->p[M-1];
      for (i=M-2; i>pos; i--)
       {
         ptr->arreglo_claves[i] = ptr->arreglo_claves[i-1];
         ptr->p[i+1] = ptr->p[i];
       }
       ptr->arreglo_claves[pos] = nueva_clave;
       ptr->p[pos+1] = newPtr;
    }
    splitPos = (M - 1)/2;//Dividimos 
    (*upKey) = ptr->arreglo_claves[splitPos];
    (*newnodo)=malloc(sizeof(struct nodo));/*Nodo a la derecha despu้s de dividir*/
    ptr->n = splitPos; /*N บ de teclas para el nodo dividido a la izquierda*/
    (*newnodo)->n = M -1-splitPos;/*No. of keys for right splitted node*/
    for (i=0; i < (*newnodo)->n; i++)
    {
    (*newnodo)->p[i] = ptr->p[i + splitPos + 1];
     if(i < (*newnodo)->n - 1)
        (*newnodo)->arreglo_claves[i] = ptr->arreglo_claves[i + splitPos + 1];
     else
        (*newnodo)->arreglo_claves[i] = ultima_clave;
    }
        (*newnodo)->p[(*newnodo)->n] = lastPtr;
 return Insertado;
 }

 void Imprimir_ArbolB(struct nodo *ptr, int blanks)
{
  if (ptr)
   {
    int i;
    for(i=1;i<=blanks;i++)
    printf("");
    for (i=0; i < ptr->n; i++)
         printf("\t%d",ptr->arreglo_claves[i]);
         printf("\n");
    for (i=0; i <= ptr->n; i++)
         Imprimir_ArbolB(ptr->p[i], blanks+10);
 }
 }

 void Buscar_Nodo(int clave)
 {
    int pos, i, n;
    struct nodo *ptr = root;
    printf(" El camino del arbol:\n");
    while (ptr)
    {
     n = ptr->n;
     for (i=0; i < ptr->n; i++)
          printf("\t%d",ptr->arreglo_claves[i]);
          printf("\n");
          pos = BuscarPosicion(clave, ptr->arreglo_claves, n);
          if (pos < n && clave == ptr->arreglo_claves[pos])
             {
              printf("\t\t\t El elemento %d fue encontrado\n",clave,i);
              return;
             }
     ptr = ptr->p[pos];
    }
    printf("\t\t\t El elemento %d NO fue encontrado\n",clave);
 }

 int BuscarPosicion(int clave, int *key_arr, int n)
 {
    int pos=0;
    while (pos < n && clave > key_arr[pos])
    pos++;
    return pos;
 }

 void Borrar_Nodo(int clave)
 {
    struct nodo *uproot;
    enum Estado_Clave value;
    value = del(root,clave);
    switch (value)
                 {
                  case SearchFailure:
                                     printf("El elemento %d no esta disponible para eliminar\n",clave);
                                     break;
                  case LessKeys:
                                     uproot = root;
                                     root = root->p[0];
                                     free(uproot);
                                     break;
                 }
 }

 enum Estado_Clave del(struct nodo *ptr, int clave)
 {
    int pos, i, pivot, n ,min;
    int *key_arr;
    enum Estado_Clave value;
    struct nodo **p,*lptr,*rptr;

    if (ptr == NULL)  return SearchFailure;
   //Asigna valores del nodo

    n=ptr->n;
    key_arr = ptr->arreglo_claves;
    p = ptr->p;
    min = (M - 1)/2;//minimo numero de claves

    pos = BuscarPosicion(clave, key_arr, n);
    if (p[0] == NULL)
    {
       if (pos == n || clave < key_arr[pos]) return SearchFailure;

       for (i=pos+1; i < n; i++)
       {
           key_arr[i-1] = key_arr[i];
           p[i] = p[i+1];
      }
       return --ptr->n >= (ptr==root ? 1 : min) ? Exacto : LessKeys;
     }

    if (pos < n && clave == key_arr[pos])
    {
        struct nodo *qp = p[pos], *qp1;
        int nkey;
        while(1)
        {
         nkey = qp->n;
        qp1 = qp->p[nkey];
         if (qp1 == NULL)
             break;
             qp = qp1;
        }
    key_arr[pos] = qp->arreglo_claves[nkey-1];
    qp->arreglo_claves[nkey - 1] = clave;
    }
     value = del(p[pos], clave);
    if (value != LessKeys)  return value;
    if (pos > 0 && p[pos-1]->n > min)
    {
       pivot = pos - 1; //pivote para nodo izquierda y derecha
       lptr = p[pivot];
       rptr = p[pos];
       //Asignar valores al nodo derecho
       rptr->p[rptr->n + 1] = rptr->p[rptr->n];
       for (i=rptr->n; i>0; i--)
       {
            rptr->arreglo_claves[i] = rptr->arreglo_claves[i-1];
            rptr->p[i] = rptr->p[i-1];
       }
        rptr->n++;
        rptr->arreglo_claves[0] = key_arr[pivot];
        rptr->p[0] = lptr->p[lptr->n];
        key_arr[pivot] = lptr->arreglo_claves[--lptr->n];
        return Exacto;
     }
     if (pos > min)
     {
         pivot = pos;//pivote para nodo izquierda y derecha
         lptr = p[pivot];
         rptr = p[pivot+1];
         //Asignar valores al nodo izquierdo
         lptr->arreglo_claves[lptr->n] = key_arr[pivot];
         lptr->p[lptr->n + 1] = rptr->p[0];
         key_arr[pivot] = rptr->arreglo_claves[0];
         lptr->n++;
         rptr->n--;
         for (i=0; i < rptr->n; i++)
         {
              rptr->arreglo_claves[i] = rptr->arreglo_claves[i+1];
              rptr->p[i] = rptr->p[i+1];
         }
         rptr->p[rptr->n] = rptr->p[rptr->n + 1];
        return Exacto;
    }

     if(pos == n)
        pivot = pos-1;
     else
        pivot = pos;
        lptr = p[pivot];
        rptr = p[pivot+1];
        //mezclar nodo derecho con nodo izquierdo
        lptr->arreglo_claves[lptr->n] = key_arr[pivot];
        lptr->p[lptr->n + 1] = rptr->p[0];
        for (i=0; i < rptr->n; i++)
        {
            lptr->arreglo_claves[lptr->n + 1 + i] = rptr->arreglo_claves[i];
            lptr->p[lptr->n + 2 + i] = rptr->p[i+1];
        }
        lptr->n = lptr->n + rptr->n +1;
        free(rptr);//Remover nodo derecho
        for (i=pos+1; i < n; i++)
        {
             key_arr[i-1] = key_arr[i];
             p[i] = p[i+1];
        }
     return --ptr->n >= (ptr == root ? 1 : min) ? Exacto : LessKeys;
 }

 void SetColor(int i)
 {
         if(hCon == NULL)
                 hCon = GetStdHandle(STD_OUTPUT_HANDLE);

                 SetConsoleTextAttribute(hCon, i);
 }


