//RISC-V Instruction translator.
//Available VIA HEX, BINARY
#include <iostream>
#include <map>
#include <bitset>
#include <cmath>
#include <algorithm>
#include <sstream>
#include <fstream>
using namespace std;


long long unsigned int binaryStringToInt(string in){
	long long unsigned int output=0;
	in.erase(std::remove(in.begin(), in.end(), ' '), in.end());
	for(int i=1;i<=in.length();i++){
		
		if( (in[in.length()-i]) == '1')
		{
			 output+=pow(2,i-1);
		}
	}
	
	return output;
}

long long unsigned int hexStringToInt(string in){
	long long unsigned output=0;
	unsigned tempDigit;
	in.erase(std::remove(in.begin(), in.end(), ' '), in.end());
	for(int i=1;i<=in.length()-2;i++){
		std::stringstream ss;
		ss<<std::hex<< in[in.length()-i];
		ss>>tempDigit;
		
		if( tempDigit>=0 && tempDigit<=15)
		{
			output+=tempDigit*(pow(16,i-1));
		}
	}
	
	return output;
	
	
}



int main(int argc, char *argv[]){

	map<int, string> opcode;
	//map<int, string> func3_R33;
	map<int, string> func7_R_0;
	map<int, string> func7_R_1;
	map<int, string> func7_R_2;
	map<int, string> func7_R_3;
	map<int, string> func7_R_4;
	map<int, string> func7_R_5;
	map<int, string> func7_R_6;
	map<int, string> func7_R_7;
	map<int, string> func7_R53_0;
	map<int, string> func7_R53_1;
	map<int, string> func7_R53_2;
	map<int, string> func7_R53_7;
	
	map<int, string> func7_R3b_0;
	map<int, string> func7_R3b_1;
	map<int, string> func7_R3b_4;
	map<int, string> func7_R3b_5;
	map<int, string> func7_R3b_6;
	
	
	
	map<int, string> func3_I13;
	map<int, string> func3_I1b;
	map<int, string> func3_I03;
	map<int, string> func3_I07;
	map<int, string> func3_S23;
	map<int, string> func3_S27;
	map<int, string> func3_B63;
	
	
	
	map<int, string> Registers;
	map<int, string> FloatRegisters;
	
  /* OPCODES:*/
  	//RV64IM	
	opcode[0x33]="R_33";
	opcode[0x3b]="R_3b";
	opcode[0x73]="I_73";
	opcode[0x67]="I_67";
	opcode[0x03]="I_03";
	opcode[0x13]="I_13";
	opcode[0x1b]="I_1b";
	opcode[0x23]="S_23";
	opcode[0x37]="U_37";
	opcode[0x17]="U_17";
	opcode[0x63]="B";
	opcode[0x6F]="J_6F";

  	//RV64FD
  	opcode[0x53]="R_53";
	opcode[0x07]="I_07";
	opcode[0x27]="S_27";


	
	
	
	
	/* R- TYPE*/
/*	
	func3_R33[0x0]="ADD";
	func3_R33[0x1]="SL";
	func3_R33[0x2]="SLT";
	func3_R33[0x4]="DIV";
	func3_R33[0x5]="SR";
	func3_R33[0x6]="REM";
	func3_R33[0x7]="AND";
*/	
	
	map<int, map<int, string>> func3_R33;
	//R_33 FUNC7 0
	func7_R_0[0x0]="add";
	func7_R_0[0x20]="sub";
	func7_R_0[0x1]="mul";
	//R FUNC7 1
	func7_R_1[0x0]="sll";
	func7_R_1[0x1]="mulh";
	//R FUNC7 2
	func7_R_2[0x0]="slt";
	//R FUNC7 3
	func7_R_3[0x0]="sltu";
	//R FUNC7 4
	func7_R_4[0x1]="xor";
	func7_R_4[0x1]="div";
	//R FUNC7 5
	func7_R_5[0x0]="srl";
	func7_R_5[0x20]="sra";
	//R FUNC7 6 (33+6)
	func7_R_6[0x1]="rem";
	func7_R_6[0x0]="or";
	//R FUNCT 7 (33+7)
	func7_R_7[0x0]="and";	
	
	
	func3_R33[0x0]=func7_R_0;
	func3_R33[0x1]=func7_R_1;
	func3_R33[0x2]=func7_R_2;
	func3_R33[0x3]=func7_R_3;
	func3_R33[0x4]=func7_R_4;
	func3_R33[0x5]=func7_R_5;
	func3_R33[0x6]=func7_R_6;
	func3_R33[0x7]=func7_R_7;
	
	map<int, map<int, string>> func3_R3b;
	//R3b FUNC7 0
	func7_R3b_0[0x0]="addw";
	func7_R3b_0[0x20]="subw";
	func7_R3b_0[0x01]="mulw";
	//R3b FUNC7 1
	func7_R3b_1[0x01]="sllw";
	//R3b FUNC7 4
	func7_R3b_4[0x1]="divw";
	//R3b FUNC7 5
	func7_R3b_5[0x0]="srlw";
	func7_R3b_5[0x20]="sraw";
	//R FUNC7 6 (33+6)
	func7_R3b_6[0x1]="remw";
	
	func3_R3b[0x0]=func7_R3b_0;
	func3_R3b[0x1]=func7_R3b_1;
	func3_R3b[0x4]=func7_R3b_4;
	func3_R3b[0x5]=func7_R3b_5;
	func3_R3b[0x6]=func7_R3b_6;
	
	
	
	
	map<int, map<int, string>> func3_R53;
	//R_53 FUNC7 0,1,2
	func7_R53_0[0x00]="fadd.s";
	func7_R53_0[0x01]="fadd.d";
	func7_R53_0[0x04]="fsub.s";
	func7_R53_0[0x05]="fsub.d";
	func7_R53_0[0x08]="fmul.s";
	func7_R53_0[0x09]="fmul.d";
	func7_R53_0[0x0c]="fdiv.s";
	func7_R53_0[0x0d]="fdiv.d";
	func7_R53_0[0x10]="fmv.s";
	func7_R53_0[0x11]="fmv.d";
	func7_R53_0[0x50]="fle.s";
	func7_R53_0[0x51]="fle.d";
	func7_R53_0[0x70]="fmv.x.s";
	func7_R53_0[0x71]="fmv.x.d";
	func7_R53_0[0x78]="fmv.s.x";
	func7_R53_0[0x79]="fmv.d.x";
	
	func7_R53_1[0x10]="fneg.s";
	func7_R53_1[0x11]="fneg.d";
	func7_R53_1[0x50]="flt.s";
	func7_R53_1[0x51]="flt.d";
	
	
	func7_R53_2[0x10]="fabs.s";
	func7_R53_2[0x11]="fabs.d";
	func7_R53_2[0x50]="feq.s";
	func7_R53_2[0x51]="feq.d";
	
	//Notice how rm(func3)=7 this means Dynamic Rounding mode.
	func7_R53_7[0x20]="fcvt.s.d";
	func7_R53_7[0x21]="fcvt.d.s";
	func7_R53_7[0x60]="fcvt.w.s";
	func7_R53_7[0x61]="fcvt.w.d";
	func7_R53_7[0x68]="fcvt.s.w"; 
	func7_R53_7[0x69]="fcvt.d.w";
	
	
	func3_R53[0x00]=func7_R53_0;
	func3_R53[0x01]=func7_R53_1;
	func3_R53[0x02]=func7_R53_2;
	func3_R53[0x07]=func7_R53_7;


	
	



	/* I- TYPE*/
	
	//
	func3_I13[0x0]="addi";
	func3_I13[0x1]="slli";
	func3_I13[0x2]="slti";
	func3_I13[0x3]="sltiu";
	func3_I13[0x4]="xori";
	func3_I13[0x5]="srai"; //OR SRLI. Uses just 5 lower immediate bits.
	func3_I13[0x6]="ori";
	func3_I13[0x7]="andi";
	
	func3_I03[0x3]="ld";
	func3_I03[0x2]="lw";
	func3_I03[0x0]="lb";
	func3_I03[0x6]="lwu";
	func3_I03[0x4]="lbu";
	
	func3_I07[0x2]="flw";
	func3_I07[0x3]="fld";
	
	func3_I1b[0x0]="addiw";
	func3_I1b[0x1]="slliw";
	func3_I1b[0x5]="sraiw";
	
	/* S- TYPE*/

	func3_S23[0x3]="sd";
	func3_S23[0x2]="sw";
	func3_S23[0x0]="sb";
	
	func3_S27[0x2]="fsw";
	func3_S27[0x3]="fsd";
	
	/*U- TYPE*/
	func3_B63[0x0]="beq";
	func3_B63[0x1]="bne";
	
	/* U- TYPE and J TYPE*/
	
	Registers[0]="zero";
	Registers[1]="ra";
	Registers[2]="sp";
	Registers[3]="gp";
	Registers[4]="tp";
	Registers[5]="t0";
	Registers[6]="t1";
	Registers[7]="t2";
	Registers[8]="s0";
	Registers[9]="s1";
	Registers[10]="a0";
	Registers[11]="a1";
	Registers[12]="a2";
	Registers[13]="a3";
	Registers[14]="a4";
	Registers[15]="a5";
	Registers[16]="a6";
	Registers[17]="a7";
	Registers[18]="s2";
	Registers[19]="s3";
	Registers[20]="s4";
	Registers[21]="s5";
	Registers[22]="s6";
	Registers[23]="s7";
	Registers[24]="s8";
	Registers[25]="s9";
	Registers[26]="s10";
	Registers[27]="s11";
	Registers[28]="t3";
	Registers[29]="t4";
	Registers[30]="t5";
	Registers[31]="t6";
	
	FloatRegisters[0]="ft0";
	FloatRegisters[1]="ft1";
	FloatRegisters[2]="ft2";
	FloatRegisters[3]="ft3";
	FloatRegisters[4]="ft4";
	FloatRegisters[5]="ft5";
	FloatRegisters[6]="ft6";
	FloatRegisters[7]="ft7";
	FloatRegisters[8]="fs0";
	FloatRegisters[9]="fs1";
	FloatRegisters[10]="fa0";
	FloatRegisters[11]="fa1";
	FloatRegisters[12]="fa2";
	FloatRegisters[13]="fa3";
	FloatRegisters[14]="fa4";
	FloatRegisters[15]="fa5";
	FloatRegisters[16]="fa6";
	FloatRegisters[17]="fa7";
	FloatRegisters[18]="fs2";
	FloatRegisters[19]="fs3";
	FloatRegisters[20]="fs4";
	FloatRegisters[21]="fs5";
	FloatRegisters[22]="fs6";
	FloatRegisters[23]="fs7";
	FloatRegisters[24]="fs8";
	FloatRegisters[25]="fs9";
	FloatRegisters[26]="fs10";
	FloatRegisters[27]="fs11";
	FloatRegisters[28]="t8";
	FloatRegisters[29]="t9";
	FloatRegisters[30]="t10";
	FloatRegisters[31]="t11";
	
	
	


	
	
	
	
	
	
	
	
	

	std::string Title =R"(
 ______            ____    ____      ____  __ __        ______  ____    ______     
/\__  _\   /'\_/`\/\  _`\ /\  _`\   /'___\/\ \\ \      /\__  _\/\  _`\ /\  _  \    
\/_/\ \/  /\      \ \ \L\_\ \ \/\ \/\ \__/\ \ \\ \     \/_/\ \/\ \,\L\_\ \ \L\ \   
   \ \ \  \ \ \__\ \ \  _\/\ \ \ \ \ \  _``\ \ \\ \_      \ \ \ \/_\__ \\ \  __ \  
    \_\ \__\ \ \_/\ \ \ \/  \ \ \_\ \ \ \L\ \ \__ ,__\     \_\ \__/\ \L\ \ \ \/\ \ 
    /\_____\\ \_\\ \_\ \_\   \ \____/\ \____/\/_/\_\_/     /\_____\ `\____\ \_\ \_\
    \/_____/ \/_/ \/_/\/_/    \/___/  \/___/    \/_/       \/_____/\/_____/\/_/\/_/
                                                                                   
                                                                                                                          
                                                                                          
)";                                                            
                                                             
	string input;
	char input2[100];
	long long unsigned int Instruction;
	int XOpcode;
	string type;
	int firsttime=1;
	
	/*In case a file is used*/
	bool fileDetected=0;
	std::ofstream Outbound;
	std::ifstream Inbound; //Used to bind files.
	string tempInstruction;
	long long unsigned int InstrCount=0;
	long long unsigned int InstrOk=0;
	
	if(argc>=3){
		string temp=argv[1];
		fileDetected=(temp=="-f")?1:0;
	}
	
do{		
		std::cout<<Title;
		std::cout<<" RV64IFMD DISASSEMBLER - INSTRUCTION SET TO ASSEMBLY DICTIONARY v1.3. Realized via C++ by Lorenzo Albani.\n Please contact lrnz.albani@gmail.com for any inquiries.\n";
		if(firsttime){
			std::cout<<endl<<" Disassembles most instructions.\n You may input either binary or hex(provided they begin with '0x') instructions.\n EXAMPLE INPUT: '00000010000010010011001010000011' or '0x2093283'.";
			input="00000010000010010011001010000011";
			firsttime=0;
		}else{
			std::cout<<endl;
		}
		
		
		 /*FILE DETECTION: Here files must be detected otherwise it may have unexpected beheaviour.*/
		if(fileDetected){
			std::cout<<endl<<endl<<endl<<" [NOTICE] -f (File Mode) Detected! Please wait as instructions are handled one by one.";
		    string filename=argv[2];
			Inbound.open(filename);
			filename += ".out";
			Outbound.open(filename,std::ios_base::app);
			Inbound>>tempInstruction;
		}
		/*PREPARING UNIQUE OUTBOUND STREAM*/
		std::ostream & OutStream=(fileDetected?  Outbound : std::cout);
		
		do{
			if(!fileDetected){
				if(input[0]=='0' && (input[1]=='x'||input[1]=='X')){
					Instruction=hexStringToInt(input);
				}else{
					Instruction=binaryStringToInt(input);
				}
			}else{
				
				tempInstruction= "0x"+tempInstruction;
				Instruction=hexStringToInt(tempInstruction);
			}
			
			XOpcode=Instruction%128;
			
			type=opcode[XOpcode];
			std::bitset<32> x(Instruction);
			std::bitset<7> y(XOpcode);
			if(fileDetected){
				OutStream<<endl<<endl<<"=====================[Instruction No. "<<InstrCount<<" ]=====================";
			}
			else{
				OutStream<<endl<<endl<<"=========================[ RESULTS: ]=====================";
			}
			OutStream<<endl<<endl<<" INSTRUCTION(BIN): "<<x;
			OutStream<<endl<<" INSTRUCTION(HEX): 0x"<<std::hex<<Instruction;
			OutStream<<endl<<" [TYPE]: "<<type<<endl<<" [OPCODE] HEX:"<<XOpcode<< " BIN:"<<y;
			OutStream<<endl<<std::dec; //RE-FIX TO DECIMAL (IT WILL MESS UP FURTHER COUTS OTHERWISE)
			
			if(type=="I_03" || type=="I_13" || type=="I_73"|| type=="I_67"|| type=="I_1b"){
				int Xrd=(Instruction%4096)/128;
				int Xfunc3=(Instruction%32768)/4096;
				int Xrs1=(Instruction%1048576)/32768;
				int Imm12=(Instruction%4294967296)/1048576;
				
				if(type=="I_03"){
					if(func3_I03[Xfunc3]==""){
						OutStream<<endl<<" [ERROR] The instruction type has been detected as \"I\" with opcode 0x03 (i.e load word/dword/byte Category) but func3 code matches no instruction.\nDOUBLE CHECK WITH RISC-V CODE TABLE AND TRY AGAIN."; 
					}else{
						OutStream<<endl<<" [ASSEMBLY (Via RegNum)]: "<<func3_I03[Xfunc3]<<" "<<"x"<<Xrd<<", "<<Imm12<<"(x"<<Xrs1<<")";
						OutStream<<endl<<" [ASSEMBLY (Via RegName)]: "<<func3_I03[Xfunc3]<<" "<<Registers[Xrd]<<", "<<Imm12<<"("<<Registers[Xrs1]<<")";
						
						std::bitset<12> ImmA(Imm12);
						std::bitset<5> Rd(Xrd);
						std::bitset<5> Rs1(Xrs1);
						std::bitset<3> func3(Xfunc3);
						OutStream<<endl<<endl<<"     IMM[11:0]      RS1   FUNC3    RD     OPCODE";
						OutStream<<endl<<"  [ "<<ImmA<<" | "<<Rs1<<" | "<<func3<<" | "<<Rd<<" | "<<y<<" ] ";
						InstrOk++;
					}
				}else if(type=="I_07"){
					if(func3_I07[Xfunc3]==""){
						OutStream<<endl<<" [ERROR] The instruction type has been detected as \"I\" with opcode 0x03 (i.e load word/dword float Category) but func3 code matches no instruction.\nDOUBLE CHECK WITH RISC-V CODE TABLE AND TRY AGAIN."; 
					}else{
						OutStream<<endl<<" [ASSEMBLY (Via RegNum)]: "<<func3_I07[Xfunc3]<<" "<<"f"<<Xrd<<", "<<Imm12<<"(x"<<Xrs1<<")";
						OutStream<<endl<<" [ASSEMBLY (Via RegName)]: "<<func3_I07[Xfunc3]<<" "<<FloatRegisters[Xrd]<<", "<<Imm12<<"("<<Registers[Xrs1]<<")";
						
						std::bitset<12> ImmA(Imm12);
						std::bitset<5> Rd(Xrd);
						std::bitset<5> Rs1(Xrs1);
						std::bitset<3> func3(Xfunc3);
						OutStream<<endl<<endl<<"     IMM[11:0]      RS1   FUNC3    RD     OPCODE";
						OutStream<<endl<<"  [ "<<ImmA<<" | "<<Rs1<<" | "<<func3<<" | "<<Rd<<" | "<<y<<" ] ";
						InstrOk++;
					}
				}else if(type=="I_13"){
					if(func3_I13[Xfunc3]==""){
						OutStream<<endl<<" [ERROR] The instruction type has been detected as \"I\" with opcode 0x13 (i.e addi/subi etc. Category) but func3 code matches no instruction.\nDOUBLE CHECK WITH RISC-V CODE TABLE AND TRY AGAIN."; 
					}else if(func3_I13[Xfunc3]!="srai"){
						OutStream<<endl<<" [ASSEMBLY (Via RegNum)]: "<<func3_I13[Xfunc3]<<" "<<"x"<<Xrd<<", "<<"x"<<Xrs1<<", "<<Imm12;
						OutStream<<endl<<" [ASSEMBLY (Via RegName)]: "<<func3_I13[Xfunc3]<<" "<<Registers[Xrd]<<", "<<"x"<<Registers[Xrs1]<<", "<<Imm12;
						
						std::bitset<12> ImmA(Imm12);
						std::bitset<5> Rd(Xrd);
						std::bitset<5> Rs1(Xrs1);
						std::bitset<3> func3(Xfunc3);
						OutStream<<endl<<endl<<"     IMM[11:0]      RS1   FUNC3    RD     OPCODE";
						OutStream<<endl<<"  [ "<<ImmA<<" | "<<Rs1<<" | "<<func3<<" | "<<Rd<<" | "<<y<<" ] ";
						InstrOk++;
					}else{ //CASE SRAI/SRLI - Important.
						
						int Xrd=(Instruction%4096)/128;
						int Xfunc3=(Instruction%32768)/4096;
						int Xrs1=(Instruction%1048576)/32768;
						int SHAMT=(Instruction%67108864)/1048576; 
						int Xfunc6=(Instruction%4294967296)/67108864;
						string Instruction13_5;
						if(Xfunc6==32){
							Instruction13_5="srai";
							OutStream<<endl<<" [ASSEMBLY (Via RegNum)]: "<<Instruction13_5<<" "<<"x"<<Xrd<<", "<<"x"<<Xrs1<<", "<<SHAMT;
							OutStream<<endl<<" [ASSEMBLY (Via RegName)]: "<<Instruction13_5<<" "<<Registers[Xrd]<<", "<<Registers[Xrs1]<<", "<<SHAMT;
							InstrOk++;
							std::bitset<6> Func7(Xfunc6);
							std::bitset<5> Rd(Xrd);
							std::bitset<6> Rs2(SHAMT);
							std::bitset<5> Rs1(Xrs1);
							std::bitset<3> func3(Xfunc3);
							
							OutStream<<endl<<endl<<"   SRAI/SRLI SHAMT     RS1   FUNC3    RD     OPCODE";
							OutStream<<endl<<"  [ "<<Func7<<" | "<<Rs2<<" | "<<Rs1<<" | "<<func3<<" | "<<Rd<<" | "<<y<<" ] ";
						
						}else if(Xfunc6==0){
							Instruction13_5="srli";
							OutStream<<endl<<" [ASSEMBLY (Via RegNum)]: "<<Instruction13_5<<" "<<"x"<<Xrd<<", "<<"x"<<Xrs1<<", "<<SHAMT;
							OutStream<<endl<<" [ASSEMBLY (Via RegName)]: "<<Instruction13_5<<" "<<Registers[Xrd]<<", "<<Registers[Xrs1]<<", "<<SHAMT;
							InstrOk++;
							std::bitset<6> Func7(Xfunc6);
							std::bitset<5> Rd(Xrd);
							std::bitset<6> Rs2(SHAMT);
							std::bitset<5> Rs1(Xrs1);
							std::bitset<3> func3(Xfunc3);
							
							OutStream<<endl<<endl<<"   SRAI/SRLI SHAMT     RS1   FUNC3    RD     OPCODE";
							OutStream<<endl<<"  [ "<<Func7<<" | "<<Rs2<<" | "<<Rs1<<" | "<<func3<<" | "<<Rd<<" | "<<y<<" ] ";

						}else{
							Instruction13_5="ERROR";
							OutStream<<" [ERROR] The Instruction was detected to belong into SRAI/SRLI Subtype (Both OPCODE 0x13 and FUNC3 0x5,\n SRAI/SRLI may depend upon most significant 6 bits) but the given immediate matches none of them.\nNote that SRAI/SRLI instruction uses just the 5 least significant Immediate bits to perform the shift.";
						}
						
						

					}
				}else if(type=="I_1b"){
					if(func3_I1b[Xfunc3]==""){
						OutStream<<endl<<" [ERROR] The instruction type has been detected as \"I\" with opcode 0x13 (i.e addiw/subiw etc. Category) but func3 code matches no instruction.\nDOUBLE CHECK WITH RISC-V CODE TABLE AND TRY AGAIN."; 
					}else if(func3_I1b[Xfunc3]!="sraiw"){
						OutStream<<endl<<" [ASSEMBLY (Via RegNum)]: "<<func3_I1b[Xfunc3]<<" "<<"x"<<Xrd<<", "<<"x"<<Xrs1<<", "<<Imm12;
						OutStream<<endl<<" [ASSEMBLY (Via RegName)]: "<<func3_I1b[Xfunc3]<<" "<<Registers[Xrd]<<", "<<Registers[Xrs1]<<", "<<Imm12;
						
						std::bitset<12> ImmA(Imm12);
						std::bitset<5> Rd(Xrd);
						std::bitset<5> Rs1(Xrs1);
						std::bitset<3> func3(Xfunc3);
						OutStream<<endl<<endl<<"     IMM[11:0]      RS1   FUNC3    RD     OPCODE";
						OutStream<<endl<<"  [ "<<ImmA<<" | "<<Rs1<<" | "<<func3<<" | "<<Rd<<" | "<<y<<" ] ";
						InstrOk++;
					}else{ //CASE SRAIW/SRLIW - Important.
						
						int Xrd=(Instruction%4096)/128;
						int Xfunc3=(Instruction%32768)/4096;
						int Xrs1=(Instruction%1048576)/32768;
						int SHAMT=(Instruction%33554432)/1048576;
						int Xfunc7=(Instruction%4294967296)/33554432;
						string Instruction13_5;
						if(Xfunc7==32){
							Instruction13_5="sraiw";
							OutStream<<endl<<" [ASSEMBLY (Via RegNum)]: "<<Instruction13_5<<" "<<"x"<<Xrd<<", "<<"x"<<Xrs1<<", "<<SHAMT;
							OutStream<<endl<<" [ASSEMBLY (Via RegName)]: "<<Instruction13_5<<" "<<Registers[Xrd]<<", "<<"x"<<Registers[Xrs1]<<", "<<SHAMT;	
							InstrOk++;
							std::bitset<7> Func7(Xfunc7);
							std::bitset<5> Rd(Xrd);
							std::bitset<5> Rs2(SHAMT);
							std::bitset<5> Rs1(Xrs1);
							std::bitset<3> func3(Xfunc3);
							
							OutStream<<endl<<endl<<"   SRAI/SRLI SHAMT     RS1   FUNC3    RD     OPCODE";
							OutStream<<endl<<"  [ "<<Func7<<" | "<<Rs2<<" | "<<Rs1<<" | "<<func3<<" | "<<Rd<<" | "<<y<<" ] ";
						
						}else if(Xfunc7==0){
							Instruction13_5="srliw";
							OutStream<<endl<<" [ASSEMBLY (Via RegNum)]: "<<Instruction13_5<<" "<<"x"<<Xrd<<", "<<"x"<<Xrs1<<", "<<SHAMT;
							OutStream<<endl<<" [ASSEMBLY (Via RegName)]: "<<Instruction13_5<<" "<<Registers[Xrd]<<", "<<"x"<<Registers[Xrs1]<<", "<<SHAMT;
							InstrOk++;
							std::bitset<7> Func7(Xfunc7);
							std::bitset<5> Rd(Xrd);
							std::bitset<5> Rs2(SHAMT);
							std::bitset<5> Rs1(Xrs1);
							std::bitset<3> func3(Xfunc3);
							
							OutStream<<endl<<endl<<"   SRAI/SRLI SHAMT     RS1   FUNC3    RD     OPCODE";
							OutStream<<endl<<"  [ "<<Func7<<" | "<<Rs2<<" | "<<Rs1<<" | "<<func3<<" | "<<Rd<<" | "<<y<<" ] ";
						}else{
							Instruction13_5="ERROR";
							OutStream<<" [ERROR] The Instruction was detected to belong into SRAIW/SRLIW Subtype (Both OPCODE 0x1b and FUNC3 0x5,\n SRAIW/SRLIW may depend upon most significant 7 bits)\n but the given immediate matches none of them.\nNote that SRAIW/SRLIW instruction uses just the 5 least significant Immediate bits to perform the shift.";
						}
						
						
					}
	
				}else if(type=="I_73"){ //ECALL/EBREAK
					if(Xfunc3==0 &&  Xrs1==0 && Imm12==0 && Xrd==0){
						OutStream<<endl<<" [ASSEMBLY]: ecall";
						OutStream<<endl<<" [NOTICE]: System call params may not be specified in the binary instruction fields\n (func3,func7, both source(Rs1) and destination(Rd) registers are all set to 0).\n The Service number and the input argument are to be saved in registers a7 and a0 respectively,\n before performing the call.";
						std::bitset<12> ImmA(Imm12);
						std::bitset<5> Rd(Xrd);
						std::bitset<5> Rs1(Xrs1);
						std::bitset<3> func3(Xfunc3);
						OutStream<<endl<<endl<<"     IMM[11:0]      RS1   FUNC3    RD     OPCODE";
						OutStream<<endl<<"  [ "<<ImmA<<" | "<<Rs1<<" | "<<func3<<" | "<<Rd<<" | "<<y<<" ] ";
						InstrOk++;
					}
					else if(Xfunc3==0 &&  Xrs1==0 && Imm12==1 && Xrd==0){
						OutStream<<endl<<" [ASSEMBLY]: ebreak";
						std::bitset<12> ImmA(Imm12);
						std::bitset<5> Rd(Xrd);
						std::bitset<5> Rs1(Xrs1);
						std::bitset<3> func3(Xfunc3);
						OutStream<<endl<<endl<<"     IMM[11:0]      RS1   FUNC3    RD     OPCODE";
						OutStream<<endl<<"  [ "<<ImmA<<" | "<<Rs1<<" | "<<func3<<" | "<<Rd<<" | "<<y<<" ] ";
						InstrOk++;
					}
					else if (Xfunc3==0 &&  Xrs1==0 && Imm12==258 && Xrd==0){ //Imm[11:0] 258 equals to func7==0x8 and rs2=0x2
						OutStream<<endl<<" [ASSEMBLY]: sret";
						OutStream<<endl<<" [NOTICE]: Format retrieved from \"RISC-V Privileged Instruction Set\" as this instruction usually is executed in Supervisor mode";
						std::bitset<12> ImmA(Imm12);
						std::bitset<5> Rd(Xrd);
						std::bitset<5> Rs1(Xrs1);
						std::bitset<3> func3(Xfunc3);
						OutStream<<endl<<endl<<"     IMM[11:0]      RS1   FUNC3    RD     OPCODE";
						OutStream<<endl<<"  [ "<<ImmA<<" | "<<Rs1<<" | "<<func3<<" | "<<Rd<<" | "<<y<<" ] ";
	                	InstrOk++;
					}else{
						OutStream<<endl<<"ERROR. The instruction type has been detected as \"I\" with opcode 0x73 (i.e Syscall Cathegory) but func3 code,Rs1 and Imm params match no known instruction.\nDOUBLE CHECK WITH RISC-V CODE TABLE AND TRY AGAIN."; 					
	
					}
				}else if(type=="I_67"){
					if(Xfunc3==0){
						OutStream<<endl<<" [ASSEMBLY (Via RegNum)]: "<<"jalr"<<" "<<"x"<<Xrd<<", "<<Imm12<<"(x"<<Xrs1<<")";
						OutStream<<endl<<" [ASSEMBLY (Via RegName)]: "<<"jalr"<<" "<<Registers[Xrd]<<", "<<Imm12<<"("<<Registers[Xrs1]<<")";
						std::bitset<12> ImmA(Imm12);
						std::bitset<5> Rd(Xrd);
						std::bitset<5> Rs1(Xrs1);
						std::bitset<3> func3(Xfunc3);
						OutStream<<endl<<endl<<"     IMM[11:0]      RS1   FUNC3    RD     OPCODE";
						OutStream<<endl<<"  [ "<<ImmA<<" | "<<Rs1<<" | "<<func3<<" | "<<Rd<<" | "<<y<<" ] ";
						InstrOk++;
					}
					else{
						OutStream<<endl<<" [ERROR] The instruction type has been detected as \"I\" with opcode 0x67 (i.e jalr Cathegory) but func3 code matches no instruction.\nDOUBLE CHECK WITH RISC-V CODE TABLE AND TRY AGAIN."; 					
					}
				}else{
						OutStream<<endl<<"[ERROR] UNEXPECTED EXCEPTION DETECTED: The program entered a case it wasn't supposed to access.\nDOUBLE CHECK WITH RISC-V CODE TABLE AND TRY AGAIN.";
				}
			}
			else if(type=="R_33"||type=="R_3b"){
				int Xrd=(Instruction%4096)/128;
				int Xfunc3=(Instruction%32768)/4096;
				int Xrs1=(Instruction%1048576)/32768;
				int Xrs2=(Instruction%33554432)/1048576;
				int Xfunc7=(Instruction%4294967296)/33554432;
				if(type=="R_3b"){
					if(func3_R3b.find(Xfunc3)==func3_R3b.end()){
						OutStream<<endl<<" [ERROR] The instruction type has been detected as \"R\" with opcode 0x3b but func3 code matches no instruction category (The instruction is specified via Func7 in type \"R\").\nDOUBLE CHECK WITH RISC-V CODE TABLE AND TRY AGAIN."; 
					}else{
						if((func3_R3b[Xfunc3])[Xfunc7]==""){
							OutStream<<endl<<" [ERROR] The instruction type has been detected as \"R\", and func3 code has matched with an instruction category, but func7 code matches no valid instruction.\nDOUBLE CHECK WITH RISC-V CODE TABLE AND TRY AGAIN."; 
						}else{
							OutStream<<endl<<" [ASSEMBLY (Via RegNum)]: "<<(func3_R3b[Xfunc3])[Xfunc7]<<" "<<"x"<<Xrd<<", "<<" "<<"x"<<Xrs1<<", "<<" "<<"x"<<Xrs2;
							OutStream<<endl<<" [ASSEMBLY (Via RegName)]: "<<(func3_R3b[Xfunc3])[Xfunc7]<<" "<<Registers[Xrd]<<", "<<" "<<Registers[Xrs1]<<", "<<" "<<Registers[Xrs2];
							
							std::bitset<7> Func7(Xfunc7);
							std::bitset<5> Rd(Xrd);
							std::bitset<5> Rs2(Xrs2);
							std::bitset<5> Rs1(Xrs1);
							std::bitset<3> func3(Xfunc3);
							
							OutStream<<endl<<endl<<"     FUNC7     RS2     RS1   FUNC3    RD     OPCODE";
							OutStream<<endl<<"  [ "<<Func7<<" | "<<Rs2<<" | "<<Rs1<<" | "<<func3<<" | "<<Rd<<" | "<<y<<" ] ";
							InstrOk++;
						}
					}
				}
				else{
					if(func3_R33.find(Xfunc3)==func3_R33.end()){
						OutStream<<endl<<" [ERROR] The instruction type has been detected as \"R\" with opcode 0x33 but func3 code matches no instruction category (The instruction is specified via Func7 in type \"R\").\nDOUBLE CHECK WITH RISC-V CODE TABLE AND TRY AGAIN."; 
					}else{
						if((func3_R33[Xfunc3])[Xfunc7]==""){
							OutStream<<endl<<" [ERROR] The instruction type has been detected as \"R\", and func3 code has matched with an instruction category, but func7 code matches no valid instruction.\nDOUBLE CHECK WITH RISC-V CODE TABLE AND TRY AGAIN."; 
						}else{
							OutStream<<endl<<" [ASSEMBLY (Via RegNum)]: "<<(func3_R33[Xfunc3])[Xfunc7]<<" "<<"x"<<Xrd<<", "<<" "<<"x"<<Xrs1<<", "<<" "<<"x"<<Xrs2;
							OutStream<<endl<<" [ASSEMBLY (Via RegName)]: "<<(func3_R33[Xfunc3])[Xfunc7]<<" "<<Registers[Xrd]<<", "<<" "<<Registers[Xrs1]<<", "<<" "<<Registers[Xrs2];
							
							std::bitset<7> Func7(Xfunc7);
							std::bitset<5> Rd(Xrd);
							std::bitset<5> Rs2(Xrs2);
							std::bitset<5> Rs1(Xrs1);
							std::bitset<3> func3(Xfunc3);
							
							OutStream<<endl<<endl<<"     FUNC7     RS2     RS1   FUNC3    RD     OPCODE";
							OutStream<<endl<<"  [ "<<Func7<<" | "<<Rs2<<" | "<<Rs1<<" | "<<func3<<" | "<<Rd<<" | "<<y<<" ] ";
							InstrOk++;
						}
					}
				}
			}
			else if(type=="R_53"){
				int Xrd=(Instruction%4096)/128;
				int Xfunc3=(Instruction%32768)/4096;
				int Xrs1=(Instruction%1048576)/32768;
				int Xrs2=(Instruction%33554432)/1048576;
				int Xfunc7=(Instruction%4294967296)/33554432;
				if(func3_R53.find(Xfunc3)==func3_R53.end()){
					OutStream<<endl<<" [ERROR] The instruction type has been detected as \"R\" with opcode 0x53 (Floating Point category) but func3 code matches no instruction category (The instruction is specified via Func7 in type \"R\").\nDOUBLE CHECK WITH RISC-V CODE TABLE AND TRY AGAIN."; 
				}else{
					if((func3_R53[Xfunc3])[Xfunc7]==""){
						OutStream<<endl<<" [ERROR] The instruction type has been detected as \"R\" with opcode 0x53 (Floating Point category), and func3 code has matched with an instruction category, but func7 code matches no valid instruction.\nDOUBLE CHECK WITH RISC-V CODE TABLE AND TRY AGAIN."; 
					}else{
						int tempCode=Xfunc7;
						//TWO OPERANDS SECTION
						if(tempCode==0x10|| tempCode==0x11 || tempCode==0x20 || tempCode==0x21 || tempCode==0x60 || tempCode==0x61 || tempCode==0x68 || tempCode==0x69||tempCode==0x70||tempCode==0x71||tempCode==0x78||tempCode==0x79){
							if(tempCode==0x21){
								//CASE TEMPCODE 21
								if(Xrs2==0){
									OutStream<<endl<<" [ASSEMBLY (Via RegNum)]: "<<(func3_R53[Xfunc3])[Xfunc7]<<" "<<"f"<<Xrd<<", "<<" "<<"f"<<Xrs1;
									OutStream<<endl<<" [ASSEMBLY (Via RegName)]: "<<(func3_R53[Xfunc3])[Xfunc7]<<" "<<FloatRegisters[Xrd]<<", "<<" "<<FloatRegisters[Xrs1];
									InstrOk++;
								}else{
									OutStream<<endl<<"ERROR. The instruction type has been detected as \"R\" with opcode 0x53 (Floating Point category),func3 and func7 code match 'fcvt.d.s' yet rs2 code won't match(supposed to be 0).\nDOUBLE CHECK WITH RISC-V CODE TABLE AND TRY AGAIN."; 
	
								}
							}
							else if(tempCode==0x20){
								//CASE TEMPCODE 20
								if(Xrs2==1){
									OutStream<<endl<<" [ASSEMBLY (Via RegNum)]: "<<(func3_R53[Xfunc3])[Xfunc7]<<" "<<"f"<<Xrd<<", "<<" "<<"f"<<Xrs1;
									OutStream<<endl<<" [ASSEMBLY (Via RegName)]: "<<(func3_R53[Xfunc3])[Xfunc7]<<" "<<FloatRegisters[Xrd]<<", "<<" "<<FloatRegisters[Xrs1];
									InstrOk++;
								}else{
									OutStream<<endl<<" [ERROR] The instruction type has been detected as \"R\" with opcode 0x53 (Floating Point category),func3 and func7 code match 'fcvt.s.d' yet rs2 code won't match(supposed to be 1).\nDOUBLE CHECK WITH RISC-V CODE TABLE AND TRY AGAIN."; 
								}	
							}else if(tempCode==0x60||tempCode==0x70||tempCode==0x61||tempCode==0x71){
								//Ist Operand is from Integer Register
								OutStream<<endl<<" [ASSEMBLY (Via RegNum)]: "<<(func3_R53[Xfunc3])[Xfunc7]<<" "<<"x"<<Xrd<<", "<<" "<<"f"<<Xrs1;
								OutStream<<endl<<" [ASSEMBLY (Via RegName)]: "<<(func3_R53[Xfunc3])[Xfunc7]<<" "<<Registers[Xrd]<<", "<<" "<<FloatRegisters[Xrs1];
								InstrOk++;							
							
							}else if(tempCode==0x68||tempCode==0x69||tempCode==0x78||tempCode==0x79){
								//IInd Operand is from Integer Register
								OutStream<<endl<<" [ASSEMBLY (Via RegNum)]: "<<(func3_R53[Xfunc3])[Xfunc7]<<" "<<"f"<<Xrd<<", "<<" "<<"x"<<Xrs1;
								OutStream<<endl<<" [ASSEMBLY (Via RegName)]: "<<(func3_R53[Xfunc3])[Xfunc7]<<" "<<FloatRegisters[Xrd]<<", "<<" "<<Registers[Xrs1];
								InstrOk++;						
							
							}
							else{
								OutStream<<endl<<" [ASSEMBLY (Via RegNum)]: "<<(func3_R53[Xfunc3])[Xfunc7]<<" "<<"f"<<Xrd<<", "<<" "<<"f"<<Xrs1;
								OutStream<<endl<<" [ASSEMBLY (Via RegName)]: "<<(func3_R53[Xfunc3])[Xfunc7]<<" "<<FloatRegisters[Xrd]<<", "<<" "<<FloatRegisters[Xrs1];
								InstrOk++;
							}
							
						}else if (tempCode==0x50||tempCode==0x51){
						//THREE OPERANDS yet Ist from Integer Register
							OutStream<<endl<<" [ASSEMBLY (Via RegNum)]: "<<(func3_R53[Xfunc3])[Xfunc7]<<" "<<"x"<<Xrd<<", "<<" "<<"f"<<Xrs1<<", "<<" "<<"f"<<Xrs2;
							OutStream<<endl<<" [ASSEMBLY (Via RegName)]: "<<(func3_R53[Xfunc3])[Xfunc7]<<" "<<Registers[Xrd]<<", "<<" "<<FloatRegisters[Xrs1]<<", "<<" "<<FloatRegisters[Xrs2];
							InstrOk++;
						}else{
							//All the remaining.
							OutStream<<endl<<" [ASSEMBLY (Via RegNum)]: "<<(func3_R53[Xfunc3])[Xfunc7]<<" "<<"f"<<Xrd<<", "<<" "<<"f"<<Xrs1<<", "<<" "<<"f"<<Xrs2;
							OutStream<<endl<<" [ASSEMBLY (Via RegName)]: "<<(func3_R53[Xfunc3])[Xfunc7]<<" "<<FloatRegisters[Xrd]<<", "<<" "<<FloatRegisters[Xrs1]<<", "<<" "<<FloatRegisters[Xrs2];
							InstrOk++;
						}
						std::bitset<7> Func7(Xfunc7);
						std::bitset<5> Rd(Xrd);
						std::bitset<5> Rs2(Xrs2);
						std::bitset<5> Rs1(Xrs1);
						std::bitset<3> func3(Xfunc3);
						
						OutStream<<endl<<endl<<"     FUNC7     RS2     RS1   FUNC3    RD     OPCODE";
						OutStream<<endl<<"  [ "<<Func7<<" | "<<Rs2<<" | "<<Rs1<<" | "<<func3<<" | "<<Rd<<" | "<<y<<" ] ";
					}
				}
			}
	
			
			else if(type=="S_23"||type=="S_27"){
				int Imm4_0=(Instruction%4096)/128;
				int Xfunc3=(Instruction%32768)/4096;
				int Xrs1=(Instruction%1048576)/32768;
				int Xrs2=(Instruction%33554432)/1048576;
				int Imm11_5=(Instruction%4294967296)/33554432;
				
				int Imm12=Imm11_5*32+Imm4_0;
				if(type=="S_23"){
					if(func3_S23[Xfunc3]==""){
						
						OutStream<<endl<<" [ERROR] The instruction type has been detected as \"S\" but func3 code matches no instruction.\nDOUBLE CHECK WITH RISC-V CODE TABLE AND TRY AGAIN."; 
					}
					else{
				
						OutStream<<endl<<" [ASSEMBLY (Via RegNum)]:  "<<func3_S23[Xfunc3]<<" "<<"x"<<Xrs2<<", "<<Imm12<<"(x"<<Xrs1<<")";
						OutStream<<endl<<" [ASSEMBLY (Via RegName)]: "<<func3_S23[Xfunc3]<<" "<<Registers[Xrs2]<<", "<<Imm12<<"("<<Registers[Xrs1]<<")";
						InstrOk++;
					}
				}else{
					if(func3_S27[Xfunc3]==""){	
						OutStream<<endl<<" [ERROR] The instruction type has been detected as \"S\" but func3 code matches no instruction.\nDOUBLE CHECK WITH RISC-V CODE TABLE AND TRY AGAIN."; 
					}
					else{
				
						OutStream<<endl<<" [ASSEMBLY (Via RegNum)]:  "<<func3_S27[Xfunc3]<<" "<<"f"<<Xrs2<<", "<<Imm12<<"(x"<<Xrs1<<")";
						OutStream<<endl<<" [ASSEMBLY (Via RegName)]: "<<func3_S27[Xfunc3]<<" "<<FloatRegisters[Xrs2]<<", "<<Imm12<<"("<<Registers[Xrs1]<<")";
						InstrOk++;
					}		
				}
				std::bitset<7> ImmA(Imm11_5);
				std::bitset<5> ImmB(Imm4_0);
				std::bitset<5> Rs2(Xrs2);
				std::bitset<5> Rs1(Xrs1);
				std::bitset<3> func3(Xfunc3);
				
				OutStream<<endl<<endl<<"   IMM[11:5]   RS2     RS1   FUNC3 IMM[4:0]  OPCODE";
				OutStream<<endl<<"  [ "<<ImmA<<" | "<<Rs2<<" | "<<Rs1<<" | "<<func3<<" | "<<ImmB<<" | "<<y<<" ] ";
			}
			
			else if(type=="B"){
				int Imm11=(Instruction%256)/128;
				int Imm4_1=(Instruction%4096)/256;
				int Xfunc3=(Instruction%32768)/4096;
				int Xrs1=(Instruction%1048576)/32768;
				int Xrs2=(Instruction%33554432)/1048576;
				int Imm10_5=(Instruction%2147483648)/33554432;
				int Imm12=(Instruction%4294967296)/2147483648;
				
				int Imm13=Imm12*4096+Imm11*2048+Imm10_5*32+Imm4_1*2; //13 bit [12:1]
				
				if(func3_B63[Xfunc3]==""){
					
					OutStream<<endl<<" [ERROR] The instruction type has been detected as \"B\" (or \"SB\") but func3 code matches no instruction.\nDOUBLE CHECK WITH RISC-V CODE TABLE AND TRY AGAIN."; 
			
	
				}else{
					
					std::bitset<1> ImmA(Imm12);
					std::bitset<6> ImmB(Imm10_5);
					std::bitset<4> ImmC(Imm4_1);
					std::bitset<1> ImmD(Imm11);
					std::bitset<5> Rs2(Xrs2);
					std::bitset<5> Rs1(Xrs1);
					std::bitset<3> func3(Xfunc3);
					
					
					OutStream<<endl<<" [ASSEMBLY (Via RegNum)]: "<<func3_B63[Xfunc3]<<" "<<"x"<<Xrs1<<", "<<"x"<<Xrs2<<", "<<Imm13;
					OutStream<<endl<<" [ASSEMBLY (Via RegName)]: "<<func3_B63[Xfunc3]<<" "<<Registers[Xrs1]<<", "<<Registers[Xrs2]<<", "<<Imm13;
					
					OutStream<<endl<<endl<<"WARNING: B instruction jumps are shown in assembly by the means of a label. EX: Beq x5,x4, Label1.";
					OutStream<<endl<<"The Integer number you see is a direct translation from the Binary Instruction (taking account of the sparse placement of B format) of the amount of Bytes to jump.";
					OutStream<<endl<<endl<<" IMM[12,10:5]  RS2     RS1   FUNC3 IMM[4:0,11] OPCODE";
					OutStream<<endl<<"  [ "<<ImmA<<" "<<ImmB<<" | "<<Rs2<<" | "<<Rs1<<" | "<<func3<<" | "<<ImmC<<" "<<ImmD<<" | "<<y<<" ] ";
					InstrOk++;
					
				}
				
				
			}
			
			else if(type=="U_37"||type=="U_17"){
				int Xrd=(Instruction%4096)/128;
				int Imm31_12=(Instruction%4294967296)/4096;
				std::bitset<5> Rd(Xrd);
				std::bitset<20> z(Imm31_12);
				string tempCode=(type=="U_37")?"lui":"auipc";
				OutStream<<endl<<" [ASSEMBLY (Via RegNum)]: "<<tempCode<<" "<<"x"<<Xrd<<", "<<std::hex<<"0x"<<Imm31_12<<std::dec;
				OutStream<<endl<<" [ASSEMBLY (Via RegName)]: "<<tempCode<<" "<<Registers[Xrd]<<", "<<std::hex<<"0x"<<Imm31_12<<std::dec;
				OutStream<<endl<<endl<<"       IMM[31:12]           RD    OPCODE";
				OutStream<<endl<<" [ "<<z<<" | "<<Rd<<" | "<< y<<" ] ";
				InstrOk++;
			}
			else if(type=="J_6F"){
				int Xrd=(Instruction%4096)/128;
				int Imm20_1=(Instruction)/4096;
				int Imm19_12=Imm20_1%256;
				int Imm11=(Imm20_1%512)/256;
				int Imm10_1=(Imm20_1%524288)/512;
				int Imm20=(Imm20_1/524288);
				long long int Offset= Imm10_1*2 + Imm11*2048 + Imm19_12*4096+ Imm20*1048576;
				
				std::bitset<1> ImmA(Imm20);
				std::bitset<10> ImmB(Imm10_1);
				std::bitset<1> ImmC(Imm11);
				std::bitset<8> ImmD(Imm19_12);
				std::bitset<5> Rd(Xrd);
				
				OutStream<<endl<<" [ASSEMBLY (Via RegNum)]: "<<"jal"<<" "<<"x"<<Xrd<<", "<<Offset;
				OutStream<<endl<<" [ASSEMBLY (Via RegName)]: "<<"jal"<<" "<<Registers[Xrd]<<", "<<Offset;
				OutStream<<endl<<endl<<" IMM[20, 10:1, 11 , 19:12]     RD    OPCODE";
				OutStream<<endl<<" [ "<<ImmA<<" "<<ImmB<<" "<<ImmC<<" "<<ImmD<<" | "<<Rd<<" | "<< y<<" ] ";
				InstrOk++;
				
				
				
			}
			else{
				OutStream<<" [ERROR] UNVALID OPCODE. \nDOUBLE CHECK WITH RISC-V CODE TABLE AND TRY AGAIN.";
			}
			
			InstrCount++;
			Inbound>>tempInstruction;
		}while(fileDetected && !Inbound.eof());
		if(fileDetected){ 
			std::cout<<endl<<" [NOTICE] File successfully scanned. "<<InstrCount<<" instruction(s) detected. "<<InstrOk<<" successfully disassembled."<<endl<<endl;  
			Outbound.close();
		}
		else{	
			std::cout<<endl<<"========================================================"<<endl<<endl<<"[INPUT BINARY INSTRUCTION]:";
			cin.getline(input2,99);
			input=input2;
			system("cls");
		}
	}while(!fileDetected);
	
	
}
