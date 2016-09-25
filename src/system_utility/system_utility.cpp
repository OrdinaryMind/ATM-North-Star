#include "system_utility.h"

#include <chrono>
#include <limits>
#include <thread>

void SystemUtility::CleanFlow() const {
  cin.clear();
  while (cin.get() != '\n')
    ;
}

void SystemUtility::Sleep(int latency_ms) const {
  std::this_thread::sleep_for(std::chrono::milliseconds(latency_ms));
}

void SystemUtility::IgnoreCinLine() const {
  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

void SystemUtility::ClearScreen() const { system("clear"); }

void SystemUtility::WriteTextWithDelay(const string &text, int delay) const {
  for (const auto &symbol : text) {
    cout << symbol;
    cout.flush();
    Sleep(delay);
  }
  cout << "\n";
}

void SystemUtility::WriteSymbolsNTimes(char symbol, int n) const {
  for (int i = 0; i < n; ++i) {
    cout << symbol;
  }
}