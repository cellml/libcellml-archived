#include <iostream>
#include "Version.h"

using namespace std;

// Dummy comment, just to test buildbot git repo polling. Another fake change, same reason.
int main() {
  cout << "Version " << libcellml::general::getVersion() << endl;
  return 0;
}
