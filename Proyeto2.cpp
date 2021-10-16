#include <iostream>
#include <fstream>

using namespace std;

int opciones(){
	int x;
	system("cls");
	cout<<"        Bienvenido   "<<endl;
	cout<<"   Elija la opcion deseada   "<<endl;
	cout<<"1......Agregar Alumnos"<<endl;
	cout<<"2......Buscar Alumnos"<<endl;
	cout<<"3......Modificar Alumnos"<<endl; 
	cin>>x;
	return x;
}

typedef struct {
	string nombre;
	string carne;
	string correo;
	string seccion;
	string carneaux;
	int ciclo;
	string estado;
	string estadoaux;
	float promedio;
	float promedioaux;
}alumno;


bool registro (string p){
 ifstream leer ("registros.txt", ios::in);
 alumno v;
 leer>>v.nombre;
 while(!leer.eof()){
  leer>>v.carne;
  if(v.carne == p){
	cout<<"Alumno duplicado"<<endl;
   system("pause");
   leer.close();
   return false;
  }
  leer>>v.nombre;
 }
   leer.close();
   return true; 
}

void agregar (ofstream &es){
	system("cls");
	es.open("registros.txt",ios::out|ios::app);
	alumno p;
	cout<<"ingrese nombre: "<<endl;
	cin>>p.nombre;
	cout<<"ingrese carne: "<<endl;
	cin>>p.carne ;
	cout<<"ingrese correo: "<<endl;
	cin>>p.correo;
	cout<<"ingrese seccion: "<<endl;
	cin>>p.seccion;
	cout<<"ingrese ciclo: "<<endl;
	cin>>p.ciclo;
	cout<<"ingrese estado: "<<endl;
	cin>>p.estado;
	cout<<"ingrese promedio: "<<endl;
	cin>>p.promedio;
	if(registro(p.carne))
	es<<p.nombre<<" "<<p.carne<<" "<<p.correo<<" "<<p.seccion<<" "<<p.ciclo<<" "<<p.estado<<" "<<p.promedio<<endl;
	es.close();
}

void buscar (ifstream &lec){
	system("cls");
	lec.open("registros.txt",ios::in);
	alumno a;
	bool dato = false;
	cout<<"ingrese el numero de carne: ";
	cin>>a.carneaux;
	lec>>a.nombre;
	if(lec.is_open()){
		while(!lec.eof() && !dato){
			lec>>a.carne;
			lec>>a.correo;
			lec>>a.seccion;
			lec>>a.ciclo;
			lec>>a.estado;
			lec>>a.promedio;
			if(a.carne==a.carneaux){
				cout<<"Nombre: "<<a.nombre<<endl;
				cout<<"Carne: "<<a.carne<<endl;
				cout<<"Correo: "<<a.correo<<endl;
				cout<<"Seccion: "<<a.seccion<<endl;
				cout<<"Ciclo: "<<a.ciclo<<endl;
				cout<<"Estado: "<<a.estado<<endl;
				cout<<"Promedio: "<<a.promedio<<endl;
				dato = true;		
			}
			lec>>a.nombre;
		}
		lec.close();
		
		if(!dato)
			cout<<"Alumno no registrado"<<endl;
	}else{
		cout<<"no se encontro el archivo"<<endl;
	}
	system("pause");
}

void cambio (ifstream &lec){
	system("cls");
	alumno h;
	lec.open("registros.txt",ios::in);
	ofstream aux("registrostemp.txt",ios::out);
	if(lec.is_open()){
		cout<<"ingrese carne a buscar: ";
		cin>>h.carneaux;
		lec>>h.nombre;
		while(!lec.eof()){
			lec>>h.carne;
			lec>>h.correo;
			lec>>h.seccion;
			lec>>h.ciclo;
			lec>>h.estado;
			lec>>h.promedio;
			if(h.carne ==h.carneaux){
				cout<<"Ingrese el nuevo estado: "<<endl;
				cin>>h.estadoaux;
				cout<<"Ingrese el nuevo Promedio: "<<endl;
				cin>>h.promedioaux;
				aux<<h.nombre<<" "<<h.carne<<" "<<h.correo<<" "<<h.seccion<<" "<<h.ciclo<<" "<<h.estadoaux<<" "<<h.promedioaux<<endl;
				}else{
				aux<<h.nombre<<" "<<h.carne<<" "<<h.correo<<" "<<h.seccion<<" "<<h.ciclo<<" "<<h.estado<<" "<<h.promedio<<endl;
			}
			lec>>h.nombre;
			
		}
		lec.close();
		aux.close(); 

	}else
		remove("registros.txt");
		rename("registrostemp.txt","registros.txt");
}

int main(){
	ofstream esc;
	ifstream lec;
	int op;
	do{
		op=opciones();
		switch(op){
			case 1:
				agregar(esc);
			break;
			case 2:
				buscar(lec);
			break;
			case 3:
				cambio(lec);
			break;
		}
	}while(op!=4);
	
	return 0;
}
