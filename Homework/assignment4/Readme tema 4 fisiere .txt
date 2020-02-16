***Format raport text***

Email 1 from me@email.com to ionut@email.com; test@email.com;
Confirmari de la: ionut@email.com;
Subject: Intalnire pregatire lucrare
Continut:
Salut !
Va propun sa ne intalnim marti pentru a lucra impreuna exemplele de la seminar.

______________________________________________________________________________________

Email 2 from me@email.com to ionut@email.com; ana@email.com; gigel@email.com
Confirmari de la: *nimeni*
Subject: Intrebare exemplu seminar
Continut:

______________________________________________________________________________________
Email 3	from me@email.com ionut@email.com; ana@email.com; gigel@email.com
Confirmari de la: ionut@email.com; ana@email.com;
Subject: Programare examen
Continut:
Salut !
Cand este programat examenul ?

Multumesc



***Structura fisier binar:***

nr_emailuri|id_email|nr_caractere_subject_cu_terminator|subject|from_pe_50_bytes|numar_adrese_to|adresa_to_1|adresa_to_2|...|confirmare_1|confirmare_2|.....|confirmare_n|nr_caractere_continut_cu_terminator|continut|......



* simbolul | nu face parte din continutul fisierului binar - este folosit in descriere pentru a delimita campurile
** pentru adresa destinatie NU este permisa scrierea numarului de caractere inainte de adresa (pentru citire trebuie numarate caracterele si apoi facu salt inapoi in fisier - seek sau se citeste caracter cu caracter pana la \0)
***subiectul, from, continutul si adresele destinatie contin terminatorul \0