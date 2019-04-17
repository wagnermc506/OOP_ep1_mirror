#include <string>

using namespace std;

class Mapa{

    private:
        int posicao;
    public:
        Mapa();
        ~Mapa();
        string create_lineMain();
        string create_lineSub();
        void show_map(string lineMain[], string lineSub);
        string edit_map();
};