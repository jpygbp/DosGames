#!/usr/bin/env python3
"""
Export decompiled code from Ghidra project
This script uses Ghidra's headless mode to export decompiled C code
"""

import os
import subprocess
import sys

def create_export_script():
    """Create a Ghidra script to export decompiled code"""
    script_content = '''//@category Export
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
'''
    
    script_path = "export_decompiled.java"
    with open(script_path, 'w') as f:
        f.write(script_content)
    
    return script_path

def export_with_ghidra():
    """Export decompiled code using Ghidra headless"""
    ghidra_path = r"C:\Users\Danie\Documents\dev\ghidra_10.1.1_PUBLIC_20211221\ghidra_10.1.1_PUBLIC"
    project_path = "."
    project_name = "skull_project"
    output_file = "skull_ghidra_decompiled.c"
    
    # Create export script
    script_path = create_export_script()
    
    # Use analyzeHeadless with postScript
    analyze_headless = os.path.join(ghidra_path, "support", "analyzeHeadless.bat")
    
    # First, let's try a simpler approach - use Ghidra's built-in export
    # We'll use a Python script instead since Java scripts are complex
    
    print("Creating Python export script for Ghidra...")
    python_script = '''# Ghidra Python script to export decompiled code
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
'''
    
    python_script_path = "export_decompiled.py"
    with open(python_script_path, 'w') as f:
        f.write(python_script)
    
    # Run Ghidra with the Python script
    cmd = [
        analyze_headless,
        project_path,
        project_name,
        "-process", "SKULL.EXE",
        "-scriptPath", ".",
        "-postScript", python_script_path,
        "-deleteProject"
    ]
    
    print(f"Running: {' '.join(cmd)}")
    result = subprocess.run(cmd, capture_output=True, text=True, cwd=".")
    
    print("STDOUT:")
    print(result.stdout)
    if result.stderr:
        print("STDERR:")
        print(result.stderr)
    
    return result.returncode == 0

if __name__ == '__main__':
    if export_with_ghidra():
        print("\nExport completed successfully!")
    else:
        print("\nExport may have completed with warnings. Check output above.")

