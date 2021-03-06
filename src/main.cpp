#include"FramPlateauLand.hpp"
#include"2048/Case2048.hpp"
#include"2048/Plateau2048Plugin.hpp"
#include"2048/Plateau2048.hpp"
#include"2048/Case2048Destroy/Case2048Destroy.hpp"
#include"Takin/PlateauTakin.hpp"
#include"Sokoban/PlateauSokoban.hpp"
#include"Sokoban/CaseSokoban.hpp"
#include "Display/display.hpp"
//#include <memory>

void playSokoban(const char * nameFile){

	PlateauSokoban * pSokoban;
	if(nameFile!=nullptr){
		pSokoban=PlateauSokoban::readFile(nameFile);
	}
	if(pSokoban!=nullptr){
		pSokoban->setGameMode(true);
		display<CaseSokoban> affichage(*pSokoban,45);
		affichage.gridBGColour=new sf::Color (250, 248, 239, 255);
		affichage.StartModeWindow();
	}

}

void playSokoban(){

	PlateauSokoban pSokoban(5,6);
    vector<char> v { '#','#','#','#','#','#',
    				'#',' ',' ',' ','#','#',
					'#','.','$',' ','#','#',
					'#',' ',' ','@','#','#',
					'#','#','#','#','#','#',
    				};
    pSokoban.initPlateau(v);
    pSokoban.setGameMode(true);
    display<CaseSokoban> affichage(pSokoban,60);
    //pSokoban.StartModeTerminal();
    affichage.gridBGColour=new sf::Color (250, 248, 239, 255);
    affichage.StartModeWindow();
}

void playTakinInt(){

	PlateauTakin<int> pTakinInt(5,2);
    vector<int> v { 2,7,0,10,5,1,4,8,4,9 };
    pTakinInt.initPlateau(v);
    pTakinInt.setBlank(1,0);
    pTakinInt.setModeBlankCaseAtTheEnd();
    pTakinInt.setGameMode(true);
    //pTakinInt.StartModeTerminal();
    display<CaseTakin<int>> affichage(pTakinInt,80);
    affichage.StartModeWindow();

}

void playTakinChar(){
	PlateauTakin<char> pTakinInt(3,6);
    vector<char> v { 'a','b',' ','d','k','t','p','m','l',
    	'x','s','a','b','p' ,'w','y','q','h'};
    pTakinInt.initPlateau(v);
    pTakinInt.setBlank(0,2);
    pTakinInt.setModeBlankCaseAtTheEnd();
    pTakinInt.setGameMode(true);
    pTakinInt.StartModeTerminal();
}

void play2048(){

	Plateau2048 pl2048(5,5);
	pl2048.initPlateau();
	pl2048.setGameMode(false);
	pl2048.setModeRecursive(false);
	display<Case2048>  affichage=display<Case2048>(pl2048,70);
	affichage.StartModeWindow();
}

void play2048Plugin(){
	Plateau2048Plugin pl2048PlugIn(5,5);
	pl2048PlugIn.initPlateau();
	pl2048PlugIn.setGameMode(true);
	pl2048PlugIn.setModeRecursive(false);

	display<Case2048>  affichage=display<Case2048>(pl2048PlugIn,70);
	affichage.StartModeWindow();
}

/*
const Case2048 Case2048::operator+(const Case2048 &other) const {
	Case2048 result = *this;     // Make a copy of myself.  Same as MyClass result(*this);
    result.valeur+=other.valeur;
    return result;              // All done!
  }
*/
int main(int argc, char* argv[]) {
   if(argc>1){
	   //playSokoban(argv[1]);
   }


/*
    std::cout<<"bonjour2"<<std::endl;

    class mama:public CaseGeneric{
    public:
    mama(int t,int v):CaseGeneric(t,v){

        }
    };

    class Casemystere:public Case2048Destroy{
    	public:
    	Casemystere(int t , int v):Case2048Destroy(t,v){

    	}
		virtual bool isFusionnableWith(CaseGeneric & case2) {
			return false;
		}

    };
*/

    //playTakinChar();
    //playSokoban();
    //playTakinInt();
    //play2048();
    play2048Plugin();

/*
    Case2048 * a =new Case2048(3,4);
    a->valeur=10;
    Case2048 * aa =new Case2048(3,4);
    aa->valeur=20;
    CaseGeneric * b =new Case2048Destroy(3,6);
    CaseGeneric * bb =new Case2048Destroy(3,6);


    std::cout<<"passage au V"<<endl;

    //Case2048  c = (*a)+(*aa);

    std::vector<std::shared_ptr<CaseGeneric> > v;


    v.push_back(std::shared_ptr<CaseGeneric>(new Case2048(3,4,true)));

    v.push_back(std::shared_ptr<CaseGeneric>(new Case2048Destroy(3,4)));

    for (auto it : v) {


    }

*/


    //(*a)>(*b);
/*
    a->FusionWith(*b,true);
    bb->FusionWith(*a,true);
    bb->FusionWith(*b,true);
*/


    //play2048();
    //a->fusion(a);


    //Case2048 * a =new CaseGe(3,4,true);



    //FramPlateauLand<int>* fr; //INTERDIT

    //FramPlateauLand<mama>* fr;
    //fr = new FramPlateauLand<mama>(8, 8);

    /*
	FramPlateauLand<Case2048>* fram;

    fram = new FramPlateauLand<Case2048>(8, 8);//interdit
	fram->affiche();

	Case2048Destroy *a = new Case2048Destroy(0,0);
	a->valeur=9;

	fram->plateau[0][0]=a;

	fram->plateau[1][0]->valeur=12;

	fram->affiche();

	fram->doDirectionalSWIPE('i',false);
	delete fram;
	*/

}
