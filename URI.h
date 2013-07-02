#ifndef URICLASS_H
#define URICLASS_H

#include <map>
#include <string>
#include <iostream>

using namespace std;


class URI {

public:
  URI(string uristr) : m_uri(uristr) {

    // find first ?, set start position
    size_t start_pos = m_uri.find("?");
    size_t end_pos   = 0;

    start_pos++;
    // google.co.jp/search?client=ubuntu&channel=fs&q=fdsfds&ie=utf-8&oe=utf-8&gl=uk&redir_esc=&ei=cGbSUf2YEpDTkgXzmIEQ
    for(;;) {
      // find next =, set end position
      end_pos = m_uri.find("=",start_pos+1);
      if(end_pos == string::npos) {break;}

      // parse out key
      string c_key = m_uri.substr(start_pos,end_pos-start_pos);

      // find next &
      start_pos = end_pos+1;
      end_pos = m_uri.find("&",end_pos+1);
      if(end_pos == string::npos) end_pos=start_pos-1;

      // parse out value
      string c_value = m_uri.substr(start_pos,end_pos-start_pos);
      start_pos = end_pos+1;

      uri_data[c_key] = c_value;
    }
  }

  string get_value(string key) {
    return uri_data[key];
  }

  string m_uri;
  map<string,string> uri_data;
};

#endif
