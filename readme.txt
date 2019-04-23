Manas programmas analize prieks parbauditaja:
Kas strada:
	1)AdminMenu:
		1.1)Iejesana ieks AdminMenu(iziesana) ar paroles palidzibu(parole 2233);
		1.2)Informacijas pievienosana prieks katram auto(ieks auto faila); Marka, modelis, gads, klase (premium, buget etc.), stundas likme, autonomas punkts;
		1.3)Informacijas par auto labosana(pa rindam, visa faila informacijas dzesana un vardu aizvietosana(fails auto_copy ) gadijuma kad notiek varda aizvietosana,
		tad mes izvelamies rindu, kur atrodas vards, izvelamies veco vardu un aizvietojam to ar jauno(izmantojam, lai parrakstitu failu no auto uz auto_copy un atpakal, vai ari kad 
		izdzesam rindu ari izmantojam auto_copy failu, tikai ir viens bags, par ko es pastastisu jums sadala, kas nestrada);
		1.4)Statistikas izvade uz ekrana(pec izveleta nosacijuma; ir vai nav masinas tagad);
	2)UserMenu
		2.1)Usera registresana un ieesana ieks User Menu(registresanas etapa parbaude uz login sakrisanu ieks loginu faila,un ieesanas parbaude ieks user faila uz loginu un paroli);
		2.2)Informacijas meklesana(autonomas punkta, briva laika, markas vai klases) un savas infomacijas ievadisana prieks rezervacijas izveides(ir ari visas parbaudes prieks datumiem), visa ierakstita informacija tiek ierakstita ieks rezervacijas faila;
		2.3)Tikkko izveidotas rezervacijas ierakstisana ieks html tabulas (tas izveide), tas ir rezervacijas drukasana(html tabula), bet rezervacijas.txt prieks rezervaciju meklesanas;
		2.4)Rezervacijas meklesana ievadot cilveka vardu un uzvardu(divi vardi ir obligati!), kas ir rezervejis to;
		2.5)Informacijas izvade, par noteiktu useru, ievadot, tas akkaunta talruna numuru;
		2.6)Datums11 un datums22 faili ir vajadzigi, lai vispirms ierakstit taja datumu veida(y:m:d)(katru reizi rezervacijas taisisanas laik faili parrakstas uz jauno informaciju),
		un pec tam izvadit divos mainigos prieks html  tabulas izveides;
		2.7)Izvada ari cenu,  kad es aprekinu datumu starpibu un izvada to dienas, pec tam parrekina stundas un izrekina stundas(ievadot ari nemsanas briza stundas  laiku,un laiku,kad atdosi masinu);
		2.8)Iziesana no katra menu;
		2.9)Pariesana katra menu;
Kas nestrada(bagi):
	1)Labosana, kad mes izdzesam noteiktu rindu faila auto.txt,tad bus kluda ar rindas numuru(strada tikai kad mes izdzesam faila pedejo rindu);
	2)Nav ipasi loti konkretas statistikas(izvada visus datus, masinas kas ir vai nav; netikai klasi, vai masinas pieejamibu;
	3)Ja ievadat citu ciparu(no menu izvelnes), tad UserMenu un AdminMenu, jums prasis vai jus gribat atkartotdarbibu noteikta menu; Sakum menu jums izvadis kludu un atkartosies izvele (registracija AdminMenu u. c.);
	4)Ari pasam vajag mainit loginu, ja jus gadijuma pasi izdzesiet user faila useri, tad izdariet to ari login faila, lai usera rinda butu vienada ari login faila, ja jo es to neizdarisiet, tad neienaksiet userMenu akkaunta);
	5)Gadijuma ja pec registresanas jus nevarat ieejiet akkaunta, tad notika datu parslodze, tad user faila un login faila vajag izdzest user vai useru, vai ari izdarit projekta rebuild vai clean, tad vajadzetu visam stradat, ja ne tad restartejiet codeblock vai pasu datoru;
	
	3 punkts no abgiem var but ari programmas fica(prieks manis) var but prieks jums tas ari bus fica, tapec prezentacija laika nevajag, citiem stastit, ka ta ir kluda!
Ja compilesanas bridi izvada kludu undefined_reference, tad izdariet rebuild vai clean.