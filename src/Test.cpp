#include <iostream>
#include "Version.h"

using namespace std;

int main() {
  cout << "Version " << libcellml::general::getVersion() << endl;
  return 0;
}
