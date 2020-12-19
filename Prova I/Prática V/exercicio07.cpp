#include <iostream>
#include <cstring>

using namespace std;

struct person {
    char primeiroNome[50];
    char ultimoNome[50];
    char cpf[11];
    int peso;
    int idade;
    double altura;
};

void SelectionSort(person **pessoas, int n, int (*tipoComparacao)(person pessoa1, person pessoa2)) {
    for (int i = 0; i < n-1; i++) {
        // acha a posicao do menor elemento
        // entre as posições (i) e (n-1)
        int posMenor = i;
        
        for (int j = i+1; j < n; j++)
            if (tipoComparacao(pessoas[j][0], pessoas[posMenor][0]) < 0)
                posMenor = j;

            // troca o menor elemento (que está na
            // posicao posMenor) com o elemento (i)
            person aux = pessoas[i][0];
            pessoas[i][0] = pessoas[posMenor][0];
            pessoas[posMenor][0] = aux;
    }
}

void insertionSort(person **pessoas, int n, int (*tipoComparacao)(person pessoa1, person pessoa2)) {
    for (int i = 1; i < n; i++) {
        // o arranjo entre as posicoes [0,i) já está ordenado
        person elemInserir = pessoas[i][0];
        int j = i-1;
        
        while(j >= 0 && tipoComparacao(pessoas[j][0], elemInserir) > 0) {
            pessoas[j+1][0] = pessoas[j][0];
            j--;
        }

        pessoas[j+1][0] = elemInserir;
    }
}

/* Supondo que v[p...q-1] e v[q...r-1] estejam ordenados */
void merge(person **pessoas, int p, int q, int r, int (*tipoComparacao)(person pessoa1, person pessoa2)) {
    int tam = r-p;
    person *aux = new person[tam];
    int i = p; //cursor 1
    int j = q; //cursor 2
    int k = 0; //cursor para aux
    
    while(i < q && j < r) {
        if (tipoComparacao(pessoas[i][0], pessoas[j][0]) < 0 || tipoComparacao(pessoas[i][0], pessoas[j][0]) == 0)
            aux[k++] = pessoas[i++][0];
        else
            aux[k++] = pessoas[j++][0];
    }

    while(i < q)
        aux[k++] = pessoas[i++][0];
    
    while(j < r)
        aux[k++] = pessoas[j++][0];
    
    for(k = 0; k < tam; k++)
        pessoas[p+k][0] = aux[k];

    delete []aux;
}

/* Ordena o vetor v entre as posicoes p e r-1 */
void mergeSort(person **pessoas, int p, int r, int (*tipoComparacao)(person pessoa1, person pessoa2)) {
    // com um elemento, já está ordenado
    if (p < r-1) {
        int meio = (p+r) / 2;
        mergeSort(pessoas, p, meio, tipoComparacao);
        mergeSort(pessoas, meio, r, tipoComparacao);
        merge(pessoas, p, meio, r, tipoComparacao); //intercala
    }
}

void mergeSort(person **pessoas, int n, int (*tipoComparacao)(person pessoa1, person pessoa2)) {
    mergeSort(pessoas, 0, n, tipoComparacao);
}

int comparaPessoaPeloPrimeiroNome(person pessoa1, person pessoa2) {
    if(strcmp(pessoa1.primeiroNome, pessoa2.primeiroNome) < 0) {
        return -1;
    } else if (strcmp(pessoa1.primeiroNome, pessoa2.primeiroNome) == 0) {
        return 0;
    } else {
        return 1;
    }
}

int comparaPessoaPeloUltimoNome(person pessoa1, person pessoa2) {
    if(strcmp(pessoa1.ultimoNome, pessoa2.ultimoNome) < 0) {
        return -1;
    } else if (strcmp(pessoa1.ultimoNome, pessoa2.ultimoNome) == 0) {
        return 0;
    } else {
        return 1;
    }
}

int comparaPessoaPeloPrimeiroEUltimoNome(person pessoa1, person pessoa2) {
    if(comparaPessoaPeloPrimeiroNome(pessoa1, pessoa2) < 0) {
        return -1;
    } else if (comparaPessoaPeloPrimeiroNome(pessoa1, pessoa2) == 0) {
        if(comparaPessoaPeloUltimoNome(pessoa1, pessoa2) < 0) {
            return -1;
        } else if (comparaPessoaPeloUltimoNome(pessoa1, pessoa2) == 0) {
            return 0;
        } else {
            return 1;
        }  
    } else {
        return 1;
    }
}

int main() {
    int N, opcao;

    cin >> N;
    
    person** pessoas = new person*[N];

    for(int i = 0; i < N; i++)
        pessoas[i] = new person();

    for(int i = 0; i < N; i++) {
        cin >> pessoas[i][0].primeiroNome;
        cin >> pessoas[i][0].ultimoNome;
    }

    int (*tipoComparacao[])(person, person) = {comparaPessoaPeloPrimeiroNome, comparaPessoaPeloUltimoNome, comparaPessoaPeloPrimeiroEUltimoNome};

    cin >> opcao;

    SelectionSort(pessoas, N, tipoComparacao[opcao]);
    insertionSort(pessoas, N, tipoComparacao[opcao]);
    mergeSort(pessoas, N, tipoComparacao[opcao]);

    for(int i = 0; i < N; i++) {
        cout << pessoas[i][0].primeiroNome << " " << pessoas[i][0].ultimoNome << endl;
    }

    for(int i = 0; i < N; i++)
        delete[] pessoas[i];

    delete[] pessoas;

    return 0;
}