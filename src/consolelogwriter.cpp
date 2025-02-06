#include <consolelogwriter.h>
#include <iostream>

void ConsoleLogWriter::WriteToLog(const char *message)
{
    std::cout << message << "\n";
}