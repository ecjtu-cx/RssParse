#include "rssparse.h"

int main() {
  RssReader reader;
  reader.parseRss("coolshell.xml");
  reader.dump("rsspars.txt");
  return 0;
}