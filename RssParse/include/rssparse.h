#include <iostream>
#include <vector>

#include "tinyxml2.h"

using std::string;
using std::vector;

struct RssItem {
  string title;
  string link;
  string description;
  string content;
};

class RssReader {
public:
  RssReader();
  void parseRss(const string &filename); //解析
  void dump(const string &filename);     //输出
private:
  vector<RssItem> _rss;
};