# RISCV_Disassembler
<h2>English:</h2><br>
This program will disassemble (from binary or hex codes) most of the RVIMFD64 ISA binary instructions into Assembly ones.

The reason why this exists (and why it looks something slightly too "raw" to be released) was me trying to learn instruction formats to pursue a Computer Architecture exam.
Long story short, here it is.

<h4>How does it work?</h4><br>
Simple. Either paste in input a 32-bit long instruction, press ENTER and watch it translate.
The program will load itself with a ready-made example.
In detail: either input something in binary like "00000010000010010011001010000011" or in hex, like: "0x2093283".<b> And remember the "0x" if you input in HEX, at the beginning, it helps the program understand that what you've given it's in hex.</b>
<h4>Cool, but i have an entire file, sounds boring, eh?</h4>
Nope. Since 1.3 version you may simply do as follows:

RISCV.exe -f instructions.txt
(Where, of course, instructions.txt is a file filled with HEX format instructions, as at the moment we only support that.)
The output will be appended to a new file instructions.txt.out!
<b>Warning: this time, you may only insert HEX Instructions WITHOUT 0x at the beginning</b>
<h6>An example of instruction.txt<h6>:
<pre>
2093283
FFFFF2B3
FFFFF2B3
FFFFF223
FFFFF2B7
112A93
225293
</pre>
<h6>And output (I intentionally placed some bad instructions) </h6>
<pre>
==========================================================

 INSTRUCTION(BIN): 00000010000010010011001010000011
 INSTRUCTION(HEX): 0x2093283
 [TYPE]: I_03
 [OPCODE] HEX:3 BIN:0000011

 [ASSEMBLY (Via RegNum)]: ld x5, 32(x18)
 [ASSEMBLY (Via RegName)]: ld t0, 32(s2)

     IMM[11:0]      RS1   FUNC3    RD     OPCODE
  [ 000000100000 | 10010 | 011 | 00101 | 0000011 ] 

==========================================================

 INSTRUCTION(BIN): 11111111111111111111001010110011
 INSTRUCTION(HEX): 0xfffff2b3
 [TYPE]: R_33
 [OPCODE] HEX:33 BIN:0110011

 [ERROR] The instruction type has been detected as "R", and func3 code has matched with an instruction category, but func7 code matches no valid instruction.
DOUBLE CHECK WITH RISC-V CODE TABLE AND TRY AGAIN.

==========================================================

 INSTRUCTION(BIN): 11111111111111111111001010110011
 INSTRUCTION(HEX): 0xfffff2b3
 [TYPE]: R_33
 [OPCODE] HEX:33 BIN:0110011

 [ERROR] The instruction type has been detected as "R", and func3 code has matched with an instruction category, but func7 code matches no valid instruction.
DOUBLE CHECK WITH RISC-V CODE TABLE AND TRY AGAIN.

==========================================================

 INSTRUCTION(BIN): 11111111111111111111001000100011
 INSTRUCTION(HEX): 0xfffff223
 [TYPE]: S_23
 [OPCODE] HEX:23 BIN:0100011

 [ERROR] The instruction type has been detected as "S" but func3 code matches no instruction.
DOUBLE CHECK WITH RISC-V CODE TABLE AND TRY AGAIN.

   IMM[11:5]   RS2     RS1   FUNC3 IMM[4:0]  OPCODE
  [ 1111111 | 11111 | 11111 | 111 | 00100 | 0100011 ] 

==========================================================

 INSTRUCTION(BIN): 11111111111111111111001010110111
 INSTRUCTION(HEX): 0xfffff2b7
 [TYPE]: U_37
 [OPCODE] HEX:37 BIN:0110111

 [ASSEMBLY (Via RegNum)]: lui x5, 0xfffff
 [ASSEMBLY (Via RegName)]: lui t0, 0xfffff

       IMM[31:12]           RD    OPCODE
 [ 11111111111111111111 | 00101 | 0110111 ] 

==========================================================

 INSTRUCTION(BIN): 00000000000100010010101010010011
 INSTRUCTION(HEX): 0x112a93
 [TYPE]: I_13
 [OPCODE] HEX:13 BIN:0010011

 [ASSEMBLY (Via RegNum)]: slti x21, x2, 1
 [ASSEMBLY (Via RegName)]: slti s5, xsp, 1

     IMM[11:0]      RS1   FUNC3    RD     OPCODE
  [ 000000000001 | 00010 | 010 | 10101 | 0010011 ] 

==========================================================

 INSTRUCTION(BIN): 00000000001000100101001010010011
 INSTRUCTION(HEX): 0x225293
 [TYPE]: I_13
 [OPCODE] HEX:13 BIN:0010011

 [ASSEMBLY (Via RegNum)]: srli x5, x4, 2
 [ASSEMBLY (Via RegName)]: srli t0, tp, 2

   SRAI/SRLI SHAMT     RS1   FUNC3    RD     OPCODE
  [ 000000 | 000010 | 00100 | 101 | 00101 | 0010011 ] </pre>


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
