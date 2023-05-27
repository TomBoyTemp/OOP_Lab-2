#include <stdio.h>
#include <cmath>
#include <conio.h>
#define TRUE 1
#define FALSE 0

class Cube {
protected:
    int side, volume, fc_area;
    int occup = FALSE;
public:
    Cube() : side(0),volume(side * side * side),fc_area(side * side) {
        printf("Cube()\n");
        printf("\n");
    }
    Cube(int fc_area){
        printf("Cube(int fc_area)\n");
        this->fc_area = fc_area;
        this->side = sqrt(fc_area);
        this->volume = side * side * side;
        printf("\n");
    }
    Cube(const Cube& p) {
        printf("Cube(const Cube &p)\n");
        side = p.side;
        volume = p.volume;
        fc_area = p.fc_area;
        printf("\n");
    }
    ~Cube() {
        printf("~Cube()\n");
        printf("Side = %-4d,Volume = %-4d,Fc_area = %-4d", side, volume, fc_area);
        printf("\n");
    }
    void exp_vol(int exp) {
        volume *= exp;
    }
    bool comp(int volume);
};
bool Cube::comp(int volume) {
    if (this->volume > volume) {
        return  true;
    }
    else {
        return false;
    }
}
//Создание потомка класса с модификатором наследования public
class OccupancyCube : public Cube {
public:
    OccupancyCube() : Cube() {
        printf("OccupancyCube()\n");
        occup = TRUE;
        printf("\n");
    }
    OccupancyCube(int bl) : Cube(fc_area) {
        printf("OccupancyCube(int bl)\n");
        if (bl > 0) {
            this->occup = TRUE;
        }
        else {
            this->occup = FALSE;
        }
        printf("\n");
    }
    OccupancyCube(const OccupancyCube& p) {
        printf("Cube(const OccupancyCube &p)\n");
        occup = p.occup;
        side = p.side;
        volume = p.volume;
        fc_area = p.fc_area;
        printf("\n");
    }
    void foo()
    {
        printf("I'm cube\n");
    }
    ~OccupancyCube() {
        printf("~OccupancyCube()\n");
        printf("Side = %-4d,Volume = %-4d,Fc_area = %-4d,Occupancy =%d", side, volume, fc_area, occup);
        printf("\n");
    }
    void reset() {
        occup = FALSE;
    }
};
class BigCube {
protected:
    Cube p1;
    Cube* p2; 
    
public:
    BigCube(): p1() {
        printf("BigCube()\n");
        p2 = new Cube();
        printf("\n");
    }
    BigCube(int fc_area1,int fc_area2):p1(fc_area1) {
        printf("BigCube()\n");
        p2 = new Cube(fc_area2);
        printf("\n");
    }
    BigCube(const BigCube& p): p1(p.p1){
        printf("BigCube(const BigCube &p)\n");
        p2 = new Cube((*p.p2));
        printf("\n");
    }
    ~BigCube() {
        printf("~BigCube()\n");
        delete p2;
        printf("\n");
    }
};
int main()
{
    {
        OccupancyCube OpC0;
        OccupancyCube* OpC1 = new OccupancyCube (OpC0);
        OpC0.foo();
        Cube* OpC2 = new OccupancyCube;
        delete OpC1;
        delete OpC2;
    }
    {
        BigCube bp0;
        BigCube bp1(16, 32);
        BigCube bp2(bp0);
    }
    BigCube* bp0 = new BigCube;
    BigCube* bp1 = new BigCube(16,32);
    BigCube* bp2 = new BigCube(*bp1);
    
    delete bp0;
    delete bp1;
    delete bp2;
   

    _getch();
    return 0;
}