#include "URI.h"
#include <iostream>

using namespace std;

int main() {

  URI u("google.co.jp/search?client=ubuntu&channel=fs&q=fdsfds&ie=utf-8&oe=utf-8&gl=uk&redir_esc=&ei=cGbSUf2YEpDTkgXzmIEQ");
  
  cout << u.get_value("client") << endl;
  cout << u.get_value("channel") << endl;
  cout << u.get_value("q") << endl;
  cout << u.get_value("ie") << endl;
  cout << u.get_value("oe") << endl;
  cout << u.get_value("gl") << endl;
  cout << u.get_value("redir_esc") << endl;
  cout << u.get_value("ei") << endl;
  


}
