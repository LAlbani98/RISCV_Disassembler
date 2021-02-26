# RISCV_Disassembler
<h2>English:</h2><br>
This program will disassemble (from binary or hex codes) most of the RVIMFD64 ISA binary instructions into Assembly ones.

The reason why this exists (and why it looks something slightly too "raw" to be released) was me trying to learn instruction formats to pursue a Computer Architecture exam.
Long story short, here it is.

<h5>How does it work?</h5><br>
Simple. Either paste in input a 32-bit long instruction, press ENTER and watch it translate.
The program will load itself with a ready-made example.
In detail: either input something in binary like "00000010000010010011001010000011" or in hex, like: "0x2093283".<b>(And remember the "0x" if you input in HEX, at the beginning, it helps the program understand that what you've given it's in hex.)</b>
Any suggestions or bug reporting to be sent either here or lrnz.albani@gmail.com.

<h2>Italian:</h2><br>
Questo programma è in grado di tradurre (da codice binario oppure esadecimale) buona parte delle istruzioni previste nell' Instruction Set Architecture RVIMFD64 di un processore RISC-V.

La ragione per il quale questo programma esiste (e il perchè può apparire non ottimizzato ed elegante in termini di stesura del codice) è perchè è stato creato quasi per gioco al fine di imparare meglio i formati delle istruzioni di un processore RISC-V in vista di un esame di Architettura di Calcolatori.
Ho deciso di completarlo al fine che possa essere utile a qualcuno.


<h4>Come funziona?</h4><br>
Semplice: è solo necessario inserire un istruzione a 32bit e premere invio.
In automatico verranno date informazioni sul formato e sulla posizione dei bit che hanno determinato tale traduzione.
Nel dettaglio, è sufficiente inserire un istruzione in binario oppure in esadecimale, per esempio "00000010000010010011001010000011", oppure "0x2093283".
<b>Nel caso si scelga di inserire qualcosa in HEX, ricordare di inserire "0x" all'inizio. Aiuta il programma a capire che è un esadecimale.</b>

Consigli e correzioni possono essere segnalati qui oppure a lrnz.albani@gmail.com.
