
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <cmath>

using namespace std;

struct Location       //creating node here
{
 string LocationName;
 int Xcoordinate, Ycoordinate;
 Location * father;
 Location * SE = NULL;
 Location * SW = NULL;
 Location * NE = NULL;
 Location * NW = NULL;
};


struct InsideTheArea    
{
 string MyLocation;
 InsideTheArea * next = NULL;
};

struct Road    
{
 string MyLocation;
 Road * next;
};



void SearchingTree (int eastboundary, int westboundary, int northboundary, int southboundary, double arrangequery, double exactx, double exacty, Location * reference, Location * mytemp, string &inRoad, string &inArea ){

    double distance = sqrt(pow((exactx - mytemp->Xcoordinate), 2) + pow((exacty - mytemp->Ycoordinate), 2));

    bool isInArea = false;

    bool isInBox = false;
    
    /*int templater = westboundary;


    westboundary = eastboundary;

    eastboundary = templater;*/

    if(distance<=arrangequery){
        isInArea = true;
    }

    if(westboundary<=mytemp->Xcoordinate && eastboundary>=mytemp->Xcoordinate && northboundary>=mytemp->Ycoordinate && southboundary<=mytemp->Ycoordinate){
        isInBox = true;
    }

    //1  SE
    if (westboundary>mytemp->Xcoordinate && northboundary < mytemp->Ycoordinate && isInArea==false&& isInBox==false){
        inRoad = inRoad + mytemp->LocationName+", "; 
        if(mytemp->SE!=NULL){
            Location * myiterator = new Location;

            myiterator = mytemp;

            myiterator = myiterator->SE;

            

            

            SearchingTree (eastboundary,  westboundary,  northboundary,  southboundary,  arrangequery,  exactx,  exacty,  reference, myiterator,inRoad,inArea)   ;
    }}

    //2  SE + SW
    else if (westboundary<=mytemp->Xcoordinate&& isInArea==false&& isInBox==false && eastboundary>=mytemp->Xcoordinate && northboundary < mytemp->Ycoordinate){
        inRoad = inRoad + mytemp->LocationName+", "; 
        if(mytemp->SE!=NULL){
            Location * myiterator = new Location;

            myiterator = mytemp;

            myiterator = myiterator->SE;

            

            SearchingTree (eastboundary,  westboundary,  northboundary,  southboundary,  arrangequery,  exactx,  exacty,  reference, myiterator,inRoad,inArea)   ;
    }
        if(mytemp->SW!=NULL){
            Location * myiterator = new Location;

            myiterator = mytemp;

            myiterator = myiterator->SW;

            

            SearchingTree (eastboundary,  westboundary,  northboundary,  southboundary,  arrangequery,  exactx,  exacty,  reference, myiterator,inRoad,inArea)   ;
    }
    }

    //3  SW
    else if (eastboundary < mytemp->Xcoordinate&& isInBox==false&& northboundary < mytemp->Ycoordinate&& isInArea==false){
        inRoad = inRoad + mytemp->LocationName+", "; 
        if(mytemp->SW!=NULL){
            Location * myiterator = new Location;

            myiterator = mytemp;

            myiterator = myiterator->SW;

            

            SearchingTree (eastboundary,  westboundary,  northboundary,  southboundary,  arrangequery,  exactx,  exacty,  reference, myiterator,inRoad,inArea)   ;
    }
    }

    //4  SE + NE
    else if (westboundary > mytemp->Xcoordinate&& isInBox==false && northboundary>=mytemp->Ycoordinate&& isInArea==false && southboundary <= mytemp->Ycoordinate){
        inRoad = inRoad + mytemp->LocationName+", "; 
        if(mytemp->SE!=NULL){
            Location * myiterator = new Location;

            myiterator = mytemp;

            myiterator = myiterator->SE;

            string myword = mytemp->LocationName;

            

            SearchingTree (eastboundary,  westboundary,  northboundary,  southboundary,  arrangequery,  exactx,  exacty,  reference, myiterator,inRoad,inArea)   ;
    }

        if(mytemp->NE!=NULL){
            Location * myiterator = new Location;

            myiterator = mytemp;

            myiterator = myiterator->NE;

            

            SearchingTree (eastboundary,  westboundary,  northboundary,  southboundary,  arrangequery,  exactx,  exacty,  reference, myiterator,inRoad,inArea)   ;
    }
    }

    //5  SW + NW

    else if (eastboundary < mytemp->Xcoordinate && isInBox==false&& northboundary>=mytemp->Ycoordinate&& isInArea==false && southboundary <= mytemp->Ycoordinate){
        inRoad = inRoad + mytemp->LocationName+", "; 
        if(mytemp->SW!=NULL){
            Location * myiterator = new Location;

            myiterator = mytemp;

            myiterator = myiterator->SW;

            

            SearchingTree (eastboundary,  westboundary,  northboundary,  southboundary,  arrangequery,  exactx,  exacty,  reference, myiterator,inRoad,inArea)   ;
    }
        if(mytemp->NW!=NULL){
            Location * myiterator = new Location;

            myiterator = mytemp;

            myiterator = myiterator->NW;

            

            SearchingTree (eastboundary,  westboundary,  northboundary,  southboundary,  arrangequery,  exactx,  exacty,  reference, myiterator,inRoad,inArea)   ;
    }

    }


    //6  NE

    else if (westboundary>mytemp->Xcoordinate && isInBox==false&& southboundary > mytemp->Ycoordinate&& isInArea==false){
        inRoad = inRoad + mytemp->LocationName+", "; 
        if(mytemp->NE!=NULL){
            Location * myiterator = new Location;

            myiterator = mytemp;

            myiterator = myiterator->NE;

            

            SearchingTree (eastboundary,  westboundary,  northboundary,  southboundary,  arrangequery,  exactx,  exacty,  reference, myiterator,inRoad,inArea)   ;
    }
    }


    //7  NE + NW 

    else if (westboundary<=mytemp->Xcoordinate && isInBox==false&& eastboundary>=mytemp->Xcoordinate&& isInArea==false && southboundary > mytemp->Ycoordinate){
        inRoad = inRoad + mytemp->LocationName+", "; 
        if(mytemp->NE!=NULL){
            Location * myiterator = new Location;

            myiterator = mytemp;

            myiterator = myiterator->NE;

            

            SearchingTree (eastboundary,  westboundary,  northboundary,  southboundary,  arrangequery,  exactx,  exacty,  reference, myiterator,inRoad,inArea)   ;
    }

        if(mytemp->NW!=NULL){
            Location * myiterator = new Location;

            myiterator = mytemp;

            myiterator = myiterator->NW;

            

            SearchingTree (eastboundary,  westboundary,  northboundary,  southboundary,  arrangequery,  exactx,  exacty,  reference, myiterator,inRoad,inArea)   ;
    }
    }


    //8  NW 

    else if (eastboundary < mytemp->Xcoordinate && isInBox==false&& southboundary > mytemp->Ycoordinate&& isInArea==false){
        inRoad = inRoad + mytemp->LocationName+", "; 
        if(mytemp->NW!=NULL){
            Location * myiterator = new Location;

            myiterator = mytemp;

            myiterator = myiterator->NW;

            

            SearchingTree (eastboundary,  westboundary,  northboundary,  southboundary,  arrangequery,  exactx,  exacty,  reference, myiterator,inRoad,inArea)   ;
    }
    }


    //9 SE + SW + NE

    else if (isInArea==false && distance > arrangequery && int(exactx) > mytemp->Xcoordinate && int(exacty) < mytemp->Ycoordinate ){
        inRoad = inRoad + mytemp->LocationName+", "; 
        if(mytemp->SE!=NULL){
            Location * myiterator = new Location;

            myiterator = mytemp;

            myiterator = myiterator->SE;

            

            SearchingTree (eastboundary,  westboundary,  northboundary,  southboundary,  arrangequery,  exactx,  exacty,  reference, myiterator,inRoad,inArea)   ;
    }
        if(mytemp->SW!=NULL){
            Location * myiterator = new Location;

            myiterator = mytemp;

            myiterator = myiterator->SW;

            

            SearchingTree (eastboundary,  westboundary,  northboundary,  southboundary,  arrangequery,  exactx,  exacty,  reference, myiterator,inRoad,inArea)   ;
    }
        if(mytemp->NE!=NULL){
            Location * myiterator = new Location;

            myiterator = mytemp;

            myiterator = myiterator->NE;

            

            SearchingTree (eastboundary,  westboundary,  northboundary,  southboundary,  arrangequery,  exactx,  exacty,  reference, myiterator,inRoad,inArea)   ;
    }
    }

 
    //10  SE + SW + NW

    else if (isInArea==false && distance > arrangequery && int(exactx) < mytemp->Xcoordinate && int(exacty) < mytemp->Ycoordinate ){
        inRoad = inRoad + mytemp->LocationName+", "; 
        if(mytemp->SE!=NULL){
            Location * myiterator = new Location;

            myiterator = mytemp;

            myiterator = myiterator->SE;

            

            SearchingTree (eastboundary,  westboundary,  northboundary,  southboundary,  arrangequery,  exactx,  exacty,  reference, myiterator,inRoad,inArea)   ;
    }
        if(mytemp->SW!=NULL){
            Location * myiterator = new Location;

            myiterator = mytemp;

            myiterator = myiterator->SW;

            

            SearchingTree (eastboundary,  westboundary,  northboundary,  southboundary,  arrangequery,  exactx,  exacty,  reference, myiterator,inRoad,inArea)   ;
    }
        if(mytemp->NW!=NULL){
            Location * myiterator = new Location;

            myiterator = mytemp;

            myiterator = myiterator->NW;

            

            SearchingTree (eastboundary,  westboundary,  northboundary,  southboundary,  arrangequery,  exactx,  exacty,  reference, myiterator,inRoad,inArea)   ;
    }
    }


    //11  SE + NE + NW

    else if (isInArea==false && distance > arrangequery && int(exactx) > mytemp->Xcoordinate && int(exacty) > mytemp->Ycoordinate ){
        inRoad = inRoad + mytemp->LocationName+", "; 
        if(mytemp->SE!=NULL){
            Location * myiterator = new Location;

            myiterator = mytemp;

            myiterator = myiterator->SE;

            

            SearchingTree (eastboundary,  westboundary,  northboundary,  southboundary,  arrangequery,  exactx,  exacty,  reference, myiterator,inRoad,inArea)   ;
    }
                
        if(mytemp->NE!=NULL){
            Location * myiterator = new Location;

            myiterator = mytemp;

            myiterator = myiterator->NE;

            

            SearchingTree (eastboundary,  westboundary,  northboundary,  southboundary,  arrangequery,  exactx,  exacty,  reference, myiterator,inRoad,inArea)   ;
    }
        if(mytemp->NW!=NULL){
            Location * myiterator = new Location;

            myiterator = mytemp;

            myiterator = myiterator->NW;

            

            SearchingTree (eastboundary,  westboundary,  northboundary,  southboundary,  arrangequery,  exactx,  exacty,  reference, myiterator,inRoad,inArea)   ;
    }
    }


    //12  SW + NE + NW

    else if (isInArea==false && distance > arrangequery && int(exactx) < mytemp->Xcoordinate && int(exacty) > mytemp->Ycoordinate ){
        inRoad = inRoad + mytemp->LocationName+", "; 

        if(mytemp->SW!=NULL){
            Location * myiterator = new Location;

            myiterator = mytemp;

            myiterator = myiterator->SW;

            

            SearchingTree (eastboundary,  westboundary,  northboundary,  southboundary,  arrangequery,  exactx,  exacty,  reference, myiterator,inRoad,inArea)   ;
    }
        if(mytemp->NE!=NULL){
            Location * myiterator = new Location;

            myiterator = mytemp;

            myiterator = myiterator->NE;

            

            SearchingTree (eastboundary,  westboundary,  northboundary,  southboundary,  arrangequery,  exactx,  exacty,  reference, myiterator,inRoad,inArea)   ;
    }
        
        if(mytemp->NW!=NULL){
            Location * myiterator = new Location;

            myiterator = mytemp;

            myiterator = myiterator->NW;

            

            SearchingTree (eastboundary,  westboundary,  northboundary,  southboundary,  arrangequery,  exactx,  exacty,  reference, myiterator,inRoad,inArea)   ;
    }
    }


    //13  SE + SW + NE + NW
    else{
            inRoad = inRoad + mytemp->LocationName+", "; 
            inArea = inArea + mytemp->LocationName+", ";

            if(mytemp->SE!=NULL){
            Location * myiterator = new Location;

            myiterator = mytemp;

            myiterator = myiterator->SE;

            

            SearchingTree (eastboundary,  westboundary,  northboundary,  southboundary,  arrangequery,  exactx,  exacty,  reference, myiterator,inRoad,inArea)   ;
    }

            if(mytemp->SW!=NULL){
            Location * myiterator = new Location;

            myiterator = mytemp;

            myiterator = myiterator->SW;

            
            

            SearchingTree (eastboundary,  westboundary,  northboundary,  southboundary,  arrangequery,  exactx,  exacty,  reference, myiterator,inRoad,inArea)   ;
    }
        if(mytemp->NE!=NULL){
            Location * myiterator = new Location;

            myiterator = mytemp;

            myiterator = myiterator->NE;

            

            SearchingTree (eastboundary,  westboundary,  northboundary,  southboundary,  arrangequery,  exactx,  exacty,  reference, myiterator,inRoad,inArea)   ;
    }
        if(mytemp->NW!=NULL){
            Location * myiterator = new Location;

            myiterator = mytemp;

            myiterator = myiterator->NW;

            

            SearchingTree (eastboundary,  westboundary,  northboundary,  southboundary,  arrangequery,  exactx,  exacty,  reference, myiterator,inRoad,inArea)   ;
    }

    }


}


void InsertingTree(Location * reference, Location * &mytemp, Location*&newLocation){

    if(mytemp->Xcoordinate > newLocation->Xcoordinate){//new one is on the west

        if(mytemp->Ycoordinate > newLocation->Ycoordinate){//new one is on the south


            if(mytemp->SW!=NULL){
                mytemp = mytemp->SW;
                InsertingTree(reference, mytemp, newLocation);

            }
            else{

            newLocation->father = mytemp;

            mytemp->SW = newLocation;

            mytemp = reference;
            }
           
            mytemp = reference;
            
        }


        else{//new one is on the north
            if(mytemp->NW!=NULL){
                mytemp = mytemp->NW;
                InsertingTree(reference, mytemp, newLocation);

            }
            else{

            newLocation->father = mytemp;

            mytemp->NW = newLocation;

            mytemp = reference;
            }
           
            mytemp = reference;
        }

    }


    else{ //new one is on the east

        if(mytemp->Ycoordinate > newLocation->Ycoordinate){//new one is on the south

            if(mytemp->SE!=NULL){
                mytemp = mytemp->SE;
                InsertingTree(reference, mytemp, newLocation);

            }
            else{

            newLocation->father = mytemp;

            mytemp->SE = newLocation;

            mytemp = reference;
            }
           
            mytemp = reference;

        }


        else{//new one is on the north
            if(mytemp->NE!=NULL){
                mytemp = mytemp->NE;
                InsertingTree(reference, mytemp, newLocation);

            }
            else{

            newLocation->father = mytemp;

            mytemp->NE = newLocation;

            mytemp = reference;
            }
           
            mytemp = reference;
        }
    }
    





}





int main()
{
    


    InsideTheArea * myArea = new InsideTheArea;

    InsideTheArea * myAreaptr= new InsideTheArea;

    myAreaptr = myArea;

    Location * reference = new Location;

    Location * mytemp = new Location;

    mytemp = reference;

	ifstream citiesfile;
    ifstream queryfile;
    stringstream sscities,ssqueries;

    string firstlineofcities,firstnodeofcities, myline, line ,destination,inArea="",inRoad="";
    int xcoordinate, ycoordinate;
    double xquery,yquery,arrangequery;

    citiesfile.open("cities.txt");

    queryfile.open("queries1.txt");


    getline(citiesfile, firstlineofcities);

    while(getline(citiesfile,line)){

        sscities<<line; 
        
        sscities >> destination;

        sscities >> xcoordinate;

        sscities >> ycoordinate; 

        if (reference->LocationName!=""){

            Location * newLocation = new Location;

            newLocation->LocationName = destination;

            newLocation->Xcoordinate = xcoordinate;

            newLocation->Ycoordinate = ycoordinate;
            
            InsertingTree( reference,mytemp, newLocation);
            
        }

        else {
            reference->LocationName= destination;
            reference->Xcoordinate= xcoordinate;
            reference->Ycoordinate= ycoordinate;
        }

        sscities.clear();
        
    }

    while(getline(queryfile,myline)){

        Road * myRoad = new Road;

        Road * myRoadptr= new Road;

        myRoad = myRoadptr;

        for (int i =0; i<myline.length();i++){
            if(myline[i]==','){
                myline.erase(i, 1);
            }
        }

        ssqueries << myline; 

        ssqueries >> xquery;

        ssqueries >> yquery;

        ssqueries >> arrangequery;

        SearchingTree (xquery+arrangequery,  xquery-arrangequery,  yquery+arrangequery,  yquery-arrangequery,  arrangequery,  xquery,  yquery,  reference, mytemp,inRoad,inArea )  ;
        



        if (inArea==""){
            cout<<"<None>"<<endl;

        }
        else{

            inArea.erase(inArea.length()-1, 1);
            inArea.erase(inArea.length()-1, 1);
            cout<<inArea<<endl;
        }
        inRoad.erase(inRoad.length()-1, 1);
        inRoad.erase(inRoad.length()-1, 1);
        cout<<inRoad<<endl;
        cout<<endl;

        inArea = "";

        inRoad ="";

        ssqueries.clear();
    }



    citiesfile.close();
    queryfile.close();

    return 0;
}
