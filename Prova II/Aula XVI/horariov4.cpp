#include <iostream>

using namespace std;

class Horario {
	private:
	int h, m, s;
	bool horarioVerao;

	public:
	void setHora(int hora);
	void setMinuto(int minuto);
	void setSegundo(int segundo);
	void setHorario(int hora, int minuto, int segundo);
	int getHora();
	int getMinuto();
	int getSegundo();
	void printHorarioPadrao();
	void printHorarioUniversal();
	void adicionaHorario(Horario &horario);
	int getSegundosMeiaNoite();
	void setHorarioVerao(bool hv);
	bool getHorarioVerao();
};

void Horario::adicionaHorario(Horario &horario) {
	int hS = getHora() + horario.getHora();
	int mS = getMinuto() + horario.getMinuto();
	int sS = getSegundo() + horario.getSegundo();

	if (sS >= 60) {
		mS++;
		sS -= 60;
	}

	if (mS >= 60) {
		hS++;
		mS -= 60;
	}

	if (hS >= 24) {		
		hS -= 24;
	}

	setHora(hS);
	setMinuto(mS);
	setSegundo(sS);
}

int Horario::getSegundosMeiaNoite() {
	return getSegundo() + getMinuto() * 60 + getHora() * 60 * 60;
}

void Horario::setHorarioVerao(bool hv) {
	horarioVerao = hv;
}

void Horario::setHora(int hora) {
	if (!getHorarioVerao()) {
		if (hora >= 24 || hora < 0) hora = 0;
		
		h = hora;
	}
}

void Horario::setMinuto(int minuto) {
	if (!getHorarioVerao()) {
		if (minuto >= 60 || minuto < 0) minuto = 0;
		
		m = minuto;
	}
}

void Horario::setSegundo(int segundo) {
	if (!getHorarioVerao()) {
		if (segundo >= 60 || segundo < 0) segundo = 0;
		
		s = segundo;
	}
}

void Horario::setHorario(int hora, int minuto, int segundo) {
	if (!getHorarioVerao()) {
		setHora(hora);
		setMinuto(minuto);
		setSegundo(segundo);
	}
}

int Horario::getHora() {
	if (horarioVerao)  return (h + 1) % 24;
	
	return h;
}

int Horario::getMinuto() {
	return m;
}

int Horario::getSegundo() {
	return s;
}

bool Horario::getHorarioVerao() {
	return horarioVerao;
}

void Horario::printHorarioPadrao() {
	if (getHora() < 10) cout << "0";
	
	cout << getHora() << ":";
	
	if (getMinuto() < 10) cout << "0";
	
	cout << getMinuto() << ":";
	
	if (getSegundo() < 10) cout << "0";
	
	cout << getSegundo() << endl;	
}

void Horario::printHorarioUniversal() {
	if (getHora() == 0 || getHora() == 12) 
		cout << "12:";
	else 
		cout << getHora() % 12 << ":";
	
	if (getMinuto() < 10) cout << "0";
	
	cout << getMinuto() << ":";
	 
	if (getSegundo() < 10) cout << "0";
	
	cout << getSegundo();	

	if (getHora() < 12) cout << " da manhã";
	
	else cout << " da tarde";

	cout << endl;		
}

int main() {
	Horario h1;

	h1.setHorarioVerao(false);
	h1.setHora(10);
	h1.setMinuto(20);
	h1.setSegundo(30);

	h1.printHorarioPadrao();

	Horario h2;

	h2.setHorarioVerao(false);
	h2.setHorario(15, 5, 5);	

	h2.printHorarioPadrao();

	h1.adicionaHorario(h2);
	
	cout << h1.getSegundosMeiaNoite() << endl;
	
	h1.printHorarioPadrao();

	h1.setHorarioVerao(true);
	
	return 0;
}