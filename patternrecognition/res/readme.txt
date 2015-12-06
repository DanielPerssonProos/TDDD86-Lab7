/**********************************************************************
 *  Mönsterigenkänning readme.txt
 **********************************************************************/

/**********************************************************************
 *  Empirisk    Fyll i tabellen nedan med riktiga körtider i sekunder
 *  analys      när det känns vettigt att vänta på hela beräkningen.
 *              Ge uppskattningar av körtiden i övriga fall.
 *
 **********************************************************************/
    
      N       brute       				sortering
 ---------------------------------------
    150		91ms						38ms
    200		195ms						53ms
    300		707ms						122ms
    400		1549ms						179ms
    800		12051ms						654ms
   1600		85580ms 					2001ms
   3200		890541ms (uppskattad)		6897ms
   6400		9261406ms (uppskattad)		25949ms
  12800		96318622ms (uppskattad)		102069ms


/**********************************************************************
 *  Teoretisk   Ge ordo-uttryck för värstafallstiden för programmen som
 *  analys      en funktion av N. Ge en kort motivering.
 *
 **********************************************************************/

Brute: ordo(n^4). Som värstafall kommer de yttersta tre for-looparna köras och om alla punkter ligger på samma linje kommer den innersta loopen att köras varje gång. 
Detta ger fyra nästlade for-loopar som vardera körs (c*n) gånger, där c = konstant. Därav ges komplexitet O(n^4)

Sortering: Den yttersta for-loopen kommer gå genom alla element. Varje element kommer att jämföras med ett specifikt referenselement
i listan och sorteras in i en map beroende på dess lutning till detta element. därefter kommer mapen itereras över för att
se om det finns tre eller fler element som har samma lutning mot referenselementet (max c*n tid).  
Därav kommer komplexiteten i det värsta fallet vara n(n+1)/2 + n*(c*n) = (1/2 + c)n^2 + (1/2)n, alltså O(n^2).