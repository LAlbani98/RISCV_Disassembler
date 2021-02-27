# RISCV Disassembler (RVIMFD ISA)
<h2>English:</h2><br>
This program will disassemble/decode (from binary or hex codes) most of the RVIMFD64 ISA 32-bit binary instructions into the related (and understandable) assembly commands, in addition to detect the instruction type, the binary instruction will be divided into the fields the format is made of.


The reason why this exists (and why the code looks like too much of a badly designed program to be released) was me trying to learn instruction formats to pass a Computer Architecture exam (Lectures held by Roberto Giorgi, Università di Siena, Siena, Italy), so i needed something that could be coded quick, after the exam i then tried to fill its holes as fast as possibile for it to be available to anybody else.
Long story short, here it is.
<br>
<br>

<h3>How to compile? Requirements? Where to download?</h3>
No dependencies needed, just a C++ Compiler. This program will just do string and math operations and use some std::map(s) as opcode-to-format dictionaries to decode instructions, pretty much any C++ compiler on any OS will be able to produce a working executable: just open RISCV.cpp into yours (or download one, like DevC++ for windows) and compile.<br><br>
Of course, i know most of those interested in this program will likely have Windows as OS, be students and not belong to the "obnoxious nerd" kind that haunts this website, and might even not know what to do with the RISCV.cpp file, so don't worry, <b> you can download the already compiled, ready-to-use .exe program (for Windows) on the Release section(on the right column).</b>
<br>
<h3>How to Use?</h3>
Simple: run the executable (that you can even download in the Release section), and either paste a binary or HEX (starting with 0x) 32-bit long instruction, press ENTER and watch it translate.
The program will load itself with a ready-made example of what the output will look like.
In detail: either input something in binary like:<pre>00000010000010010011001010000011</pre> or in hex, like: <pre>0x2093283</pre><b>And remember the "0x" at the beginning of the instruction if you input one in HEX format, it helps the program understand that what you've given it's in hex.</b>
<br>
<br>
<h3>Cool, but i have an entire file full of codes to translate, sounds boring, eh?</h3>
Nope. Since 1.3 version you may simply do as follows:

<pre>RISCV.exe -f instructions.txt</pre>

<br>(Where, of course, instructions.txt is a file filled with HEX format instructions, as at the moment we only support that.)

<br>The output will be appended to a new file instructions.txt.out!

<br><b>Warning: this time, you may only insert HEX Instructions WITHOUT 0x at the beginning</b>

<h6>An example of instruction.txt:<h6>
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

   SRAI/SRLI  SHAMT    RS1   FUNC3    RD     OPCODE
  [ 000000 | 000010 | 00100 | 101 | 00101 | 0010011 ] </pre>


Any suggestions or bug reporting to be sent either here or lrnz.albani@gmail.com.


<h2>Italian:</h2><br>
Questo programma è in grado di tradurre (da codice binario oppure esadecimale) buona parte delle istruzioni previste nell' Instruction Set Architecture RVIMFD64 di un processore RISC-V.

La ragione per il quale questo programma esiste (e il perchè può apparire non ottimizzato ed elegante in termini di stesura del codice) è perchè è stato creato quasi per gioco al fine di imparare meglio i formati delle istruzioni di un processore RISC-V in vista di un esame di Architettura di Calcolatori.
Ho deciso di completarlo al fine che possa essere utile a qualcuno.


<h3>Come funziona?</h3><br>
Semplice: è solo necessario inserire un istruzione a 32bit e premere invio.
In automatico verranno date informazioni sul formato e sulla posizione dei bit che hanno determinato tale traduzione.
Nel dettaglio, è sufficiente inserire un istruzione in binario oppure in esadecimale, per esempio "00000010000010010011001010000011", oppure "0x2093283".
<b>Nel caso si scelga di inserire qualcosa in HEX, ricordare di inserire "0x" all'inizio. Aiuta il programma a capire che è un esadecimale.</b>

Consigli e correzioni possono essere segnalati qui oppure a lrnz.albani@gmail.com.
