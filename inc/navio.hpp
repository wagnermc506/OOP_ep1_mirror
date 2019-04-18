#include <string>
#include <iostream>

using namespace std;

class Navio{

    private:
        int hitPoints;
        int line;
        int column;
        int type;
        int partsNumber;
    
    public:
        Navio();
        ~Navio();
        
        void set_hitPoints(int hitPoints);
        int get_hitPoints();
        void set_line(int line);
        int get_line();
        void set_column(int column);
        int get_column();
        void set_type(int type);
        int get_type();
        void set_partsNumber(int partsNumber);
        int get_partsNumber();

};