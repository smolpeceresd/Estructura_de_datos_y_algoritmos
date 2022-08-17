#include <iostream>
#include "aristagrafo.h"
#include "grafo.h"
#include <vector>
#include <list>
using namespace std;
// PARTICIPANTES:
//CARMEN SANCHEZ HERNANDEZ
//SANTIAGO MOLPECERES DIAZ
int main()
{
    cout<<"\nPARTICIPANTES:"
          "\nCARMEN SANCHEZ HERNANDEZ"
          "\nSANTIAGO MOLPECERES DIAZ\n";
    Grafo d = Grafo(20);

    //QT no permite la ñ
    d.inserta(1, 2, 1118,"A Coruna","Barcelona");
    d.inserta(1, 3, 644,"A Coruna","Bilbao");
    d.inserta(1, 4, 535,"A Coruna","Burgos");
    d.inserta(1, 5, 683,"A Coruna","Caceres");
    d.inserta(1, 6, 995,"A Coruna","Cordoba");
    d.inserta(1, 7, 334,"A Coruna","Leon");
    d.inserta(1, 8, 609,"A Coruna","Madrid");
    d.inserta(1, 9, 1153,"A Coruna","Malaga");
    d.inserta(1, 10, 1010,"A Coruna","Murcia");
    d.inserta(1, 11, 340,"A Coruna","Oviedo");
    d.inserta(1, 12, 738,"A Coruna","Pamplona");
    d.inserta(1, 13, 573,"A Coruna","Salamanca");
    d.inserta(1, 14, 763,"A Coruna","San Sebastian");
    d.inserta(1, 15, 947,"A Coruna","Sevilla");
    d.inserta(1, 16, 676,"A Coruna","Soria");
    d.inserta(1, 17, 961,"A Coruna","Valencia");
    d.inserta(1, 18, 455,"A Coruna","Valladolid");
    d.inserta(1, 19, 411,"A Coruna","Zamora");
    d.inserta(1, 20, 833,"A Coruna","Zaragoza");
    ///////////////////////////////////////
    d.inserta(2, 3, 620,"Barcelona","Bilbao");
    d.inserta(2, 4, 583,"Barcelona","Burgos");
    d.inserta(2, 5, 918,"Barcelona","Caceres");
    d.inserta(2, 6, 908,"Barcelona","Cordoba");
    d.inserta(2, 7, 784,"Barcelona","Leon");
    d.inserta(2, 8, 621,"Barcelona","Madrid");
    d.inserta(2, 9, 997,"Barcelona","Malaga");
    d.inserta(2, 10, 590,"Barcelona","Murcia");
    d.inserta(2, 11, 902,"Barcelona","Oviedo");
    d.inserta(2, 12, 437,"Barcelona","Pamplona");
    d.inserta(2, 13, 778,"Barcelona","Salamanca");
    d.inserta(2, 14, 529,"Barcelona","San Sebastina");
    d.inserta(2, 15, 1046,"Barcelona","Sevilla");
    d.inserta(2, 16, 453,"Barcelona","Soria");
    d.inserta(2, 17, 349,"Barcelona","Valencia");
    d.inserta(2, 18, 663,"Barcelona","Valladolid");
    d.inserta(2, 19, 759,"Barcelona","Zamora");
    d.inserta(2, 20, 296,"Barcelona","Zaragoza");
    /////////////////////////////////////////
    d.inserta(3, 4, 158,"Bilbao","Burgos");
    d.inserta(3, 5, 605,"Bilbao","Caceres");
    d.inserta(3, 6, 795,"Bilbao","Cordoba");
    d.inserta(3, 7, 359,"Bilbao","Leon");
    d.inserta(3, 8, 395,"Bilbao","Madrid");
    d.inserta(3, 9, 939,"Bilbao","Malaga");
    d.inserta(3, 10, 796,"Bilbao","Murcia");
    d.inserta(3, 11, 304,"Bilbao","Oviedo");
    d.inserta(3, 12, 159,"Bilbao","Pamplona");
    d.inserta(3, 13, 395,"Bilbao","Salamanca");
    d.inserta(3, 14, 119,"Bilbao","San Sebastian");
    d.inserta(3, 15, 993,"Bilbao","Sevilla");
    d.inserta(3, 16, 257,"Bilbao","Soria");
    d.inserta(3, 17, 633,"Bilbao","Valencia");
    d.inserta(3, 18, 280,"Bilbao","Valladolid");
    d.inserta(3, 19, 376,"Bilbao","Zamora");
    d.inserta(3, 20, 324,"Bilbao","Zaragoza");
    /////////////////////////////////////////
    d.inserta(4, 5, 447,"Burgos","Caceres");
    d.inserta(4, 6, 637,"Burgos","Cordoba");
    d.inserta(4, 7, 201,"Burgos","Leon");
    d.inserta(4, 8, 237,"Burgos","Madrid");
    d.inserta(4, 9, 781,"Burgos","Malaga");
    d.inserta(4, 10, 638,"Burgos","Murcia");
    d.inserta(4, 11, 322,"Burgos","Oviedo");
    d.inserta(4, 12, 203,"Burgos","Pamplona");
    d.inserta(4, 13, 237,"Burgos","Salamanca");
    d.inserta(4, 14, 232,"Burgos","San Sebastian");
    d.inserta(4, 15, 775,"Burgos","Sevilla");
    d.inserta(4, 16, 141,"Burgos","Soria");
    d.inserta(4, 17, 517,"Burgos","Valencia");
    d.inserta(4, 18, 122,"Burgos","Valladolid");
    d.inserta(4, 19, 218,"Burgos","Zamora");
    d.inserta(4, 20, 287,"Burgos","Zaragoza");
    ////////////////////////////////////////////
    d.inserta(5, 6, 319,"Caceres","Cordoba");
    d.inserta(5, 7, 407,"Caceres","Leon");
    d.inserta(5, 8, 297,"Caceres","Madrid");
    d.inserta(5, 9, 506,"Caceres","Malaga");
    d.inserta(5, 10, 654,"Caceres","Murcia");
    d.inserta(5, 11, 525,"Caceres","Oviedo");
    d.inserta(5, 12, 650,"Caceres","Pamplona");
    d.inserta(5, 13, 210,"Caceres","Salamanca");
    d.inserta(5, 14, 679,"Caceres","San Sebastian");
    d.inserta(5, 15, 264,"Caceres","Sevilla");
    d.inserta(5, 16, 490,"Caceres","Soria");
    d.inserta(5, 17, 636,"Caceres","Valencia");
    d.inserta(5, 18, 325,"Caceres","Valladolid");
    d.inserta(5, 19, 272,"Caceres","Zamora");
    d.inserta(5, 20, 622,"Caceres","Zaragoza");
    ///////////////////////////////////////////////
    d.inserta(6, 7, 733,"Cordoba","Leon");
    d.inserta(6, 8, 400,"Cordoba","Madrid");
    d.inserta(6, 9, 187,"Cordoba","Malaga");
    d.inserta(6, 10, 444,"Cordoba","Murcia");
    d.inserta(6, 11, 851,"Cordoba","Oviedo");
    d.inserta(6, 12, 807,"Cordoba","Pamplona");
    d.inserta(6, 13, 529,"Cordoba","Salamanca");
    d.inserta(6, 14, 869,"Cordoba","San Sebastian");
    d.inserta(6, 15, 138,"Cordoba","Sevilla");
    d.inserta(6, 16, 831,"Cordoba","Soria");
    d.inserta(6, 17, 545,"Cordoba","Valencia");
    d.inserta(6, 18, 578,"Cordoba","Valladolid");
    d.inserta(6, 19, 616,"Cordoba","Zamora");
    d.inserta(6, 20, 725,"Cordoba","Zaragoza");
    ////////////////////////////////////////////
    d.inserta(7, 8, 333,"Leon","Madrid");
    d.inserta(7, 9, 877,"Leon","Malaga");
    d.inserta(7, 10, 734,"Leon","Murcia");
    d.inserta(7, 11, 118,"Leon","Oviedo");
    d.inserta(7, 12, 404,"Leon","Pamplona");
    d.inserta(7, 13, 197,"Leon","Salamanca");
    d.inserta(7, 14, 433,"Leon","San Sebastian");
    d.inserta(7, 15, 671,"Leon","Sevilla");
    d.inserta(7, 16, 342,"Leon","Soria");
    d.inserta(7, 17, 685,"Leon","Valencia");
    d.inserta(7, 18, 134,"Leon","Valladolid");
    d.inserta(7, 19, 135,"Leon","Zamora");
    d.inserta(7, 20, 488,"Leon","Zaragoza");
    //////////////////////////////////////////////////
    d.inserta(8, 9, 544,"Madrid","Malaga");
    d.inserta(8, 10, 401,"Madrid","Murcia");
    d.inserta(8, 11, 451,"Madrid","Oviedo");
    d.inserta(8, 12, 407,"Madrid","Pamplona");
    d.inserta(8, 13, 212,"Madrid","Salamanca");
    d.inserta(8, 14, 469,"Madrid","San Sebastian");
    d.inserta(8, 15, 538,"Madrid","Sevilla");
    d.inserta(8, 16, 231,"Madrid","Soria");
    d.inserta(8, 17, 352,"Madrid","Valencia");
    d.inserta(8, 18, 193,"Madrid","Valladolid");
    d.inserta(8, 19, 248,"Madrid","Zamora");
    d.inserta(8, 20, 325,"Madrid","Zaragoza");
    ////////////////////////////////////////////////////
    d.inserta(9, 10, 407,"Malaga","Murcia");
    d.inserta(9, 11, 995,"Malaga","Oviedo");
    d.inserta(9, 12, 951,"Malaga","Pamplona");
    d.inserta(9, 13, 756,"Malaga","Salamanca");
    d.inserta(9, 14, 1013,"Malaga","San Sebastian");
    d.inserta(9, 15, 219,"Malaga","Sevilla");
    d.inserta(9, 16, 775,"Malaga","Soria");
    d.inserta(9, 17, 648,"Malaga","Valencia");
    d.inserta(9, 18, 737,"Malaga","Valladolid");
    d.inserta(9, 19, 792,"Malaga","Zamora");
    d.inserta(9, 20, 869,"Malaga","Zaragoza");
    //////////////////////////////////////////////////////////////
    d.inserta(10, 11, 852,"Murcia","Oviedo");
    d.inserta(10, 12, 714,"Murcia","Pamplona");
    d.inserta(10, 13, 613,"Murcia","Salamanca");
    d.inserta(10, 14, 807,"Murcia","San Sebastian");
    d.inserta(10, 15, 534,"Murcia","Sevilla");
    d.inserta(10, 16, 589,"Murcia","Soria");
    d.inserta(10, 17, 241,"Murcia","Valencia");
    d.inserta(10, 18, 594,"Murcia","Valladolid");
    d.inserta(10, 19, 649,"Murcia","Zamora");
    d.inserta(10, 20, 539,"Murcia","Zaragoza");
    ////////////////////////////////////////////////////
    d.inserta(11, 12, 463,"Oviedo","Pamplona");
    d.inserta(11, 13, 315,"Oviedo","Salamanca");
    d.inserta(11, 14, 423,"Oviedo","San Sebastian");
    d.inserta(11, 15, 789,"Oviedo","Sevilla");
    d.inserta(11, 16, 463,"Oviedo","Soria");
    d.inserta(11, 17, 803,"Oviedo","Valencia");
    d.inserta(11, 18, 252,"Oviedo","Valladolid");
    d.inserta(11, 19, 253,"Oviedo","Zamora");
    d.inserta(11, 20, 604,"Oviedo","Zaragoza");
    ///////////////////////////////////////////////////
    d.inserta(12, 13, 440,"Pamplona","Salamanca");
    d.inserta(12, 14, 92,"Pamplona","San Sebastian");
    d.inserta(12, 15, 945,"Pamplona","Sevilla");
    d.inserta(12, 16, 176,"Pamplona","Soria");
    d.inserta(12, 17, 501,"Pamplona","Valencia");
    d.inserta(12, 18, 325,"Pamplona","Valladolid");
    d.inserta(12, 19, 421,"Pamplona","Zamora");
    d.inserta(12, 20, 175,"Pamplona","Zaragoza");
    //////////////////////////////////////////////////////
    d.inserta(13, 14, 469,"Salamanca","San Sebastian");
    d.inserta(13, 15, 474,"Salamanca","Sevilla");
    d.inserta(13, 16, 325,"Salamanca","Soria");
    d.inserta(13, 17, 564,"Salamanca","Valencia");
    d.inserta(13, 18, 115,"Salamanca","Valladolid");
    d.inserta(13, 19, 62,"Salamanca","Zamora");
    d.inserta(13, 20, 482,"Salamanca","Zaragoza");
    /////////////////////////////////////////////////////
    d.inserta(14, 15, 1007,"San Sebastian","Sevilla");
    d.inserta(14, 16, 268,"San Sebastian","Soria");
    d.inserta(14, 17, 594,"San Sebastian","Valencia");
    d.inserta(14, 18, 354,"San Sebastian","Valladolid");
    d.inserta(14, 19, 450,"San Sebastian","Zamora");
    d.inserta(14, 20, 268,"San Sebastian","Zaragoza");
    //////////////////////////////////////////////////////
    d.inserta(15, 16, 769,"Sevilla","Soria");
    d.inserta(15, 17, 697,"Sevilla","Valencia");
    d.inserta(15, 18, 589,"Sevilla","Valladolid");
    d.inserta(15, 19, 536,"Sevilla","Zamora");
    d.inserta(15, 20, 863,"Sevilla","Zaragoza");
    ///////////////////////////////////////////////////
    d.inserta(16, 17, 376,"Soria","Valencia");
    d.inserta(16, 18, 210,"Soria","Valladolid");
    d.inserta(16, 19, 306,"Soria","Zamora");
    d.inserta(16, 20, 157,"Soria","Zaragoza");
    ////////////////////////////////////////////////
    d.inserta(17, 18, 545,"Valenica","valladolid");
    d.inserta(17, 19, 600,"Valenica","Zamora");
    d.inserta(17, 20, 326,"Valenica","Zaragoza");
    /////////////////////////////////////////////
    d.inserta(18, 19, 96,"valladolid","Zamora");
    d.inserta(18, 20, 367,"valladolid","Zaragoza");
    ////////////////////////////////////////////////
    d.inserta(19, 20, 463,"Zamora","Zaragoza");



    std::cout << d.imprime("Grafo de costes ");

    list<AristaGrafo*> hola=Grafo::viajanteComercioVecino(d,1);

    std::cout << Grafo::imprimeLista("Costes Viajante del comercio Vecino", hola);

    list<AristaGrafo*> bye=Grafo::viajanteComercioPrim(d,1);

    std::cout<<Grafo::imprimeLista("Coste Viajante Comercio Prim",bye);


    return 0;
}
