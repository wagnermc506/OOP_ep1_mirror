#include <iostream>

using namespace std;

class Posicao{
    private:

    public:
        Posicao();
        ~Posicao();
        
        void criar_matriz(int posicao[][13]);
        void mostrar_matriz(int posicao[][13]);
        void editar_matriz(int posicao[][13], int line, int column, int tipo);

        void ler_arquivo();
};