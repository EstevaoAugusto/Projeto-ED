/* Equipe:
 * Estevão Augusto da Fonseca Santos
 * Felipe Geraldo de Oliveira
 * Eduardo Cesar Cauduro Coelho
 */


#include <iostream>
#include <fstream>
#include <cstring>
#include <string>

using namespace std;

struct call991{
	int e = -1;
	int id = -1;//atributo secundario
	float lat = -1, lng = -1;
	char addr[60] = "-1"; //atributo primario
	char desc[30] = "-1", zip[30] = "-1", title[20] = "-1";
	char timeStamp[40] = "-1", twp[50] = "-1";
	
	
	void imprimir();
	void leitura(ifstream& ler);
	
	inline void padronizar(){
		e = -1;
		id = -1;
		lat = -1;
		lng = -1;
		addr[0] = '\0';
		desc[0] = '\0';
		zip[0] = '\0';
		title[0] = '\0';
		timeStamp[0] = '\0';
		twp[0] = '\0';
	}
};


//Id,lat,lng,desc,zip,title,timeStamp,twp,addr,e
void call991::imprimir(){
	cout << id << "  " << lat << "   " << lng << "   " << desc << "   " << 
	zip << "   " << title << "   " << timeStamp << "   " << twp << "   " << addr << "   " << e << endl;
}

void call991::leitura(ifstream& ler){
	
}

void processamento(ifstream& ler, string arquivo){
	call991 *c1 = new call991;
	int tam = 0;
	// int cabecalho = 0;
	ofstream escrever("binario.dat");
	string lixo;
	//string arquivo_res;
	char auxiliar[25];
	
	
	ler >> lixo;
	
	/* Id,   lat,         lng         ,desc                  ,zip          ,title       ,timeStamp                      ,twp                                       ,addr           					,e
	   0,    40.2978759,  -75.5812935,REINDEER CT & DEAD END;  NEW HANOVER; Station 332; 2015-12-10 @ 17:10:52;,19525.0,EMS: BACK PAINS/INJURY,2015-12-10 17:10:52,NEW HANOVER,REINDEER CT & DEAD END,1
	 */
	cout << "---------------------------------------------------------------------------------------------------------" << endl;
	cout << "| Id    | Lat    |  Lng   | desc    |   zip    |    title | timeStamp   |   twp    |   addr |   e    " << endl;
	cout << "----------------------------------------------------------------------------------------------------------" << endl << endl;
	while(tam < 3){
		ler >> c1->id;
		ler >> auxiliar[0];
		ler >> c1->lat;
		ler >> auxiliar[0];
		ler >> c1->lng;
		ler >> auxiliar[0];
		ler.getline(c1->desc, 30, ';');
		ler.getline(c1->zip, 30, ';');
		ler.getline(c1->title, 20,  ';');
		ler.getline(c1->timeStamp, 40, ';');
		ler >> auxiliar[0];
		
		ler.getline(c1->twp, 50, ',');
		strcat(c1->twp, ",");
		
		ler.getline(auxiliar, 30, ',');
		strcat(c1->twp, auxiliar);
		ler.getline(auxiliar, 30, ',');
		strcat(c1->twp, auxiliar);
		
		ler.getline(c1->addr, 60, ',');
		strcat(c1->addr, ",");
		ler.getline(auxiliar, 25, ',');
		strcat(c1->addr, auxiliar);
		
		ler >> c1->e;
		
		c1->imprimir();
		
		cout << "tam:" << tam << endl;
		
		
		c1->padronizar();
		
		tam++;
	}
	
	//cout << sizeof(c1->desc) << endl;
	//cout << sizeof(c1->desc.c_str()) << endl;//a funcao c_str() faz com que uma string retorne o seu conteudo em formato de vetor de caracteres
	
	// sizeof(aux) e sizeof(c1->desc.c_str()) resultam em valores diferentes
	// o primeiro resulta em 50 e o outro em 4;
	
	//char aux[50];
	//cout<< sizeof(aux) << endl;
	
	delete c1;
	escrever.close();
}


void converter(){
	
	string arquivo;
	cout << "Digite o nome do arquivo: ";
	//cin >> arquivo;
	// nome do arquivo é call911_2.csv
	arquivo = "Testes.csv";
	
	ifstream ler(arquivo);
	
	if(ler){
		cout << "Arquivo encontrado" << endl;
		processamento(ler, arquivo);
	} else {
		cout << "Arquivo nao encontrado!" << endl;
	}
	ler.close();
}

int main()
{
	char comando = '1';
	
	do{
		cout << "#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=" << endl;
		cout << "      Conversor de arquivo CSV para Binario" << endl;
		cout << "#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=" << endl << endl;
		
		cout << "1) Converter arquivo CSV" << endl;
		cout << "0) Sair" << endl << endl;
	
		cout << "#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=" << endl;
		cout << "Sua resposta: ";
		cin >> comando;
		cout << endl;
	
		switch(comando){
			case '1':
				converter();
				break;
			case '0':
				break;
			default:
				cout << "Opcao inexistente" << endl;
		}
	}while(comando != '0');
	
	return 0;
}
