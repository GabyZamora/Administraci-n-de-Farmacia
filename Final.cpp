//Estudiantes: Teresa de Jesús González Guevara
//Sheyla Marisol Guidos Berrios
//Gabriela Carolina Zamora Alvarado
//Proyecto N°5 Administración de una Farmacia
#include <iostream>
#include <stdlib.h>
#include <string>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <fstream>
#include <iomanip>

using namespace std;

class Medicina{
	public:
		void BuyMedicine();
		void ShowItemList();
		void AddItemList();
		void DeleteStockItem();
		void Resumen();
		void Salir();
	Medicina();
};

Medicina::Medicina(){
	//constructor
}

struct node {
	int Num_Orden;
	string Cliente;
	string Fecha;
	int cantidad[10];
	string type = {"OTC"};
	int n, Menu[10];
		double cifra[10];
		
		string Nombre_Medicina[10]={"Hierro(Tabletas)", "Acetaminofen(500mg)","Amoxicilina",
		 "Peptobismol","Intestinomicina", "Alka-Seltzer","Vick-Vaporub(100g)", "Ibuprofeno", 
		 "Clorfeniramina(Tabletas)","Dorival"};
		 double Precio[10]={3.00,1.50,2.50,4.00,0.75,0.50,3.50,1.00,0.50,2.50};
		 double total;
		 
	
	node *next;
	
} *q, *temp; //Punteros

node *start_ptr = NULL;
node *last =  NULL;

int main(){
Medicina med;
int menu;
do{
	system("cls");
	cout<<"\t\t\t Bienvenido a la Farmacia \n";
	cout<<"\t\t--------------------------------------------------\n";
	cout<<"\t\t |\t   1. Comprar medicina \t\t|\n";
	cout<<"\t\t |\t   2. Mostrar Orden    \t\t|\n";
	cout<<"\t\t |\t   3. Modificar Orden  \t\t|\n";
	cout<<"\t\t |\t   4. Resumen          \t\t|\n";
	cout<<"\t\t |\t   5. Borrar           \t\t|\n";
	cout<<"\t\t |\t   6. Salir            \t\t|\n";
	cout<<"\t\t--------------------------------------------------\n";
	cout<<"Ingrese opcion: ";
	cin>>menu;
	
	switch (menu)
	{
		case 1:
			{
				med.BuyMedicine();
				break;
			}
		case 2:
			{
				med.ShowItemList();
				system("PAUSE");
				break;
			}
		case 3:
			{
				med.AddItemList();
				system("PAUSE");
				break;
			}
		case 4:
			{
				med.Resumen();
				system("PAUSE");
				break;
			}
		case 5:
			{
				med.DeleteStockItem();
				system("PAUSE");
				break;
			}
		case 6:{
			med.Salir();
			break;
		}
		
		default:
			{
				cout<<"Tu dato ingresado es incorrecto ERROR!"<<endl;
			}
	}//Fin del Switch case
}while(menu!=6);
cout<<"Gracias"<<endl;
system("PAUSE");
return 0;
}

void Medicina::BuyMedicine()
{
	system("cls");
	int m;
	
	
	cout<<"Detalles de la Orden \n";
	
	node *temp;
	temp = new node;
	
			cout<<"-------------------------------------------------------------\n\n";
			cout<<"Codigo|"<<"\t\tTipo|"<<" \t\tNombre de Medicina|"<<"\t\tPrecio($)|"<<endl;
			cout<<"---------------------------------------------------------------\n";
				cout<<"01"<<"\tOTC"<<"\t\t"<<"Hierro(Tabletas)"<<        "\t\t"<<"$3.00"<<endl;
				cout<<"02"<<"\tOTC"<<"\t\t"<<"Acetaminofen(500g)"<<      "\t\t"<<"$1.50"<<endl;
				cout<<"03"<<"\tOTC"<<"\t\t"<<"Amoxicilina"<<             "\t\t"<<"$2.50"<<endl;
				cout<<"04"<<"\tOTC"<<"\t\t"<<"Peptobismol"<<             "\t\t"<<"$4.00"<<endl;
				cout<<"05"<<"\tOTC"<<"\t\t"<<"Intestinomicina"<<         "\t\t"<<"$0.75"<<endl;
				cout<<"06"<<"\tOTC"<<"\t\t"<<"Alka-Seltzer"<<            "\t\t"<<"$0.50"<<endl;
				cout<<"07"<<"\tOTC"<<"\t\t"<<"Vick-Vaporub(100g)"<<      "\t\t"<<"$3.50"<<endl;
				cout<<"08"<<"\tOTC"<<"\t\t"<<"Ibuprofeno"<<              "\t\t"<<"$1.00"<<endl;
				cout<<"09"<<"\tOTC"<<"\t\t"<<"Clorfeniramina(Tabletas)"<<"\t\t"<<"$0.50"<<endl;
				cout<<"010"<<"\tOTC"<<"\t\t"<<"Dorival"<<                "\t\t"<<"$2.50"<<endl;
				
	temp = new node;
	cout << "Numero de Orden: ";
		cin>>temp ->Num_Orden;
	cout<< "Ingrese apellido del Cliente: ";
	cin>> temp -> Cliente;
	cout<<"Ingresar fecha:";
	cin>>temp->Fecha;
	cout<<"Cuantas medicinas desea ordenar:"<<endl;
	cout<<"(Maximo de orden es de 10 Items por transaccion)\n";
	cout<<" ";
	cin>> temp->n;
	if(temp->n >10)
	{
		cout<<"La medicina excede el maximo de items permitidos por transaccion";
		system("pause");
	}
	else{
		for(m=0; m<temp->n; m++){
			cout<<"Ingrese codigo del medicamento:" <<endl;
			cin>>temp->Menu[m];
			cout<<"Nombre de la Medicina: " <<temp->Nombre_Medicina[temp->Menu[m]-1]<<endl;
			cout<<"¿Cuantas medicinas desea?: ";
			cin>>temp->cantidad[m];
			temp->cifra[m] = temp->cantidad[m] *temp->Precio
			[temp->Menu[m]-1];
			cout<<"La cifra que debes pagar es: "<<temp->cifra[m]<<"USD"<<endl;
			system("pause");
		
		}
	cout<<"Orden realizada exitosamente"<<endl;
	cout<<"Ir al menu para pagar factura"<<endl;
	system("pause");
	
		temp->next=NULL;
		if(start_ptr!=NULL)
		{
			temp->next=start_ptr;
		}
		start_ptr=temp;
		system("cls");
	
	}
}

void Medicina::ShowItemList()
{
	int m, n1, n2;
	bool found;
	system("cls");
	node *temp;
	
	temp = start_ptr;
	found = false;
	
	cout<<"Ingrese numero de orden para imprimir receta:\n";
	cin>>n2;
	cout<<"\n";
	cout<<"\t\tLa lista del orden:";
	
	if(temp==NULL)
	{
		cout<<"\t No hay orden que mostrar\n\t\t La lista está vacia\n\n\n";
	}
	while(temp!=NULL && !found)
	{
		if(temp->Num_Orden==n2)
		{
			found= true;
		}
		else
		{
			temp= temp->next;
		}
			if(found)
			{   
				cout<<"Numero de Orden: "<<temp->Num_Orden;
				cout<<"\n";
				cout<<"Nombre del Cliente: "<<temp->Cliente<<endl;
				cout<<"Fecha: "<<temp->Fecha<<endl;
			
			cout<<"---------------------------------------------------------"<<endl;
			cout<<"|Tipo de Medicina|Nombre de Medicina|Cantidad|Precio Total|"<<endl;
			cout<<"----------------------------------------------------------"<<endl;
			for(m=0; m<temp->n;m++)
			{
				cout<<temp->type<<"\t\t";
				cout<<temp->Nombre_Medicina[temp->Menu[m]-1]<<"\t\t\t";
				cout<<temp->cantidad[m]<<"\t\t";
				cout<<temp->cifra[m]<<"USD"<<endl;
				
			}
	
			
			temp->total=temp->cifra[0]+temp->cifra[1]+temp->cifra[2]+temp->cifra[3]+
			temp->cifra[4]+temp->cifra[5]+temp->cifra[6]+temp->cifra[7]+temp->cifra[8]+
			temp->cifra[9];	
			cout<<"Cuenta total es:"<<temp->total;
			cout<<"\n";
			cout<<"Ingresa el monto exacto que debes pagar:";
				cin>>n1;
				
			cout<<"\n";
			cout<<"\n";
			cout<<"Pago finalizado\n Gracias\n";
			}
	
    }
}

void Medicina::DeleteStockItem()
{
	system("cls");
	int n, n3, count;
	cout<<"Ingrese el dato que desea eliminar:\n";
	cin>>n3;
	node *q;
	node *temp;
	bool found;
	
	if(start_ptr == NULL)
	
		cout<<"No se puede eliminar una lista vacia \n";
	else
	{
		if(start_ptr->Num_Orden==n3)
		{
			q = start_ptr;
			start_ptr = start_ptr->next;
			count--;
			if(start_ptr == NULL)
			last = NULL;
			delete q;
			cout<<"La orden ha sido eliminado exitosamente"<<endl;
			
		}	
		else
		{
			found = false;
			temp = start_ptr;
			q = start_ptr->next;
			
		while((!found)&&(q!= NULL))
		{
			if(q->Num_Orden != n3)
			{
				temp = q;
				q = q->next;
			}
			else
			found = true;
		}
		
		if(found)
		{
			temp->next = q->next;
			count--;
			
			if(last ==q)
			last = temp;
			delete q;
			cout<<"La orden ha sido eliminada exitosamente"<<endl;
		}
		else
		cout<<"El producto no se encuentra en la lista"<<endl;
		}
	}
}

void Medicina::AddItemList()
{
  	system("cls");
  	int m, chan;
  	bool found;
  	found = false;
  	temp = start_ptr;
  	cout<<"Ingrese numero de orden a modificar:";
  	cin>>chan;
  	if(temp==NULL && chan==0)
  	{
  		cout<<"No hay orden que modificar!"<<endl;
	}
	else
	{
		while(temp !=NULL && !found)
		{
			if(temp->Num_Orden==chan)
			{
				found = true;
			}
			else
			{
				temp= temp->next;
			}
			if(found)
			{
				cout<<"Cambia numero de Orden:";
				cin>>temp->Num_Orden;
				cout<<"Cambiar nombre de cliente:";
				cin>>temp->Cliente;
				cout<<"Cambiar fecha:";
				cin>>temp->Fecha;
				cout<<"¿Cuantas medicinas desea cambiar:"<<endl;
				cout<<"(El maximo de orden es 10 articulos por transaccion)\n";
				cout<<" ";
				cin>>temp->n;
				if(temp->n >10)
				{
					cout<<"Tu orden de medicinas excede el maximo permitido!";
					system("pause");
				}
				else{
					for(m=0; m<temp->n; m++)
					{
						cout<<"Ingrese codigo de medicamento que desea cambiar:"<<endl;
						cin>>temp->Menu[m];
						cout<<"Cambiar nombre de medicina: "<<temp->Nombre_Medicina[temp->Menu[m]-1]<<endl;
						cout<<"¿Cuantos medicamentos nuevos desea: ";
						cin>>temp->cantidad[m];
						temp->cifra[m] = temp->cantidad[m] * temp->Precio[temp->Menu[m]-1];
						cout<<"El costo que debes pagar despues de modificar es:"<<temp->cifra[m]<<"USD"<<endl;
						system("pause");
					}
					temp = temp->next;
				    system("cls");
				
				}
				cout<<"Registro modificado exitosamente!"<<endl;
				
				
					
			}
			else{
				if(temp!=NULL && temp->Num_Orden !=chan)
				{
					cout<<"Numero de orden invalido"<<endl;
				}
			}
		}
	}
}

void Medicina::Resumen()
{
	int m, n4;
	system("cls");
	node *temp;
	
	temp=start_ptr;
	
	if(temp==NULL)
	{
		cout<<"No hay orden que mostrar\n\t\t Así que la lista esta vacia\n\n\n";
		
	}
	else{
		cout<<"\n";
		cout<<"____________________________________________________________________"<<endl;
		cout<<"Este es el resumen de ordenes del dia\n";
		cout<<"____________________________________________________________________"<<endl;
		while(temp!=NULL)
		{
			cout<<"Numero de Orden: "<<temp->Num_Orden;
			cout<<"\n";
			cout<<"Nombre del cliente:"<<temp->Cliente<<endl;
			cout<<"Fecha:"<<temp->Fecha<<endl;
			
				cout<<"---------------------------------------------------------"<<endl;
			cout<<"|Tipo de Medicina|Nombre de Medicina|Cantidad|Precio Total|"<<endl;
			cout<<"----------------------------------------------------------"<<endl;
			for(m=0; m<temp->n;m++)
			{
				cout<<temp->type<<"\t\t";
				cout<<temp->Nombre_Medicina[temp->Menu[m]-1]<<"\t\t\t";
				cout<<temp->cantidad[m]<<"\t\t";
				cout<<temp->cifra[m]<<"USD"<<endl;
		    }
				
					temp->total=temp->cifra[0]+temp->cifra[1]+temp->cifra[2]+temp->cifra[3]+
			temp->cifra[4]+temp->cifra[5]+temp->cifra[6]+temp->cifra[7]+temp->cifra[8]+
			temp->cifra[9];	
			cout<<"Cuenta total es:"<<temp->total;
			cout<<"\n";
			temp=temp->next;
					
			
		}
		
	}
	
}

void Medicina::Salir()
{
	cout<<"Has decidido salir\n"<<endl;
}


