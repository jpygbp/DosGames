# Ghidra Python script to export decompiled code
from ghidra.app.decompiler import DecompInterface
from ghidra.program.model.listing import FunctionManager
from java.io import PrintWriter, FileWriter

output_file = "skull_ghidra_decompiled.c"
writer = PrintWriter(FileWriter(output_file))

writer.println("/* Decompiled C code from SKULL.EXE using Ghidra */")
writer.println("/* Generated automatically - may contain errors */")
writer.println("")
writer.println("#include <stdio.h>")
writer.println("#include <stdlib.h>")
writer.println("#include <string.h>")
writer.println("#include <dos.h>")
writer.println("")

decompiler = DecompInterface()
decompiler.openProgram(getCurrentProgram())

functionManager = getCurrentProgram().getFunctionManager()
functions = functionManager.getFunctions(True)

count = 0
for function in functions:
    if function.isExternal() or function.isThunk():
        continue
    
    try:
        results = decompiler.decompileFunction(function, 30, getMonitor())
        
        if results.decompileCompleted():
            decompiled = results.getDecompiledFunction().getC()
            
            writer.println("/* Function: " + function.getName() + 
                         " @ " + str(function.getEntryPoint()) + " */")
            writer.println(decompiled)
            writer.println("")
            count += 1
    except Exception, e:
        writer.println("/* Error decompiling " + function.getName() + ": " + 
                     str(e) + " */")

decompiler.dispose()
writer.close()

print "Exported " + str(count) + " functions to " + output_file
