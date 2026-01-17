//@category Export
// Export all decompiled functions to C file

import ghidra.app.decompiler.*;
import ghidra.app.decompiler.component.*;
import ghidra.program.model.listing.*;
import ghidra.util.exception.CancelledException;
import java.io.*;

public class ExportDecompiled extends GhidraScript {
    
    public void run() throws Exception {
        String outputFile = getScriptArgs()[0];
        PrintWriter writer = new PrintWriter(new FileWriter(outputFile));
        
        writer.println("/* Decompiled C code from SKULL.EXE using Ghidra */");
        writer.println("/* Generated automatically - may contain errors */");
        writer.println("");
        writer.println("#include <stdio.h>");
        writer.println("#include <stdlib.h>");
        writer.println("#include <string.h>");
        writer.println("#include <dos.h>");
        writer.println("");
        
        DecompInterface decompiler = new DecompInterface();
        decompiler.openProgram(currentProgram);
        
        FunctionManager functionManager = currentProgram.getFunctionManager();
        FunctionIterator functions = functionManager.getFunctions(true);
        
        int count = 0;
        while (functions.hasNext() && !monitor.isCancelled()) {
            Function function = functions.next();
            
            if (function.isExternal() || function.isThunk()) {
                continue;
            }
            
            try {
                DecompileResults results = decompiler.decompileFunction(
                    function, 30, monitor);
                
                if (results.decompileCompleted()) {
                    String decompiled = results.getDecompiledFunction().getC();
                    
                    writer.println("/* Function: " + function.getName() + 
                                 " @ " + function.getEntryPoint() + " */");
                    writer.println(decompiled);
                    writer.println("");
                    count++;
                }
            } catch (Exception e) {
                writer.println("/* Error decompiling " + function.getName() + ": " + 
                             e.getMessage() + " */");
            }
        }
        
        decompiler.dispose();
        writer.close();
        
        println("Exported " + count + " functions to " + outputFile);
    }
}
