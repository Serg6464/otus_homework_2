#include <consolelogwriter.h>
#include <iostream>

void ConsleLogWriter::WriteToLog(const char *message)
{
    std::cout << message << "\n";
}