#ifndef SYSTEM_UTILITY_H
#define SYSTEM_UTILITY_H

#include <string>

using string = std::string;

void Sleep(int latency_ms);
void WriteTextWithDelay(const string &text);
void IgnoreCinLine();
void ClearScreen();

#endif  // SYSTEM_UTILITY_H
