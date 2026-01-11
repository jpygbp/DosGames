/* Decompiled pseudocode from SKULL.EXE */
/* This is an approximation - not exact source code */

#include <dos.h>

/* DOS Function Calls Found: */
// 0x3E08: Get DOS Version
// 0x3E62: Resize Memory Block
// 0x3EBA: Get DOS Version
// 0x3FC9: Close File
// 0x3FD6: Terminate Program with Return Code
// 0x4001: Set Interrupt Vector
// 0x42CD: Write File
// 0x42FE: Resize Memory Block
// 0x5000: Close File
// 0x507A: Move File Pointer
// 0x50B8: Open File
// 0x50DB: Close File
// 0x510E: Write File
// 0x5115: Close File
// 0x5144: Read File
// 0x515D: Write File
// 0x51A4: Close File
// 0x51B3: Open File
// 0x51FD: Close File
// 0x5255: Read File
// 0x52C1: Read File
// 0x52D2: Read File
// 0x53BC: Write File
// 0x540D: Write File
// 0x5653: Unknown DOS Function (AH=0x48)
// 0x56AE: Resize Memory Block
// 0x579D: Unknown DOS Function (AH=0x0B)

/* Decompiled Functions: */

// Function at 0x0210
void function_0210() {
    // Function prologue: push bp; mov bp, sp
    function_404E();
    function_589C();
    function_3D24();
    function_3CEE();
    function_4FEC();
    function_3D24();
    if (jmp) goto label_028E;
    if (je) goto label_02AB;
}

// Function at 0x0512
void function_0512() {
    // Function prologue: push bp; mov bp, sp
    function_404E();
    if (jne) goto label_0543;
    if (jmp) goto label_0557;
    if (je) goto label_0567;
    if (jne) goto label_054C;
    if (jle) goto label_058C;
    function_0854();
    if (jmp) goto label_0591;
}

// Function at 0x05A6
void function_05A6() {
    // Function prologue: push bp; mov bp, sp
    function_404E();
    function_06AA();
    if (jmp) goto label_0682;
    if (jge) goto label_05E5;
    if (je) goto label_05D2;
    if (jmp) goto label_060D;
    if (jge) goto label_0615;
    if (jne) goto label_05F2;
    if (jle) goto label_062A;
    if (jmp) goto label_0633;
}

// Function at 0x06AA
void function_06AA() {
    // Function prologue: push bp; mov bp, sp
    function_404E();
    function_3940();
    if (jmp) goto label_076E;
    if (jne) goto label_06EF;
    if (jmp) goto label_0779;
    function_57A6();
    if (jne) goto label_0702;
    function_57A6();
    if (jmp) goto label_0771;
    if (je) goto label_0771;
    if (je) goto label_073C;
}

// Function at 0x07B6
void function_07B6() {
    // Function prologue: push bp; mov bp, sp
    function_404E();
    if (jmp) goto label_0831;
    function_56F2();
    function_570E();
    if (jne) goto label_0826;
    if (jmp) goto label_0831;
}

// Function at 0x0854
void function_0854() {
    // Function prologue: push bp; mov bp, sp
    function_404E();
    if (je) goto label_0892;
    if (jne) goto label_0892;
    function_09EE();
    if (jmp) goto label_08B9;
    function_0A92();
    if (je) goto label_08B4;
    function_10A0();
    if (jmp) goto label_0889;
    if (jne) goto label_093B;
}

// Function at 0x09EE
void function_09EE() {
    // Function prologue: push bp; mov bp, sp
    function_404E();
    if (ja) goto label_0A8A;
    if (jmp) goto label_0876;
    function_334A();
    if (jmp) goto label_0A8A;
    function_3F7C();
    if (jmp) goto label_0A8A;
    function_35B8();
    if (jmp) goto label_0A8A;
    function_35B8();
    if (jmp) goto label_0A8A;
    function_3A0E();
    if (jmp) goto label_0A2E;
}

// Function at 0x0A92
void function_0A92() {
    // Function prologue: push bp; mov bp, sp
    function_404E();
    if (jmp) goto label_0AC6;
    if (jl) goto label_0ABA;
    if (je) goto label_0B08;
    if (je) goto label_0B08;
    function_56C0();
    if (jmp) goto label_0B44;
}

// Function at 0x0C70
void function_0C70() {
    // Function prologue: push bp; mov bp, sp
    function_404E();
    if (je) goto label_0CBF;
    if (je) goto label_0CBF;
    function_56C0();
    if (jl) goto label_0D2E;
    if (jne) goto label_0D2E;
    if (je) goto label_0CE6;
    if (jmp) goto label_0CEE;
    if (je) goto label_0D02;
}

// Function at 0x0E1C
void function_0E1C() {
    // Function prologue: push bp; mov bp, sp
    function_404E();
    if (je) goto label_0E45;
    if (jmp) goto label_0F24;
    if (jne) goto label_0E60;
    function_35B8();
    if (jmp) goto label_0F24;
    function_35B8();
    if (jmp) goto label_0F24;
    if (je) goto label_0EA9;
    function_05A6();
    function_0C70();
}

