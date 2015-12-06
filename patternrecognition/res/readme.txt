/**********************************************************************
 *  M�nsterigenk�nning readme.txt
 **********************************************************************/

/**********************************************************************
 *  Empirisk    Fyll i tabellen nedan med riktiga k�rtider i sekunder
 *  analys      n�r det k�nns vettigt att v�nta p� hela ber�kningen.
 *              Ge uppskattningar av k�rtiden i �vriga fall.
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
 *  Teoretisk   Ge ordo-uttryck f�r v�rstafallstiden f�r programmen som
 *  analys      en funktion av N. Ge en kort motivering.
 *
 **********************************************************************/

Brute: ordo(n^4). Som v�rstafall kommer de yttersta tre for-looparna k�ras och om alla punkter ligger p� samma linje kommer den innersta loopen att k�ras varje g�ng. 
Detta ger fyra n�stlade for-loopar som vardera k�rs (c*n) g�nger, d�r c = konstant. D�rav ges komplexitet O(n^4)

Sortering: Den yttersta for-loopen kommer g� genom alla element. Varje element kommer att j�mf�ras med ett specifikt referenselement
i listan och sorteras in i en map beroende p� dess lutning till detta element. d�refter kommer mapen itereras �ver f�r att
se om det finns tre eller fler element som har samma lutning mot referenselementet (max c*n tid).  
D�rav kommer komplexiteten i det v�rsta fallet vara n(n+1)/2 + n*(c*n) = (1/2 + c)n^2 + (1/2)n, allts� O(n^2).